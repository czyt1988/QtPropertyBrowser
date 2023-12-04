macro(create_win32_resource_version)
	if(MSVC) # TODO: MinGW (http://www.mingw.org/wiki/MS_resource_compiler)
		set(_target)
		set(_filename)
		set(_version ${PROJECT_VERSION})
		set(_ext "ico")
		set(_companyname "https://github.com/czyt1988")
		set(_copyright "Copyright (C) 2023 by 尘中远 github:czyt1988")
		set(_description "DA")
		set(cmd "_target")
		foreach(arg ${ARGN})
			if(arg STREQUAL "TARGET")
				set(cmd "_target")
			elseif(arg STREQUAL "FILENAME")
				set(cmd "_filename")
			elseif(arg STREQUAL "VERSION")
				set(cmd "_version")
			elseif(arg STREQUAL "EXT")
				set(cmd "_ext")
			elseif(arg STREQUAL "COMPANYNAME")
				set(cmd "_companyname")
			elseif(arg STREQUAL "COPYRIGHT")
				set(cmd "_copyright")
			elseif(arg STREQUAL "DESCRIPTION")
				set(cmd "_description")
			else()
				if("${cmd}" STREQUAL "_target")
					set(_target ${arg})
				elseif("${cmd}" STREQUAL "_filename")
					set(_filename ${arg})
				elseif("${cmd}" STREQUAL "_version")
					set(_version ${arg})
				elseif("${cmd}" STREQUAL "_ext")
					set(_ext ${arg})
				elseif("${cmd}" STREQUAL "_companyname")
					set(_companyname ${arg})
				elseif("${cmd}" STREQUAL "_copyright")
					set(_copyright ${arg})
				elseif("${cmd}" STREQUAL "_description")
					set(_description ${arg})
				else()
				endif()
			endif()
		endforeach()
		string(REGEX MATCHALL "[.]" matches "${_version}")
		list(LENGTH matches n_matches)
		while(n_matches LESS 3)
			string(APPEND _version ".0")
			string(REGEX MATCHALL "[.]" matches "${_version}")
			list(LENGTH matches n_matches)
		endwhile()
		string(REPLACE "." "," PC ${_version})
		set(RC_FILE ${CMAKE_CURRENT_BINARY_DIR}/${_target}.rc)
		file(WRITE  ${RC_FILE} "#include <winres.h>\n\n")
		file(APPEND ${RC_FILE} "#define TARGET_NAME \"${_target}\"\n")
		file(APPEND ${RC_FILE} "#define FILE_VERSION_C ${PC}\n")
		file(APPEND ${RC_FILE} "#define FILE_VERSION_S \"${_version}\"\n")
		if("${_ext}" STREQUAL "exe")
			set(_filetype "0x1L")
			file(APPEND ${RC_FILE} "#define FILE_NAME \"${_filename}.exe\"\n")
		else()
			set(_filetype "0x2L")
			file(APPEND ${RC_FILE} "#ifdef _DEBUG\n")
			file(APPEND ${RC_FILE} "#define FILE_NAME \"${_filename}${CMAKE_DEBUG_POSTFIX}.dll\"\n")
			file(APPEND ${RC_FILE} "#else\n")
			file(APPEND ${RC_FILE} "#define FILE_NAME \"${_filename}.dll\"\n")
			file(APPEND ${RC_FILE} "#endif\n")
		endif()
		file(APPEND ${RC_FILE} "\nVS_VERSION_INFO VERSIONINFO\n")
		file(APPEND ${RC_FILE} " FILEVERSION FILE_VERSION_C\n")
		file(APPEND ${RC_FILE} " PRODUCTVERSION FILE_VERSION_C\n")
		file(APPEND ${RC_FILE} " FILEFLAGSMASK 0x3fL\n")
		file(APPEND ${RC_FILE} "#ifdef _DEBUG\n")
		file(APPEND ${RC_FILE} " FILEFLAGS 0x1L\n")
		file(APPEND ${RC_FILE} "#else\n")
		file(APPEND ${RC_FILE} " FILEFLAGS 0x0L\n")
		file(APPEND ${RC_FILE} "#endif\n")
		file(APPEND ${RC_FILE} " FILEOS 0x40004L\n")
		file(APPEND ${RC_FILE} " FILETYPE ${_filetype}\n")
		file(APPEND ${RC_FILE} " FILESUBTYPE 0x0L\n")
		file(APPEND ${RC_FILE} "BEGIN\n")
		file(APPEND ${RC_FILE} "    BLOCK \"StringFileInfo\"\n")
		file(APPEND ${RC_FILE} "    BEGIN\n")
		file(APPEND ${RC_FILE} "        BLOCK \"040704b0\"\n")
		file(APPEND ${RC_FILE} "        BEGIN\n")
		file(APPEND ${RC_FILE} "            VALUE \"CompanyName\", \"${_companyname}\"\n")
		file(APPEND ${RC_FILE} "            VALUE \"FileDescription\", \"${_description}\"\n")
		file(APPEND ${RC_FILE} "            VALUE \"FileVersion\", FILE_VERSION_S\n")
		file(APPEND ${RC_FILE} "            VALUE \"InternalName\", FILE_NAME\n")
		file(APPEND ${RC_FILE} "            VALUE \"LegalCopyright\", \"${_copyright}\"\n")
		file(APPEND ${RC_FILE} "            VALUE \"OriginalFilename\", FILE_NAME\n")
		file(APPEND ${RC_FILE} "            VALUE \"ProductName\", TARGET_NAME\n")
		file(APPEND ${RC_FILE} "            VALUE \"ProductVersion\", FILE_VERSION_S\n")
		file(APPEND ${RC_FILE} "        END\n")
		file(APPEND ${RC_FILE} "    END\n")
		file(APPEND ${RC_FILE} "    BLOCK \"VarFileInfo\"\n")
		file(APPEND ${RC_FILE} "    BEGIN\n")
		file(APPEND ${RC_FILE} "        VALUE \"Translation\", 0x409, 1200\n")
		file(APPEND ${RC_FILE} "    END\n")
		file(APPEND ${RC_FILE} "END\n")
		target_sources(${_target} PRIVATE ${RC_FILE})
	endif()
endmacro(create_win32_resource_version)

macro(visual_studio_qt_helper)
	if(MSVC AND TARGET Qt::qmake)
		get_target_property(_qt_qmake_location Qt::qmake IMPORTED_LOCATION)
		execute_process(COMMAND "${_qt_qmake_location}" -query QT_INSTALL_PREFIX RESULT_VARIABLE return_code OUTPUT_VARIABLE qt_install_prefix OUTPUT_STRIP_TRAILING_WHITESPACE)
		set(VSUSER_FILE ${CMAKE_CURRENT_BINARY_DIR}/${ARGV0}.vcxproj.user)
		file(WRITE  ${VSUSER_FILE} "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n")
		file(APPEND ${VSUSER_FILE} "<Project xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\n")
		file(APPEND ${VSUSER_FILE} "  <PropertyGroup>\n")
		file(APPEND ${VSUSER_FILE} "    <LocalDebuggerEnvironment>PATH=$(SolutionDir)src\\SARibbonBar\\$(Configuration);${qt_install_prefix}\\bin;$(Path)\n")
		file(APPEND ${VSUSER_FILE} "$(LocalDebuggerEnvironment)</LocalDebuggerEnvironment>\n")
		file(APPEND ${VSUSER_FILE} "    <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>\n")
		file(APPEND ${VSUSER_FILE} "  </PropertyGroup>\n")
		file(APPEND ${VSUSER_FILE} "</Project>\n")
	endif()
endmacro(visual_studio_qt_helper)

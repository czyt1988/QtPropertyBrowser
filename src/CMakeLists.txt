
# QtPropertyBrowser库的cmake编译
cmake_minimum_required(VERSION 3.5)
message("")

set(QtPropertyBrowser_LIB_NAME "QtPropertyBrowser")
set(QtPropertyBrowser_DESCRIPTION "QtPropertyBrowser${QtPropertyBrowser_VERSION} - A property browser framework enabling the user to edit a set of properties")
project(${QtPropertyBrowser_LIB_NAME} 
        VERSION ${QtPropertyBrowser_VERSION} 
        LANGUAGES CXX
        DESCRIPTION ${QtPropertyBrowser_DESCRIPTION}
)
########################################################
# 通用常规设置
########################################################
# C++标准要求最低C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 编译选项
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")
set(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_RELWITHDEBINFO_POSTFIX "rd" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_MINSIZEREL_POSTFIX "s" CACHE STRING "add a postfix, usually empty on windows")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
########################################################
# MSVC设置
########################################################
if(MSVC)
# msvc utf-8
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()
########################################################
# Qt
########################################################
set(QtPropertyBrowser_MIN_QT_VERSION 5.6)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)

find_package(Qt${QT_VERSION_MAJOR} ${QtPropertyBrowser_MIN_QT_VERSION} COMPONENTS
    Core
    Gui
    Widgets
    REQUIRED
)

if(Qt5_POSITION_INDEPENDENT_CODE)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

########################################################
# 目录包含
########################################################
# 包含自身目录
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/moc)

########################################################
# 文件加载
########################################################
SET(KIT_HEADER 
  qtpropertybrowserglobal.h
  qtbuttonpropertybrowser.h
  qteditorfactory.h
  qtgroupboxpropertybrowser.h
  qtpropertybrowser.h
  qtpropertybrowserutils_p.h
  qtpropertymanager.h
  qttreepropertybrowser.h
  qtvariantproperty.h
)

SET(KIT_HEADER_PRIVATE
  qtpropertybrowserutils_p.h
)

SET(KIT_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/qt${QT_VERSION_MAJOR}/qtbuttonpropertybrowser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/qt${QT_VERSION_MAJOR}/qteditorfactory.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/qt${QT_VERSION_MAJOR}/qtgroupboxpropertybrowser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/qt${QT_VERSION_MAJOR}/qtpropertybrowser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/qt${QT_VERSION_MAJOR}/qtpropertybrowserutils.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/qt${QT_VERSION_MAJOR}/qtpropertymanager.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/qt${QT_VERSION_MAJOR}/qttreepropertybrowser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/qt${QT_VERSION_MAJOR}/qtvariantproperty.cpp
)
SET(KIT_RESOURCE
  qtpropertybrowser.qrc
)



add_library(${QtPropertyBrowser_LIB_NAME} SHARED
  ${KIT_HEADER}
  ${KIT_HEADER_PRIVATE}
  ${KIT_SOURCE}
  ${KIT_RESOURCE}
)
# 启用别名，通过QtPropertyBrowser::QtPropertyBrowser 引入
add_library(${QtPropertyBrowser_LIB_NAME}::${QtPropertyBrowser_LIB_NAME} ALIAS ${QtPropertyBrowser_LIB_NAME})
# 构建库定义的宏
target_compile_definitions(${QtPropertyBrowser_LIB_NAME} PRIVATE QT_QTPROPERTYBROWSER_MAKE_LIB)

########################################################
# 依赖链接
########################################################
target_link_libraries(${QtPropertyBrowser_LIB_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

if(${QT_VERSION_MAJOR} EQUAL 6)
   find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
   target_link_libraries(${QtPropertyBrowser_LIB_NAME} PRIVATE Qt6::Core5Compat)
endif()



########################################################
# 设置target属性，以及Qt的moc
########################################################
# 在同一个 CMake build tree 中，每个项目的 targets 对外都是可见的
set_target_properties(${QtPropertyBrowser_LIB_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    CXX_EXTENSIONS OFF
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
    VERSION ${QtPropertyBrowser_VERSION}
    EXPORT_NAME ${QtPropertyBrowser_LIB_NAME}
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

########################################################
# 目标依赖目录
########################################################
target_include_directories(${QtPropertyBrowser_LIB_NAME} PUBLIC
  $<INSTALL_INTERFACE:include/${QtPropertyBrowser_LIB_NAME}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

########################################################
# 安装
########################################################
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

message(STATUS "${QtPropertyBrowser_LIB_NAME} install dir is : ${CMAKE_INSTALL_PREFIX}")
# xxx.cmake.in中，会让此变量和“${PACKAGE_PREFIX_DIR}/”进行拼接，也就是${PACKAGE_PREFIX_DIR}/@QtPropertyBrowser_LIB_INCLUDE_INSTALL_DIR@
# PACKAGE_PREFIX_DIR = ${CMAKE_CURRENT_LIST_DIR}/../..
# 最终变为${CMAKE_CURRENT_LIST_DIR}/../../include/${QtPropertyBrowser_LIB_NAME}
set(QtPropertyBrowser_LIB_INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_INCLUDEDIR}/${QtPropertyBrowser_LIB_NAME})

# Generate library version info which will generate xxxConfigVersion.cmake,
# the ${PACKAGE_VERSION} is the version defined in project()

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${QtPropertyBrowser_LIB_NAME}ConfigVersion.cmake
    VERSION ${QtPropertyBrowser_VERSION}
    COMPATIBILITY SameMajorVersion
)
configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/QtPropertyBrowserConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/${QtPropertyBrowser_LIB_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${QtPropertyBrowser_LIB_NAME}
  PATH_VARS QtPropertyBrowser_LIB_INCLUDE_INSTALL_DIR
)

# 声明导出target的名称
install(TARGETS ${QtPropertyBrowser_LIB_NAME}
    EXPORT ${QtPropertyBrowser_LIB_NAME}Targets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${QtPropertyBrowser_LIB_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(EXPORT "${QtPropertyBrowser_LIB_NAME}Targets"
    FILE ${QtPropertyBrowser_LIB_NAME}Targets.cmake # 导出的文件基准名。
    NAMESPACE ${QtPropertyBrowser_LIB_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${QtPropertyBrowser_LIB_NAME}
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${QtPropertyBrowser_LIB_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${QtPropertyBrowser_LIB_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${QtPropertyBrowser_LIB_NAME}
)

install(FILES
    ${KIT_HEADER}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${QtPropertyBrowser_LIB_NAME}
    COMPONENT headers
)

set(KIT_INCLASS_INCLUDES
    QtAbstractEditorFactoryBase
    QtAbstractPropertyBrowser
    QtAbstractPropertyManager
    QtBoolPropertyManager
    QtBrowserItem
    QtButtonPropertyBrowser
    QtCharEditorFactory
    QtCharPropertyManager
    QtCheckBoxFactory
    QtColorEditorFactory
    QtColorPropertyManager
    QtCursorEditorFactory
    QtCursorPropertyManager
    QtDateEditFactory
    QtDatePropertyManager
    QtDateTimeEditFactory
    QtDateTimePropertyManager
    QtDoublePropertyManager
    QtDoubleSpinBoxFactory
    QtEnumEditorFactory
    QtEnumPropertyManager
    QtFlagPropertyManager
    QtFontEditorFactory
    QtFontPropertyManager
    QtGroupBoxPropertyBrowser
    QtGroupPropertyManager
    QtIntPropertyManager
    QtKeySequenceEditorFactory
    QtKeySequencePropertyManager
    QtLineEditFactory
    QtLocalePropertyManager
    QtPointFPropertyManager
    QtPointPropertyManager
    QtProperty
    QtRectFPropertyManager
    QtRectPropertyManager
    QtScrollBarFactory
    QtSizeFPropertyManager
    QtSizePolicyPropertyManager
    QtSizePropertyManager
    QtSliderFactory
    QtSpinBoxFactory
    QtStringPropertyManager
    QtTimeEditFactory
    QtTimePropertyManager
    QtTreePropertyBrowser
    QtVariantEditorFactory
    QtVariantProperty
    QtVariantPropertyManager
)
install(FILES
    ${KIT_INCLASS_INCLUDES}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${QtPropertyBrowser_LIB_NAME}
    COMPONENT headers
)

export(EXPORT ${QtPropertyBrowser_LIB_NAME}Targets
   FILE ${CMAKE_CURRENT_BINARY_DIR}/${QtPropertyBrowser_LIB_NAME}Targets.cmake
)

########################################################
# dll资源信息
########################################################
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/create_win32_resource_version.cmake)
if(WIN32)
        create_win32_resource_version(
                TARGET ${QtPropertyBrowser_LIB_NAME}
                FILENAME ${QtPropertyBrowser_LIB_NAME}
                VERSION ${QtPropertyBrowser_VERSION}
                EXT "dll"
                COMPANYNAME "Qt"
                COPYRIGHT "LGPL"
                DESCRIPTION ${QtPropertyBrowser_DESCRIPTION}
        )
endif()

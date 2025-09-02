# QtPropertyBrowser cmake 
# 可适用于Qt5/6
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
set(QtPropertyBrowser_VERSION_MAJOR 2)
set(QtPropertyBrowser_VERSION_MINOR 6)
set(QtPropertyBrowser_VERSION_PATCH 0)
set(QtPropertyBrowser_VERSION "${QtPropertyBrowser_VERSION_MAJOR}.${QtPropertyBrowser_VERSION_MINOR}.${QtPropertyBrowser_VERSION_PATCH}")
message(STATUS "QtPropertyBrowser Version is ${QtPropertyBrowser_VERSION}")
message(STATUS "Original source code is archived at https://qt.gitorious.org/qt-solutions/qt-solutions This fork adds CMake")
########################################################
# 定义工程
########################################################
set(QtPropertyBrowser_PROJECT_NAME "QtPropertyBrowser-project")
project(${QtPropertyBrowser_PROJECT_NAME} 
        VERSION ${QtPropertyBrowser_VERSION} 
        LANGUAGES CXX
        DESCRIPTION "QtPropertyBrowser - A property browser framework enabling the user to edit a set of properties. Original source code is archived at https://qt.gitorious.org/qt-solutions/qt-solutions This fork adds CMake"
        )

OPTION(QtPropertyBrowser_BUILD_EXAMPLES "Build examples" OFF)

########################################################
# 一些常规设置
########################################################


set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")
set(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_RELWITHDEBINFO_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_MINSIZEREL_POSTFIX "s" CACHE STRING "add a postfix, usually empty on windows")

# c++标准，要求为11
set(CMAKE_CXX_STANDARD 11)
# 强制要求
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#-----------------------------------------------------------------------------
# Qt
#
########################################################
# 安装路径设置
########################################################
set(QtPropertyBrowser_MIN_QT_VERSION 5.6)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
    set(QtPropertyBrowser_PLATFORM_NAME "x86")
else()
    set(QtPropertyBrowser_PLATFORM_NAME "x64")
endif()
set(QtPropertyBrowser_BIN_DIR_NAME bin_qt${QT_VERSION}_${CMAKE_BUILD_TYPE}_${QtPropertyBrowser_PLATFORM_NAME})


if(WIN32)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/${QtPropertyBrowser_BIN_DIR_NAME}")
endif()

#-----------------------------------------------------------------------------
# Subdirectories
#
add_subdirectory(src)
IF(QtPropertyBrowser_BUILD_EXAMPLES)
  add_subdirectory(examples)
ENDIF()


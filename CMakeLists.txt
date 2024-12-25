cmake_minimum_required(VERSION 3.13)

set(FLAMESHOT_VERSION 12.1.0)

# Flameshot-org
set(GIT_API_URL "https://api.github.com/repos/flameshot-org/flameshot/releases/latest")
# Namecheap
# set(GIT_API_URL "https://api.github.com/repos/namecheap/flameshot/releases/latest")

# TODO - fix it for all linux distros
#find_package (Git)
#if (GIT_FOUND)
#  message("git found: ${GIT_EXECUTABLE} in version     ${GIT_VERSION_STRING}")
#
#  # set flameshot updates url
#  execute_process(COMMAND ${GIT_EXECUTABLE} ls-remote --get-url OUTPUT_VARIABLE GIT_ORIGIN_REMOTE)
#  message("GIT_ORIGIN_REMOTE: ${GIT_ORIGIN_REMOTE}")
#  string(REGEX REPLACE ".git\r*\n*$" "/releases/latest" GIT_API_URL ${GIT_ORIGIN_REMOTE})
#  string(REGEX REPLACE "^.*:" "https://api.github.com/repos/" GIT_API_URL ${GIT_API_URL})
#  message("GIT_API_URL: '${GIT_API_URL}'")
#
#  # get application version
#  execute_process(COMMAND ${GIT_EXECUTABLE} describe --tags --abbrev=0 --match v[0-9]* OUTPUT_VARIABLE FLAMESHOT_VERSION)
#  string(REGEX REPLACE "\r" "" FLAMESHOT_VERSION ${FLAMESHOT_VERSION})
#  string(REGEX REPLACE "\n" "" FLAMESHOT_VERSION ${FLAMESHOT_VERSION})
#  string(REGEX REPLACE "^v" "" FLAMESHOT_VERSION ${FLAMESHOT_VERSION})
#  message("FLAMESHOT_VERSION: '${FLAMESHOT_VERSION}'")
#else()
#  message("git command is not found")
#endif ()

project(
        demo
        VERSION 0.1
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)


# Configuration options
set(DEFAULT_RUN_IN_PLACE FALSE)
set(RUN_IN_PLACE
        ${DEFAULT_RUN_IN_PLACE}
        CACHE BOOL "Run directly in source directory structure")


option(FLAMESHOT_DEBUG_CAPTURE "Enable mode to make debugging easier" OFF)
option(USE_MONOCHROME_ICON "Build using monochrome icon as default" OFF)
option(GENERATE_TS "Regenerate translation source files" OFF)
option(USE_EXTERNAL_SINGLEAPPLICATION "Use external QtSingleApplication library" OFF)
option(USE_LAUNCHER_ABSOLUTE_PATH "Use absolute path for the desktop launcher" ON)
option(USE_WAYLAND_CLIPBOARD "USE KF Gui Wayland Clipboard" OFF)
option(DISABLE_UPDATE_CHECKER "Disable check for updates" OFF)
if (DISABLE_UPDATE_CHECKER)
  add_compile_definitions(DISABLE_UPDATE_CHECKER)
endif ()

# Generate compile_commands.json to make it easier to work with clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE
      RelWithDebInfo
      CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui, ccmake
  set_property(
    CACHE CMAKE_BUILD_TYPE
    PROPERTY STRINGS
             "Debug"
             "Release"
             "MinSizeRel"
             "RelWithDebInfo")
endif()


set(QAPPLICATION_CLASS
        QApplication
        CACHE STRING "Inheritance class for SingleApplication")


option(BUILD_STATIC_LIBS ON)
option(BUILD_SHARED_LIBS OFF)

add_subdirectory(src)

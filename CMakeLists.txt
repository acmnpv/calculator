# I prefer setting up projects with CMake due to working 
# with it for several years now and it allowing easy checking
# for available features and compiler versions
#
# I'm using a fairly recent CMake here, but any not too ancient
# version should work as well.

cmake_minimum_required(VERSION 3.18)

# I'm using the name I gave the project in the readme.
project (calculator VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(Ctest)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


# Add some checks for compilation and headers, to make sure we at least have C++17 support
include(CheckIncludeFileCXX)
include(CheckCXXSourceCompiles) 
include(CheckCXXCompilerFlag) 
check_include_file_cxx(iostream HAVE_IOSTREAM)
check_include_file_cxx(numeric HAVE_NUMERIC)

if (NOT HAVE_IOSTREAM OR NOT HAVE_NUMERIC)
        message(FATAL_ERROR "Need to have full support for all dependencies")
endif()

# STATIC stuff (Windows)
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(BUILD_FOR_WIN TRUE)
endif()
option(STATIC_BUILD "Build a static binary." ${BUILD_FOR_WIN})

if (STATIC_BUILD)
        set(CMAKE_EXE_LINKER_FLAGS "-static")
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" CONFIG)
        set(BUILD_SHARED_LIBS OFF)
endif()


# little helper for checking if we can enable a warning flag
function(can_enable_warning TARGET FLAG_NAME VARIABLENAME)
        check_cxx_compiler_flag(${FLAG_NAME} ${VARIABLENAME})
    if (${VARIABLENAME})
          target_compile_options(${TARGET} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${FLAG_NAME}>)
    endif()
endfunction()

# The project is quite simple, so we don't need to do much setup or checking
# I set up a separate library/executable target because this allows testing
# against the linked library, but it is not really necessary for a simple
# project like this.

add_library(calculator_library OBJECT
        src/coulomb.cpp
        src/lennardjones.cpp
        src/particle.cpp
        src/geometry.cpp)

target_include_directories(calculator_library PUBLIC ${PROJECT_SOURCE_DIR}/include)

can_enable_warning(calculator_library "-Weverything" HAS_WARNING_EVERYTHING)
can_enable_warning(calculator_library "-Wall" HAS_WARNING_ALL)
can_enable_warning(calculator_library "-Wno-c++98-compat" HAS_WARNING_NO_CPLUSPLUS98_COMPAT)
can_enable_warning(calculator_library "-Wno-c++98-compat-pedantic" HAS_WARNING_NO_CPLUSPLUS98_COMPAT_PEDANTIC)

target_link_libraries(calculator_library ${CONAN_LIBS})

# Add an executable
add_executable(calculator calculator.cpp)
target_link_libraries(calculator PRIVATE calculator_library)
target_link_libraries(calculator ${CONAN_LIBS})

can_enable_warning(calculator "-Weverything" HAS_WARNING_EVERYTHING)
can_enable_warning(calculator "-Wall" HAS_WARNING_ALL)
can_enable_warning(calculator "-Wno-c++98-compat" HAS_WARNING_NO_CPLUSPLUS98_COMPAT)
can_enable_warning(calculator "-Wno-c++98-compat-pedantic" HAS_WARNING_NO_CPLUSPLUS98_COMPAT_PEDANTIC)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif()

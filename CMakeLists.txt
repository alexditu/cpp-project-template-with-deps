cmake_minimum_required (VERSION 3.18)

project (cpp-project-template-with-deps)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)
set (CMAKE_CXX_VISIBILITY_PRESET hidden)
set (CMAKE_VISIBILITY_INLINES_HIDDEN YES)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED True)

# 3rd party deps
include (FetchContent)

set (FETCHCONTENT_QUIET Off)

set (THIRD_PARTY_DEPS "thirdpartydeps")
FetchContent_Declare (${THIRD_PARTY_DEPS}
	URL "file:///opt/third_party_cpp_deps.tar.gz"
	# URL_HASH SHA256=6f393368e20c5760abaf008c4f972f03ee51e3c6e97941956490aadbc12a9c9b
)

FetchContent_GetProperties (${THIRD_PARTY_DEPS})

if (NOT ${THIRD_PARTY_DEPS}_POPULATED)
	FetchContent_Populate (${THIRD_PARTY_DEPS})
endif ()

set (THIRD_PARTY_DEPS_DIR "${${THIRD_PARTY_DEPS}_SOURCE_DIR}")
include ("${THIRD_PARTY_DEPS_DIR}/third_party_cpp_deps.cmake")

message (STATUS "UsingTHIRD_PARTY_DEPS_DIR: ${THIRD_PARTY_DEPS_DIR}")



# project specific options:

add_compile_options (-Wall -Wextra -g -ggdb -pthread -fno-common -fstack-protector -fno-omit-frame-pointer)

add_third_party_include_dir_global (${THIRD_PARTY_DEPS_DIR})
add_third_party_lib_dir_global (${THIRD_PARTY_DEPS_DIR})

link_libraries (spdlog)

add_subdirectory (src)
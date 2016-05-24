# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (DG_CPP)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()


# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)

include_directories(
	external/glfw-3.0.3/include/GLFW/
	external/glm-0.9.7.0/
	external/glew-1.9.0/include/
	external/Box2D/
	dg_cpp/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	GLFW_303
	GLEW_190
	dg_cpp
	Box2D
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# dg_cpp library
add_library(dg_cpp
	dg_cpp/camera.cpp
	dg_cpp/camera.h
	dg_cpp/gameobject.cpp
	dg_cpp/gameobject.h
	dg_cpp/line.cpp
	dg_cpp/line.h
	dg_cpp/pointx.h
	dg_cpp/renderer.cpp
	dg_cpp/renderer.h
	dg_cpp/scene.cpp
	dg_cpp/scene.h
	dg_cpp/settings.h
	dg_cpp/shader.cpp
	dg_cpp/shader.h
	dg_cpp/texture.cpp
	dg_cpp/texture.h
	dg_cpp/timer.cpp
	dg_cpp/timer.h
)
file(
	COPY ${CMAKE_SOURCE_DIR}/dg_cpp/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)

# Demo
add_executable(demo
	demo/main.cpp
	demo/box2ddemo.cpp
	demo/box2ddemo.h
	demo/scene01.cpp
	demo/scene01.h
)
file(
	COPY ${CMAKE_SOURCE_DIR}/demo/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)

if(UNIX)
	set(BOX2D_INSTALL_BY_DEFAULT ON)
else(UNIX)
	set(BOX2D_INSTALL_BY_DEFAULT OFF)
endif(UNIX)

option(BOX2D_INSTALL "Install Box2D libs, includes, and CMake scripts" ${BOX2D_INSTALL_BY_DEFAULT})
option(BOX2D_INSTALL_DOC "Install Box2D documentation" OFF)
option(BOX2D_BUILD_SHARED "Build Box2D shared libraries" OFF)
option(BOX2D_BUILD_STATIC "Build Box2D static libraries" ON)
option(BOX2D_BUILD_EXAMPLES "Build Box2D examples" ON)

set(BOX2D_VERSION 2.3.2)
set(LIB_INSTALL_DIR lib${LIB_SUFFIX})

# The Box2D library.
add_subdirectory(external/Box2D)


target_link_libraries(demo
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(demo PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/demo/")
create_target_launcher(demo WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/demo/")

SOURCE_GROUP(dg_cpp REGULAR_EXPRESSION ".*/dg_cpp/.*" )
SOURCE_GROUP(demo REGULAR_EXPRESSION ".*/demo/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shaders$" )

if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
#add_custom_command(
#   TARGET demo POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/demo${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/demo/"
#)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

cmake_minimum_required (VERSION 3.1)

if(DEFINED ENV{VCPKG_DEFAULT_TRIPLET})
  message(STATUS "Setting default vcpkg target triplet to $ENV{VCPKG_DEFAULT_TRIPLET}")
  set(VCPKG_TARGET_TRIPLET $ENV{VCPKG_DEFAULT_TRIPLET})
endif()

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
  message(STATUS "VCPKG found: $ENV{VCPKG_ROOT}")
  message(STATUS "Using VCPKG integration")
  message(STATUS "VCPKG_MANIFEST_FEATURES: ${VCPKG_MANIFEST_FEATURES}")
elseif(DEFINED CMAKE_TOOLCHAIN_FILE)
  message(STATUS "Using toolchain: ${CMAKE_TOOLCHAIN_FILE}")
  if(CMAKE_TOOLCHAIN_FILE MATCHES "vcpkg.cmake")
    message(STATUS "Toolchain uses VCPKG integration")
    message(STATUS "VCPKG_MANIFEST_FEATURES: ${VCPKG_MANIFEST_FEATURES}")
  endif()
else()
  message(WARNING "vcpkg not found, toolchain not defined, build might fail")
endif()

project (metnum)
set(CMAKE_CXX_STANDARD 11)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}" CACHE PATH "Install prefix" FORCE)
endif()

set(INSTALL_BIN_DIR      "bin"                   CACHE PATH "Path where exe and dll will be installed")
set(INSTALL_LIB_DIR      "lib"                   CACHE PATH "Path where lib will be installed")
set(INSTALL_INCLUDE_DIR  "include"               CACHE PATH "Path where headers will be installed ")
set(INSTALL_CMAKE_DIR    "share/${PROJECT_NAME}" CACHE PATH "Path where cmake configs will be installed")

find_package(OpenGL REQUIRED)
find_package(FLTK CONFIG REQUIRED)

include_directories(${FLTK_INCLUDE_DIR})

add_executable(hello_fltk  ${CMAKE_SOURCE_DIR}/grafica_fltk/hello_fltk.cpp)
add_executable(button_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/button_fltk.cpp)
add_executable(events_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/events_fltk.cpp)
add_executable(mouse_fltk  ${CMAKE_SOURCE_DIR}/grafica_fltk/mouse_fltk.cpp)
add_executable(slider_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/slider_fltk.cpp)
add_executable(harm        ${CMAKE_SOURCE_DIR}/harm/harm.cpp)
add_executable(langevin    ${CMAKE_SOURCE_DIR}/langevin/langevin.cpp)
add_executable(quadratura  ${CMAKE_SOURCE_DIR}/quadratura/quadratura.cpp)
add_executable(simplettici ${CMAKE_SOURCE_DIR}/simplettici/simplettici.cpp)
add_executable(wave        ${CMAKE_SOURCE_DIR}/wave/wave.cpp)
add_executable(z3          ${CMAKE_SOURCE_DIR}/z3/z3.cpp)

target_link_libraries(hello_fltk  fltk_gl OpenGL::GL OpenGL::GLU)
target_link_libraries(button_fltk fltk_gl OpenGL::GL OpenGL::GLU)
target_link_libraries(events_fltk fltk_gl OpenGL::GL OpenGL::GLU)
target_link_libraries(mouse_fltk  fltk_gl OpenGL::GL OpenGL::GLU)
target_link_libraries(slider_fltk fltk_gl OpenGL::GL OpenGL::GLU)

if(MSVC)
  target_compile_definitions(quadratura  PRIVATE _CRT_SECURE_NO_WARNINGS)
  target_compile_definitions(wave        PRIVATE _CRT_SECURE_NO_WARNINGS)
  target_compile_definitions(z3          PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

if(UNIX)
  target_link_libraries(hello_fltk  ${CMAKE_DL_LIBS})
  target_link_libraries(button_fltk ${CMAKE_DL_LIBS})
  target_link_libraries(events_fltk ${CMAKE_DL_LIBS})
  target_link_libraries(mouse_fltk  ${CMAKE_DL_LIBS})
  target_link_libraries(slider_fltk ${CMAKE_DL_LIBS})
endif()

install (TARGETS
    hello_fltk
    button_fltk
    events_fltk
    mouse_fltk
    slider_fltk
    harm
    langevin
    quadratura
    simplettici
    wave
    z3
    DESTINATION
    ${INSTALL_BIN_DIR}
)

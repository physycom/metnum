cmake_minimum_required (VERSION 3.1)
project (metnum)
set(CMAKE_CXX_STANDARD 11)


macro(configure_link_flags)
  # Set compiler options.
  set(MSVC_C_CXX_FLAGS
    CMAKE_C_FLAGS_DEBUG
    CMAKE_C_FLAGS_MINSIZEREL
    CMAKE_C_FLAGS_RELEASE
    CMAKE_C_FLAGS_RELWITHDEBINFO
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_MINSIZEREL
    CMAKE_CXX_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_RELWITHDEBINFO
  )
  if(${VCPKG_TARGET_TRIPLET} MATCHES "static")
    message(STATUS
      "VCPKG: static link"
    )
    foreach(flag ${MSVC_C_CXX_FLAGS})
      if(${flag} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
      endif()
    endforeach()
  else()
    message(STATUS
      "VCPKG: dynamic link"
    )
    foreach(flag ${MSVC_C_CXX_FLAGS})
      if(${flag} MATCHES "/MT")
        string(REGEX REPLACE "/MT" "/MD" ${flag} "${${flag}}")
      endif()
    endforeach()
  endif()
endmacro()

macro(print_link_flags)
  set(MSVC_C_CXX_FLAGS
    CMAKE_C_FLAGS_DEBUG
    CMAKE_C_FLAGS_MINSIZEREL
    CMAKE_C_FLAGS_RELEASE
    CMAKE_C_FLAGS_RELWITHDEBINFO
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_MINSIZEREL
    CMAKE_CXX_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_RELWITHDEBINFO
  )
  message(STATUS "Initial build flags:")
  foreach(flag ${MSVC_C_CXX_FLAGS})
    message(STATUS "  '${flag}': ${${flag}}")
  endforeach()
  message(STATUS "")
endmacro()

if(MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  configure_link_flags()
  #print_link_flags()
endif()

if (APPLE)
	add_definitions(-Wno-deprecated-declarations)
endif()


# make sure that the default is a RELEASE
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RELEASE)
endif()


### Set output directories on a per-configuration base
# Single configuration
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )
# Multi configuration
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

find_package(OpenGL REQUIRED)
find_package(FLTK REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${FLTK_INCLUDE_DIR})

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

target_link_libraries(hello_fltk  ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(button_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(events_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(mouse_fltk  ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(slider_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})

if(UNIX)
target_link_libraries(hello_fltk  ${CMAKE_DL_LIBS} )
target_link_libraries(button_fltk ${CMAKE_DL_LIBS} )
target_link_libraries(events_fltk ${CMAKE_DL_LIBS} )
target_link_libraries(mouse_fltk  ${CMAKE_DL_LIBS} )
target_link_libraries(slider_fltk ${CMAKE_DL_LIBS} )
endif()

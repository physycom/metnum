cmake_minimum_required(VERSION 2.8)
project(metnum)
set(CMAKE_CXX_STANDARD 11)

if(MSVC)
  set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
  foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    string(REPLACE "/MDd" "/MTd" ${CompilerFlag} "${${CompilerFlag}}")
  endforeach()
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:LIBCMT")
  #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:LIBCMTD")
  set(FLTK_SKIP_FLUID TRUE)
  set(Boost_USE_STATIC_LIBS ON)
  set(Boost_USE_STATIC_RUNTIME ON)
endif()

find_package(Boost REQUIRED)
find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${FLTK_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${PROJECT_BINARY_DIR}) 
add_executable(hello_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/hello_fltk.cpp)
add_executable(button_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/button_fltk.cpp)
add_executable(events_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/events_fltk.cpp)
add_executable(mouse_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/mouse_fltk.cpp)
add_executable(slider_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/slider_fltk.cpp)
add_executable(harm ${CMAKE_SOURCE_DIR}/harm/harm.cpp)
add_executable(langevin ${CMAKE_SOURCE_DIR}/langevin/langevin.cpp)
add_executable(quadratura ${CMAKE_SOURCE_DIR}/quadratura/quadratura.cpp)
add_executable(simplettici ${CMAKE_SOURCE_DIR}/simplettici/simplettici.cpp)
add_executable(wave ${CMAKE_SOURCE_DIR}/wave/wave.cpp)
add_executable(z3 ${CMAKE_SOURCE_DIR}/z3/z3.cpp)
target_link_libraries(hello_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(button_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(events_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(mouse_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(slider_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})

install (TARGETS hello_fltk button_fltk events_fltk mouse_fltk slider_fltk harm langevin quadratura simplettici wave z3 DESTINATION ${CMAKE_SOURCE_DIR}/bin)

cmake_minimum_required(VERSION 2.8)
project(metnum)
set(CMAKE_CXX_STANDARD 11)

if(MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  set(FLTK_SKIP_FLUID TRUE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT")
  set(Boost_USE_STATIC_LIBS ON)
  set(Boost_USE_STATIC_RUNTIME ON)
endif()

find_package(Boost REQUIRED)
find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


include_directories(${Boost_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${PROJECT_BINARY_DIR}) 
add_executable(hello_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/hello_fltk.cpp)
add_executable(slider_fltk ${CMAKE_SOURCE_DIR}/grafica_fltk/slider_fltk.cpp)
add_executable(harm ${CMAKE_SOURCE_DIR}/harm/harm.cpp)
add_executable(langevin ${CMAKE_SOURCE_DIR}/langevin/langevin.cpp)
add_executable(quadratura ${CMAKE_SOURCE_DIR}/quadratura/quadratura.cpp)
add_executable(simplettici ${CMAKE_SOURCE_DIR}/simplettici/simplettici.cpp)
add_executable(wave ${CMAKE_SOURCE_DIR}/wave/wave.cpp)
add_executable(z3 ${CMAKE_SOURCE_DIR}/z3/z3.cpp)
target_link_libraries(hello_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_link_libraries(slider_fltk ${FLTK_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})

install (TARGETS hello_fltk slider_fltk harm langevin quadratura simplettici wave z3 
	DESTINATION ${CMAKE_SOURCE_DIR}/bin)

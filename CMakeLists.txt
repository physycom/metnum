cmake_minimum_required (VERSION 3.1)
project (metnum)
set(CMAKE_CXX_STANDARD 11)

if (EXISTS "$ENV{WORKSPACE}/sysconfig/cmake/physycom_config.cmake")
   message(STATUS "Enabling physycom settings")
   include("$ENV{WORKSPACE}/sysconfig/cmake/physycom_config.cmake")
else()
   message(STATUS "Unable to find physycom settings file")
endif()

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
    ${CMAKE_SOURCE_DIR}/bin/
)

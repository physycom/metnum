LINKED_LIBS  = -lfltk -lfltk_gl -lglut 

MY_OS := $(shell uname -s)
ifeq ($(MY_OS),Darwin)
LINKED_LIBS += -framework OpenGL
else
LINKED_LIBS += -lGL -lGLU
endif


test:
	$(CXX) -std=c++11 grafica_test.cpp $(LINKED_LIBS)



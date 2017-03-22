
TOOLS := grafica_fltk \
harm \
langevin \
quadratura \
simplettici \
wave \
z3


all:
	@for i in $(TOOLS) ; do \
	$(MAKE) -C $$i ;\
	done

	

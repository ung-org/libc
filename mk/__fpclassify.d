libm_C.0: libm.a(__fpclassify.o)
libm.a(__fpclassify.o): $(OBJDIR)/__fpclassify.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/__fpclassify.o: src/math/__fpclassify.c
$(OBJDIR)/__fpclassify.o: src/complex/_tgmath.h
$(OBJDIR)/src/math/_tgmath.h.o: 
$(OBJDIR)/__fpclassify.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/math/__fpclassify.c

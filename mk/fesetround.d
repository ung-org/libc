libm_C.199901: libm.a(fesetround.o)
libm.a(fesetround.o): $(OBJDIR)/fesetround.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/fesetround.o: src/fenv/fesetround.c
$(OBJDIR)/fesetround.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/fenv/fesetround.c

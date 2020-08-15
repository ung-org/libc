libc_X.400: libc.a(setstate.o)
libc.a(setstate.o): $(OBJDIR)/setstate.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/setstate.o: src/stdlib/setstate.c
$(OBJDIR)/setstate.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/stdlib/setstate.c

libc_C.1: libc.a(wctomb.o)
libc.a(wctomb.o): $(OBJDIR)/wctomb.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/wctomb.o: src/stdlib/wctomb.c
$(OBJDIR)/wctomb.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/stdlib/wctomb.c

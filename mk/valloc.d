libc_X.400: libc.a(valloc.o)
libc.a(valloc.o): $(OBJDIR)/valloc.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/valloc.o: src/stdlib/valloc.c
$(OBJDIR)/valloc.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/stdlib/valloc.c

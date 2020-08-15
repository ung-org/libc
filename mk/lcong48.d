libc_X.4: libc.a(lcong48.o)
libc.a(lcong48.o): $(OBJDIR)/lcong48.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/lcong48.o: src/stdlib/lcong48.c
$(OBJDIR)/lcong48.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/stdlib/lcong48.c

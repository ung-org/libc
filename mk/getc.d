libc_C.1: libc.a(getc.o)
libc.a(getc.o): $(OBJDIR)/getc.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/getc.o: src/stdio/getc.c
$(OBJDIR)/getc.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/stdio/getc.c

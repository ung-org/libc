libc_C.1: libc.a(div.o)
libc.a(div.o): $(OBJDIR)/div.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/div.o: src/stdlib/div.c
$(OBJDIR)/div.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/stdlib/div.c

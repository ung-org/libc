libc_C.199901: libc.a(atoll.o)
libc.a(atoll.o): $(OBJDIR)/atoll.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/atoll.o: src/stdlib/atoll.c
$(OBJDIR)/atoll.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/stdlib/atoll.c

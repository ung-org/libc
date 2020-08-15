libc_C.1: libc.a(memcmp.o)
libc.a(memcmp.o): $(OBJDIR)/memcmp.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/memcmp.o: src/string/memcmp.c
$(OBJDIR)/memcmp.o: src/_assert.h
$(OBJDIR)/memcmp.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/string/memcmp.c

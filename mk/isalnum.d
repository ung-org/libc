libc_C.1: libc.a(isalnum.o)
libc.a(isalnum.o): $(OBJDIR)/isalnum.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/isalnum.o: src/ctype/isalnum.c
$(OBJDIR)/isalnum.o: src/_assert.h
$(OBJDIR)/isalnum.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/ctype/isalnum.c

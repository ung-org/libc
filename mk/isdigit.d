libc_C.1: libc.a(isdigit.o)
libc.a(isdigit.o): $(OBJDIR)/isdigit.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/isdigit.o: src/ctype/isdigit.c
$(OBJDIR)/isdigit.o: src/_assert.h
$(OBJDIR)/isdigit.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/ctype/isdigit.c

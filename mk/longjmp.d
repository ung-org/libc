libc_C.1: libc.a(longjmp.o)
libc.a(longjmp.o): $(OBJDIR)/longjmp.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/longjmp.o: src/setjmp/longjmp.c
$(OBJDIR)/longjmp.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/setjmp/longjmp.c

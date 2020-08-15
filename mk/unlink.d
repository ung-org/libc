libc_P.1: libc.a(unlink.o)
libc.a(unlink.o): $(OBJDIR)/unlink.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/unlink.o: src/unistd/unlink.c
$(OBJDIR)/unlink.o: src/_assert.h
$(OBJDIR)/unlink.o: src/_syscall.h
$(OBJDIR)/unlink.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/unistd/unlink.c

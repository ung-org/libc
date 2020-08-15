libc_P.1: libc.a(pipe.o)
libc.a(pipe.o): $(OBJDIR)/pipe.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/pipe.o: src/unistd/pipe.c
$(OBJDIR)/pipe.o: src/_assert.h
$(OBJDIR)/pipe.o: src/_syscall.h
$(OBJDIR)/pipe.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/unistd/pipe.c

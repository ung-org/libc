libc_C.0: libc.a(__checked_call.o)
libc.a(__checked_call.o): $(OBJDIR)/__checked_call.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/__checked_call.o: src/__checked_call.c
$(OBJDIR)/__checked_call.o: src/_assert.h
$(OBJDIR)/__checked_call.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/__checked_call.c

libc_X.4: libc.a(strptime.o)
libc.a(strptime.o): $(OBJDIR)/strptime.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/strptime.o: src/time/strptime.c
$(OBJDIR)/strptime.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/time/strptime.c

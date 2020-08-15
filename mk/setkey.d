libc_X.4: libc.a(setkey.o)
libc.a(setkey.o): $(OBJDIR)/setkey.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/setkey.o: src/stdlib/setkey.c
$(OBJDIR)/setkey.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/stdlib/setkey.c

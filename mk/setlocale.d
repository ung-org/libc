libc_C.1: libc.a(setlocale.o)
libc.a(setlocale.o): $(OBJDIR)/setlocale.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/setlocale.o: src/locale/setlocale.c
$(OBJDIR)/setlocale.o: src/locale/_locale.h
$(OBJDIR)/setlocale.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/locale/setlocale.c

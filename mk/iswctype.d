libc_C.199409: libc.a(iswctype.o)
libc.a(iswctype.o): $(OBJDIR)/iswctype.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/iswctype.o: src/wctype/iswctype.c
$(OBJDIR)/iswctype.o: src/_assert.h
$(OBJDIR)/iswctype.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/wctype/iswctype.c

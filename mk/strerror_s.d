libc_C_X1.201112: libc.a(strerror_s.o)
libc.a(strerror_s.o): $(OBJDIR)/strerror_s.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/strerror_s.o: src/string/strerror_s.c
$(OBJDIR)/strerror_s.o: 
$(OBJDIR)/strerror_s.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/string/strerror_s.c

#!/bin/sh
find_includes () {
	grep '#include.*_' $1 | sed -e 's/^.*"\(.\)/\1/;s/"$//'
}

SOURCE=$1
BASE=$(basename $SOURCE .c)
LIB=$(grep -F 'LINK(' $SOURCE | tr -d 'LINK()')
test -z "$LIB" && LIB="c"

#
# TODO: only grab functions and global variables
#
if grep -q "#define $BASE" $SOURCE; then
	#printf '%s: is a macro\n' $BASE
	return
fi

if grep -q "#undef $BASE" $SOURCE; then
	#printf '%s: is an undefined macro\n' $BASE
	return
fi

RECORD=$(echo $BASE | tr '_' ' ')
if grep -q -e "^$RECORD;" -e "$RECORD {" $SOURCE; then
	#printf '%s: is a union or struct\n' $BASE
	return
fi

if grep -q -e "^typedef.*$BASE;" -e "^} $BASE;" $SOURCE; then
	#printf '%s: is a typedef\n' $BASE
	return
fi

if ! grep -q "^mk/$BASE.d:" mk/deps.mk 2>&1; then
	printf 'all: mk/%s.d\n' $BASE >> mk/deps.mk
	printf 'mk/%s.d: %s\n' $BASE $SOURCE >> mk/deps.mk
	printf '\tsh mk/deps.sh %s\n\n' $SOURCE >> mk/deps.mk
fi

if ! grep -q "include mk/$BASE.d" mk/all.mk 2>&1; then
	printf 'include mk/%s.d\n' $BASE >> mk/all.mk
fi

exec > mk/$BASE.d
#echo "#LIB: $LIB"
#echo "#BASE: $BASE"
#echo "#SOURCE: $SOURCE"

C=$(grep -F 'STDC(' $SOURCE | sed -e 's/STDC(//;s/,.*//;s/)$//g')
test -n "$C" && printf 'lib%s_C.%s: lib%s.a(%s.o)\n' $LIB $C $LIB $BASE
#echo "#C: $C"

CX1=$(grep -F 'CEXT1(' $SOURCE | sed -e 's/CEXT1(//;s/,.*//;s/)$//g')
test -n "$CX1" && printf 'lib%s_C_X1.%s: lib%s.a(%s.o)\n' $LIB $CX1 $LIB $BASE

P=$(grep -F 'POSIX(' $SOURCE | sed -e 's/POSIX(//;s/,.*//;s/)$//g')
test -n "$P" && printf 'lib%s_P.%s: lib%s.a(%s.o)\n' $LIB $P $LIB $BASE
#echo "#POSIX: $P"

X=$(grep -F 'XOPEN(' $SOURCE | sed -e 's/XOPEN(//;s/,.*//;s/)$//g')
test -n "$X" && printf 'lib%s_X.%s: lib%s.a(%s.o)\n' $LIB $X $LIB $BASE
#echo "#XOPEN: $X"

if [ -z "$C" ] && [ -z "$P" ] && [ -z "$X" ] && [ -z "$CX1" ]; then
	printf 'lib%s_C.0: lib%s.a(%s.o)\n' $LIB $LIB $BASE
fi

printf 'lib%s.a(%s.o): $(OBJDIR)/%s.o\n' $LIB $BASE $BASE
#printf '\t@echo "  [AR] $@($%%)"\n'
printf '\t@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%%\n\n'

printf '$(OBJDIR)/%s.o: %s\n' $BASE $SOURCE

#
# TODO: make this recursive
#
for INC in $(find_includes $SOURCE); do
	if [ -f src/$INC ]; then
		FILE=src/$INC
	else
		FILE=$(find src -name $INC)
	fi

	printf '$(OBJDIR)/%s.o: %s\n' $BASE $FILE
done

printf '$(OBJDIR)/%s.o:\n' $BASE
printf '\t@echo "  [CC] $@"\n'
printf '\t@mkdir -p $(@D)\n'
printf '\t@$(CC) -c -o $@ $(CFLAGS) %s\n' $SOURCE

#!/bin/sh

TOPDIR=$(dirname $0)
if [ -z "${INCDIR}" ]; then
	INCDIR="${TOPDIR}/include"
fi
. "${TOPDIR}/mk.sh"

export LC_ALL=POSIX
export LANG=POSIX
HEADER=$1
HEADERNAME=$(echo $HEADER | sed -e "s#^${INCDIR}/*##")
GUARD=__$(echo $HEADERNAME | tr a-z/. A-Z__)__
mkdir -p $(dirname $HEADER)
exec > $HEADER

if [ $(basename $HEADER) != assert.h ]; then
	printf '#ifndef %s\n#define %s\n\n' ${GUARD} ${GUARD}
fi

printf "/*\nUNG's Not GNU\n\n%s\n*/\n\n" "$(cat LICENSE)"

rm -rf $HEADER.*
for i in $(cat "${TOPDIR}/.deps/h/${HEADERNAME}.deps" | sort -u); do
	# TODO: refs
	type=$(classify_source $i)
	source=$i
	if [ $type = "REFERENCE" ] && ! grep -Fq 'REFERENCE(<' $source; then
		source=src/$(grep REFERENCE $i | m4 -DREFERENCE='$1')
		type=$(classify_source $source)
	fi
	version=v$(grep -F -e 'STDC(' -e 'POSIX(' -e 'XOPEN(' $i | sed -e 's/STDC/C/' | sort | tr , - | tr -d '() \n')
	mkdir -p $HEADER.$type
	echo $source >> $HEADER.$type/$version

	if ! [ -f $(dirname $0)/.deps/ftm/$version ]; then
		mkdir -p $(dirname $0)/.deps/ftm
		version_guard $source > $(dirname $0)/.deps/ftm/$version
	fi

	printf '%s <%s> (%s)\n' "$i" "$HEADER" "$version" >&2
done

###
### TODO: prevent _XOPEN_SOURCE expanding to empty string
###
if grep -Fq -e '_XOPEN_SOURCE <' -e '< _XOPEN_SOURCE' $(cat $(HEADER.*/*); then
cat <<-EOF
	#if defined _XOPEN_SOURCE && _XOPEN_SOURCE - 1 < 0
	#	undef _XOPEN_SOURCE
	#	define _XOPEN_SOURCE 400
	#endif
EOF
fi

if grep -Fq 'POSIX(' $(cat $HEADER.*/*); then
cat <<-EOF
	#if defined _XOPEN_SOURCE && !defined _POSIX_C_SOURCE
	#	if (_XOPEN_SOURCE >= 700)
	#		define _POSIX_C_SOURCE 200809L
	#	elif (_XOPEN_SOURCE >= 600)
	#		define _POSIX_C_SOURCE 200112L
	#	elif (_XOPEN_SOURCE >= 500)
	#		define _POSIX_C_SOURCE 199506L
	#	else
	#		define _POSIX_C_SOURCE 2
	#	endif
	#endif

	#if defined _POSIX_C_SOURCE && !defined _POSIX_SOURCE
	#	define _POSIX_SOURCE
	#endif

EOF
fi

if grep -Fq -e 'POSIX(' -e 'XOPEN(' $(cat $HEADER.*/*); then
cat <<-EOF
	#if !defined __STDC_VERSION__ || __STDC_VERSION__ < 19901L
	#	if (defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 200112L)
	#		error POSIX.1-2001 and later require a C99 compiler
	#	elif(defined _XOPEN_SOURCE && _XOPEN_SOURCE >= 600)
	#		error XOPEN Issue 6 and later require a C99 compiler
	#	endif
	#endif
EOF
fi

for type in REFERENCE MACRO TYPE TYPE_LONG RECORD FNTYPE EXTERN; do
	if [ -d $HEADER.$type ]; then
		for v in $HEADER.$type/*; do
			version=$(cat $(dirname $0)/.deps/ftm/$(basename $v | sed -e 's/^.*\.//'))
			if [ -n "$version" ]; then
				printf '%s\n' "$version"
			fi

			for i in $(sort -u $v); do
				printf '/* %s */\n' $i
				get_declaration $i
			done

			if [ -n "$version" ]; then
				printf '#endif\n'
			fi

			printf '\n'
		done
		rm -rf $HEADER.$type
	fi
done

if [ -d $HEADER.TGFN ]; then
	for v in $HEADER.TGFN/*; do
		version=$(cat $(dirname $0)/.deps/ftm/$(basename $v | sed -e 's/^.*\.//'))
		if [ -n "$version" ]; then
			printf '%s\n' "$version"
		fi

		for i in $(sort -u $v); do
				printf '/* %s */\n' $i
			get_declaration $i TGFN
		done

		if [ -n "$version" ]; then
			printf '#endif\n'
		fi

		printf '\n'
	done
	rm -rf $HEADER.TGFN
fi

if [ -d $HEADER.FUNCTION ]; then
	if grep -q restrict $(cat $HEADER.FUNCTION/*); then
		if grep -Fq -e 'STDC(1)' -e 'STDC(1,' -e 'STDC(199409' $(grep -l restrict $(cat $HEADER.FUNCTION/*)) || ! grep -Fq 'STDC(' $(grep -l restrict $(cat $HEADER.FUNCTION/*)); then
			printf '#if (!defined __STDC_VERSION__) || (__STDC_VERSION__ < 199901L)\n'
			printf '#define restrict\n'
			printf '#endif\n\n'
		fi
	fi

	### TODO: only if header works with C<11
	if grep -q _Noreturn $(cat $HEADER.FUNCTION/*); then
		printf '#if (!defined __STDC_VERSION__) || (__STDC_VERSION__ < 200112L)\n'
		printf '#define _Noreturn\n'
		printf '#endif\n\n'
	fi

	for v in $HEADER.FUNCTION/*; do
		version=$(cat $(dirname $0)/.deps/ftm/$(basename $v | sed -e 's/^.*\.//'))
		if [ -n "$version" ]; then
			printf '%s\n' "$version"
		fi

		for i in $(sort -u $v); do
				printf '/* %s */\n' $i
			get_declaration $i FUNCTION | sed -e 's/\([a-zA-Z_][a-zA-Z_0-9]*\)\([,)]\)/__\1\2/g;s/(__\([a-zA-Z_][a-zA-Z_0-9]*\))/(\1)/g'
		done

		if [ -n "$version" ]; then
			printf '#endif\n'
		fi

		printf '\n'
	done
	rm -rf $HEADER.FUNCTION
fi

rm -rf $HEADER.REFERENCE

if [ $(basename $HEADER) != assert.h ]; then
	printf '\n#endif\n'
fi

#include <term.h>
#include <string.h>

char * tgetstr(char id[2], char ** area)
{
	char *str = NULL;
	size_t i;
	const struct {
		char tc[3];
		char ti[8];
	} map[] = {
		/* string variables */
		{ "ac", "acsc" },
		{ "S8", "scesa" },
		{ "bt", "cbt" },
		{ "bl", "bel" },
		{ "Yv", "bicr" },
		{ "Zz", "binel" },
		{ "Xy", "birep" },
		{ "cr", "cr" },
		{ "ZA", "cpi" },
		{ "ZB", "lpi" },
		{ "ZC", "chr" },
		{ "ZD", "cvr" },
		{ "cs", "csr" },
		{ "rP", "rmp" },
		{ "Zy", "csnm" },
		{ "ct", "tbc" },
		{ "MC", "mgc" },
		{ "cl", "clear" },
		{ "cb", "ell" },
		{ "ce", "el" },
		{ "cd", "ed" },
		{ "ci", "csin" },
		{ "Yw", "colornm" },
		{ "ch", "hpa" },
		{ "CC", "cmdch" },
		{ "CW", "cwin" },
		{ "cm", "cup" },
		{ "do", "cudl" },
		{ "ho", "home" },
		{ "vi", "civis" },
		{ "le", "cubl" },
		{ "CM", "mrcup" },
		{ "ve", "cnorm" },
		{ "nd", "cufl" },
		{ "ll", "ll" },
		{ "up", "cuul" },
		{ "vs", "cvvis" },
		{ "Yx", "defbi" },
		{ "ZE", "defc" },
		{ "dc", "dchl" },
		{ "dl", "dll" },
		{ "dv", "devt" },
		{ "DI", "dial" },
		{ "ds", "dsl" },
		{ "DK", "dclk" },
		{ "S1", "dispc" },
		{ "hd", "hd" },
		{ "eA", "enacs" },
		{ "Yy", "endbi" },
		{ "as", "smacs" },
		{ "SA", "smam" },
		{ "mb", "blink" },
		{ "md", "bold" },
		{ "ti", "smcup" },
		{ "dm", "smdc" },
		{ "mh", "dim" },
		{ "ZF", "swidm" },
		{ "ZG", "sdrfq" },
		{ "im", "smir" },
		{ "ZH", "sitm" },
		{ "ZI", "slm" },
		{ "ZJ", "smicm" },
		{ "ZK", "snlq" },
		{ "ZL", "snrmq" },
		{ "S2", "smpch" },
		{ "mp", "prot" },
		{ "mr", "rev" },
		{ "S4", "smsc" },
		{ "mk", "invis" },
		{ "ZM", "sshm" },
		{ "so", "smso" },
		{ "ZN", "ssubm" },
		{ "ZO", "ssupm" },
		{ "us", "smul" },
		{ "ZP", "sum" },
		{ "SX", "smxon" },
		{ "ec", "ech" },
		{ "ae", "rmacs" },
		{ "RA", "rmam" },
		{ "me", "sgr0" },
		{ "te", "rmcup" },
		{ "ed", "rmdc" },
		{ "ZQ", "rwidm" },
		{ "ei", "rmir" },
		{ "ZR", "ritm" },
		{ "ZS", "rlm" },
		{ "ZT", "rmicm" },
		{ "S3", "rmpch" },
		{ "S5", "rmsc" },
		{ "ZU", "rshm" },
		{ "se", "rmso" },
		{ "ZV", "rsubm" },
		{ "ZW", "rsupm" },
		{ "ue", "rmul" },
		{ "ZX", "rum" },
		{ "RX", "rmxon" },
		{ "PA", "pause" },
		{ "fh", "hook" },
		{ "vb", "flash" },
		{ "ff", "ff" },
		{ "fs", "fsl" },
		{ "Gm", "getm" },
		{ "WG", "wingo" },
		{ "HU", "hup" },
		{ "i1", "is1" },
		{ "i2", "is2" },
		{ "i3", "is3" },
		{ "if", "if" },
		{ "iP", "iprog" },
		{ "IC", "initc" },
		{ "Ip", "initp" },
		{ "ic", "ichl" },
		{ "al", "ill" },
		{ "ip", "ip" },

		/* key codes */
		{ "K1", "ka1" },
		{ "K3", "ka3" },
		{ "K2", "kb2" },
		{ "kb", "kbs" },
		{ "@1", "kbeg" },
		{ "kB", "kcbt" },
		{ "K4", "kc1" },
		{ "K5", "kc3" },
		{ "@2", "kcan" },
		{ "ka", "ktbc" },
		{ "kC", "kclr" },
		{ "@3", "kclo" },
		{ "@4", "kcmd" },
		{ "@5", "kcpy" },
		{ "@6", "kcrt" },
		{ "kt", "kctab" },
		{ "kD", "kdchl" },
		{ "kL", "kdll" },
		{ "kd", "kcudl" },
		{ "kM", "krmir" },
		{ "@7", "kend" },
		{ "@8", "kent" },
		{ "kE", "kel" },
		{ "kS", "ked" },
		{ "@9", "kext" },
		{ "k0", "kf0" },
		{ "k1", "kf1" },
		{ "k2", "kf2" },
		{ "k3", "kf3" },
		{ "k4", "kf4" },
		{ "k5", "kf5" },
		{ "k6", "kf6" },
		{ "k7", "kf7" },
		{ "k8", "kf8" },
		{ "k9", "kf9" },
		{ "ka", "kf10" },
		{ "kb", "kf11" },
		{ "kc", "kf12" },
		{ "kd", "kf13" },
		{ "ke", "kf14" },
		{ "kf", "kf15" },
		{ "kg", "kf16" },
		{ "kh", "kf17" },
		{ "ki", "kf18" },
		{ "kj", "kf19" },
		{ "kk", "kf20" },
		{ "kl", "kf21" },
		{ "km", "kf22" },
		{ "kn", "kf23" },
		{ "ko", "kf24" },
		{ "kp", "kf25" },
		{ "kq", "kf26" },
		{ "kr", "kf27" },
		{ "ks", "kf28" },
		{ "kt", "kf29" },
		{ "ku", "kf30" },
		{ "kv", "kf31" },
		{ "kw", "kf32" },
		{ "kx", "kf33" },
		{ "ky", "kf34" },
		{ "kz", "kf35" },
		{ "F0", "kf36" },
		{ "F1", "kf37" },
		{ "F2", "kf38" },
		{ "F3", "kf39" },
		{ "F4", "kf40" },
		{ "F5", "kf41" },
		{ "F6", "kf42" },
		{ "F7", "kf43" },
		{ "F8", "kf44" },
		{ "F9", "kf45" },
		{ "Fa", "kf46" },
		{ "Fb", "kf47" },
		{ "Fc", "kf48" },
		{ "Fd", "kf49" },
		{ "Fe", "kf50" },
		{ "Ff", "kf51" },
		{ "Fg", "kf52" },
		{ "Fh", "kf53" },
		{ "Fi", "kf54" },
		{ "Fj", "kf55" },
		{ "Fk", "kf56" },
		{ "Fl", "kf57" },
		{ "Fm", "kf58" },
		{ "Fn", "kf59" },
		{ "Fo", "kf60" },
		{ "Fp", "kf61" },
		{ "Fq", "kf62" },
		{ "Fr", "kf63" },
		{ "@0", "kfnd" },
		{ "%1", "khlp" },
		{ "kh", "khome" },
		{ "kI", "kichl" },
		{ "kA", "kill" },
		{ "kl", "kcubl" },
		{ "kH", "kll" },
		{ "%2", "kmrk" },
		{ "%3", "kmsg" },
		{ "Km", "kmous" },
		{ "%4", "kmov" },
		{ "%5", "knxt" },
		{ "kN", "knp" },
		{ "%6", "kopn" },
		{ "%7", "kopt" },
		{ "kP", "kpp" },
		{ "%8", "kprv" },
		{ "%9", "kprt" },
		{ "%0", "krdo" },
		{ "&1", "kref" },
		{ "&2", "krfr" },
		{ "&3", "krpl" },
		{ "&4", "krst" },
		{ "&5", "kres" },
		{ "kr", "kcufl" },
		{ "&6", "ksav" },
		{ "&9", "kBEG" },
		{ "&0", "kCAN" },
		{ "*1", "kCMD" },
		{ "*2", "kCPY" },
		{ "*3", "kCRT" },
		{ "*4", "kDC" },
		{ "*5", "kDL" },
		{ "*6", "kslt" },
		{ "*7", "kEND" },
		{ "*8", "kEOL" },
		{ "*9", "kEXT" },
		{ "kF", "kind" },
		{ "*0", "kFND" },
		{ "#1", "kHLP" },
		{ "#2", "kHOM" },
		{ "#3", "kIC" },
		{ "#4", "kLFT" },
		{ "%a", "kMSG" },
		{ "%b", "kMOV" },
		{ "%c", "kNXT" },
		{ "%d", "kOPT" },
		{ "%e", "kPRV" },
		{ "%f", "kPRT" },
		{ "kR", "kri" },
		{ "%g", "kRDO" },
		{ "%h", "kRPL" },
		{ "%i", "kRIT" },
		{ "%j", "kRES" },
		{ "!1", "kSAV" },
		{ "!2", "kSPD" },
		{ "kT", "khts" },
		{ "!3", "kUND" },
		{ "&7", "kspd" },
		{ "&8", "kund" },
		{ "ku", "kcuul" },
		{ "ke", "rmkx" },
		{ "ks", "smkx" },

		/* more strings */
		{ "l0", "lf0" },
		{ "l1", "lf1" },
		{ "l2", "lf2" },
		{ "l3", "lf3" },
		{ "l4", "lf4" },
		{ "l5", "lf5" },
		{ "l6", "lf6" },
		{ "l7", "lf7" },
		{ "l8", "lf8" },
		{ "l9", "lf9" },
		{ "la", "lf10" },
		{ "Lf", "fln" },
		{ "LF", "rmln" },
		{ "LO", "smln" },
		{ "mo", "rmm" },
		{ "mm", "smm" },
		{ "ZY", "mhpa" },
		{ "ZZ", "mcudl" },
		{ "Za", "mcubl" },
		{ "Zb", "mcufl" },
		{ "Zc", "mvpa" },
		{ "Zd", "mcuul" },
		{ "Mi", "minfo" },
		{ "nw", "nel" },
		{ "Ze", "porder" },
		{ "oc", "oc" },
		{ "op", "op" },
		{ "pc", "pad" },
		{ "DC", "dch" },
		{ "DL", "dl" },
		{ "DO", "cud" },
		{ "Zf", "mcud" },
		{ "IC", "ich" },
		{ "SF", "indn" },
		{ "AL", "il" },
		{ "LE", "cub" },
		{ "Zg", "mcub" },
		{ "RI", "cuf" },
		{ "Zh", "mcuf" },
		{ "SR", "rin" },
		{ "UP", "cuu" },
		{ "Zi", "mcuu" },
		{ "S6", "pctrm" },
		{ "pk", "pfkey" },
		{ "pl", "pfloc" },
		{ "xl", "pfxl" },
		{ "px", "pfx" },
		{ "pn", "pln" },
 		{ "ps", "mc0" },
		{ "p0", "mc5p" },
		{ "pf", "mc4" },
		{ "po", "mc5" },
		{ "PU", "pulse" },
		{ "QD", "qdial" },
		{ "RC", "rmclk" },
		{ "rp", "rep" },
		{ "RF", "rfi" },
		{ "RQ", "reqmp" },
		{ "r1", "rs1" },
		{ "r2", "rs2" },
		{ "r3", "rs3" },
		{ "rf", "rf" },
		{ "rc", "rc" },
		{ "cv", "vpa" },
		{ "sc", "sc" },
		{ "S7", "scesc" },
		{ "sf", "ind" },
		{ "sr", "ri" },
		{ "Zj", "scs" },
		{ "s0", "s0ds" },
		{ "s1", "s1ds" },
		{ "s2", "s2ds" },
		{ "s3", "s3ds" },
		{ "AB", "setab" },
		{ "AF", "setaf" },
		{ "sa", "sgr" },
		{ "Sb", "setb" },
		{ "Zk", "smgb" },
		{ "Zl", "smgbp" },
		{ "SC", "sclk" },
		{ "Yz", "setcolor" },
		{ "sp", "scp" },
		{ "Sf", "setf" },
		{ "ML", "smgl" },	/* note: duplicate */
		{ "Zm", "smglp" },
		{ "ML", "smgrl" },	/* note: duplicate */
		{ "YZ", "slines" },
		{ "YI", "slength" },
		{ "MR", "smgr" },
		{ "Zn", "smgrp" },
		{ "st", "hts" },
		{ "MT", "smgtb" },
		{ "Zo", "smgt" },
		{ "Zp", "smgtp" },
		{ "wi", "wind" },
		{ "Zq", "sbim" },
		{ "Zr", "scsd" },
		{ "Zs", "rbim" },
		{ "Zt", "rcsd" },
		{ "Zu", "subcs" },
		{ "Zv", "supcs" },
		{ "ta", "ht" },
		{ "Zw", "docr" },
		{ "ts", "tsl" },
		{ "u0", "u0" },
		{ "u1", "u1" },
		{ "u2", "u2" },
		{ "u3", "u3" },
		{ "u4", "u4" },
		{ "u5", "u5" },
		{ "u6", "u6" },
		{ "u7", "u7" },
		{ "u8", "u8" },
		{ "u9", "u9" },
		{ "uc", "uc" },
		{ "hu", "hu" },
		{ "WA", "wait" },
		{ "XF", "xoffc" },
		{ "XN", "xonc" },
		{ "Zx", "zerom" },
	};

	for (i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
		if (map[i].tc[0] == id[0] && map[i].tc[1] == id[1]) {
			str = tigetstr(map[i].ti);
			break;
		}
	}

	/* TODO: the rest isn't quite right */
	if (str != NULL) {
		strcpy(*area, str);
		*area += strlen(*area);
	}

	return str;
}

/*
XOPEN(400, 700)
LINK(curses)
*/

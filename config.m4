PHP_ARG_ENABLE(errno, Whether to enable the "errno" extension,
[  --enable-errno     Enable "errno" extension support])

if test $PHP_ERRNO != "no"; then
    PHP_NEW_EXTENSION(errno, php_errno.c, $ext_shared)
    PHP_SUBST(ERRNO_SHARED_LIBADD)
    PHP_SUBST([CFLAGS])
fi

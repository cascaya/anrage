PHP_ARG_ENABLE(strflip, whether to enable strflip,
[ --enable-strflip   Enable strflip extension])
 
if test "$PHP_STRFLIP" = "yes"; then
  AC_DEFINE(HAVE_STRFLIP, 1, [Whether you have strflip])
  PHP_NEW_EXTENSION(strflip, strflip.c, $ext_shared)
fi

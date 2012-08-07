PHP_ARG_ENABLE(country, whether to enable country,
[ --enable-country   Enable country extension])
 
if test "$PHP_COUNTRY" = "yes"; then
  AC_DEFINE(HAVE_COUNTRY, 1, [Whether you have country])
  PHP_NEW_EXTENSION(country, country.c, $ext_shared)
fi

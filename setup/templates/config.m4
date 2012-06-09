PHP_ARG_ENABLE(%%module-low%%, whether to enable %%module-low%%,
[ --enable-%%module-low%%   Enable %%module-low%% extension])
 
if test "$PHP_%%module-up%%" = "yes"; then
  AC_DEFINE(HAVE_%%module-up%%, 1, [Whether you have %%module-low%%])
  PHP_NEW_EXTENSION(%%module-low%%, %%module-low%%.c, $ext_shared)
fi

#ifndef PHP_%%module-up%%_H
#define PHP_%%module-up%%_H 1

#define PHP_%%module-up%%_VERSION "1.0"
#define PHP_%%module-up%%_EXTNAME "%%module-low%%"

%%functions%%
 
extern zend_module_entry %%module-low%%_module_entry;
#define phpext_%%module-low%%_ptr &%%module-low%%_module_entry

#endif

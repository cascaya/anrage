#ifndef PHP_%%module-up%%_H
#define PHP__%%module-up%%_H 1

#define PHP_EXTENSION_VERSION "1.0"
#define PHP_EXTENSION_EXTNAME "%%module-low%%"
 
extern zend_module_entry %%module-low%%_module_entry;
#define phpext_%%module-low%%_ptr &%%module-low%%_module_entry

    %%functions%%
#endif

#ifndef PHP_STRFLIP_H
#define PHP_STRFLIP_H 1

#define PHP_STRFLIP_VERSION "1.0"
#define PHP_STRFLIP_EXTNAME "strflip"

PHP_FUNCTION(strflip);
    
 
extern zend_module_entry strflip_module_entry;
#define phpext_strflip_ptr &strflip_module_entry

#endif

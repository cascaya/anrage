#ifndef PHP_COUNTRY_H
#define PHP_COUNTRY_H 1

#define PHP_COUNTRY_VERSION "1.0"
#define PHP_COUNTRY_EXTNAME "country"

//new recource 
typedef struct _php_country {
    char *name,*shortcut;
    int name_len, shortcut_len;
} php_country;

//type definition for var_dump
#define PHP_COUNTRY_RES_NAME "Country"

PHP_FUNCTION(country);
PHP_FUNCTION(country_get_name); 
PHP_FUNCTION(country_get_short); 
 
extern zend_module_entry country_module_entry;
#define phpext_country_ptr &country_module_entry

#endif

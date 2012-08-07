#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <php.h>
#include <php_country.h>
#include <functions.c>


// list of custom PHP functions provided by this extension
// set {NULL, NULL, NULL} as the last record to mark the end of list
static zend_function_entry country_functions[] = {
    PHP_FE(country, NULL)
    PHP_FE(country_get_name, NULL)
    PHP_FE(country_get_short, NULL)
    {NULL, NULL, NULL}
};
 
// the following code creates an entry for the module and registers it with Zend.
zend_module_entry country_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_COUNTRY_EXTNAME,
    country_functions,
    PHP_MINIT(country), // name of the MINIT function or NULL if not applicable
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    NULL, // name of the MINFO function or NULL if not applicable
#if ZEND_MODULE_API_NO >= 20010901
    PHP_COUNTRY_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};
 
ZEND_GET_MODULE(country)
 



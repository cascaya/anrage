#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <php.h>
#include <php_%%module-low%%.h>
#include <functions.c>


// list of custom PHP functions provided by this extension
// set {NULL, NULL, NULL} as the last record to mark the end of list
static zend_function_entry %%module-low%%_functions[] = {
    %%functions%%{NULL, NULL, NULL}
};
 
// the following code creates an entry for the module and registers it with Zend.
zend_module_entry %%module-low%%_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_%%module-up%%_EXTNAME,
    %%module-low%%_functions,
    NULL, // name of the MINIT function or NULL if not applicable
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    NULL, // name of the MINFO function or NULL if not applicable
#if ZEND_MODULE_API_NO >= 20010901
    PHP_%%module-up%%_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};
 
ZEND_GET_MODULE(%%module-low%%)
 



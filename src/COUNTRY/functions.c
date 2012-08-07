// need for register
int le_country;

PHP_MINIT_FUNCTION(country)
{
    le_country = zend_register_list_destructors_ex(NULL, NULL, PHP_COUNTRY_RES_NAME, module_number);
    return SUCCESS;
}


/**
 * main country function to create new recource 
 */
PHP_FUNCTION(country)
{
    php_country *country;
    char *name, *shortcut;
    int name_len, shortcut_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &name, &name_len, &shortcut, &shortcut_len) == FAILURE) {
        RETURN_FALSE;
    }

    if (name_len < 1) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "No name given, country resource not created.");
        RETURN_FALSE;
    }

    if (shortcut_len != 5) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "shortcut must have a lenqth of 5 caracters ");
        RETURN_FALSE;
    }


    country = emalloc(sizeof(php_country));
    country->name = estrndup(name, name_len);
    country->name_len = name_len;
    country->shortcut = estrndup(shortcut, shortcut_len);
    country->shortcut_len = shortcut_len;

    ZEND_REGISTER_RESOURCE(return_value, country, le_country);
}

/**
 * getter functions ....  
 */

PHP_FUNCTION(country_get_name)
{
    php_country *country;
    zval *zcountry;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &zcountry) == FAILURE) {
        RETURN_FALSE;
    }

    ZEND_FETCH_RESOURCE(country, php_country*, &zcountry, -1, PHP_COUNTRY_RES_NAME, le_country);

    RETURN_STRING(country->name, country->name_len);
} 

PHP_FUNCTION(country_get_short)
{
    php_country *country;
    zval *zcountry;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &zcountry) == FAILURE) {
        RETURN_FALSE;
    }

    ZEND_FETCH_RESOURCE(country, php_country*, &zcountry, -1, PHP_COUNTRY_RES_NAME, le_country);

    RETURN_STRING(country->shortcut, country->shortcut_len);
}

/*
   +----------------------------------------------------------------------+
   | ecma_intl extension for PHP                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Ben Ramsey <ben@benramsey.com>                         |
   | This source file is subject to the MIT license that is bundled with  |
   | this package in the file LICENSE, and is available at the following  |
   | web address: https://opensource.org/license/mit/                     |
   +----------------------------------------------------------------------+
*/

#ifndef PHP_ECMA_INTL_H
#define PHP_ECMA_INTL_H

#include "php/php_common.h"

extern zend_module_entry ecma_intl_module_entry;
#define phpext_ecma_intl_ptr &ecma_intl_module_entry

#define PHP_ECMA_INTL_VERSION "0.1.0"

#if defined(ZTS) && defined(COMPILE_DL_ECMA_INTL)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

PHP_MINIT_FUNCTION(ecma_intl);
PHP_RINIT_FUNCTION(ecma_intl);
PHP_MINFO_FUNCTION(ecma_intl);

#endif /* PHP_ECMA_INTL_H */

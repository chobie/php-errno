#ifndef PHP_ERRNO_H

#define PHP_ERRNO_H

#define PHP_ERRNO_EXTNAME "errno"
#define PHP_ERRNO_EXTVER "0.1.0"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "zend_interfaces.h"

/* Define the entry point symbol
 * Zend will use when loading this module
 */
extern zend_module_entry errno_module_entry;
#define phpext_errno_ptr &errno_module_entry

#endif /* PHP_ERRNO_H */
/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2013 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Shuhei Tanuma <chobieeee@php.net>                          |
   +----------------------------------------------------------------------+
 */

#include "php_errno.h"
#include "zend_exceptions.h"
#include "ext/standard/info.h"

#ifndef PHP_ERRNO_DEBUG
#define PHP_ERRNO_DEBUG 0
#endif

zend_class_entry *errno_error_class_entry;
zend_class_entry *errno_eperm_class_entry;
zend_class_entry *errno_enoent_class_entry;
zend_class_entry *errno_esrch_class_entry;
zend_class_entry *errno_eintr_class_entry;
zend_class_entry *errno_eio_class_entry;
zend_class_entry *errno_enxio_class_entry;
zend_class_entry *errno_e2big_class_entry;
zend_class_entry *errno_enoexec_class_entry;
zend_class_entry *errno_ebadf_class_entry;
zend_class_entry *errno_echild_class_entry;
zend_class_entry *errno_eagain_class_entry;
zend_class_entry *errno_enomem_class_entry;
zend_class_entry *errno_eacces_class_entry;
zend_class_entry *errno_efault_class_entry;
zend_class_entry *errno_enotblk_class_entry;
zend_class_entry *errno_ebusy_class_entry;
zend_class_entry *errno_eexist_class_entry;
zend_class_entry *errno_exdev_class_entry;
zend_class_entry *errno_enodev_class_entry;
zend_class_entry *errno_enotdir_class_entry;
zend_class_entry *errno_eisdir_class_entry;
zend_class_entry *errno_einval_class_entry;
zend_class_entry *errno_enfile_class_entry;
zend_class_entry *errno_emfile_class_entry;
zend_class_entry *errno_enotty_class_entry;
zend_class_entry *errno_etxtbsy_class_entry;
zend_class_entry *errno_efbig_class_entry;
zend_class_entry *errno_enospc_class_entry;
zend_class_entry *errno_espipe_class_entry;
zend_class_entry *errno_erofs_class_entry;
zend_class_entry *errno_emlink_class_entry;
zend_class_entry *errno_epipe_class_entry;
zend_class_entry *errno_edom_class_entry;
zend_class_entry *errno_erange_class_entry;
zend_class_entry *errno_edeadlk_class_entry;
zend_class_entry *errno_enametoolong_class_entry;
zend_class_entry *errno_enolck_class_entry;
zend_class_entry *errno_enosys_class_entry;
zend_class_entry *errno_enotempty_class_entry;
zend_class_entry *errno_eloop_class_entry;
zend_class_entry *errno_ewouldblock_class_entry;
zend_class_entry *errno_enomsg_class_entry;
zend_class_entry *errno_eidrm_class_entry;
zend_class_entry *errno_echrng_class_entry;
zend_class_entry *errno_el2nsync_class_entry;
zend_class_entry *errno_el3hlt_class_entry;
zend_class_entry *errno_el3rst_class_entry;
zend_class_entry *errno_elnrng_class_entry;
zend_class_entry *errno_eunatch_class_entry;
zend_class_entry *errno_enocsi_class_entry;
zend_class_entry *errno_el2hlt_class_entry;
zend_class_entry *errno_ebade_class_entry;
zend_class_entry *errno_ebadr_class_entry;
zend_class_entry *errno_exfull_class_entry;
zend_class_entry *errno_enoano_class_entry;
zend_class_entry *errno_ebadrqc_class_entry;
zend_class_entry *errno_ebadslt_class_entry;
zend_class_entry *errno_edeadlock_class_entry;
zend_class_entry *errno_ebfont_class_entry;
zend_class_entry *errno_enostr_class_entry;
zend_class_entry *errno_enodata_class_entry;
zend_class_entry *errno_etime_class_entry;
zend_class_entry *errno_enosr_class_entry;
zend_class_entry *errno_enonet_class_entry;
zend_class_entry *errno_enopkg_class_entry;
zend_class_entry *errno_eremote_class_entry;
zend_class_entry *errno_enolink_class_entry;
zend_class_entry *errno_eadv_class_entry;
zend_class_entry *errno_esrmnt_class_entry;
zend_class_entry *errno_ecomm_class_entry;
zend_class_entry *errno_eproto_class_entry;
zend_class_entry *errno_emultihop_class_entry;
zend_class_entry *errno_edotdot_class_entry;
zend_class_entry *errno_ebadmsg_class_entry;
zend_class_entry *errno_eoverflow_class_entry;
zend_class_entry *errno_enotuniq_class_entry;
zend_class_entry *errno_ebadfd_class_entry;
zend_class_entry *errno_eremchg_class_entry;
zend_class_entry *errno_elibacc_class_entry;
zend_class_entry *errno_elibbad_class_entry;
zend_class_entry *errno_elibscn_class_entry;
zend_class_entry *errno_elibmax_class_entry;
zend_class_entry *errno_elibexec_class_entry;
zend_class_entry *errno_eilseq_class_entry;
zend_class_entry *errno_erestart_class_entry;
zend_class_entry *errno_estrpipe_class_entry;
zend_class_entry *errno_eusers_class_entry;
zend_class_entry *errno_enotsock_class_entry;
zend_class_entry *errno_edestaddrreq_class_entry;
zend_class_entry *errno_emsgsize_class_entry;
zend_class_entry *errno_eprototype_class_entry;
zend_class_entry *errno_enoprotoopt_class_entry;
zend_class_entry *errno_eprotonosupport_class_entry;
zend_class_entry *errno_esocktnosupport_class_entry;
zend_class_entry *errno_eopnotsupp_class_entry;
zend_class_entry *errno_epfnosupport_class_entry;
zend_class_entry *errno_eafnosupport_class_entry;
zend_class_entry *errno_eaddrinuse_class_entry;
zend_class_entry *errno_eaddrnotavail_class_entry;
zend_class_entry *errno_enetdown_class_entry;
zend_class_entry *errno_enetunreach_class_entry;
zend_class_entry *errno_enetreset_class_entry;
zend_class_entry *errno_econnaborted_class_entry;
zend_class_entry *errno_econnreset_class_entry;
zend_class_entry *errno_enobufs_class_entry;
zend_class_entry *errno_eisconn_class_entry;
zend_class_entry *errno_enotconn_class_entry;
zend_class_entry *errno_eshutdown_class_entry;
zend_class_entry *errno_etoomanyrefs_class_entry;
zend_class_entry *errno_etimedout_class_entry;
zend_class_entry *errno_econnrefused_class_entry;
zend_class_entry *errno_ehostdown_class_entry;
zend_class_entry *errno_ehostunreach_class_entry;
zend_class_entry *errno_ealready_class_entry;
zend_class_entry *errno_einprogress_class_entry;
zend_class_entry *errno_estale_class_entry;
zend_class_entry *errno_euclean_class_entry;
zend_class_entry *errno_enotnam_class_entry;
zend_class_entry *errno_enavail_class_entry;
zend_class_entry *errno_eisnam_class_entry;
zend_class_entry *errno_eremoteio_class_entry;
zend_class_entry *errno_edquot_class_entry;

#if (PHP_MAJOR_VERSION == 5) && (PHP_MINOR_VERSION < 3)
	#define ERRNO_INIT_CLASS_ENTRY(ce, name, methods)	INIT_CLASS_ENTRY(ce, "Errno_" ## name, methods)
#else
	#define ERRNO_INIT_CLASS_ENTRY(ce, name, methods)	INIT_NS_CLASS_ENTRY(ce, "Errno", name, methods)
#endif

static inline zend_class_entry* php_errno_get_exception_base(TSRMLS_D);

void php_errno_init(TSRMLS_D);

static inline zend_class_entry* php_errno_get_exception_base(TSRMLS_D)
{
#if (PHP_MAJOR_VERSION == 5) && (PHP_MINOR_VERSION < 2)
	return zend_exception_get_default();
#else
	return zend_exception_get_default(TSRMLS_C);
#endif
}
	
static zend_function_entry errno_methods[] = {
	{NULL, NULL, NULL}
};

static zend_function_entry errno_functions[] = {
	{NULL, NULL, NULL}
};

#define PHP_ERRNO_DECLARE_CLASS(class, name, error) \
{ \
	zend_class_entry ce; \
 \
	ERRNO_INIT_CLASS_ENTRY(ce, name, errno_methods); \
	class = zend_register_internal_class_ex(&ce, php_errno_get_exception_base(TSRMLS_C), NULL TSRMLS_CC); \
	zend_declare_class_constant_long(class, "ERRNO", sizeof("ERRNO")-1, error TSRMLS_CC); \
}

void php_errno_init(TSRMLS_D)
{
#ifdef ERROR
	PHP_ERRNO_DECLARE_CLASS(errno_error_class_entry, "ERROR", ERROR);
#endif
#ifdef EPERM
	PHP_ERRNO_DECLARE_CLASS(errno_eperm_class_entry, "EPERM", EPERM);
#endif
#ifdef ENOENT
	PHP_ERRNO_DECLARE_CLASS(errno_enoent_class_entry, "ENOENT", ENOENT);
#endif
#ifdef ESRCH
	PHP_ERRNO_DECLARE_CLASS(errno_esrch_class_entry, "ESRCH", ESRCH);
#endif
#ifdef EINTR
	PHP_ERRNO_DECLARE_CLASS(errno_eintr_class_entry, "EINTR", EINTR);
#endif
#ifdef EIO
	PHP_ERRNO_DECLARE_CLASS(errno_eio_class_entry, "EIO", EIO);
#endif
#ifdef ENXIO
	PHP_ERRNO_DECLARE_CLASS(errno_enxio_class_entry, "ENXIO", ENXIO);
#endif
#ifdef E2BIG
	PHP_ERRNO_DECLARE_CLASS(errno_e2big_class_entry, "E2BIG", E2BIG);
#endif
#ifdef ENOEXEC
	PHP_ERRNO_DECLARE_CLASS(errno_enoexec_class_entry, "ENOEXEC", ENOEXEC);
#endif
#ifdef EBADF
	PHP_ERRNO_DECLARE_CLASS(errno_ebadf_class_entry, "EBADF", EBADF);
#endif
#ifdef ECHILD
	PHP_ERRNO_DECLARE_CLASS(errno_echild_class_entry, "ECHILD", ECHILD);
#endif
#ifdef EAGAIN
	PHP_ERRNO_DECLARE_CLASS(errno_eagain_class_entry, "EAGAIN", EAGAIN);
#endif
#ifdef ENOMEM
	PHP_ERRNO_DECLARE_CLASS(errno_enomem_class_entry, "ENOMEM", ENOMEM);
#endif
#ifdef EACCES
	PHP_ERRNO_DECLARE_CLASS(errno_eacces_class_entry, "EACCES", EACCES);
#endif
#ifdef EFAULT
	PHP_ERRNO_DECLARE_CLASS(errno_efault_class_entry, "EFAULT", EFAULT);
#endif
#ifdef ENOTBLK
	PHP_ERRNO_DECLARE_CLASS(errno_enotblk_class_entry, "ENOTBLK", ENOTBLK);
#endif
#ifdef EBUSY
	PHP_ERRNO_DECLARE_CLASS(errno_ebusy_class_entry, "EBUSY", EBUSY);
#endif
#ifdef EEXIST
	PHP_ERRNO_DECLARE_CLASS(errno_eexist_class_entry, "EEXIST", EEXIST);
#endif
#ifdef EXDEV
	PHP_ERRNO_DECLARE_CLASS(errno_exdev_class_entry, "EXDEV", EXDEV);
#endif
#ifdef ENODEV
	PHP_ERRNO_DECLARE_CLASS(errno_enodev_class_entry, "ENODEV", ENODEV);
#endif
#ifdef ENOTDIR
	PHP_ERRNO_DECLARE_CLASS(errno_enotdir_class_entry, "ENOTDIR", ENOTDIR);
#endif
#ifdef EISDIR
	PHP_ERRNO_DECLARE_CLASS(errno_eisdir_class_entry, "EISDIR", EISDIR);
#endif
#ifdef EINVAL
	PHP_ERRNO_DECLARE_CLASS(errno_einval_class_entry, "EINVAL", EINVAL);
#endif
#ifdef ENFILE
	PHP_ERRNO_DECLARE_CLASS(errno_enfile_class_entry, "ENFILE", ENFILE);
#endif
#ifdef EMFILE
	PHP_ERRNO_DECLARE_CLASS(errno_emfile_class_entry, "EMFILE", EMFILE);
#endif
#ifdef ENOTTY
	PHP_ERRNO_DECLARE_CLASS(errno_enotty_class_entry, "ENOTTY", ENOTTY);
#endif
#ifdef ETXTBSY
	PHP_ERRNO_DECLARE_CLASS(errno_etxtbsy_class_entry, "ETXTBSY", ETXTBSY);
#endif
#ifdef EFBIG
	PHP_ERRNO_DECLARE_CLASS(errno_efbig_class_entry, "EFBIG", EFBIG);
#endif
#ifdef ENOSPC
	PHP_ERRNO_DECLARE_CLASS(errno_enospc_class_entry, "ENOSPC", ENOSPC);
#endif
#ifdef ESPIPE
	PHP_ERRNO_DECLARE_CLASS(errno_espipe_class_entry, "ESPIPE", ESPIPE);
#endif
#ifdef EROFS
	PHP_ERRNO_DECLARE_CLASS(errno_erofs_class_entry, "EROFS", EROFS);
#endif
#ifdef EMLINK
	PHP_ERRNO_DECLARE_CLASS(errno_emlink_class_entry, "EMLINK", EMLINK);
#endif
#ifdef EPIPE
	PHP_ERRNO_DECLARE_CLASS(errno_epipe_class_entry, "EPIPE", EPIPE);
#endif
#ifdef EDOM
	PHP_ERRNO_DECLARE_CLASS(errno_edom_class_entry, "EDOM", EDOM);
#endif
#ifdef ERANGE
	PHP_ERRNO_DECLARE_CLASS(errno_erange_class_entry, "ERANGE", ERANGE);
#endif
#ifdef EDEADLK
	PHP_ERRNO_DECLARE_CLASS(errno_edeadlk_class_entry, "EDEADLK", EDEADLK);
#endif
#ifdef ENAMETOOLONG
	PHP_ERRNO_DECLARE_CLASS(errno_enametoolong_class_entry, "ENAMETOOLONG", ENAMETOOLONG);
#endif
#ifdef ENOLCK
	PHP_ERRNO_DECLARE_CLASS(errno_enolck_class_entry, "ENOLCK", ENOLCK);
#endif
#ifdef ENOSYS
	PHP_ERRNO_DECLARE_CLASS(errno_enosys_class_entry, "ENOSYS", ENOSYS);
#endif
#ifdef ENOTEMPTY
	PHP_ERRNO_DECLARE_CLASS(errno_enotempty_class_entry, "ENOTEMPTY", ENOTEMPTY);
#endif
#ifdef ELOOP
	PHP_ERRNO_DECLARE_CLASS(errno_eloop_class_entry, "ELOOP", ELOOP);
#endif
#ifdef EWOULDBLOCK
	PHP_ERRNO_DECLARE_CLASS(errno_ewouldblock_class_entry, "EWOULDBLOCK", EWOULDBLOCK);
#endif
#ifdef ENOMSG
	PHP_ERRNO_DECLARE_CLASS(errno_enomsg_class_entry, "ENOMSG", ENOMSG);
#endif
#ifdef EIDRM
	PHP_ERRNO_DECLARE_CLASS(errno_eidrm_class_entry, "EIDRM", EIDRM);
#endif
#ifdef ECHRNG
	PHP_ERRNO_DECLARE_CLASS(errno_echrng_class_entry, "ECHRNG", ECHRNG);
#endif
#ifdef EL2NSYNC
	PHP_ERRNO_DECLARE_CLASS(errno_el2nsync_class_entry, "EL2NSYNC", EL2NSYNC);
#endif
#ifdef EL3HLT
	PHP_ERRNO_DECLARE_CLASS(errno_el3hlt_class_entry, "EL3HLT", EL3HLT);
#endif
#ifdef EL3RST
	PHP_ERRNO_DECLARE_CLASS(errno_el3rst_class_entry, "EL3RST", EL3RST);
#endif
#ifdef ELNRNG
	PHP_ERRNO_DECLARE_CLASS(errno_elnrng_class_entry, "ELNRNG", ELNRNG);
#endif
#ifdef EUNATCH
	PHP_ERRNO_DECLARE_CLASS(errno_eunatch_class_entry, "EUNATCH", EUNATCH);
#endif
#ifdef ENOCSI
	PHP_ERRNO_DECLARE_CLASS(errno_enocsi_class_entry, "ENOCSI", ENOCSI);
#endif
#ifdef EL2HLT
	PHP_ERRNO_DECLARE_CLASS(errno_el2hlt_class_entry, "EL2HLT", EL2HLT);
#endif
#ifdef EBADE
	PHP_ERRNO_DECLARE_CLASS(errno_ebade_class_entry, "EBADE", EBADE);
#endif
#ifdef EBADR
	PHP_ERRNO_DECLARE_CLASS(errno_ebadr_class_entry, "EBADR", EBADR);
#endif
#ifdef EXFULL
	PHP_ERRNO_DECLARE_CLASS(errno_exfull_class_entry, "EXFULL", EXFULL);
#endif
#ifdef ENOANO
	PHP_ERRNO_DECLARE_CLASS(errno_enoano_class_entry, "ENOANO", ENOANO);
#endif
#ifdef EBADRQC
	PHP_ERRNO_DECLARE_CLASS(errno_ebadrqc_class_entry, "EBADRQC", EBADRQC);
#endif
#ifdef EBADSLT
	PHP_ERRNO_DECLARE_CLASS(errno_ebadslt_class_entry, "EBADSLT", EBADSLT);
#endif
#ifdef EDEADLOCK
	PHP_ERRNO_DECLARE_CLASS(errno_edeadlock_class_entry, "EDEADLOCK", EDEADLOCK);
#endif
#ifdef EBFONT
	PHP_ERRNO_DECLARE_CLASS(errno_ebfont_class_entry, "EBFONT", EBFONT);
#endif
#ifdef ENOSTR
	PHP_ERRNO_DECLARE_CLASS(errno_enostr_class_entry, "ENOSTR", ENOSTR);
#endif
#ifdef ENODATA
	PHP_ERRNO_DECLARE_CLASS(errno_enodata_class_entry, "ENODATA", ENODATA);
#endif
#ifdef ETIME
	PHP_ERRNO_DECLARE_CLASS(errno_etime_class_entry, "ETIME", ETIME);
#endif
#ifdef ENOSR
	PHP_ERRNO_DECLARE_CLASS(errno_enosr_class_entry, "ENOSR", ENOSR);
#endif
#ifdef ENONET
	PHP_ERRNO_DECLARE_CLASS(errno_enonet_class_entry, "ENONET", ENONET);
#endif
#ifdef ENOPKG
	PHP_ERRNO_DECLARE_CLASS(errno_enopkg_class_entry, "ENOPKG", ENOPKG);
#endif
#ifdef EREMOTE
	PHP_ERRNO_DECLARE_CLASS(errno_eremote_class_entry, "EREMOTE", EREMOTE);
#endif
#ifdef ENOLINK
	PHP_ERRNO_DECLARE_CLASS(errno_enolink_class_entry, "ENOLINK", ENOLINK);
#endif
#ifdef EADV
	PHP_ERRNO_DECLARE_CLASS(errno_eadv_class_entry, "EADV", EADV);
#endif
#ifdef ESRMNT
	PHP_ERRNO_DECLARE_CLASS(errno_esrmnt_class_entry, "ESRMNT", ESRMNT);
#endif
#ifdef ECOMM
	PHP_ERRNO_DECLARE_CLASS(errno_ecomm_class_entry, "ECOMM", ECOMM);
#endif
#ifdef EPROTO
	PHP_ERRNO_DECLARE_CLASS(errno_eproto_class_entry, "EPROTO", EPROTO);
#endif
#ifdef EMULTIHOP
	PHP_ERRNO_DECLARE_CLASS(errno_emultihop_class_entry, "EMULTIHOP", EMULTIHOP);
#endif
#ifdef EDOTDOT
	PHP_ERRNO_DECLARE_CLASS(errno_edotdot_class_entry, "EDOTDOT", EDOTDOT);
#endif
#ifdef EBADMSG
	PHP_ERRNO_DECLARE_CLASS(errno_ebadmsg_class_entry, "EBADMSG", EBADMSG);
#endif
#ifdef EOVERFLOW
	PHP_ERRNO_DECLARE_CLASS(errno_eoverflow_class_entry, "EOVERFLOW", EOVERFLOW);
#endif
#ifdef ENOTUNIQ
	PHP_ERRNO_DECLARE_CLASS(errno_enotuniq_class_entry, "ENOTUNIQ", ENOTUNIQ);
#endif
#ifdef EBADFD
	PHP_ERRNO_DECLARE_CLASS(errno_ebadfd_class_entry, "EBADFD", EBADFD);
#endif
#ifdef EREMCHG
	PHP_ERRNO_DECLARE_CLASS(errno_eremchg_class_entry, "EREMCHG", EREMCHG);
#endif
#ifdef ELIBACC
	PHP_ERRNO_DECLARE_CLASS(errno_elibacc_class_entry, "ELIBACC", ELIBACC);
#endif
#ifdef ELIBBAD
	PHP_ERRNO_DECLARE_CLASS(errno_elibbad_class_entry, "ELIBBAD", ELIBBAD);
#endif
#ifdef ELIBSCN
	PHP_ERRNO_DECLARE_CLASS(errno_elibscn_class_entry, "ELIBSCN", ELIBSCN);
#endif
#ifdef ELIBMAX
	PHP_ERRNO_DECLARE_CLASS(errno_elibmax_class_entry, "ELIBMAX", ELIBMAX);
#endif
#ifdef ELIBEXEC
	PHP_ERRNO_DECLARE_CLASS(errno_elibexec_class_entry, "ELIBEXEC", ELIBEXEC);
#endif
#ifdef EILSEQ
	PHP_ERRNO_DECLARE_CLASS(errno_eilseq_class_entry, "EILSEQ", EILSEQ);
#endif
#ifdef ERESTART
	PHP_ERRNO_DECLARE_CLASS(errno_erestart_class_entry, "ERESTART", ERESTART);
#endif
#ifdef ESTRPIPE
	PHP_ERRNO_DECLARE_CLASS(errno_estrpipe_class_entry, "ESTRPIPE", ESTRPIPE);
#endif
#ifdef EUSERS
	PHP_ERRNO_DECLARE_CLASS(errno_eusers_class_entry, "EUSERS", EUSERS);
#endif
#ifdef ENOTSOCK
	PHP_ERRNO_DECLARE_CLASS(errno_enotsock_class_entry, "ENOTSOCK", ENOTSOCK);
#endif
#ifdef EDESTADDRREQ
	PHP_ERRNO_DECLARE_CLASS(errno_edestaddrreq_class_entry, "EDESTADDRREQ", EDESTADDRREQ);
#endif
#ifdef EMSGSIZE
	PHP_ERRNO_DECLARE_CLASS(errno_emsgsize_class_entry, "EMSGSIZE", EMSGSIZE);
#endif
#ifdef EPROTOTYPE
	PHP_ERRNO_DECLARE_CLASS(errno_eprototype_class_entry, "EPROTOTYPE", EPROTOTYPE);
#endif
#ifdef ENOPROTOOPT
	PHP_ERRNO_DECLARE_CLASS(errno_enoprotoopt_class_entry, "ENOPROTOOPT", ENOPROTOOPT);
#endif
#ifdef EPROTONOSUPPORT
	PHP_ERRNO_DECLARE_CLASS(errno_eprotonosupport_class_entry, "EPROTONOSUPPORT", EPROTONOSUPPORT);
#endif
#ifdef ESOCKTNOSUPPORT
	PHP_ERRNO_DECLARE_CLASS(errno_esocktnosupport_class_entry, "ESOCKTNOSUPPORT", ESOCKTNOSUPPORT);
#endif
#ifdef EOPNOTSUPP
	PHP_ERRNO_DECLARE_CLASS(errno_eopnotsupp_class_entry, "EOPNOTSUPP", EOPNOTSUPP);
#endif
#ifdef EPFNOSUPPORT
	PHP_ERRNO_DECLARE_CLASS(errno_epfnosupport_class_entry, "EPFNOSUPPORT", EPFNOSUPPORT);
#endif
#ifdef EAFNOSUPPORT
	PHP_ERRNO_DECLARE_CLASS(errno_eafnosupport_class_entry, "EAFNOSUPPORT", EAFNOSUPPORT);
#endif
#ifdef EADDRINUSE
	PHP_ERRNO_DECLARE_CLASS(errno_eaddrinuse_class_entry, "EADDRINUSE", EADDRINUSE);
#endif
#ifdef EADDRNOTAVAIL
	PHP_ERRNO_DECLARE_CLASS(errno_eaddrnotavail_class_entry, "EADDRNOTAVAIL", EADDRNOTAVAIL);
#endif
#ifdef ENETDOWN
	PHP_ERRNO_DECLARE_CLASS(errno_enetdown_class_entry, "ENETDOWN", ENETDOWN);
#endif
#ifdef ENETUNREACH
	PHP_ERRNO_DECLARE_CLASS(errno_enetunreach_class_entry, "ENETUNREACH", ENETUNREACH);
#endif
#ifdef ENETRESET
	PHP_ERRNO_DECLARE_CLASS(errno_enetreset_class_entry, "ENETRESET", ENETRESET);
#endif
#ifdef ECONNABORTED
	PHP_ERRNO_DECLARE_CLASS(errno_econnaborted_class_entry, "ECONNABORTED", ECONNABORTED);
#endif
#ifdef ECONNRESET
	PHP_ERRNO_DECLARE_CLASS(errno_econnreset_class_entry, "ECONNRESET", ECONNRESET);
#endif
#ifdef ENOBUFS
	PHP_ERRNO_DECLARE_CLASS(errno_enobufs_class_entry, "ENOBUFS", ENOBUFS);
#endif
#ifdef EISCONN
	PHP_ERRNO_DECLARE_CLASS(errno_eisconn_class_entry, "EISCONN", EISCONN);
#endif
#ifdef ENOTCONN
	PHP_ERRNO_DECLARE_CLASS(errno_enotconn_class_entry, "ENOTCONN", ENOTCONN);
#endif
#ifdef ESHUTDOWN
	PHP_ERRNO_DECLARE_CLASS(errno_eshutdown_class_entry, "ESHUTDOWN", ESHUTDOWN);
#endif
#ifdef ETOOMANYREFS
	PHP_ERRNO_DECLARE_CLASS(errno_etoomanyrefs_class_entry, "ETOOMANYREFS", ETOOMANYREFS);
#endif
#ifdef ETIMEDOUT
	PHP_ERRNO_DECLARE_CLASS(errno_etimedout_class_entry, "ETIMEDOUT", ETIMEDOUT);
#endif
#ifdef ECONNREFUSED
	PHP_ERRNO_DECLARE_CLASS(errno_econnrefused_class_entry, "ECONNREFUSED", ECONNREFUSED);
#endif
#ifdef EHOSTDOWN
	PHP_ERRNO_DECLARE_CLASS(errno_ehostdown_class_entry, "EHOSTDOWN", EHOSTDOWN);
#endif
#ifdef EHOSTUNREACH
	PHP_ERRNO_DECLARE_CLASS(errno_ehostunreach_class_entry, "EHOSTUNREACH", EHOSTUNREACH);
#endif
#ifdef EALREADY
	PHP_ERRNO_DECLARE_CLASS(errno_ealready_class_entry, "EALREADY", EALREADY);
#endif
#ifdef EINPROGRESS
	PHP_ERRNO_DECLARE_CLASS(errno_einprogress_class_entry, "EINPROGRESS", EINPROGRESS);
#endif
#ifdef ESTALE
	PHP_ERRNO_DECLARE_CLASS(errno_estale_class_entry, "ESTALE", ESTALE);
#endif
#ifdef EUCLEAN
	PHP_ERRNO_DECLARE_CLASS(errno_euclean_class_entry, "EUCLEAN", EUCLEAN);
#endif
#ifdef ENOTNAM
	PHP_ERRNO_DECLARE_CLASS(errno_enotnam_class_entry, "ENOTNAM", ENOTNAM);
#endif
#ifdef ENAVAIL
	PHP_ERRNO_DECLARE_CLASS(errno_enavail_class_entry, "ENAVAIL", ENAVAIL);
#endif
#ifdef EISNAM
	PHP_ERRNO_DECLARE_CLASS(errno_eisnam_class_entry, "EISNAM", EISNAM);
#endif
#ifdef EREMOTEIO
	PHP_ERRNO_DECLARE_CLASS(errno_eremoteio_class_entry, "EREMOTEIO", EREMOTEIO);
#endif
#ifdef EDQUOT
	PHP_ERRNO_DECLARE_CLASS(errno_edquot_class_entry, "EDQUOT", EDQUOT);
#endif
	PHP_ERRNO_DECLARE_CLASS(errno_edquot_class_entry, "NOERROR", 0);
}

PHP_MINFO_FUNCTION(errno_ext)
{
	php_printf("PHP Errno Extension\n");
	php_info_print_table_start();
	php_info_print_table_row(2,"Version", PHP_ERRNO_EXTVER);
	php_info_print_table_end();
}

PHP_MINIT_FUNCTION(errno_ext)
{
	php_errno_init(TSRMLS_C);

	return SUCCESS;
}

zend_module_entry errno_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"errno",
	errno_functions,	/* Functions */
	PHP_MINIT(errno_ext),	/* MINIT */
	NULL,				/* MSHUTDOWN */
	NULL,				/* RINIT */
	NULL,				/* RSHUTDOWN */
	PHP_MINFO(errno_ext),	/* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
	PHP_ERRNO_EXTVER,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_ERRNO
ZEND_GET_MODULE(errno)
#endif

/* KallistiOS ##version##

   os/svcmpx.h
   (c)2000-2001 Dan Potter

   svcmpx.h,v 1.2 2002/01/05 07:23:32 bardtx Exp

*/

#ifndef __OS_SVCMPX_H
#define __OS_SVCMPX_H

#include <sys/cdefs.h>
__BEGIN_DECLS

/* Gets a current handler */
void *svcmpx_get_handler(const char *name);

/* Adds a new service handler (replacing any previous handler) */
int svcmpx_add_handler(const char *name, void *svc_struct);

/* Removes the handler of the given name (if any) */
int svcmpx_remove_handler(const char *name);

/* Returns 1 if the svcmpx module is active */
int svcmpx_enabled();

int svcmpx_init();
void svcmpx_shutdown();

__END_DECLS

#endif	/* __OS_SVCMPX_H */


/* KallistiOS ##version##

   os/abi/spu.h
   (c)2000-2001 Dan Potter

   spu.h,v 1.2 2002/01/05 07:23:32 bardtx Exp

*/

#ifndef __OS_ABI_SPU_H
#define __OS_ABI_SPU_H

#include <sys/cdefs.h>
__BEGIN_DECLS

#include <os/process.h>
#include <dc/spu.h>

typedef struct {
	service_abi_t	hdr;		/* Header info */

	void	(*write_wait)();
	void	(*memload)(uint32 to, uint8* from, int length);
	void	(*memset)(uint32 to, uint32 what, int length);
	void	(*enable)();
	void	(*disable)();
} abi_spu_t;

__END_DECLS

#endif	/* __OS_ABI_SPU_H */


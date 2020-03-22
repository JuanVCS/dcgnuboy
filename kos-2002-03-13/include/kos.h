/* KallistiOS ##version##

   kos.h
   (c)2001 Dan Potter

   kos.h,v 1.9 2002/03/04 04:32:27 bardtx Exp
*/

#ifndef __KOS_H
#define __KOS_H

/* The ultimate for the truly lazy: include and go! No more figuring out
   which headers to include for your project. */

#include <sys/cdefs.h>
__BEGIN_DECLS

#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* These still haven't been fully ported */
/* #include <kos/msg.h> */

#include <kos/fs.h>
#include <kos/fs_builtin.h>
#include <kos/fs_romdisk.h>
#include <kos/limits.h>
#include <kos/pcx.h>
#include <kos/thread.h>
#include <kos/sem.h>
#include <kos/cond.h>

#include <arch/arch.h>
#include <arch/cache.h>
#include <arch/dbgio.h>
#include <arch/irq.h>
#include <arch/spinlock.h>
#include <arch/syscall.h>
#include <arch/timer.h>
#include <arch/types.h>

#ifdef _arch_dreamcast
#	include <dc/biosfont.h>
#	include <dc/cdrom.h>
#	include <dc/fs_dcload.h>
#	include <dc/fs_iso9660.h>
#	include <dc/fs_vmu.h>
#	include <dc/asic.h>
#	include <dc/maple.h>
#	include <dc/maple/controller.h>
#	include <dc/maple/keyboard.h>
#	include <dc/maple/mouse.h>
#	include <dc/maple/vmu.h>
#	include <dc/vmu_pkg.h>
#	include <dc/spu.h>
#	include <dc/ta.h>
#	include <dc/pvr.h>
#	include <dc/video.h>
#	include <dc/fmath.h>
#	include <dc/sound/stream.h>
#	include <dc/sound/sfxmgr.h>
#	include <dc/net/broadband_adapter.h>
#	include <dc/net/lan_adapter.h>
#	include <dc/sq.h>

#	include <mp3/sndserver.h>
#	include <os/process.h>
#	include <os/svcmpx.h>
#	include <dcutils/3dutils.h>
#	include <dcutils/bspline.h>
#	include <dcutils/matrix.h>
#	include <dcutils/pcx.h>
#	include <dcutils/precompiler.h>
#	include <dcutils/pvrutils.h>
#elif _arch_gba	/* _arch_dreamcast */
#	include <gba/keys.h>
#	include <gba/sprite.h>
#	include <gba/video.h>
#else	/* _arch_gba */
#	error Invalid architecture or no architecture specified
#endif

__END_DECLS

#endif


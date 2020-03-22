/* KallistiOS ##version##

   arch/dreamcast/include/timer.h
   (c)2000-2001 Dan Potter

   timer.h,v 1.3 2002/02/24 00:22:30 bardtx Exp

*/

#ifndef __ARCH_TIMER_H
#define __ARCH_TIMER_H

#include <sys/cdefs.h>
__BEGIN_DECLS

#include <arch/types.h>

/* Timer sources -- we get four on the SH4 */
#define TMU0	0	/* Off limits during thread operation */
#define TMU1	1	/* Used for timer_spin_sleep() */
#define TMU2	2	/* Used for timer_get_ticks() */
#define WDT	3	/* Not supported yet */

/* The main timer for the task switcher to use */
#define TIMER_ID TMU0

/* Pre-initialize a timer; set values but don't start it */
int timer_prime(int which, uint32 speed, int interrupts);

/* Start a timer -- starts it running (and interrupts if applicable) */
int timer_start(int which);

/* Stop a timer -- and disables its interrupt */
int timer_stop(int which);

/* Returns the count value of a timer */
uint32 timer_count(int which);

/* Clears the timer underflow bit and returns what its value was */
int timer_clear(int which);

/* Spin-loop kernel sleep func: uses the secondary timer in the
   SH-4 to very accurately delay even when interrupts are disabled */
void timer_spin_sleep(int ms);

/* Enable timer interrupts (high priority); needs to move
   to irq.c sometime. */
void timer_enable_ints(int which);

/* Disable timer interrupts; needs to move to irq.c sometime. */
void timer_disable_ints(int which);

/* Check whether ints are enabled */
int timer_ints_enabled(int which);

/* Enable the millisecond timer */
void timer_ms_enable();
void timer_ms_disable();

/* Return the number of ticks since KOS was booted */
void timer_ms_gettime(uint32 *secs, uint32 *msecs);

/* Enable the main kernel timer */
void timer_primary_enable();
void timer_primary_disable();

/* Init function */
int timer_init();

/* Shutdown */
void timer_shutdown();

__END_DECLS

#endif	/* __ARCH_TIMER_H */


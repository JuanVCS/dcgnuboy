/* KallistiOS ##version##

   include/kos/sem.h
   (c)2001 Dan Potter

   sem.h,v 1.2 2002/01/05 07:23:32 bardtx Exp

*/

#ifndef __KOS_SEM_H
#define __KOS_SEM_H

#include <sys/cdefs.h>
__BEGIN_DECLS

#include <arch/types.h>
#include <sys/iovec.h>
#include <sys/queue.h>
#include <kos/thread.h>

/* Semaphore structure definition */
typedef struct semaphore {
	/* List entry for the global list of semaphores */
	LIST_ENTRY(semaphore)	g_list;

	/* Basic semaphore info */
	tid_t		owner;		/* Process that owns this semaphore */
	int		count;		/* The semaphore count */

	/* Threads blocked waiting for a signal */
	struct ktqueue	blocked_wait;
} semaphore_t;

LIST_HEAD(semlist, semaphore);

/* Allocate a new semaphore; the semaphore will be assigned
   to the calling process and when that process dies, the semaphore
   will also die (in theory...). */
semaphore_t *sem_create(int value);

/* Free a semaphore */
void sem_destroy(semaphore_t *sem);

/* Wait on a semaphore */
void sem_wait(semaphore_t *sem);

/* Signal a semaphore */
void sem_signal(semaphore_t *sem);

/* Return the semaphore count */
int sem_count(semaphore_t *sem);

/* Free all semaphores for the given process' pid */
void sem_freeall(int tid);

/* Init / shutdown */
int sem_init();
void sem_shutdown();

__END_DECLS

#endif	/* __KOS_SEM_H */


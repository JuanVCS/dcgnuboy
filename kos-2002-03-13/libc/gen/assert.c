/* KallistiOS ##version##

   assert.c
   (c)2002 Dan Potter

   assert.c,v 1.1 2002/02/09 06:15:42 bardtx Exp
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

CVSID("assert.c,v 1.1 2002/02/09 06:15:42 bardtx Exp");

void __assert(const char *file, int line, const char *expr, const char *msg, const char *func) {
	dbglog(DBG_CRITICAL, "\n*** ASSERTION FAILURE ***\n");
	if (msg == NULL)
		dbglog(DBG_CRITICAL, "Assertion \"%s\" failed at %s:%d in `%s'\n\n",
			expr, file, line, func);
	else
		dbglog(DBG_CRITICAL, "Assertion \"%s\" failed at %s:%d in `%s': %s\n\n",
			expr, file, line, func, msg);
	abort();
	/* NOT REACHED */
}


/* KallistiOS ##version##

   time.h
   (c)2000 Dan Potter

   time.h,v 1.2 2002/02/24 01:24:00 bardtx Exp

*/

#ifndef __TIME_H
#define __TIME_H

#include <sys/cdefs.h>
__BEGIN_DECLS

#include <arch/types.h>

typedef uint32 time_t;

time_t time(time_t *t);
double difftime(time_t time1, time_t time0);

/* Time value */
struct timeval {
	long	tv_sec;		/* Seconds */
	long	tv_usec;	/* Microseconds */
};

/* We don't support time zones, but put it here for compatability */
struct timezone {
	int	tz_minuteswest;
	int	tz_dsttime;
};

/* Return the number of seconds and microseconds since 1970 */
int gettimeofday(struct timeval *tv, struct timezone *tz);

/* Time struct */
struct tm {
	int	tm_sec;		/* seconds */
	int	tm_min;		/* minutes */
	int	tm_hour;	/* hours */
	int	tm_mday;	/* day of the month */
	int	tm_mon;		/* month (0 - 11) */
	int	tm_year;	/* year */
	int	tm_wday;	/* day of the week */
	int	tm_yday;	/* day of the year */
	int	tm_isdst;	/* daylight savings time */
};

/* Convert a struct tm into a time_t */
time_t mktime(struct tm *timeptr);

/* Convert a time_t into a struct tm (thread-safe) */
struct tm *localtime_r(const time_t *timep, struct tm * dst);

__END_DECLS

#endif	/* __TIME_H */


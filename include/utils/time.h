#ifndef TIME_H
#define TIME_H

#ifdef __linux__
#include <unistd.h>
#else
#include <windows.h>
#endif //__linux__

struct Time
{
    double seconds;
    double minutes;
    double hours;
};

void time_start_count(void);

double time_get_seconds(void);
double time_get_minutes(void);
double time_get_hours(void);


static inline time_sleep(unsigned seconds)
{
#ifdef __linux__
sleep(seconds);
#else
Sleep(seconds * 1000);
#endif //__linux__
}

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

//double time_
#endif //TIME_H

#ifndef TIME_H
#define TIME_H

#include <unistd.h>

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

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

//double time_
#endif //TIME_H

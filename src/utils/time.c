#include "utils/time.h"

static struct Time time = {0};

void time_increment_seconds(void)
{
    sleep(1);
    ++time.seconds;
}

double time_get_seconds(void)
{
    return time.seconds;
}

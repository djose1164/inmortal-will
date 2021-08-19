#ifndef PHYSICS
#define PHYSICS

#include "living.h"
#include <raylib.h>

struct PhysicsAttrs
{
    Vector2 velocity;
    Vector2 pos;
    double mass;
    double acceleration;
};

static inline double physics_get_velocity(Living *being, const double time)
{
    return (double)(being->str / being->weight) * time;
}
#endif //PHYSICS

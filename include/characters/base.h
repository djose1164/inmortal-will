#ifndef BASE_H
#define BASE_H

#include "common_atrrs.h"
#include "characters/living_vars.h"


Living *base_init(const char *name, Type type, const Frame *frame);

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void base_bindfuncs(Living *const self);

static void base_set_frame(Living *const self, const Frame *frame);

static void base_draw(const Living *self);

static void base_del(Living *self);

#endif //BASE_H

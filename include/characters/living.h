#ifndef LIVING_H
#define LIVING_H

#include "common_atrrs.h"
#include "characters/living_vars.h"


Living *living_init(const char *name, Type type, const Frame *frame);

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void living_bindfuncs(Living *const self);

static void living_set_frame(Living *const self, const Frame *frame);

static void living_draw(const Living *self);

static void living_del(Living *self);

#endif //LIVING_H

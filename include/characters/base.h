#ifndef BASE_H
#define BASE_H

#include "item/weapon.h"
#include "core/type.h"
#include "core/object.h"
#include "graphics/frame.h"

typedef struct Living Living;
struct Living
{
    Object *object_super;
    char *name; /* Name (the nicksame has to be saved here). */
    Frame *frame;
    /* Current level. */
    unsigned lvl;
    bool magic;

    void (*del)(Living *self);
    void (*draw)(const Living *self);
};

Living *base_init(const char *name, Type type, const Frame *frame);

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void base_bindfuncs(Living *const self);

static void base_set_frame(Living *const self, const Frame *frame);

static void base_draw(const Living *self);

static void base_del(Living *self);

#endif //BASE_H

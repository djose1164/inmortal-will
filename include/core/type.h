#ifndef TYPE_H
#define TYPE_H
/**
 * @brief For passing to memory_allocate. If you don't care the type pass OBJECT.
 * Objects should be freed at exit.
 */
extern enum Type
{
    PLAYER,     /* Will be player type. */
    MONSTER,    /* Will be monster type. */
    ITEM,       /* Will be item type. */
    OBJECT,     /* The type doesn't care. */
    LIST,       /* Node of linked list. */
    STRING,     /* String object. */
    SCREEN,     /* Screen Object. */
    FRAME,      /* Frame object. */
    TEXTURE,    /* Texture object. */
};
typedef enum Type Type;

#endif /* TYPE_H */
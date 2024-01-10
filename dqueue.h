#ifndef DQUEUE_H
#define DQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef char* string;
typedef void* object;

#define DEFINE_DQUEUE_HEADER(type)                                  \
    typedef struct dqueue_entry_##type {                            \
        type data;                                                  \
        struct dqueue_entry_##type *next;                           \
        struct dqueue_entry_##type *prev;                           \
    } dqueue_entry_##type;                                          \
                                                                    \
    typedef struct dqueue_##type {                                  \
        dqueue_entry_##type *head;                                  \
        dqueue_entry_##type *tail;                                  \
        size_t size;                                                \
    } dqueue_##type;                                                \
                                                                    \
    extern dqueue_##type* dqueue_init_##type();                     \
    extern void dqueue_push_##type(dqueue_##type *queue, type el);  \
    extern type dqueue_pop_##type(dqueue_##type *queue);            \
    extern void dqueue_clear_##type(dqueue_##type *queue);          \
    extern void dqueue_add_##type(dqueue_##type *queue, type el);   \
    extern type dqueue_peek_##type(dqueue_##type *queue);           \


DEFINE_DQUEUE_HEADER(object);
DEFINE_DQUEUE_HEADER(string);

#endif //DQUEUE_H

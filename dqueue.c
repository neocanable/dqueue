
#include "dqueue.h"

#define DEFINE_DQUEUE_BODY(type)                                            \
    dqueue_##type* dqueue_init_##type()                                     \
    {                                                                       \
        dqueue_##type *dqueue = x_alloc(sizeof(dqueue_##type));             \
        dqueue->head = NULL;                                                \
        dqueue->tail = NULL;                                                \
        dqueue->size = 0;                                                   \
        return dqueue;                                                      \
    }                                                                       \
                                                                            \
    void dqueue_push_##type(dqueue_##type *queue, type el)                  \
    {                                                                       \
        dqueue_entry_##type *entry = x_alloc(sizeof(dqueue_entry_##type));  \
        entry->data = el;                                                   \
        entry->next = queue->head;                                          \
        entry->prev = NULL;                                                 \
        if (queue->head != NULL) {                                          \
            queue->head->prev = entry;                                      \
        }                                                                   \
        if (queue->tail == NULL)                                            \
        {                                                                   \
            queue->tail = entry;                                            \
        }                                                                   \
        queue->head = entry;                                                \
        queue->size++;                                                      \
    }                                                                       \
                                                                            \
    type dqueue_pop_##type(dqueue_##type *queue)                            \
    {                                                                       \
        if (queue->head == NULL)                                            \
        {                                                                   \
            return NULL;                                                    \
        }                                                                   \
        dqueue_entry_##type *entry = queue->head;                           \
        queue->head = entry->next;                                          \
        queue->size--;                                                      \
        if (queue->size == 0) queue->tail = NULL;                           \
        return entry->data;                                                 \
    }                                                                       \
                                                                            \
    type dqueue_peek_##type(dqueue_##type *queue)                           \
    {                                                                       \
        if (queue->head == NULL)                                            \
        {                                                                   \
            return NULL;                                                    \
        }                                                                   \
        return queue->head->data;                                           \
    }                                                                       \
                                                                            \
    void dqueue_clear_##type(dqueue_##type *queue)                          \
    {                                                                       \
        queue->head = NULL;                                                 \
        queue->tail = NULL;                                                 \
        queue->size = 0;                                                    \
    }                                                                       \
                                                                            \
    void dqueue_add_##type(dqueue_##type *queue, type el)                   \
    {                                                                       \
        dqueue_entry_##type *entry = x_alloc(sizeof(dqueue_entry_##type));  \
        entry->data = el;                                                   \
        entry->next = NULL;                                                 \
        entry->prev = queue->tail;                                          \
        if (queue->tail != NULL) {                                          \
            queue->tail->next = entry;                                      \
        }                                                                   \
        if (queue->head == NULL)                                            \
        {                                                                   \
            queue->head = entry;                                            \
        }                                                                   \
        queue->tail = entry;                                                \
        queue->size++;                                                      \
    }                                                                       \


DEFINE_DQUEUE_BODY(object);
DEFINE_DQUEUE_BODY(string);

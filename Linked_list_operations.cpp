#include <iostream>
#include "stdint.h"

struct maybe_int64 {
    bool valid;
    int64_t value;
};

const struct maybe_int64 none_int64 = { 0 };

struct list {
    int64_t value;
    struct list* next;
};

struct maybe_int64 some_int64( int64_t i ) {
    return (struct maybe_int64) { .valid = true, .value = i };
}

struct list* node_create(int64_t value) {
    struct list* list = (struct list*) malloc(sizeof(struct list));
    if (list) {
        list->value = value;
        list->next  = NULL;
    }
    return list;
}

void list_add_front( struct list **old, int64_t value ) {
    struct list *tmp = node_create(value);
    if (old) {
        tmp->next = *old;
        *old = tmp;
    }
}

size_t list_length(const struct list* list) {
    size_t count = 0;
    while(list){
        count++;
        list = list->next;
    }
    return count;
}

struct list* list_last( struct list * list ) {
    if (list) {
        while (list->next) {
            list = list->next;
        }
        return list;
    }
    else return NULL;
}

void list_add_back(struct list** lst, int64_t value ) {
    if (!(*lst))
        (*lst) = node_create(value);
    else
    {
        struct list *last = list_last(*lst);
        last->next= (list*) malloc(sizeof(struct list));
        last->next->value = value;
        last->next->next = NULL;
    }
}

int64_t list_sum( const struct list* list ) {
    size_t count = 0;
    while(list){
        count = count + list->value;
        list = list->next;
    }
    return count;
}

int64_t list_at(const struct list* list, size_t idx) {
    while (list && idx--) {
        list = list->next;
    }
    return list
           ? list->value
           : NULL;
}

struct list* list_reverse( struct list const* list ) {
    struct list* reverse_list = NULL;
    for (struct list const* current = list; current ; current = current -> next ) {
        list_add_front( &reverse_list, current-> value );
    }
    return reverse_list;
}

struct maybe_int64 maybe_read_int64() {
    int64_t i;
    if (scanf("%ld", &i) > 0)
    return some_int64(i);
    return none_int64;
}

struct list* list_read() {
    struct list* list = NULL;
    struct list** plast = &list;
    struct maybe_int64 i = {0};
    for (;;) {
        i = maybe_read_int64();
        if (i.valid) {
            *plast = node_create( i.value );
            plast = &((**plast).next);
        }
        else return list;
    }
    return list;
}

void list_destroy( struct list* list ) {
    while ( list )
    {
        struct list* tmp = list->next;
        free(list);
        list = tmp;
    }
}

#ifndef TEST_01_LINKED_LIST_OPERATIONS_H
#define TEST_01_LINKED_LIST_OPERATIONS_H
struct list* node_create(int64_t value);
void list_add_front( struct list **old, int64_t value );
void list_destroy( struct list* list );
size_t list_length(const struct list* list);
void list_add_back(struct list** lst, int64_t value );
int64_t list_sum( const struct list* list );
struct list* list_last( struct list * list );
int64_t list_at(const struct list* list, size_t idx);
struct list* list_reverse( const struct list* list );
struct maybe_int64 maybe_read_int64();
struct list* list_read();
#endif //TEST_01_LINKED_LIST_OPERATIONS_H

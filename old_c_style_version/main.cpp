#include <iostream>
#include "Linked_list_operations.h"

int main()
{
    struct list* s = list_read();
    struct list* hm;
    hm = list_reverse(s);
    for (size_t i = 0; i < list_length(s); i++) std::cout << list_at(s, i) << " ";
    std::cout << "\n";
    for (size_t i = 0; i < list_length(hm); i++) std::cout << list_at(hm, i) << " ";
    list_destroy(s);
    list_destroy(hm);
    return 0;
}

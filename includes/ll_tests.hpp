#ifndef LL_CONTAINERS_LIST_TESTS_HPP
#define LL_CONTAINERS_LIST_TESTS_HPP

#include "ll_headers.hpp"

void list_tests();

template <typename T> bool operator==(ll::list<T> &a, std::list<T> &b) {
  if (a.size() != b.size())
    return (false);
  if (a.empty() != b.empty())
    return (false);
  typename ll::list<T>::iterator it = a.begin();
  typename std::list<T>::iterator it2 = b.begin();
  while (it != a.end()) {
    if (*it != *it2)
      return (false);
    ++it;
    ++it2;
  }
  return (true);
};

#endif // LL_CONTAINERS_LIST_TESTS_HPP

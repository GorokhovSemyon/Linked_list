#ifndef LL_CONTAINERS_ALGORITHM_HPP
#define LL_CONTAINERS_ALGORITHM_HPP

namespace ll {
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2) {
  while (first1 != last1) {
    if (first2 == last2 || *first2 < *first1)
      return false;
    else if (*first1 < *first2)
      return true;
    ++first1;
    ++first2;
  }
  return (first2 != last2);
}
} // namespace ll
#endif // LL_CONTAINERS_ALGORITHM_HPP

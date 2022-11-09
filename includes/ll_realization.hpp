#ifndef LL_CONTAINERS_LIST_H
#define LL_CONTAINERS_LIST_H

#include "str_compare.hpp"
#include <limits>

namespace ll {
template <class T> class list {
private:
  class node {
  public:
    T data;
    node *next;
    node *prev;

    node() : next(nullptr), prev(nullptr){};
    node(const T &val) : data(val), next(nullptr), prev(nullptr){};
    node(node &src) : data(src.data), next(nullptr), prev(nullptr){};
  };
  node *_llNode;
  size_t _len;

public:
  list() : _llNode(new node()), _len(0) {
    this->_llNode->next = this->_llNode;
    this->_llNode->prev = this->_llNode;
  };
  list(size_t n, const T &val = T()) : _llNode(new node()), _len(0) {
    this->_llNode->next = this->_llNode;
    this->_llNode->prev = this->_llNode;
    this->assign(n, val);
  };
  template <class InputIterator>
  list(InputIterator first, InputIterator last) : _llNode(new node()), _len(0) {
    this->_llNode->next = this->_llNode;
    this->_llNode->prev = this->_llNode;
    this->assign(first, last);
  };
  list(const list &x) : _llNode(new node()), _len(0) {
    this->_llNode->next = this->_llNode;
    this->_llNode->prev = this->_llNode;
    this->assign(x.begin(), x.end());
  };
  ~list() {
    this->clear();
    delete this->_llNode;
  };

  list &operator=(const list &x) {
    this->assign(x.begin(), x.end());
    return (*this);
  };

  /* Forward iterator class */
  class iterator {
  public:
    node *_current;

    iterator() : _current(nullptr){};
    iterator(node *Node) : _current(Node){};
    iterator(const iterator &src) : _current(src._current){};
    ~iterator(){};

    /* Operators */
    iterator &operator++() {
      this->_current = this->_current->next;
      return (*this);
    };
    iterator operator++(int) {
      iterator result(*this);

      this->_current = this->_current->next;
      return (result);
    };
    iterator &operator--() {
      this->_current = this->_current->prev;
      return (*this);
    };
    iterator operator--(int) {
      iterator result(*this);

      this->_current = this->_current->prev;
      return (result);
    };
    T &operator*() { return (this->_current->data); };
    T *operator->() const { return &(operator*()); }
    bool operator!=(const iterator &rhs) {
      if (this->_current != rhs._current)
        return (true);
      else
        return (false);
    };
    bool operator==(const iterator &rhs) {
      if (this->_current == rhs._current)
        return (true);
      else
        return (false);
    };
    iterator &operator=(const iterator &rhs) {
      if (this != &rhs)
        this->_current = rhs._current;
      return (*this);
    };
  };

  /* Const Forward iterator class */
  class const_iterator {
  public:
    node *_current;

    const_iterator() : _current(nullptr){};
    const_iterator(node *Node) : _current(Node){};
    const_iterator(const const_iterator &src) : _current(src._current){};
    ~const_iterator(){};

    /* Operators */
    const_iterator &operator++() {
      this->_current = this->_current->next;
      return (*this);
    };
    const_iterator operator++(int) {
      const_iterator result(*this);

      this->_current = this->_current->next;
      return (result);
    };
    const_iterator &operator--() {
      this->_current = this->_current->prev;
      return (*this);
    };
    const_iterator operator--(int) {
      const_iterator result(*this);

      this->_current = this->_current->prev;
      return (result);
    };
    const T &operator*() { return (this->_current->data); };
    const T *operator->() const { return &(operator*()); }
    bool operator!=(const const_iterator &rhs) {
      if (this->_current != rhs._current)
        return (true);
      else
        return (false);
    };
    bool operator==(const const_iterator &rhs) {
      if (this->_current == rhs._current)
        return (true);
      else
        return (false);
    };
    const_iterator &operator=(const const_iterator &rhs) {
      if (this != &rhs)
        this->_current = rhs._current;
      return (*this);
    };
  };

  /* Iterators */
  iterator begin(void) { return (iterator(this->_llNode->next)); };
  const_iterator begin(void) const {
    return (const_iterator(this->_llNode->next));
  };
  iterator end() { return (iterator(this->_llNode)); };
  const_iterator end() const { return (const_iterator(this->_llNode)); };

  /* Capacity */
  bool empty() const {
    if (this->_len == 0)
      return true;
    else
      return false;
  };
  size_t size() const { return (this->_len); };

  size_t max_size() const {
    return (std::numeric_limits<size_t>::max() / (sizeof(node)));
  };

  /* Element access */
  T &front() { return (this->_llNode->next->data); };
  const T &front() const { return (this->_llNode->next->data); };
  T &back() { return (this->_llNode->prev->data); };
  const T &back() const { return (this->_llNode->prev->data); };

  /* Modifiers */
  template <class InputIterator>
  void assign(InputIterator first, InputIterator last) {
    this->clear();
    this->insert(this->begin(), first, last);
  };
  void assign(size_t n, const T &val) {
    this->clear();
    this->insert(this->begin(), n, val);
  };
  void push_front(const T &val) {
    node *newNode = new node(val);

    newNode->prev = this->_llNode;
    if (this->_len == 0)
      newNode->next = this->_llNode;
    else {
      newNode->next = this->_llNode->next;
      newNode->next->prev = newNode;
    }
    this->_llNode->next = newNode;
    if (this->_len == 0)
      this->_llNode->prev = newNode;
    this->_len++;
  };
  void pop_front() {
    node *address = this->_llNode->next;

    this->_llNode->next = address->next;
    address->next->prev = this->_llNode;
    delete address;
    this->_len--;
    if (this->_len == 0) {
      this->_llNode->next = this->_llNode;
      this->_llNode->prev = this->_llNode;
    }
  };
  void push_back(const T &val) {
    node *newNode = new node(val);

    newNode->next = this->_llNode;
    if (this->_len == 0)
      newNode->prev = this->_llNode;
    else {
      newNode->prev = this->_llNode->prev;
      newNode->prev->next = newNode;
    }
    this->_llNode->prev = newNode;
    if (this->_len == 0)
      this->_llNode->next = newNode;
    this->_len++;
  };
  void pop_back() {
    node *address = this->_llNode->prev;

    this->_llNode->prev = address->prev;
    address->prev->next = this->_llNode;
    delete address;
    this->_len--;
    if (this->_len == 0) {
      this->_llNode->next = this->_llNode;
      this->_llNode->prev = this->_llNode;
    }
  };
  iterator insert(iterator position, const T &val) {
    iterator ret;

    if (position._current != this->_llNode) {
      node *newNode = new node(val);

      ret._current = newNode;
      newNode->next = position._current;
      newNode->prev = position._current->prev;
      position._current->prev->next = newNode;
      position._current->prev = newNode;
      this->_len++;
    } else {
      this->push_back(val);
      ret._current = this->_llNode;
    }
    return (ret);
  };
  void insert(iterator position, size_t n, const T &val) {
    size_t i = 0;
    while (i++ < n)
      position = this->insert(position, val);
  };
  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last) {
    T val;
    while (first != last) {
      val = *first;
      position = this->insert(position, val);
      first++;
    }
  };
  iterator erase(iterator position) {
    iterator ret;

    if (position._current != this->_llNode) {
      ret._current = position._current->next;
      position._current->next->prev = position._current->prev;
      position._current->prev->next = position._current->next;
      this->_len--;
      delete position._current;
    }
    return (ret);
  };
  iterator erase(iterator first, iterator last) {
    while (first != last)
      first = this->erase(first);
    return (first);
  };
  void swap(list &x) {
    size_t nlen;
    node *nNode;

    nlen = this->_len;
    this->_len = x._len;
    x._len = nlen;
    nNode = this->_llNode;
    this->_llNode = x._llNode;
    x._llNode = nNode;
  };
  void resize(size_t n, T val = T()) {
    if (n > this->size()) {
      while (n > this->size())
        this->push_back(val);
    } else {
      while (n < this->size())
        this->pop_back();
    }
  };
  void clear() {
    while (!this->empty())
      this->pop_front();
  }

  /* Operations */
  void splice(iterator position, list &x) {
    this->splice(position, x, x.begin(), x.end());
  };
  void splice(iterator position, list &x, iterator i) {
    iterator first = i;
    i++;
    this->splice(position, x, first, i);
  };
  void splice(iterator position, list &x, iterator first, iterator last) {
    list<T>::iterator it = first;
    size_t len = 0;

    while (it++ != last)
      len++;
    first._current->prev->next = last._current;
    last--;
    last._current->next->prev = first._current->prev;
    position._current->prev->next = first._current;
    first._current->prev = position._current->prev;
    last._current->next = position._current;
    position._current->prev = last._current;
    this->_len += len;
    x._len -= len;
  };
  void remove(const T &val) {
    list<T>::iterator it = this->begin();
    while (it != this->end()) {
      if (*it == val)
        it = this->erase(it);
      else
        it++;
    }
  };

  node *sortedMerge(node *a, node *b) {
    if (a == nullptr) {
      return b;
    } else if (b == nullptr) {
      return a;
    }
    node *result = nullptr;
    if (a->data <= b->data) {
      result = a;
      result->next = sortedMerge(a->next, b);
    } else {
      result = b;
      result->next = sortedMerge(a, b->next);
    }
    return result;
  }

  void frontBackSplit(node *source, node **frontRef, node **backRef,
                      size_t len) {
    if (source == nullptr || source->next == nullptr) {
      *frontRef = source;
      *backRef = nullptr;
      return;
    }
    int cnt = 0;
    node *slow = source;
    node *fast = source->next;
    while (fast != nullptr && cnt < len) {
      cnt++;
      fast = fast->next;
      if (fast != nullptr && cnt < len) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
  }

  void mergesort(node **head, size_t len) {
    if (*head == nullptr || (*head)->next == nullptr) {
      return;
    }
    node *a;
    node *b;
    frontBackSplit(*head, &a, &b, len);
    mergesort(&a, len);
    mergesort(&b, len);
    *head = sortedMerge(a, b);
  }

  void sort() {
    iterator it = this->begin();
    node *tmp = this->begin()._current;
    node **tmp_ptr = &tmp;
    mergesort(tmp_ptr, this->_len);
    for (int j = 0; j < this->_len; j++)
      it++;
    it._current->next = this->_llNode;
  };

  template <class Compare> void sort(Compare comp) {
    size_t i = 0;
    iterator it;
    iterator ite = this->end();
    T bubble;

    while (i < this->_len) {
      it = this->begin();
      ite--;
      while (it != ite) {
        if (!comp(it._current->data, it._current->next->data)) {
          bubble = it._current->data;
          it._current->data = it._current->next->data;
          it._current->next->data = bubble;
        }
        it++;
      }
      i++;
    }
  };
};

/* Non member function overloads */
template <class T> void swap(list<T> &x, list<T> &y) { x.swap(y); };

template <class T> bool operator==(const list<T> &lhs, const list<T> &rhs) {
  typename list<T>::const_iterator itl = lhs.begin();
  typename list<T>::const_iterator itle = lhs.end();
  typename list<T>::const_iterator itr = rhs.begin();
  typename list<T>::const_iterator itre = rhs.end();

  if (lhs.size() != rhs.size())
    return (false);
  while (itl != itle && itr != itre) {
    if (*itl != *itr)
      return (false);
    itl++;
    itr++;
  }
  return (true);
};

template <class T> bool operator!=(const list<T> &lhs, const list<T> &rhs) {
  return (!(lhs == rhs));
};

template <class T> bool operator<(const list<T> &lhs, const list<T> &rhs) {
  return (ll::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                      rhs.end()));
};

template <class T> bool operator>(const list<T> &lhs, const list<T> &rhs) {
  return (operator<(rhs, lhs));
};

template <class T> bool operator<=(const list<T> &lhs, const list<T> &rhs) {
  return (!(operator<(rhs, lhs)));
};

template <class T> bool operator>=(const list<T> &lhs, const list<T> &rhs) {
  return (!(operator<(lhs, rhs)));
};
} // namespace ll
#endif // LL_CONTAINERS_LIST_H

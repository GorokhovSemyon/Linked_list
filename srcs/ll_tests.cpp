#include "ll_tests.hpp"

static void check(std::string const title, bool value) {

  std::string margin(38 - title.length(), ' ');
  if (value)
    std::cout << title << ": " << margin << GREEN << GOOD << RESET << std::endl;
  else
    std::cout << title << ": " << margin << FAIL << std::endl;
}

static bool compare_nocase(const std::string &first,
                           const std::string &second) {
  unsigned int i = 0;
  while ((i < first.length()) && (i < second.length())) {
    if (tolower(first[i]) < tolower(second[i]))
      return true;
    else if (tolower(first[i]) > tolower(second[i]))
      return false;
    ++i;
  }
  return (first.length() < second.length());
}

static void constructor_tests() {
  std::list<std::string> l1;
  ll::list<std::string> myl1;
  std::string name = "Default constructor test";

  std::cout << GREEN << "~~~~~~~~~~~ Constructors tests ~~~~~~~~~~~" << RESET
            << std::endl;

  check(name, myl1 == l1);

  std::list<std::string> filll1(15, "12341234");
  ll::list<std::string> myfilll1(15, "12341234");

  name = "Fill constructor test";
  check(name, myfilll1 == filll1);

  std::vector<int> range_list(7, -41234231);
  std::list<int> rangel1(range_list.begin(), --range_list.end());
  ll::list<int> myrangel1(range_list.begin(), --range_list.end());

  name = "Range constructor test";
  check(name, myrangel1 == rangel1);

  std::list<int> cpl1(rangel1);
  ll::list<int> mycpl1(myrangel1);

  name = "Copy constructor test";
  check(name, mycpl1 == cpl1);
}

static void copy_operator_tests() {
  std::list<std::string> filll1(15, "12341234");
  ll::list<std::string> myfilll1(15, "12341234");
  std::list<std::string> cpyl1 = filll1;
  ll::list<std::string> mycpyl1 = myfilll1;
  std::string name = "Copy operator test";

  std::cout << GREEN << "~~~~~~~~~~~ Copy operator test ~~~~~~~~~~~" << RESET
            << std::endl;
  check(name, mycpyl1 == cpyl1);
}

static void iterators_tests() {
  std::list<int> l1;
  ll::list<int> myl1;
  std::string name = "Begin iterator test";

  l1.push_back(1);
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(5);
  l1.push_back(8);
  l1.push_back(13);
  l1.push_back(21);
  l1.push_back(34);
  l1.push_back(55);
  myl1.push_back(1);
  myl1.push_back(1);
  myl1.push_back(2);
  myl1.push_back(3);
  myl1.push_back(5);
  myl1.push_back(8);
  myl1.push_back(13);
  myl1.push_back(21);
  myl1.push_back(34);
  myl1.push_back(55);

  std::cout << GREEN << "~~~~~~~~~~~~ Iterators tests ~~~~~~~~~~~~~" << RESET
            << std::endl;
  check(name, *myl1.begin() == *l1.begin());

  name = "End iterator test";
  check(name, *--myl1.end() == *--l1.end());

  std::cout << GREEN << "~~~~~~ Testing for iterators output ~~~~~~" << RESET
            << std::endl;

  const std::list<int> l2(l1);
  const ll::list<int> myl2(myl1);

  std::cout << "L1 forward output:" << std::endl;

  for (std::list<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

  std::cout << "myL1 forward output:" << std::endl;

  for (ll::list<int>::iterator it = myl1.begin(); it != myl1.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

  std::cout << "L2 const forward output:" << std::endl;

  for (std::list<int>::const_iterator it = l2.begin(); it != l2.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

  std::cout << "myL2 const forward output:" << std::endl;

  for (ll::list<int>::const_iterator it = myl2.begin(); it != myl2.end();
       ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;
}

static void capacity_tests() {
  std::list<int> l1;
  ll::list<int> myl1;
  std::string name = "Size test";

  l1.push_back(1);
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(5);
  l1.push_back(8);
  l1.push_back(13);
  l1.push_back(21);
  l1.push_back(34);
  l1.push_back(55);
  myl1.push_back(1);
  myl1.push_back(1);
  myl1.push_back(2);
  myl1.push_back(3);
  myl1.push_back(5);
  myl1.push_back(8);
  myl1.push_back(13);
  myl1.push_back(21);
  myl1.push_back(34);
  myl1.push_back(55);

  std::cout << GREEN << "~~~~~~~~~~~~ Capacity tests ~~~~~~~~~~~~~~" << RESET
            << std::endl;

  check(name, myl1.size() == l1.size());

  name = "Max size test";
  check(name, myl1.max_size() == 2 * l1.max_size());
}

static void element_access_tests() {
  std::list<std::string> l1;
  ll::list<std::string> myl1;
  std::string name;

  l1.push_back("a");
  l1.push_back("b");
  l1.push_back("c");
  l1.push_back("d");
  l1.push_back("e");
  l1.push_back("f");
  l1.push_back("g");
  l1.push_back("h");
  l1.push_back("i");
  l1.push_back("j");
  myl1.push_back("a");
  myl1.push_back("b");
  myl1.push_back("c");
  myl1.push_back("d");
  myl1.push_back("e");
  myl1.push_back("f");
  myl1.push_back("g");
  myl1.push_back("h");
  myl1.push_back("i");
  myl1.push_back("j");

  const std::list<std::string> l2(l1);
  const ll::list<std::string> myl2(myl1);

  std::cout << GREEN << "~~~~~~~~~~ Element access tests ~~~~~~~~~~" << RESET
            << std::endl;

  name = "Front test";
  check(name, myl1.front() == l1.front());

  name = "Const front test";
  check(name, myl2.front() == l2.front());

  name = "Back test";
  check(name, myl1.back() == l1.back());

  name = "Const back test";
  check(name, myl2.back() == l2.back());
}

static void modifiers_test() {
  std::list<std::string> l1;
  ll::list<std::string> myl1;
  std::vector<std::string> v(15, "Bondrewd");
  std::string name = "Insert 1 element test";

  std::cout << GREEN << "~~~~~~~~~~~~ Modifiers tests ~~~~~~~~~~~~~" << RESET
            << std::endl;

  std::list<std::string>::iterator it1 = l1.begin();
  ll::list<std::string>::iterator myit1 = myl1.begin();

  it1++;
  it1++;
  it1++;
  myit1++;
  myit1++;
  myit1++;

  l1.insert(it1, "John");
  myl1.insert(myit1, "John");
  check(name, myl1 == l1);

  name = "Insert fill test";
  l1.insert(it1, 5, "John");
  myl1.insert(myit1, 5, "John");
  check(name, myl1 == l1);

  name = "Insert range test";
  l1.insert(it1, v.begin(), v.end());
  myl1.insert(myit1, v.begin(), v.end());
  check(name, myl1 == l1);

  it1 = l1.begin();
  myit1 = myl1.begin();
  it1++;
  it1++;
  it1++;
  myit1++;
  myit1++;
  myit1++;

  l1.push_back("1");
  myl1.push_back("1");
  name = "Pushback test";
  check(name, myl1 == l1);

  l1.push_back("2");
  myl1.push_back("2");
  l1.push_back("3");
  myl1.push_back("3");

  l1.push_front("1");
  myl1.push_front("1");
  name = "Pushfront test";
  check(name, myl1 == l1);

  l1.pop_front();
  myl1.pop_front();
  name = "Pop front test";
  check(name, myl1 == l1);

  l1.pop_back();
  myl1.pop_back();
  name = "Pop back test";
  check(name, myl1 == l1);

  name = "Erase 1 element test";
  it1 = l1.erase(it1);
  myit1 = myl1.erase(myit1);
  check(name, myl1 == l1 && *it1 == *myit1);

  name = "Erase range of elements test";
  std::list<std::string>::iterator erit1 = l1.erase(it1, l1.end());
  ll::list<std::string>::iterator myerit1 = myl1.erase(myit1, myl1.end());

  check(name, myl1 == l1 && *--erit1 == *--myerit1);

  name = "Resize test with n < capacity";
  l1.resize(8);
  myl1.resize(8);
  check(name, myl1 == l1);

  name = "Resize test with n == capacity";
  l1.resize(8);
  myl1.resize(8);
  check(name, myl1 == l1);

  name = "Resize test with n > capacity";
  l1.resize(19);
  myl1.resize(19);
  check(name, myl1 == l1);

  std::list<std::string> v2;
  ll::list<std::string> myv2;

  v2.swap(l1);
  myv2.swap(myl1);
  name = "Swap test";
  check(name, myl1 == l1 && myv2 == v2);

  name = "Clear test";
  l1.clear();
  myl1.clear();
  check(name, myl1 == l1);
}

static void relational_operators_test() {
  std::list<int> foo(3, 100); // three ints with a value of 100
  std::list<int> bar(2, 200); // two ints with a value of 200
  std::list<int> foo2(3, 100);
  std::list<int> bar2(2, 200);
  ll::list<int> myfoo((size_t)3, 100);
  ll::list<int> myfoo2((size_t)3, 100);
  ll::list<int> mybar((size_t)2, 200);
  ll::list<int> mybar2((size_t)2, 200);
  std::string name;

  std::cout << GREEN << "~~~~~~ Relational operators tests ~~~~~~~~" << RESET
            << std::endl;

  name = "== test";
  check(name, (foo == foo2) && (myfoo == myfoo2));

  name = "!= test";
  check(name, (foo != bar) && (myfoo != mybar));

  name = "< test";
  check(name, (foo < bar) && (myfoo < mybar));

  name = "<= test";
  check(name, (foo <= bar) && (myfoo <= mybar));

  name = "> test";
  check(name, !((foo > bar) && (myfoo > mybar)));

  name = ">= test";
  check(name, !((foo >= bar) && (myfoo >= mybar)));
}

static void operation_tests() {
  std::list<int> l1(2, 49), l2(4, 1984);
  std::list<int>::iterator it1;
  ll::list<int> myl1((size_t)2, 49), myl2((size_t)4, 1984);
  ll::list<int>::iterator myit1;
  std::string name;

  std::cout << GREEN << "~~~~~~ Operations operators tests ~~~~~~~~" << RESET
            << std::endl;

  name = "Splice entire list test";
  it1 = l1.begin();
  l1.splice(it1, l2);
  myit1 = myl1.begin();
  myl1.splice(myit1, myl2);
  check(name, myl1 == l1);

  name = "Splice single element test";
  it1 = l2.begin();
  l2.splice(it1, l1, l1.begin());
  myit1 = myl2.begin();
  myl2.splice(myit1, myl1, myl1.begin());
  check(name, myl2 == l2);

  name = "Splice element range test";
  it1 = l2.begin();
  l2.splice(it1, l1, l1.begin(), l1.end());
  myit1 = myl2.begin();
  myl2.splice(myit1, myl1, myl1.begin(), myl1.end());
  check(name, myl2 == l2);

  name = "Merge sort test";
  l1.push_back(99);
  l1.push_back(80);
  l1.push_back(63);
  l1.push_back(48);
  l1.push_back(35);
  l1.push_back(24);
  l1.push_back(15);
  l1.push_back(8);
  l1.push_back(3);
  l1.push_back(1);
  myl1.push_back(99);
  myl1.push_back(80);
  myl1.push_back(63);
  myl1.push_back(48);
  myl1.push_back(35);
  myl1.push_back(24);
  myl1.push_back(15);
  myl1.push_back(8);
  myl1.push_back(3);
  myl1.push_back(1);
  l1.sort();
  myl1.sort();
  check(name, myl1 == l1);

  name = "Sort with comp test";
  std::list<std::string> list;
  std::list<std::string>::iterator it;
  ll::list<std::string> mylist;
  ll::list<std::string>::iterator myit;

  list.push_back("One");
  list.push_back("Two");
  list.push_back("Three");
  mylist.push_back("One");
  mylist.push_back("Two");
  mylist.push_back("Three");

  list.sort(compare_nocase);
  mylist.sort(compare_nocase);
  check(name, mylist == list);

  name = "Remove element test";
  l2.remove(1984);
  myl2.remove(1984);
  check(name, myl2 == l2);
}

void list_tests() {
  std::cout << GREEN << std::endl;
  std::cout << "==========================================" << std::endl;
  std::cout << "~~~~~~~~~~~~~~ List tests ~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "==========================================" << std::endl;
  std::cout << RESET;

  constructor_tests();
  copy_operator_tests();
  iterators_tests();
  capacity_tests();
  element_access_tests();
  modifiers_test();
  operation_tests();
  relational_operators_test();
}
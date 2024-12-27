

#include "List.h"
#include "unit_test_framework.h"

using namespace std;



TEST(test_size) {
    int size = 6;
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);
    int size_comp = list.size();
    ASSERT_EQUAL(size, size_comp);
}

TEST(test_empty) {
    List<int> list;
    ASSERT_TRUE(list.empty());
}

TEST(test_front) {
    List<int> list;
    list.push_back(5);
    list.push_back(7);
    list.push_front(1);
    ASSERT_EQUAL(list.front(), 1);
}

TEST(test_front2) {
    List<int> list;
    list.push_front(5);
    list.push_front(7);
    list.push_front(0);
    ASSERT_EQUAL(list.front(), 0);
}

TEST(test_back) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    ASSERT_EQUAL(list.back(), 1);
}

TEST(test_back2) {
    List<int> list;
    list.push_back(1);
    list.push_front(2);
    list.push_front(3);
    ASSERT_EQUAL(list.back(), 1);
}

TEST(test_pop_front) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);
    ASSERT_EQUAL(list.size(), 6);
    ASSERT_EQUAL(list.front(), 6);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 5);
}

TEST(test_pop_front2) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    ASSERT_EQUAL(list.size(), 6);
    ASSERT_EQUAL(list.front(), 1);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 3);
}

TEST(test_pop_back) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6); 
    ASSERT_EQUAL(list.size(), 6);
    ASSERT_EQUAL(list.back(), 1);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 2);
}

TEST(test_pop_back2) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    ASSERT_EQUAL(list.size(), 6);
    ASSERT_EQUAL(list.back(), 6);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 5);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 4);
}

TEST(clear) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6); 
    list.clear();
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_front_iterator) {
    List<string> list;
    list.push_back("a");
    list.push_back("b");
    list.push_back("c");
    list.push_back("d");
    List<string>::Iterator itor = list.begin();
    ASSERT_EQUAL(*itor, "a");
    ++itor;
    ASSERT_EQUAL(*itor, "b");
    ++itor;
    ASSERT_EQUAL(*itor, "c");
    ++itor;
    ASSERT_EQUAL(*itor, "d");
    --itor;
    ASSERT_EQUAL(*itor, "c");
    --itor;
    ASSERT_EQUAL(*itor, "b");
    --itor;
    ASSERT_EQUAL(*itor, "a");
}

TEST(test_push_front_push_back_until_empty) {
    List<double> list;
    list.push_back(1.1);
    list.push_back(1.2);
    list.push_back(1.3);
    list.push_back(1.4);
    ASSERT_EQUAL(list.size(), 4);
    list.pop_back();
    list.pop_front();
    list.pop_back();
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(test_iterator_operations) {
    List<string> list;
    list.push_back("a");
    list.push_back("b");
    list.push_back("c");
    list.push_back("d");
    List<string>::Iterator itor = list.begin();
    ASSERT_TRUE(*itor == "a");
    ++itor;
    ++itor;
    ++itor;
    ASSERT_TRUE(*itor == "d");
    --itor;
    ASSERT_TRUE(*itor == "c");
    --itor;
    --itor;
    ASSERT_TRUE(*itor == "a");
}

TEST(test_iterator_begin) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator itor = list.begin();
    ASSERT_EQUAL(*itor, 1);
    list.pop_front();
    itor = list.begin();
    ASSERT_EQUAL(*itor, 2);
}

TEST(test_iterator_end) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator itor = list.end();
    List<int>::Iterator itor_comp;
    ASSERT_TRUE(itor == itor_comp);
}

TEST(test_iterator_erase) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator itor = list.begin();
    list.erase(itor);
    itor = list.begin();
    ASSERT_EQUAL(*itor, 2);
    
    List<int>::Iterator itor2 = list.begin();
    ++itor2;
    list.erase(itor2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 4);
    itor2 = list.begin();
    list.erase(itor2);
    ASSERT_EQUAL(list.back(), 4)
    ASSERT_EQUAL(list.size(), 1); 
}

/*
TEST(test_erase) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator itor = list.begin();
    ++itor;
    list.erase(itor);
    itor = list.begin();
    ASSERT_EQUAL(*itor, 1);
} */

TEST(test_iterator_insert) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator itor = list.begin();
    ++itor;
    ASSERT_TRUE(list.size() == 4);
    list.insert(itor, 5);
    ASSERT_TRUE(list.size() == 5);
    itor = list.begin();
    ASSERT_EQUAL(*itor, 1);
    ++itor;
    ASSERT_EQUAL(*itor, 5);
    ++itor;
    ASSERT_EQUAL(*itor, 2);
    ++itor;
    ASSERT_EQUAL(*itor, 3);
    ++itor;
    ASSERT_EQUAL(*itor, 4);
}


TEST(test_iterator_insert2) {
    List<string> list;
    list.push_back("a");
    list.push_back("b");
    list.push_back("c");
    list.push_back("d");
    List<string>::Iterator itor = list.begin();
    ++itor;
    ++itor;
    ASSERT_TRUE(list.size() == 4);
    list.insert(itor, "z");
    ASSERT_TRUE(list.size() == 5);
    itor = list.begin();
    ASSERT_EQUAL(*itor, "a");
    ++itor;
    ASSERT_EQUAL(*itor, "b");
    ++itor;
    ASSERT_EQUAL(*itor, "z");
    ++itor;
    ASSERT_EQUAL(*itor, "c");
    ++itor;
    ASSERT_EQUAL(*itor, "d");
}

TEST(test_copy) {
    List<int> list1;
    List<int> list2;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list2 = list1;
    List<int>::Iterator itor1 = list1.begin();
    List<int>::Iterator itor2 = list2.begin();
    ASSERT_TRUE(list1.size() == list2.size());
    ASSERT_EQUAL(list1.front(), list2.front());
    ASSERT_EQUAL(list1.back(), list2.back());
    for (int i = 0; i < list1.size(); ++i) {
        ASSERT_EQUAL(*itor1, *itor2);
        ++itor1;
        ++itor2;
    }
}

TEST(assignment_operator) {
    List<int> list1;
    List<int> list2;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(6);
    list2 = list1;
    List<int>::Iterator itorL1 = list1.begin();
    List<int>::Iterator itorL2 = list2.begin();
    ASSERT_EQUAL(list1.size(), list2.size());
    ASSERT_EQUAL(list1.front(), list2.front());
    ASSERT_EQUAL(list1.back(), list2.back());
    for (int i = 0; i < list1.size(); ++i) {
        ASSERT_TRUE(*itorL1 == *itorL2);
        ++itorL1;
        ++itorL2;
    }
}


TEST(operators2) {
    List<string> list;
    list.push_back("a");
    list.push_back("b");
    list.push_back("c");
    list.push_back("d");
    List<string>::Iterator itor = list.begin();
    List<string>::Iterator itor2 = list.begin();
    ASSERT_TRUE(*itor == *itor2);
    ++itor;
    ASSERT_TRUE(*itor != *itor2);
    --itor;
    ASSERT_TRUE(*itor == *itor2);
    ++itor;
    ++itor2;
    ++itor2;
    ASSERT_TRUE(*itor != *itor2);
}


TEST(contructor) {
    List<string> list;
    list.push_back("a");
    list.push_back("b");
    list.push_back("c");
    list.push_back("d");
    List<string>::Iterator p = list.begin();
    List<string>::Iterator p2(p);
    ASSERT_TRUE(*p2 == *p);
}




TEST_MAIN()





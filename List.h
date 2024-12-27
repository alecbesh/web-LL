#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL
#include <string>
#include <sstream>
#include <utility>


template <typename T>
class List {
  
public:

  //EFFECTS:  returns true if the list is empty
  bool empty() const {
    if (first == nullptr) {
      return true;
    }
    else {
      return false;
    }
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const {
    int count = 0;
    Node *begin = first;
    while (begin != nullptr) {
      ++count;
      begin = begin->next;
    }
    return count;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front() {
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back() {
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum) {
    Node *begin = new Node;
    begin->datum = datum;
    begin->next = first;
    begin->prev = nullptr;
    if (empty()) {
      first = begin;
      last = begin;
    }
    else {
      first->prev = begin;
      first = begin;
    }
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum) {
    Node *end = new Node;
    end->datum = datum;
    end->prev = last;
    end->next = nullptr;
    if (empty()) {
      first = end;
      last = end;
    }
    else {
      last->next = end;
      last = end;
    }
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front() {
    Node *victim = first;
    first = first->next;
    if (first == nullptr) {
      last = nullptr;
    }
    else {
      first->prev = nullptr;
    }
    delete victim;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back() {
    Node *victim = last;
    last = last->prev;
    if (last == nullptr) {
      first = nullptr;
    }
    else {
      last->next = nullptr;
    }
    delete victim;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear() {
    while(!empty()) {
      pop_front();
    }
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

  List() : first(nullptr), last(nullptr) {}

  ~List() {
    clear();
  }

  List(const List<T> &other) : first(nullptr), last(nullptr) {
    copy_all(other);
  }

  List &operator=(const List &other) {
    if (this == &other) {
      return *this;
    }
    else {
      clear();
      copy_all(other);
      return *this;
    }
  }
  

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other) {
    for (Node *ptr = other.first; ptr; ptr = ptr->next) {
      push_back(ptr->datum);
    }
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

    T& operator*() const {
      assert(node_ptr);
      return node_ptr->datum;
    }

    Iterator& operator++() {
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    bool operator==(Iterator rhs) const {
      return (node_ptr == rhs.node_ptr);
    }

    bool operator!=(Iterator rhs) const {
      return (node_ptr != rhs.node_ptr);
    }

    Iterator() : node_ptr(nullptr) { }

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    friend class List;

    // construct an Iterator at a specific position
    Iterator(Node *p) 
    : node_ptr(p) {}

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    return Iterator();
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i) {
    if (begin() == i) {
      pop_front();
    }
    /*
    else if (end() == i) {
      pop_back();
    } */
    else {
      i.node_ptr->next->prev = i.node_ptr->prev;
      i.node_ptr->prev->next = i.node_ptr->next;
      delete i.node_ptr;
      i.node_ptr = nullptr;
    }
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum) {
    if (begin() == i || empty()) {
      push_front(datum);
    }
    else if (i.node_ptr == nullptr) {
      push_back(datum);
    }
    else {
      Node *ptr = new Node;
      ptr->datum = datum;
      ptr->next = i.node_ptr;
      --i;
      ptr->prev = i.node_ptr;
      i.node_ptr->next = ptr;
      ++i;
      ++i;
      i.node_ptr->prev = ptr;
    }
  }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line u r gay
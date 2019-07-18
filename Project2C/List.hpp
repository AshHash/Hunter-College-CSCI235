//
//  List.hpp
//  List
//  A doubly-liked list implementation for Project2B
//  Project-specific member function scan(position) returns a sublist of increasingly-sorted items including the item at position
//
//  Created by Tiziana Ligorio on 10/21/18.
//  Copyright © 2018 Tiziana Ligorio. All rights reserved.
//

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include "Node.hpp"

template<class T>
class List
{

public:
    List(); // constructor
    List(const List<T>& a_list); // copy constructor
    ~List(); // destructor

    /**@return true if list is empty - item_count_ == 0 */
    bool isEmpty() const;

    /**@return the number of items in the list - item_count_ */
    size_t getLength() const;


    /**
     @param position indicating point of insertion
     @param new_element to be inserted in list
     @post new_element is added at position in list (before the node previously at that position)
     @return true always - it always inserts, if position > item_count_ it inserts at end of list */
    bool insert(size_t position, const T& new_element);

    /**
     @param position indicating point of deletion
     @post node at position is deleted, if any. List order is retains
     @return true if ther eis a node at position to be deleted, false otherwise */
    bool remove(size_t position);

    /**
     @pre assumes there is an item at position - NO ERROR HANDLING
     @param position of item to be retrieved
     @return the item at position in list if there is one, otherwise it returns a dummy UNITIALIZED object of type T -- temporary suboptimal solution in place of error handling to be discussed later in the course  */
    T getItem(size_t position) const;

    /**@post the list is empty and item_count_ == 0*/
    void clear();


    //*** PROJECT-SPECIFIC METHODS  ***//

    /**
     @pre assumes std::cout << is defined for objects of type T (can be sent to standard output) -- This method is not general, thus not appropriate for a templated class, it is provided for project debugging purposes
     @post traverses the list and prints (std::cout) every item in the list*/
    void traverse();



private:
    Node<T>* first_;      // Pointer to first node
    Node<T>* last_;       // Pointer to last node
    size_t item_count_;    // number of items in the list

    //if position > item_count_ returns nullptr
    Node<T>* getPointerTo(size_t position) const;

}; // end List

#include "List.cpp"
#endif // LIST_H_

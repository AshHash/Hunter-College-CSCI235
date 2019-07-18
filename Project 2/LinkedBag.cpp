/*
//  
//  Atta Saleh
//  EMPLID 14187529
//  3/1/19
//  Project 2A 
//
//  Definitions of functions for LinkedBag class
*/
//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Tiziana Ligorio 2019 for CSCI 235 Hunter College

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.hpp"
#include "Node.hpp"
#include <cstddef>

template<class T>
LinkedBag<T>::LinkedBag() : head_ptr_(nullptr), item_count_(0)
{
}  // end default constructor

template<class T>
LinkedBag<T>::LinkedBag(const LinkedBag<T>& a_bag)
{
	item_count_ = a_bag.item_count_;
   Node<T>* orig_chain_ptr = a_bag.head_ptr_;  // Points to nodes in original chain

   if (orig_chain_ptr == nullptr)
      head_ptr_ = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_ptr->getItem());

      // Copy remaining nodes
      Node<T>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
      orig_chain_ptr = orig_chain_ptr->getNext();     // Advance original-chain pointer

      while (orig_chain_ptr != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_ptr->getItem();

         // Create a new node containing the next item
         Node<T>* new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_ptr = orig_chain_ptr->getNext();
      }  // end while

      new_chain_ptr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class T>
LinkedBag<T>::~LinkedBag()
{
   clear();
}  // end destructor

template<class T>
bool LinkedBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty

template<class T>
int LinkedBag<T>::getCurrentSize() const
{
    return item_count_;
}  // end getCurrentSize

template<class T>
bool LinkedBag<T>::add(const T& new_entry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (head_ptr_ is null if chain is empty)
   Node<T>* next_node_ptr = new Node<T>();
   next_node_ptr->setItem(new_entry);
   next_node_ptr->setNext(head_ptr_);  // New node points to chain
//   Node<T>* next_node_ptr = new Node<T>(new_entry, head_ptr_); // alternate code

   head_ptr_ = next_node_ptr;          // New node is now first node
   item_count_++;

   return true;
}  // end add


template<class T>
std::vector<T> LinkedBag<T>::toVector() const
{
   std::vector<T> bag_contents;
   Node<T>* cur_ptr = head_ptr_;
	while ((cur_ptr != nullptr))
   {
		bag_contents.push_back(cur_ptr->getItem());
        cur_ptr = cur_ptr->getNext();
   }  // end while

   return bag_contents;
}  // end toVector

template<class T>
bool LinkedBag<T>::remove(const T& an_entry)
{
   Node<T>* entry_node_ptr = getPointerTo(an_entry);
   bool can_remove = !isEmpty() && (entry_node_ptr != nullptr);
   if (can_remove)
   {
      // Copy data from first node to located node
      entry_node_ptr->setItem(head_ptr_->getItem());

      // Delete first node
      Node<T>* node_to_delete = head_ptr_;
      head_ptr_ = head_ptr_->getNext();

      // Return node to the system
      node_to_delete->setNext(nullptr);
      delete node_to_delete;
      node_to_delete = nullptr;

      item_count_--;
   } // end if

	return can_remove;
}  // end remove


template<class T>
void LinkedBag<T>::clear()
{
   Node<T>* node_to_delete = head_ptr_;
   while (head_ptr_ != nullptr)
   {
      head_ptr_ = head_ptr_->getNext();

      // Return node to the system
      node_to_delete->setNext(nullptr);
      delete node_to_delete;

      node_to_delete = head_ptr_;
   }  // end while
   // head_ptr_ is nullptr; node_to_delete is nullptr

	item_count_ = 0;
}  // end clear


template<class T>
int LinkedBag<T>::getFrequencyOf(const T& an_entry) const
{
	int frequency = 0;
   int counter = 0;
   Node<T>* cur_ptr = head_ptr_;
   while ((cur_ptr != nullptr) && (counter < item_count_))
   {
      if (an_entry == cur_ptr->getItem())
      {
         frequency++;
      } // end if

      counter++;
      cur_ptr = cur_ptr->getNext();
   } // end while

	return frequency;
}  // end getFrequencyOf

template<class T>
bool LinkedBag<T>::contains(const T& an_entry) const
{
	return (getPointerTo(an_entry) != nullptr);
}  // end contains




// private


/**
 @return Returns either a pointer to the node containing a given entry
 or the null pointer if the entry is not in the bag.
 */
template<class T>
Node<T>* LinkedBag<T>::getPointerTo(const T& an_entry) const
{
    bool found = false;
    Node<T>* cur_ptr = head_ptr_;

    while (!found && (cur_ptr != nullptr))
    {
        if (an_entry == cur_ptr->getItem())
            found = true;
        else
            cur_ptr = cur_ptr->getNext();
    } // end while

    return cur_ptr;
} // end getPointerTo


/****************************************************/
/**
  Returns a LinkedBag that contains all elements in
  this bag (items_) and from a_bag. Can contain duplicates
*/
template<class T>
LinkedBag<T> LinkedBag<T>::bagUnion(const LinkedBag<T>& a_bag) const
{
  LinkedBag<T> newBag;  
  Node<T>* cur_ptr = head_ptr_; //points to first node of this bag

  //for this bag, go through each node until we reach a null pointer (empty node)
  while(cur_ptr != nullptr)
  {
    // Get next item from this bag
    T next_item = cur_ptr->getItem();

    // adds next item to the end of newBag
    newBag.add(next_item);

    // advance pointer to next node
    cur_ptr = cur_ptr->getNext();
  }
  cur_ptr = a_bag.head_ptr_;
  while(cur_ptr != nullptr)
  {
    // Get next item from a_bag
    T next_item = cur_ptr->getItem();

    // adds next item to the end of newBag
    newBag.add(next_item);

    // advance pointer to next node
    cur_ptr = cur_ptr->getNext();
  }
  return newBag;
} 
/**
  Returns a new LinkedBag that contains the intersection
  of the contents of this bag (items_) and a_bag. 
  Does not contain duplicates
*/
template<class T>
LinkedBag<T> LinkedBag<T>::bagIntersectionNoDuplicates(const LinkedBag<T>& a_bag) const
{
  LinkedBag<T> newBag;

  //pointer to first node of this bag
  Node<T>* cur_ptr = head_ptr_;    

  while(cur_ptr != nullptr)
  {
    //Get the current item in this bag
    T cur_item = cur_ptr->getItem(); 
    //If the item is in a_bag and not yet in newBag, add it to newBag
    if(a_bag.contains(cur_item) && !newBag.contains(cur_item))
      newBag.add(cur_item);
    //advance pointer to next node 
    cur_ptr = cur_ptr->getNext();
  }
  return newBag;
}
/**
  Returns a new LinkedBag that returns only items that occur in either
  items_ or a_bag but not both.
*/
template<class T>
LinkedBag<T> LinkedBag<T>::bagDifference(const LinkedBag<T>& a_bag) const
{
  LinkedBag<T> newBag;

  //pointer to first node of this bag
  Node<T>* cur_ptr = head_ptr_;    

  //adds one copy of each item in this bag to newBag
  while(cur_ptr != nullptr)
  {
    //Get the current item in this bag
    T cur_item = cur_ptr->getItem(); 
    //Adds one copy of each item in this bag to newBag
    if(!newBag.contains(cur_item))
      newBag.add(cur_item);
    //advance pointer to next node 
    cur_ptr = cur_ptr->getNext();
  }

  //creates a bag that contains the intersection of a_bag and newBag
  LinkedBag<T> intersectionBag = newBag.bagIntersectionNoDuplicates(a_bag);

  //points to head ptr of a_bag
  cur_ptr = a_bag.head_ptr_;
  int counter = 0;
  //adds one of each item in a_bag to newBag
  while(cur_ptr != nullptr && counter < a_bag.item_count_)
  {
    //Get the current item in a_bag
    T cur_item = cur_ptr->getItem(); 
    //Adds current item to newBag if it isn't already in newBag
    if(!newBag.contains(cur_item))
      newBag.add(cur_item);
    //advance pointer to next node 
    cur_ptr = cur_ptr->getNext();
    counter++;
  }

  //points to first node of intersection bag
  cur_ptr = intersectionBag.head_ptr_;

  //resets counter to 0;
  counter = 0;

  //removes all items in intersectionBag from newBag
  while(cur_ptr != nullptr  && counter < intersectionBag.item_count_)
  {
    //gets current item in intersectionBag
    T cur_item = cur_ptr->getItem();
    //if the item is in newBag, remove it
    while(newBag.contains(cur_item))
      newBag.remove(cur_item);
    //advance to next node
    cur_ptr = cur_ptr->getNext();
    counter++;
  }
  return newBag;
} 
/**
  Copies contents of parameter a_bag to the calling bag
*/
template<class T>
void LinkedBag<T>::operator= (const LinkedBag<T>& a_bag)
{
  clear();
  item_count_ = a_bag.item_count_;
  Node<T>* copy_ptr = a_bag.head_ptr_;  // Points to first node in bag to

   if (copy_ptr == nullptr)
      head_ptr_ = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(copy_ptr->getItem());

      // Copy remaining nodes
      Node<T>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
      copy_ptr = copy_ptr->getNext();     // Advance original-chain pointer

      while (copy_ptr != nullptr)
      {
         // Get next item from original chain
         T next_item = copy_ptr->getItem();

         // Create a new node containing the next item
         Node<T>* new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         copy_ptr = copy_ptr->getNext();
      }  // end while

      new_chain_ptr->setNext(nullptr);              // Flag end of chain
   }  // end if 
}
/**
  Adds new_entry to the end of a bag, returns true if succesful, false if not.
*/
template<class T>
bool LinkedBag<T>::addToEnd(const T& new_entry)
{
  Node<T>* end_node_ptr = new Node<T>();
  end_node_ptr->setItem(new_entry);
  Node<T>* cur_ptr = head_ptr_;
  Node<T>* prev_ptr = nullptr;
  while(cur_ptr != nullptr)
  {
    prev_ptr = cur_ptr;
    cur_ptr = cur_ptr->getNext();
  }
  prev_ptr->setNext(end_node_ptr);
  item_count_++;
  return true;
}




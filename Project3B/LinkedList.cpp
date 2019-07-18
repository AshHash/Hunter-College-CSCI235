//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  Modified by Tiziana Ligorio for Hunter College CSCI 235
//  Removed Exception Handling becuse not yet covered and
// Student will add project-specific methods

/** ADT list: Singly linked list implementation.

 Implementation file for the class LinkedList.
 @file LinkedList.cpp */

 /*
 Atta Saleh
 EMPLID 14187529
 Project 3B
*/

#include "LinkedList.hpp"  // Header file
#include <cassert>

template<class T>
LinkedList<T>::LinkedList() : head_ptr_(nullptr), item_count_(0)
{
}  // end default constructor

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& a_list) : item_count_(a_list.item_count_)
{
   Node<T>* orig_chain_pointer = a_list.head_ptr_;  // Points to nodes in original chain

   if (orig_chain_pointer == nullptr)
      head_ptr_ = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_pointer->getItem());

      // Copy remaining nodes
      Node<T>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
      orig_chain_pointer = orig_chain_pointer->getNext();     // Advance original-chain pointer
      while (orig_chain_pointer != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_pointer->getItem();

         // Create a new node containing the next item
         Node<T>* new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_pointer = orig_chain_pointer->getNext();
      }  // end while

      new_chain_ptr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class T>
LinkedList<T>::~LinkedList()
{
   clear();
}  // end destructor

template<class T>
bool LinkedList<T>::isEmpty() const
{
   return item_count_ == 0;
}  // end isEmpty

template<class T>
int LinkedList<T>::getLength() const
{
   return item_count_;
}  // end getLength

template<class T>
bool LinkedList<T>::insert(int new_position, const T& new_entry)
{
   bool able_to_insert = (new_position >= 1) && (new_position <= item_count_ + 1);
   if (able_to_insert)
   {
      // Create a new node containing the new entry
      Node<T>* new_node_ptr = new Node<T>(new_entry);

      // Attach new node to chain
      if (new_position == 1)
      {
         // Insert new node at beginning of chain
         new_node_ptr->setNext(head_ptr_);
         head_ptr_ = new_node_ptr;
      }
      else
      {
         // Find node that will be before new node
         Node<T>* prev_ptr = getNodeAt(new_position - 1);

         // Insert new node after node to which prev_ptr points
         new_node_ptr->setNext(prev_ptr->getNext());
         prev_ptr->setNext(new_node_ptr);
      }  // end if

      item_count_++;  // Increase count of entries
   }  // end if

   return able_to_insert;
}  // end insert

template<class T>
bool LinkedList<T>::remove(int position)
{
   bool able_to_remove = (position >= 1) && (position <= item_count_);
   if (able_to_remove)
   {
      Node<T>* cur_ptr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         cur_ptr = head_ptr_; // Save pointer to node
         head_ptr_ = head_ptr_->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<T>* prev_ptr = getNodeAt(position - 1);

         // Point to node to delete
         cur_ptr = prev_ptr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prev_ptr->setNext(cur_ptr->getNext());
      }  // end if

      // Return node to system
      cur_ptr->setNext(nullptr);
      delete cur_ptr;
      cur_ptr = nullptr;

      item_count_--;  // Decrease count of entries
   }  // end if

   return able_to_remove;
}  // end remove

template<class T>
void LinkedList<T>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class T>
T LinkedList<T>::getEntry(int position) const
{
    T dummy;
   // Check precondition
   bool able_to_get = (position >= 1) && (position <= item_count_);
   if (able_to_get)
   {
      Node<T>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
    else
        return dummy; //PROBLEM!!!! may return uninitialized object - will fix later with Exception Handling

}  // end getEntry



/************* PROJECT-SPECIFIC PUBLIC METHODS ************/

// Wrapper to a recursive method that inverts the contents of the list
// the contents are inverted such that the item previously at pos 1 is at
// item_count_, pos 2 at item_count_ -1 and so on.
template<class T>
void LinkedList<T>::invert()
{
   if(item_count_ > 0)
   {
      invertRest(head_ptr_);
      getNodeAt(item_count_)->setNext(nullptr);
   }
}

// A wrapper to a recursive selection sort method that sorts the list in increasing order
// @post the contents of the list are sorted in increasing order such that
// the item at position 1 <= the item at at position 2 <= ...
// <= item at position item_count_-1
template<class T>
void LinkedList<T>::selectionSort()
{
   if(item_count_ > 0)
   {
      head_ptr_ = recursiveSelectionSort(head_ptr_);
   }
}







/************* PRIVATE ************/



template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert((position >= 1) && (position <= item_count_));

   // Count from the beginning of the chain
   Node<T>* cur_ptr = head_ptr_;
   for (int skip = 1; skip < position; skip++)
      cur_ptr = cur_ptr->getNext();

   return cur_ptr;
}  // end getNodeAt

//helper function to get minimum node ptr
template<class T>
Node<T>* LinkedList<T>::getMinimum(Node<T>* starting_ptr) const
{
   Node<T>* minimum_ptr = starting_ptr;
   while(starting_ptr->getNext() != nullptr)
   {
      if(starting_ptr->getNext()->getItem() < minimum_ptr->getItem())
      {
         minimum_ptr = starting_ptr->getNext();
      }
      starting_ptr = starting_ptr->getNext();
   }
   return minimum_ptr;
}

//helper function that gets pointer before the minimum
template<class T>
Node<T>* LinkedList<T>::getPrevMinimum(Node<T>* starting_ptr) const
{
   Node<T>* minimum_ptr = starting_ptr;
   Node<T>* output_ptr = starting_ptr;
   while(starting_ptr->getNext() != nullptr)
   {
      if(starting_ptr->getNext()->getItem() < minimum_ptr->getItem())
      {
         minimum_ptr = starting_ptr->getNext();
         output_ptr = starting_ptr;
      }
      starting_ptr = starting_ptr->getNext();
   }
   return output_ptr;
}



       /***************** PROJECT-SPECIFIC PRIVATE METHODS ****************/

//Private function to invert, used for safe programming to avoid
//exposing pointers to list in public methods.
template<class T>
void LinkedList<T>::invertRest(Node<T>* current_first_ptr)
{

   //makes the last node the first in the list
   if(current_first_ptr->getNext() == nullptr)
   {
      //Does nothing if there are no items.
      if(item_count_ != 0)
         head_ptr_ = current_first_ptr;
   }

   //recursively calls itself until it reaches the last node
   else
   {
      invertRest(current_first_ptr->getNext());
   }


   //recursively sets the "next" to the current node if the current node isn't the new first item. 
   if(current_first_ptr != head_ptr_)
   {
   current_first_ptr->getNext()->setNext(current_first_ptr);
   }
   
}


//recursive selection sort, used for safe programming to avoid
//exposing pointers to list in public methods
//To sort the list, it relies on re-linking the chain rather than copying data items
// @post the contents of the list are sorted in increasing order such that
// the item at position 1 <= the item at at position 2 <= ...
// <= item at position item_count_-1

template<class T>
Node<T>* LinkedList<T>::recursiveSelectionSort(Node<T>* current_first_ptr)
{

   //nodes of the minimum value and the one that points to it
   Node<T>* minimum_ptr = getMinimum(current_first_ptr);
   Node<T>* prev_minimum = getPrevMinimum(current_first_ptr);

   //if the current_first_ptr is the last item, return it.
   if(current_first_ptr->getNext() == nullptr)
   {
      return current_first_ptr;
   }
   //if the current_first_ptr is the minimum, make another recursive call on the next item.
   else if(current_first_ptr == minimum_ptr)
   {
      current_first_ptr->setNext(recursiveSelectionSort(current_first_ptr->getNext()));
      return current_first_ptr;
   }
   //if the current_first_ptr isn't the minimum or the last item, finds the minimum and moves it to current_first_ptr's position
   else
   {

      //placeholders for reconnecting the linked list
      Node<T>* new_next_for_first = nullptr;
      Node<T>* new_next_for_min = nullptr;

      //holding place while we reconnect the chain
      if(current_first_ptr->getNext() != minimum_ptr)
      {
         new_next_for_min = current_first_ptr->getNext();
         new_next_for_first = minimum_ptr->getNext();
         //moves current_first_ptr to the position of minimum_ptr
         prev_minimum->setNext(current_first_ptr);
         current_first_ptr->setNext(new_next_for_first);
         //moves minimum_ptr to where current_first_ptr was
         minimum_ptr->setNext(recursiveSelectionSort(new_next_for_min));
         return minimum_ptr;
      }
      else
      {
         current_first_ptr -> setNext(minimum_ptr->getNext());
         minimum_ptr -> setNext(recursiveSelectioNSort(current_first_ptr);
         return minimum_ptr;
      }
      new_next_for_min = nullptr;
      new_next_for_first = nullptr;

      
   }
} 


//  End of implementation file.
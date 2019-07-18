/*
// 
// Atta Saleh
// EMPLID 14187529
// 2/22/19
// Project 1C  
//
// ArrayBag.cpp
*/
//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//  Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.hpp"
#include <cstddef>

/** default constructor**/
template<class T>
ArrayBag<T>::ArrayBag(): item_count_(0)
{
}  // end default constructor


/**
 @return item_count_ : the current size of the bag
 **/
template<class T>
int ArrayBag<T>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize


/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class T>
bool ArrayBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty


/**
 @return true if new_etry was successfully added to items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::add(const T& new_entry)
{
	bool has_room = (item_count_ < DEFAULT_CAPACITY);
	if (has_room)
	{
		items_[item_count_] = new_entry;
		item_count_++;
	}  // end if
    
	return has_room;
}  // end add


/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::remove(const T& an_entry)
{
   int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if
    
	return can_remove;
}  // end remove


/**
 @post item_count_ == 0
 **/
template<class T>
void ArrayBag<T>::clear()
{
	item_count_ = 0;
}  // end clear


/**
 @return the number of times an_entry is found in items_
 **/
template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if
      
      cun_index++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains


/**
 @return a vector having the same cotntents as items_
 **/
template<class T>
std::vector<T> ArrayBag<T>::toVector() const
{
   std::vector<T> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);
      
   return bag_contents;
}  // end toVector


 
// PRIVATE

/**
 @param target to be found in items_
 @return either the index target in the array items_ or -1,
 if the array does not containthe target.
 **/
template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const
{
	bool found = false;
   int result = -1;
   int search_index = 0;
   
   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {
      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      } 
      else
      {
         search_index++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

/****************************************************************/
/**
@param a_bag to be combined with the contents of this bag
@return a new ArrayBag that contains all elements from this bag (items_)
and as many elements from the argument a_bag as space requires. Note
that it may contain duplicates
*/
template<class T>
ArrayBag<T> ArrayBag<T>::bagUnion(const ArrayBag<T>& a_bag) const
{
   ArrayBag<T> newBag;

   for(int i = 0; i < item_count_; i++)
   {
      newBag.add(items_[i]);
   }
   for(int j = 0; j < a_bag.item_count_; j++)
   {
      newBag.add(a_bag.items_[j]);
   }
   return newBag;
} 
/**
@param a_bag to be intersected with the contents of this bag (items_)
@return a new ArrayBag that contains the intersection of the contents
of this bag and those of the argument a_bag. This intersection does
not contain duplicates (e.g. every element occurring in BOTH bags will
be found only once in the intersection, no matter how many
occurrences in the original bags) as in set intersection A ∩ B
*/
template<class T>
ArrayBag<T> ArrayBag<T>::bagIntersectionNoDuplicates(const ArrayBag<T>& a_bag) const
{
   ArrayBag<T> newBag;

   for(int i = 0; i < item_count_; i++)
   {
      //if the item is in a_bag and items_, and not yet in newBag, add it to newBag
      if(a_bag.getFrequencyOf(items_[i])> 0 && newBag.getFrequencyOf(items_[i])==0)
         newBag.add(items_[i]);
   }
   return newBag;
}
/**
@param a_bag to be subtracted from this bag
@return a new ArrayBag that contains only those items that occur in this
bag or in a_bag but not in both, and it does not contain duplicates
*/
template<class T>
ArrayBag<T> ArrayBag<T>::bagDifference(const ArrayBag<T>& a_bag) const
{
   ArrayBag<T> newBag;

   ArrayBag<T> intersectionBag;
   
   for(int i = 0; i < item_count_; i++)
   {
      //adds one copy of each item in items_ 
      if(newBag.getFrequencyOf(items_[i])==0)
         newBag.add(items_[i]);
   }

   //add bag that is intersection of newBag (with one of each item in items_)
   intersectionBag = newBag.bagIntersectionNoDuplicates(a_bag);

   
   for(int i = 0; i < a_bag.item_count_; i++)
   {
      //adds one copy of each item in a_bag
      if(newBag.getFrequencyOf(a_bag.items_[i])==0)
         newBag.add(a_bag.items_[i]);
   }

   for(int i = 0; i < newBag.item_count_; i++)
   {
      if(intersectionBag.getFrequencyOf(newBag.items_[i])>0)
         newBag.remove(newBag.items_[i]);
   }
   return newBag;
}

/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	2/22/19
//	Project 1C	
//
//	BagTest.hpp 
*/

#ifndef BagTest_hpp
#define BagTest_hpp

#include <string>
#include <fstream>
#include <iostream>
#include "CourseMember.hpp"
#include "ArrayBag.hpp"

class BagTest: public CourseMember
{

public:

/**
 @pre the input file is in csv format as follows:
 “id,first_name,last_name,title\n”
 @post this function asks the user for an input file name.
 It extracts the information necessary to create a CourseMember object
 from each line in the input file, and it adds the corresponding
 CourseMember object to bag_.
 @return returns the populated bag_
**/
ArrayBag<CourseMember> testCourseMemberBag();

/**
 @post prints to the standard output all CourseMe,ber
 objects found in bag_, one per line in the format:
 id first_name last_name
**/
void displayCourseMemberBag(const ArrayBag<CourseMember>& a_bag); 

private:

	ArrayBag<CourseMember> bag_;
	//creates an ArrayBag item of type CourseMember from string input
	ArrayBag<CourseMember> createBagFromInput(std::string input_file); 
};

#endif

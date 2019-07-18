/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	2/22/19
//	Project 1C	
//
//	BagTest.cpp 
*/

#include "BagTest.hpp"
#include <sstream>

/**
 @pre the input file is in csv format as follows:
 “id,first_name,last_name,title\n”
 @post this function asks the user for an input file name.
 It extracts the information necessary to create a CourseMember object
 from each line in the input file, and it adds the corresponding
 CourseMember object to bag_.
 @return returns the populated bag_
**/
ArrayBag<CourseMember> BagTest::testCourseMemberBag()
{
	std::string fileName;
	std::cout << "Input file name: ";
	std::cin >> fileName;
	bag_ = createBagFromInput(fileName);
	return bag_;
}

/**
 @post prints to the standard output all CourseMember
 objects found in bag_, one per line in the format:
 id first_name last_name
**/
void BagTest::displayCourseMemberBag(const ArrayBag<CourseMember>& a_bag)
{
	for(int i = 0; i < a_bag.getCurrentSize(); i++)
	{
		std::vector<CourseMember> courseVector = a_bag.toVector();
		std::cout << courseVector[i].getID() << " ";
		std::cout << courseVector[i].getFirstName() << " ";
		std::cout << courseVector[i].getLastName() << std::endl;
	}
} 

ArrayBag<CourseMember> BagTest::createBagFromInput(std::string input_file)
{
	std::ifstream input;
	input.open(input_file.c_str());
	std::string junk; 						//placeholder for roles in class which aren't needed
	std::string first_name_, last_name_; 	//placeholder for first and last names
	std::string holdInt; 					//Holds string int to be converted to int;
	int id;
	while(!input.eof())
	{
		getline (input,holdInt,',');
		std::stringstream convert(holdInt);
		if (!(convert >> id))
		{
			id = 0;
		}
		getline (input,first_name_,',');
		getline (input,last_name_,',');
		getline (input,junk);
		CourseMember temp(id,first_name_,last_name_);
		bag_.add(temp);
	}
	input.close();
	return bag_;
}



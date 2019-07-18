/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	3/15/19
//	Project 2C	
//
//	Student.hpp 
*/

#ifndef Student_hpp
#define Student_hpp

#include "CourseMember.hpp"
#include <iostream>
#include <string>


class Student: public CourseMember
{
public:
 
	//Parameterized constructor
 	Student(int id, std::string first, std::string last);
 	
 	//returns Student major_
 	std::string getMajor() const;
 	
 	//returns Student gpa_
 	double getGpa() const;
 	
 	//Sets major_
 	void setMajor(const std::string major);
	
	//Sets gpa_
	void setGpa(const double gpa);

	virtual void displayMember() const override;

protected:

	//Protected variables defined
	std::string major_;

	double gpa_;
}; 

#endif
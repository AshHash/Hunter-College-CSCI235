/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	3/15/19
//	Project 2C	
//
//	TeachingAssistant.hpp 
*/

#ifndef TeachingAssistant_hpp
#define TeachingAssistant_hpp

#include "Student.hpp"
#include <string>
#include <iostream>

enum ta_role {LAB_ASSISTANT, LECTURE_ASSISTANT, FULL_ASSISTANT};

class TeachingAssistant: public Student
{
public:
	
	//Parameterized constructor for TeachingAssistant class
	TeachingAssistant(int id, std::string first, std::string last);

	//Gets hours_per_week
 	int getHours() const;

 	//gets role_ enum
 	ta_role getRole() const;

 	//Sets hours_per_week
 	void setHours(const int hours);

 	//Sets role, defaults to LAB_ASSISTANT
 	void setRole(const ta_role role); 

 	virtual void displayMember() const override;

private:

	//Protected variables defined
	int hours_per_week;

	ta_role role_;
}; 
#endif
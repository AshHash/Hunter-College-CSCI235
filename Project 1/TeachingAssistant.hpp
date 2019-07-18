/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	2/15/19
//	Project 1B	
//
//	TeachingAssistant.hpp 
*/
#include "Student.hpp"
#include <string>

enum ta_role {LAB_ASSISTANT, LECTURE_ASSISTANT, BOTH};

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

private:

	//Protected variables defined
	int hours_per_week;

	ta_role role_;
}; 

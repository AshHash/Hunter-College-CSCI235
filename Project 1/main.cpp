//testing 

#include <iostream>
#include "BagTest.hpp"

int main()
{
	ArrayBag<CourseMember> Roster;
	BagTest Bag;
    Roster = Bag.testCourseMemberBag();
    Bag.displayCourseMemberBag(Roster);
    ArrayBag<CourseMember> test;
    test = Bag.testCourseMemberBag();
    ArrayBag<CourseMember> output;
    output = test.bagUnion(Roster); 

    Bag.displayCourseMemberBag(output);
	return 0;
}
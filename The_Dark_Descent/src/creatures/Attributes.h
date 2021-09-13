#pragma once
#include <iostream>

// class should be singular?!
struct Attributes
{
	int myStrength;
	int myDexterity;
	int myVitality;
	int myMagic;

//friend std::ostream& operator<<(std::ostream& out, const Attributes& a);
};


//std::ostream& operator<<(std::ostream& out, const Attributes& a)
//{
//	out << "[Attributes]"
//		"\tStrength"  << a.myStrength  << 
//		"\tDexterity" << a.myDexterity <<
//		"\tVitality"  << a.myVitality  <<
//		"\tMagic: "   << a.myMagic;
//	return out;
//}
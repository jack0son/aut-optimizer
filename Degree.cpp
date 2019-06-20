#include "Degree.h"

using namespace std;

Degree::Degree()
{
	//
}

Degree::Degree(string name, vector<Course> courses)
{
	setName(name);
	setCourses(courses);
}

Degree::~Degree()
{
	//
}

string Degree::getName() const
{
	return name;
}

int Degree::setName(string name)
{
	Degree::name = name;

	return 1;
}

vector<Course> Degree::getCourses() const
{
	return courses;
}

int Degree::setCourses(vector<Course> courses)
{
	Degree::courses = courses;

	return 1;
}
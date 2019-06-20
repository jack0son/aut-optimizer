#include "Course.h"

using namespace std;

Course::Course()
{
	//
}

Course::Course(string name, vector<Lesson> lectures, vector<Lesson> practicals, vector<Lesson> seminars, vector<Lesson> tutorials, vector<Lesson> workshops)
{
	setName(name);
	setLectures(lectures);
	setPracticals(practicals);
	setSeminars(seminars);
	setTutorials(tutorials);
	setWorkshops(workshops);
}

Course::~Course()
{
	//
}

string Course::getName() const
{
	return name;
}

int Course::setName(string name)
{
	Course::name = name;
	
	return 1;
}

vector<Lesson> Course::getLectures() const
{
	return lectures;
}

int Course::setLectures(vector<Lesson> lectures)
{
	Course::lectures = lectures;

	return 1;
}

vector<Lesson> Course::getPracticals() const
{
	return practicals;
}

int Course::setPracticals(vector<Lesson> practicals)
{
	Course::practicals = practicals;

	return 1;
}

vector<Lesson> Course::getSeminars() const
{
	return seminars;
}

int Course::setSeminars(vector<Lesson> seminars)
{
	Course::seminars = seminars;

	return 1;
}

vector<Lesson> Course::getTutorials() const
{
	return tutorials;
}

int Course::setTutorials(vector<Lesson> tutorials)
{
	Course::tutorials = tutorials;

	return 1;
}

vector<Lesson> Course::getWorkshops() const
{
	return workshops;
}

int Course::setWorkshops(vector<Lesson> workshops)
{
	Course::workshops = workshops;

	return 1;
}
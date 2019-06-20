#include "Lesson.h"
#include <vector>
#include "Timeslot.h"

using namespace std;

Lesson::Lesson()
{
	//
}

Lesson::Lesson(vector<Timeslot> timeslots)
{
	setTimeslots(timeslots);
}

Lesson::~Lesson()
{
	//
}

vector<Timeslot> Lesson::getTimeslots() const
{
	return timeslots;
}

int Lesson::setTimeslots(vector<Timeslot> timeslots)
{
	Lesson::timeslots = timeslots;

	return 1;
}
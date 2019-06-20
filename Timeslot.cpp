#include "Timeslot.h"
#include <string>
#include "WeekDay.h"

using namespace std;

Timeslot::Timeslot()
{
	//
}

Timeslot::Timeslot(string location, WeekDay day, int startTime, int endTime)
{
	setLocation(location);
	setDay(day);
	setStartTime(startTime);
	setEndTime(endTime);
}

Timeslot::~Timeslot()
{
	//
}

string Timeslot::getLocation() const
{
	return location;
}

int Timeslot::setLocation(string location)
{
	Timeslot::location = location;

	return 1;
}

WeekDay Timeslot::getDay() const
{
	return day;
}

int Timeslot::setDay(WeekDay day)
{
	Timeslot::day = day;

	return 1;
}

int Timeslot::getStartTime() const
{
	return startTime;
}

int Timeslot::setStartTime(int startTime)
{
	if ((startTime >= 0) && (startTime <= 2400))
	{
		Timeslot::startTime = startTime;

		return 1;
	}
	else if ((startTime < 0) || (startTime > 2400))
	{
		return 0;
	}
}

int Timeslot::getEndTime() const
{
	return endTime;
}

int Timeslot::setEndTime(int endTime)
{
	if ((endTime >= 0) && (endTime <= 2400))
	{
		Timeslot::endTime = endTime;

		return 1;
	}
	else if ((startTime < 0) || (startTime > 2400))
	{
		return 0;
	}
}
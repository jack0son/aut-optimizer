#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <string>
#include "WeekDay.h"

class Timeslot
{
	public:
		Timeslot();
		Timeslot(std::string location, WeekDay day, int startTime, int endTime);
		~Timeslot();

		std::string getLocation() const;
		int setLocation(std::string location);

		WeekDay getDay() const;
		int setDay(WeekDay day);

		int getStartTime() const;
		int setStartTime(int startTime);

		int getEndTime() const;
		int setEndTime(int endTime);

	private:
		std::string location;
		WeekDay day;
		int startTime;
		int endTime;
};

#endif
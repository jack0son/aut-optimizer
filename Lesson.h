#ifndef LESSON_H
#define LESSON_H

#include <vector>
#include "Timeslot.h"

class Lesson
{
	public:
		Lesson();
		Lesson(std::vector<Timeslot> timeslots);
		~Lesson();

		std::vector<Timeslot> getTimeslots() const;
		int setTimeslots(std::vector<Timeslot> timeslots);

	private:
		std::vector<Timeslot> timeslots;
};

#endif
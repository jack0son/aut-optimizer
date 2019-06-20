#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Lesson.h"

class Course
{
	public:
		Course();
		Course(std::string name, std::vector<Lesson> lectures, std::vector<Lesson> practicals, std::vector<Lesson> seminars, std::vector<Lesson> tutorials, std::vector<Lesson> workshops);
		~Course();

		std::string getName() const;
		int setName(std::string name);

		std::vector<Lesson> getLectures() const;
		int setLectures(std::vector<Lesson> lectures);

		std::vector<Lesson> getPracticals() const;
		int setPracticals(std::vector<Lesson> practicals);

		std::vector<Lesson> getSeminars() const;
		int setSeminars(std::vector<Lesson> seminars);

		std::vector<Lesson> getTutorials() const;
		int setTutorials(std::vector<Lesson> tutorials);

		std::vector<Lesson> getWorkshops() const;
		int setWorkshops(std::vector<Lesson> workshops);

	private:
		std::string name;
		std::vector<Lesson> lectures;
		std::vector<Lesson> practicals;
		std::vector<Lesson> seminars;
		std::vector<Lesson> tutorials;
		std::vector<Lesson> workshops;
};

#endif
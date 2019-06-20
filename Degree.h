#ifndef DEGREE_H
#define DEGREE_H

#include <string>
#include <vector>
#include "Course.h"

class Degree
{
	public:
		Degree();
		Degree(std::string name, std::vector<Course> courses);
		~Degree();

		std::string getName() const;
		int setName(std::string name);

		std::vector<Course> getCourses() const;
		int setCourses(std::vector<Course> courses);

	private:
		std::string name;
		std::vector<Course> courses;
};

#endif
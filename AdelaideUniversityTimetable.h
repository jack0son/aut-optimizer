#ifndef AUT_H
#define AUT_H

#include "Timetable.h"
#include <vector>
#include "Degree.h"
#include "Course.h"
#include <string>

const Timetable initDefaultTimetable();
std::vector<Timetable> createTimetables(std::vector<Degree> degrees);
Course pullCourse(std::string subjectAreaA, std::string catalogueNumberA, std::string semesterA, std::string campusA);

#endif
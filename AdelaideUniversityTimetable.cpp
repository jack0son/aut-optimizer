#include "AdelaideUniversityTimetable.h"
#include "Timetable.h"
#include <string>
#include <iostream>
#include "Utilities.h"
#include "Course.h"
#include <vector>
#include "Degree.h"
#include <fstream>
#include <iomanip>
#include "Timeslot.h"
#include "Lesson.h"
#include <cmath>
#include <ctime>
#include <sstream>
#include "Menu.h"

using namespace std;

const Timetable defaultTimetable = initDefaultTimetable();

void doAlltheThings()
{
	string subjectArea;
	string catalogueNumber;
	string semester;
	string campus;

	cout << "Please enter the subject area of your course, e.g. COMP SCI: ";
	getline(cin, subjectArea);
	replace(subjectArea, " ", "+");
	cout << "Please enter the catalogue number of your course, e.g. 1102: ";
	getline(cin, catalogueNumber);
	cout << "Please enter the semester that your course is in, e.g. Semester 1: ";
	getline(cin, semester);
	cout << "Please enter the campus that your course is on, e.g. North Terrace: ";
	getline(cin, campus);
	cout << endl;

	Course course = pullCourse(subjectArea, catalogueNumber, semester, campus);

	vector<Course> tempCourses;
	vector<Degree> tempDegrees;

	Degree degree;
	degree.setName("Degree");
	tempCourses.push_back(course);
	degree.setCourses(tempCourses);
	tempCourses.clear();

	tempDegrees.push_back(degree);
	
	vector<Timetable> timetables = createTimetables(tempDegrees);

	tempDegrees.clear();

	/* WRITE THE POSSIBLE TIMETABLES */
	ofstream out("output.txt");
	for (int i = 0; i < timetables.size(); i++)
	{
		if (timetables[i].timeslots[0][0].getLocation() != "false")
		{
			out << setw(28) << "" << setw(28) << "MONDAY" << setw(28) << "TUESDAY" << setw(28) << "WEDNESDAY" << setw(28) << "THURSDAY" << setw(28) << "FRIDAY" << setw(28) << endl;
			out << setw(28) << "0900 - 1000" << setw(28) << newLeft(timetables[i].timeslots[0][0].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][0].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][0].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][0].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][0].getLocation(), 27, 24) << setw(28) << endl;
			out << setw(28) << "1000 - 1100" << setw(28) << newLeft(timetables[i].timeslots[0][1].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][1].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][1].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][1].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][1].getLocation(), 27, 24) << setw(28) << endl;
			out << setw(28) << "1100 - 1200" << setw(28) << newLeft(timetables[i].timeslots[0][2].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][2].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][2].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][2].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][2].getLocation(), 27, 24) << setw(28) << endl;
			out << setw(28) << "1200 - 1300" << setw(28) << newLeft(timetables[i].timeslots[0][3].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][3].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][3].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][3].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][3].getLocation(), 27, 24) << setw(28) << endl;
			out << setw(28) << "1300 - 1400" << setw(28) << newLeft(timetables[i].timeslots[0][4].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][4].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][4].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][4].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][4].getLocation(), 27, 24) << setw(28) << endl;
			out << setw(28) << "1400 - 1500" << setw(28) << newLeft(timetables[i].timeslots[0][5].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][5].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][5].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][5].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][5].getLocation(), 27, 24) << setw(28) << endl;
			out << setw(28) << "1500 - 1600" << setw(28) << newLeft(timetables[i].timeslots[0][6].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][6].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][6].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][6].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][6].getLocation(), 27, 24) << setw(28) << endl;
			out << setw(28) << "1600 - 1700" << setw(28) << newLeft(timetables[i].timeslots[0][7].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][7].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][7].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][7].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][7].getLocation(), 27, 24) << setw(28) << endl;
			out << setw(28) << "1700 - 1800" << setw(28) << newLeft(timetables[i].timeslots[0][8].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[1][8].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[2][8].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[3][8].getLocation(), 27, 24) << setw(28) << newLeft(timetables[i].timeslots[4][8].getLocation(), 27, 24) << setw(28);
			(i == (timetables.size() - 1)) ? out << "" : out << endl;
		}
	}
	out.close();
	
	cout << endl;
}

int main(int argc, char* argv[])
{
	Menu mainMenu("Main menu: ");
	mainMenu.addItem("Make timetables", &doAlltheThings);
	mainMenu.useMenu();

	// Windows only
	system("pause");

	return 0;
}

const Timetable initDefaultTimetable()
{
	Timetable defaultTimetable;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			defaultTimetable.timeslots[i][j] = Timeslot("", (WeekDay)(i), j + 9, j + 10);
		}
	}

	return defaultTimetable;
}

vector<Timetable> createTimetables(vector<Degree> degrees)
{
	int totalPossibleTimetables = 1;
	for (int i = 0; i < degrees.size(); i++)
	{
		for (int j = 0; j < degrees[i].getCourses().size(); j++)
		{
			totalPossibleTimetables *= (degrees[i].getCourses()[j].getLectures().size() != 0) ? degrees[i].getCourses()[j].getLectures().size() : 1;
			totalPossibleTimetables *= (degrees[i].getCourses()[j].getPracticals().size() != 0) ? degrees[i].getCourses()[j].getPracticals().size() : 1;
			totalPossibleTimetables *= (degrees[i].getCourses()[j].getSeminars().size() != 0) ? degrees[i].getCourses()[j].getSeminars().size() : 1;
			totalPossibleTimetables *= (degrees[i].getCourses()[j].getTutorials().size() != 0) ? degrees[i].getCourses()[j].getTutorials().size() : 1;
			totalPossibleTimetables *= (degrees[i].getCourses()[j].getWorkshops().size() != 0) ? degrees[i].getCourses()[j].getWorkshops().size() : 1;
		}
	}

	vector<Timetable> timetables(totalPossibleTimetables, defaultTimetable);

	vector<Course> tempCourses;
	vector<Lesson> tempLessons;
	int tempInt;
	bool invalidTimetable = false;
	vector<Timeslot> tempTimeslots;
	Timeslot* tempTimeslot;
	string tempString;
	int validTimetables = 0;
	for (int i = 0; i < timetables.size(); i++)
	{
		for (int j = 0; j < degrees.size(); j++)
		{
			tempCourses = degrees[j].getCourses();
			for (int k = 0; k < tempCourses.size(); k++)
			{
				tempLessons = tempCourses[k].getLectures();
				tempInt = tempLessons.size();
				if ((tempInt != 0) && !invalidTimetable)
				{
					tempTimeslots = tempLessons[i % tempInt].getTimeslots();
					for (int l = 0; l < tempTimeslots.size(); l++)
					{
						tempTimeslot = &(timetables[i].timeslots[tempTimeslots[l].getDay()][(tempTimeslots[l].getStartTime() / 100) - 9]);
						tempString = tempTimeslot->getLocation();
						if (tempString == "")
						{
							*tempTimeslot = tempTimeslots[l];
						}
						else if (tempString != "")
						{
							invalidTimetable = true;
							break;
						}
					}
				}

				if (invalidTimetable)
				{
					break;
				}
				
				tempLessons = tempCourses[k].getPracticals();
				tempInt = tempLessons.size();
				if ((tempInt != 0) && !invalidTimetable)
				{
					tempTimeslots = tempLessons[i % tempInt].getTimeslots();
					for (int l = 0; l < tempTimeslots.size(); l++)
					{
						tempTimeslot = &(timetables[i].timeslots[tempTimeslots[l].getDay()][(tempTimeslots[l].getStartTime() / 100) - 9]);
						tempString = tempTimeslot->getLocation();
						if (tempString == "")
						{
							*tempTimeslot = tempTimeslots[l];
						}
						else if (tempString != "")
						{
							invalidTimetable = true;
							break;
						}
					}
				}

				if (invalidTimetable)
				{
					break;
				}

				tempLessons = tempCourses[k].getSeminars();
				tempInt = tempLessons.size();
				if ((tempInt != 0) && !invalidTimetable)
				{
					tempTimeslots = tempLessons[i % tempInt].getTimeslots();
					for (int l = 0; l < tempTimeslots.size(); l++)
					{
						tempTimeslot = &(timetables[i].timeslots[tempTimeslots[l].getDay()][(tempTimeslots[l].getStartTime() / 100) - 9]);
						tempString = tempTimeslot->getLocation();
						if (tempString == "")
						{
							*tempTimeslot = tempTimeslots[l];
						}
						else if (tempString != "")
						{
							invalidTimetable = true;
							break;
						}
					}
				}

				if (invalidTimetable)
				{
					break;
				}

				tempLessons = tempCourses[k].getTutorials();
				tempInt = tempLessons.size();
				if ((tempInt != 0) && !invalidTimetable)
				{
					tempTimeslots = tempLessons[i % tempInt].getTimeslots();
					for (int l = 0; l < tempTimeslots.size(); l++)
					{
						tempTimeslot = &(timetables[i].timeslots[tempTimeslots[l].getDay()][(tempTimeslots[l].getStartTime() / 100) - 9]);
						tempString = tempTimeslot->getLocation();
						if (tempString == "")
						{
							*tempTimeslot = tempTimeslots[l];
						}
						else if (tempString != "")
						{
							invalidTimetable = true;
							break;
						}
					}
				}

				if (invalidTimetable)
				{
					break;
				}

				tempLessons = tempCourses[k].getWorkshops();
				tempInt = tempLessons.size();
				if ((tempInt != 0) && !invalidTimetable)
				{
					tempTimeslots = tempLessons[i % tempInt].getTimeslots();
					for (int l = 0; l < tempTimeslots.size(); l++)
					{
						tempTimeslot = &(timetables[i].timeslots[tempTimeslots[l].getDay()][(tempTimeslots[l].getStartTime() / 100) - 9]);
						tempString = tempTimeslot->getLocation();
						if (tempString == "")
						{
							*tempTimeslot = tempTimeslots[l];
						}
						else if (tempString != "")
						{
							invalidTimetable = true;
							break;
						}
					}
				}

				if (invalidTimetable)
				{
					break;
				}
			}

			if (invalidTimetable)
			{
				break;
			}
		}

		if (!invalidTimetable)
		{
			validTimetables++;
		}
		else if (invalidTimetable)
		{
			timetables[i].timeslots[0][0].setLocation("false");
		}

		cout << i + 1 << "/" << timetables.size() << " (" << ceil((static_cast<float>(i + 1) / static_cast<float>(timetables.size())) * 100) << "%) completed, " << validTimetables << " (" << ceil((static_cast<float>(validTimetables) / static_cast<float>(timetables.size())) * 100) << "%) valid timetables..." << endl; 

		invalidTimetable = false;
	}

	return timetables;
}

Course pullCourse(string subjectAreaA, string catalogueNumberA, string semesterA, string campusA)
{
	time_t currentTime;
	time(&currentTime);
	tm technicalMachine;	// :P
	localtime_s(&technicalMachine, &currentTime);
	int iCurrentYear = technicalMachine.tm_year + 1900;
	stringstream ssCurrentYear;
	ssCurrentYear << iCurrentYear;
	const string searchURL[] = { "https://access.adelaide.edu.au/courses/", "search.asp?year=" + ssCurrentYear.str() + "&m=r&title=&subject=", "&catalogue=", "&action=Search&term=&career=&campus=&class=&sort=" };
	stringstream stringStream;

	stringStream << searchURL[0] << searchURL[1] << subjectAreaA << searchURL[2] << catalogueNumberA << searchURL[3];
	// string rawSearchHTML = replace(urlToString(stringStream.str()), "amp;", "");
	string rawSearchHTML = replace("    <tr>\n\n\n        <td class=\"odd\">Semester 1\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 1001</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=103727+1+3210+1\">Introduction to Development Studies</a></td>\n\n\n        <td class=\"odd\" align=\"right\">3</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=103727+1+3210+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 2002</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=106395+1+3220+1\">Rights and Development</a></td>\n\n\n        <td class=\"even\" align=\"right\">3</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=106395+1+3220+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Winter School\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 2003</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=106399+1+3215+1\">Managing Conflict in the Developing World</a></td>\n\n\n        <td class=\"odd\" align=\"right\">3</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=106399+1+3215+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 2100</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=104596+1+3220+1\">Poverty and Social Development</a></td>\n\n\n        <td class=\"even\" align=\"right\">3</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=104596+1+3220+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Semester 1\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 2101</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=104597+1+3210+1\">Community, Gender and Critical Development</a></td>\n\n\n        <td class=\"odd\" align=\"right\">3</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=104597+1+3210+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Summer School\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 3002</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=105412+1+3205+1\">Development Studies Professional Practicum</a></td>\n\n\n        <td class=\"even\" align=\"right\">6</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=105412+1+3205+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 3100</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=104840+1+3220+1\">Aid Policy and Practice</a></td>\n\n\n        <td class=\"odd\" align=\"right\">3</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=104840+1+3220+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Semester 1\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 4401A</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=105226+1+3210+FY1\">Honours Development Studies Part 1</a></td>\n\n\n        <td class=\"even\" align=\"right\">12</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=105226+1+3210+FY1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 4401A</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=105226+1+3220+TYA\">Honours Development Studies Part 1</a></td>\n\n\n        <td class=\"odd\" align=\"right\">12</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=105226+1+3220+TYA&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Semester 1\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 4401B</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=105227+1+3210+1\">Honours Development Studies Part 2</a></td>\n\n\n        <td class=\"even\" align=\"right\">12</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=105227+1+3210+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 4401B</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=105227+1+3220+1\">Honours Development Studies Part 2</a></td>\n\n\n        <td class=\"odd\" align=\"right\">12</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=105227+1+3220+1&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Semester 1\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 4471A</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=105392+1+3210+TYA\">Honours Development Studies Two Year Continuing</a></td>\n\n\n        <td class=\"even\" align=\"right\">6</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=105392+1+3210+TYA&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Semester 1\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 4471A</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=105392+1+3210+TYB\">Honours Development Studies Two Year Continuing</a></td>\n\n\n        <td class=\"odd\" align=\"right\">6</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=105392+1+3210+TYB&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Semester 1\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 4471A</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=105392+1+3210+TYC\">Honours Development Studies Two Year Continuing</a></td>\n\n\n        <td class=\"even\" align=\"right\">6</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=105392+1+3210+TYC&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 4471A</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=105392+1+3220+TYA\">Honours Development Studies Two Year Continuing</a></td>\n\n\n        <td class=\"odd\" align=\"right\">6</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=105392+1+3220+TYA&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 4471A</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=105392+1+3220+TYB\">Honours Development Studies Two Year Continuing</a></td>\n\n\n        <td class=\"even\" align=\"right\">6</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=105392+1+3220+TYB&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 4471A</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=105392+1+3220+TYC\">Honours Development Studies Two Year Continuing</a></td>\n\n\n        <td class=\"odd\" align=\"right\">6</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=105392+1+3220+TYC&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"even\">Semester 1\n\n\n        </td>\n\n\n        <td class=\"even\">DEVT 4471B</td>\n\n\n        <td class=\"even\"><a href=\"details.asp?year=2012&amp;course=105393+1+3210+TYD\">Honours Development Studies Two Year Final</a></td>\n\n\n        <td class=\"even\" align=\"right\">6</td>\n\n\n        <td class=\"even\">Undergraduate</td>\n\n\n        <td class=\"even\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"even\"><a href=\"search.asp?year=2012&amp;add=105393+1+3210+TYD&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    <tr>\n\n\n        <td class=\"odd\">Semester 2\n\n\n        </td>\n\n\n        <td class=\"odd\">DEVT 4471B</td>\n\n\n        <td class=\"odd\"><a href=\"details.asp?year=2012&amp;course=105393+1+3220+TYD\">Honours Development Studies Two Year Final</a></td>\n\n\n        <td class=\"odd\" align=\"right\">6</td>\n\n\n        <td class=\"odd\">Undergraduate</td>\n\n\n        <td class=\"odd\">North Terrace</td>\n\n\n        \n\n\n            <td class=\"odd\"><a href=\"search.asp?year=2012&amp;add=105393+1+3220+TYD&amp;next=%2Fcourses%2Fsearch%2Easp%3Fyear%3D2008%26m%3Dr%26title%3DBA%2B%26subject%3DDEVT%26catalogue%3D%26action%3DSearch%26term%3D%26career%3D%26campus%3D%26class%3D%26sort\">Add</a></td>\n\n\n        \n\n\n    </tr>\n\n\n    \n\n\n    </table>\n\n\n    \n\n\n    </p>", "amp;", "");

	vector<string> odd = split(rawSearchHTML, vector<string>(1, "<td class=\"odd\">"));

	vector<string> delimitersA;
	delimitersA.push_back("\n");
	delimitersA.push_back("</td>");

	vector<string> delimitersB;
	delimitersB.push_back("<a href=\"");
	delimitersB.push_back("\">");

	int counter = 1;
	string semesterB;
	string subjectAreaB;
	string catalogueNumberB;
	string link;
	string campusB;
	bool foundCourse = false;
	while (counter < odd.size())
	{
		semesterB = split(odd[counter], delimitersA)[0];
		
		counter++;
		
		subjectAreaB = split(split(odd[counter], delimitersA)[0], vector<string>(1, " "))[0];
		catalogueNumberB = split(split(odd[counter], delimitersA)[0], vector<string>(1, " "))[1];

		counter++;

		link = searchURL[0] + split(split(odd[counter], delimitersA)[0], delimitersB)[1];
		
		counter += 2;
		
		campusB = split(odd[counter], delimitersA)[0];
		
		counter += 2;
		
		if ((subjectAreaB == subjectAreaA) && (catalogueNumberB == catalogueNumberA) && (semesterB == semesterA) && (campusB == campusA))
		{
			foundCourse = true;
			break;
		}
	}

	delimitersA.clear();
	delimitersB.clear();

	Course course;

	if (!foundCourse)
	{
		course.setName("false");

		return course;
	}
	else if (foundCourse)
	{
		// string rawCourseHTML = replace(urlToString(link), "amp;", "");
		string rawCourseHTML = replace("<th colspan=\"2\" class=\"course\">&nbsp;</th>\n\n\n        \n\n\n            <th colspan=\"8\" class=\"course\"><a href=\"help.asp?topic=csscontrib2&amp;year=2012\" target=\"cphelp\" onClick=\"window.open('help.asp?topic=csscontrib2&amp;year=2012&amp;popup=Y','cphelp','width=350,height=300,scrollbars=yes,resizable=yes,menubar=no,toolbar=no').focus();return false;\">Commonwealth Supported Student Contribution</a></th>\n\n\n        <th colspan=\"2\" class=\"course\">\n\n\n    <table width=\"720\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\n\n    <tr><th colspan=\"8\" class=\"course\">Enrolment Class: Workshop</th></tr>\n\n\n        <tr class=\"trheader\">\n\n\n            <th class=\"course\">Class Nbr</th>\n\n\n            <th class=\"course\">Section</th>\n\n\n            <th class=\"course\">Size</th>\n\n\n            <th class=\"course\">Available</th>\n\n\n            <th class=\"course-accent\">Dates</th>\n\n\n            <th class=\"course-accent\">Days</th>\n\n\n            <th class=\"course-accent\">Time</th>\n\n\n            <th class=\"course-accent\">Location</th>\n\n\n        </tr>\n\n\n        \n\n\n                            <tr class=\"data\">\n\n\n                                <td class=\"odd\"  rowspan=\"2\">24265</td>\n\n\n                                <td class=\"odd\"  rowspan=\"2\">WR01</td>\n\n\n                                \n\n\n                                    <td class=\"odd\"  rowspan=\"2\">80</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\"  rowspan=\"2\">1</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\">23 Jul -  10 Sep</td>\n\n\n                                        <td class=\"odd\">Monday</td>\n\n\n                                        <td class=\"odd\">1pm - 3pm</td>\n\n\n                                        <td class=\"odd\">Ingkarni Wardli, 218, Collaborative Suite</td>\n\n\n                                    \n\n\n                                            </tr><tr>\n\n\n                                        \n\n\n                                        <td class=\"even\">1 Oct -  22 Oct</td>\n\n\n                                        <td class=\"even\">Monday</td>\n\n\n                                        <td class=\"even\">1pm - 3pm</td>\n\n\n                                        <td class=\"even\">Ingkarni Wardli, 218, Collaborative Suite</td>\n\n\n                                    \n\n\n                            </tr>\n\n\n                            \n\n\n                            <tr class=\"data\">\n\n\n                                <td class=\"even\"  rowspan=\"2\">24266</td>\n\n\n                                <td class=\"even\"  rowspan=\"2\">WR02</td>\n\n\n                                \n\n\n                                    <td class=\"even\"  rowspan=\"2\">73</td>\n\n\n                                    \n\n\n                                        <td class=\"even\"  rowspan=\"2\">5</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\">24 Jul -  11 Sep</td>\n\n\n                                        <td class=\"odd\">Tuesday</td>\n\n\n                                        <td class=\"odd\">11am - 1pm</td>\n\n\n                                        <td class=\"odd\">Ingkarni Wardli, 218, Collaborative Suite</td>\n\n\n                                    \n\n\n                                            </tr><tr>\n\n\n                                        \n\n\n                                        <td class=\"even\">2 Oct -  23 Oct</td>\n\n\n                                        <td class=\"even\">Tuesday</td>\n\n\n                                        <td class=\"even\">11am - 1pm</td>\n\n\n                                        <td class=\"even\">Ingkarni Wardli, 218, Collaborative Suite</td>\n\n\n                                    \n\n\n                            </tr>\n\n\n                            \n\n\n                            <tr class=\"data\">\n\n\n                                <td class=\"odd\"  rowspan=\"2\">24279</td>\n\n\n                                <td class=\"odd\"  rowspan=\"2\">WR03</td>\n\n\n                                \n\n\n                                    <td class=\"odd\"  rowspan=\"2\">62</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\"  rowspan=\"2\">35</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\">24 Jul -  11 Sep</td>\n\n\n                                        <td class=\"odd\">Tuesday</td>\n\n\n                                        <td class=\"odd\">4pm - 6pm</td>\n\n\n                                        <td class=\"odd\">Ingkarni Wardli, 218, Collaborative Suite</td>\n\n\n                                    \n\n\n                                            </tr><tr>\n\n\n                                        \n\n\n                                        <td class=\"even\">2 Oct -  23 Oct</td>\n\n\n                                        <td class=\"even\">Tuesday</td>\n\n\n                                        <td class=\"even\">4pm - 6pm</td>\n\n\n                                        <td class=\"even\">Ingkarni Wardli, 218, Collaborative Suite</td>\n\n\n                                    \n\n\n                            </tr>\n\n\n                            <tr><th colspan=\"8\" class=\"course\">Related Class: Practical</th></tr>\n\n\n        <tr class=\"trheader\">\n\n\n            <th class=\"course\">Class Nbr</th>\n\n\n            <th class=\"course\">Section</th>\n\n\n            <th class=\"course\">Size</th>\n\n\n            <th class=\"course\">Available</th>\n\n\n            <th class=\"course-accent\">Dates</th>\n\n\n            <th class=\"course-accent\">Days</th>\n\n\n            <th class=\"course-accent\">Time</th>\n\n\n            <th class=\"course-accent\">Location</th>\n\n\n        </tr>\n\n\n        \n\n\n                            <tr class=\"data\">\n\n\n                                <td class=\"odd\"  rowspan=\"2\">21671</td>\n\n\n                                <td class=\"odd\"  rowspan=\"2\">PR01</td>\n\n\n                                \n\n\n                                    <td class=\"odd\"  rowspan=\"2\">78</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\"  rowspan=\"2\">3</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\">1 Aug -  12 Sep</td>\n\n\n                                        <td class=\"odd\">Wednesday</td>\n\n\n                                        <td class=\"odd\">3pm - 5pm</td>\n\n\n                                        <td class=\"odd\">Engineering &amp; Mathematics, EM108/109, Computer Sci Suite 1&amp;2</td>\n\n\n                                    \n\n\n                                            </tr><tr>\n\n\n                                        \n\n\n                                        <td class=\"even\">3 Oct -  24 Oct</td>\n\n\n                                        <td class=\"even\">Wednesday</td>\n\n\n                                        <td class=\"even\">3pm - 5pm</td>\n\n\n                                        <td class=\"even\">Engineering &amp; Mathematics, EM108/109, Computer Sci Suite 1&amp;2</td>\n\n\n                                    \n\n\n                            </tr>\n\n\n                            \n\n\n                            <tr class=\"data\">\n\n\n                                <td class=\"even\"  rowspan=\"2\">21672</td>\n\n\n                                <td class=\"even\"  rowspan=\"2\">PR02</td>\n\n\n                                \n\n\n                                    <td class=\"even\"  rowspan=\"2\">53</td>\n\n\n                                    \n\n\n                                        <td class=\"even\"  rowspan=\"2\"><b>FULL</b></td>\n\n\n                                    \n\n\n                                        <td class=\"odd\">2 Aug -  13 Sep</td>\n\n\n                                        <td class=\"odd\">Thursday</td>\n\n\n                                        <td class=\"odd\">1pm - 3pm</td>\n\n\n                                        <td class=\"odd\">Engineering &amp; Mathematics, EM108/109, Computer Sci Suite 1&amp;2</td>\n\n\n                                    \n\n\n                                            </tr><tr>\n\n\n                                        \n\n\n                                        <td class=\"even\">4 Oct -  25 Oct</td>\n\n\n                                        <td class=\"even\">Thursday</td>\n\n\n                                        <td class=\"even\">1pm - 3pm</td>\n\n\n                                        <td class=\"even\">Engineering &amp; Mathematics, EM108/109, Computer Sci Suite 1&amp;2</td>\n\n\n                                    \n\n\n                            </tr>\n\n\n                            \n\n\n                            <tr class=\"data\">\n\n\n                                <td class=\"odd\"  rowspan=\"2\">21673</td>\n\n\n                                <td class=\"odd\"  rowspan=\"2\">PR03</td>\n\n\n                                \n\n\n                                    <td class=\"odd\"  rowspan=\"2\">78</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\"  rowspan=\"2\">31</td>\n\n\n                                    \n\n\n                                        <td class=\"odd\">2 Aug -  13 Sep</td>\n\n\n                                        <td class=\"odd\">Thursday</td>\n\n\n                                        <td class=\"odd\">9am - 11am</td>\n\n\n                                        <td class=\"odd\">Engineering &amp; Mathematics, EM108/109, Computer Sci Suite 1&amp;2</td>\n\n\n                                    \n\n\n                                            </tr><tr>\n\n\n                                        \n\n\n                                        <td class=\"even\">4 Oct -  25 Oct</td>\n\n\n                                        <td class=\"even\">Thursday</td>\n\n\n                                        <td class=\"even\">9am - 11am</td>\n\n\n                                        <td class=\"even\">Engineering &amp; Mathematics, EM108/109, Computer Sci Suite 1&amp;2</td>\n\n\n                                    \n\n\n                            </tr>\n\n\n                            <tr><th colspan=\"8\"", "amp;", "");

		odd = split(rawCourseHTML, vector<string>(1, "class=\"course\""));

		vector<string> rawCourseData;
		counter = 4;
		while (counter < odd.size())
		{
			rawCourseData.push_back(odd[counter]);
			
			counter += 4;

			rawCourseData.push_back(odd[counter]);

			counter++;
		}

		delimitersA.push_back("Class: ");
		delimitersA.push_back("</th>");

		delimitersB.push_back("\">");
		delimitersB.push_back("</td>");

		course.setName(subjectAreaA + " " + catalogueNumberA);

		vector<string> tempLessonData;
		string sWeekDay;
		WeekDay wDWeekDay;
		int startTime;
		int endTime;
		string location;
		vector<Timeslot> tempTimeslots;
		vector<Lesson> tempLessons;
		for (int i = 0; i < rawCourseData.size(); i += 2)
		{
			// Using if-else statements here, because C++ doesn't support the switching of strings. Wynaut?! :O
			if (split(rawCourseData[i], delimitersA)[1] == "Lecture")
			{
				tempLessonData = split(rawCourseData[i + 1], vector<string>(1, "LE"));

				for (int j = 1; j < tempLessonData.size(); j++)
				{
					counter = 8;
					while (counter < (split(tempLessonData[j], delimitersB).size() - 9))
					{
						sWeekDay = split(tempLessonData[j], delimitersB)[counter];

						// Same as before
						if (sWeekDay == "Monday")
						{
							wDWeekDay = MONDAY;
						}
						else if (sWeekDay == "Tuesday")
						{
							wDWeekDay = TUESDAY;
						}
						else if (sWeekDay == "Wednesday")
						{
							wDWeekDay = WEDNESDAY;
						}
						else if (sWeekDay == "Thursday")
						{
							wDWeekDay = THURSDAY;
						}
						else if (sWeekDay == "Friday")
						{
							wDWeekDay = FRIDAY;
						}

						counter += 2;
						
						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "9am")
						{
							startTime = 900;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							startTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							startTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							startTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							startTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							startTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							startTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							startTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							startTime = 1700;
						}

						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							endTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							endTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							endTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							endTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							endTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							endTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							endTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							endTime = 1700;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "6pm")
						{
							endTime = 1800;
						}

						counter += 2;

						location = split(tempLessonData[j], delimitersB)[counter];

						counter += 4;

						tempTimeslots.push_back(Timeslot(location, wDWeekDay, startTime, endTime));
					}

					tempLessons.push_back(Lesson(tempTimeslots));
					tempTimeslots.clear();
				}

				course.setLectures(tempLessons);
				tempLessons.clear();
			}
			else if (split(rawCourseData[i], delimitersA)[1] == "Practical")
			{
				tempLessonData = split(rawCourseData[i + 1], vector<string>(1, "PR"));

				for (int j = 1; j < tempLessonData.size(); j++)
				{
					counter = 8;
					while (counter < (split(tempLessonData[j], delimitersB).size() - 9))
					{
						sWeekDay = split(tempLessonData[j], delimitersB)[counter];

						// Same as before
						if (sWeekDay == "Monday")
						{
							wDWeekDay = MONDAY;
						}
						else if (sWeekDay == "Tuesday")
						{
							wDWeekDay = TUESDAY;
						}
						else if (sWeekDay == "Wednesday")
						{
							wDWeekDay = WEDNESDAY;
						}
						else if (sWeekDay == "Thursday")
						{
							wDWeekDay = THURSDAY;
						}
						else if (sWeekDay == "Friday")
						{
							wDWeekDay = FRIDAY;
						}

						counter += 2;
						
						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "9am")
						{
							startTime = 900;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							startTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							startTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							startTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							startTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							startTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							startTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							startTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							startTime = 1700;
						}

						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							endTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							endTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							endTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							endTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							endTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							endTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							endTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							endTime = 1700;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "6pm")
						{
							endTime = 1800;
						}

						counter += 2;

						location = split(tempLessonData[j], delimitersB)[counter];

						counter += 4;

						tempTimeslots.push_back(Timeslot(location, wDWeekDay, startTime, endTime));
					}

					tempLessons.push_back(Lesson(tempTimeslots));
					tempTimeslots.clear();
				}

				course.setPracticals(tempLessons);
				tempLessons.clear();
			}
			else if (split(rawCourseData[i], delimitersA)[1] == "Seminar")
			{
				tempLessonData = split(rawCourseData[i + 1], vector<string>(1, "SE"));

				for (int j = 1; j < tempLessonData.size(); j++)
				{
					counter = 8;
					while (counter < (split(tempLessonData[j], delimitersB).size() - 9))
					{
						sWeekDay = split(tempLessonData[j], delimitersB)[counter];

						// Same as before
						if (sWeekDay == "Monday")
						{
							wDWeekDay = MONDAY;
						}
						else if (sWeekDay == "Tuesday")
						{
							wDWeekDay = TUESDAY;
						}
						else if (sWeekDay == "Wednesday")
						{
							wDWeekDay = WEDNESDAY;
						}
						else if (sWeekDay == "Thursday")
						{
							wDWeekDay = THURSDAY;
						}
						else if (sWeekDay == "Friday")
						{
							wDWeekDay = FRIDAY;
						}

						counter += 2;
						
						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "9am")
						{
							startTime = 900;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							startTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							startTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							startTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							startTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							startTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							startTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							startTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							startTime = 1700;
						}

						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							endTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							endTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							endTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							endTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							endTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							endTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							endTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							endTime = 1700;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "6pm")
						{
							endTime = 1800;
						}

						counter += 2;

						location = split(tempLessonData[j], delimitersB)[counter];

						counter += 4;

						tempTimeslots.push_back(Timeslot(location, wDWeekDay, startTime, endTime));
					}

					tempLessons.push_back(Lesson(tempTimeslots));
					tempTimeslots.clear();
				}

				course.setSeminars(tempLessons);
				tempLessons.clear();
			}
			else if (split(rawCourseData[i], delimitersA)[1] == "Tutorial")
			{
				tempLessonData = split(rawCourseData[i + 1], vector<string>(1, "TU"));

				for (int j = 1; j < tempLessonData.size(); j++)
				{
					counter = 8;
					while (counter < (split(tempLessonData[j], delimitersB).size() - 9))
					{
						sWeekDay = split(tempLessonData[j], delimitersB)[counter];

						// Same as before
						if (sWeekDay == "Monday")
						{
							wDWeekDay = MONDAY;
						}
						else if (sWeekDay == "Tuesday")
						{
							wDWeekDay = TUESDAY;
						}
						else if (sWeekDay == "Wednesday")
						{
							wDWeekDay = WEDNESDAY;
						}
						else if (sWeekDay == "Thursday")
						{
							wDWeekDay = THURSDAY;
						}
						else if (sWeekDay == "Friday")
						{
							wDWeekDay = FRIDAY;
						}

						counter += 2;
						
						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "9am")
						{
							startTime = 900;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							startTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							startTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							startTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							startTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							startTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							startTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							startTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							startTime = 1700;
						}

						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							endTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							endTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							endTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							endTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							endTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							endTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							endTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							endTime = 1700;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "6pm")
						{
							endTime = 1800;
						}

						counter += 2;

						location = split(tempLessonData[j], delimitersB)[counter];

						counter += 4;

						tempTimeslots.push_back(Timeslot(location, wDWeekDay, startTime, endTime));
					}

					tempLessons.push_back(Lesson(tempTimeslots));
					tempTimeslots.clear();
				}

				course.setTutorials(tempLessons);
				tempLessons.clear();
			}
			else if (split(rawCourseData[i], delimitersA)[1] == "Workshop")
			{
				tempLessonData = split(rawCourseData[i + 1], vector<string>(1, "WR"));

				for (int j = 1; j < tempLessonData.size(); j++)
				{
					counter = 8;
					while (counter < (split(tempLessonData[j], delimitersB).size() - 9))
					{
						sWeekDay = split(tempLessonData[j], delimitersB)[counter];

						// Same as before
						if (sWeekDay == "Monday")
						{
							wDWeekDay = MONDAY;
						}
						else if (sWeekDay == "Tuesday")
						{
							wDWeekDay = TUESDAY;
						}
						else if (sWeekDay == "Wednesday")
						{
							wDWeekDay = WEDNESDAY;
						}
						else if (sWeekDay == "Thursday")
						{
							wDWeekDay = THURSDAY;
						}
						else if (sWeekDay == "Friday")
						{
							wDWeekDay = FRIDAY;
						}

						counter += 2;
						
						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "9am")
						{
							startTime = 900;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							startTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							startTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							startTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							startTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							startTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							startTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							startTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							startTime = 1700;
						}

						if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "10am")
						{
							endTime = 1000;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "11am")
						{
							endTime = 1100;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "12pm")
						{
							endTime = 1200;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "1pm")
						{
							endTime = 1300;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "2pm")
						{
							endTime = 1400;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "3pm")
						{
							endTime = 1500;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "4pm")
						{
							endTime = 1600;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "5pm")
						{
							endTime = 1700;
						}
						else if (split(split(tempLessonData[j], delimitersB)[counter], vector<string>(1, " - "))[0] == "6pm")
						{
							endTime = 1800;
						}

						counter += 2;

						location = split(tempLessonData[j], delimitersB)[counter];

						counter += 4;

						tempTimeslots.push_back(Timeslot(location, wDWeekDay, startTime, endTime));
					}

					tempLessons.push_back(Lesson(tempTimeslots));
					tempTimeslots.clear();
				}

				course.setWorkshops(tempLessons);
				tempLessons.clear();
			}
		}

		delimitersA.clear();
		delimitersB.clear();
	}

	return course;
}
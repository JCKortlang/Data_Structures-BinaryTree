/*
	Assignment #6
	Name:	Jan Christian Chavez-Kortlang
	Email:	jchavezk@asu.edu
*/

#ifndef CITY_H
#define CITY_H

#include <string>
using std::string;

class City
{
	friend class ZipInfo;
public:
	City();
	City(string city, string state, string zipCode);
	string getCity();
	string getState();
	string getZip();
	string toString();
	int compareTo(string city, string state, string zipCode);
	int compareTo(string city, string state);
private:
	void setCity(string city);
	void setZipCode(string zipCode);
	void setState(string state);

	string m_city;
	string m_state;
	string m_zipCode;
};
#endif // !CITY_H

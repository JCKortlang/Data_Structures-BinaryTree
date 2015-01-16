/*
	Assignment #6
	Name:	Jan Christian Chavez-Kortlang
	Email:	jchavezk@asu.edu
*/
#include "City.h"

City::City()
{
	m_city = "?";
	m_zipCode = "?";
	m_state = "?";
}

City::City(string city, string state, string zipCode)
{
	m_city = city;
	m_state = state;
	m_zipCode = zipCode;
}

string City::getCity()
{
	return m_city;
}

string City::getState()
{
	return m_state;
}

string City::getZip()
{
	return m_zipCode;
}

string City::toString()
{
	return m_city + " in " + m_state + " with zipcode of " + m_zipCode;
}

int City::compareTo(string city, string state)
{
	int cityResult = city.compare(m_city);

	if (cityResult == 0)
		return state.compare(m_state);
	else
		return cityResult;
}

int City::compareTo(string city, string state, string zipCode)
{
	int result = compareTo(city, state);

	if (result == 0)
		return zipCode.compare(m_zipCode);
	else
		return result;
}

void City::setCity(string city)
{
	m_city = city;
}

void City::setZipCode(string zipCode)
{
	m_zipCode = zipCode;
}

void City::setState(string state)
{
	m_state = state;
}
/*
	Assignment #6
	Name:	Jan Christian Chavez-Kortlang
	Email:	jchavezk@asu.edu
*/

#include "ZipInfo.h"

//The following three functions are constructors
ZipInfo::ZipInfo()
{
	m_parent = NULL;
	m_leftChild = NULL;
	m_rightChild = NULL;
}

ZipInfo::ZipInfo(string city, string state, string zipCode)
{
	m_City.setCity(city);
	m_City.setState(state);
	m_City.setZipCode(zipCode);
	m_parent = NULL;
	m_leftChild = NULL;
	m_rightChild = NULL;
}
ZipInfo::ZipInfo(string city, string state)
{
	m_City.setCity(city);
	m_City.setState(state);
	m_parent = NULL;
	m_leftChild = NULL;
	m_rightChild = NULL;
}

//Recursively deletes all nodes below this node.
ZipInfo::~ZipInfo()
{
	if (m_leftChild != NULL)
	{
		delete m_leftChild;
	}
	if (m_rightChild != NULL)
	{
		delete m_rightChild;
	}
}
//The following functions are accessor functions
string ZipInfo::getCity()
{
	return m_City.getCity();
}
string ZipInfo::getState()
{
	return m_City.getState();
}
string ZipInfo::getZip()
{
	return m_City.getZip();
}
ZipInfo* ZipInfo::getLeft()
{
	return m_leftChild;
}

ZipInfo* ZipInfo::getRight()
{
	return m_rightChild;
}

ZipInfo* ZipInfo::getParent()
{
	return m_parent;
}

int ZipInfo::getChildCount()
{
	int childCount = 0;

	if (m_leftChild != NULL)
		childCount +=  1 + m_leftChild->getChildCount();
	if (m_rightChild != NULL)
		childCount += 1 + m_rightChild->getChildCount();

	return childCount;
}

//The following three functions are mutator functions
void ZipInfo::setLeft(ZipInfo * other)
{
	m_leftChild = other;
}

void ZipInfo::setRight(ZipInfo * other)
{
	m_rightChild = other;
}

void ZipInfo::setParent(ZipInfo * other)
{
	m_parent = other;
}
void ZipInfo::print()
{
	cout << m_City.toString() << endl;
}

/*
	Returns 0 if the two objects are equal.
	Returns < 0 if the key is smaller than the object.
	Returns > 0 if the key is larger than the object.
*/
int ZipInfo::compareTo(string city, string state)
{
	return m_City.compareTo(city, state);
}
int ZipInfo::compareTo(string city, string state, string zipCode)
{
	return m_City.compareTo(city, state, zipCode);
}

ZipInfo* ZipInfo::search(string city, string state)
{
	int result = compareTo(city, state);

	if (result == 0)
	{
		return this;
	}
	else if (result > 0 && m_rightChild != NULL)
	{
		return m_rightChild->search(city, state);
	}
	else if (result < 0 && m_leftChild != NULL)
	{
		return m_leftChild->search(city, state);
	}
	return NULL;
}
/*
	Assignment #6
	Name:	Jan Christian Chavez-Kortlang
	Email:	jchavezk@asu.edu
*/

#ifndef ZIPINFO_H
#define ZIPINFO_H

#include "City.h"
#include <iostream>

using std::cout;
using std::endl;

//ZipInfo represents a combination of city, state, and zip code
class ZipInfo
{
public:
	//The following three functions are constructors
	ZipInfo();
	ZipInfo(string city, string state, string zipCode);
	ZipInfo(string city, string state);
	~ZipInfo();
	//The following functions are accessor functions
	string getCity();
	string getState();
	string getZip();
	ZipInfo * getLeft();
	ZipInfo * getRight();
	ZipInfo * getParent();
	int getChildCount();

	//The following three functions are mutator functions
	void setLeft(ZipInfo * other);
	void setRight(ZipInfo * other);
	void setParent(ZipInfo * other);

	void print();
	int compareTo(string city, string state);
	int compareTo(string city, string state, string zipCode);
	ZipInfo* search(string city, string state);
	int deleteNode(ZipInfo* node);

private:
	City m_City;
	ZipInfo * m_leftChild;
	ZipInfo * m_rightChild;
	ZipInfo * m_parent;
}; //end of ZipInfo class

#endif
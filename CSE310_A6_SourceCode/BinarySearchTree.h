/*
	Assignment #6
	Name:	Jan Christian Chavez-Kortlang
	Email:	jchavezk@asu.edu
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "ZipInfo.h"

//class BinarySearchTree will contains cities
class BinarySearchTree
 {
 public:
     BinarySearchTree();
     ~BinarySearchTree();
     bool isEmpty();
     void inOrderTreePrint();
     void preOrderTreePrint();
     void postOrderTreePrint();
     void inOrderTreeWalk(ZipInfo *);
     void preOrderTreeWalk(ZipInfo *);
     void postOrderTreeWalk(ZipInfo *);
     ZipInfo* treeMinimum();
	 ZipInfo* treeMinimum(ZipInfo* node);
     ZipInfo* treeMaximum();
	 ZipInfo* treeMaximum(ZipInfo* node);
     ZipInfo* treeSuccessor(string,string);
     ZipInfo* treePredecessor(string,string);
     ZipInfo* treeSearch(string, string);
     bool treeInsert(string,string,string);
     ZipInfo * treeDelete(string,string);
	 void transplant(ZipInfo* nodeA, ZipInfo* nodeB);

 private:
	 ZipInfo * m_root;
 };

#endif


/*
	Assignment #6
	Name:	Jan Christian Chavez-Kortlang
	Email:	jchavezk@asu.edu
*/
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	m_root = NULL;
}

/*
	Recursively deletes all nodes and prints out the number of nodes deleted. Refer to ~ZipInfo().
*/
BinarySearchTree::~BinarySearchTree()
{
	//Children + 1(root)
	cout << "The number of nodes deleted: " << m_root->getChildCount() + 1 << endl;
	delete m_root;
}

bool BinarySearchTree::isEmpty()
{
	return m_root == NULL;
}

/*
	Prints all nodes in order using the inOrderPrintWalk().
*/
void BinarySearchTree::inOrderTreePrint()
{
	if (isEmpty())
		cout << "tree is empty" << endl;
	else
	{
		cout << "\n";
		inOrderTreeWalk(m_root);
		cout << "\n";
	}
}

/*
	Prints all nodes in pre-order using preOrderTreeWalk().
*/
void BinarySearchTree::preOrderTreePrint()
{
	if (isEmpty())
		cout << "tree is empty" << endl;
	else
	{
		cout << "\n";
		preOrderTreeWalk(m_root);
		cout << "\n";
	}
}

/*
	Prints all nodes in post-order using postOrderTreeWalk()
*/
void BinarySearchTree::postOrderTreePrint()
{
	if (isEmpty())
		cout << "tree is empty" << endl;
	else
	{
		cout << "\n";
		postOrderTreeWalk(m_root);
		cout << "\n";
	}
}

/*
	Prints nodes under the parameter node x using in-order.
*/
void BinarySearchTree::inOrderTreeWalk(ZipInfo * x)
{
	if (x != NULL)
	{
		inOrderTreeWalk(x->getLeft());
		x->print();
		inOrderTreeWalk(x->getRight());
		
	}
}

/*
Prints nodes under the parameter node x using pre-order.
*/
void BinarySearchTree::preOrderTreeWalk(ZipInfo * x)
{
	if (m_root != NULL)
	{
		x->print();
		preOrderTreeWalk(x->getLeft());
		preOrderTreeWalk(x->getRight());
	}
}

/*
Prints nodes under the parameter node x using post-order.
*/
void BinarySearchTree::postOrderTreeWalk(ZipInfo * x)
{
	if (m_root != NULL)
	{
		postOrderTreeWalk(x->getLeft());
		postOrderTreeWalk(x->getRight());
		x->print();
	}
}

/*
	Recursively iterates through the tree until a matching node is found. Refer to ZipInfo::search().
	Returns NULL if a matching node is not found.
*/
ZipInfo * BinarySearchTree::treeSearch(string city, string state)
{
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		return m_root->search(city, state);
	}
}

/*
	Returns the node with the smallest key value.
*/
ZipInfo * BinarySearchTree::treeMinimum()
{
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		ZipInfo* temp = m_root;
		while (temp->getLeft() != NULL)
			temp = temp->getLeft();
		return temp;
	}
}

/*
	Returns the node with the smallest key value of the subtree starting at node x.
*/
ZipInfo* BinarySearchTree::treeMinimum(ZipInfo* node)
{
	if (node == NULL)
	{
		return NULL;
	}
	else
	{
		ZipInfo* temp = node;
		while (temp->getLeft() != NULL)
			temp = temp->getLeft();
		return temp;
	}
}

/*
	Returns the node with the maximum key value.
*/
ZipInfo * BinarySearchTree::treeMaximum()
{
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		ZipInfo* temp = m_root;
		while (temp->getRight() != NULL)
			temp = temp->getRight();
		return temp;
	}
}

/*
	Returns the node with the maximum key value of the subtree starting at the parameter node.
*/
ZipInfo* BinarySearchTree::treeMaximum(ZipInfo* node)
{
	if (node == NULL)
	{
		return NULL;
	}
	else
	{
		ZipInfo* temp = node;
		while (temp->getRight() != NULL)
			temp = temp->getRight();
		return temp;
	}
}

/*
	Searches for the node specified by the parameters and returns its successor.
*/
ZipInfo * BinarySearchTree::treeSuccessor(string city, string state)
{
	ZipInfo* result = treeSearch(city, state);
	if (result == NULL)
	{
		return NULL;
	}
	else if (result->getRight() != NULL)
	{
		return treeMinimum(result->getRight());
	}
	else
	{
		ZipInfo* temp = result->getParent();
		while (temp != NULL && result == temp->getRight())
		{
			result = temp;
			temp = temp->getParent();
		}
		return temp;
	}
}

/*
	Searches for the node specified by the parameters and returns its predecessor.
*/
ZipInfo* BinarySearchTree::treePredecessor(string city, string state)
{
	ZipInfo* result = treeSearch(city, state);
	if (result == NULL)
	{
		return NULL;
	}
	else if (result->getLeft() != NULL)
	{
		return treeMaximum(result->getLeft());
	}
	else
	{
		ZipInfo* temp = result->getParent();
		while (temp != NULL && result == temp->getLeft())
		{
			result = temp;
			temp = temp->getParent();
		}
		return temp;
	}
}

/*
	Creates a node from the input parameters and inserts it into the tree.
*/
bool BinarySearchTree::treeInsert(string city, string state, string zipcode)
{
	ZipInfo* node = new ZipInfo(city, state, zipcode);
	ZipInfo* iterator = m_root;
	ZipInfo* temp = NULL;

	while (iterator != NULL)
	{
		temp = iterator;
		int result = temp->compareTo(city, state, zipcode);
		if (result < 0)
		{
			iterator = iterator->getLeft();
		}
		else
		{
			iterator = iterator->getRight();
		}
	}
	node->setParent(temp);
	if (temp == NULL)
	{
		m_root = node;
		return true;
	}
	else
	{
		int result2 = temp->compareTo(city, state, zipcode);
		if (result2 < 0)
		{
			temp->setLeft(node);
		}
		else
		{
			temp->setRight(node);
		}
		return true;
	}
	return false;
}


/*
	Removes the node specified by the parameters and returns it. Returns NULL if the node does not exist in the tree.
*/
ZipInfo * BinarySearchTree::treeDelete(string city, string state)
{
	ZipInfo* result = treeSearch(city, state);

	if (result != NULL)
	{
		int childCount = result->getChildCount();

		if (result->getLeft() == NULL)
		{
			transplant(result, result->getRight());
		}
		else if (result->getRight() == NULL)
		{
			transplant(result, result->getLeft());
		}
		else
		{
			ZipInfo* successor = treeSuccessor(city, state);
			if (successor->getParent()->compareTo(city, state) != 0)
			{
				transplant(successor, successor->getRight());
				successor->setRight(result->getRight());
				successor->getRight()->setParent(successor);
			}
			transplant(result, successor);
			successor->setLeft(result->getLeft());
			successor->getLeft()->setParent(successor);
		}
	}
	return result;
}

/*
	Replaces nodeA with nodeB
*/
void BinarySearchTree::transplant(ZipInfo* nodeA, ZipInfo* nodeB)
{
	if (nodeA->getParent() == NULL)
	{
		m_root = nodeB;
	}
	else if (nodeA == nodeA->getParent()->getLeft())
	{
		nodeA->getParent()->setLeft(nodeB);
	}
	else
	{
		nodeA->getParent()->setRight(nodeB);
	}
	if (nodeB->getParent() != NULL)
	{
		nodeB->setParent(nodeA->getParent());
	}
}
/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: jjfeddock
 */

#include "Node.h"

Node::Node(int info, Node* temp1, Node* temp2)
{
	data = info;
	leftChild = temp1;
	rightChild = temp2;
}

Node::~Node()
{

}


int Node::getData()
{
	return data;
}

NodeInterface * Node::getLeftChild()
{
	return leftChild;
}

NodeInterface * Node::getRightChild()
{
	return rightChild;
}



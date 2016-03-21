/*
 * Node.h
 *
 *  Created on: Mar 5, 2016
 *      Author: jjfeddock
 */

#ifndef NODE_H_
#define NODE_H_

#include "NodeInterface.h"

class Node : public NodeInterface {

public:
	Node(int info, Node* temp1, Node* temp2);
	virtual ~Node();
	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData();

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild();

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild();

	int data;
	Node* leftChild;
	Node* rightChild;

};



#endif /* NODE_H_ */

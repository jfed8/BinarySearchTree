/*
 * BST.h
 *
 *  Created on: Mar 5, 2016
 *      Author: jjfeddock
 */

#ifndef BST_H_
#define BST_H_

#include "BSTInterface.h"
#include "NodeInterface.h"
#include "Node.h"

class BST : public BSTInterface {

public:
	BST();
	virtual ~BST();

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * getRootNode();

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	bool findNode(int data);
	void replace_parent(Node*& seeker, Node*& trailer);
	void replace_parent_root(Node* seeker, Node*& trailer);
        void erase(Node*& root);

protected:
	Node* root;
	Node* local_root;
	int total_nodes;
        int direction;
        Node* trail;

};


#endif /* BST_H_ */

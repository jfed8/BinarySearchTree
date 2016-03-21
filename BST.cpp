/*
 * BST.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: jjfeddock
 */

#include "BST.h"
#include "BSTInterface.h"
#include "Node.h"


BST::BST()
{
	root = NULL;
	local_root = root;
	total_nodes = 0;
    direction = -1;
    trail = local_root;
}

BST::~BST()
{
    clear();
}


NodeInterface * BST::getRootNode()
{
	return root;
}

bool BST::add(int data)
{
	if (findNode(data) == false)
	{
		if (root == NULL)
		{
			root = new Node(data, NULL, NULL);
            local_root = root;
            trail = root;
			total_nodes++;
			return true;
		}
		Node* trailer = root;
		Node* seeker = root;
		while (seeker != NULL)
		{
			if (seeker->data < data)
			{
				trailer = seeker;
				seeker = seeker->rightChild;
			}
			else if(seeker->data > data)
			{
				trailer = seeker;
				seeker = seeker->leftChild;
			}
		}
		if (trailer->data < data)
		{
			trailer->rightChild = new Node(data, NULL, NULL);
			total_nodes++;
			return true;
		}
		else if (trailer->data > data)
		{
			trailer->leftChild = new Node(data, NULL, NULL);
			total_nodes++;
			return true;
		}
	}


	return false;
}

bool BST::remove(int data)
{
	if (findNode(data) == false)
    {
		return false;
    }

    if (root->data == data && total_nodes == 1)
    {
        Node* del = root;
        delete del;
        root = NULL;
        total_nodes--;
        return true;
    }
    else if (root->data == data && total_nodes > 1)
    {
        local_root = root;
        Node* dele = root;
        if (root->leftChild == NULL)
        {
            root = root->rightChild;
            delete dele;
            total_nodes--;
            local_root = root;
            return true;
        }
        else if (root->rightChild == NULL)
        {
            root = root->leftChild;
            delete dele;
            total_nodes--;
            local_root = root;
            return true;
        }
        else
        {
            replace_parent_root(root, root->leftChild);
            total_nodes--;
            local_root = root;
            return true;
        }
    }
	else
    {
		if (data < local_root->data)
        {
            trail = local_root;
            local_root = local_root->leftChild;
            direction = 0;
			return remove(data);
		}
        else if (local_root->data < data)
        {
            trail = local_root;
            local_root = local_root->rightChild;
            direction = 1;
			return remove(data);
		}
        else if (local_root->data == data)
        {
            Node* del = local_root;

            if (local_root->leftChild == NULL && local_root->rightChild == NULL)
            {
                if (direction == 1)
                {
                    trail->rightChild = NULL;
                }
                if (direction == 0)
                {
                    trail->leftChild = NULL;
                }
                delete del;
                total_nodes--;
                local_root = root;
                return true;
            }
            else if (local_root->leftChild == NULL)
            {
                if (direction == 1)
                    trail->rightChild = local_root->rightChild;
                else if (direction == 0)
                    trail->leftChild = local_root->rightChild;
			}
			else if (local_root->rightChild == NULL)
			{
                if (direction == 1)
                    trail->rightChild = local_root->leftChild;
                else if (direction == 0)
                    trail->leftChild = local_root->leftChild;
            }
			else
			{
				replace_parent(del, del->leftChild);
			}
			delete del;
			total_nodes--;
            local_root = root;
			return true;
		}
    }
    return false;
}

void BST::clear()
{
    erase(root);
    root = NULL;
}

bool BST::findNode(int data)
{
    if (root == NULL)
        return false;

    if (total_nodes == 0)
        return false;

    if (root->data == data)
    {
        return true;
    }

    else
    {
        Node* finder = root;
        while (finder->data != data)
        {
            if (data > finder->data)
            {
                if (finder->rightChild == NULL){
                    return false;
                }
                else
                    finder = finder->rightChild;
            }
            else if (data < finder->data)
            {
                if (finder->leftChild == NULL){
                    return false;
                }
                else
                finder = finder->leftChild;
            }
        }
    }
    return true;
}

void BST::replace_parent(Node*& seeker, Node*& trailer)
{
	if (trailer->rightChild != NULL)
	{
		replace_parent(seeker, trailer->rightChild);
	}
	else
	{
        Node* temp = trailer;
		seeker->data = trailer->data;
		seeker = trailer;
		trailer = trailer->leftChild;
        delete temp;
	}
}

void BST::replace_parent_root(Node* seeker, Node*& trailer)
{
    if (trailer->rightChild != NULL)
    {
        replace_parent(seeker, trailer->rightChild);
    }
    else
    {
        Node* temp = trailer;
        root->data = trailer->data;
        trailer = trailer->leftChild;
        delete temp;
    }
}


void BST::erase(Node*& root)
{
    if (root != NULL)
    {
        Node* del = root;
        erase(root->leftChild);
        erase(root->rightChild);
        delete del;
    }
}

/*
 * Factory.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: jjfeddock
 */

#include "Factory.h"
#include "BST.h"


/*
	getBST()

*/
BSTInterface * Factory::getBST()
{
    return new BST();
}

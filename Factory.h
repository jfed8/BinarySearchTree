/*
 * Factory.h
 *
 *  Created on: Mar 5, 2016
 *      Author: jjfeddock
 */

#pragma once
#include "BSTInterface.h"

using namespace std;


/*
getBST()
*/
class Factory
{
public:
	static BSTInterface * getBST();
};
//=======================================================================================

/*
 * function.h
 *
 *  Created on: Mar 18, 2014
 *      Author: peixinho
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include<functional>
#include<vector>

using namespace std;

namespace opf
{
    typedef std::function<double(const vector<double>,const vector<double>)> Distance;
}


#endif /* FUNCTION_H_ */

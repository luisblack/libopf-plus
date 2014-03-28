/*
 * function.h
 *
 *  Created on: Mar 18, 2014
 *      Author: peixinho
 */

#include<functional>
#include<vector>

#ifndef FUNCTION_H_
#define FUNCTION_H_

using namespace std;

namespace opf
{
    typedef std::function<double(const vector<double>,const vector<double>)> Distance;
}


#endif /* FUNCTION_H_ */

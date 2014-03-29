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

/**\authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
*\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
* \version 1.0.0
*/


namespace opf
{
    typedef std::function<double(const vector<double>,const vector<double>)> Distance;
}


#endif /* FUNCTION_H_ */

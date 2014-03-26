/*
 * patterns.h
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#ifndef PATTERNS_H_
#define PATTERNS_H_

#include<string>
#include <iostream>
#include <fstream>
#include<stdlib.h>

#include "pattern.h"

using namespace std;

/**Class for handling a set of patterns.
*@see Pattern()
*/
class Patterns{
public:
    Pattern *pattern;

    Patterns();

    /**Constructor creating an set of patterns from a dataset file with defined extension.
    * @param file_name name of dataset file.
    *@param labeled_dataset denotes if the dataset has or not label
    * */
    Patterns(string file_name);

	/**Constructor creating an empty set of patterns with defined size.
    * @param number_of_patterns number of patterns to be allocated.
    * */
	Patterns(int number_of_patterns);

	/**Destructor of patterns.*/
	~Patterns();

	/**Returns the number of patterns in the dataset.*/
	int get_number_of_patterns() const;

	/**Sets the number of patterns.
    * @param number_of_patterns number of patterns to be set. */
    void set_number_of_patterns(int number_of_patterns);

	/**Returns the number of classes.*/
	int get_number_of_classes() const;

	/**Sets the number of classes.
    * @param number_of_classes number of classes to be set. */
	void set_number_of_classes(int number_of_classes);

    friend istream& operator >>(istream& input, Patterns &patterns);

private:
	int number_of_patterns_;
	int number_of_classes_;

	/*Load a txt dataset and save in a pattern object**/
    void LoadTextFile(string file_name);
};


#endif /* INSTANCES_H_ */

/*
 * instance.h
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#ifndef PATTERN_H_
#define PATTERN_H_

#include <istream>
#include <iterator>
#include <vector>

#include<iostream>

using namespace std;

/**Class for handling a single pattern.
*@see Patterns()
*/
class Pattern{
public:

	/**Standard constructor for a single pattern.*/
    Pattern();

    /**Constructor creating a labeled pattern.
    * @param class_value class value whose the pattern belongs to.
    * @param feature_vector feature vector that represents the pattern.
    * @param dimension dimension of feature vector.
    * @param index index of pattern.
    * */
    template <typename Iterator> Pattern(int class_value, Iterator begin, Iterator end, int index)
        :dimension_(end-begin), feature_vector_(dimension_)
    {
        cout << "another header paradas" << endl;
        class_value_ = class_value;
        set_feature_vector(begin, end);
        index_ = index;
    }

	/**Constructor creating a unlabeled pattern.
    * @param feature_vector that represents the pattern.
    * @param dimension dimension of feature vector.
    * @param index index of pattern.
    * */
    template <typename Iterator> Pattern(Iterator begin, Iterator end, int index)
    {
        cout << "header paradas" << endl;
        dimension_ = end - begin;
        set_feature_vector(begin, end);
        index_ = index;
    }

	/**Constructor creating a pattern allocating space to feature vector.
    * @param dimension number of features in the vector.
    * */
	Pattern(int dimension);

	/**Destructor for single pattern*/
	~Pattern();

	/**Returns the class value of the pattern*/
	int get_class_value() const;

	/**Sets the class value of the pattern
	* @param class_value class value whose the pattern belongs to.
	*/
	void set_class_value(int class_value);

	/**Returns the feature vector of the pattern*/
    const vector<double> get_feature_vector() const;

	/**Sets the feature vector of the pattern
	* @param feature_vector feature vector that represents the pattern.
	*/
    template<typename Iterator> void set_feature_vector(Iterator begin, Iterator end)
    {
        feature_vector_ = std::vector<double>(begin, end);
    }

	/**Returns the dimension size of feature vector*/
	int get_dimension() const;

	/**Sets the dimension size of feature vector.
	* @param dimension dimension of feature vector.
	*/
	void set_dimension(int dimension);

	/**Returns the index of a pattern.*/
	int get_index() const;

	/**Sets the index of a pattern.
	* @param index index of the pattern.
	*/
	void set_index(int index);

    double operator[](int feature_index)
    {
        return feature_vector_[feature_index];
    }

	/**Overloads the operator >> to input stream for a single pattern.
	 * @param in input stream.
	 * @param pattern a single pattern.
	 * */
    friend istream& operator>>(istream& in, Pattern pattern);

private:
	int class_value_;
	int dimension_;
    vector<double> feature_vector_;
	int index_;

};

#endif /* PATTERN_H_ */

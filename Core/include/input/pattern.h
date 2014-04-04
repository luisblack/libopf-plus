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

namespace opf{

/**Class for handling a single pattern.
 *@see Patterns()
 *
 *\author Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
 *\author Luis Augusto Martins Pereria lmartins@ic.unicamb.br
 *\version 1.0.0
 */


class Pattern{
public:

    /**Defaul constructor for a single pattern.*/
    Pattern();

    /**Creates an instance for labeled patterns.
    * @param class_value class whose the pattern belongs to.
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

    /**Creates an instance for unlabeled patterns.
     * Class value attribute is assinged with -1.
    * @param begin begining of feature vector
    * @param end   ending of feature vector
    * @param index index of pattern.
    * */
    template <typename Iterator> Pattern(Iterator begin, Iterator end, int index)
    {
        class_value_ = -1;
        dimension_ = end - begin;
        set_feature_vector(begin, end);
        index_ = index;
    }

    /**Creates an instance defining a dimension of the feature vector.
    * @param dimension number of feature the vector dimension.
    * */
	Pattern(int dimension);

	/**Destructor for single pattern*/
	~Pattern();

    /**Gets the class value of the pattern
     * @return class value
    */
	int get_class_value() const;

	/**Sets the class value of the pattern
	* @param class_value class value whose the pattern belongs to.
	*/
	void set_class_value(int class_value);

    /**Gets the feature vector of the pattern
     * @return feature vector
    */
    const vector<double> get_feature_vector() const;

	/**Sets the feature vector of the pattern
	* @param feature_vector feature vector that represents the pattern.
	*/
    template<typename Iterator> void set_feature_vector(Iterator begin, Iterator end)
    {
        feature_vector_ = std::vector<double>(begin, end);
    }

    /**Gets the dimension size of feature vector
     * @return number of dimensions
    */
	int get_dimension() const;

	/**Sets the dimension size of feature vector.
	* @param dimension dimension of feature vector.
	*/
	void set_dimension(int dimension);

    /**Gets the index from pattern.
     * @return index from pattern
    */
	int get_index() const;

	/**Sets the index of a pattern.
	* @param index index of the pattern.
	*/
	void set_index(int index);

    /**
     * @brief operator [] Allows a fast reference to read/write feature values
     * @param feature_index The feature index
     * @return The index related feature
     */
    double& operator[](int feature_index)
    {
        return feature_vector_[feature_index];
    }

    friend ostream& operator<<(ostream& in, const Pattern& pattern);

	/**Overloads the operator >> to input stream for a single pattern.
	 * @param in input stream.
     * @param pattern itself.
	 * */
    friend istream& operator>>(istream& in, Pattern& pattern);

private:
	int class_value_;
	int dimension_;
    vector<double> feature_vector_;
	int index_;

};

}

#endif /* PATTERN_H_ */

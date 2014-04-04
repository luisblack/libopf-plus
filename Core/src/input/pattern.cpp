/*
 * Pattern.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */
#include <input/pattern.h>
#include <iostream>
#include <assert.h>

namespace opf{

Pattern::Pattern(): feature_vector_(0){
    class_value_ = 0;
    dimension_ = 0;
    index_ = -1;
}

Pattern::Pattern(int dimension): feature_vector_(dimension){
    class_value_ = 0;
    dimension_ = dimension;
    index_ = -1;
    assert(this!=NULL);
    cout << this << endl;
}

Pattern::~Pattern(){
}

int Pattern::get_class_value() const {
	return class_value_;
}

void Pattern::set_class_value(int class_value) {
	class_value_ = class_value;
}

const vector<double> Pattern::get_feature_vector() const {
	return feature_vector_;
}

int Pattern::get_dimension() const {
	return dimension_;
}

void Pattern::set_dimension(int dimension) {

    feature_vector_.clear();
    feature_vector_.resize(dimension);
    dimension_ = dimension;
}

int Pattern::get_index() const {
	return index_;
}

void Pattern::set_index(int index) {
	index_ = index;
}

ostream& operator<<(ostream& output, const Pattern &pattern)
{
    output << pattern.index_ << " " << pattern.class_value_ << " ";
    copy(pattern.feature_vector_.begin(), pattern.feature_vector_.end(), ostream_iterator<double>(output, " "));
    output << endl;
}

istream& operator>>(istream& in, Pattern &pattern)
{
    in >> pattern.index_;
    in >> pattern.class_value_;

    //std::cout << "Pattern( index=  " << pattern.index_ << ", class= " << pattern.class_value_ << ")\n";
    for (int j = 0; j < pattern.dimension_; ++j) {
        in >> pattern.feature_vector_[j];
    }

//    for (int j = 0; j < pattern.dimension_; ++j) {
//        std::cout << pattern.feature_vector_[j] << ", ";
//    }
    return in;
}

}

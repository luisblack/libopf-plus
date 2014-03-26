/*
 * patterns.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#include <input/patterns.h>
#include <input/pattern.h>

Patterns::Patterns(string file_name) {
    LoadTextFile(file_name);
}

Patterns::Patterns(int number_of_patterns) {
    std::cout << number_of_patterns << " patterns quentinhos saindo ..." << endl;
	number_of_classes_ = 0;
	number_of_patterns_ = number_of_patterns;
    pattern = new Pattern[number_of_patterns];
}

Patterns::~Patterns(){
    //Dica: o destrutor eh chamado automaticamente
    //a menos que seja uma variavel alocada dinamicamente, e neste caso utilizamos o antagonista do new, o delete
	for(int i; i < number_of_patterns_; i++) pattern[i].~Pattern();
}

int Patterns::get_number_of_patterns() const {
	return number_of_patterns_;
}

void Patterns::set_number_of_patterns(int number_of_patterns) {
	number_of_patterns_ = number_of_patterns;
}

int Patterns::get_number_of_classes() const {
	return number_of_classes_;
}

void Patterns::set_number_of_classes(int number_of_classes) {
	number_of_classes_ = number_of_classes;
}

void Patterns::LoadTextFile(string file_name){
    ifstream filein;
    int dimension;

    filein.open(file_name.c_str(), ifstream::in);

    if(filein.is_open()){
        filein >> *this;
        filein.close();
	}else{
        throw "Unable to open file " + file_name;
	}
}


istream& operator >>(istream& input, Patterns &patterns)
{
    int samples_number;

    input >> samples_number >> patterns.number_of_classes_ >> patterns.number_of_patterns_;

    //cout << "Patterns( samples= " << samples_number << ", classes= " << patterns.number_of_classes_ << ", features= " << patterns.number_of_patterns_ << ")\n";

    patterns.pattern = new Pattern[samples_number];

    for(int i=0; i<samples_number; ++i)
    {
        Pattern&p = patterns.pattern[i];
        p.set_dimension(patterns.number_of_patterns_);
        input >> p;
    }
}

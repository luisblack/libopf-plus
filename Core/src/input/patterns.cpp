/*
 * patterns.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#include <input/patterns.h>
#include <input/pattern.h>

#include <exception/opf_exception.h>

Patterns::Patterns(string file_name) {
    load_text_file(file_name);
}

Patterns::Patterns(int number_of_patterns):number_of_patterns_(number_of_patterns), number_of_classes_(0), pattern(number_of_patterns){

}

Patterns::~Patterns(){
    //Dica: o destrutor eh chamado automaticamente
    //a menos que seja uma variavel alocada dinamicamente, e neste caso utilizamos o antagonista do new, o delete
    //for(int i; i < number_of_patterns_; i++) {
    //    delete pattern[i];
    //}
}
int Patterns::get_number_of_patterns() const {
	return number_of_patterns_;
}

void Patterns::set_number_of_patterns(int number_of_patterns) {
	number_of_patterns_ = number_of_patterns;
    pattern.resize(number_of_patterns_);
}

int Patterns::get_number_of_classes() const {
	return number_of_classes_;
}

void Patterns::set_number_of_classes(int number_of_classes) {
	number_of_classes_ = number_of_classes;
}

void Patterns::load_text_file(string file_name){
    ifstream filein;

    filein.open(file_name.c_str(), ifstream::in);

    if(filein.is_open()){
        filein >> *this;
        filein.close();
    }else{
        throw opf::OPFException("Unable to open file " + file_name);
	}
}

ostream& operator <<(ostream& output, Patterns &patterns)
{
    output << patterns.number_of_patterns_ << " " << patterns.number_of_classes_ << " ";

    if(patterns.number_of_patterns_<=0)//there are no samples
    {
        output << 0 << endl;
        return output;
    }

    output << patterns.pattern[0].get_dimension() << endl;

    for(Pattern& p : patterns.pattern)
    {
        output << p;
    }

}

istream& operator >>(istream& input, Patterns &patterns)
{
    int number_of_features;
    try{
        //TODO: ler uma linha de cada vez, para validar linhas.
        input >> patterns.number_of_patterns_ >> patterns.number_of_classes_ >> number_of_features;

        //cout << "Patterns( samples= " << patterns.number_of_patterns_ << ", classes= " << patterns.number_of_classes_ << ", features= " << number_of_features << ")\n";

        patterns.pattern.resize(patterns.number_of_patterns_);

        for(int i=0; i < patterns.number_of_patterns_; ++i)
        {
            Pattern&p = patterns.pattern[i];
            p.set_dimension(patterns.number_of_patterns_);
            input >> p;
        }
    }catch(std::exception e){
        throw opf::OPFException("File in invalid format.");
    }

}

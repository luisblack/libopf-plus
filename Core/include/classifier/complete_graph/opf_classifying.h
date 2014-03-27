#ifndef OPF_CLASSIFYING_H
#define OPF_CLASSIFYING_H

#include<classifier/core/classifying_strategy.h>
#include<vector>

class OPFClassifying:public ClassifyingStrategy{
   OPFClassifying();
   virtual vector<int>predict(Model training_model, Patterns test_patterns);
};

#endif // OPF_CLASSIFYING_H

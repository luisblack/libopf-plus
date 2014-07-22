#include<classifier/complete_graph/opf_classifying.h>
#include<classifier/core/model.h>
#include<limits>

namespace opf{
OPFClassifying::OPFClassifying(){

}

vector<double> OPFClassifying::classify(Model model, Patterns test)
{
    vector<double> classes(test.get_number_of_patterns());

    for (int i = 0; i < classes.size(); ++i) {
        classes[i] = classify(model, test[i]);
    }

    return classes;
}

double OPFClassifying::classify(Model model, Pattern pattern)
{
    double weight = numeric_limits<double>::max();
    double class_value = 0;

    //TO DO: use ordered list of nodes to speed up
    for (ModelNode node : model) {
        double distance = model.distance(node.get_feature_vector(), pattern.get_feature_vector());
        if(distance<weight)
        {
            weight = distance;
            class_value = node.get_class_value();
        }
    }

    return class_value;
}

//vector<double> OPFClassifying::classify(Model model, Patterns test){

//    ModelNode node;
//    double weight, min_cost, tmp;
//    vector<double> predict_classes(test.get_number_of_patterns());


//    for(Patterns::iterator node_test = test.pattern.begin(); node_test != test.pattern.end(); ++node_test){

//        //DUVIDA: como remover da lista
//        node = model.pop_ordered_list_of_nodes();
//        weight = model.distance(node.get_feature_vector(), node_test->get_feature_vector());

//        min_cost = max(node.get_cost(), weight);
//        predict_classes[node_test->get_index()] = node.get_class_value();

////        //DUVIDA: comparação do ponteiro
////        while((node != model.get_ordered_list_of_nodes().end()) && (min_cost > (node+1).get_cost())){

////            weight = model.distance((node+1).get_feature_vector(), node_test->get_feature_vector());
////            tmp = max((node+1).get_cost(), weight);

////            if(tmp < min_cost){
////                min_cost = tmp;
////                predict_classes[node_test.get_index()] = node.get_class_value();
////            }

////            node = node+1;

////        }
//    }
//    return predict_classes;
//}

}

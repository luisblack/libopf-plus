#include<classifier/complete_graph/opf_classifying.h>
#include<classifier/core/model.h>

OPFClassifying::OPFClassifying(){

}

//vector<int> OPFClassifying::predict(Model model, Patterns test){

//    ModelNode* node, prox_node;
//    double weight, min_cost, tmp;
//    vector<int>predict_classes(test.get_number_of_patterns());

//    for(auto node_test = test.pattern.begin(); node_test != test.pattern.end(); ++node_test){
//        node = model.pop_ordered_list_of_nodes();
//        weight = model_training.distance(node.get_feature_vector(), node_test.get_feature_vector());

//        min_cost = max(node.get_cost(), weight);
//        predict_classes[node_test.get_index()] = node.get_class_value();

//        prox_node = model.pop_ordered_list_of_nodes();
//        //duvida ak!!!!!
//        while((node != model.get_ordered_list_of_nodes().end()) && (min_cost > prox_node.get_cost())){

//            weight = model.distance(prox_node.get_feature_vector(), node_test.get_feature_vector());
//            tmp = max(prox_node.get_cost(), weight);

//            if(tmp < min_cost){
//                min_cost = tmp;
//                predict_classes[node_test.get_index()] = node.get_class_value();
//            }

//            node = prox_node;
//            prox_node = model.pop_ordered_list_of_nodes();
//        }
//    }
//    return predict_classes;
//}

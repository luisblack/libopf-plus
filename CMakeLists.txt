cmake_minimum_required(VERSION 2.8.4)
project(libopf_plus)

include_directories(./Core/include/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(libopfplus
    Core/include/classifier/complete_graph/mst_prototype.h
    Core/include/classifier/complete_graph/opf_classifying.h
    Core/include/classifier/complete_graph/opf_training.h
    Core/include/classifier/core/classifier.h
    Core/include/classifier/core/classifying_strategy.h
    Core/include/classifier/core/model.h
    Core/include/classifier/core/model_node.h
    Core/include/classifier/core/opf.h
    Core/include/classifier/core/prototypes_strategy.h
    Core/include/classifier/core/trainer.h
    Core/include/classifier/core/training_strategy.h
    Core/include/exception/invalid_format_exception.h
    Core/include/exception/lazy_programer_exception.h
    Core/include/exception/opf_exception.h
    Core/include/input/csv_format.h
    Core/include/input/io_formater.h
    Core/include/input/io_method.h
    Core/include/input/opf.h
    Core/include/input/pattern.h
    Core/include/input/patterns.h
    Core/include/input/svmlight_format.h
    Core/include/utils/distance.h
    Core/include/utils/indexed_iterator.h
    Core/include/utils/io_utils.h
    Core/include/utils/priority_queue.h
    Core/include/utils/queue_element.h
    Core/include/utils/string_utils.h
    Core/include/libopf-plus.h
    Core/src/classifier/complete_graph/mst_prototype.cpp
    Core/src/classifier/complete_graph/opf_classifying.cpp
    Core/src/classifier/complete_graph/opf_training.cpp
    Core/src/classifier/core/model.cpp
    Core/src/classifier/core/model_node.cpp
    Core/src/classifier/core/opf.cpp
    Core/src/classifier/core/trainer.cpp
    Core/src/exception/invalid_format_exception.cpp
    Core/src/exception/lazy_programer_exception.cpp
    Core/src/exception/opf_exception.cpp
    Core/src/input/csv_format.cpp
    Core/src/input/io_formatter.cpp
    Core/src/input/pattern.cpp
    Core/src/input/patterns.cpp
    Core/src/input/string_utils.cpp
    Core/src/utils/priority_queue.cpp)

add_executable(Main App/main.cpp)
#add_executable(Hue App/hue.cpp)

target_link_libraries(Main libopfplus)
#target_link_libraries(Hue libopfplus)

install (TARGETS Main DESTINATION bin)

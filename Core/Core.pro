#-------------------------------------------------
#
# Project created by QtCreator 2014-03-25T22:30:58
#
#-------------------------------------------------

QT       -= core gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib \
    c++11

INCLUDEPATH += \
    include

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


HEADERS += \
    include/classifier/complete_graph/opf_training.h \
    include/classifier/complete_graph/mst_prototype.h \
    include/classifier/core/training_strategy.h \
    include/classifier/core/trainer.h \
    include/classifier/core/opf.h \
    include/classifier/core/classifying_strategy.h \
    include/classifier/core/classifier.h \
    include/input/patterns.h \
    include/input/pattern.h \
    include/utils/priority_queue.h \
    include/utils/distance.h \
    include/libopf-plus.h \
    include/classifier/core/model.h \
    include/classifier/complete_graph/opf_classifying.h \
    include/classifier/core/model_node.h \
    include/classifier/core/prototypes_strategy.h \
    include/input/io_formater.h \
    include/input/svmlight_format.h \
    include/exception/opf_exception.h \
    include/exception/lazy_programer_exception.h \
    include/utils/string_utils.h \
    include/input/csv_format.h \
    include/exception/invalid_format_exception.h \
    include/utils/queue_element.h

SOURCES += \
    src/input/patterns.cpp \
    src/input/pattern.cpp \
    src/classifier/complete_graph/mst_prototype.cpp \
    src/classifier/core/opf.cpp \
    src/utils/priority_queue.cpp \
    src/classifier/complete_graph/opf_training.cpp \
    src/classifier/core/model.cpp \
    src/classifier/complete_graph/opf_classifying.cpp \
    src/classifier/core/model_node.cpp \
    src/exception/opf_exception.cpp \
    src/exception/lazy_programer_exception.cpp \
    src/input/io_formatter.cpp \
    src/input/csv_format.cpp \
    src/input/string_utils.cpp \
    src/exception/invalid_format_exception.cpp

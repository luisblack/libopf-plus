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
    include/classifier/core/prototype_strategy.h \
    include/classifier/core/opf.h \
    include/classifier/core/classifying_strategy.h \
    include/classifier/core/classifier.h \
    include/input/patterns.h \
    include/input/pattern.h \
    include/utils/priority_queue.h \
    include/utils/distance.h \
    include/libopf-plus.h \
    include/input/file_formats.h \
    include/classifier/core/model.h \
    include/classifier/complete_graph/opf_classifying.h \
    include/classifier/core/model_node.h

SOURCES += \
    src/input/patterns.cpp \
    src/input/pattern.cpp \
    src/classifier/complete_graph/mst_prototype.cpp \
    src/classifier/core/opf.cpp \
    src/input/file_formats.cpp \
    src/utils/priority_queue.cpp \
    src/classifier/complete_graph/opf_training.cpp \
    src/classifier/core/model.cpp \
    src/classifier/complete_graph/opf_classifying.cpp \
    src/classifier/core/model_node.cpp

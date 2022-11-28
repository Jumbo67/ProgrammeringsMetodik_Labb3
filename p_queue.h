//
// Created by vince on 2022-11-26.
//

#ifndef PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
#define PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
#include <iostream>
#include <vector>

template<class T, class Comparator>
class p_queue {

    std::vector<T> que;
    Comparator comp;

public:

    T pop();
    void push(T elem) {
        que.insert();
    }

    int size();
    bool empty();

};



#endif //PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H

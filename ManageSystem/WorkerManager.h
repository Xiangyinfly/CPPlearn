//
// Created by 陈文韬 on 2023/7/19.
//

#ifndef MANAGESYSTEM_WORKERMANAGER_H
#define MANAGESYSTEM_WORKERMANAGER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "Worker.h"

using namespace std;

class WorkerManager {
public:
    Worker **workers;
    int workersNum;

    WorkerManager();

    virtual ~WorkerManager();

    void mainMenu();
    void add();
    void show();
    void remove();
    void update();
    void search();
    void sort();
    void empty();
    void exit();
};


#endif //MANAGESYSTEM_WORKERMANAGER_H

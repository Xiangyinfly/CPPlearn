//
// Created by 陈文韬 on 2023/7/19.
//

#ifndef MANAGESYSTEM_WORKER_H
#define MANAGESYSTEM_WORKER_H

#include <iostream>
#include <string>

using namespace std;

class Worker {
public:
    int id;
    string name;
    int deptId;
    string deptName;

    virtual void showInfo() = 0;
};


#endif //MANAGESYSTEM_WORKER_H

//
// Created by 陈文韬 on 2023/7/19.
//

#ifndef MANAGESYSTEM_MANAGER_H
#define MANAGESYSTEM_MANAGER_H

#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;

class Manager : public Worker{
public:
    Manager(int id,string name);

    void showInfo();

};


#endif //MANAGESYSTEM_MANAGER_H

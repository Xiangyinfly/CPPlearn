//
// Created by 陈文韬 on 2023/7/19.
//

#ifndef MANAGESYSTEM_EMPLOYEE_H
#define MANAGESYSTEM_EMPLOYEE_H

#include <iostream>
#include <string>
#include "Worker.h"

using namespace std;

class Employee : public Worker {
public:
    Employee(int id,string name);

    void showInfo();

};


#endif //MANAGESYSTEM_EMPLOYEE_H

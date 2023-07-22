//
// Created by 陈文韬 on 2023/7/19.
//

#ifndef MANAGESYSTEM_RECORD_H
#define MANAGESYSTEM_RECORD_H

#include <iostream>
#include <string>
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"

class Record {
public:
    static ofstream ofs;
    static ifstream ifs;

    static void save(Worker** workers,int workersNum);
    static void read(Worker** &workers,int &workersNum);

};


#endif //MANAGESYSTEM_RECORD_H

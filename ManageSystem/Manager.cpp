//
// Created by 陈文韬 on 2023/7/19.
//

#include "Manager.h"

Manager::Manager(int id, std::string name) {
    this->id = id;
    this->name = name;
    this->deptId = 2;
    this->deptName = "经理";
}

void Manager::showInfo() {
    cout << "===============员工信息如下===============" << endl;
    cout << "id = " << id << "\t";
    cout << "name = " << name << "\t";
    cout << "deptId = " << deptId << "\t";
    cout << "deptName = " << deptName << endl;
}
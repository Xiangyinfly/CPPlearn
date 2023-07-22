//
// Created by 陈文韬 on 2023/7/19.
//

#include "Employee.h"

Employee::Employee(int id,string name) {
    this->id = id;
    this->name = name;
    this->deptId = 1;
    this->deptName = "员工";
}

void Employee::showInfo() {
    cout << "===============员工信息如下===============" << endl;
    cout << "id = " << id << "\t";
    cout << "name = " << name << "\t";
    cout << "deptId = " << deptId << "\t";
    cout << "deptName = " << deptName << endl;
}
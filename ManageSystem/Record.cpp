//
// Created by 陈文韬 on 2023/7/19.
//

#include "Record.h"

//ofstream Record::ofs("../record.txt",ios::out);
ofstream Record::ofs;
//ifstream Record::ifs("../record.txt",ios::in);
ifstream Record::ifs;

void Record::save(Worker** workers,int workersNum) {
    ofs.open("../record.txt",ios::out);
    ofs << workersNum << endl;
    for (int i = 0; i < workersNum; ++i) {
        ofs << workers[i]->id << " "
            << workers[i]->name << " "
            << workers[i]->deptId << endl;
    }
    ofs.close();
}

void Record::read(Worker** &workers,int &workersNum) {
    ifs.open("../record.txt",ios::in);
    if (!ifs.is_open()) {
        cout << "注册员工信息文件不存在" << endl;
        ifs.close();
        return;
    }
    ifs >> workersNum;
    if (ifs.eof() || workersNum == 0) {
        cout << "注册员工信息文件为空" << endl;
        ifs.close();
        return;
    }

    int id;
    string name;
    int dId;
    int index = 0;
    workers = new Worker* [workersNum];

    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker *worker = NULL;
        if (dId == 1) {
            worker = new Employee(id,name);
        }
        if (dId == 2) {
            worker = new Manager(id,name);
        }

        workers[index ++] = worker;
    }

    ifs.close();
}
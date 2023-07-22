//
// Created by 陈文韬 on 2023/7/19.
//

#include "WorkerManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Record.h"

bool flag = true;

WorkerManager::WorkerManager() {
    workersNum = 0;
    workers = NULL;
    Record::read(workers,workersNum);
}

WorkerManager::~WorkerManager() {
    Record::save(workers,workersNum);
    if (this->workers != NULL) {
        delete[] workers;
    }
}

void WorkerManager::mainMenu() {
    char choice;

    while (flag) {
        cout << "********************************************" << endl;
        cout << "*********  欢迎使用职工管理系统！ **********" << endl;
        cout << "*************  0.退出管理程序  *************" << endl;
        cout << "*************  1.增加职工信息  *************" << endl;
        cout << "*************  2.显示职工信息  *************" << endl;
        cout << "*************  3.删除离职职工  *************" << endl;
        cout << "*************  4.修改职工信息  *************" << endl;
        cout << "*************  5.查找职工信息  *************" << endl;
        cout << "*************  6.按照编号排序  *************" << endl;
        cout << "*************  7.清空所有文档  *************" << endl;
        cout << "********************************************" << endl;
        cout << "请输入您的选择：";

        cin >> choice;
        switch (choice) {
            case '0':
                exit();
                break;
            case '1':
                add();
                break;
            case '2':
                show();
                break;
            case '3':
                remove();
                break;
            case '4':
                update();
                break;
            case '5':
                search();
                break;
            case '6':
                sort();
                break;
            case '7':
                empty();
                break;
            default:
                system("clear");
        }

    }
}

void WorkerManager::add() {
    int addNum = 0;
    int id;
    int key;
    string name;
    cout << "请输入增加的职工数量：";
    cin >> addNum;
    int size = this->workersNum + addNum;

    if (addNum > 0) {
        Worker **newSpace = new Worker *[size];
        for (int i = 0; i < addNum; ++i) {
            cout << "录入第" << i + 1 << "个职工" << endl;
            cout << "请输入id：";
            cin >> id;

            for (int j = 0; j < workersNum; ++j) {
                if (id == workers[i]->id) {
                    cout << "此id已存在，添加失败" << endl;
                    delete[] newSpace;
                    newSpace = NULL;
                    return;
                }
            }

            cout << "请输入name：";
            cin >> name;
            cout << "请选择职工部门(1/2)：" << endl;
            cout << "1. 员工" << endl;
            cout << "2. 经理" << endl;
            cin >> key;
            switch (key) {
                case 1:
                    newSpace[workersNum + i] = new Employee(id,name);
                    break;
                case 2:
                    newSpace[workersNum + i] = new Manager(id,name);
                    break;
                default:
                    cout << "添加失败，请选择1/2" << endl;
                    return;
            }
        }

        for (int i = 0; i < workersNum; ++i) {
            newSpace[i] = workers[i];
        }

        delete[] workers;
        workers = newSpace;
        workersNum = size;
        Record::save(workers,workersNum);

        cout << "添加成功 " << endl;
    } else {
        cout << "添加失败" << endl;
    }
    cout << "按Enter继续..." << endl;
    cin.get();
    system("clear");
}

void WorkerManager::show() {
    if (workersNum == 0) {
        cout << "已注册职工列表为空" << endl;
        system("clear");
        return;
    }
    cout << "===============已注册职工信息===============" << endl;
    cout << "id\t" << "name\t" << "deptId\t" << "deptName\t" << endl;
    for (int i = 0; i < workersNum; ++i) {
        cout << workers[i]->id << "\t"
        << workers[i]->name << "\t"
        << workers[i]->deptId << "\t"
        << workers[i]->deptName << endl;
    }
    cout << "按Enter继续..." << endl;
    cin.get();
    system("clear");
}

void WorkerManager::remove() {
    if (workersNum == 0) {
        cout << "已注册职工列表为空" << endl;
        system("clear");
        return;
    }
    
    int id;
    int index = -1;
    Worker **newSpace = new Worker * [workersNum - 1];
    cout << "请输入职工的id:";
    cin >> id;
    for (int i = 0; i < workersNum; ++i) {
        if (id == workers[i]->id) {
            index = i;
            break;
        } else {
            cout << "查无此人..." << endl;
            delete[] newSpace;
            newSpace = NULL;
            return;
        }
    }

    for (int i = 0; i < index; ++i) {
        newSpace[i] = workers[i];
    }
    for (int i = index + 1; i < workersNum; ++i) {
        newSpace[i - 1] = workers[i];
    }

    delete[] workers;
    workers = newSpace;
    workersNum --;
    Record::save(workers,workersNum);

    cout << "删除成功" << endl;
    cout << "按Enter继续..." << endl;
    cin.get();
    system("clear");
}

void WorkerManager::update() {
    if (workersNum == 0) {
        cout << "已注册职工列表为空" << endl;
        system("clear");
        return;
    }
    
    int id;
    int index = -1;
    bool flag = false;
    cout << "请输入要修改数据的员工的id：";
    cin >> id;

    for (int i = 0; i < workersNum; ++i) {
        if (workers[i]->id == id) {
            index = i;
            flag = true;
            break;
        }
    }

    if (index == -1) {
        cout << "查无此人..." << endl;
        return;
    }

    while (flag) {
        char key = '0';
        bool flag1 = true;

        cout << "请输入需要修改的项：" << endl;
        cout << "1.id" << endl;
        cout << "2.name" << endl;
        cout << "3.deptId" << endl;
        cout << "4.退出修改" << endl;
        cin >> key;

        switch (key) {
            case '1':
                int nId;
                while (flag1) {
                    flag1 = false;
                    cout << "请输入修改后的id：";
                    cin >> nId;
                    for (int i = 0; i < workersNum; ++i) {
                        if (workers[i]->id == nId || nId <= 0) {
                            cout << "修改失败，不能使用该id" << endl;
                            flag1 = true;
                            break;
                        }
                    }
                }
                workers[index]->id = nId;
                cout << "修改成功" << endl;
                 break;
            case '2':
                cout << "请输入修改后的name：";
                cin >> workers[index]->name;
                cout << "修改成功" << endl;
                break;
            case '3':
                int ndId;
                cout << "请输入修改后的deptId（1/2）：";
                cin >> ndId;
                if (ndId == 1) {
                    workers[index]->deptId = 1;
                    workers[index]->deptName = "员工";
                    cout << "修改成功" << endl;
                } else if (ndId == 2) {
                    workers[index]->deptId = 2;
                    workers[index]->deptName = "经理";
                    cout << "修改成功" << endl;
                } else {
                    cout << "修改失败，请输入1/2" << endl;
                }
                break;
            case '4':
                flag = false;
                cout << "退出修改..." << endl;
                break;
            default:
                cout << "请输入1-4" << endl;
        }
    }

    Record::save(workers,workersNum);
    cout << "按Enter继续..." << endl;
    cin.get();
    system("clear");
}

void WorkerManager::search() {
    if (workersNum == 0) {
        cout << "已注册职工列表为空" << endl;
        system("clear");
        return;
    }
    
    int id;
    int index = -1;
    cout << "输入查找员工的id：";
    cin >> id;

    for (int i = 0; i < workersNum; ++i) {
        if (id == workers[i]->id) {
            index = i;
            cout << "============信息如下============" << endl;
            workers[i]->showInfo();
            break;
        }
    }
    if (index == -1) {
        cout << "查无此人..." << endl;
    }

    cout << "按Enter继续..." << endl;
    cin.get();
    system("clear");
}

void WorkerManager::sort() {
    if (workersNum == 0) {
        cout << "已注册职工列表为空" << endl;
        system("clear");
        return;
    }
    
    int* ids = new int[workersNum];
    for (int i = 0; i < workersNum; ++i) {
        ids[i] = workers[i]->id;
    }

    for (int i = 0; i < workersNum - 1; ++i) {
        for (int j = i + 1; j < workersNum; ++j) {
            if (ids[i] > ids[j]) {
                int temp = ids[i];
                ids[i] = ids[j];
                ids[j] = temp;
            }
        }
    }

    cout << "=============排序后已注册员工信息=============" << endl;
    cout << "id\t" << "name\t" << "deptId\t" << "deptName\t" << endl;
    for (int i = 0; i < workersNum; ++i) {
        for (int j = 0; j < workersNum; ++j) {
            if (ids[i] == workers[j]->id) {
                cout << workers[j]->id << "\t"
                     << workers[j]->name << "\t"
                     << workers[j]->deptId << "\t"
                     << workers[j]->deptName << endl;
            }
        }
    }

    delete[] ids;
    cout << "按Enter继续..." << endl;
    cin.get();
    system("clear");
}

void WorkerManager::empty() {
    if (workersNum == 0) {
        cout << "已注册职工列表为空" << endl;
        system("clear");
        return;
    }
    
    char key;
    bool flag = true;

    while (flag) {
        flag = false;
        cout << "确定要清空已注册员工信息y/n？";
        cin >> key;
        switch (key) {
            case 'y':
                delete[] workers;
                workers = NULL;
                workersNum = 0;
                Record::save(workers,workersNum);
                cout << "已清空" << endl;
                break;
            case 'n':
                break;
            default:
                flag = true;
                cout << "请输入y/n" << endl;
        }
    }

    cout << "按Enter继续..." << endl;
    cin.get();
    system("clear");
}

void WorkerManager::exit() {
    char key;
    cout << "确认要退出吗(y/n):";
    cin >> key;
    if (key == 'y') {
        flag = false;
        return;
    }
    system("clear");
}

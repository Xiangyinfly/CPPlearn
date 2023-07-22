#include <iostream>
#include <string>

#include "WorkerManager.h"

int main() {
    WorkerManager workerManager;
    workerManager.mainMenu();
}


/**
 * q1:cin接收char的时候如果接收两个字符，会第一次接收一个，第二次接收上次输入的第二个，如何解决
 * 接收int如果输入字符，int会自动置为0，是一个特性吗
 * q2:所有试图暂停界面的，如getchar，cin.get都无法暂停
 * q3:初始化ifs/ofs的时候直接打开文件会导致文件清空，为什么
 * 现在通过在调用方法的时候open()来解决
 * q4:指向 元素为指针的数组 的指针作为参数传递不能改变原数组？例如read()传递**workers不可以
*/
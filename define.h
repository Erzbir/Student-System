//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_DEFINE_H
#define SYS_2_DEFINE_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

#define USER_FILE "./user.txt" // 用户信息路径
#define STU_FILE "./stu.txt"    // 学生信息路径
#define USER_SIZE 20    // 最大用户数量
#define STU_SIZE 10000  // 最大学生数据连续输入量
#define PAUSE "read"// MacOS系统任意键继续
//#define PAUSE "pause" // Windows系统任意键继续
StuNode *head;          // 头节点
Users User[USER_SIZE];  // 存储用户信息
int size = 0;           // 当前用户数量
int size_2 = 0;         // 当前学生数量

#endif //SYS_2_DEFINE_H

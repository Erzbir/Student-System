//
// Created by Erzbir on 2022/5/9.
//

#ifndef SYS_STRUCT_HEAD_H
#define SYS_STRUCT_HEAD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    long int num;
    char name[20];
    float score[3];
    float aver;
    float sum;
} Student;

typedef struct Users {
    char account[16];
    char password[16];
    int type;   //权限标记,0为管理员,1为普通用户
} Users;

//typedef struct UserNode{
//    Users data;
//    struct UserNode *next;
//}UserNode;
//
//typedef struct StuNode{
//    Student data;
//    struct StuNode *next;
//}StuNode;
#endif //SYS_STRUCT_HEAD_H


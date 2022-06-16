//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_STRUCT_H
#define SYS_2_STRUCT_H


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

typedef struct StuNode {
    Student data;
    struct StuNode *next;
    struct StuNode *pre;
} StuNode;

#endif //SYS_2_STRUCT_H

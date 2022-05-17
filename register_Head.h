//
// Created by Erzbir on 2022/5/9.
//
#include "data_wr_Head.h"

#ifndef SYS_REGISTER_HEAD_H
#define SYS_REGISTER_HEAD_H

#include <string.h>

int Register(Users *User, const int SIZE) {
    int size = 1;
    if(!(User_count_r(&size))){
        return -1;
    }
    int n;
    char account[16], password[16], password_sure[16];
    printf("输入用户名:");
    scanf("%s", account);
    for (n = 0; n < SIZE - 1; n++) {
        if (strcmp(User[n].account, account) == 0) {
            printf("\n用户已存在\n");
            return 0;
        }
    }
    printf("输入密码:");
    scanf("%s", password);
    printf("确认密码:");
    scanf("%s", password_sure);
    if (strcmp(password_sure, password) == 0) {
        strcpy(User[size - 1].account, account);
        strcpy(User[size - 1].password, password);
        User[size - 1].type = 1;
        size++;
        if (!(User_data_w(User, size))) {
            return -1;
        }
        if (!(User_count_w(&size))) {
            return -1;
        }
    } else {
        printf("\n两次密码不同\n");
        return 0;
    }
    printf("\n注册成功\n");
    return 1;
}

#endif //SYS_REGISTER_HEAD_H


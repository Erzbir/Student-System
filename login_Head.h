//
// Created by Erzbir on 2022/5/9.
//
#include <string.h>

#ifndef SYS_LOGIN_HEAD_H
#define SYS_LOGIN_HEAD_H

int Login(Users *User, const int SIZE) {
    int n;
    char account[16], password[16];
    printf("输入帐号:");
    scanf("%s", account);
    printf("输入密码:");
    scanf("%s", password);
    for (n = 0; n < SIZE; n++) {
        if (strcmp(User[n].account, account) == 0 && strcmp(User[n].password, password) == 0) {
            printf("\n登录成功\n");
            return n;
        }
    }
    return -1;
}

#endif //SYS_LOGIN_HEAD_H


//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_LOGIN_H
#define SYS_2_LOGIN_H

#include <string.h>
#include "define.h"
#include <stdio.h>

int Login() {
    int n;
    char account[16], password[16];
    printf("输入帐号:");
    scanf("%s", account);
    printf("输入密码:");
    scanf("%s", password);
    for (n = 0; n < USER_SIZE; n++) {
        if (strcmp(User[n].account, account) == 0 && strcmp(User[n].password, password) == 0) {
            printf("\n登录成功\n");
            system(PAUSE);
            return n;
        }
    }
    return 0;
}

#endif //SYS_2_LOGIN_H

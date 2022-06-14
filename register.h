//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_REGISTER_H
#define SYS_2_REGISTER_H

#include <string.h>
#include "define.h"
#include "serialization.h"


int Register() {
    int n;
    char account[16], password[16], password_sure[16];
    printf("输入用户名:");
    scanf("%s", account);
    for (n = 0; n < USER_SIZE - 1; n++) {
        if (strcmp(User[n].account, account) == 0) {
            printf("\n用户已存在\n");
            system(PAUSE);
            return 0;
        }
    }
    printf("输入密码:");
    scanf("%s", password);
    printf("确认密码:");
    scanf("%s", password_sure);
    if (strcmp(password_sure, password) == 0) {
        strcpy(User[size].account, account);
        strcpy(User[size].password, password);
        User[size].type = 1;
        size++;
        if (!(User_data_w())) {
            return -1;
        }
    } else {
        printf("\n两次密码不同\n");
        system(PAUSE);
        return 0;
    }
    printf("\n注册成功\n");
    system(PAUSE);
    return 1;
}

#endif //SYS_2_REGISTER_H

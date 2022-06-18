//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_REGISTER_H
#define SYS_2_REGISTER_H

#include <string.h>
#include "serialization.h"


int Register() {
    int n;
    char account[16], password[16], password_sure[16];
    printf("Enter username:");
    scanf("%s", account);
    for (n = 0; n < USER_SIZE - 1; n++) {
        if (strcmp(User[n].account, account) == 0) {
            printf("\nUser has existed\n");
            system(PAUSE);
            return 0;
        }
    }
    printf("Enter password:");
    scanf("%s", password);
    printf("Sure password:");
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
        printf("\nTwo passwords are not same\n");
        system(PAUSE);
        return 0;
    }
    printf("\nRegistered Successfully\n");
    system(PAUSE);
    return 1;
}

#endif //SYS_2_REGISTER_H

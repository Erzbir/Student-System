//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_GETADMIN_H
#define SYS_2_GETADMIN_H

#include "serialization.h"
#include <string.h>

int Admin(int index) {
    char passwd[16];
    char passwd_admin[16];
    strcpy(passwd_admin, "123456");
    printf("Enter admin password:");
    scanf("%s", passwd);
    if (strcmp(passwd, passwd_admin) == 0) {
        User[index].type = 0;
        if (User_data_w(User) == -1) {
            return 0;
        }
        printf("\nPermission Obtained Successfully\n");
        system(PAUSE);
    } else {
        printf("\nWrong password\n");
        system(PAUSE);
        return 0;
    }
    return 1;
}

#endif //SYS_2_GETADMIN_H

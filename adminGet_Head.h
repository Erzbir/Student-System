//
// Created by Erzbir on 2022/5/13.
//


#ifndef SYS_ADMINGET_HEAD_H
#define SYS_ADMINGET_HEAD_H

int Admin(const int SIZE, int index) {
    char passwd[16];
    char passwd_admin[16];
    Users User[SIZE];
    strcpy(passwd_admin, "123456");
    if (!(User_data_r(User, SIZE))) {
        return -1;
    }
    printf("输入管理员密码:");
    scanf("%s", passwd);
    if (strcmp(passwd, passwd_admin) == 0) {
        User[index].type = 0;
        if(!(User_data_w(User, SIZE)))
        {
            return -1;
        }
        printf("\n权限获取成功\n");
    } else {
        printf("\n密码错误\n");
        getchar();
        return 0;
    }
    return 1;
}

#endif //SYS_ADMINGET_HEAD_H

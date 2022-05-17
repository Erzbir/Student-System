//
// Created by Erzbir on 2022/5/14.
//

//检查权限

#ifndef SYS_CHECK_HEAD_H
#define SYS_CHECK_HEAD_H


int Check(const int SIZE, int index) {
    Users User[SIZE];
    if (!(User_data_r(User, SIZE))) {
        return -1;
    }
    if (User[index].type == 0) {
        return 1;
    }
    return -1;
}

#endif //SYS_CHECK_HEAD_H

//
// Created by Erzbir on 2022/5/14.
//

//检查权限

#ifndef SYS_CHECK_HEAD_H
#define SYS_CHECK_HEAD_H


int Check(Users *User, int index) {
    if (User[index].type == 0) {
        return 1;
    }
    return -1;
}

#endif //SYS_CHECK_HEAD_H

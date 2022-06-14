//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_CHECKADMIN_H
#define SYS_2_CHECKADMIN_H

#include "define.h"

int Check(int index) {
    if (User[index].type == 0) {
        return 1;
    }
    return -1;
}

#endif //SYS_2_CHECKADMIN_H

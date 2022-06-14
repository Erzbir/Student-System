//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_DELETE_H
#define SYS_2_DELETE_H
#include <stdlib.h>
#include "find.h"

int Delete() {
    long int num;
    char select;
    StuNode *L;
    while (1) {
        printf("需要删除的学生学号:");
        scanf("%ld", &num);
        if(!(L = Scan(num))){
            return 0;
        }
        printf("是否确定删除(y/n):");
        scanf("%s", &select);
        if (select == 'n' || select == 'N') {
            return 0;
        }
        else if (select == 'y' || select == 'Y') {
            L->pre->next = L->next;
            L->pre = NULL;
            free(L);
            size_2--;
            printf("\n删除成功\n");
            system(PAUSE);
        } else {
            printf("\n重新输入\n");
            system(PAUSE);
            break;
        }
        printf("是否继续(y/n):");
        scanf("%s", &select);
        if (select == 'N' || select == 'n') {
            if (!(Stu_data_w())) {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

#endif //SYS_2_DELETE_H

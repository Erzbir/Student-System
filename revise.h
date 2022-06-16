//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_REVISE_H
#define SYS_2_REVISE_H

#include "find.h"

int Revise() {
    long int num = 0;
    char select = 0;
    StuNode *L = NULL;
    while (1) {
        printf("输入学号:");
        scanf("%ld", &num);
        if (!(L = Scan(num))) {
            return 0;
        }
        printf("1.姓名\n2.成绩\n");
        printf("输入要修改的数据的序号:");
        scanf("%s", &select);
        if (select == '1') {
            printf("修改姓名:");
            scanf("%s", L->data.name);
            printf("\n修改成功\n");
            system(PAUSE);
        } else if (select == '2') {
            printf("修改第一科成绩:");
            scanf("%f", &L->data.score[0]);
            printf("修改第二科成绩:");
            scanf("%f", &L->data.score[1]);
            printf("修改第三科成绩:");
            scanf("%f", &L->data.score[2]);
            L->data.sum = L->data.score[0] + L->data.score[1] + L->data.score[2];
            L->data.aver = L->data.sum / 3;
            printf("\n修改成功\n");
            system(PAUSE);
        } else {
            printf("\n重新输入\n");
            system(PAUSE);
            break;
        }
        printf("是否继续(y/n):");
        scanf("%s", &select);
        if (select == 'N' || select == 'n') {
            if (!Stu_data_w()) {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

#endif //SYS_2_REVISE_H

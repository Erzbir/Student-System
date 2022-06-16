//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_FIND_H
#define SYS_2_FIND_H

#include "define.h"

StuNode *Scan(long int item) {
    char select = 0;
    StuNode *L = head->next, *P = head->pre;
    while (L) {
        if (L->data.num == item) {
            while (1) {
                printf("已查询到该学生,是否打印其信息(y/n):");
                scanf("%s", &select);
                if (select == 'y' || select == 'Y') {
                    printf("学号:%ld, 姓名:%s   第一科成绩:%.2f, 第二科成绩:%.2f, "
                           "第三科成绩:%.2f  总分:%.2f 平均分:%.2f\n",
                           L->data.num, L->data.name, L->data.score[0],
                           L->data.score[1], L->data.score[2], L->data.sum, L->data.aver);
                    printf("\n查询成功\n");
                    system(PAUSE);
                    return L;
                } else if (select == 'N' || select == 'n') {
                    return L;
                } else {
                    printf("\n重新输入\n");
                    system(PAUSE);
                }
            }
        }
        if (P->data.num == item) {
            while (1) {
                printf("已查询到该学生,是否打印其信息(y/n):");
                scanf("%s", &select);
                if (select == 'y' || select == 'Y') {
                    printf("学号:%ld, 姓名:%s   第一科成绩:%.2f, 第二科成绩:%.2f, "
                           "第三科成绩:%.2f  总分:%.2f 平均分:%.2f\n",
                           P->data.num, P->data.name, P->data.score[0],
                           P->data.score[1], P->data.score[2], L->data.sum, P->data.aver);
                    printf("\n查询成功\n");
                    return P;
                } else if (select == 'N' || select == 'n') {
                    return P;
                } else {
                    printf("\n重新输入\n");
                }
            }
        }
        L = L->next;
        P = P->pre;
    }
    printf("\n未查询到该学生\n");
    return 0;
}

#endif //SYS_2_FIND_H

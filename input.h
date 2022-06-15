//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_INPUT_H
#define SYS_2_INPUT_H

#include "define.h"
#include "serialization.h"

int Input() {
    int n, i;
    long int num;
    StuNode *s, *L = head;
    for (n = 0; n < STU_SIZE; n++) {
        s = (StuNode *) malloc(sizeof(StuNode));
        if (!s) {
            return 0;
        }
        printf("输入第%d个学生信息(学号,姓名)(-1结束):", n + 1);
        scanf("%ld, %s", &num, s->data.name);
        if (num < 0) {
            break;
        }
        s->data.num = num;
        for (i = 0; i < 3; i++) {
            printf("输入第%d科成绩:", i + 1);
            scanf("%f", &s->data.score[i]);
        }
        s->data.sum = s->data.score[0] + s->data.score[1] + s->data.score[2];
        s->data.aver = s->data.sum / 3;
        L->next = s;
        s->pre = L;
        L = L->next;
        size_2++;
    }
    head->pre = L;
    L->next = NULL;
    if (!(Stu_data_a())) {
        return 0;
    }
    if (!(Stu_data_r())) {
        return 0;
    }
    printf("\n录入成功\n");
    system(PAUSE);
    return 1;
}

#endif //SYS_2_INPUT_H
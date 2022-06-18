//
// Created by Erzbir on 2022/6/18.
//

#ifndef SYS_2_MAX_H
#define SYS_2_MAX_H

#include "define.h"

StuNode *Max() {
    StuNode *L = head->next, *P = head->pre, *s;
    if (!L) {
        return NULL;
    }
    while (L->next) {
        if (L->data.sum > P->data.sum) {
            s = L;
        }
        L = L->next;
        P = P->pre;
    }
    printf("\nID:%ld, name:%s, score_1:%.2f, score_2:%.2f, "
           "score_3:%.2f, total_score:%.2f, average_score:%.2f\n",
           s->data.num, s->data.name, s->data.score[0],
           s->data.score[1], s->data.score[2], s->data.sum, s->data.aver);
    return s;
}

#endif //SYS_2_MAX_H

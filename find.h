//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_FIND_H
#define SYS_2_FIND_H

#include "define.h"

StuNode *Scan(long int item) {
    char select = 0;
    StuNode *L = head->next, *P = head->pre;
    if (!L) {
        return 0;
    }
    while (L->next) {
        if (L->data.num == item) {
            while (1) {
                printf("Already found student, do you want to display?(y/n):");
                scanf("%s", &select);
                if (select == 'y' || select == 'Y') {
                    printf("\nID:%ld, name:%s, score_1:%.2f, score_2:%.2f, "
                           "score_3:%.2f, total_score:%.2f, average_score:%.2f\n",
                           L->data.num, L->data.name, L->data.score[0],
                           L->data.score[1], L->data.score[2], L->data.sum, L->data.aver);
                    printf("\nSearched Successfully\n");
                    system(PAUSE);
                    return L;
                } else if (select == 'N' || select == 'n') {
                    return L;
                } else {
                    printf("\nPlease re-enter\n");
                }
            }
        }
        if (P->data.num == item) {
            while (1) {
                printf("Already found student, do you want to display?(y/n):");
                scanf("%s", &select);
                if (select == 'y' || select == 'Y') {
                    printf("\nID:%ld, name:%s, score_1:%.2f, score_2:%.2f, "
                           "score_3:%.2f, total_score:%.2f, average_score:%.2f\n",
                           P->data.num, P->data.name, P->data.score[0],
                           P->data.score[1], P->data.score[2], L->data.sum, P->data.aver);
                    printf("\nSearched Successfully\n");
                    system(PAUSE);
                    return P;
                } else if (select == 'N' || select == 'n') {
                    return P;
                } else {
                    printf("\nPlease re-enter\n");
                }
            }
        }
        L = L->next;
        P = P->pre;
    }
    printf("\nStudent Did Not Found\n");
    system(PAUSE);
    return 0;
}

#endif //SYS_2_FIND_H

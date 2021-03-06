//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_OUTPUT_H
#define SYS_2_OUTPUT_H

#include "serialization.h"

int Print() {
    StuNode *L = head->next;
    if (!L) {
        return 0;
    }
    int n = 0, num_1 = size_2, num_2 = 1, i = 0;
    printf("Enter the number to display:");
    scanf("%d", &num_2);
    i = (num_2 >= num_1) ? num_1 - 1 : num_2; // judge how much student will be displayed
    if (i > 0) {
        printf("\n");
        for (; n < i; n++) {
            printf("ID:%ld, name:%s, score_1:%.2f, score_2:%.2f, "
                   "score_3:%.2f, total_score:%.2f, average_score:%.2f\n",
                   L->data.num, L->data.name, L->data.score[0],
                   L->data.score[1], L->data.score[2], L->data.sum, L->data.aver);
            L = L->next;
        }
        printf("\nDisplay Successfully\n");
        system(PAUSE);
    }
    return 1;
}

#endif //SYS_2_OUTPUT_H

//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_SORT_H
#define SYS_2_SORT_H

#include "define.h"

int Sort() {
    int n = 0, m, size_3 = 0;
    int select = 0;
    Student Stu[1000], tmp;
    StuNode *L = head->next, *P = head->next;
    if (L == NULL) {
        return -1;
    }
    while (L->next) {
        Stu[n] = L->data;
        L = L->next;
        n++;
        size_3++;
    }
    printf("1.sumScore.sort\n2.averScore.sort\n3.ID.sort\nEnter your choice:");
    scanf("%d", &select);
    if (select == 1) {
        for (n = 0; n < size_3 - 1; n++) {
            for (m = 0; m < size_3 - n - 1; m++) {
                if (Stu[m].sum < Stu[m + 1].sum) {
                    tmp = Stu[m];
                    Stu[m] = Stu[m + 1];
                    Stu[m + 1] = tmp;
                }
            }
        }
    } else if (select == 2) {
        for (n = 0; n < size_3 - 1; n++) {
            for (m = 0; m < size_3 - n - 1; m++) {
                if (Stu[m].aver < Stu[m + 1].aver) {
                    tmp = Stu[m];
                    Stu[m] = Stu[m + 1];
                    Stu[m + 1] = tmp;
                }
            }
        }
    } else if (select == 3) {
        for (n = 0; n < size_3 - 1; n++) {
            for (m = 0; m < size_3 - n - 1; m++) {
                if (Stu[m].num > Stu[m + 1].num) {
                    tmp = Stu[m];
                    Stu[m] = Stu[m + 1];
                    Stu[m + 1] = tmp;
                }
            }
        }
    } else {
        printf("\nPlease re-enter\n");
        system(PAUSE);
    }
    for (n = 0; P->next; n++) {
        P->data = Stu[n];
        P = P->next;
    }
    if (!(Stu_data_w())) {
        return 0;
    }
    printf("\nSorted Successfully\n");
    system(PAUSE);
    return 1;
}

#endif //SYS_2_SORT_H

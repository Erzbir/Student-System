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
        printf("Enter ID:");
        scanf("%ld", &num);
        if (!(L = Scan(num))) {
            return 0;
        }
        printf("1.Name\n2.Score\n");
        printf("Enter your choice:");
        scanf("%s", &select);
        if (select == '1') {
            printf("Revise name:");
            scanf("%s", L->data.name);
            printf("\nRevised Successfully\n");
            system(PAUSE);
        } else if (select == '2') {
            printf("Revise No.1 score:");
            scanf("%f", &L->data.score[0]);
            printf("Revise No.2 score:");
            scanf("%f", &L->data.score[1]);
            printf("Revise No.3 score:");
            scanf("%f", &L->data.score[2]);
            L->data.sum = L->data.score[0] + L->data.score[1] + L->data.score[2];
            L->data.aver = L->data.sum / 3;
            printf("\nRevised Successfully\n");
            system(PAUSE);
        } else {
            printf("\nPlease re-enter\n");
            system(PAUSE);
            break;
        }
        printf("Whether to continue?(y/n):");
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

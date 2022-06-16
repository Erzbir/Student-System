//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_DELETE_H
#define SYS_2_DELETE_H

#include <stdlib.h>
#include "find.h"

int Delete() {
    long int num = 0;
    char select = 0;
    StuNode *L = NULL;
    while (1) {
        printf("The ID you want to delete:");
        scanf("%ld", &num);
        if (!(L = Scan(num))) {
            return 0;
        }
        printf("Sure to delete?(y/n):");
        scanf("%s", &select);
        if (select == 'n' || select == 'N') {
            return 0;
        } else if (select == 'y' || select == 'Y') {
            L->pre->next = L->next;
            L->pre = NULL;
            free(L);
            size_2--;
            printf("\nDeleted Successfully\n");
            system(PAUSE);
        } else {
            printf("\nPlease re-enter\n");
            system(PAUSE);
            break;
        }
        printf("Whether to continue?(y/n):");
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

//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_INPUT_H
#define SYS_2_INPUT_H

#include "serialization.h"

int Input() {
    short int n = 0, i = 0;
    long int num = 0;
    StuNode *s = NULL, *L = head;
    for (n = 0; n < STU_SIZE; n++) {
        int flag = 1; // a qualification
        s = (StuNode *) malloc(sizeof(StuNode));
        if (!s) {
            return 0;
        }
        printf("Enter No.%d student info(ID,Name)(-1 to exit):", n + 1);
        scanf("%ld, %s", &num, s->data.name);
        //this is a qualification to judge exit or continue
        if (num < 0) {
            free(s);
            s = NULL;
            break;
        }
        StuNode *temp = head; // when begin verify, temp points to head
        //to make sure ID is unique
        if (temp) {
            while (temp) {
                if (num == temp->data.num) {
                    printf("Student has existed\n");
                    flag = 0;
                }
                temp = temp->next;
            }
        }
        if (!flag) {
            free(s);
            s = NULL;
            n--;
            continue;
        }
        s->data.num = num;
        for (i = 0; i < 3; i++) {
            printf("Enter No.%d score:", i + 1);
            scanf("%f", &s->data.score[i]);
        }
        s->data.sum = s->data.score[0] + s->data.score[1] + s->data.score[2];
        s->data.aver = s->data.sum / 3;
        L->next = s;
        s->pre = L;
        s->next = NULL;
        L = s;
        size_2++;
    }
    L->next = NULL; // this is useless you can delete that is I want you to understand these code
    head->pre = L; // the head points to the rear
    if (!(Stu_data_a())) {
        return 0;
    }
    if (!(Stu_data_r())) {
        return 0;
    }
    printf("\nInput Successfully\n");
    system(PAUSE);
    return 1;
}

#endif //SYS_2_INPUT_H

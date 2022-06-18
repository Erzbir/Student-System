//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_SERIALIZATION_H
#define SYS_2_SERIALIZATION_H

#include "define.h"

//read student data
int Stu_data_r() {
    StuNode *L = head, *s = NULL;
    FILE *file = NULL;
    if (!(file = fopen(STU_FILE, "rb"))) {
        printf("\nFailed to Open student.IOStream\n");
        system(PAUSE);
        return 0;
    }
    while (!feof(file)) {
        if (!(s = (StuNode *) malloc(sizeof(StuNode)))) {
            return 0;
        }
        fread(&s->data, sizeof(Student), 1, file);
        L->next = s;
        s->pre = L;
        s->next = NULL;
        L = s;
    }
    fclose(file);
    head->pre = L->pre;
    return 1;
}

//read user data
int User_data_r() {
    int n = 0;
    FILE *file = NULL;
    if (!(file = fopen(USER_FILE, "rb"))) {
        printf("\nFailed to Open user.IOStream\n");
        system(PAUSE);
        return 0;
    }
    while (!feof(file)) {
        fread(&User[n], sizeof(Users), 1, file);
        size++;
        n++;
    }
    fclose(file);
    return 1;
}

//save student data
int Stu_data_a() {
    StuNode *L = head->next;
    FILE *file = NULL;
    if (!(file = fopen(STU_FILE, "ab"))) {
        printf("\nFailed to Open student.IOStream\n");
        system(PAUSE);
        return 0;
    }
    while (L) {
        fwrite(&L->data, sizeof(Student), 1, file);
        L = L->next;
    }
    fclose(file);
    return 1;
}

//save student data
int Stu_data_w() {
    StuNode *L = head->next;
    FILE *file = NULL;
    if (!(file = fopen(STU_FILE, "wb"))) {
        printf("\nFailed to Open student.IOStream\n");
        system(PAUSE);
        return 0;
    }
    while (L->next) {
        fwrite(&L->data, sizeof(Student), 1, file);
        L = L->next;
    }
    fclose(file);
    return 1;
}

//save user data
int User_data_w() {
    int n;
    FILE *file = NULL;
    if ((file = fopen(USER_FILE, "wb")) == NULL) {
        printf("\nFailed to Open student.IOStream\n");
        system(PAUSE);
        return 0;
    }
    for (n = 0; n < USER_SIZE; n++) {
        fwrite(&User[n], sizeof(Users), 1, file);
    }
    fclose(file);
    return 1;
}


#endif //SYS_2_SERIALIZATION_H

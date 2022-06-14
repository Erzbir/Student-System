//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_SERIALIZATION_H
#define SYS_2_SERIALIZATION_H

#include "define.h"

//读取学生数据
int Stu_data_r() {
    StuNode *L = head, *s;
    FILE *file;
    if (!(file = fopen(STU_FILE, "rb"))) {
        printf("\n学生信息读取失败\n");
        system(PAUSE);
        return 0;
    }
    while(!feof(file)) {
        if(!(s = (StuNode*) malloc(sizeof(StuNode)))){
            return 0;
        }
        fread(&s->data, sizeof(Student), 1, file);
        L->next = s;
        s->pre = L;
        L = L->next;
    }
    fclose(file);
    head->pre = L;
    L->next = NULL;
    return 1;
}

//读取用户数据
int User_data_r() {
    int n = 0;
    FILE *file;
    if (!(file = fopen(USER_FILE, "rb"))) {
        printf("\n用户信息读取失败\n");
        system(PAUSE);
        return 0;
    }
    while(!feof(file)) {
        fread(&User[n], sizeof(Users), 1, file);
        size++;
        n++;
    }
    fclose(file);
    return 1;
}

//保存学生数据
int Stu_data_a() {
    StuNode *L = head->next;
    FILE *file;
    if (!(file = fopen(STU_FILE, "ab"))) {
        printf("\n学生信息读取失败\n");
        system(PAUSE);
        return 0;
    }
    while(L) {
        fwrite(&L->data, sizeof(Student), 1, file);
        L = L->next;
    }
    fclose(file);
    return 1;
}

int Stu_data_w() {
    StuNode *L = head->next;
    FILE *file;
    if (!(file = fopen(STU_FILE, "wb"))) {
        printf("\n学生信息读取失败\n");
        system(PAUSE);
        return 0;
    }
    while(L) {
        fwrite(&L->data, sizeof(Student), 1, file);
        L = L->next;
    }
    fclose(file);
    return 1;
}

//保存用户数据
int User_data_w() {
    int n;
    FILE *file;
    if ((file = fopen(USER_FILE, "wb")) == NULL) {
        printf("\n用户信息读取失败\n");
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

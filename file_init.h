//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_FILE_INIT_H
#define SYS_2_FILE_INIT_H

#include "define.h"
#include "serialization.h"

int FileInit(){
    FILE *file = NULL;
    StuNode *L;
    L = (StuNode*) malloc(sizeof(StuNode));
    if(!(file = fopen(USER_FILE, "ab"))){
        return 0;
    }
    fclose(file);
    if(!(file = fopen(STU_FILE, "ab"))) {
        return 0;
    }
    fclose(file);
    if(!(file = fopen(STU_FILE, "rb"))){
        return 0;
    }
    while(!feof(file)){
        fread(&L->data, sizeof(Student), 1, file);
        size_2++;
    }
    fclose(file);
    if (!(Stu_data_r())) {
        return 0;
    }
    if (!(User_data_r())) {
        return 0;
    }
    return 1;
}

#endif //SYS_2_FILE_INIT_H

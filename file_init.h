//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_FILE_INIT_H
#define SYS_2_FILE_INIT_H

#include "serialization.h"

int FileInit() {
    FILE *file = NULL;
    StuNode *L = NULL; // just is a point to record size
    L = (StuNode *) malloc(sizeof(StuNode));
    if (!(file = fopen(USER_FILE, "ab"))) {
        return 0;
    }
    fclose(file);
    if (!(file = fopen(STU_FILE, "ab"))) {
        return 0;
    }
    fclose(file);
    // the above is only create file. Why use "ab"? Because use "wb" will cover file to block.

    if (!(file = fopen(STU_FILE, "rb"))) {
        return 0;
    }
    while (!feof(file)) {
        fread(&L->data, sizeof(Student), 1, file);
        size_2++; // this "while" is just count how much student data in file
    }
    fclose(file);
    free(L); // release useless node
    return Stu_data_r() && User_data_r();
}

#endif //SYS_2_FILE_INIT_H

//
// Created by Erzbir on 2022/5/14.
//
#include "file_Head.h"
#include "struct_Head.h"

#ifndef SYS_DATA_WR_HEAD_H
#define SYS_DATA_WR_HEAD_H

#endif //SYS_DATA_WR_HEAD_H

//读取计数器和学生数据
int Stu_all_r(Student *Stu, const int SIZE, int *size) {
    int n;
    FILE *file = NULL;
    FILE *count = NULL;    //计数器,将数组元素个数保存到文件中,下次再读取出来
    if ((file = fopen(STU_FILE, "rb")) == NULL) {
        printf("\n学生信息读取失败\n");
        getchar();
        return -1;
    }
    if ((count = fopen(STU_COUNT, "rb")) == NULL) {
        printf("\n计数器读取失败\n");
        getchar();
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fread(&Stu[n], sizeof(Student), 1, file);
    }
    fclose(file);
    fread(size, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//读取计数器和用户数据
int User_all_r(Users *User, const int SIZE, int *size) {
    int n;
    FILE *file = NULL;
    FILE *count = NULL;    //计数器,将数组元素个数保存到文件中,下次再读取出来
    if ((file = fopen(USER_FILE, "rb")) == NULL) {
        printf("\n用户信息读取失败\n");
        return -1;
    }
    if ((count = fopen(USER_COUNT, "rb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fread(&User[n], sizeof(Users), 1, file);
    }
    fclose(file);
    fread(size, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//读取计数器
int Stu_count_r(int *size) {
    FILE *count = NULL;    //计数器,将数组元素个数保存到文件中,下次再读取出来
    if ((count = fopen(STU_COUNT, "rb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    fread(size, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//读取计数器
int User_count_r(int *size) {
    FILE *count = NULL;    //计数器,将数组元素个数保存到文件中,下次再读取出来
    if ((count = fopen(USER_COUNT, "rb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    fread(size, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//保存计数器
int Stu_count_w(int *size) {
    FILE *count = NULL;    //计数器,将数组元素个数保存到文件中,下次再读取出来
    if ((count = fopen(STU_COUNT, "wb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    fwrite(size, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//保存计数器
int User_count_w(int *size) {
    FILE *count = NULL;    //计数器,将数组元素个数保存到文件中,下次再读取出来
    if ((count = fopen(USER_COUNT, "wb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    fwrite(size, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//读取学生数据
int Stu_data_r(Student *Stu, const int SIZE) {
    FILE *file = NULL;
    int n;
//    int size = 1;
    if ((file = fopen(STU_FILE, "rb")) == NULL) {
        printf("\n学生信息读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fread(&Stu[n], sizeof(Student), 1, file);
    }
    fclose(file);
    return 1;
}

//读取用户数据
int User_data_r(Users *User, const int SIZE) {
    FILE *file = NULL;
    int n;
//    int size = 1;
    if ((file = fopen(USER_FILE, "rb")) == NULL) {
        printf("\n学生信息读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fread(&User[n], sizeof(Users), 1, file);
    }
    fclose(file);
    return 1;
}

//保存学生数据
int Stu_data_w(Student *Stu, const int SIZE) {
    int n;
    FILE *file = NULL;
    if ((file = fopen(STU_FILE, "wb")) == NULL) {
        printf("\n学生信息读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fwrite(&Stu[n], sizeof(Student), 1, file);
    }
    fclose(file);
    return 1;
}

//保存用户数据
int User_data_w(Users *User, const int SIZE) {
    int n;
    FILE *file = NULL;
    if ((file = fopen(USER_FILE, "wb")) == NULL) {
        printf("\n用户信息读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fwrite(&User[n], sizeof(Users), 1, file);
    }
    fclose(file);
    return 1;
}
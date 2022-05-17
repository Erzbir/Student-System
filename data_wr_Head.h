//
// Created by Erzbir on 2022/5/14.
//
#include "file_Head.h"
#include "struct_Head.h"

#ifndef SYS_DATA_WR_HEAD_H
#define SYS_DATA_WR_HEAD_H

#endif //SYS_DATA_WR_HEAD_H

//读取计数器和学生数据
int Stu_all_r(Student *Stu_all, const int SIZE, int *size_all) {
    FILE *file;
    FILE *count;
    int n;
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
        fread(&Stu_all[n], sizeof(Student), 1, file);
    }
    fclose(file);
    fread(size_all, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//读取计数器和用户数据
int User_all_r(Users *User_all, const int SIZE, int *size_all) {
    FILE *file;
    FILE *count;
    int n;
    if ((file = fopen(USER_FILE, "rb")) == NULL) {
        printf("\n用户信息读取失败\n");
        return -1;
    }
    if ((count = fopen(USER_COUNT, "rb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fread(&User_all[n], sizeof(Users), 1, file);
    }
    fclose(file);
    fread(size_all, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//读取计数器
int Stu_count_r(int *size_stu) {
    FILE *count;
    if ((count = fopen(STU_COUNT, "rb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    fread(size_stu, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//读取计数器
int User_count_r(int *size_user) {
    FILE *count;
    if ((count = fopen(USER_COUNT, "rb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    fread(size_user, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//保存计数器
int Stu_count_w(int *size_stu) {
    FILE *count;
    if ((count = fopen(STU_COUNT, "wb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    fwrite(size_stu, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//保存计数器
int User_count_w(int *size_user) {
    FILE *count;
    if ((count = fopen(USER_COUNT, "wb")) == NULL) {
        printf("\n计数器读取失败\n");
        return -1;
    }
    fwrite(size_user, sizeof(int), 1, count);
    fclose(count);
    return 1;
}

//读取学生数据
int Stu_data_r(Student *Stu_data, const int SIZE) {
    int n;
    FILE *file;
    if ((file = fopen(STU_FILE, "rb")) == NULL) {
        printf("\n学生信息读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fread(&Stu_data[n], sizeof(Student), 1, file);
    }
    fclose(file);
    return 1;
}

//读取用户数据
int User_data_r(Users *User_data, const int SIZE) {
    int n;
    FILE *file;
    if ((file = fopen(USER_FILE, "rb")) == NULL) {
        printf("\n学生信息读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        fread(&User_data[n], sizeof(Users), 1, file);
    }
    fclose(file);
    return 1;
}

//保存学生数据
int Stu_data_w(Student *Stu_data, const int SIZE_data) {
    int n;
    FILE *file;
    if ((file = fopen(STU_FILE, "wb")) == NULL) {
        printf("\n学生信息读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE_data; n++) {
        fwrite(&Stu_data[n], sizeof(Student), 1, file);
    }
    fclose(file);
    return 1;
}

//保存用户数据
int User_data_w(Users *User_data, const int SIZE_data) {
    int n;
    FILE *file;
    if ((file = fopen(USER_FILE, "wb")) == NULL) {
        printf("\n用户信息读取失败\n");
        return -1;
    }
    for (n = 0; n < SIZE_data; n++) {
        fwrite(&User_data[n], sizeof(Users), 1, file);
    }
    fclose(file);
    return 1;
}

//追加保存学生数据
int Stu_data_a(Student *Stu_data, const int *size, int index) {
    FILE *file = NULL;
    int n;
    if ((file = fopen(STU_FILE, "wb")) == NULL) {
        printf("\n学生信息读取失败\n");
        return -1;
    }
    for (n = index; n < *size; n++) {
        fwrite(&Stu_data[n], sizeof(Users), 1, file);
    }
    fclose(file);
    return 1;
}
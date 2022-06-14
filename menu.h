//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_MENU_H
#define SYS_2_MENU_H

#include <stdio.h>

int Menu_main_1() {
    printf("\n");
    printf("*****************************\n");
    printf("0.退出\n");
    printf("1.注册\n");
    printf("2.登录\n");
    printf("*****************************\n");
    printf("输入你的选项(选项前面的数字即可):");
    return 1;
}

int Menu_main_2() {
    printf("\n");
    printf("*****************************\n");
    printf("0.退出\n");
    printf("1.获取管理权限\n");
    printf("2.输入学生信息\n");
    printf("3.学生成绩排序(总成绩排序、平均分排序)\n");
    printf("4.显示学生信息(学号、姓名、成绩(三科成绩))\n");
    printf("5.查找并显示学生信息(学号、姓名、成绩(三科成绩))\n");
    printf("6.修改学生信息(学号、姓名、成绩(三科成绩))\n");
    printf("7.删除学生信息\n");
    printf("8.统计学生人数\n");
    printf("*****************************\n");
    printf("输入你的选项(选项前面的数字即可):");
    return 2;
}

#endif //SYS_2_MENU_H

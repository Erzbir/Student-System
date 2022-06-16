//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_MENU_H
#define SYS_2_MENU_H

#include <stdio.h>

int Menu_main_1() {
    printf("\n");
    printf("*****************************\n");
    printf("0.Exit\n");
    printf("1.Sign up\n");
    printf("2.Sign in\n");
    printf("*****************************\n");
    printf("Enter your choice:");
    return 1;
}

int Menu_main_2() {
    printf("\n");
    printf("*****************************\n");
    printf("0.Exit\n");
    printf("1.Obtain permission\n");
    printf("2.Input student info\n");
    printf("3.Sort student info\n");
    printf("4.Display student info\n");
    printf("5.Search and output student info\n");
    printf("6.Revise student info\n");
    printf("7.Delete student info\n");
    printf("8.Count number of students\n");
    printf("*****************************\n");
    printf("Enter your choice:");
    return 2;
}

#endif //SYS_2_MENU_H

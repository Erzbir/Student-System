//
// Created by Erzbir on 2022/6/14.
//

// student-system

// This is debug version, use DoubleLinkList but not circular.

// Why I use English? Because use Chinese may cause garbled characters, the reason is different encoding.

//Write Environment:
/*
 * System Environment: macOS
 * Hardware Environment: MacbookPro (M1 chip)
 * Software Environment: Clion2022
 * Encoding: UTF-8
 */

/*
 * This version is implemented as an array and a DoubleLinkList.
 * There is less user data, so it is directly stored in an array.
 * The student data uses a DoubleLinkList uses the simplest bubble sort.
 * The DoubleLinkList is not circular, the next of the last node points to the NULL and does not point to the first node, except that it is the same as the DoubleCircularLinkList,
 */

//Please modify the file path which was declared in "define.h" before running. The file name can be customized and can be located in different folders, but must be different files.
//Please change the PAUSE declared in "define.h" to the command under Windows before running the Windows system

//Need to add all files to the working directory, preferably CLion, if you use C-free or Dev-C++ or VS, opening "main.c" directly and running it.

//You cannot operate "modify" and "delete" without permission. If you want to operate, you must obtain permission first.
// The management password is: 123456




#include <stdio.h>
#include <stdlib.h>
#include "output.h"     // display student data
#include "input.h"      // input student data
#include "struct.h"     // data struct of all
#include "define.h"     // all global variable and defined constant
#include "delete.h"     // delete student data
#include "sort.h"       // nums.sort, sumScore.sort, averScore.sort
#include "revise.h"     // modify student info
#include "menu.h"       // two menus
#include "register.h"   // sign up
#include "login.h"      // sign in
#include "getAdmin.h"   // obtain admin permission
#include "checkAdmin.h" // check whether user is an admin
#include "file_init.h"  // program.init
#include "find.h"       // search student data
#include "max.h"        // display the No.1

int main() {
    head = (StuNode *) malloc(sizeof(StuNode));
    int select = 1, select_2 = 1;
    long int num = 0;
    int value = 0;
    if (!(FileInit())) {
        printf("\nFailed to Initialize\n");
        system(PAUSE);
        exit(0);
    }
    while (select) {
        Menu_main_1();
        scanf("%d", &select);
        switch (select) {
            case 0:
                printf("exited");
                system(PAUSE);
                break;
            case 1:
                if (!(Register())) {
                    printf("Failed to Register");
                    system(PAUSE);
                }
                break;
            case 2:
                value = Login();
                if (!value) {
                    printf("\nFailed to Login\n");
                    system(PAUSE);
                }
                break;
            default:
                printf("\nPlease re-enter\n");
                system(PAUSE);
                break;
        }
        if (select == 2 && value) {
            while (select_2) {
                Menu_main_2();
                scanf("%d", &select_2);
                switch (select_2) {
                    case 0:
                        printf("\nexited\n");
                        system(PAUSE);
                        break;
                    case 1:
                        if (!(Admin(value))) {
                            printf("Failed to obtain");
                            system(PAUSE);
                        }
                        break;
                    case 2:
                        if (!(Input())) {
                            printf("\nFailed to input\n");
                            system(PAUSE);
                        }
                        break;
                    case 3:
                        if (!(Sort())) {
                            printf("\nFailed to Sort\n");
                            system(PAUSE);
                        }
                        break;
                    case 4:
                        if (!(Print())) {
                            printf("\nFailed to Output\n");
                            system(PAUSE);
                        }
                        break;
                    case 5:
                        printf("Enter student ID:");
                        scanf("%ld", &num);
                        if (!(Scan(num))) {
                            printf("\nFailed to Search\n");
                            system(PAUSE);
                        }
                        break;
                    case 6:
                        if (!(Check(value))) {
                            printf("\nNo Permission\n");
                            system(PAUSE);
                            break;
                        }
                        if (!(Revise())) {
                            printf("\nFailed to Revise\n");
                            system(PAUSE);
                        }
                        break;
                    case 7:
                        if (!(Check(value))) {
                            printf("\nNo Permission\n");
                            system(PAUSE);
                            break;
                        }
                        if (!Delete()) {
                            printf("\nFailed to Delete\n");
                            system(PAUSE);
                        }
                        break;
                    case 8:
                        printf("\nThe total number of student:%d\n", size_2);
                        system(PAUSE);
                        break;
                    case 9:
                        if (!Max()) {
                            printf("Error");
                        }
                        system(PAUSE);
                        break;
                    default:
                        printf("\nPlease re-enter\n");
                        system(PAUSE);
                        break;
                }
            }
        }
    }
    return 0;
}


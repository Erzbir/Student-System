//
// Created by Erzbir on 2022/6/14.
//

#ifndef SYS_2_DEFINE_H
#define SYS_2_DEFINE_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

#ifndef USER_FILE
#define USER_FILE "./user.txt"  // user data path
#endif //USER_FILE

#ifndef STU_FILE
#define STU_FILE "./stu.txt"    // student data path
#endif //STU_FILE

#ifndef USER_SIZE
#define USER_SIZE 20    // user data limit
#endif //USER_SIZE

#ifndef STU_SIZE
#define STU_SIZE 10000  // student data limit when input
#endif //STU_SIZE

#ifndef PAUSE
#define PAUSE "read"    // pause of macOS
//#define PAUSE "pause"   // pause of Windows
#endif //PAUSE

StuNode *head = NULL;          // head node
Users User[USER_SIZE];  // user data
int size = 0;           // the size of user data
int size_2 = 0;         // the size of student data

#endif //SYS_2_DEFINE_H

//
// Created by Erzbir on 2022/5/13.
//

#ifndef SYS_STU_INIT_HEAD_H
#define SYS_STU_INIT_HEAD_H

int Init_file(Users *User_1, Student *Stu_1, int SIZE_1, int SIZE_2){
    FILE *file = NULL;
    file = fopen(USER_FILE, "ab");
    fclose(file);
    file = fopen(STU_FILE, "ab");
    fclose(file);
    file = fopen(USER_COUNT, "ab");
    fclose(file);
    file = fopen(STU_COUNT, "ab");
    fclose(file);
    if(!(Stu_data_r(Stu_1, SIZE_1))){
        return -1;
    }
    if(!(User_data_r(User_1, SIZE_2))){
        return -1;
    }
    printf("加载数据成功");
    return 1;
}

#endif //SYS_STU_INIT_HEAD_H

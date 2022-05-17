//
// Created by Erzbir on 2022/5/13.
//

#ifndef SYS_STU_INIT_HEAD_H
#define SYS_STU_INIT_HEAD_H

int Init_all() {
    FILE *file;
    file = fopen(USER_FILE, "ab");
    fclose(file);
    file = fopen(STU_FILE, "ab");
    fclose(file);
    file = fopen(USER_COUNT, "ab");
    fclose(file);
    file = fopen(STU_COUNT, "ab");
    fclose(file);
    return 1;
}

#endif //SYS_STU_INIT_HEAD_H

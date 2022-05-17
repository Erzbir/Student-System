//
// Created by Erzbir on 2022/5/13.
//

#ifndef SYS_DELETE_HEAD_H
#define SYS_DELETE_HEAD_H

int Delete(Student *Stu_1, const int SIZE_stu) {
    int value, j;
    int size = 1;
    long int num;
    char select;
    printf("需要删除的学生学号:");
    scanf("%ld", &num);
    if(!(Stu_count_r(&size))){
        return -1;
    }
    value = Scan(Stu_1, num, size);
    if (value == 0) {
        return -1;
    }
    while (1) {
        printf("是否确定删除(y/n):");
        scanf("%s", &select);
        if (select == 'n' || select == 'N') {
            return 0;
        }
        else if (select == 'y' || select == 'Y') {
            for (j = value; j < size - value + 1; j++) {
                Stu_1[j] = Stu_1[j + 1];//覆盖
            }
            if (!(Stu_data_w(Stu_1, size))) {
                return -1;
            }
            size--;
            if (!(Stu_count_w(&size))) {
                return -1;
            }
            printf("\n删除成功\n");
            return 1;
        } else {
            printf("\n重新输入\n");
            break;
        }
    }
    return 0;
}

#endif //SYS_DELETE_HEAD_H


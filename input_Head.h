//
// Created by Erzbir on 2022/5/9.
//

#ifndef SYS_INPUT_HEAD_H
#define SYS_INPUT_HEAD_H


int Input(const int SIZE) {
    int n, i;
    int size = 1;   //用于记录数组的元素个数
    long int num;
    Student Stu[SIZE];
    if(!(Stu_count_r(&size))){
        return -1;
    }
    if (!(Stu_data_r(Stu, size+1))) {
        return -1;
    }
    for (n = 0; n < size; n++) {
        int value = 1;
        printf("输入第%d个学生信息(学号,姓名)(-1结束):", n + 1);
        scanf("%ld, %s", &num, Stu[size - 1].name);
        if (num < 0) {
            break;
        }
        for (i = 0; i < size; i++) {
            if (num == Stu[i].num) {
                printf("\n已存在该学生\n");
                n--;
                value = -1;
                break;
            }
        }
        if (value != -1) {
            Stu[size - 1].num = num;
            for (i = 0; i < 3; i++) {
                printf("输入第%d科成绩:", i + 1);
                scanf("%f", &Stu[size - 1].score[i]);
            }
            Stu[size - 1].sum = Stu[size - 1].score[0] + Stu[size - 1].score[1] + Stu[size - 1].score[2];
            Stu[size - 1].aver = Stu[size - 1].sum / 3;
            size++;
        }
    }
    if (!(Stu_data_w(Stu, size))) {
        return -1;
    }
    if (!(Stu_count_w(&size))) {
        return -1;
    }
    printf("\n录入成功\n");
    getchar();
    return 1;
}

#endif //SYS_INPUT_HEAD_H


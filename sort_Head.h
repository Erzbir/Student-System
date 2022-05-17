//
// Created by Erzbir on 2022/5/9.
//

#ifndef SYS_SORT_HEAD_H
#define SYS_SORT_HEAD_H

int Sort(const int SIZE) {
    int n, m;
    int size = 1;   //用于记录数组的元素个数
    int select;
    Student Stu[SIZE], tmp;
    if(!(Stu_count_r(&size))){
        return -1;
    }
    if (!(Stu_data_r(Stu, size+1))) {
        return -1;
    }
    printf("1.按总分排序\n2.按平均分排序\n3.按学号排序\n选择模式(序号即可):");
    scanf("%d", &select);
    if (select == 1) {
        for (n = 0; n < size - 1; n++) {
            for (m = 0; m < size - n - 2; m++) {
                if (Stu[m].sum < Stu[m + 1].sum) {
                    tmp = Stu[m];
                    Stu[m] = Stu[m + 1];
                    Stu[m + 1] = tmp;
                }
            }
        }
    } else if (select == 2) {
        for (n = 0; n < size - 1; n++) {
            for (m = 0; m < size - n - 2; m++) {
                if (Stu[m].aver < Stu[m + 1].aver) {
                    tmp = Stu[m];
                    Stu[m] = Stu[m + 1];
                    Stu[m + 1] = tmp;
                }
            }
        }
    } else if (select == 3) {
        for (n = 0; n < size - 1; n++) {
            for (m = 0; m < size - n - 2; m++) {
                if (Stu[m].num > Stu[m + 1].num) {
                    tmp = Stu[m];
                    Stu[m] = Stu[m + 1];
                    Stu[m + 1] = tmp;
                }
            }
        }
    } else {
        printf("\n选择错误\n");
    }
    if (!(Stu_data_w(Stu, size))) {
        return -1;
    }
    printf("\n排序完成\n");
    getchar();
    return 1;
}

#endif //SYS_SORT_HEAD_H



//
// Created by Erzbir on 2022/5/9.
//

#ifndef SYS_FIND_HEAD_H
#define SYS_FIND_HEAD_H


int Scan(long int item, const int SIZE) {
    int n;
    int size_1;   //用于记录数组的元素个数
    char select;
    Student Stu[SIZE];
    if(!(Stu_count_r(&size_1))){
        return -1;
    }
    if (!(Stu_data_r(Stu, size_1+1))) {
        return -1;
    }
    for (n = 0; n < size_1; n++) {
        if (Stu[n].num == item) {
            while (1) {
                printf("已查询到该学生,是否打印其信息(y/n):");
                scanf("%s", &select);
                if (select == 'y' || select == 'Y') {
                    printf("学号:%ld, 姓名:%s   第一科成绩:%.2f, 第二科成绩:%.2f, "
                           "第三科成绩:%.2f  总分:%.2f 平均分:%.2f\n",
                           Stu[n].num, Stu[n].name, Stu[n].score[0],
                           Stu[n].score[1], Stu[n].score[2], Stu[n].sum, Stu[n].aver);
                    printf("\n查询成功\n");
                    return n;
                } else if (select == 'N' || select == 'n') {
                    return n;
                } else {
                    printf("\n重新输入\n");
                    getchar();
                }
            }
        }
    }
    printf("\n未查询到该学生\n");
    getchar();
    return 0;
}

#endif //SYS_FIND_HEAD_H


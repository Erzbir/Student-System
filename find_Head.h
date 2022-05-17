//
// Created by Erzbir on 2022/5/9.
//

#ifndef SYS_FIND_HEAD_H
#define SYS_FIND_HEAD_H


int Scan(Student *Stu_s, long int item, const int SIZE) {
    int n;
    int size = 1;
    char select;
    if(!(Stu_count_r(&size))){
        return -1;
    }
    for (n = 0; n < SIZE; n++) {
        if (Stu_s[n].num == item) {
            while (1) {
                printf("已查询到该学生,是否打印其信息(y/n):");
                scanf("%s", &select);
                if (select == 'y' || select == 'Y') {
                    printf("学号:%ld, 姓名:%s   第一科成绩:%.2f, 第二科成绩:%.2f, "
                           "第三科成绩:%.2f  总分:%.2f 平均分:%.2f\n",
                           Stu_s[n].num, Stu_s[n].name, Stu_s[n].score[0],
                           Stu_s[n].score[1], Stu_s[n].score[2], Stu_s[n].sum, Stu_s[n].aver);
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


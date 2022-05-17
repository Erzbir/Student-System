//
// Created by Erzbir on 2022/5/9.
//

#ifndef SYS_OUTPUT_HEAD_H
#define SYS_OUTPUT_HEAD_H


int Print(const int SIZE) {
    int n = 0, num_1 = -1, num_2 = 1;
    int size = 1;   //用于记录数组的元素个数
    Student Stu[SIZE];
    if(!(Stu_count_r(&num_1))){
        return -1;
    }
    if (!(Stu_data_r(Stu, num_1+1))) {
        return -1;
    }
    if (num_1 == -1) {
        printf("\n学生信息为空\n");
        return 0;
    }
    printf("输入显示的学生数量:");
    scanf("%d", &num_2);
    size = (num_2 >= num_1) ? num_1 - 1 : num_2;
    if (size > 0) {
        for (n = 0; n < size; n++) {
            printf("学号:%ld, 姓名:%s   第一科成绩:%.2f, 第二科成绩:%.2f, "
                   "第三科成绩:%.2f  总分:%.2f 平均分:%.2f\n",
                   Stu[n].num, Stu[n].name, Stu[n].score[0],
                   Stu[n].score[1], Stu[n].score[2], Stu[n].sum, Stu[n].aver);
        }
        printf("\n显示成功\n");
    }
    return 1;
}

#endif //SYS_OUTPUT_HEAD_H

//可以输入学号进行单个打印,也可输入打印的个数从第一个开始往后打印

//
// Created by Erzbir on 2022/5/9.
//

#ifndef SYS_REVISE_HEAD_H
#define SYS_REVISE_HEAD_H


int Revise(Student *Stu, const int SIZE_stu) {
    int size = 1;
    int value;
    long int num;
    char select;
    if (!(Stu_count_r(&size))) {
        return -1;
    }
    while (1) {
        printf("输入学号:");
        scanf("%ld", &num);
        value = Scan(Stu,num, size);
        if (value < 0) {
            return -1;
        }
        printf("1.姓名\n2.成绩\n");
        printf("输入要修改的数据的序号:");
        scanf("%s", &select);
        if (select == '1') {
            printf("修改姓名:");
            scanf("%s", Stu[value].name);
            if (!(Stu_data_w(Stu, size))) {
                return -1;
            }
            printf("\n修改成功\n");
        } else if (select == '2') {
            printf("修改第一科成绩:");
            scanf("%f", &Stu[value].score[0]);
            printf("修改第二科成绩:");
            scanf("%f", &Stu[value].score[1]);
            printf("修改第三科成绩:");
            scanf("%f", &Stu[value].score[2]);
            Stu[value].sum = Stu[value].score[0] + Stu[value].score[1] + Stu[value].score[2];
            Stu[value].aver = Stu[value].sum / 3;
            if (!(Stu_data_w(Stu, size))) {
                return -1;
            }
            printf("\n修改成功\n");
        } else {
            printf("\n重新输入\n");
            getchar();
        }
        printf("是否继续(y/n):");
        scanf("%s", &select);
        if (select == 'N' || select == 'n') {
            break;
        }
    }
    return 0;
}


#endif //SYS_REVISE_HEAD_H


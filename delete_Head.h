//
// Created by Erzbir on 2022/5/13.
//

#ifndef SYS_DELETE_HEAD_H
#define SYS_DELETE_HEAD_H

int Delete(const int SIZE) {
    int value, j;
    long int num;
    int size;   //用于记录数组的元素个数
    char select;
    Student Stu[SIZE];
    if(!(Stu_count_r(&size))){
        return -1;
    }
    if (!(Stu_data_r(Stu, size+1))) {
        return -1;
    }
    printf("需要删除的学生学号:");
    scanf("%ld", &num);
    value = Scan(num, size+1);
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
            if(!(Stu_count_r(&size))){
                return -1;
            }
            for (j = value; j < size - value + 1; j++) {
                Stu[j] = Stu[j + 1];//覆盖
            }
            if (!(Stu_data_w(Stu, size+1))) {
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


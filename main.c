//
// Created by Erzbir on 2022/6/14.
//

//编写环境:
/*
 * 系统: MacOS
 * 硬件环境: MacbookPro(M1芯片)
 * 软件环境: Clion2022
 * 编码: UTF-8
 */

/*
 * 此版实现方式为数组和双向链表, 用户数据较少所以直接用数组存,
 * 而学生数据则使用的是双向链表, 没有检查学号唯一性且用最简单的冒泡排序(没有时间了),
 * 此双向链表并不是循环链表, 最后一个节点的next指向了空并没有指向第一个节点, 除此之外和双向循环链表一样,
 */

//运行前请先修改"define.h"中声明的文件路径, 文件名可以自定义且可以位于不同文件夹, 但必须是不相同的文件.
//Windows系统运行前请将"define.h"中声明的PAUSE改成Windows下的命令


/*
 * 代码中或者Windows命令行下运行时如果出现乱码问题请修改本项目所有的文件编码, Windows命令行默认的编码为GBK, 一般修改为GBK即可
 * 如果MacOS或Linux上出现乱码, 尝试不同编码, 这种情况一般不会出现
*/

//需要将所有文件添加到工作目录, 最好用CLion

//没有权限不能操作"修改"和"删除", 要想操作先获取权限, 管理密码为:123456


#include <stdio.h>
#include <stdlib.h>
#include "output.h"     // 输出数据
#include "input.h"      // 输入数据
#include "struct.h"     // 数据存储结构
#include "define.h"     // 各种全局变量定义和常量声明
#include "delete.h"     // 删除学生数据
#include "sort.h"       // 排序
#include "revise.h"     // 修改
#include "menu.h"       // 菜单
#include "register.h"   // 注册
#include "login.h"      // 登录
#include "getAdmin.h"      // 获取管理权限
#include "checkAdmin.h" // 检查是否有权限
#include "file_init.h"  // 程序初始化

int main() {
    head = (StuNode *) malloc(sizeof(StuNode));
    int select = 1, select_2 = 1;
    long int num;
    int value;
    if (!(FileInit())) {
        printf("\n初始化错误\n");
        system(PAUSE);
        exit(0);
    }
    while (select) {
        Menu_main_1();
        scanf("%d", &select);
        switch (select) {
            case 0:
                printf("已退出");
                system(PAUSE);
                break;
            case 1:
                if (!(Register())) {
                    printf("注册错误");
                    system(PAUSE);
                }
                break;
            case 2:
                value = Login();
                if (!value) {
                    printf("\n登录错误\n");
                    system(PAUSE);
                }
                break;
            default:
                printf("\n请重输\n");
                system(PAUSE);
                break;
        }
        if (select == 2 && value) {
            while (select_2) {
                Menu_main_2();
                scanf("%d", &select_2);
                switch (select_2) {
                    case 0:
                        printf("\n已退出\n");
                        system(PAUSE);
                        break;
                    case 1:
                        if (!(Admin(value))) {
                            printf("获取错误");
                            system(PAUSE);
                        }
                        break;
                    case 2:
                        if (!(Input())) {
                            printf("\n录入错误\n");
                            system(PAUSE);
                        }
                        break;
                    case 3:
                        if (!(Sort())) {
                            printf("\n排序错误\n");
                            system(PAUSE);
                        }
                        break;
                    case 4:
                        if (!(Print())) {
                            printf("\n显示错误\n");
                            system(PAUSE);
                        }
                        break;
                    case 5:
                        printf("输入学号:");
                        scanf("%ld", &num);
                        if (!(Scan(num))) {
                            printf("\n查找错误\n");
                            system(PAUSE);
                        }
                        break;
                    case 6:
                        if (!(Check(value))) {
                            printf("\n没有权限\n");
                            system(PAUSE);
                            break;
                        }
                        if (!(Revise())) {
                            printf("\n修改错误\n");
                            system(PAUSE);
                        }
                        break;
                    case 7:
                        if (!(Check(value))) {
                            printf("\n没有权限\n");
                            system(PAUSE);
                            break;
                        }
                        if (!Delete()) {
                            printf("\n删除错误\n");
                            system(PAUSE);
                        }
                        break;
                    case 8:
                        printf("\n%d\n", size_2);
                        break;
                    default:
                        printf("\n请重输\n");
                        system(PAUSE);
                        break;
                }
            }
        }
    }
    return 0;
}


//
// Created by Erzbir on 2022/5/9.
//


//请先阅读注释, 此版针对运行速度进行优化但牺牲内存占用
//请先阅读注释, 此版针对运行速度进行优化但牺牲内存占用
//请先阅读注释, 此版针对运行速度进行优化但牺牲内存占用
//请先阅读注释, 此版针对运行速度进行优化但牺牲内存占用




//编写环境:
/*
 * 系统: MacOS
 * 硬件环境: Macbookpro(M1芯片)
 * 软件环境: Clion2022
 * 编码: UTF-8
 *
 */

//运行前请先修改"file_Head.h"中声明的文件路径, 文件名可以自定义且可以位于不同文件夹, 但必须是四个不同名字的文件.


/*
 * 代码中或者Windows命令行下运行时如果出现乱码问题请修改本项目所有的文件编码, Windows命令行默认的编码为GBK, 一般修改为GBK即可
 * 如果MacOS或Linux上出现乱码, 尝试不同编码, 这种情况一般不会出现
*/

//需要将所有文件添加到工作目录, 最好用CLion

//计数器原理:        //跟正常的记录元素个数(数组长度)不太一样, 特此说明
 /*
  * 每完成一次输入(注册和学生信息录入)计数器的值+1, 记录下一次要输入后元素的总个数, 在此程序中计数器记录的值统一称"size", size初始值为1.
  * 例如注册第一个用户, size初始值为1, 当输入用户名和密码且符合规则并正常运行之后, 第一个个用户的数据记录到array[size -1]也就是array[0], size的值+1变成2并序列化存储到保存计数器的文件中,
  * 当下一次注册第二个用户时, 读取计数器记录的元素个数也就是2, 注册后将用户数据存到array[size - 1]也就是array[1], size值+1变成3并储存.
  *
  *     注:"size"并不是下一个要输入或者输出的元素, 而是完成下一次输入后元素的总数, 而size - 1才是下一个要输入的元素,
  *         例如size = 2, 则已经输入了array[0]的数据, 现在输入[size - 1]也就是array[1]的数据.
  */
/*
 为了快速完成编写, 所有操作均用二进制遍历覆写实现, 这样也许会很慢.
 如果要提高速度, 改变data_wr_Head中包含fwrite()和fread()的循环体条件将SIZE改成size(可以改变名称, 不过要修改则在使用fread和fwrite前必须先读取计数器),
 还可以一并将模式改为"ab"(这个需要通读理解代码).
 */

//没有权限不能操作"修改"和"删除", 要想操作先获取权限, 管理密码为:123456

#include <stdio.h>
#include "register_Head.h"  //注册
#include "find_Head.h"      //查询
#include "output_Head.h"    //输出
#include "input_Head.h"     //输入
#include "revise_Head.h"    //修改
#include "menu_Head.h"      //菜单
#include "login_Head.h"     //登录
#include "delete_Head.h"    //删除
#include "sort_Head.h"      //排序
#include "adminGet_Head.h"  //获取权限
#include "file_init_Head.h"  //文件创建和初始化
#include "check_Head.h"     //权限检查
//#include "file_Head.h"      //文件存放路径
//#include "data_wr_Head.h"   //序列化和反序列化


#define USER_SIZE 20    //最大用户数量
#define STU_SIZE 10000     //最大学生数量

int main() {
    Users user[USER_SIZE];
    Student stu[STU_SIZE];
    int select = 1, select_2 = 1;
    long int num;
    int value;
    if ((Init_file(user, stu, USER_SIZE, STU_SIZE)) == -1) {
        printf("\n初始化错误\n");
        exit(0);
    }
    while (select) {
        Menu_main_1();
        scanf("%d", &select);
        switch (select) {
            case 0:
                printf("已退出");
                break;
            case 1:
                if (Register(user, USER_SIZE) == -1) {
                    printf("注册错误");
                }
                break;
            case 2:
                value = Login(user, USER_SIZE);
                if (value == -1) {
                    printf("\n登录错误\n");
                }
                break;
            default:
                printf("\n请重输\n");
                break;
        }
        if (select == 2 && value != -1) {
            while (select_2) {
                Menu_main_2();
                scanf("%d", &select_2);
                switch (select_2) {
                    case 0:
                        printf("\n已退出\n");
                        break;
                    case 1:
                        if(Admin(user, USER_SIZE, value) == -1){
                            printf("获取错误");
                        }
                        break;
                    case 2:
                        if (Input(stu, STU_SIZE) == -1) {
                            printf("\n录入错误\n");
                        }
                        break;
                    case 3:
                        if (Sort(stu, STU_SIZE) == -1) {
                            printf("\n排序错误\n");
                        }
                        break;
                    case 4:
                        if (Print(stu, STU_SIZE) == -1) {
                            printf("\n显示错误\n");
                        }
                        break;
                    case 5:
                        printf("输入学号:");
                        scanf("%ld", &num);
                        if (Scan(stu, num, STU_SIZE) == -1) {
                            printf("\n查找错误\n");
                        }
                        break;
                    case 6:
                        if (Check(user, value) == -1) {
                            printf("\n没有权限\n");
                            break;
                        }
                        if (Revise(stu, STU_SIZE) == -1) {
                            printf("\n修改错误\n");
                        }
                        break;
                    case 7:
                        if (Check(user, value) == -1) {
                            printf("\n没有权限\n");
                            break;
                        }
                        if (Delete(stu, STU_SIZE) == -1) {
                            printf("\n删除错误\n");
                        }
                        break;
                    default:
                        printf("\n请重输\n");
                        break;
                }
            }
        }
    }
}

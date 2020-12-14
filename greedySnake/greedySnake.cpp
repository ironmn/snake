// greedySnake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CTR_SECURE_NO_WARNING
#include <iostream>
#include <time.h>
#include<string.h>
#include <algorithm>
#define INF 0x3f3f3f3f
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include "snake.h"
#include"wall.h"
using namespace std;

clock_t nowTime, preTime;//用于计算时间差
int max_scores[5];
int speed[] = { 10000,500,150,15,2 };
int main()
{
    fill(max_scores, max_scores + 5, -INF);
    //重新开始的标记
    char restart =  ' ';
    while (restart != 'q') {
        system("cls");//先把之前所有的控制台输出都给他清空了
        //开始界面
        cout << "请输入游戏难度！" << endl;
        cout << "1: 简单\t 2:中等\t 3:困难\t 4:地狱" << endl;
        char diff = getchar();
        int degree = diff - '0';
        system("cls");
        //正式进入游戏
        Wall wall;
        wall.initWall();//新建一个墙，并且初始化一下
        Snake snake;//创建一条蛇
        wall.drawSnake(snake.getHead());//把蛇画在控制台上
        //默认的移动方向为d
        char input = 'd';
        bool has_input = false;//用于防止用户在一次时间间隔内
        //重复输入导致无法明确的获得蛇的运行过程
        while (!wall.fail) {//
            //更新地图
            wall.update(snake, input);
            preTime = clock();
            has_input = false;
            while (true)
            {
                nowTime = clock();//当时间差超过了我们设定的阈值后
                //就进行下一步移动操作
                if (nowTime - preTime > speed[degree]) {
                    break;
                }
                //如果检测到了输入，就把input设置为输入的字符
                if (kbhit() && !has_input) {
                    input = _getch();
                    has_input = true;//防止重复的输入去迭代input
                }
            }
            //清空控制台的所有输出
            system("cls");
        }
        //如果退出循环了，表明游戏已经失败
        max_scores[degree] = max(max_scores[degree], wall.getScore());
      
        wall.game_over();
        cout << "在难度为 " << degree << " 下的历史最高分是：" << max_scores[degree] << endl;
        cout << "按任意键重新开始游戏" << endl;
        cout << "按Q退出" << endl;
        getchar();
        //读取字符，用于测试用户是否还要继续游戏
        restart = getchar();
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

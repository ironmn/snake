// greedySnake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CTR_SECURE_NO_WARNING
#include <iostream>
#include <time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include "snake.h"
#include"wall.h"
using namespace std;

clock_t nowTime, preTime;

int speed[] = { 10000,500,150,15,2 };
int main()
{
    char restart =  ' ';
    while (restart != 'q') {
        system("cls");
        //开始界面
        cout << "请输入游戏难度！" << endl;
        cout << "1: 简单\t 2:中等\t 3:困难\t4:地狱" << endl;
        char diff = getchar();
        system("cls");
        //正式进入游戏
        Wall wall;
        wall.initWall();
        Snake snake;
        wall.drawSnake(snake.getHead());
        //默认的移动方向
        char input = 'd';
        bool has_input = false;
        while (!wall.fail) {
            wall.update(snake, input);
            preTime = clock();
            has_input = false;
            while (true)
            {
                nowTime = clock();
                if (nowTime - preTime > speed[diff - '0']) {
                    break;
                }
                //如果检测到了输入，就把input设置为输入的字符
                if (kbhit() && !has_input) {
                    input = _getch();
                    has_input = true;//防止重复的输入去迭代input
                }
            }
            system("cls");
        }
        wall.game_over();
        cout << "按任意键重新开始游戏"<<endl;
        cout << "按Q退出" << endl;
        getchar();
        restart = getchar();
        Wall::ate = false;
        Wall::fail = false;
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

#pragma once
#ifndef __greedy__snake__wall
#define __greedy__snake__wall
#include<iostream>
#include"node.h"
#include<stdio.h>
using namespace std;
class Wall
{
public:
	
	enum {
		ROW = 32,
		COL = 32
	};
	//初始化地图
	void initWall();
	//展示地图的所有元素
	void showWall();
	//提供一个外部的接口，能够对地图的元素进行修改
	void setMaze(node* param);
	//重载实现
	void setMaze(int x, int y, char c);
	//外部的对象可以获取地图元素
	char getElem(int x, int y);

	void drawSnake(node* para);

private:
	char gameArray[ROW][COL];
};




#endif // !__greedy__snake__wall

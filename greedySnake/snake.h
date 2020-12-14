#pragma once
#ifndef __snake
#define __snake
#include"node.h"
#include<iostream>
#include<map>
using namespace std;
class Snake
{
public:
	Snake();
	~Snake();

	node* getHead();
	void setHead(node* temp);
	//设置运动的方向
	void setDirection(char c);
	//不带参数的move表示单方向的移动（也就是自动移动）
	void move();
	//带参数的move，表示用户按下了某个按钮，会导致蛇位置发生变化。
	void move(char c);
	void eat();
	char getDirection();

	bool validate();
	pair<int, int> next_position();
private:
	//head结点表示蛇头
	node* head;
	//tail节点表示蛇尾，主要用于增加蛇的长度
	node* tail;
	//length指示蛇的长度
	int length;
	//direct用于指示蛇当前的移动方向
	//用小写的w、a、s、d来表示。默认的移动方向是向右的
	char direct;
};

#endif



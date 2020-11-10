#pragma once
#ifndef __snake
#define __snake
#include"node.h"
#include<iostream>
class Snake
{
public:
	Snake();
	~Snake();

	node* getHead();

	void setHead(node* temp);

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


#endif // !1



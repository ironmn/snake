#pragma once
#ifndef __datastucture__of__snake
#define __datastucture__of__snake
#include<stdio.h>
struct node
{
	int x;
	int y;
	char icon;
	node* next;
	node();
	node(int _x, int _y, char _icon, node* _next = nullptr) :x(_x), y(_y), icon(_icon), next(_next) {}
};

#endif // !__datastucture__of__snake

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
	//head����ʾ��ͷ
	node* head;
	//tail�ڵ��ʾ��β����Ҫ���������ߵĳ���
	node* tail;
	//lengthָʾ�ߵĳ���
	int length;
	//direct����ָʾ�ߵ�ǰ���ƶ�����
	//��Сд��w��a��s��d����ʾ��Ĭ�ϵ��ƶ����������ҵ�
	char direct;
};


#endif // !1



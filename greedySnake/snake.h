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
	//�����˶��ķ���
	void setDirection(char c);
	//����������move��ʾ��������ƶ���Ҳ�����Զ��ƶ���
	void move();
	//��������move����ʾ�û�������ĳ����ť���ᵼ����λ�÷����仯��
	void move(char c);
	void eat();
	char getDirection();
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



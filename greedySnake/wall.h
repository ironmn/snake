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
	//��ʼ����ͼ
	void initWall();
	//չʾ��ͼ������Ԫ��
	void showWall();
	//�ṩһ���ⲿ�Ľӿڣ��ܹ��Ե�ͼ��Ԫ�ؽ����޸�
	void setMaze(node* param);
	//����ʵ��
	void setMaze(int x, int y, char c);
	//�ⲿ�Ķ�����Ի�ȡ��ͼԪ��
	char getElem(int x, int y);

	void drawSnake(node* para);

private:
	char gameArray[ROW][COL];
};




#endif // !__greedy__snake__wall

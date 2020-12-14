#pragma once
#ifndef __greedy__snake__wall
#define __greedy__snake__wall
#include<iostream>
#include"node.h"
#include"snake.h"
#include<stdio.h>
using namespace std;
class Wall
{
public:
	bool ate = false;
	bool fail = false;
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

	//����Ĭ�ϲ�����update����
	void update(Snake& snake, char direct = 'd');

	bool test(Snake& snake);

	void game_over();

	void update_food();

	void snake_eat(Snake& snake);

	int getScore() {
		return score;
	}

private:
	char gameArray[ROW][COL];
	int food_x, food_y;
	int score = 0;//Ĭ�ϵķ���Ϊ0;
protected:
	
};


#endif // !__greedy__snake__wall

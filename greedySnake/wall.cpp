#include"wall.h"
#define _TIME_LEAP 200;
#include<Windows.h>
#include<random>

bool Wall::ate = false;

void Wall :: initWall() {
	update_food();
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
				gameArray[i][j] = '#';
			}
			else gameArray[i][j] = ' ';
		}
	}
	gameArray[food_x][food_y] = 'o';
}

void Wall::showWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << gameArray[i][j] << " ";
		}
		if (i == 5) {
			cout << "����������";
		}
		if (i == 6) {
			cout << "W:�����ƶ�";
		}
		if (i == 7) {
			cout << "S:�����ƶ�";
		}
		if (i == 8) {
			cout << "A:�����ƶ�";
		}
		if (i == 9) {
			cout << "D:�����ƶ�";
		}
		cout << endl;
	}
}

void Wall::setMaze(node* param)
{
	gameArray[param->y][param->x] = param->icon;
}

void Wall::setMaze(int x, int y, char c)
{
	gameArray[y][x] = c;
}



char Wall::getElem(int x, int y)
{
	return gameArray[x][y];
}

void Wall::drawSnake(node* para)//paraָʾ������ͷ�Ľڵ�
{
	while (para != NULL) {
		setMaze(para);
		para = para->next;
	}
}
//�����ж�ʳ���Ƿ���������


void Wall::update(Snake& snake, char direct)
{
	
	if (!test(snake)) {
		//�����ǰ�����Ѿ������߽��ˣ��ʹ����쳣
		game_over();
		return;
	}
	if (snake.getHead()->y == food_x && snake.getHead()->x == food_y) {
		snake_eat(snake);
	}
	else if (direct == 'w' || direct == 'a' || direct == 's' || direct == 'd') {
		snake.move(direct);
	}
	initWall();
	//����
	drawSnake(snake.getHead());
	//����ʳ��
	if (!ate) {
		update_food();
		ate = true;
	}
	
	showWall();
}

bool Wall::test(Snake& snake)
{
	node* head = snake.getHead();
	char m = getElem(head->x, head->y);
	if (m == '#' || !snake.validate()) {//����ҧ�����Լ�
		//�����Ѿ�����ǽ��
		return false;//����false
	}
	return true;
}

void Wall::game_over()
{
	this->initWall();
	gameArray[15][8] = 'G';
	gameArray[15][10] = 'A';
	gameArray[15][12] = 'M';
	gameArray[15][14] = 'E';
	gameArray[15][18] = 'O';
	gameArray[15][20] = 'V';
	gameArray[15][22] = 'E';
	gameArray[15][24] = 'R';
	this->showWall();
}

int r() {
	return 2 + rand() % 28;
}
void Wall::update_food()
{
	if (ate == false) {
		food_x = r();
		food_y = r();
		while (gameArray[food_x][food_y] == '*' || gameArray[food_x][food_y] == '@')
		{
			food_x = r();
			food_y = r();
		}
	}
	ate = true;
}

void Wall::snake_eat(Snake& snake)
{
	ate = false;
	snake.eat();
}

#include"wall.h"
void Wall :: initWall() {
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


void Wall::update(Snake& snake, char direct)
{
	if (!test(snake)) {
		//�����ǰ�����Ѿ������߽��ˣ��ʹ����쳣
		game_over();
		return;
	}
	if(direct == 'w' || direct == 'a' || direct == 's' || direct == 'd'){
		snake.move(direct);
	}
	initWall();
	drawSnake(snake.getHead());
	showWall();
}

bool Wall::test(Snake& snake)
{
	node* head = snake.getHead();
	char m = getElem(head->x, head->y);
	if (m == '#' || m == '*') {
		//�����Ѿ�����ǽ������Լ���
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

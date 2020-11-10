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
			cout << "操作方法：";
		}
		if (i == 6) {
			cout << "W:向上移动";
		}
		if (i == 7) {
			cout << "S:向下移动";
		}
		if (i == 8) {
			cout << "A:向左移动";
		}
		if (i == 9) {
			cout << "D:向右移动";
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

void Wall::drawSnake(node* para)//para指示的是蛇头的节点
{
	while (para != NULL) {
		setMaze(para);
		para = para->next;
	}
}

#include"wall.h"
#include<random>
bool Wall::ate = false;

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
//用于判定食物是否在蛇里面


void Wall::update(Snake& snake, char direct)
{
	if (!test(snake)) {
		//如果当前的蛇已经碰到边界了，就处理异常
		game_over();
		return;
	}
	if(direct == 'w' || direct == 'a' || direct == 's' || direct == 'd'){
		snake.move(direct);
	}
	initWall();
	//画蛇
	drawSnake(snake.getHead());
	//更新食物
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
	if (m == '#' || m == '*') {
		//表明已经碰到墙体或者自己了
		return false;//返回false
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

void Wall::update_food()
{
	food_x = 1 + rand() % 31;
	food_y = 1 + rand() % 31;
	while (gameArray[food_x][food_y]=='*'||gameArray[food_x][food_y] == '@')
	{
		food_x = 1 + rand() % 31;
		food_y = 1 + rand() % 31;
	}
	gameArray[food_x][food_y] = 'o';
}

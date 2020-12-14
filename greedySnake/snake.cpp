#include"snake.h"

Snake::Snake()
{
	head = new node(1 + (rand() % 13), 1 + (rand() % 13), '@', NULL);
	tail = new node(head->x-1 , head->y, '*');
	head->next = tail;
	direct = 'd';
	length = 2;
}

Snake::~Snake()
{
	free(head);
	free(tail);
}

node* Snake::getHead()
{
	return head;
}

void Snake::setHead(node* temp)
{
	this->head = temp;
}

void Snake::setDirection(char c)
{
	this->direct = c;
}

//用于验证接下来的移动是否合法
bool Snake::validate()
{
	int x = next_position().first;
	int y = next_position().second;
	node* tmp = getHead();
	while (tmp)
	{
		if (x == tmp->x && y == tmp->y) return false;
		tmp = tmp->next;
	}
	return true;
}

//返回接下来要移动的坐标,这个坐标是实际坐标
pair<int,int> 
Snake::next_position() {
	//根据不同的方向来设定新的蛇头
	if (direct == 'w') return { head->x, head->y - 1 };
	else if (direct == 'a') return { head->x - 1, head->y };
	else if (direct == 's') return { head->x, head->y + 1 };
	else if (direct == 'd') return { head->x + 1, head->y };
}


void Snake::move()
{
	node* newHead = NULL;
	//根据不同的方向来设定新的蛇头
	newHead = new node(next_position().first, next_position().second, head->icon, head);
	
	//直接释放掉之前的old tail；这种做法是错误的。
	//delete操作是直接把指针变成一个野指针，而不是设置为NULL
	//删除尾部节点还是得用链表的基本用法。
	head->icon = '*';
	while (head->next != tail) {
		head = head->next;
	}
	head->next = NULL;
	delete tail;
	tail = head;
	head = newHead;
}



char Snake::getDirection()
{
	return this->direct;
}

bool is_opposite(pair<char, char> tmp)
{
	if (tmp.first == 'w' && tmp.second == 's' ||
		tmp.first == 's' && tmp.second == 'w' ||
		tmp.first == 'd' && tmp.second == 'a' ||
		tmp.first == 'a' && tmp.second == 'd')
		return true;
	return false;
}
//这个方法用于转向以后的移动操作
void Snake::move(char c)
{
	//如果不是相反的方向，那么可以转向,否则就只能继续前进
	if (!is_opposite({ c,getDirection() }))
		setDirection(c);
	move();
}

void Snake::eat()
{
	node* newHead = NULL;
	newHead = new node(next_position().first, next_position().second, head->icon, head);
	head->icon = '*';
	head = newHead;
	length++;
}


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

void Snake::move()
{
	node* newHead = NULL;
	//根据不同的方向来设定新的蛇头
	if (direct == 'w') newHead = new node(head->x, head->y - 1, head->icon, head);
	else if (direct == 'a') newHead = new node(head->x - 1, head->y, head->icon, head);
	else if (direct == 's') newHead = new node(head->x, head->y+1, head->icon, head);
	else if (direct == 'd') newHead = new node(head->x+1, head->y, head->icon, head);
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

//这个方法用于转向以后的移动操作
void Snake::move(char c)
{
	if (is_opposite({ c,getDirection() }))
		setDirection(c);
	move();
}

bool is_opposite(pair<char,char> tmp)
{
	if (tmp.first == 'w' && tmp.second == 's' ||
		tmp.first == 's' && tmp.second == 'w' ||
		tmp.first == 'd' && tmp.second == 'a' ||
		tmp.first == 'a' && tmp.second == 'd')
		return true;
	return false;
}
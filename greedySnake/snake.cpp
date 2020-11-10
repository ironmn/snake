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

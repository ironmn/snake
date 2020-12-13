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
	//���ݲ�ͬ�ķ������趨�µ���ͷ
	if (direct == 'w') newHead = new node(head->x, head->y - 1, head->icon, head);
	else if (direct == 'a') newHead = new node(head->x - 1, head->y, head->icon, head);
	else if (direct == 's') newHead = new node(head->x, head->y+1, head->icon, head);
	else if (direct == 'd') newHead = new node(head->x+1, head->y, head->icon, head);
	//ֱ���ͷŵ�֮ǰ��old tail�����������Ǵ���ġ�
	//delete������ֱ�Ӱ�ָ����һ��Ұָ�룬����������ΪNULL
	//ɾ��β���ڵ㻹�ǵ�������Ļ����÷���
	head->icon = '*';
	while (head->next != tail) {
		head = head->next;
	}
	head->next = NULL;
	delete tail;
	tail = head;
	head = newHead;
}

//�����������ת���Ժ���ƶ�����
void Snake::move(char c)
{
	setDirection(c);
	move();
}

char Snake::getDirection()
{
	return this->direct;
}

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
//�����������ת���Ժ���ƶ�����
void Snake::move(char c)
{
	//��������෴�ķ�����ô����ת��,�����ֻ�ܼ���ǰ��
	if (!is_opposite({ c,getDirection() }))
		setDirection(c);
	move();
}


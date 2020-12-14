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

//������֤���������ƶ��Ƿ�Ϸ�
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

//���ؽ�����Ҫ�ƶ�������,���������ʵ������
pair<int,int> 
Snake::next_position() {
	//���ݲ�ͬ�ķ������趨�µ���ͷ
	if (direct == 'w') return { head->x, head->y - 1 };
	else if (direct == 'a') return { head->x - 1, head->y };
	else if (direct == 's') return { head->x, head->y + 1 };
	else if (direct == 'd') return { head->x + 1, head->y };
}


void Snake::move()
{
	node* newHead = NULL;
	//���ݲ�ͬ�ķ������趨�µ���ͷ
	newHead = new node(next_position().first, next_position().second, head->icon, head);
	
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

void Snake::eat()
{
	node* newHead = NULL;
	newHead = new node(next_position().first, next_position().second, head->icon, head);
	head->icon = '*';
	head = newHead;
	length++;
}


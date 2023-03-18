#pragma once
#include "SpaceObject.h"

ref struct node // узел списка
{
	SpaceObject^ inf; // указатель на объект
	node^ next; // следующий узел
	node^ prev; // предыдущий узел

	node() 
	{ 
		inf = nullptr; 
		next = prev = nullptr; 
	}
};

ref class List // список объектов
{
private:
	node^ head; // голова и хвост
	node^ tail;
public:
	List() { head = tail = nullptr; }
	node^ GetHead() { return head; }
	node^ GetTail() { return tail; }

	void add(SpaceObject^ obj) // добавление объекта в список
	{
		node^ NewNode = gcnew node;
		NewNode->inf = obj;

		if (!head && !tail)
		{
			head = tail = NewNode;
			return;
		}

		tail->next = NewNode;
		NewNode->prev = tail;
		tail = NewNode;
	}
	void del(node^ ptr) // удаление узла
	{
		if (!ptr->next && !ptr->prev)
		{
			head = tail = nullptr;
			delete(ptr);
			return;
		}

		if (!ptr->next)
		{
			tail = ptr->prev;
			tail->next = nullptr;
			delete(ptr);
			return;
		}

		if (!ptr->prev)
		{
			head = ptr->next;
			head->prev = nullptr;
			delete(ptr);
			return;
		}

		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		delete(ptr);
		return;
	}
	void del(SpaceObject^ obj) // поиск объекта в списке и его удаление
	{
		for(node^ ptr = head; ptr; ptr = ptr->next)
			if (ptr->inf == obj)
			{
				del(ptr);
				return;
			}
	}
	void Draw() // рисование всего списка
	{
		for (node^ ptr = head; ptr; ptr = ptr->next)
			ptr->inf->Draw();
	}
	void CalcAllAcc() // расчёт всех ускорений в данный момент
	{
		for (node^ i = head; i; i = i->next)
		{
			point^ a = gcnew point;

			for(node^ j = head; j; j = j->next)
				if (j != i)
				{
					a = a + i->inf->CalcAcc(j->inf);
				}

			i->inf->SetAcc(a);
		}
	}
	void Move() // движение всей системы
	{
		for (node^ ptr = head; ptr; ptr = ptr->next)
			ptr->inf->Move();
	}
	void mult(double x, double y, double val) // растяжение/сжатие списка относительно точки
	{
		for (node^ ptr = head; ptr; ptr = ptr->next)
			ptr->inf->mult(x, y, val);
	}
	void MoveByMouse(int dx, int dy) // смещение всей системы
	{
		for (node^ ptr = head; ptr; ptr = ptr->next)
			ptr->inf->MoveByMouse(dx, dy);
	}
};
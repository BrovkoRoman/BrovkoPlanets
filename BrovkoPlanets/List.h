#pragma once
#include "SpaceObject.h"

ref struct node // ���� ������
{
	SpaceObject^ inf; // ��������� �� ������
	node^ next; // ��������� ����
	node^ prev; // ���������� ����

	node() 
	{ 
		inf = nullptr; 
		next = prev = nullptr; 
	}
};

ref class List // ������ ��������
{
private:
	node^ head; // ������ � �����
	node^ tail;
public:
	List() { head = tail = nullptr; }
	node^ GetHead() { return head; }
	node^ GetTail() { return tail; }

	void add(SpaceObject^ obj) // ���������� ������� � ������
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
	void del(node^ ptr) // �������� ����
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
	void del(SpaceObject^ obj) // ����� ������� � ������ � ��� ��������
	{
		for(node^ ptr = head; ptr; ptr = ptr->next)
			if (ptr->inf == obj)
			{
				del(ptr);
				return;
			}
	}
	void Draw() // ��������� ����� ������
	{
		for (node^ ptr = head; ptr; ptr = ptr->next)
			ptr->inf->Draw();
	}
	void CalcAllAcc() // ������ ���� ��������� � ������ ������
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
	void Move() // �������� ���� �������
	{
		for (node^ ptr = head; ptr; ptr = ptr->next)
			ptr->inf->Move();
	}
	void mult(double x, double y, double val) // ����������/������ ������ ������������ �����
	{
		for (node^ ptr = head; ptr; ptr = ptr->next)
			ptr->inf->mult(x, y, val);
	}
	void MoveByMouse(int dx, int dy) // �������� ���� �������
	{
		for (node^ ptr = head; ptr; ptr = ptr->next)
			ptr->inf->MoveByMouse(dx, dy);
	}
};
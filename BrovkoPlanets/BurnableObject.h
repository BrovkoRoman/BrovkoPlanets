#pragma once
#include "SpaceObject.h"
#include "List.h"

public ref class BurnableObject : SpaceObject // ������, ��������� �� ������ - ��� �������
{
protected:
	static List^ L; // ����� ������ �������, ����� ������� ��� �� ������, ������� ������ ��������� �� ������
public:
	BurnableObject() : SpaceObject() {}
	BurnableObject(bool* ShowName, String^ Name, double x, double y, double vx, double vy, double R, double mass, Brush^ Color) :
		SpaceObject(ShowName, Name, x, y, vx, vy, R, mass, Color) {}

	virtual void Move() override // ������ ��� �������� ����� �������
	{
		vx += ax;
		vy += ay;
		x += vx;
		y += vy;

		if (dist(Sun) <= Sun->Get_R()) // ������� �������, ���� � ����� ��������� �� ������
		{
			Sun->Set_vx((Sun->Get_vx() * Sun->Get_mass() + this->vx * this->mass) / (this->mass + Sun->Get_mass())); // ������ ��������� ����� � �������
			Sun->Set_vy((Sun->Get_vy() * Sun->Get_mass() + this->vy * this->mass) / (this->mass + Sun->Get_mass()));
			Sun->Set_mass(Sun->Get_mass() + this->mass);
			L->del(this); // ������� �������
		}
	}
};
#pragma once

#include "BurnableObject.h"

public ref class Satellite : BurnableObject // �������� ����������� �� ��������� ��������
{
private:
	SpaceObject^ ancestor; // �������, ������� ���� �������
public:
	Satellite() : BurnableObject() {}
	// ����� ������ ������� �������� - �����������, ��������� � ��������
	Satellite(bool* ShowName, String^ Name, SpaceObject^ ancestor, double dist, double v, double R, double mass, Brush^ Color) : BurnableObject(ShowName, Name, ancestor->Get_x() + dist, ancestor->Get_y(), 0, v, R, mass, Color)
	{
		this->ancestor = ancestor;
	}
};
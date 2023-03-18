#pragma once
#include "SpaceObject.h"
#include "List.h"

public ref class BurnableObject : SpaceObject // объект, сгорающий на Солнце - это планеты
{
protected:
	static List^ L; // когда объект сгорает, нужно удалить его из списка, поэтому храним указатель на список
public:
	BurnableObject() : SpaceObject() {}
	BurnableObject(bool* ShowName, String^ Name, double x, double y, double vx, double vy, double R, double mass, Brush^ Color) :
		SpaceObject(ShowName, Name, x, y, vx, vy, R, mass, Color) {}

	virtual void Move() override // теперь при движении можно сгореть
	{
		vx += ax;
		vy += ay;
		x += vx;
		y += vy;

		if (dist(Sun) <= Sun->Get_R()) // планета сгорает, если её центр находится на Солнце
		{
			Sun->Set_vx((Sun->Get_vx() * Sun->Get_mass() + this->vx * this->mass) / (this->mass + Sun->Get_mass())); // Солнце поглощает массу и импульс
			Sun->Set_vy((Sun->Get_vy() * Sun->Get_mass() + this->vy * this->mass) / (this->mass + Sun->Get_mass()));
			Sun->Set_mass(Sun->Get_mass() + this->mass);
			L->del(this); // удаляем планету
		}
	}
};
#pragma once

#include "List.h"
#include "BurnableObject.h"

public ref class Comet : BurnableObject // кометы - это сгораемые объекты
{
public:
	Comet() : BurnableObject() {}
	Comet(bool* ShowName, SpaceObject^ Sun, List^ L, String^ Name, double x, double y, double vx, double vy, double R, double mass, Brush^ Color) :
		BurnableObject(ShowName, Name, x, y, vx, vy, R, mass, Color)
	{ // этот конструктор нужен, чтобы передать статические указатели L и Sun
		this->L = L;
		this->Sun = Sun;
	}
	Comet(bool* ShowName, String^ Name, double x, double y, double vx, double vy, double R, double mass, Brush^ Color) :
		BurnableObject(ShowName, Name, x, y, vx, vy, R, mass, Color) {}

	void Move() override // кометы могут сгореть не только на Солнце, их могут запустить куда угодно
	{
		vx += ax;
		vy += ay;
		x += vx;
		y += vy;

		for (node^ ptr = L->GetHead(); ptr; ptr = ptr->next) // поэтому перебираем, где мы сгорим
			if (ptr->inf != this && dist(ptr->inf) <= ptr->inf->Get_R())
			{ // планета также может поглощать импульс и массу
				ptr->inf->Set_vx((ptr->inf->Get_vx() * ptr->inf->Get_mass() + this->vx * this->mass) / (this->mass + ptr->inf->Get_mass()));
				ptr->inf->Set_vy((ptr->inf->Get_vy() * ptr->inf->Get_mass() + this->vy * this->mass) / (this->mass + ptr->inf->Get_mass()));
				ptr->inf->Set_mass(ptr->inf->Get_mass() + this->mass);
				L->del(this); // удаляем комету
			}
	}
};
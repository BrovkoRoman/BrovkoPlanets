#pragma once
#include <cmath>
using namespace System;
using namespace System::Drawing;

ref struct point // ��������� ����� � ����������� + � - � �������� ��������
{
	double x;
	double y;

	point() { x = y = 0; }
	point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	point^ operator +(point^ pt1)
	{
		return gcnew point(this->x + pt1->x, this->y + pt1->y);
	}
	point^ operator -(point^ pt1)
	{
		return gcnew point(this->x - pt1->x, this->y - pt1->y);
	}

	void Rotate(double phi)
	{
		double R = sqrt(x * x + y * y);
		double Phi = atan2(y, x);
		Phi += phi;
		x = R * cos(Phi);
		y = R * sin(Phi);
	}
};
public ref class SpaceObject // ����������� ������ - ����� ������� �����, � ���� ��������� ������ ������
{
protected:
	static SpaceObject^ Sun; // ��������� �� ������
	double x, y, vx, vy, ax, ay, R, mass; // ����������, ��������, ���������, �����
	Brush^ Color; // ����
	String^ Name; // ���
	bool* ShowName; // ����� �� ���������� ���
public:
	static System::Windows::Forms::PaintEventArgs^ eventarg; // �������� ��� ���������
	void SetAcc(point^ p) // ������� ������������ ��������� �� �����
	{
		ax = p->x;
		ay = p->y;
	}
	SpaceObject() {} // ������������
	SpaceObject(bool* ShowName, String^ Name, double x, double y, double vx, double vy, double R, double mass, Brush^ Color)
	{
		this->ShowName = ShowName;
		this->Name = Name;
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
		this->R = R;
		this->mass = mass;
		this->Color = Color;
	}
	void Draw() // ��������� �������
	{
		eventarg->Graphics->FillEllipse(Color, Rectangle(x - R, y - R, 2 * R, 2 * R)); // ������ ���

		if (*ShowName) // ���������� �������, ���� �����
		{
			String^ drawString = Name;
			Font^ drawFont = gcnew Font("Arial", 16);
			SolidBrush^ drawBrush = gcnew SolidBrush(Color::White);
			eventarg->Graphics->DrawString(Name, drawFont, drawBrush, x - Name->Length * 7, y + R);
		}
	}
	virtual void Move() // �������� �������
	{
		vx += ax; // �� 1 ������������ ������� ������� � �������� ������������ ���������, � � ����������� ��������
		vy += ay;
		x += vx;
		y += vy;
	}
	double sqrdist(SpaceObject^ obj) // ������� ���������� �� ������� �������
	{
		return (this->x - obj->x) * (this->x - obj->x) + (this->y - obj->y) * (this->y - obj->y);
	}
	double dist(SpaceObject^ obj) // ���������� �� ������� �������
	{
		return sqrt(sqrdist(obj));
	}
	double distx(SpaceObject^ obj) // ���������� �� x
	{
		return obj->x - this->x;
	}
	double disty(SpaceObject^ obj) // ���������� �� y
	{
		return obj->y - this->y;
	}
	point^ CalcAcc(SpaceObject^ obj) // ������ ���������, ����������� �� ������� �������
	{
		double Abs_a = obj->mass / this->sqrdist(obj); // ��������� g ~ M / R ^ 2
		double ax = Abs_a / dist(obj) * distx(obj);
		double ay = Abs_a / dist(obj) * disty(obj);
		return gcnew point(ax, ay);
	}
	void mult(double x, double y, double val) // ����������/������ ������� ������������ ����� (x, y) � val ���
	{
		this->x -= x;
		this->x *= val;
		this->x += x;

		this->y -= y;
		this->y *= val;
		this->y += y;

		this->vx *= val;
		this->vy *= val;
		this->ax *= val;
		this->ay *= val;
		this->R *= val;
		this->mass *= val * val * val; // ��� ���������� ���������� � val ��� ��������� ���� ������ ����������� � val ���
		// �� ��� ����������� � val ^ 2, ������� �������� ��� ������
	}
	void MoveByMouse(int dx, int dy) // �������� ������� �� (dx, dy)
	{
		this->x += dx;
		this->y += dy;
	}
	void Rotate(double phi) // ������� �� ���� phi ������ ������� �������
	{
		point^ r = gcnew point(x, y);
		r->Rotate(phi);
		x = r->x, y = r->y;

		point^ v = gcnew point(vx, vy);
		v->Rotate(phi);
		vx = v->x, vy = v->y;

		point^ a = gcnew point(ax, ay);
		a->Rotate(phi);
		ax = a->x, ay = a->y;
	}
	void Rotate(double phi, point^ O) // ������� ������������ �����
	{
		point^ r = gcnew point(x, y);
		r -= O;
		r->Rotate(phi);
		r += O;
		x = r->x, y = r->y;

		point^ v = gcnew point(vx, vy);
		v->Rotate(phi);
		vx = v->x, vy = v->y;

		point^ a = gcnew point(ax, ay);
		a->Rotate(phi);
		ax = a->x, ay = a->y;
	}
	void Rotate(double phi, SpaceObject^ obj) // ������� ������������ �������
	{
		Rotate(phi, gcnew point(obj->x, obj->y));
	}
	double Get_x() { return x; } // ������� � �������
	double Get_y() { return y; }
	double Get_vx() { return vx; }
	double Get_vy() { return vy; }
	double Get_R() { return R; }
	double Get_mass() { return mass; }
	Brush^ Get_Color() { return Color; }
	void Set_x(double x) { this->x = x; }
	void Set_y(double y) { this->y = y; }
	void Set_vx(double vx) { this->vx = vx; }
	void Set_vy(double vy) { this->vy = vy; }
	void Set_R(double R) { this->R = R; }
	void Set_mass(double mass) { this->mass = mass; }
	void Set_Color(Brush^ Color) { this->Color = Color; }
};


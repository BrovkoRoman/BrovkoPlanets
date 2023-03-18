#pragma once
#include "SpaceObject.h"
#include "List.h"
#include "BurnableObject.h"
#include "Comet.h"
#include "Satellite.h"
#include <time.h>
namespace BrovkoPlanets {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timerForMoving;
	private: System::Windows::Forms::Button^ btnFaster;
	private: System::Windows::Forms::Button^ btnSlower;
	private: System::Windows::Forms::Label^ lblCometMass;
	private: System::Windows::Forms::TextBox^ txtCometMass;
	private: System::Windows::Forms::Button^ btnLaunchComet;
	private: System::Windows::Forms::Button^ btnShowSunName;
	private: System::Windows::Forms::Button^ btnShowPlanetName;
	private: System::Windows::Forms::Button^ btnShowSatelliteName;
	private: System::Windows::Forms::Button^ btnShowCometName;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::Button^ btnDeleteComet;


	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timerForMoving = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnFaster = (gcnew System::Windows::Forms::Button());
			this->btnSlower = (gcnew System::Windows::Forms::Button());
			this->lblCometMass = (gcnew System::Windows::Forms::Label());
			this->txtCometMass = (gcnew System::Windows::Forms::TextBox());
			this->btnLaunchComet = (gcnew System::Windows::Forms::Button());
			this->btnShowSunName = (gcnew System::Windows::Forms::Button());
			this->btnShowPlanetName = (gcnew System::Windows::Forms::Button());
			this->btnShowSatelliteName = (gcnew System::Windows::Forms::Button());
			this->btnShowCometName = (gcnew System::Windows::Forms::Button());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->btnDeleteComet = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-4, -4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(526, 252);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			this->pictureBox1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseWheel);
			this->pictureBox1->Resize += gcnew System::EventHandler(this, &MyForm::pictureBox1_Resize);
			// 
			// timerForMoving
			// 
			this->timerForMoving->Enabled = true;
			this->timerForMoving->Interval = 40;
			this->timerForMoving->Tick += gcnew System::EventHandler(this, &MyForm::timerForMoving_Tick);
			// 
			// btnFaster
			// 
			this->btnFaster->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnFaster->Location = System::Drawing::Point(38, 42);
			this->btnFaster->Name = L"btnFaster";
			this->btnFaster->Size = System::Drawing::Size(161, 61);
			this->btnFaster->TabIndex = 1;
			this->btnFaster->Text = L"Быстрее";
			this->btnFaster->UseVisualStyleBackColor = true;
			this->btnFaster->Click += gcnew System::EventHandler(this, &MyForm::btnFaster_Click);
			// 
			// btnSlower
			// 
			this->btnSlower->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnSlower->Location = System::Drawing::Point(38, 130);
			this->btnSlower->Name = L"btnSlower";
			this->btnSlower->Size = System::Drawing::Size(161, 61);
			this->btnSlower->TabIndex = 2;
			this->btnSlower->Text = L"Медленнее";
			this->btnSlower->UseVisualStyleBackColor = true;
			this->btnSlower->Click += gcnew System::EventHandler(this, &MyForm::btnSlower_Click);
			// 
			// lblCometMass
			// 
			this->lblCometMass->AutoSize = true;
			this->lblCometMass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblCometMass->Location = System::Drawing::Point(34, 221);
			this->lblCometMass->Name = L"lblCometMass";
			this->lblCometMass->Size = System::Drawing::Size(192, 40);
			this->lblCometMass->TabIndex = 3;
			this->lblCometMass->Text = L"Масса кометы\r\n(в % от массы Земли)";
			// 
			// txtCometMass
			// 
			this->txtCometMass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtCometMass->Location = System::Drawing::Point(38, 274);
			this->txtCometMass->Name = L"txtCometMass";
			this->txtCometMass->Size = System::Drawing::Size(188, 27);
			this->txtCometMass->TabIndex = 4;
			this->txtCometMass->Text = L"0,0001";
			// 
			// btnLaunchComet
			// 
			this->btnLaunchComet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnLaunchComet->Location = System::Drawing::Point(38, 319);
			this->btnLaunchComet->Name = L"btnLaunchComet";
			this->btnLaunchComet->Size = System::Drawing::Size(161, 61);
			this->btnLaunchComet->TabIndex = 5;
			this->btnLaunchComet->Text = L"Запустить комету";
			this->btnLaunchComet->UseVisualStyleBackColor = true;
			this->btnLaunchComet->Click += gcnew System::EventHandler(this, &MyForm::btnLaunchComet_Click);
			// 
			// btnShowSunName
			// 
			this->btnShowSunName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnShowSunName->Location = System::Drawing::Point(38, 476);
			this->btnShowSunName->Name = L"btnShowSunName";
			this->btnShowSunName->Size = System::Drawing::Size(161, 61);
			this->btnShowSunName->TabIndex = 6;
			this->btnShowSunName->Text = L"Подпись к Солнцу";
			this->btnShowSunName->UseVisualStyleBackColor = true;
			this->btnShowSunName->Click += gcnew System::EventHandler(this, &MyForm::btnShowSunName_Click);
			// 
			// btnShowPlanetName
			// 
			this->btnShowPlanetName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btnShowPlanetName->Location = System::Drawing::Point(38, 543);
			this->btnShowPlanetName->Name = L"btnShowPlanetName";
			this->btnShowPlanetName->Size = System::Drawing::Size(161, 61);
			this->btnShowPlanetName->TabIndex = 7;
			this->btnShowPlanetName->Text = L"Подписи к планетам";
			this->btnShowPlanetName->UseVisualStyleBackColor = true;
			this->btnShowPlanetName->Click += gcnew System::EventHandler(this, &MyForm::btnShowPlanetName_Click);
			// 
			// btnShowSatelliteName
			// 
			this->btnShowSatelliteName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btnShowSatelliteName->Location = System::Drawing::Point(38, 610);
			this->btnShowSatelliteName->Name = L"btnShowSatelliteName";
			this->btnShowSatelliteName->Size = System::Drawing::Size(161, 61);
			this->btnShowSatelliteName->TabIndex = 8;
			this->btnShowSatelliteName->Text = L"Подписи к спутникам";
			this->btnShowSatelliteName->UseVisualStyleBackColor = true;
			this->btnShowSatelliteName->Click += gcnew System::EventHandler(this, &MyForm::btnShowSatelliteName_Click);
			// 
			// btnShowCometName
			// 
			this->btnShowCometName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btnShowCometName->Location = System::Drawing::Point(38, 677);
			this->btnShowCometName->Name = L"btnShowCometName";
			this->btnShowCometName->Size = System::Drawing::Size(161, 61);
			this->btnShowCometName->TabIndex = 9;
			this->btnShowCometName->Text = L"Подписи к кометам";
			this->btnShowCometName->UseVisualStyleBackColor = true;
			this->btnShowCometName->Click += gcnew System::EventHandler(this, &MyForm::btnShowCometName_Click);
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// btnDeleteComet
			// 
			this->btnDeleteComet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDeleteComet->Location = System::Drawing::Point(38, 395);
			this->btnDeleteComet->Name = L"btnDeleteComet";
			this->btnDeleteComet->Size = System::Drawing::Size(161, 61);
			this->btnDeleteComet->TabIndex = 10;
			this->btnDeleteComet->Text = L"Удалить комету";
			this->btnDeleteComet->UseVisualStyleBackColor = true;
			this->btnDeleteComet->Click += gcnew System::EventHandler(this, &MyForm::btnDeleteComet_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1648, 989);
			this->Controls->Add(this->btnDeleteComet);
			this->Controls->Add(this->btnShowCometName);
			this->Controls->Add(this->btnShowSatelliteName);
			this->Controls->Add(this->btnShowPlanetName);
			this->Controls->Add(this->btnShowSunName);
			this->Controls->Add(this->btnLaunchComet);
			this->Controls->Add(this->txtCometMass);
			this->Controls->Add(this->lblCometMass);
			this->Controls->Add(this->btnSlower);
			this->Controls->Add(this->btnFaster);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"Солнечная система";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void ClearErrors() // очистка ошибок, нужно использовать при нажатии на кнопки
	{
		errorProvider1->SetError(txtCometMass, "");
	}

	private: 
		List^ L = gcnew List; // список всех объектов
		bool LaunchComet = false; // запускаем ли мы спутник
		bool IsPressed = false; // нажата ли кнопка мыши
		int mousex = -100, mousey = -100; // координаты курсора

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) { // событие перерисовки
		int w = this->pictureBox1->Width; // определяем размеры элемента PictureBox
		int h = this->pictureBox1->Height;
		Point ltp(0, 0); // крайние точки
		Point rbp(w, h);
		e->Graphics->FillRectangle(Brushes::Black, ltp.X, ltp.Y, rbp.X - ltp.X, rbp.Y - ltp.Y); // красим всё в чёрный цвет
		
		Sun->eventarg = e; // добавляем аргумент e этого события в статическую переменную космических объектов, чтобы они сами могли рисоваться
		L->Draw(); // теперь можно нарисовать весь список

		if (LaunchComet) // если мы запускаем комету
		{
			if (IsPressed) // проверяем, зажата ли кнопка мыши; если да, то рисуем красную линию от кометы до мыши
			{
				e->Graphics->FillEllipse(Brushes::Yellow, Rectangle(comet->Get_x() - 10, comet->Get_y() - 10, 20, 20));
				e->Graphics->DrawLine(Pens::Red, Point(comet->Get_x(), comet->Get_y()), Point(mousex, mousey));
			} // иначе рисуем комету рядом с курсором
			else e->Graphics->FillEllipse(Brushes::Yellow, Rectangle(mousex - 10, mousey - 10, 20, 20));
		}
	}

	private: 
		int speed = 10; // скорость просмотра и ускорение от кнопок Быстрее и Медленнее
		double MinSpeedScale = 4;

	private: System::Void timerForMoving_Tick(System::Object^ sender, System::EventArgs^ e) { // время двигаться

		for (int i = 0; i < speed; i++) // делаем speed шагов
		{
			L->CalcAllAcc(); // двигаем все объекты
			L->Move();
		}

		this->pictureBox1->Invalidate(); // перерисовываем изображение
	}
	private:
		const double AU = 2000.0; // константы для создания объектов
		const double EarthRadius = 40;
		const double SunRadius = EarthRadius * 109 * 0.1;
		const double EarthMass = 5;
		const double BigPlanetMassCoef = 0.01;
		const double SunMass = 2800;
		const double kms = 0.04;
		const double PhobosDeimosKms = 0.1;
		double CometMass; // изначальная масса кометы
		double CometRadius = 10; // изначальный радиус кометы
		Comet^ comet; // комета (она может быть только одна)
		bool* ShowPlanetName = new bool; // переменные, отвечающие за подписи
		bool* ShowSunName = new bool;
		bool* ShowSatelliteName = new bool;
		bool* ShowCometName = new bool;
		SpaceObject^ Sun = gcnew SpaceObject(ShowSunName, "Солнце", 0, 0, 0, 0, SunRadius, SunMass, Brushes::Yellow); // Солнце

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) { // при загрузке формы
		pictureBox1->Width = MyForm::Width; // расширяем pictureBox на всю форму
		pictureBox1->Height = MyForm::Height;

		*ShowSunName = true; // включаем все подписи
		*ShowPlanetName = true;
		*ShowSatelliteName = true;
		*ShowCometName = true;

		double phi0; // это угол, на который будем крутить планеты и спутники
		srand(time(NULL));
		double pi = acos(-1);

		L->add(Sun); // добавляем Солнце в список

		BurnableObject^ Mercury = gcnew BurnableObject(ShowPlanetName, "Меркурий", 0.4 * AU, 0, 0, 47.36 * kms, 0.38 * EarthRadius, 0.055 * EarthMass, Brushes::Orange);
		phi0 = rand() / 65536.0 * 2 * pi; // создаём Меркурий и крутим его на случайный угол относительно Солнца (которое находится в нуле)
		Mercury->Rotate(phi0);
		L->add(Mercury);

		BurnableObject^ Venus = gcnew BurnableObject(ShowPlanetName, "Венера", 0.72 * AU, 0, 0, 35.02 * kms, 0.95 * EarthRadius, 0.815 * EarthMass, Brushes::LightGray);
		phi0 = rand();
		Venus->Rotate(phi0);
		L->add(Venus);

		BurnableObject^ Earth = gcnew BurnableObject(ShowPlanetName, "Земля", 1 * AU, 0, 0, 29.78 * kms, 1 * EarthRadius, 1 * EarthMass, Brushes::Blue);
		phi0 = rand();
		Earth->Rotate(phi0);
		L->add(Earth);

		Satellite^ Moon = gcnew Satellite(ShowSatelliteName, "Луна", Earth, 70, (29.78 + 6.5) * kms, 0.27 * EarthRadius, 0.012 * EarthMass, Brushes::Gray);
		Moon->Rotate(phi0, Earth);
		L->add(Moon);

		BurnableObject^ Mars = gcnew BurnableObject(ShowPlanetName, "Марс", 1.5 * AU, 0, 0, 24.13 * kms, 0.53 * EarthRadius, 0.507 * EarthMass, Brushes::Red); // масса Марса увеличена, чтобы лучше держались спутники
		phi0 = rand();
		Mars->Rotate(phi0);
		L->add(Mars);

		Satellite^ Phobos = gcnew Satellite(ShowSatelliteName, "Фобос", Mars, 60, 24.13 * kms + 2.14 * PhobosDeimosKms, 0.017 * EarthRadius, 1.8e-9 * EarthMass, Brushes::Gray);
		Phobos->Rotate(phi0, Mars);
		L->add(Phobos);

		Satellite^ Deimos = gcnew Satellite(ShowSatelliteName, "Деймос", Mars, 100, 24.13 * kms + 1.35 * PhobosDeimosKms, 0.0097 * EarthRadius, 2.48e-10 * EarthMass, Brushes::Gray);
		Deimos->Rotate(phi0, Mars);
		L->add(Deimos);

		BurnableObject^ Jupiter = gcnew BurnableObject(ShowPlanetName, "Юпитер", 5.2 * AU, 0, 0, 13.07 * kms, 10.97 * EarthRadius, 317.8 * EarthMass * BigPlanetMassCoef, Brushes::Brown);
		phi0 = rand();
		Jupiter->Rotate(phi0);
		L->add(Jupiter);

		BurnableObject^ Saturn = gcnew BurnableObject(ShowPlanetName, "Сатурн", 9.6 * AU, 0, 0, 9.69 * kms, 9.14 * EarthRadius, 95.2 * EarthMass * BigPlanetMassCoef, Brushes::LightGray);
		phi0 = rand();
		Saturn->Rotate(phi0);
		L->add(Saturn);

		BurnableObject^ Uranus = gcnew BurnableObject(ShowPlanetName, "Уран", 19.2 * AU, 0, 0, 6.81 * kms, 3.98 * EarthRadius, 14.54 * EarthMass * BigPlanetMassCoef, Brushes::LightBlue);
		phi0 = rand();
		Uranus->Rotate(phi0);
		L->add(Uranus);

		BurnableObject^ Neptune = gcnew BurnableObject(ShowPlanetName, "Нептун", 30.4 * AU, 0, 0, 5.43 * kms, 3.86 * EarthRadius, 17.15 * EarthMass * BigPlanetMassCoef, Brushes::Blue);
		phi0 = rand();
		Neptune->Rotate(phi0);
		L->add(Neptune);

		L->MoveByMouse(1000, 0); // сдвигаем картину вправо, чтобы не так сильно загораживали кнопки

		comet = gcnew Comet(ShowCometName, Sun, L, "Комета", 0, 0, -0.3, 0.3, 10, 0, Brushes::Yellow);
		// создаём комету и записываем в статические переменные адрес Солнца и списка

		srand(time(NULL)); // двигаем всё, чтобы спутники располагались случайно
		int k = rand() % 10000;

		for (int i = 0; i < k; i++)
		{
			L->CalcAllAcc();
			L->Move();
		}
	}
	private: System::Void pictureBox1_Resize(System::Object^ sender, System::EventArgs^ e) { // это функция для перерисовки, если изменят размер pictureBox
		System::Drawing::Graphics^ graph = this->pictureBox1 -> CreateGraphics();
		System::Drawing::Rectangle rect;
		System::Windows::Forms::PaintEventArgs^ e1 = gcnew
			System::Windows::Forms::PaintEventArgs(graph, rect);
		OnPaint(e1);
	}
private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) { // а это для изменения размеров формы: подстраиваем размер pictureBox
	pictureBox1->Width = MyForm::Width;
	pictureBox1->Height = MyForm::Height;
}
private: System::Void pictureBox1_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { // масштабирование колесиком
	const double minscale = 1.2;
	int k = e->Delta / 120;

	while (k > 0)
	{
		k--;
		L->mult(e->X, e->Y, minscale);
	}

	while (k < 0)
	{
		k++;
		L->mult(e->X, e->Y, 1.0 / minscale);
	}
}

private: 
	int prev_x; // теперь  реализуем перемещение с помощью мыши
	int prev_y; // для этого запомним предыдущую позицию курсора

private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) // при нажатии левой кнопки мыши
	{
		IsPressed = true; // реализуем сразу 2 действия: поставим флажок нажатой кнопки
		prev_x = e->X;
		prev_y = e->Y;

		if (LaunchComet) // и проверим, не нужно ли запускать комету
		{
			L->del(comet);
			comet->Set_x(e->X);
			comet->Set_y(e->Y);
		}
	}
}
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (LaunchComet && IsPressed) // если отпущена левая кнопка мыши и нужно запустить комету
		{
			comet->Set_R(CometRadius * Sun->Get_R() / SunRadius); // считаем параметры кометы с учётом масштабирования
			comet->Set_vx((e->X - comet->Get_x()) / 100 * Sun->Get_R() / SunRadius);
			comet->Set_vy((e->Y - comet->Get_y()) / 100 * Sun->Get_R() / SunRadius);
			L->add(comet); // добавляем комету в список объектов
			LaunchComet = false; // теперь нам не нужно запускать комету
			mousex = mousey = -100; // координаты новой кометы выведем из поля зрения
		}

		IsPressed = false; // теперь кнопка не нажата
	}
}
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (LaunchComet) // при перемещении мыши запоминаем её координаты
	{
		mousex = e->X;
		mousey = e->Y;
	}
	else if (IsPressed) // если не запускается комета, а мышь нажата, то это перетаскивание
	{
		L->MoveByMouse(e->X - prev_x, e->Y - prev_y);
		prev_x = e->X;
		prev_y = e->Y;
	}
}

private: System::Void btnFaster_Click(System::Object^ sender, System::EventArgs^ e) { // ускорение показа
	ClearErrors(); // кнопка нажата, нужно очистить ошибки
	int NewSpeed = speed * MinSpeedScale;

	if (NewSpeed > 1000)
		speed = 1000;
	else
		if (NewSpeed == speed)
			speed++;
		else speed = NewSpeed;
}
private: System::Void btnSlower_Click(System::Object^ sender, System::EventArgs^ e) { // замедление показа
	ClearErrors(); // кнопка нажата, нужно очистить ошибки
	int NewSpeed = speed / MinSpeedScale;

	if (speed > 0)
	{
		if (NewSpeed == speed)
			speed--;
		else speed = NewSpeed;
	}
}
private: System::Void btnLaunchComet_Click(System::Object^ sender, System::EventArgs^ e) { // нажатие на кнопку Запустить комету
	ClearErrors(); // кнопка нажата, нужно очистить ошибки
	if (LaunchComet) // если комета уже запускается, то отменяем действие
		LaunchComet = 0;
	else // иначе считываем массу кометы
	{
		bool res = Double::TryParse(txtCometMass->Text, CometMass);

		if (!res)
		{
			errorProvider1->SetError(txtCometMass, "Некорректное число");
			return;
		}

		if (CometMass < 0 || CometMass > 100)
		{
			errorProvider1->SetError(txtCometMass, "Число должно быть от 0 до 100");
			return;
		}

		comet->Set_mass(CometMass * EarthMass / 100 * Sun->Get_mass() / SunMass); // если масса корректна, переходим к запуску кометы
		LaunchComet = 1;
	}
}
private: System::Void btnShowSunName_Click(System::Object^ sender, System::EventArgs^ e) { // кнопки, отвечающие за подписи
	ClearErrors(); // кнопка нажата, нужно очистить ошибки
	*ShowSunName ^= 1;
}
private: System::Void btnShowPlanetName_Click(System::Object^ sender, System::EventArgs^ e) {
	ClearErrors(); // кнопка нажата, нужно очистить ошибки
	*ShowPlanetName ^= 1;
}
private: System::Void btnShowSatelliteName_Click(System::Object^ sender, System::EventArgs^ e) {
	ClearErrors(); // кнопка нажата, нужно очистить ошибки
	*ShowSatelliteName ^= 1;
}
private: System::Void btnShowCometName_Click(System::Object^ sender, System::EventArgs^ e) {
	ClearErrors(); // кнопка нажата, нужно очистить ошибки
	*ShowCometName ^= 1;
}
private: System::Void btnDeleteComet_Click(System::Object^ sender, System::EventArgs^ e) { // удаление кометы
	ClearErrors(); // кнопка нажата, нужно очистить ошибки
	L->del(comet);
}
};
}

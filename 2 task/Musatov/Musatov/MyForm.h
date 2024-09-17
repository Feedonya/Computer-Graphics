#pragma once

namespace Musatov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	float lines[] = {
		// голова
		0.5f, 3.0f, 1.f, 4.5f, // от левой щеки вверх до уха
		1.f, 4.5f, 0.5f, 6.f, // левое ухо слева снизу вверх
		0.5f, 6.f, 0.5f, 7.5f, // левое ухо слева
		0.5f, 7.5f, 1.f, 8.f, // левое ухо верх слева
		1.f, 8.f, 1.5f, 8.f, // левое ухо верх середина
		1.5f, 8.f, 2.f, 7.5f, // левое ухо верх справа
		2.0f, 7.5f, 1.5f, 6.f, // левое ухо справа сверху вниз
		1.5f, 6.f, 1.5f, 4.5f, // левое ухо справа до макушки
		1.5f, 4.5f, 3.f, 4.5f, // макушка
		3.f, 4.5f, 3.f, 6.f, // правое ухо слева снизу вверх
		3.f, 6.f, 2.5f, 7.5f, //правое ухо слева
		2.5f, 7.5f, 3.f, 8.f, // правое ухо верх слева
		3.f, 8.f, 3.5f, 8.f, // правое ухо верх середина
		3.5f, 8.f, 4.f, 7.5f, // правое ухо верх справа
		4.f, 7.5f, 4.f, 6.f, // правое ухо сверху вниз
		4.f, 6.f, 3.5f, 4.5f, // правое ухо справа
		3.5f, 4.5f, 4.f, 3.f, // от правого ухо вниз до щеки
		4.f, 3.f, 3.5f, 1.5f, // правая скула
		3.5f, 1.5f, 2.5f, 1.f, // подбородок справа
		2.5f, 1.f, 2.f, 1.f, // подбородок снизу
		2.f, 1.f, 1.f, 1.5f, // подбородок слева
		1.f, 1.5f, 0.5f, 3.f, // левая скула
		// туловище
		4.f, 3.f, 5.5f, 3.5f, // спина от головы вправо
		5.5f, 3.5f, 7.f, 3.5f, // спина верх
		7.f, 3.5f, 7.5f, 2.5f, // спина сверху до хвоста
		7.5f, 2.5f, 8.f, 2.5f, // хвост сверху
		8.f, 2.5f, 8.f, 2.f, // хвост справа
		8.f, 2.f, 7.5f, 2.f, // хвост низ справа налево
		7.5f, 2.f, 7.5f, 0.5f, // задняя нога справа сверху вниз
		7.5f, 0.5f, 6.5f, 0.5f, // задняя нога низ
		6.5f, 0.5f, 6.5f, 1.f, // задняя нога слева
		6.5f, 1.f, 6.f, 1.f, // между задних ног
		6.f, 1.f, 6.f, 0.5f, // левая задняя нога справа
		6.f, 0.5f, 5.f, 0.5f, // левая задняя нога низ
		5.f, 0.5f, 5.f, 1.f, // левая задняя нога слева
		5.f, 1.f, 4.f, 1.f, // между задними и передними ногами
		4.f, 1.f, 4.f, 0.5f, // правая передняя нога справа
		4.f, 0.5f, 3.f, 0.5f, // правая передняя нога низ
		3.f, 0.5f, 3.f, 1.f, // правая передняя нога слева
		3.f, 1.f, 2.5f, 1.f, // между передних ног
		2.5f, 1.f, 2.5f, 0.5f, // передняя нога справа
		2.5f, 0.5f, 1.5f, 0.5f, // передняя нога низ
		1.5f, 0.5f, 1.5f, 1.25f, // передняя нога слева
		// левый глаз
		1.5f, 3.5f, 1.5f, 3.f, // левый глаз слева сверху вниз
		1.5f, 3.f, 2.f, 3.f, // левый глаз низ
		2.f, 3.f, 2.f, 3.5f, // левый глаз справа
		2.f, 3.5f, 1.5f, 3.5f, // левый глаз верх
		// правый глаз
		2.5f,3.5f,2.5f,3.f, // правый глаз слева
		2.5f,3.f,3.f, 3.f, // правый глаз снизу
		3.f,3.f,3.f,3.5f, // правый глаз справа
		3.f,3.5f,2.5f,3.5f, // правый глаз сверху
		// ушные раковины
		1.f, 5.5f, 1.f, 7.f, // левая ушная раковина
		3.5f,5.5f,3.5f,7.f, // правая ушная раковина
		// нос
		2.f, 2.5f, 2.5f, 2.5f, // нос сверху
		2.5f, 2.5f, 2.25f, 2.f, // нос справа
		2.25f, 2.f, 2.f, 2.5f // нос слева
	};
	unsigned int arrayLength = sizeof(lines) / sizeof(float);
	float Vx = 8.5f; // размер рисунка по горизонтали
	float Vy = 8.5f; // размер рисунка по вертикали
	float aspectFig = Vx / Vy; // соотношение сторон рисунка



	float mushroom[] = {
		// шляпка гриба
		4.f, 4.f, 3.f, 4.f, // слева от ножки прямо влево
		3.f, 4.f, 1.5f, 4.5f, // слева от ножки левее вверх
		1.5f, 4.5f, 0.5f, 5.5f, // слева от ножки левее вверх
		0.5f, 5.5f, 0.5f, 7.f, // слева от ножки прямо вверх
		0.5f, 7.f, 1.5f, 8.f, // слева от ножки вверх вправо
		1.5f, 8.f, 4.f, 13.5f, // левая часть шапки
		4.f, 13.5f, 4.5f, 14.f, // от левой части шапки к макушке
		4.5f, 14.f, 5.5f, 14.f, // макушка
		5.5f, 14.f, 6.f, 13.5f, // от макушки к правой части шапки
		6.f, 13.5f, 8.5f, 8.f, // правая часть шапки
		8.5f, 8.f, 9.5f, 7.f, // справа от ножки вниз вправо
		9.5f, 7.f, 9.5f, 5.5f, // справо от ножки прямо вниз
		9.5f, 5.5f, 8.5f, 4.5f, // справа от ножки прямо вниз
		8.5f, 4.5f, 7.f, 4.f, // справа от ножки левее вниз
		7.f, 4.f, 6.f, 4.f, // стыкуемся к правой части ножки

		// ножка гриба
		6.f, 4.f, 6.5f, 5.5f, // правая верхняя часть ножки
		6.5f, 5.5f, 5.5f, 6.f, // правая часть вершины ножки
		5.5f, 6.f, 4.5f, 6.f, // вершина
		4.5f, 6.f, 3.5f, 5.5f, // левая часть вершины ножки
		3.5f, 5.5f, 4.f, 4.f, // левая верхняя часть ножки
		4.f, 4.f, 3.5f, 1.5f, // левая середина ножки
		3.5f, 1.5f, 4.f, 0.5f, // левая нижняя часть ножки
		4.f, 0.5f, 5.f, 0.f, // левый низ ножки
		5.f, 0.f, 6.f, 0.5f, // правый низ ножки
		6.f, 0.5f, 6.5f, 1.5f, // правая нижняя часть ножки
		6.5f, 1.5f, 6.f, 4.f, // правая середина ножки

		// трава
		2.f, 0.f, 1.f, 1.f, // с левой стороны снизу от травы 
		1.f, 1.f, 2.5f, 1.f, // прямо вправо
		2.5f, 1.f, 1.5f, 2.f, // влево вверх
		1.5f, 2.f, 2.5f, 1.5f, // вниз вправо
		2.5f, 1.5f, 2.5f, 2.5f, // прямо вверх
		2.5f, 2.5f, 3.f, 1.5f, // вниз влево
		3.f, 1.5f, 3.f, 3.5f, // прямо вверх
		3.f, 3.5f, 3.5f, 1.5f, // вниз влево

		6.5f, 1.5f, 7.f, 3.5f, // от правой стороны ножки вверх вправо
		7.f, 3.5f, 7.f, 1.5f, // вниз прямо
		7.f, 1.5, 7.5f, 2.5f, // вправо вверх
		7.5f, 2.5f, 7.5f, 1.5f, // вниз прямо
		7.5f, 1.5f, 8.5f, 2.f, // вправо вверх
		8.5f, 2.f, 7.5f, 1.f, // влево вниз
		7.5f, 1.f, 9.f, 1.f, // вправо прямо
		9.f, 1.f, 8.f, 0.f, // вниз влево
		8.f, 0.f, 2.f, 0.f, // середина травы

		// губка
		// контур губки
		3.8f, 4.5f, 3.f, 4.5f, // с левой стороны ножки прямо
		3.f, 4.5f, 2.f, 5.f, // с левой стороны ножки левее вверх
		2.f, 5.f, 1.f, 6.f, // с левой стороны ножки левее вверх до середины контура
		1.f, 6.f, 2.f, 7.f, // от середины контура вверх
		2.f, 7.f, 3.5f, 7.5f, // правве вверх до вершины контура губки гриба
		3.5f, 7.5f, 6.5f, 7.5f, // вершина контура губки
		6.5f, 7.5f, 8.f, 7.f, // от вершины влево вниз
		8.f, 7.f, 9.f, 6.f, // вниз до середины контура
		9.f, 6.f, 8.f, 5.f, // от середины контура вниз к правой стороне ножки
		8.f, 5.f, 7.f, 4.5f, // к правой стороне ножки вниз влево
		7.f, 4.5f, 6.2f, 4.5f,  // примыкаем к правой стороне ножки
		// пластинки губки
		3.5f, 5.5f, 1.5f, 6.5f, // 1-ая пластинка слева от вершины ножки
		4.f, 5.7f, 3.f, 7.3f, // 2-ая пластинка
		4.5f, 6.f, 4.f, 7.5f, // 3-ая пластинка
		5.f, 6.f, 5.f, 7.5f, // 4-ая пластинка
		5.5f, 6.f, 6.f, 7.5f, // 5-ая пластинка
		6.f, 5.7f, 7.f, 7.3f, // 6-ая пластинка
		6.5f, 5.5f, 8.5f, 6.5f, // 7-ая пластинка

		// хлопья
		// отсчет сверху вниз - 1-ое пятно самое верхнее, 2-ое ниже и т.д.
		// 1-ое
		4.f, 13.5f, 4.5f, 13.5f,
		4.5f, 13.5f, 5.f, 13.f,
		5.f, 13.f, 5.f, 12.5f,
		5.f, 12.5f, 4.5f, 12.f,
		4.5f, 12.f, 4.f, 12.f,
		4.f, 12.f, 3.5f, 12.5f,
		// 2-ое
		5.f, 11.f, 5.f, 11.5f,
		5.f, 11.5f, 5.5f, 12.f,
		5.5f, 12.f, 6.f, 12.f,
		6.f, 12.f, 6.5f, 11.5f,
		6.5f, 11.5f, 6.5f, 11.f,
		6.5f, 11.f, 6.f, 10.5f,
		6.f, 10.5f, 5.5f, 10.5f,
		5.5f, 10.5f, 5.f, 11.f,
		// 3-ее
		3.f, 9.5f, 3.f, 10.f,
		3.f, 10.f, 3.5f, 10.5f,
		3.5f, 10.5f, 4.f, 10.5f,
		4.f, 10.5f, 4.5f, 10.f,
		4.5f, 10.f, 4.5f, 9.5f,
		4.5f, 9.5f, 4.f, 9.f,
		4.f, 9.f, 3.5f, 9.f,
		3.5f, 9.f, 3.f, 9.5f,
		// 4-ое
		5.5f, 8.5f, 5.5f, 9.5f,
		5.5f, 9.5f, 6.f, 10.f,
		6.f, 10.f, 7.f, 10.f,
		7.f, 10.f, 7.5f, 9.5f,
		7.5f, 9.5f, 7.5f, 8.5f,
		7.5f, 8.5f, 7.f, 8.f,
		7.f, 8.f, 6.f, 8.f,
		6.f, 8.f, 5.5f, 8.5f,
		// 5-ое
		2.f, 9.f, 2.5f, 8.5f,
		2.5f, 8.5f, 2.5f, 8.f,
		2.5f, 8.f, 2.f, 7.5f,
		2.f, 7.5f, 1.f, 7.5f,
		// 6-ое
		3.5f, 7.5f, 3.f, 8.f,
		3.f, 8.f, 3.5f, 8.5f,
		3.5f, 8.5f, 4.f, 8.5f,
		4.f, 8.5f, 4.5f, 8.f,
		4.5f, 8.f, 4.f, 7.5f,
		// 7-ое
		8.5f, 8.f, 8.f, 7.5f,
		8.f, 7.5f, 8.5f, 7.f,
		8.5f, 7.f, 9.5f, 7.f,
		// 8-ое
		0.5f, 6.f, 1.f, 6.5f,
		1.f, 6.5f, 0.5f, 7.f,
	};
	unsigned int arrayLengthMushroom = sizeof(mushroom) / sizeof(float);
	float Vx2 = 15.f;
	float Vy2 = 15.f;
	float aspectPicture = Vx2 / Vy2;


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

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 408);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio; // значение - сохранять ли соотношение рисунка
	private: bool keepFlag;

	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		// заяц
		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float Wx = ClientRectangle.Width; // размер окна по горизонтали
		float Wy = ClientRectangle.Height; // размер окна по вертикали
		float aspectForm = Wx / Wy; // соотношение сторон окна рисования
		float Sx, Sy;

		// гриб
		Pen^ bluePen = gcnew Pen(Color::Blue, 2);

		float Wx2 = ClientRectangle.Width;
		float Wy2 = ClientRectangle.Height;
		float aspectWindow = Wx2 / Wy2;
		float Sx2, Sy2;


		//Выводим гриб
		if (keepFlag) {
			if (keepAspectRatio) {
				Sx2 = Sy2 = aspectPicture < aspectWindow ? Wy2 / Vy2 : Wx2 / Vx2;
			}
			else {
				Sx2 = Wx2 / Vx2 * 1.5;
				Sy2 = Wy2 / Vy2;
			}
			float Ty2 = Sy2 * Vy2;
			for (int i = 0; i < arrayLengthMushroom; i += 4) {
				g->DrawLine(bluePen, Sx2 * mushroom[i], Ty2 - Sy2 * mushroom[i + 1], Sx2 * mushroom[i + 2], Ty2 - Sy2 * mushroom[i + 3]);
			}
		}
		//Выводим зайца
		else {
			if (keepAspectRatio) {
				//коофициенты увеличения при сохранении исходного соотношения сторон
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
			}
			else {
				Sx = Wx / Vx; // коэффициент увеличения по оси Ox
				Sy = Wy / Vy; // коэффициент увеличения по оси Oy
			}
			float Ty = Sy * Vy; // смещение в положительную сторону по оси Oy после смены знака
			for (int i = 0; i < arrayLength; i += 4) {
				g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1], Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
			}
		}
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true; // начальное значение: сохранять соотношение сторон рисунка
		keepFlag = true; // начальное значение моего примера
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::N:
			keepFlag = !keepFlag;
			break;
		default:
			break;
		}
		Refresh();
	}
	};
}
//Vx и Vy — размеры заданного рисунка в единицах
//нашей выбранной системы координат, а так же понадобятся размеры видимой части области
//рисования Wx и Wy .
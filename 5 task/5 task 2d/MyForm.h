#pragma once

namespace Musatov {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	vec2 Vc; //координаты левого нижнего угла
	vec2 V; //размеры прямоугольника в пространстве графика
	vec2 Vc_work, V_work; //рабочие параметры прямоугольника
	mat3 T = mat3(1.f); //матрица, в которой накапливаются все преобразования. Первоначально - единичная матрица
	mat3 initT; //матрица начального преобразования

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
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	protected:


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
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Multiselect = true;
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(155, 120);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: float left = 30, right = 100, top = 20, bottom = 50; //расстояния до границ окна
		   float minX = left, maxX; //диапазон изменения координат x
		   float minY = top, maxY; //диапазон изменения координат y
		   float Wcx = left, Wcy; //координаты левого нижнего угла прямоугольника
		   float Wx, Wy; //ширина и высота прямоугольника
		   int numXsect = 5, numYsect = 5; //количество секций координатной сетки по осям

	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; //диапазон изменения координат x
		maxY = ClientRectangle.Height - bottom; //диапазон изменения координат y
		Wcy = maxY; //координаты левого нижнего угла прямоугольника
		Wx = maxX - left; //ширина прямоугольника
		Wy = maxY - top; //ширина и высота прямоугольника
	}

	private: System::Void worldRectCalc() {
		Vc_work = normalize(T * vec3(Vc, 1.f));
		V_work = mat2(T) * V;
	}

	private: float f(float x) {
		return tan(x);
	}

	private: bool f_exists(float x, float delta) {
		return fabs(2.f * acos(cos(x)) - Math::PI) > delta;
	}

	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Black);

		Pen^ rectPen = gcnew Pen(Color::White, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		Pen^ gridPen = gcnew Pen(Color::White, 1);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::White);
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
		//Х
		float gridStep_x = Wx / numXsect; //расстояние между линиями сетки по x
		float grid_dX = V_work.x / numXsect; //расстояние между линиями сетки по x в мировых координатах
		float tick_x = Vc_work.x; //значение соответствующее первой линии сетки
		for (int i = 0; i <= numXsect; i++) { //цикл по количеству линий
			float tmpXCoord_v = Wcx + i * gridStep_x; //координата x i-й вертикальной линии
			//i-я вертикальная линия
			g->DrawLine(gridPen, tmpXCoord_v, Wcy, tmpXCoord_v, minY);
			if (i > 0 && i < numXsect) //если линия не крайняя
				//выводим текст в нижней точке диагональной линии
				g->DrawString(tick_x.ToString("F4"), drawFont, drawBrush, tmpXCoord_v, Wcy);
			tick_x += grid_dX; //вычисляем значение, соответствующее следующей линии
		}
		//Y
		float gridStep_y = Wy / numYsect; //расстояние между линиями сетки по y
		float grid_dY = V_work.y / numYsect; //расстояние между линиями сетки по y в мировых координатах
		float tick_y = Vc_work.y; //значение соответствующее первой линии сетки
		for (int i = 0; i <= numYsect; i++) { //цикл по количеству линий
			float tmpYCoord_g = Wcy - i * gridStep_y; //координата у i-й горизонтальной линии
			//i-я горизонтальная линия
			g->DrawLine(gridPen, Wcx, tmpYCoord_g, maxX, tmpYCoord_g);
			if (i > 0 && i < numYsect) //если линия не крайняя
				//выводим текст в нижней точке диагональной линии
				g->DrawString(tick_y.ToString("F4"), drawFont, drawBrush, Wcx, tmpYCoord_g);
			tick_y += grid_dY; //вычисляем значение, соответствующее следующей линии
		}
		Pen^ pen = gcnew Pen(Color::Blue, 1);
		float deltaX = V_work.x / Wx; //шаг по x в мировых координатах
		bool hasStart;
		vec2 start; //точка начала отрезка в координатах экрана	
		float x, y; //переменные для координат точки в мировой СК
		start.x = Wcx; //для начальной точки первого отрезка устанавливаем координату x
		x = Vc_work.x; //координата x начальной точки первого отрезка в мировых координатах
		hasStart = f_exists(x, deltaX);
		if (hasStart) {
			y = f(x); //координата y начальной точки в мировых координатах
			//вычисляем соответствующее значение в координатах экрана
			start.y = Wcy - (y - Vc_work.y) / V_work.y * Wy;
		}
		float deltaY; //высота точки в прямоугольнике (доля общей высоты)
		float red, green, blue; //компоненты цвета отрезка
		while (start.x < maxX) {
			vec2 end;//точка конца отрезка в координатах экрана
			bool hasEnd;
			end.x = start.x + 1.f; //координата x отличается на единицу
			x += deltaX; //координата x конечной точки отрезка в мировых координатах
			hasEnd = f_exists(x, deltaX);
			if (hasEnd) {
				y = f(x); //координата y начальной точки в мировых координатах
				//вычисляем соответствующее значение в координатах экрана
				//вычисляем соответствующее значение в координатах экрана
				deltaY = (y - Vc_work.y) / V_work.y;
				end.y = Wcy - deltaY * Wy;
			}

			vec2 tmpEnd = end;
			bool visible = hasStart && hasEnd && clip(start, end, minX, minY, maxX, maxY);

			if (visible) { //если отрезок видим
				//после отсечения, start и end - концы видимой части отрезка
				if (deltaY > 1.f) deltaY = 1.f; //нормализуем значение высоты точки
				if (deltaY < 0.f) deltaY = 0.f; //на случай, если отрезок отсекался
				green = 510.f * deltaY; //предварительное вычисление произведения
				if (deltaY < 0.5) { //если точка ниже середины области видимости
					//компонента зеленого уже вычислена
					blue = 255.f - green; //синий дополняет зеленый
					red = 0.f; //красный равен нулю
				}
				else { //если точка не ниже середины
					blue = 0.f; //синий равен нулю
					red = green - 255.f; //вычисляем красный и зеленый
					green = 510.f - green; //с использованием вычисленного произведения
				}
				pen->Color = Color::FromArgb(red, green, blue); //меняем цвет пера
				g->DrawLine(pen, start.x, start.y, end.x, end.y); //отрисовка видимых частей
			}
			//конечная точка неотсеченного отрезка становится начальной точкой следующего
			start = tmpEnd;
			hasStart = hasEnd;

		}
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Vc = vec2(-2.f, -2.f);
		V = vec2(4.f, 4.f);
		initT = mat3(1.f);
		T = initT;
		rectCalc();
		worldRectCalc();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float centerX = Vc_work.x + V_work.x / 2; //координаты центра прямоугольника
		float centerY = Vc_work.y + V_work.y / 2; //в мировой системе координат
		switch (e->KeyCode) {
		case Keys::W:
			T = translate(0.f, -V_work.y / Wy) * T; //сдвиг графика вверх на один пиксел
			break;
		case Keys::A:
			T = translate(-V_work.x / Wx, 0.f) * T; //сдвиг графика вправо на один пиксел
			break;
		case Keys::S:
			T = translate(0.f, V_work.y / Wy) * T; //сдвиг графика вправо на один пиксел
			break;
		case Keys::D:
			T = translate(V_work.x / Wx, 0.f) * T; //сдвиг графика влево на один пиксел
			break;
		case Keys::Z:
			T = translate(-centerX, -centerY) * T; //перенос начала координат в центр
			T = scale(1.1) * T; //масштабирование относительно начала координат
			T = translate(centerX, centerY) * T; //возврат позиции начала координат
			break;
		case Keys::X:
			T = translate(-centerX, -centerY) * T; //перенос начала координат в центр
			T = scale(1 / 1.1) * T; //масштабирование относительно начала координат
			T = translate(centerX, centerY) * T; //возврат позиции начала координат
			break;
		case Keys::T:
			T = translate(-centerX, -centerY) * T; //перенос начала координат в центр
			T = scale(1.1, 1.f) * T; //масштабирование относительно начала координат
			T = translate(centerX, centerY) * T; //возврат позиции начала координат
			break;
		case Keys::G:
			T = translate(-centerX, -centerY) * T; //перенос начала координат в центр
			T = scale(1 / 1.1, 1.f) * T; //масштабирование относительно начала координат
			T = translate(centerX, centerY) * T; //возврат позиции начала координат
			break;
		case Keys::Y:
			T = translate(-centerX, -centerY) * T; //перенос начала координат в центр
			T = scale(1.f, 1.1) * T; //масштабирование относительно начала координат
			T = translate(centerX, centerY) * T; //возврат позиции начала координат
			break;
		case Keys::H:
			T = translate(-centerX, -centerY) * T; //перенос начала координат в центр
			T = scale(1.f, 1 / 1.1) * T; //масштабирование относительно начала координат
			T = translate(centerX, centerY) * T; //возврат позиции начала координат
			break;
		case Keys::D1:
			numXsect += 1;
			break;
		case Keys::D2:
			if (numXsect > 2)
				numXsect -= 1;
			break;
		case Keys::D3:
			numYsect += 1;
			break;
		case Keys::D4:
			if (numYsect > 2)
				numYsect -= 1;
			break;
		case Keys::Escape:
			T = initT;
			numXsect = 5;
			numYsect = 5;
			break;
		default:
			break;
		}
		worldRectCalc();
		Refresh();
	}
	};
}
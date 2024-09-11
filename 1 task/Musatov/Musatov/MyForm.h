#pragma once

namespace Musatov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
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
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
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
			this->ClientSize = System::Drawing::Size(325, 325);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		//“ак как в нашей программе будет производитьс€ много обращений к области рисовани€,опишем переменную g, в которой сохраним это значение.
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);
		
		//код, отвечающий за красную линию
		Pen^ redPen = gcnew Pen(Color::Red);//задаем цвет
		redPen->Width = 6;//толщина

		// передаем в процедуру (переменна€ с параметрами линии; координаты x;y; ширина; длина экрана у пользовател€)
		g->DrawLine(redPen, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);//рисуем на форме

		//код, отвечающий за синию линию
		Pen^ bluePen = gcnew Pen(Color::Blue, 10);//цвет, толщина
		g->DrawLine(bluePen, 90, 50, ClientRectangle.Width, 80);//рисуем 
	
		//добавл€ем надпись на форму
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);//цвет
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10);//шрифт, размер
		g->DrawString("Ќадпись на форме", drawFont, drawBrush, 40, 100);// текст; параметры надписи; x; y

		//добавл€ем линию по заданию
		Pen^ greenPen = gcnew Pen(Color::Green, 5);//цвет, толщина

		//передаем в область рисовани€ параметры линии; x,y, котора€ обозначает сторону в соотношении 2:1 экрана текущего разрешени€
		//нижн€€ права€
		g->DrawLine(greenPen, ClientRectangle.Width, ClientRectangle.Height - ClientRectangle.Height / 3, ClientRectangle.Width / 3, ClientRectangle.Height);
		//права€
		g->DrawLine(greenPen, ClientRectangle.Width - ClientRectangle.Width / 3, 0, ClientRectangle.Width, ClientRectangle.Height - ClientRectangle.Height / 3);
		//лева€
		g->DrawLine(greenPen, 0, ClientRectangle.Height / 3, ClientRectangle.Width / 3, ClientRectangle.Height);
		//верхн€€ лева€
		g->DrawLine(greenPen, 0, ClientRectangle.Height / 3, ClientRectangle.Width - ClientRectangle.Width / 3, 0);
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	};
}

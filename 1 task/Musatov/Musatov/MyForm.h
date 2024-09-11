#pragma once

namespace Musatov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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

		//��� ��� � ����� ��������� ����� ������������� ����� ��������� � ������� ���������,������ ���������� g, � ������� �������� ��� ��������.
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);
		
		//���, ���������� �� ������� �����
		Pen^ redPen = gcnew Pen(Color::Red);//������ ����
		redPen->Width = 6;//�������

		// �������� � ��������� (���������� � ����������� �����; ���������� x;y; ������; ����� ������ � ������������)
		g->DrawLine(redPen, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);//������ �� �����

		//���, ���������� �� ����� �����
		Pen^ bluePen = gcnew Pen(Color::Blue, 10);//����, �������
		g->DrawLine(bluePen, 90, 50, ClientRectangle.Width, 80);//������ 
	
		//��������� ������� �� �����
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);//����
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10);//�����, ������
		g->DrawString("������� �� �����", drawFont, drawBrush, 40, 100);// �����; ��������� �������; x; y

		//��������� ����� �� �������
		Pen^ greenPen = gcnew Pen(Color::Green, 5);//����, �������

		//�������� � ������� ��������� ��������� �����; x,y, ������� ���������� ������� � ����������� 2:1 ������ �������� ����������
		//������ ������
		g->DrawLine(greenPen, ClientRectangle.Width, ClientRectangle.Height - ClientRectangle.Height / 3, ClientRectangle.Width / 3, ClientRectangle.Height);
		//������
		g->DrawLine(greenPen, ClientRectangle.Width - ClientRectangle.Width / 3, 0, ClientRectangle.Width, ClientRectangle.Height - ClientRectangle.Height / 3);
		//�����
		g->DrawLine(greenPen, 0, ClientRectangle.Height / 3, ClientRectangle.Width / 3, ClientRectangle.Height);
		//������� �����
		g->DrawLine(greenPen, 0, ClientRectangle.Height / 3, ClientRectangle.Width - ClientRectangle.Width / 3, 0);
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	};
}

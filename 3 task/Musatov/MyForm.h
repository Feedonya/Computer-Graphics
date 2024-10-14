#pragma once
#include <vector>
#include "Matrix.h"
#include "Figure.h"
#include "Transform.h"

namespace Musatov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	float lines[]{
		//�����, ����� �����
		2.f, 0.f, 5.f, 0.f, //��������� ����� �����
		2.f, 0.f, 1.f, 1.f, //������� ����� ����� �����
		1.f, 1.f, 2.5f, 1.f, //����� ����� ����� ������
		2.5f, 1.f, 1.5f, 2.f, // ����� ����� ����� ����� �� ��������� ������
		1.5f, 2.f, 2.5f, 1.5f, //����� ����� ����� ���� �������
		2.5f, 1.5f, 2.5f, 2.5f, //����� ����� ����� ������
		2.5f, 2.5f, 3.f, 1.5f, //����� ����� ����� ����� ������
		3.f, 1.5f, 3.f, 3.5f, //����� ����� ����� ������
		3.f, 3.5f, 3.5f, 1.5f, //������� ����
		3.5f, 1.5f, 4.f, 0.5f, //����� �� ��������� ����� �����
		4.f, 0.5f, 5.f, 0.f, //"����� ���������������" � ������ ������ ����� �����

		//�����, ������ �����
		5.f, 0.f, 6.f, 0.5f, //����� ������, ������ � ��������� ������
		6.f, 0.5f, 6.5f, 1.5f, //������ ������� ���� �� ��������� �����
		6.5f, 1.5f, 7.f, 3.5f, //������ ����� �����, ����� ������� �����
		7.f, 3.5f, 7.f, 1.5f, //����� ����
		7.f, 1.5f, 7.5f, 2.5f, //������ ������
		7.5f, 2.5f, 7.5f, 1.5f, //����� ����
		7.5f, 1.5f, 8.5f, 2.f, //��������� ������
		8.5f, 2.f, 7.5f, 1.f, //��������� �����
		7.5f, 1.f, 9.f, 1.f, //������
		9.f, 1.f, 8.f, 0.f, //�������� ����
		8.f, 0.f, 5.f, 0.f, //��������� ������ ����� � �������

		//��������� �����
		3.5f, 1.5f, 4.f, 4.f, //� ����� ������� ����� �������
		4.f, 4.f, 3.5f, 5.5f, //� ����� ������� ����� ������
		3.5f, 5.5f, 4.5f, 6.f, //����� ������� �����
		4.5f, 6.f, 5.5f, 6.f, //������ ������
		5.5f, 6.f, 6.5f, 5.5f, //���� �������
		6.5f, 5.5f, 6.f, 4.f, //���� �����
		6.f, 4.f, 6.5f, 1.5f, //��������� ������ ����� � ������

		//������ �����, � �������� ������.
		4.f, 4.f, 3.f, 4.f, //������ ������
		3.f, 4.f, 1.5f, 4.5f, //����� ������
		1.5f, 4.5f, 0.5f, 5.5f, //����� ������
		0.5f, 5.5f, 0.5f, 7.f, //������ �����
		0.5f, 7.f, 1.5f, 8.f, //����� �������
		1.5f, 8.f, 4.f, 14.f, //������� ����� ����� ������
		4.f, 14.f, 4.5f, 14.5f, //��������� �������
		4.5f, 14.5f, 5.5f, 14.5f, //������� �����

		//������ �����, � ������ ����� ������� ����
		5.5f, 14.5f, 6.f, 14.f, //��������� �������
		6.f, 14.f, 8.5f, 8.f, //������� ������� ����
		8.5f, 8.f, 9.5f, 7.f, //������ ����
		9.5f, 7.f, 9.5f, 5.5f, //����
		9.5f, 5.5f, 8.5f, 4.5f, //����� ����
		8.5f, 4.5f, 7.f, 4.f, //����� ����
		7.f, 4.f, 6.f, 4.f, //��������� �� ������� ������

		//���������� ������ �����
		//3.75f, 4.5f, 2.5f, 4.5f //����� 
		3.75f, 4.5f, 3.f, 4.5f, //������ ������
		3.f, 4.5f, 2.f, 5.f, //����� ������
		2.f, 5.f, 1.f, 6.f, //��� ��� �����
		1.f, 6.f, 2.f, 7.f, //����� ������
		2.f, 7.f, 3.5f, 7.5f, //�����
		3.5f, 7.5f, 6.5f, 7.5f, //������ ���������� ������

		//���������� ������ � ������ ������� ����
		6.5f, 7.5f, 8.f, 7.f, //���� ����� ������
		8.f, 7.f, 9.f, 6.f, //���� ����� ������
		9.f, 6.f, 8.f, 5.f, //����� ���� �����
		8.f, 5.f, 7.f, 4.5f, //����� ���� �����
		7.f, 4.5f, 6.25f, 4.5f, //������, ����������� ���������� ������ �� �������

		//������� ������ �����, ����� �������
		3.5f, 5.5f, 1.5f, 6.5f, //������ ������
		4.f, 5.75f, 3.f, 7.25f, // ������ ������
		4.5f, 6.f, 4.f, 7.5f, // ������
		5.f, 6.f, 5.f, 7.5f, // 4
		5.5f, 6.f, 6.f, 7.5f, // 5
		6.f, 5.75f, 7.f, 7.25f, // 6
		6.5f, 5.5f, 8.5f, 6.5f, // 7

		//������� ������, ������ ����� �����
		0.5f, 6.f, 1.f, 6.5f, //������ ������
		1.f, 6.5f, 0.5f, 7.f, //����� �����

		//������� ������, ������ ����
		1.f, 7.5f, 2.f, 7.5f, //������ ������� �����
		2.f, 7.5f, 2.5f, 8.f, //������ �����
		2.5f, 8.f, 2.5f, 8.5f, //�����
		2.5f, 8.5f, 2.f, 9.f, //����� ��������� �� �������

		//������ ������ (� ����)
		3.5f, 7.5f, 3.f, 8.f, //������ ����� �����
		3.f, 8.f, 3.5f, 8.5f, //����� �������
		3.5f, 8.5f, 4.f, 8.5f, //������
		4.f, 8.5f, 4.5f, 8.f, //������ ����
		4.5f, 8.f, 4.f, 7.5f, //����� ����

		//������ ����
		3.5f, 9.f, 3.f, 9.5f, //������ ����� �����
		3.f, 9.5f, 3.f, 10.f, //�����
		3.f, 10.f, 3.5f, 10.5f, //������
		3.5f, 10.5f, 4.f, 10.5f, //������ ������
		4.f, 10.5f, 4.5f, 10.f, //������ ���� �����
		4.5f, 10.f, 4.5f, 9.5f, //����
		4.5f, 9.5f, 4.f, 9.f, //����� ����
		4.f, 9.f, 3.5f, 9.f, //���������

		//����� ������� ������
		4.f, 12.f, 3.5f, 12.5f, //����� �����
		4.f, 12.f, 4.5f, 12.f, //������ ������
		4.5f, 12.f, 5.f, 12.5f, //����� �������
		5.f, 12.5f, 5.f, 13.f, //�����
		5.f, 13.f, 4.5f, 13.5f, //����� ������
		4.5f, 13.5f, 4.f, 13.5f, //��������� �����

		//������ ���� � ������
		5.5f, 12.f, 6.f, 12.f, //������ ������ ������
		6.f, 12.f, 6.5f, 11.5f, //���� ������ 
		6.5f, 11.5f, 6.5f, 11.f, //������ ����
		6.5f, 11.f, 6.f, 10.5f, //����� ����
		6.f, 10.5f, 5.5f, 10.5f, //������ �����
		5.5f, 10.5f, 5.f, 11.f, //����� �����
		5.f, 11.f, 5.f, 11.5f, //�����
		5.f, 11.5f, 5.5f, 12.f, //��������� 

		//������ ����, ����� �������
		6.f, 10.f, 7.f, 10.f, //������ ������ ������
		7.f, 10.f, 7.5f, 9.5f, //������ ����
		7.5f, 9.5f, 7.5f, 8.5f, //���� ������
		7.5f, 8.5f, 7.f, 8.f, //����� ����
		7.f, 8.f, 6.f, 8.f, //������ �����
		6.f, 8.f, 5.5f, 8.5f, //����� ������
		5.5f, 8.5f, 5.5f, 9.5f, //����
		5.5f, 9.5f, 6.f, 10.f, //���������

		//����� ������ ������
		8.5f, 8.f, 8.f, 7.5f, //������ ���� ������
		8.f, 7.5f, 8.5f, 7.f, //������ ����
		8.5f, 7.f, 9.5f, 7.f //���������

	};
	float linesBunny[]{
		// ������
	0.5f,3.f,1.f,4.5f, // �� ����� ���� ����� �� ���
	1.f,4.5f,0.5f,6.f, // ����� ��� ����� ����� �����
	0.5f,6.f,0.5f, 7.5f, // ����� ��� �����
	0.5f, 7.5f,1.f,8.f, // ����� ��� ���� �����
	1.f,8.f,1.5f,8.f, // ����� ��� ���� ��������
	1.5f,8.f,2.f,7.5f, // ����� ��� ���� ������
	2.f,7.5f,1.5f, 6.f, // ����� ��� ������ ������ ����
	1.5f, 6.f,1.5f,4.5f, // ����� ��� ������ �� �������
	1.5f,4.5f,3.f,4.5f, // �������
	3.f,4.5f,3.f,6.f, // ������ ��� ����� ����� �����
	3.f,6.f,2.5f,7.5f, // ������ ��� �����
	2.5f,7.5f,3.f,8.f, // ������ ��� ���� �����
	3.f,8.f,3.5f,8.f, // ������ ��� ���� ��������
	3.5f,8.f,4.f,7.5f, // ������ ��� ���� ������
	4.f,7.5f,4.f,6.f, // ������ ��� ������ ����
	4.f,6.f,3.5f,4.5f, // ������ ��� ������
	3.5f,4.5f,4.f,3.f, // �� ������� ��� ���� �� ����
	4.f,3.f,3.5f,1.5f, // ������ �����
	3.5f,1.5f,2.5f,1.f, // ���������� ������
	2.5f,1.f,2.f,1.f, // ���������� �����
	2.f,1.f,1.f,1.5f, // ���������� �����
	1.f,1.5f,0.5f,3.f, // ����� �����
	// ��������
	4.f,3.f,5.5f,3.5f, // ����� �� ������ ������
	5.5f,3.5f,7.f,3.5f, // ����� ����
	7.f,3.5f,7.5f,2.5f, // ����� ������ �� ������
	7.5f,2.5f,8.f,2.5f, // ����� ������
	8.f,2.5f,8.f,2.f, // ����� ������
	8.f,2.f,7.5f,2.f, // ����� ��� ������ ������
	7.5f,2.f,7.5f,0.5f, // ������ ���� ������ ������ ����
	7.5f,0.5f,6.5f,0.5f, // ������ ���� ���
	6.5f,0.5f,6.5f,1.f, // ������ ���� �����
	6.5f,1.f,6.f,1.f, // ����� ������ ���
	6.f,1.f,6.f,0.5f, // ����� ������ ���� ������
	6.f,0.5f,5.f,0.5f, // ����� ������ ���� ���
	5.f,0.5f,5.f,1.f, // ����� ������ ���� �����
	5.f,1.f,4.f,1.f, // ����� ������� � ��������� ������
	4.f,1.f,4.f,0.5f, // ������ �������� ���� ������
	4.f,0.5f,3.f,0.5f, // ������ �������� ���� ���
	3.f,0.5f,3.f,1.f, // ������ �������� ���� �����
	3.f,1.f,2.5f,1.f, // ����� �������� ���
	2.5f,1.f,2.5f,0.5f, // �������� ���� ������
	2.5f,0.5f,1.5f,0.5f, // �������� ���� ���
	1.5f,0.5f,1.5f,1.25f, // �������� ���� �����
	// ����� ����
	1.5f,3.5f,1.5f,3.f, // ����� ���� ����� ������ ����
	1.5f,3.f,2.f,3.f, // ����� ���� ���
	2.f, 3.f,2.f,3.5f, // ����� ���� ������
	2.f,3.5f,1.5f,3.5f, // ����� ���� ����
	// ������ ����
	2.5f,3.5f,2.5f,3.f, // ������ ���� �����
	2.5f,3.f,3.f, 3.f, // ������ ���� �����
	3.f,3.f,3.f,3.5f, // ������ ���� ������
	3.f,3.5f,2.5f,3.5f, // ������ ���� ������
	// ����� ��������
	1.f,5.5f,1.f,7.f, // ����� ����� ��������
	3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
	// ���
	2.f,2.5f,2.5f,2.5f, // ��� ������
	2.5f,2.5f,2.25f,2.f, // ��� ������
	2.25f,2.f,2.f,2.5f // ��� �����
	};

	float Vx;
	float Vy;
	float aspectFig;
	mat3 T; // �������, � ������� ������������� ��� ��������������
	// ������������� - ��������� �������
	mat3 initT; // ������� ���������� ��������������
	vector<path> figure;



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
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	protected:
	private: System::Windows::Forms::Button^ btnOpen;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"��������� ����� (*.txt)|*.txt|��� ����� (*.*)|*.*";
			this->openFileDialog->Title = L"������� ����";
			this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog_FileOk);
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(81, 83);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"�������";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnOpen);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio;

	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);
		for (int i = 0; i < figure.size(); i++) {
			path lines = figure[i]; // lines - ��������� ������� �����
			Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
			pen->Width = lines.thickness;
			vec2 start = normalize(T * vec3(lines.vertices[0], 1.0)); // ������ ��������� �����
			for (int j = 1; j < lines.vertices.size(); j++) { // ���� �� �������� ������ (�� �������)
				vec2 end = normalize(T * vec3(lines.vertices[j], 1.0)); // �������� �����
				g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� �������
				start = end; // �������� ����� �������� ������� ���������� ��������� ������ ����������
			}
		}

	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = ClientRectangle.Width / 2.f; // ���������� ������
		float Wcy = ClientRectangle.Height / 2.f; // �������� ����
		switch (e->KeyCode)
		{
		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		default:
			break;
		}
		Refresh();
		switch (e->KeyCode)
		{
		case Keys::Q:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(0.01f) * T; // ������� �� 0.01 ������ ������������
			// ������ ������
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::E:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(-0.01f) * T; // ������� �� -0.01 ������ ������������
			// ������ ������
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::W:
			T = translate(0.f, -1.f) * T; // ����� ����� �� ���� ������
			break;
		case Keys::A:
			T = translate(-1.f, 0.f) * T; // ����� ����� �� ���� ������
			break;
		case Keys::S:
			T = translate(0.f, 1.f) * T; // ����� ���� �� ���� ������
			break;
		case Keys::D:
			T = translate(1.f, 0.f) * T; // ����� ������ �� ���� ������
			break;
		case Keys::R:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(0.05f) * T; // ������� �� 0.05 ������ ������������
			// ������ ������
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::Y:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(-0.05f) * T; // ������� �� -0.05 ������ ������������
			// ������ ������
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::T:
			T = translate(0.f, -10.f) * T; // ����� ����� �� 10 ��������
			break;
		case Keys::G:
			T = translate(0.f, 10.f) * T; // ����� ���� �� 10 ��������
			break;
		case Keys::F:
			T = translate(-10.f, 0.f) * T; // ����� ����� �� 10 ��������
			break;
		case Keys::H:
			T = translate(10.f, 0.f) * T; // ����� ������ �� 10 ��������
			break;

		case Keys::Z:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1.1f, 1.1f) * T; // ������� �� 0.01 ������ ������������
			// ������ ������
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::X:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1 / 1.1f, 1 / 1.1f) * T; // ������� �� -0.01 ������ ������������
			// ������ ������
			T = translate(Wcx, Wcy) * T; // ������� ������� ��������� �������
			break;

		case Keys::U:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = mirrorX() * T;		//���������� ����������� ������������ �������������� ���
			// ������ ������ ������ ������� �������
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::J:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = mirrorY() * T;		//���������� ����������� ������������ ������������ ���
			// ������ ������ ������ ������� �������
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;

		case Keys::I:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1.1f, 1.f) * T;		//���������� �� ����������� �� 1.1
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::K:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1 / 1.1f, 1.f) * T;		//������ �� ����������� �� 1.1
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::O:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1.f, 1.1f) * T;		//���������� �� ��������� �� 1.1
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;
		case Keys::L:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = scale(1.f, 1 / 1.1f) * T;		//������ �� ��������� �� 1.1
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break;



		case Keys::Escape:
			T = initT; // ��������� T ��������� �������
			break;
		default:
			break;
		}
		Refresh();

	}
	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// � �������� ������� ������ ������ OK
			// ���������� ����� ����� �� openFileDialog->FileName � fileName
			wchar_t fileName[1024]; // ����������, � ������� ����������� �������� ��� �����
			for (int i = 0; i < openFileDialog->FileName->Length; i++)
				fileName[i] = openFileDialog->FileName[i];
			fileName[openFileDialog->FileName->Length] = '\0';

			// ���������� � �������� �����
			ifstream in;
			in.open(fileName);
			if (in.is_open()) {
				// ���� ������� ������
				figure.clear(); // ������� ��������� ������ �������
				// ��������� ���������� ��� ������ �� �����
				float thickness = 2; // ������� �� ��������� �� ��������� 2
				float r, g, b; // ������������ �����
				r = g = b = 0; // �������� ������������ ����� �� ��������� (������)
				string cmd; // ������ ��� ���������� ����� �������
				// ��������������� ������ � ������
				string str; // ������, � ������� ��������� ������ �����
				getline(in, str); // ��������� �� �������� ����� ������ ������
				while (in) { // ���� ��������� ������ ������� �������
					// ������������ ������
					if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
						// ����������� ������ �� ����� � �� �����������
						stringstream s(str); // ��������� ����� �� ������ str
						s >> cmd;
						if (cmd == "frame") { // ������� �����������
							s >> Vx >> Vy; // ��������� ���������� �������� Vx � Vy
							aspectFig = Vx / Vy; // ���������� ����������� ������
							float Wx = ClientRectangle.Width; // ������ ���� �� �����������
							float Wy = ClientRectangle.Height; // ������ ���� �� ���������
							float aspectForm = Wx / Wy; // ����������� ������ ���� ���������
							// ����������� ���������� ��� ���������� ��������� ����������� ������
							float S = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
							float Ty = S * Vy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
							initT = translate(0.f, Ty) * scale(S, -S); // �������������� ����������� ������ ������
							//T = initT;
							// ������� ���������������, � ����� �������
							// � initT ��������� ��� ��� ��������������
							T = initT;
						}
						else if (cmd == "color") { // ���� �����
							s >> r >> g >> b; // ��������� ��� ������������ �����
						}
						else if (cmd == "thickness") { // ������� �����
							s >> thickness; // ��������� �������� �������
						}
						else if (cmd == "path") { // ����� �����
							vector<vec2> vertices; // ������ ����� �������
							int N; // ���������� �����
							s >> N;
							string str1; // �������������� ������ ��� ������ �� �����
							while (N > 0) { // ���� �� ��� ����� �������
								getline(in, str1); // ��������� � str1 �� �������� ����� ��������� ������
								// ��� ��� ���� ����������, �� �� ����� ����� ��������� �� �����
								if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#')) {
									// ����������� ������ �� ����� � �� �����������
									// ������ � ��� ���� ���������
									float x, y; // ���������� ��� ����������
									stringstream s1(str1); // ��� ���� ��������� ����� �� ������ str1
									s1 >> x >> y;
									vertices.push_back(vec2(x, y)); // ��������� ����� � ������
									N--; // ��������� ������� ����� ��������� ���������� �����
								}
							}
							// ��� ����� �������, ���������� ������� (path) � ������ �� � ������ figure
							figure.push_back(path(vertices, vec3(r, g, b), thickness));
						}
					}
					// ��������� ��������� ������
					getline(in, str);
				}
				Refresh();
			}
		}
	}
	private: System::Void openFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	};
}


//(x,y) (x,y, 1.0)
//Matrix
//����� ����
//initT ������� ���������� ���������������
// T - ������� ����������� ��������������, ���������� ���������
// � �������� ������ ��������� � �������� ����, �������� � �������� ��������
//mirrorY, ������ �� �������������
//��
//����� �� 0 �� 255
//��
//color
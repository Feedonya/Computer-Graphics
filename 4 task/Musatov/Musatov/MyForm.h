#pragma once
#include "Clip.h"
#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"
#include <fstream>
#include <sstream>
#include<string>

namespace Musatov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	float Vx;
	float Vy;
	float aspectFig;
	mat3 T;
	mat3 initT; // ������� ���������� ��������������
	vector<model> models;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ btnOpen;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
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
			// 
			// btnOpen
			// 
			this->btnOpen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnOpen->Location = System::Drawing::Point(404, 12);
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
			this->ClientSize = System::Drawing::Size(491, 424);
			this->Controls->Add(this->btnOpen);
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

	private:float left = 30;
		   float right = 100;
		   float top = 20;
		   float bottom = 50;
		   float minX = left, maxX; // �������� ��������� ��������� x
		   float minY = top, maxY; // �������� ��������� ��������� y
		   float Wcx = left;
		   float Wcy; // ���������� ������ ������� ���� ��������������
		   float Wx, Wy; // ������ � ������ ��������������
	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // �������� ��������� ��������� x
		maxY = ClientRectangle.Height - bottom; // �������� ��������� ��������� y
		Wcy = maxY; // ���������� ������ ������� ���� ��������������
		Wx = maxX - left; // ������ ��������������
		Wy = maxY - top; // ������� ��������������
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::LightSkyBlue);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		for (int k = 0; k < models.size(); k++) { // ���� �� ��������
			vector<path> figure = models[k].figure; // ������ ������� ���������� �������
			mat3 TM = T * models[k].modelM; // ������� ������ �������������� �������
			for (int i = 0; i < figure.size(); i++) {
				path lines = figure[i]; // lines - ��������� ������� �����
				Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
				pen->Width = lines.thickness;

				vec2 start = normalize(TM * vec3(lines.vertices[0], 1.0)); // ������ ��������� �����
				for (int j = 1; j < lines.vertices.size(); j++) { // ���� �� �������� ������ (�� �������)
					vec2 end = normalize(TM * vec3(lines.vertices[j], 1.0)); // �������� �����
					vec2 tmpEnd = end;
					if (clip(start, end, minX, minY, maxX, maxY)) { // ���� ������� �����
						// ����� ���������, start � end - ����� ������� ����� �������
						g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� ������� �����
					}

					start = tmpEnd; // �������� ����� �������� ������� ���������� ��������� ������ ����������
				}
			}
		}
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();

	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		float Wcx = (ClientRectangle.Width) / 2.f; // ���������� ������
		float Wcy = (ClientRectangle.Height) / 2.f; // �������� ����

		switch (e->KeyCode) {
		case Keys::Q:
			T = translate(-Wcx + left, -Wcy + top) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(0.01f) * T; // ������� �� 0.01 ������ ������������
			// ������ ������
			T = translate(Wcx - left, Wcy - top) * T; // ������� ������ ��������� �������
			break;
		case Keys::W:
			T = translate(0.f, -1.f) * T; // ����� ����� �� ���� ������
			break;
		case Keys::Escape:
			T = initT; // ��������� T ��������� �������
			break;
		case Keys::S:
			T = translate(0.f, 1.f) * T;
			break;
		case Keys::A:
			T = translate(-1.f, 0.f) * T;
			break;
		case Keys::D:
			T = translate(1.f, 0.f) * T;
			break;
		case Keys::T:
			T = translate(0.f, -10.f) * T;
			break;
		case Keys::G:
			T = translate(0.f, 10.f) * T;
			break;
		case Keys::F:
			T = translate(-10.f, 0.f) * T;
			break;
		case Keys::H:
			T = translate(10.f, 0.f) * T;
			break;
		case Keys::E:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = rotate(-0.01f) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::R:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = rotate(-0.05f) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::Y:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = rotate(0.05f) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::Z:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = scale(1.1f) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::X:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = scale(1.f / 1.1) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::I:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = scale(1.1f, 1.f) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::K:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = scale(1.f / 1.1, 1.f) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::O:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = scale(1.f, 1.1f) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::L:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = scale(1.f, 1.f / 1.1) * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::U:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = mirrorX() * T;
			T = translate(Wcx - left, Wcy - top) * T;
			break;
		case Keys::J:
			T = translate(-Wcx + left, -Wcy + top) * T;
			T = mirrorY() * T;
			T = translate(Wcx - left, Wcy - top) * T;
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
			if (in.is_open())
			{
				// ���� ������� ������
				models.clear(); // ������� ��������� ������ �������
				// ��������� ���������� ��� ������ �� �����
				mat3 M = mat3(1.f); // ������� ��� ��������� ��������� �������
				mat3 initM; // ������� ��� ���������� �������������� ������� �������
				vector<mat3> transforms; // ���� ������ ��������������
				vector<path> figure; // ������ ������� ���������� �������
				float thickness = 2; // ������� �� ��������� �� ��������� 2
				float r, g, b; // ������������ �����
				r = g = b = 0; // �������� ������������ ����� �� ��������� (������)
				string cmd; // ������ ��� ���������� ����� �������
				// ��������������� ������ � ������
				string str; // ������, � ������� ��������� ������ �����
				getline(in, str); // ��������� �� �������� ����� ������ ������
				while (in)
				{ // ���� ��������� ������ ������� �������
					 // ������������ ������
					if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#'))
					{
						// ����������� ������ �� ����� � �� �����������
						stringstream s(str); // ��������� ����� �� ������ str
						s >> cmd;
						if (cmd == "frame")
						{ // ������� �����������
							s >> Vx >> Vy; // ��������� ���������� �������� Vx � Vy
							aspectFig = Vx / Vy; // ���������� ����������� ������

							float aspectRect = Wx / Wy; // ����������� ������ ���� ���������
							// ����������� ���������� ��� ���������� ��������� ����������� ������
// �������� ������ ������� � ������� ���������
							mat3 T1 = translate(-Vx / 2, -Vy / 2);
							// ��������������� �������� �������, �������� ������ ��������
							// ����������� ���������� ��� ���������� ��������� ����������� ������
							float S = aspectFig < aspectRect ? Wy / Vy : Wx / Vx;
							mat3 S1 = scale(S, -S);
							// ����� ����� �������� �� ������ ��������� � ������ �������
							mat3 T2 = translate(Wx / 2 + Wcx, Wcy - Wy / 2);
							// � initT ��������� ��� ��� �������������� (������ ������)
							initT = T2 * (S1 * T1);

							T = initT;
						}
						else if (cmd == "color")
						{
							s >> r >> g >> b;
						}
						else if (cmd == "thickness")
						{
							s >> thickness;
						}
						else if (cmd == "path")
						{ // ����� �����
							vector<vec2> vertices; // ������ ����� �������
							int N; // ���������� �����
							s >> N;
							string str1;
							while (N > 0)
							{
								getline(in, str1);
								if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#'))
								{
									float x, y;
									stringstream s1(str1);
									s1 >> x >> y;
									vertices.push_back(vec2(x, y));
									N--;
								}
							}
							figure.push_back(path(vertices, vec3(r, g, b), thickness));
						}
						else if (cmd == "model") { // ������ �������� ������ �������
							float mVcx, mVcy, mVx, mVy; // ��������� ������� model
							s >> mVcx >> mVcy >> mVx >> mVy; // ��������� �������� ����������
							float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
							// ����� ����� �������� �� ������ ��������� � ������ �������
							// ����� �������� �������� ���������������
							initM = scale(S) * translate(-mVcx, -mVcy);
							figure.clear();
						}
						else if (cmd == "figure") { // ������������ ����� ������
							models.push_back(model(figure, M * initM)); // ��������� ������� � ������
						}
						else if (cmd == "translate") { // �������
							float Tx, Ty; // ��������� �������������� ��������
							s >> Tx >> Ty; // ��������� ���������
							M = translate(Tx, Ty) * M; // ��������� ������� � ������ ��������������
						}
						else if (cmd == "scale") { // ���������������
							float S; // �������� ���������������
							s >> S; // ��������� ��������
							M = scale(S) * M; // ��������� ��������������� � ������ ��������������
						}
						else if (cmd == "rotate") { // �������
							float theta; // ���� �������� � ��������
							s >> theta; // ��������� ��������
							M = rotate(-theta / 180.f * Math::PI) * M; // ��������� ������� � ������ ��������������
						}
						else if (cmd == "pushTransform") { // ���������� ������� � ����
							transforms.push_back(M); // ��������� ������� � ����
						}
						else if (cmd == "popTransform") { // ����� � ������� �� �����
							M = transforms.back(); // �������� ������� ������� �����
							transforms.pop_back(); // ���������� ������� �� �����
						}
					}
					getline(in, str);
				}
				Refresh();
			}
		}
	}
	};
}
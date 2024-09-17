#pragma once

namespace Musatov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	float lines[] = {
		// ������
		0.5f, 3.0f, 1.f, 4.5f, // �� ����� ���� ����� �� ���
		1.f, 4.5f, 0.5f, 6.f, // ����� ��� ����� ����� �����
		0.5f, 6.f, 0.5f, 7.5f, // ����� ��� �����
		0.5f, 7.5f, 1.f, 8.f, // ����� ��� ���� �����
		1.f, 8.f, 1.5f, 8.f, // ����� ��� ���� ��������
		1.5f, 8.f, 2.f, 7.5f, // ����� ��� ���� ������
		2.0f, 7.5f, 1.5f, 6.f, // ����� ��� ������ ������ ����
		1.5f, 6.f, 1.5f, 4.5f, // ����� ��� ������ �� �������
		1.5f, 4.5f, 3.f, 4.5f, // �������
		3.f, 4.5f, 3.f, 6.f, // ������ ��� ����� ����� �����
		3.f, 6.f, 2.5f, 7.5f, //������ ��� �����
		2.5f, 7.5f, 3.f, 8.f, // ������ ��� ���� �����
		3.f, 8.f, 3.5f, 8.f, // ������ ��� ���� ��������
		3.5f, 8.f, 4.f, 7.5f, // ������ ��� ���� ������
		4.f, 7.5f, 4.f, 6.f, // ������ ��� ������ ����
		4.f, 6.f, 3.5f, 4.5f, // ������ ��� ������
		3.5f, 4.5f, 4.f, 3.f, // �� ������� ��� ���� �� ����
		4.f, 3.f, 3.5f, 1.5f, // ������ �����
		3.5f, 1.5f, 2.5f, 1.f, // ���������� ������
		2.5f, 1.f, 2.f, 1.f, // ���������� �����
		2.f, 1.f, 1.f, 1.5f, // ���������� �����
		1.f, 1.5f, 0.5f, 3.f, // ����� �����
		// ��������
		4.f, 3.f, 5.5f, 3.5f, // ����� �� ������ ������
		5.5f, 3.5f, 7.f, 3.5f, // ����� ����
		7.f, 3.5f, 7.5f, 2.5f, // ����� ������ �� ������
		7.5f, 2.5f, 8.f, 2.5f, // ����� ������
		8.f, 2.5f, 8.f, 2.f, // ����� ������
		8.f, 2.f, 7.5f, 2.f, // ����� ��� ������ ������
		7.5f, 2.f, 7.5f, 0.5f, // ������ ���� ������ ������ ����
		7.5f, 0.5f, 6.5f, 0.5f, // ������ ���� ���
		6.5f, 0.5f, 6.5f, 1.f, // ������ ���� �����
		6.5f, 1.f, 6.f, 1.f, // ����� ������ ���
		6.f, 1.f, 6.f, 0.5f, // ����� ������ ���� ������
		6.f, 0.5f, 5.f, 0.5f, // ����� ������ ���� ���
		5.f, 0.5f, 5.f, 1.f, // ����� ������ ���� �����
		5.f, 1.f, 4.f, 1.f, // ����� ������� � ��������� ������
		4.f, 1.f, 4.f, 0.5f, // ������ �������� ���� ������
		4.f, 0.5f, 3.f, 0.5f, // ������ �������� ���� ���
		3.f, 0.5f, 3.f, 1.f, // ������ �������� ���� �����
		3.f, 1.f, 2.5f, 1.f, // ����� �������� ���
		2.5f, 1.f, 2.5f, 0.5f, // �������� ���� ������
		2.5f, 0.5f, 1.5f, 0.5f, // �������� ���� ���
		1.5f, 0.5f, 1.5f, 1.25f, // �������� ���� �����
		// ����� ����
		1.5f, 3.5f, 1.5f, 3.f, // ����� ���� ����� ������ ����
		1.5f, 3.f, 2.f, 3.f, // ����� ���� ���
		2.f, 3.f, 2.f, 3.5f, // ����� ���� ������
		2.f, 3.5f, 1.5f, 3.5f, // ����� ���� ����
		// ������ ����
		2.5f,3.5f,2.5f,3.f, // ������ ���� �����
		2.5f,3.f,3.f, 3.f, // ������ ���� �����
		3.f,3.f,3.f,3.5f, // ������ ���� ������
		3.f,3.5f,2.5f,3.5f, // ������ ���� ������
		// ����� ��������
		1.f, 5.5f, 1.f, 7.f, // ����� ����� ��������
		3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
		// ���
		2.f, 2.5f, 2.5f, 2.5f, // ��� ������
		2.5f, 2.5f, 2.25f, 2.f, // ��� ������
		2.25f, 2.f, 2.f, 2.5f // ��� �����
	};
	unsigned int arrayLength = sizeof(lines) / sizeof(float);
	float Vx = 8.5f; // ������ ������� �� �����������
	float Vy = 8.5f; // ������ ������� �� ���������
	float aspectFig = Vx / Vy; // ����������� ������ �������



	float mushroom[] = {
		// ������ �����
		4.f, 4.f, 3.f, 4.f, // ����� �� ����� ����� �����
		3.f, 4.f, 1.5f, 4.5f, // ����� �� ����� ����� �����
		1.5f, 4.5f, 0.5f, 5.5f, // ����� �� ����� ����� �����
		0.5f, 5.5f, 0.5f, 7.f, // ����� �� ����� ����� �����
		0.5f, 7.f, 1.5f, 8.f, // ����� �� ����� ����� ������
		1.5f, 8.f, 4.f, 13.5f, // ����� ����� �����
		4.f, 13.5f, 4.5f, 14.f, // �� ����� ����� ����� � �������
		4.5f, 14.f, 5.5f, 14.f, // �������
		5.5f, 14.f, 6.f, 13.5f, // �� ������� � ������ ����� �����
		6.f, 13.5f, 8.5f, 8.f, // ������ ����� �����
		8.5f, 8.f, 9.5f, 7.f, // ������ �� ����� ���� ������
		9.5f, 7.f, 9.5f, 5.5f, // ������ �� ����� ����� ����
		9.5f, 5.5f, 8.5f, 4.5f, // ������ �� ����� ����� ����
		8.5f, 4.5f, 7.f, 4.f, // ������ �� ����� ����� ����
		7.f, 4.f, 6.f, 4.f, // ��������� � ������ ����� �����

		// ����� �����
		6.f, 4.f, 6.5f, 5.5f, // ������ ������� ����� �����
		6.5f, 5.5f, 5.5f, 6.f, // ������ ����� ������� �����
		5.5f, 6.f, 4.5f, 6.f, // �������
		4.5f, 6.f, 3.5f, 5.5f, // ����� ����� ������� �����
		3.5f, 5.5f, 4.f, 4.f, // ����� ������� ����� �����
		4.f, 4.f, 3.5f, 1.5f, // ����� �������� �����
		3.5f, 1.5f, 4.f, 0.5f, // ����� ������ ����� �����
		4.f, 0.5f, 5.f, 0.f, // ����� ��� �����
		5.f, 0.f, 6.f, 0.5f, // ������ ��� �����
		6.f, 0.5f, 6.5f, 1.5f, // ������ ������ ����� �����
		6.5f, 1.5f, 6.f, 4.f, // ������ �������� �����

		// �����
		2.f, 0.f, 1.f, 1.f, // � ����� ������� ����� �� ����� 
		1.f, 1.f, 2.5f, 1.f, // ����� ������
		2.5f, 1.f, 1.5f, 2.f, // ����� �����
		1.5f, 2.f, 2.5f, 1.5f, // ���� ������
		2.5f, 1.5f, 2.5f, 2.5f, // ����� �����
		2.5f, 2.5f, 3.f, 1.5f, // ���� �����
		3.f, 1.5f, 3.f, 3.5f, // ����� �����
		3.f, 3.5f, 3.5f, 1.5f, // ���� �����

		6.5f, 1.5f, 7.f, 3.5f, // �� ������ ������� ����� ����� ������
		7.f, 3.5f, 7.f, 1.5f, // ���� �����
		7.f, 1.5, 7.5f, 2.5f, // ������ �����
		7.5f, 2.5f, 7.5f, 1.5f, // ���� �����
		7.5f, 1.5f, 8.5f, 2.f, // ������ �����
		8.5f, 2.f, 7.5f, 1.f, // ����� ����
		7.5f, 1.f, 9.f, 1.f, // ������ �����
		9.f, 1.f, 8.f, 0.f, // ���� �����
		8.f, 0.f, 2.f, 0.f, // �������� �����

		// �����
		// ������ �����
		3.8f, 4.5f, 3.f, 4.5f, // � ����� ������� ����� �����
		3.f, 4.5f, 2.f, 5.f, // � ����� ������� ����� ����� �����
		2.f, 5.f, 1.f, 6.f, // � ����� ������� ����� ����� ����� �� �������� �������
		1.f, 6.f, 2.f, 7.f, // �� �������� ������� �����
		2.f, 7.f, 3.5f, 7.5f, // ������ ����� �� ������� ������� ����� �����
		3.5f, 7.5f, 6.5f, 7.5f, // ������� ������� �����
		6.5f, 7.5f, 8.f, 7.f, // �� ������� ����� ����
		8.f, 7.f, 9.f, 6.f, // ���� �� �������� �������
		9.f, 6.f, 8.f, 5.f, // �� �������� ������� ���� � ������ ������� �����
		8.f, 5.f, 7.f, 4.5f, // � ������ ������� ����� ���� �����
		7.f, 4.5f, 6.2f, 4.5f,  // ��������� � ������ ������� �����
		// ��������� �����
		3.5f, 5.5f, 1.5f, 6.5f, // 1-�� ��������� ����� �� ������� �����
		4.f, 5.7f, 3.f, 7.3f, // 2-�� ���������
		4.5f, 6.f, 4.f, 7.5f, // 3-�� ���������
		5.f, 6.f, 5.f, 7.5f, // 4-�� ���������
		5.5f, 6.f, 6.f, 7.5f, // 5-�� ���������
		6.f, 5.7f, 7.f, 7.3f, // 6-�� ���������
		6.5f, 5.5f, 8.5f, 6.5f, // 7-�� ���������

		// ������
		// ������ ������ ���� - 1-�� ����� ����� �������, 2-�� ���� � �.�.
		// 1-��
		4.f, 13.5f, 4.5f, 13.5f,
		4.5f, 13.5f, 5.f, 13.f,
		5.f, 13.f, 5.f, 12.5f,
		5.f, 12.5f, 4.5f, 12.f,
		4.5f, 12.f, 4.f, 12.f,
		4.f, 12.f, 3.5f, 12.5f,
		// 2-��
		5.f, 11.f, 5.f, 11.5f,
		5.f, 11.5f, 5.5f, 12.f,
		5.5f, 12.f, 6.f, 12.f,
		6.f, 12.f, 6.5f, 11.5f,
		6.5f, 11.5f, 6.5f, 11.f,
		6.5f, 11.f, 6.f, 10.5f,
		6.f, 10.5f, 5.5f, 10.5f,
		5.5f, 10.5f, 5.f, 11.f,
		// 3-��
		3.f, 9.5f, 3.f, 10.f,
		3.f, 10.f, 3.5f, 10.5f,
		3.5f, 10.5f, 4.f, 10.5f,
		4.f, 10.5f, 4.5f, 10.f,
		4.5f, 10.f, 4.5f, 9.5f,
		4.5f, 9.5f, 4.f, 9.f,
		4.f, 9.f, 3.5f, 9.f,
		3.5f, 9.f, 3.f, 9.5f,
		// 4-��
		5.5f, 8.5f, 5.5f, 9.5f,
		5.5f, 9.5f, 6.f, 10.f,
		6.f, 10.f, 7.f, 10.f,
		7.f, 10.f, 7.5f, 9.5f,
		7.5f, 9.5f, 7.5f, 8.5f,
		7.5f, 8.5f, 7.f, 8.f,
		7.f, 8.f, 6.f, 8.f,
		6.f, 8.f, 5.5f, 8.5f,
		// 5-��
		2.f, 9.f, 2.5f, 8.5f,
		2.5f, 8.5f, 2.5f, 8.f,
		2.5f, 8.f, 2.f, 7.5f,
		2.f, 7.5f, 1.f, 7.5f,
		// 6-��
		3.5f, 7.5f, 3.f, 8.f,
		3.f, 8.f, 3.5f, 8.5f,
		3.5f, 8.5f, 4.f, 8.5f,
		4.f, 8.5f, 4.5f, 8.f,
		4.5f, 8.f, 4.f, 7.5f,
		// 7-��
		8.5f, 8.f, 8.f, 7.5f,
		8.f, 7.5f, 8.5f, 7.f,
		8.5f, 7.f, 9.5f, 7.f,
		// 8-��
		0.5f, 6.f, 1.f, 6.5f,
		1.f, 6.5f, 0.5f, 7.f,
	};
	unsigned int arrayLengthMushroom = sizeof(mushroom) / sizeof(float);
	float Vx2 = 15.f;
	float Vy2 = 15.f;
	float aspectPicture = Vx2 / Vy2;


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
		System::ComponentModel::Container^ components;

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
	private: bool keepAspectRatio; // �������� - ��������� �� ����������� �������
	private: bool keepFlag;

	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		// ����
		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float Wx = ClientRectangle.Width; // ������ ���� �� �����������
		float Wy = ClientRectangle.Height; // ������ ���� �� ���������
		float aspectForm = Wx / Wy; // ����������� ������ ���� ���������
		float Sx, Sy;

		// ����
		Pen^ bluePen = gcnew Pen(Color::Blue, 2);

		float Wx2 = ClientRectangle.Width;
		float Wy2 = ClientRectangle.Height;
		float aspectWindow = Wx2 / Wy2;
		float Sx2, Sy2;


		//������� ����
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
		//������� �����
		else {
			if (keepAspectRatio) {
				//����������� ���������� ��� ���������� ��������� ����������� ������
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
			}
			else {
				Sx = Wx / Vx; // ����������� ���������� �� ��� Ox
				Sy = Wy / Vy; // ����������� ���������� �� ��� Oy
			}
			float Ty = Sy * Vy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
			for (int i = 0; i < arrayLength; i += 4) {
				g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1], Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
			}
		}
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true; // ��������� ��������: ��������� ����������� ������ �������
		keepFlag = true; // ��������� �������� ����� �������
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
//Vx � Vy � ������� ��������� ������� � ��������
//����� ��������� ������� ���������, � ��� �� ����������� ������� ������� ����� �������
//��������� Wx � Wy .
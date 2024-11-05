#include "Matrix.h"
#include "Transform.h"
#include <vector>
#include "Clip.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Musatov::MyForm form;
	Application::Run(% form);
}
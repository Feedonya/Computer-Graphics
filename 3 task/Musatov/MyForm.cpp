#include <vector>
#include <fstream>
#include <sstream>
#include "MyForm.h"
#include "Matrix.h"
#include "Transform.h"
#include "Figure.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Musatov::MyForm form;
	Application::Run(% form);
}
#include "Transform.h"
#include <fstream>
#include <sstream>
#include "Figure.h"
#include "Clip.h"
#include "MyForm.h"
#include "Matrix.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Musatov::MyForm form;
	Application::Run(% form);
}
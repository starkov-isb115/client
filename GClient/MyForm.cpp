using namespace System;
using namespace System::Windows::Forms;

#include "MyForm.h"

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GClient::MyForm form;
	Application::Run(%form);
}


#pragma once

#define WIN32_LEAN_AND_MEAN

#include <WinSock2.h>
#include <iostream>
#include <stdlib.h>
#include <clocale>
//#include <thread>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512


namespace GClient {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System;
 using namespace System::Threading;

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>

	
	public: void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(546, 195);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 228);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(313, 74);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(332, 228);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 74);
			this->button1->TabIndex = 2;
			this->button1->Text = L"SEND";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(459, 228);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"SIGN IN";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(459, 279);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(99, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"LEAVE";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 314);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

			}
#pragma endregion

	SOCKET mySock;


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	setlocale(LOCALE_ALL,"russian");
	WSAData wsaData;
	WORD sockver = MAKEWORD(2,2);
	if (WSAStartup(sockver, &wsaData) != 0 )
	{	
		exit(1);
	}
	 
	richTextBox1->Text = "connected to srv";

	SOCKADDR_IN address;
	int adresize = sizeof(address);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(1997);
	address.sin_family = AF_INET;

	mySock = socket(AF_INET, SOCK_STREAM, NULL);
	connect(mySock, (SOCKADDR*)&address, adresize);

	ThreadStart^ threadDelegate = gcnew ThreadStart(this, &MyForm::TestThread);
		Thread^ newThread = gcnew Thread( threadDelegate );
		newThread->Start();

		 }

	public: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

System::Void TestThread()
{
	char get[DEFAULT_BUFLEN];
	String^ msg = "";
	while(true)
	{
		recv(mySock, get, sizeof(get), NULL);
		printf(get); printf("\n");

		for ( int i = 0; i < sizeof(get); i ++ )
		{
			msg+= Convert::ToChar(get[i]);
		}

		richTextBox1->Invoke(gcnew Action<String^>(this, &MyForm::showMsg), msg);
	}
}

System::Void showMsg(String^ s)
	{ 
		richTextBox1->Text = s;
	};
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		char msg[DEFAULT_BUFLEN];
		String^ smg = "";

		smg += textBox1->Text;
		for ( int i = 0; i < sizeof(smg); i++ )
		{
			msg[i] = Convert::ToChar(smg[i]);
		}
		richTextBox1->Text = smg;
		send(mySock, msg, sizeof(msg), NULL);
		 }
};


}
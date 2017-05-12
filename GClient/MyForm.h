#pragma once

#define WIN32_LEAN_AND_MEAN

#include <WinSock2.h>
#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 1024


namespace GClient {

	using namespace std;
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
		/// Освободить все используемые ресурсы.
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

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  тянкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  leaveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  оливкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  дляМеняToolStripMenuItem;





	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>

	
	public: void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->тянкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оливкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->дляМеняToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->leaveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox1->ForeColor = System::Drawing::Color::Black;
			this->richTextBox1->Location = System::Drawing::Point(301, 56);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(277, 196);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(301, 260);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(131, 74);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(444, 284);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 50);
			this->button1->TabIndex = 2;
			this->button1->Text = L"SEND";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(466, 27);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"SIGN IN";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(332, 29);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem1, 
				this->menuToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(602, 24);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->тянкаToolStripMenuItem, 
				this->оливкаToolStripMenuItem, this->дляМеняToolStripMenuItem});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(88, 20);
			this->toolStripMenuItem1->Text = L"Backgrounds";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem1_Click);
			// 
			// тянкаToolStripMenuItem
			// 
			this->тянкаToolStripMenuItem->Name = L"тянкаToolStripMenuItem";
			this->тянкаToolStripMenuItem->Size = System::Drawing::Size(217, 22);
			this->тянкаToolStripMenuItem->Text = L"Для уверенных в себе";
			this->тянкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::тянкаToolStripMenuItem_Click);
			// 
			// оливкаToolStripMenuItem
			// 
			this->оливкаToolStripMenuItem->Name = L"оливкаToolStripMenuItem";
			this->оливкаToolStripMenuItem->Size = System::Drawing::Size(217, 22);
			this->оливкаToolStripMenuItem->Text = L"Для знающих толк в моде";
			this->оливкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оливкаToolStripMenuItem_Click);
			// 
			// дляМеняToolStripMenuItem
			// 
			this->дляМеняToolStripMenuItem->Name = L"дляМеняToolStripMenuItem";
			this->дляМеняToolStripMenuItem->Size = System::Drawing::Size(217, 22);
			this->дляМеняToolStripMenuItem->Text = L"Для меня";
			this->дляМеняToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::дляМеняToolStripMenuItem_Click);
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->leaveToolStripMenuItem});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// leaveToolStripMenuItem
			// 
			this->leaveToolStripMenuItem->Name = L"leaveToolStripMenuItem";
			this->leaveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->leaveToolStripMenuItem->Text = L"Leave";
			this->leaveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::leaveToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(602, 346);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->richTextBox1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
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
	 
	SOCKADDR_IN address;
	int adresize = sizeof(address);
	address.sin_addr.s_addr = inet_addr(getIP().c_str());
	address.sin_port = htons(1997);
	address.sin_family = AF_INET;

	mySock = socket(AF_INET, SOCK_STREAM, NULL);
	connect(mySock, (SOCKADDR*)&address, adresize);
	richTextBox1->AppendText("connect to srv!" + "\n");
	sendName();
	textBox2->Enabled = false;
	textBox2->Clear();

		ThreadStart^ threadDelegate = gcnew ThreadStart(this, &MyForm::TestThread);
		Thread^ newThread = gcnew Thread( threadDelegate );
		newThread->Start();

		 }

	public: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

System::Void sendName()
{
	String^ nick = "";
	nick = textBox2->Text;
	textBox2->Text = "";

	char msg[DEFAULT_BUFLEN];
	
		for ( int i = 0; i < nick->Length; i++)
		{
			msg[i] = nick[i];
		}
		for ( int i = nick->Length; i < DEFAULT_BUFLEN - nick->Length; i++)
		{
			msg[i] = '\0';
		}

		send(mySock,msg,sizeof(msg), NULL);
		richTextBox1->AppendText(nick + "\n");
}

void TestThread()
{
	while(1)
	{
	for (;; Sleep(75))
	{
		char *get = new char[1024];
		String^ msg = "";
	
	for (int i = 0; i < DEFAULT_BUFLEN; i++) get[i] = 0;

		recv(mySock, get, sizeof(get), NULL);
		printf(get); 
			printf("\n"); 
		for ( int i = 0; i < 1024; i ++ )
		{
			msg+= Convert::ToChar(get[i]);
		}
		
		richTextBox1->Invoke(gcnew Action<String^>(this, &MyForm::showMsg), msg);
		
	delete get;
	
	}
	}
}
System::Void showMsg(String^ msg)
	{ 
		
		richTextBox1->AppendText(msg);
	}

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ smg = "";
		smg += textBox1->Text;
		textBox1->Clear();
		char msg[DEFAULT_BUFLEN];
	
		for ( int i = 0; i < smg->Length; i++)
		{
			msg[i] = smg[i];
		}
		for ( int i = smg->Length; i < DEFAULT_BUFLEN - smg->Length; i++)
		{
			msg[i] = '\0';
		}
		msg[smg->Length] = '\n';

		send(mySock,msg,sizeof(msg), NULL);
		
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

string getIP()
		{
				setlocale(LC_ALL,"russian");

    string s; // сюда будем класть считанные строки
    ifstream file("C:\\cppstudio.txt"); // файл из которого читаем (для линукс путь будет выглядеть по другому)
	string str;
    while(getline(file, s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
		str = s;
    }

    file.close(); // обязательно закрываем файл что бы не повредить его

  vector<string> arr;
cout << str << endl;  string delim(" ");
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();

  while( ( next = str.find( delim, prev ) ) != string::npos ){

    string tmp = str.substr( prev, next-prev );
    cout << tmp << endl;

    arr.push_back( str.substr( prev, next-prev ) );
    prev = next + delta;
  }
 
  string tmp = str.substr( prev );
  cout << tmp << endl;

  arr.push_back( str.substr( prev ) );
 return tmp;
		}
private: System::Void тянкаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MyForm::BackgroundImage = Image::FromFile("C:\\t2.jpg");
		 }
private: System::Void Backgrounds_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void оливкаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MyForm::BackgroundImage = Image::FromFile("C:\\guard.png");
		 }
private: System::Void дляМеняToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  MyForm::BackgroundImage = Image::FromFile("C:\\havchik.png");
		 }
private: System::Void leaveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 closesocket(mySock);
			 exit(0);
		 }
};

}
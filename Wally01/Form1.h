#pragma once

namespace Wally01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	public:

	public:

	public:

	public:

	public:
		int flag = 0;
		String^ path = gcnew String("");
		String^ contenuTextbox3 = gcnew String("");
		String^ contenuTextbox4 = gcnew String("");
		String^ contenuTextbox5 = gcnew String("");
		
		










	public: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabPage^  tabPage8;
	private: System::Windows::Forms::TabPage^  tabPage9;
	private: System::Windows::Forms::TabPage^  tabPage10;
	private: System::Windows::Forms::TabPage^  tabPage11;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox_graphique;

	private: System::Windows::Forms::Label^  label11;

	private: System::Windows::Forms::CheckBox^  checkBox3;

	private: System::Windows::Forms::CheckBox^  checkBox1;
	public: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	public: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::ComboBox^  comboBox_choix1;
	private: System::Windows::Forms::ComboBox^  comboBox_choix6;


	private: System::Windows::Forms::ComboBox^  comboBox_choix5;

	private: System::Windows::Forms::ComboBox^  comboBox_choix4;

	private: System::Windows::Forms::ComboBox^  comboBox_choix3;

	private: System::Windows::Forms::ComboBox^  comboBox_choix2;

	private: System::Windows::Forms::CheckBox^  checkBox2;





	private: System::Windows::Forms::Button^  button2;
















			 
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
		

	protected:







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabPage10 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabPage11 = (gcnew System::Windows::Forms::TabPage());
			this->comboBox_choix1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_choix6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_choix5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_choix4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_choix3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_choix2 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->comboBox_graphique = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage8->SuspendLayout();
			this->tabPage9->SuspendLayout();
			this->tabPage10->SuspendLayout();
			this->tabPage11->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage8);
			this->tabControl1->Controls->Add(this->tabPage9);
			this->tabControl1->Controls->Add(this->tabPage10);
			this->tabControl1->Controls->Add(this->tabPage11);
			this->tabControl1->Location = System::Drawing::Point(0, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(924, 420);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->label2);
			this->tabPage8->Controls->Add(this->textBox1);
			this->tabPage8->Controls->Add(this->button1);
			this->tabPage8->Location = System::Drawing::Point(4, 25);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Size = System::Drawing::Size(916, 391);
			this->tabPage8->TabIndex = 7;
			this->tabPage8->Text = L"Fichier";
			this->tabPage8->UseVisualStyleBackColor = true;
			this->tabPage8->Click += gcnew System::EventHandler(this, &Form1::tabPage8_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(399, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(206, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Insérez le fichier qui sera utilisé";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(169, 122);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(403, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(609, 118);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button1->Size = System::Drawing::Size(141, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Parcourir";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// tabPage9
			// 
			this->tabPage9->Controls->Add(this->label12);
			this->tabPage9->Controls->Add(this->textBox2);
			this->tabPage9->Controls->Add(this->label3);
			this->tabPage9->Location = System::Drawing::Point(4, 25);
			this->tabPage9->Name = L"tabPage9";
			this->tabPage9->Size = System::Drawing::Size(916, 391);
			this->tabPage9->TabIndex = 8;
			this->tabPage9->Text = L"Données physiques";
			this->tabPage9->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(181, 160);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(98, 17);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Pas de temps:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(305, 95);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(257, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(222, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 17);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Masse:";
			// 
			// tabPage10
			// 
			this->tabPage10->Controls->Add(this->checkBox3);
			this->tabPage10->Controls->Add(this->checkBox1);
			this->tabPage10->Controls->Add(this->textBox5);
			this->tabPage10->Controls->Add(this->textBox4);
			this->tabPage10->Controls->Add(this->textBox3);
			this->tabPage10->Controls->Add(this->label10);
			this->tabPage10->Controls->Add(this->label9);
			this->tabPage10->Controls->Add(this->label8);
			this->tabPage10->Controls->Add(this->label7);
			this->tabPage10->Controls->Add(this->label6);
			this->tabPage10->Controls->Add(this->label5);
			this->tabPage10->Controls->Add(this->label4);
			this->tabPage10->Location = System::Drawing::Point(4, 25);
			this->tabPage10->Name = L"tabPage10";
			this->tabPage10->Size = System::Drawing::Size(916, 391);
			this->tabPage10->TabIndex = 9;
			this->tabPage10->Text = L"Configuration 3D";
			this->tabPage10->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(477, 295);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(18, 17);
			this->checkBox3->TabIndex = 12;
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(477, 249);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(18, 17);
			this->checkBox1->TabIndex = 10;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(408, 147);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(279, 22);
			this->textBox5->TabIndex = 9;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Form1::textBox5_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(408, 112);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(279, 22);
			this->textBox4->TabIndex = 8;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(408, 72);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(279, 22);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged_1);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(235, 295);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(233, 17);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Affichage du vecteur \"accéleration\":";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(235, 249);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(204, 17);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Affichage du vecteur \"vitesse\" :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(383, 200);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 17);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Vecteurs";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(282, 147);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(120, 17);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Vitesse de zoom :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(235, 112);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(167, 17);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Vitesse de déplacement :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(268, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(134, 17);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Vitesse de rotation :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(335, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(177, 17);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Déplacement de la caméra";
			// 
			// tabPage11
			// 
			this->tabPage11->Controls->Add(this->comboBox_choix1);
			this->tabPage11->Controls->Add(this->comboBox_choix6);
			this->tabPage11->Controls->Add(this->comboBox_choix5);
			this->tabPage11->Controls->Add(this->comboBox_choix4);
			this->tabPage11->Controls->Add(this->comboBox_choix3);
			this->tabPage11->Controls->Add(this->comboBox_choix2);
			this->tabPage11->Controls->Add(this->checkBox2);
			this->tabPage11->Controls->Add(this->label13);
			this->tabPage11->Controls->Add(this->comboBox_graphique);
			this->tabPage11->Controls->Add(this->label11);
			this->tabPage11->Location = System::Drawing::Point(4, 25);
			this->tabPage11->Name = L"tabPage11";
			this->tabPage11->Size = System::Drawing::Size(916, 391);
			this->tabPage11->TabIndex = 10;
			this->tabPage11->Text = L"Configuration 2D";
			this->tabPage11->UseVisualStyleBackColor = true;
			// 
			// comboBox_choix1
			// 
			this->comboBox_choix1->FormattingEnabled = true;
			this->comboBox_choix1->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"moduleAcc,", L"AccX", L"AccY", L"AccZ",
					L"moduleVit", L"VitX", L"VitY", L"VitZ", L"modulePos", L"PosX", L"PosY", L"PosZ", L"EnergiePotentielle", L"EnergieCinétique",
					L"EnergieMécanique"
			});
			this->comboBox_choix1->Location = System::Drawing::Point(114, 147);
			this->comboBox_choix1->Name = L"comboBox_choix1";
			this->comboBox_choix1->Size = System::Drawing::Size(121, 24);
			this->comboBox_choix1->TabIndex = 9;
			// 
			// comboBox_choix6
			// 
			this->comboBox_choix6->FormattingEnabled = true;
			this->comboBox_choix6->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"moduleAcc,", L"AccX", L"AccY", L"AccZ",
					L"moduleVit", L"VitX", L"VitY", L"VitZ", L"modulePos", L"PosX", L"PosY", L"PosZ", L"EnergiePotentielle", L"EnergieCinétique",
					L"EnergieMécanique"
			});
			this->comboBox_choix6->Location = System::Drawing::Point(539, 208);
			this->comboBox_choix6->Name = L"comboBox_choix6";
			this->comboBox_choix6->Size = System::Drawing::Size(121, 24);
			this->comboBox_choix6->TabIndex = 8;
			// 
			// comboBox_choix5
			// 
			this->comboBox_choix5->FormattingEnabled = true;
			this->comboBox_choix5->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"moduleAcc,", L"AccX", L"AccY", L"AccZ",
					L"moduleVit", L"VitX", L"VitY", L"VitZ", L"modulePos", L"PosX", L"PosY", L"PosZ", L"EnergiePotentielle", L"EnergieCinétique",
					L"EnergieMécanique"
			});
			this->comboBox_choix5->Location = System::Drawing::Point(539, 147);
			this->comboBox_choix5->Name = L"comboBox_choix5";
			this->comboBox_choix5->Size = System::Drawing::Size(121, 24);
			this->comboBox_choix5->TabIndex = 7;
			// 
			// comboBox_choix4
			// 
			this->comboBox_choix4->FormattingEnabled = true;
			this->comboBox_choix4->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"moduleAcc,", L"AccX", L"AccY", L"AccZ",
					L"moduleVit", L"VitX", L"VitY", L"VitZ", L"modulePos", L"PosX", L"PosY", L"PosZ", L"EnergiePotentielle", L"EnergieCinétique",
					L"EnergieMécanique"
			});
			this->comboBox_choix4->Location = System::Drawing::Point(332, 208);
			this->comboBox_choix4->Name = L"comboBox_choix4";
			this->comboBox_choix4->Size = System::Drawing::Size(121, 24);
			this->comboBox_choix4->TabIndex = 6;
			// 
			// comboBox_choix3
			// 
			this->comboBox_choix3->FormattingEnabled = true;
			this->comboBox_choix3->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"moduleAcc,", L"AccX", L"AccY", L"AccZ",
					L"moduleVit", L"VitX", L"VitY", L"VitZ", L"modulePos", L"PosX", L"PosY", L"PosZ", L"EnergiePotentielle", L"EnergieCinétique",
					L"EnergieMécanique"
			});
			this->comboBox_choix3->Location = System::Drawing::Point(332, 147);
			this->comboBox_choix3->Name = L"comboBox_choix3";
			this->comboBox_choix3->Size = System::Drawing::Size(121, 24);
			this->comboBox_choix3->TabIndex = 5;
			// 
			// comboBox_choix2
			// 
			this->comboBox_choix2->FormattingEnabled = true;
			this->comboBox_choix2->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"moduleAcc,", L"AccX", L"AccY", L"AccZ",
					L"moduleVit", L"VitX", L"VitY", L"VitZ", L"modulePos", L"PosX", L"PosY", L"PosZ", L"EnergiePotentielle", L"EnergieCinétique",
					L"EnergieMécanique"
			});
			this->comboBox_choix2->Location = System::Drawing::Point(114, 208);
			this->comboBox_choix2->Name = L"comboBox_choix2";
			this->comboBox_choix2->Size = System::Drawing::Size(121, 24);
			this->comboBox_choix2->TabIndex = 4;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(448, 272);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(18, 17);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(127, 276);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(268, 17);
			this->label13->TabIndex = 2;
			this->label13->Text = L"Simuler également sur les graphiques 2D";
			// 
			// comboBox_graphique
			// 
			this->comboBox_graphique->FormattingEnabled = true;
			this->comboBox_graphique->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"4", L"6" });
			this->comboBox_graphique->Location = System::Drawing::Point(425, 51);
			this->comboBox_graphique->Name = L"comboBox_graphique";
			this->comboBox_graphique->Size = System::Drawing::Size(121, 24);
			this->comboBox_graphique->TabIndex = 1;
			this->comboBox_graphique->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(242, 54);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(153, 17);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Nombre de graphiques";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(321, 430);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(245, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 289);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 17);
			this->label1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(936, 471);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Projet Walibi";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->tabControl1->ResumeLayout(false);
			this->tabPage8->ResumeLayout(false);
			this->tabPage8->PerformLayout();
			this->tabPage9->ResumeLayout(false);
			this->tabPage9->PerformLayout();
			this->tabPage10->ResumeLayout(false);
			this->tabPage10->PerformLayout();
			this->tabPage11->ResumeLayout(false);
			this->tabPage11->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				
				
				this->textBox1->Text = openFileDialog1->FileName;
				textBox1->Text = openFileDialog1->FileName;
				
				
				
				
				
				
			}
		
		}
		
	}
			 
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		comboBox_choix1->Enabled = false;
		comboBox_choix2->Enabled = false;
		comboBox_choix3->Enabled = false;
		comboBox_choix4->Enabled = false;
		comboBox_choix5->Enabled = false;
		comboBox_choix6->Enabled = false;
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	contenuTextbox3 = textBox3->Text;
	contenuTextbox4 = textBox4->Text; 
	contenuTextbox5 = textBox5->Text;
	

	MessageBox::Show(contenuTextbox5, "Erreur" , MessageBoxButtons::OK, MessageBoxIcon::Error);
	
	path = textBox1->Text;
	
	flag = 1;
	this->Close();
	

}
private: System::Void ouvrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	

}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void fichierToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void tabPage8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	int choix= this->comboBox_graphique->SelectedIndex;
	switch (choix)
	{
	case 0:
	{
		comboBox_choix1->Enabled = true;
		comboBox_choix2->Enabled = false;
		comboBox_choix3->Enabled = false;
		comboBox_choix4->Enabled = false;
		comboBox_choix5->Enabled = false;
		comboBox_choix6->Enabled = false;
		
	
		comboBox_choix2->Text = "";
		comboBox_choix3->Text = "";
		comboBox_choix4->Text = "";
		comboBox_choix5->Text = "";
		comboBox_choix6->Text = "";
		break;
	}
	case 1:
	{
		comboBox_choix1->Enabled = true;
		comboBox_choix2->Enabled = true;
		comboBox_choix3->Enabled = false;
		comboBox_choix4->Enabled = false;
		comboBox_choix5->Enabled = false;
		comboBox_choix6->Enabled = false;

		comboBox_choix3->Text = "";
		comboBox_choix4->Text = "";
		comboBox_choix5->Text = "";
		comboBox_choix6->Text = "";
		break;
	}
	case 2:
	{
		comboBox_choix1->Enabled = true;
		comboBox_choix2->Enabled = true;
		comboBox_choix3->Enabled = true;
		comboBox_choix4->Enabled = true;
		comboBox_choix5->Enabled = false;
		comboBox_choix6->Enabled = false;

		comboBox_choix5->Text = "";
		comboBox_choix6->Text = "";
		break;
	}
	case 3:
	{
		comboBox_choix1->Enabled = true;
		comboBox_choix2->Enabled = true;
		comboBox_choix3->Enabled = true;
		comboBox_choix4->Enabled = true;
		comboBox_choix5->Enabled = true;
		comboBox_choix6->Enabled = true;
		break;
	}
	
	
	}


}


private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	
	if (System::Text::RegularExpressions::Regex::IsMatch(textBox2->Text,"[ ^ 0-9]"))    //autoriser l'utilisateur a entré uniquement un chiffre entre 0 et 9
	{
		
	}
	else
	{
		//si la textbox ne contient aucun caractère ne pas génerer le message d'erreur
		if (textBox2->Text == "")
		{

		}
		else
		{//sinon, si la textbox contient des caractères ou des lettres ==> erreur
			MessageBox::Show("Veuillez entrer un nombre" , "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox2->Text = "";
		}
		
		
	}
}

		
	private: System::Void textBox3_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
		if (System::Text::RegularExpressions::Regex::IsMatch(textBox3->Text, "[ ^ 0-9]"))    //autoriser l'utilisateur a entré uniquement un chiffre entre 0 et 9
		{

		}
		else
		{
			//si la textbox ne contient aucun caractère ne pas génerer le message d'erreur
			if (textBox3->Text == "")
			{

			}
			else
			{//sinon, si la textbox contient des caractères ou des lettres ==> erreur
				MessageBox::Show("Veuillez entrer un nombre", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
				textBox3->Text = "";
			}

		}
	}
	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (System::Text::RegularExpressions::Regex::IsMatch(textBox4->Text, "[ ^ 0-9]"))    //autoriser l'utilisateur a entré uniquement un chiffre entre 0 et 9
		{

		}
		else
		{
			//si la textbox ne contient aucun caractère ne pas génerer le message d'erreur
			if (textBox4->Text == "")
			{

			}
			else
			{//sinon, si la textbox contient des caractères ou des lettres ==> erreur
				MessageBox::Show("Veuillez entrer un nombre", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
				textBox4->Text = "";
			}

		}
	}
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox5->Text, "[ ^ 0-9]"))    //autoriser l'utilisateur a entré uniquement un chiffre entre 0 et 9
		{

		}
		else
		{
			//si la textbox ne contient aucun caractère ne pas génerer le message d'erreur
			if (textBox5->Text == "")
			{

			}
			else
			{//sinon, si la textbox contient des caractères ou des lettres ==> erreur
				MessageBox::Show("Veuillez entrer un nombre", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
				textBox5->Text = "";
			}

		}
	}
};
}

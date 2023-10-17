#pragma once
#include "Leer_Cd.h"

namespace Proyecto1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
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
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_reproducir;
	protected:

	private: System::Windows::Forms::Button^ btn_adelantar;
	private: System::Windows::Forms::Button^ btn_menu;


	private: System::Windows::Forms::Button^ btn_retroceder;
	protected:




	private: System::Windows::Forms::Button^ btn_cargar;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			this->btn_reproducir = (gcnew System::Windows::Forms::Button());
			this->btn_adelantar = (gcnew System::Windows::Forms::Button());
			this->btn_menu = (gcnew System::Windows::Forms::Button());
			this->btn_retroceder = (gcnew System::Windows::Forms::Button());
			this->btn_cargar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_reproducir
			// 
			this->btn_reproducir->AutoSize = true;
			this->btn_reproducir->BackColor = System::Drawing::Color::Transparent;
			this->btn_reproducir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_reproducir.BackgroundImage")));
			this->btn_reproducir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_reproducir->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btn_reproducir->FlatAppearance->BorderSize = 0;
			this->btn_reproducir->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->btn_reproducir->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->btn_reproducir->ForeColor = System::Drawing::SystemColors::Control;
			this->btn_reproducir->Location = System::Drawing::Point(211, 197);
			this->btn_reproducir->Name = L"btn_reproducir";
			this->btn_reproducir->Size = System::Drawing::Size(90, 87);
			this->btn_reproducir->TabIndex = 0;
			this->btn_reproducir->UseVisualStyleBackColor = false;
			this->btn_reproducir->Click += gcnew System::EventHandler(this, &main::reproducir_Click);
			// 
			// btn_adelantar
			// 
			this->btn_adelantar->AutoSize = true;
			this->btn_adelantar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_adelantar.BackgroundImage")));
			this->btn_adelantar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_adelantar->Location = System::Drawing::Point(142, 229);
			this->btn_adelantar->Name = L"btn_adelantar";
			this->btn_adelantar->Size = System::Drawing::Size(53, 23);
			this->btn_adelantar->TabIndex = 1;
			this->btn_adelantar->UseVisualStyleBackColor = true;
			this->btn_adelantar->Click += gcnew System::EventHandler(this, &main::adelantar_Click);
			// 
			// btn_menu
			// 
			this->btn_menu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_menu.BackgroundImage")));
			this->btn_menu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_menu->Location = System::Drawing::Point(470, 12);
			this->btn_menu->Name = L"btn_menu";
			this->btn_menu->Size = System::Drawing::Size(50, 42);
			this->btn_menu->TabIndex = 2;
			this->btn_menu->UseVisualStyleBackColor = true;
			this->btn_menu->Click += gcnew System::EventHandler(this, &main::menu_Click);
			// 
			// btn_retroceder
			// 
			this->btn_retroceder->AutoSize = true;
			this->btn_retroceder->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_retroceder.BackgroundImage")));
			this->btn_retroceder->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_retroceder->Location = System::Drawing::Point(318, 229);
			this->btn_retroceder->Name = L"btn_retroceder";
			this->btn_retroceder->Size = System::Drawing::Size(53, 23);
			this->btn_retroceder->TabIndex = 3;
			this->btn_retroceder->UseVisualStyleBackColor = true;
			this->btn_retroceder->Click += gcnew System::EventHandler(this, &main::retroceder_Click);
			// 
			// btn_cargar
			// 
			this->btn_cargar->Location = System::Drawing::Point(12, 22);
			this->btn_cargar->Name = L"btn_cargar";
			this->btn_cargar->Size = System::Drawing::Size(75, 23);
			this->btn_cargar->TabIndex = 4;
			this->btn_cargar->Text = L"Cargar Cd";
			this->btn_cargar->UseVisualStyleBackColor = true;
			this->btn_cargar->Click += gcnew System::EventHandler(this, &main::btn_cargar_Click);
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(532, 296);
			this->Controls->Add(this->btn_cargar);
			this->Controls->Add(this->btn_retroceder);
			this->Controls->Add(this->btn_menu);
			this->Controls->Add(this->btn_adelantar);
			this->Controls->Add(this->btn_reproducir);
			this->Name = L"main";
			this->Text = L"main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Lista^ listado_de_cds = nullptr;

		private: System::Void menu_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void retroceder_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void reproducir_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void adelantar_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void btn_cargar_Click(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

			// Set the initial directory (optional)
			folderBrowserDialog1->SelectedPath = "C:\\";

			// Show the dialog and get the result
			System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();


			if (listado_de_cds) {
				listado_de_cds = nullptr;
			}
			if (result == System::Windows::Forms::DialogResult::OK) {
				msclr::interop::marshal_context context;
				listado_de_cds = Leer_dirrección(context.marshal_as<std::string>(folderBrowserDialog1->SelectedPath));
			}
		}
	};
}

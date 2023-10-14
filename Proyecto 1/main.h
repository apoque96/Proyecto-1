#pragma once
#include "Cd.h"

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
	private: System::Windows::Forms::Button^ reproducir;
	private: System::Windows::Forms::Button^ adelantar;
	private: System::Windows::Forms::Button^ menu;
	protected:



	private: System::Windows::Forms::Button^ retroceder;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			this->reproducir = (gcnew System::Windows::Forms::Button());
			this->adelantar = (gcnew System::Windows::Forms::Button());
			this->menu = (gcnew System::Windows::Forms::Button());
			this->retroceder = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// reproducir
			// 
			this->reproducir->AutoSize = true;
			this->reproducir->BackColor = System::Drawing::Color::Transparent;
			this->reproducir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"reproducir.BackgroundImage")));
			this->reproducir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->reproducir->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->reproducir->FlatAppearance->BorderSize = 0;
			this->reproducir->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->reproducir->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->reproducir->ForeColor = System::Drawing::SystemColors::Control;
			this->reproducir->Location = System::Drawing::Point(211, 197);
			this->reproducir->Name = L"reproducir";
			this->reproducir->Size = System::Drawing::Size(90, 87);
			this->reproducir->TabIndex = 0;
			this->reproducir->UseVisualStyleBackColor = false;
			this->reproducir->Click += gcnew System::EventHandler(this, &main::reproducir_Click);
			// 
			// adelantar
			// 
			this->adelantar->AutoSize = true;
			this->adelantar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"adelantar.BackgroundImage")));
			this->adelantar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->adelantar->Location = System::Drawing::Point(142, 229);
			this->adelantar->Name = L"adelantar";
			this->adelantar->Size = System::Drawing::Size(53, 23);
			this->adelantar->TabIndex = 1;
			this->adelantar->UseVisualStyleBackColor = true;
			this->adelantar->Click += gcnew System::EventHandler(this, &main::adelantar_Click);
			// 
			// menu
			// 
			this->menu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu.BackgroundImage")));
			this->menu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->menu->Location = System::Drawing::Point(470, 12);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(50, 42);
			this->menu->TabIndex = 2;
			this->menu->UseVisualStyleBackColor = true;
			this->menu->Click += gcnew System::EventHandler(this, &main::menu_Click);
			// 
			// retroceder
			// 
			this->retroceder->AutoSize = true;
			this->retroceder->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"retroceder.BackgroundImage")));
			this->retroceder->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->retroceder->Location = System::Drawing::Point(318, 229);
			this->retroceder->Name = L"retroceder";
			this->retroceder->Size = System::Drawing::Size(53, 23);
			this->retroceder->TabIndex = 3;
			this->retroceder->UseVisualStyleBackColor = true;
			this->retroceder->Click += gcnew System::EventHandler(this, &main::retroceder_Click);
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(532, 296);
			this->Controls->Add(this->retroceder);
			this->Controls->Add(this->menu);
			this->Controls->Add(this->adelantar);
			this->Controls->Add(this->reproducir);
			this->Name = L"main";
			this->Text = L"main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void menu_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void retroceder_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void reproducir_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void adelantar_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
};
}

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


	private: System::Windows::Forms::Button^ btn_menu;
	private: System::Windows::Forms::Button^ btn_siguiente;



	protected:




	private: System::Windows::Forms::Button^ btn_cargar;
	private: System::Windows::Forms::Panel^ pl_cds;
	private: System::Windows::Forms::DataGridView^ dgv_cd;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cd;
	private: System::Windows::Forms::Button^ btn_cds_cerrar;
	private: System::Windows::Forms::Panel^ pl_cancion;
	private: System::Windows::Forms::Button^ btn_cancion_cerrar;


	private: System::Windows::Forms::DataGridView^ dgv_cancion;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Artista;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Duración;
	private: System::Windows::Forms::ListBox^ lb_reproducción;
	private: System::Windows::Forms::Button^ btn_reproducción;
	private: System::Windows::Forms::Label^ lbl_Ordenar;
	private: System::Windows::Forms::Button^ btn_ordenar_nombre;






	private: System::Windows::Forms::Button^ btn_reproducción_cerrar;
	private: System::Windows::Forms::Panel^ pl_reproducción;
	private: System::Windows::Forms::Button^ btn_ordenar_duración;


	private: System::Windows::Forms::Button^ btn_ordenar_artista;

	private: System::Windows::Forms::Label^ lbl_reproducir;
	private: System::Windows::Forms::RadioButton^ rB_descendente;
	private: System::Windows::Forms::RadioButton^ rB_ascendente;












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
			this->btn_menu = (gcnew System::Windows::Forms::Button());
			this->btn_siguiente = (gcnew System::Windows::Forms::Button());
			this->btn_cargar = (gcnew System::Windows::Forms::Button());
			this->pl_cds = (gcnew System::Windows::Forms::Panel());
			this->btn_cds_cerrar = (gcnew System::Windows::Forms::Button());
			this->dgv_cd = (gcnew System::Windows::Forms::DataGridView());
			this->Cd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pl_cancion = (gcnew System::Windows::Forms::Panel());
			this->btn_cancion_cerrar = (gcnew System::Windows::Forms::Button());
			this->dgv_cancion = (gcnew System::Windows::Forms::DataGridView());
			this->Nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Artista = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Duración = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lb_reproducción = (gcnew System::Windows::Forms::ListBox());
			this->btn_reproducción = (gcnew System::Windows::Forms::Button());
			this->lbl_Ordenar = (gcnew System::Windows::Forms::Label());
			this->btn_ordenar_nombre = (gcnew System::Windows::Forms::Button());
			this->btn_reproducción_cerrar = (gcnew System::Windows::Forms::Button());
			this->pl_reproducción = (gcnew System::Windows::Forms::Panel());
			this->rB_descendente = (gcnew System::Windows::Forms::RadioButton());
			this->rB_ascendente = (gcnew System::Windows::Forms::RadioButton());
			this->btn_ordenar_duración = (gcnew System::Windows::Forms::Button());
			this->btn_ordenar_artista = (gcnew System::Windows::Forms::Button());
			this->lbl_reproducir = (gcnew System::Windows::Forms::Label());
			this->pl_cds->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_cd))->BeginInit();
			this->pl_cancion->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_cancion))->BeginInit();
			this->pl_reproducción->SuspendLayout();
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
			this->btn_reproducir->Location = System::Drawing::Point(231, 197);
			this->btn_reproducir->Name = L"btn_reproducir";
			this->btn_reproducir->Size = System::Drawing::Size(90, 87);
			this->btn_reproducir->TabIndex = 0;
			this->btn_reproducir->UseVisualStyleBackColor = false;
			this->btn_reproducir->Click += gcnew System::EventHandler(this, &main::reproducir_Click);
			// 
			// btn_menu
			// 
			this->btn_menu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_menu.BackgroundImage")));
			this->btn_menu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_menu->Location = System::Drawing::Point(12, 12);
			this->btn_menu->Name = L"btn_menu";
			this->btn_menu->Size = System::Drawing::Size(50, 42);
			this->btn_menu->TabIndex = 2;
			this->btn_menu->UseVisualStyleBackColor = true;
			this->btn_menu->Click += gcnew System::EventHandler(this, &main::menu_Click);
			// 
			// btn_siguiente
			// 
			this->btn_siguiente->AutoSize = true;
			this->btn_siguiente->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_siguiente.BackgroundImage")));
			this->btn_siguiente->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_siguiente->Location = System::Drawing::Point(338, 229);
			this->btn_siguiente->Name = L"btn_siguiente";
			this->btn_siguiente->Size = System::Drawing::Size(53, 23);
			this->btn_siguiente->TabIndex = 3;
			this->btn_siguiente->UseVisualStyleBackColor = true;
			this->btn_siguiente->Click += gcnew System::EventHandler(this, &main::btn_siguiente_Click);
			// 
			// btn_cargar
			// 
			this->btn_cargar->Location = System::Drawing::Point(445, 12);
			this->btn_cargar->Name = L"btn_cargar";
			this->btn_cargar->Size = System::Drawing::Size(75, 23);
			this->btn_cargar->TabIndex = 4;
			this->btn_cargar->Text = L"Cargar Cd";
			this->btn_cargar->UseVisualStyleBackColor = true;
			this->btn_cargar->Click += gcnew System::EventHandler(this, &main::btn_cargar_Click);
			// 
			// pl_cds
			// 
			this->pl_cds->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pl_cds->Controls->Add(this->btn_cds_cerrar);
			this->pl_cds->Controls->Add(this->dgv_cd);
			this->pl_cds->Location = System::Drawing::Point(383, 278);
			this->pl_cds->Name = L"pl_cds";
			this->pl_cds->Size = System::Drawing::Size(147, 190);
			this->pl_cds->TabIndex = 5;
			this->pl_cds->Visible = false;
			// 
			// btn_cds_cerrar
			// 
			this->btn_cds_cerrar->Location = System::Drawing::Point(-1, 159);
			this->btn_cds_cerrar->Name = L"btn_cds_cerrar";
			this->btn_cds_cerrar->Size = System::Drawing::Size(143, 23);
			this->btn_cds_cerrar->TabIndex = 1;
			this->btn_cds_cerrar->Text = L"Cerrar";
			this->btn_cds_cerrar->UseVisualStyleBackColor = true;
			this->btn_cds_cerrar->Click += gcnew System::EventHandler(this, &main::btn_cds_cerrar_Click);
			// 
			// dgv_cd
			// 
			this->dgv_cd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_cd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Cd });
			this->dgv_cd->Location = System::Drawing::Point(-1, 3);
			this->dgv_cd->Name = L"dgv_cd";
			this->dgv_cd->ReadOnly = true;
			this->dgv_cd->Size = System::Drawing::Size(143, 150);
			this->dgv_cd->TabIndex = 0;
			this->dgv_cd->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &main::dgv_cd_CellDoubleClick);
			// 
			// Cd
			// 
			this->Cd->HeaderText = L"Cd";
			this->Cd->Name = L"Cd";
			this->Cd->ReadOnly = true;
			// 
			// pl_cancion
			// 
			this->pl_cancion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pl_cancion->Controls->Add(this->btn_cancion_cerrar);
			this->pl_cancion->Controls->Add(this->dgv_cancion);
			this->pl_cancion->Location = System::Drawing::Point(397, 25);
			this->pl_cancion->Name = L"pl_cancion";
			this->pl_cancion->Size = System::Drawing::Size(345, 251);
			this->pl_cancion->TabIndex = 6;
			this->pl_cancion->Visible = false;
			// 
			// btn_cancion_cerrar
			// 
			this->btn_cancion_cerrar->Location = System::Drawing::Point(-1, 223);
			this->btn_cancion_cerrar->Name = L"btn_cancion_cerrar";
			this->btn_cancion_cerrar->Size = System::Drawing::Size(345, 23);
			this->btn_cancion_cerrar->TabIndex = 1;
			this->btn_cancion_cerrar->Text = L"Cerrar";
			this->btn_cancion_cerrar->UseVisualStyleBackColor = true;
			this->btn_cancion_cerrar->Click += gcnew System::EventHandler(this, &main::btn_cancion_cerrar_Click);
			// 
			// dgv_cancion
			// 
			this->dgv_cancion->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_cancion->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Nombre, this->Artista,
					this->Duración
			});
			this->dgv_cancion->Location = System::Drawing::Point(-1, 3);
			this->dgv_cancion->Name = L"dgv_cancion";
			this->dgv_cancion->ReadOnly = true;
			this->dgv_cancion->Size = System::Drawing::Size(343, 214);
			this->dgv_cancion->TabIndex = 0;
			this->dgv_cancion->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &main::dgv_cancion_CellDoubleClick);
			// 
			// Nombre
			// 
			this->Nombre->HeaderText = L"Nombre";
			this->Nombre->Name = L"Nombre";
			this->Nombre->ReadOnly = true;
			// 
			// Artista
			// 
			this->Artista->HeaderText = L"Artista";
			this->Artista->Name = L"Artista";
			this->Artista->ReadOnly = true;
			// 
			// Duración
			// 
			this->Duración->HeaderText = L"Duración";
			this->Duración->Name = L"Duración";
			this->Duración->ReadOnly = true;
			// 
			// lb_reproducción
			// 
			this->lb_reproducción->FormattingEnabled = true;
			this->lb_reproducción->Location = System::Drawing::Point(3, 3);
			this->lb_reproducción->Name = L"lb_reproducción";
			this->lb_reproducción->Size = System::Drawing::Size(500, 134);
			this->lb_reproducción->TabIndex = 2;
			// 
			// btn_reproducción
			// 
			this->btn_reproducción->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_reproducción.BackgroundImage")));
			this->btn_reproducción->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_reproducción->Location = System::Drawing::Point(12, 82);
			this->btn_reproducción->Name = L"btn_reproducción";
			this->btn_reproducción->Size = System::Drawing::Size(50, 42);
			this->btn_reproducción->TabIndex = 7;
			this->btn_reproducción->UseVisualStyleBackColor = true;
			this->btn_reproducción->Click += gcnew System::EventHandler(this, &main::btn_reproducción_Click);
			// 
			// lbl_Ordenar
			// 
			this->lbl_Ordenar->AutoSize = true;
			this->lbl_Ordenar->Location = System::Drawing::Point(4, 141);
			this->lbl_Ordenar->Name = L"lbl_Ordenar";
			this->lbl_Ordenar->Size = System::Drawing::Size(66, 13);
			this->lbl_Ordenar->TabIndex = 9;
			this->lbl_Ordenar->Text = L"Ordenar por:";
			// 
			// btn_ordenar_nombre
			// 
			this->btn_ordenar_nombre->Location = System::Drawing::Point(4, 157);
			this->btn_ordenar_nombre->Name = L"btn_ordenar_nombre";
			this->btn_ordenar_nombre->Size = System::Drawing::Size(66, 23);
			this->btn_ordenar_nombre->TabIndex = 10;
			this->btn_ordenar_nombre->Text = L"nombre";
			this->btn_ordenar_nombre->UseVisualStyleBackColor = true;
			this->btn_ordenar_nombre->Click += gcnew System::EventHandler(this, &main::btn_ordenar_nombre_Click);
			// 
			// btn_reproducción_cerrar
			// 
			this->btn_reproducción_cerrar->Location = System::Drawing::Point(4, 186);
			this->btn_reproducción_cerrar->Name = L"btn_reproducción_cerrar";
			this->btn_reproducción_cerrar->Size = System::Drawing::Size(209, 23);
			this->btn_reproducción_cerrar->TabIndex = 13;
			this->btn_reproducción_cerrar->Text = L"Cerrar";
			this->btn_reproducción_cerrar->UseVisualStyleBackColor = true;
			this->btn_reproducción_cerrar->Click += gcnew System::EventHandler(this, &main::btn_reproducción_cerrar_Click);
			// 
			// pl_reproducción
			// 
			this->pl_reproducción->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pl_reproducción->Controls->Add(this->rB_descendente);
			this->pl_reproducción->Controls->Add(this->rB_ascendente);
			this->pl_reproducción->Controls->Add(this->btn_ordenar_duración);
			this->pl_reproducción->Controls->Add(this->btn_ordenar_artista);
			this->pl_reproducción->Controls->Add(this->lb_reproducción);
			this->pl_reproducción->Controls->Add(this->btn_reproducción_cerrar);
			this->pl_reproducción->Controls->Add(this->lbl_Ordenar);
			this->pl_reproducción->Controls->Add(this->btn_ordenar_nombre);
			this->pl_reproducción->Location = System::Drawing::Point(22, 97);
			this->pl_reproducción->Name = L"pl_reproducción";
			this->pl_reproducción->Size = System::Drawing::Size(508, 219);
			this->pl_reproducción->TabIndex = 7;
			this->pl_reproducción->Visible = false;
			// 
			// rB_descendente
			// 
			this->rB_descendente->AutoSize = true;
			this->rB_descendente->Location = System::Drawing::Point(235, 172);
			this->rB_descendente->Name = L"rB_descendente";
			this->rB_descendente->Size = System::Drawing::Size(87, 17);
			this->rB_descendente->TabIndex = 17;
			this->rB_descendente->Text = L"descendente";
			this->rB_descendente->UseVisualStyleBackColor = true;
			this->rB_descendente->Click += gcnew System::EventHandler(this, &main::rB_descendente_Click);
			// 
			// rB_ascendente
			// 
			this->rB_ascendente->AutoSize = true;
			this->rB_ascendente->Checked = true;
			this->rB_ascendente->Location = System::Drawing::Point(235, 149);
			this->rB_ascendente->Name = L"rB_ascendente";
			this->rB_ascendente->Size = System::Drawing::Size(81, 17);
			this->rB_ascendente->TabIndex = 16;
			this->rB_ascendente->TabStop = true;
			this->rB_ascendente->Text = L"ascendente";
			this->rB_ascendente->UseVisualStyleBackColor = true;
			this->rB_ascendente->Click += gcnew System::EventHandler(this, &main::rB_ascendente_Click);
			// 
			// btn_ordenar_duración
			// 
			this->btn_ordenar_duración->Location = System::Drawing::Point(147, 157);
			this->btn_ordenar_duración->Name = L"btn_ordenar_duración";
			this->btn_ordenar_duración->Size = System::Drawing::Size(66, 23);
			this->btn_ordenar_duración->TabIndex = 15;
			this->btn_ordenar_duración->Text = L"duración";
			this->btn_ordenar_duración->UseVisualStyleBackColor = true;
			this->btn_ordenar_duración->Click += gcnew System::EventHandler(this, &main::btn_ordenar_duración_Click);
			// 
			// btn_ordenar_artista
			// 
			this->btn_ordenar_artista->Location = System::Drawing::Point(76, 157);
			this->btn_ordenar_artista->Name = L"btn_ordenar_artista";
			this->btn_ordenar_artista->Size = System::Drawing::Size(66, 23);
			this->btn_ordenar_artista->TabIndex = 14;
			this->btn_ordenar_artista->Text = L"artista";
			this->btn_ordenar_artista->UseVisualStyleBackColor = true;
			this->btn_ordenar_artista->Click += gcnew System::EventHandler(this, &main::btn_ordenar_artista_Click);
			// 
			// lbl_reproducir
			// 
			this->lbl_reproducir->AutoSize = true;
			this->lbl_reproducir->Location = System::Drawing::Point(228, 97);
			this->lbl_reproducir->Name = L"lbl_reproducir";
			this->lbl_reproducir->Size = System::Drawing::Size(0, 13);
			this->lbl_reproducir->TabIndex = 8;
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(532, 308);
			this->Controls->Add(this->pl_cds);
			this->Controls->Add(this->pl_cancion);
			this->Controls->Add(this->btn_menu);
			this->Controls->Add(this->pl_reproducción);
			this->Controls->Add(this->btn_reproducción);
			this->Controls->Add(this->btn_cargar);
			this->Controls->Add(this->btn_siguiente);
			this->Controls->Add(this->btn_reproducir);
			this->Controls->Add(this->lbl_reproducir);
			this->Name = L"main";
			this->Text = L"main";
			this->pl_cds->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_cd))->EndInit();
			this->pl_cancion->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_cancion))->EndInit();
			this->pl_reproducción->ResumeLayout(false);
			this->pl_reproducción->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma region variables

		//Lista que contiene los cds cargados
		Lista^ listado_de_cds = nullptr;
		//Guarda el nombre del cd
		System::String^ cd_seleccionado = nullptr;
		//Cola de reproducción
		Cola^ lista_reproducción = gcnew Cola();
		//Indica si hay alguna canción reproduciendose
		bool reproduciendo = false;
		//Indica de que forma se quiere ordenar la cola de reproducción
		forma_ordenar forma = ascendente;
#pragma endregion

#pragma region Metodos y funciones


		void actualizar_datos() {
			dgv_cd->AllowUserToAddRows = false;
			//Borra los datos
			dgv_cd->Rows->Clear();
			//Llena los datos al datagridview
			if (!listado_de_cds) return;
			auto current = listado_de_cds->get(0);
			while (current) {
				dgv_cd->Rows->Add(current->val_cd->get_nombre());
				current = current->next;
			}
		}

		void abrir_cd(int row_index) {
			if (row_index == -1) return;
			dgv_cancion->AllowUserToAddRows = false;
			//Borra los datos
			dgv_cancion->Rows->Clear();
			//Llena los datos del datagridview
			auto current = listado_de_cds->get(row_index)->val_cd->get_canciones()->get(0);
			cd_seleccionado = current->val_cancion->obtener_cd();
			while (current) {
				//Guarda la canción actual en una variable
				cancion^ current_cancion = current->val_cancion;
				//Formatea la duración como un string
				int minutos = current_cancion->obtener_duracion_segundos() / 60;
				int segundos = current_cancion->obtener_duracion_segundos() % 60;
				std::string s = std::to_string(minutos) + ":";
				if (segundos < 10) s += "0";
				s += std::to_string(segundos);
				System::String^ duracion = gcnew System::String(s.c_str());
				//Añade la canción
				dgv_cancion->Rows->Add(current_cancion->obtener_nombre(), current_cancion->obtener_artista(),
					duracion);
				current = current->next;
			}
			pl_cds->Visible = false;
			pl_cancion->Location = btn_menu->Location;
			pl_cancion->Visible = true;
		}
		//Añade a la cola de reproducción la canción seleccionada
		void añadir_a_cola(int row_index) {
			if (row_index == -1) return;
			System::String^ nombre = dgv_cancion->Rows[row_index]->Cells[0]->Value->ToString();
			System::String^ artista = dgv_cancion->Rows[row_index]->Cells[1]->Value->ToString();
			System::String^ duración = dgv_cancion->Rows[row_index]->Cells[2]->Value->ToString();

			std::string dur = msclr::interop::marshal_as<std::string>(duración);

			int duración_segundos = atoi(dur.substr(0, dur.find_last_of(':')).c_str()) * 60;
			duración_segundos += atoi(dur.substr(dur.find_last_of(':')+1).c_str());

			lista_reproducción->queue(nombre, artista, cd_seleccionado, duración_segundos);
			System::Windows::Forms::MessageBox::Show("Canción agregada a la lista de reproducción",
				"Agregar canción");
		}
		//Muestra en pantalla la canción a reproducir, mostrando los datos de
		//Artista, nombre de la canción, cd y la duración de la canción
		void actualizar_reproducción() {
			cancion^ canción_a_reproducir = lista_reproducción->front()->val_cancion;
			reproduciendo = true;

			int minutos = canción_a_reproducir->obtener_duracion_segundos() / 60;
			int segundos = canción_a_reproducir->obtener_duracion_segundos() % 60;
			std::string s = std::to_string(minutos) + ":";
			if (segundos < 10) s += "0";
			s += std::to_string(segundos);
			System::String^ duracion = gcnew System::String(s.c_str());

			lbl_reproducir->Text = "Canción: " + canción_a_reproducir->obtener_nombre()
				+ "\nArtista: " + canción_a_reproducir->obtener_artista()
				+ "\nDuración: " + duracion
				+ "\nCd: " + canción_a_reproducir->obtener_cd();

			btn_reproducir->BackgroundImage = Image::FromFile(
				IO::Path::Combine(Environment::CurrentDirectory, "imagenes", "Stop.png"));
		}
#pragma endregion

#pragma region  botones

		//Carga el folder indicado
		private: System::Void btn_cargar_Click(System::Object^ sender, System::EventArgs^ e) {
			//Oculta los paneles que están siendo mostrados
			pl_cancion->Visible = false;
			pl_cds->Visible = false;
			pl_reproducción->Visible = false;
			
			//Crea un FolderBrowserDialog y obtiene la dirección del folder seleccionado
			System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

			System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();

			//Vacía el listado de cds previamente cargados
			if (listado_de_cds) {
				listado_de_cds = nullptr;
			}
			//Se ejecuta si se ha seleccionado algún folder
			if (result == System::Windows::Forms::DialogResult::OK) {
				msclr::interop::marshal_context context;
				//Lee todos los archivos dentro del folder, guardando los correctos a una lista
				listado_de_cds = Leer_dirrección(context.marshal_as<std::string>(folderBrowserDialog1->SelectedPath));
				//Actualiza los datos de para mostrar los cds cargados
				actualizar_datos();
				//Cambia el estado de reproducción a falso(no se está reproduciendo)
				reproduciendo = false;
				lbl_reproducir->Text = "";
				btn_reproducir->BackgroundImage = Image::FromFile(
					IO::Path::Combine(Environment::CurrentDirectory, "imagenes", "Play.png"));
				//Limpia la cola de reproducción
				lb_reproducción->Items->Clear();
				lista_reproducción = gcnew Cola();
			}
		}
		//Muestra el panel que despliegua la información de los cds cargados
		private: System::Void menu_Click(System::Object^ sender, System::EventArgs^ e) {
			pl_cds->Location = btn_menu->Location;
			pl_cds->Visible = true;
			pl_reproducción->Visible = false;
		}
		//Muestra el panel con la lista de las canciones del cd seleccionado
		private: System::Void dgv_cd_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if(listado_de_cds)abrir_cd(e->RowIndex);
		}
		//Cierra el panel de la lista de los cds
		private: System::Void btn_cds_cerrar_Click(System::Object^ sender, System::EventArgs^ e) {
			pl_cds->Visible = false;
		}
		//Añade la canción elegida a la cola de reproducción
		private: System::Void dgv_cancion_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			añadir_a_cola(e->RowIndex);
		}
		//Cierra el panel que contiene la lista de canciones cargadas 
		private: System::Void btn_cancion_cerrar_Click(System::Object^ sender, System::EventArgs^ e) {
			pl_cancion->Visible = false;
		}
		//Enseña el panel de la cola de reproducción
		private: System::Void btn_reproducción_Click(System::Object^ sender, System::EventArgs^ e) {
			pl_reproducción->Location = btn_reproducción->Location;
			pl_reproducción->Visible = true;
			pl_cancion->Visible = false;
			pl_cds->Visible = false;
			lista_reproducción->mostrar_cola(lb_reproducción);
		}
		//Indica que la cola de reproducción se ordenara de forma ascendente
		private: System::Void rB_ascendente_Click(System::Object^ sender, System::EventArgs^ e) {
			forma = ascendente;
		}
		//Indica que la cola de reproducción se ordenara de forma descendente
		private: System::Void rB_descendente_Click(System::Object^ sender, System::EventArgs^ e) {
			forma = descendente;
		}
		//Ordena la cola de reproducción a traves del nombre de la canción
		private: System::Void btn_ordenar_nombre_Click(System::Object^ sender, System::EventArgs^ e) {
			lista_reproducción->sort(ordenar_por::nombre, forma);
			lista_reproducción->mostrar_cola(lb_reproducción);
			if(reproduciendo)actualizar_reproducción();
		}
		//Ordena la cola de reproducción a traves del artista
		private: System::Void btn_ordenar_artista_Click(System::Object^ sender, System::EventArgs^ e) {
			lista_reproducción->sort(ordenar_por::artista, forma);
			lista_reproducción->mostrar_cola(lb_reproducción);
			if(reproduciendo)actualizar_reproducción();
		}
		//Ordena la cola de reproducción a traves de la duración
		private: System::Void btn_ordenar_duración_Click(System::Object^ sender, System::EventArgs^ e) {
			lista_reproducción->sort(ordenar_por::duracion, forma);
			lista_reproducción->mostrar_cola(lb_reproducción);
			if(reproduciendo)actualizar_reproducción();
		}
		//Esconde el panel de la cola de reproducción
		private: System::Void btn_reproducción_cerrar_Click(System::Object^ sender, System::EventArgs^ e) {
			pl_reproducción->Visible = false;
		}
		//Muestra la canción a reproducir
		private: System::Void reproducir_Click(System::Object^ sender, System::EventArgs^ e) {
			if (lista_reproducción->isEmpty()) {
				System::Windows::Forms::MessageBox::Show("Lista de reproducción vacía", "Error");
				return;
			}
			if (reproduciendo) {
				reproduciendo = false;
				lbl_reproducir->Text = "";
				btn_reproducir->BackgroundImage = Image::FromFile(
					IO::Path::Combine(Environment::CurrentDirectory, "imagenes", "Play.png"));
				return;
			}
			actualizar_reproducción();
			reproduciendo = true;
		}
		//Reproduce la siguiente canción en la cola de reproducción y pone la canción anteriormente reproducida
		//al final de la cola
		private: System::Void btn_siguiente_Click(System::Object^ sender, System::EventArgs^ e) {
			if (lista_reproducción->isEmpty()) {
				System::Windows::Forms::MessageBox::Show("Lista de reproducción vacía", "Error");
				return;
			}
			auto temp = lista_reproducción->front()->val_cancion;
			lista_reproducción->pop();

			int duración_segundos = temp->obtener_duracion_segundos() / 60;
			duración_segundos += temp->obtener_duracion_segundos() % 60;

			lista_reproducción->queue(temp->obtener_nombre(), temp->obtener_artista(), 
				temp->obtener_cd(), duración_segundos);

			lista_reproducción->mostrar_cola(lb_reproducción);
			actualizar_reproducción();
		}
#pragma endregion
	};
}

#pragma once

namespace DataEntryMySQL 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	public ref class MyForm : public System::Windows::Forms::Form
	{

		#pragma region Variables
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDtR;

		public:
			MyForm(void)
			{
				InitializeComponent();
				MembershipDB();
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MyForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Panel^ panel1;
		protected:
		private: System::Windows::Forms::Panel^ panel2;
		private: System::Windows::Forms::Panel^ panel3;
		private: System::Windows::Forms::Button^ btnAddNew;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Button^ btnExit;
		private: System::Windows::Forms::Button^ btnReset;
		private: System::Windows::Forms::Button^ btnDelete;
		private: System::Windows::Forms::Button^ btnUpdate;
		private: System::Windows::Forms::Button^ btnRefresh;
		private: System::Windows::Forms::Button^ btnSearch;


		private: System::Windows::Forms::DataGridView^ dataGridView1;
		private: System::Windows::Forms::ComboBox^ comboBoxMemFees;

		private: System::Windows::Forms::ComboBox^ comboBoxMemType;

		private: System::Windows::Forms::DateTimePicker^ dateTime;
		private: System::Windows::Forms::TextBox^ txtAddress;


		private: System::Windows::Forms::TextBox^ txtSearch;

		private: System::Windows::Forms::TextBox^ txtLastName;



		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::TextBox^ txtDateReg;

		private: System::Windows::Forms::TextBox^ txtFirstName;

		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ txtMobile;

		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::TextBox^ txtRef;

		private: System::Windows::Forms::Label^ label11;
		private: System::Windows::Forms::Label^ label10;
		private: System::Windows::Forms::Label^ label9;
		private: System::Windows::Forms::ComboBox^ comboBoxProof;


		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

		#pragma endregion

		#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->comboBoxProof = (gcnew System::Windows::Forms::ComboBox());
				this->comboBoxMemFees = (gcnew System::Windows::Forms::ComboBox());
				this->comboBoxMemType = (gcnew System::Windows::Forms::ComboBox());
				this->dateTime = (gcnew System::Windows::Forms::DateTimePicker());
				this->btnSearch = (gcnew System::Windows::Forms::Button());
				this->txtAddress = (gcnew System::Windows::Forms::TextBox());
				this->txtSearch = (gcnew System::Windows::Forms::TextBox());
				this->txtLastName = (gcnew System::Windows::Forms::TextBox());
				this->label11 = (gcnew System::Windows::Forms::Label());
				this->label10 = (gcnew System::Windows::Forms::Label());
				this->label9 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->txtDateReg = (gcnew System::Windows::Forms::TextBox());
				this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->txtMobile = (gcnew System::Windows::Forms::TextBox());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->txtRef = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->panel2 = (gcnew System::Windows::Forms::Panel());
				this->btnExit = (gcnew System::Windows::Forms::Button());
				this->btnReset = (gcnew System::Windows::Forms::Button());
				this->btnDelete = (gcnew System::Windows::Forms::Button());
				this->btnUpdate = (gcnew System::Windows::Forms::Button());
				this->btnRefresh = (gcnew System::Windows::Forms::Button());
				this->btnAddNew = (gcnew System::Windows::Forms::Button());
				this->panel3 = (gcnew System::Windows::Forms::Panel());
				this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
				this->panel1->SuspendLayout();
				this->panel2->SuspendLayout();
				this->panel3->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
				this->SuspendLayout();
				// 
				// panel1
				// 
				this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				this->panel1->Controls->Add(this->comboBoxProof);
				this->panel1->Controls->Add(this->comboBoxMemFees);
				this->panel1->Controls->Add(this->comboBoxMemType);
				this->panel1->Controls->Add(this->dateTime);
				this->panel1->Controls->Add(this->btnSearch);
				this->panel1->Controls->Add(this->txtAddress);
				this->panel1->Controls->Add(this->txtSearch);
				this->panel1->Controls->Add(this->txtLastName);
				this->panel1->Controls->Add(this->label11);
				this->panel1->Controls->Add(this->label10);
				this->panel1->Controls->Add(this->label9);
				this->panel1->Controls->Add(this->label4);
				this->panel1->Controls->Add(this->label7);
				this->panel1->Controls->Add(this->label3);
				this->panel1->Controls->Add(this->txtDateReg);
				this->panel1->Controls->Add(this->txtFirstName);
				this->panel1->Controls->Add(this->label6);
				this->panel1->Controls->Add(this->label2);
				this->panel1->Controls->Add(this->txtMobile);
				this->panel1->Controls->Add(this->label5);
				this->panel1->Controls->Add(this->txtRef);
				this->panel1->Controls->Add(this->label1);
				this->panel1->Location = System::Drawing::Point(12, 29);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(1364, 424);
				this->panel1->TabIndex = 0;
				// 
				// comboBoxProof
				// 
				this->comboBoxProof->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->comboBoxProof->FormattingEnabled = true;
				this->comboBoxProof->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
					L"Government ID", L"Passport", L"Drivers License",
						L"Military ID", L"Tribal ID"
				});
				this->comboBoxProof->Location = System::Drawing::Point(574, 96);
				this->comboBoxProof->Name = L"comboBoxProof";
				this->comboBoxProof->Size = System::Drawing::Size(240, 37);
				this->comboBoxProof->TabIndex = 4;
				// 
				// comboBoxMemFees
				// 
				this->comboBoxMemFees->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->comboBoxMemFees->FormattingEnabled = true;
				this->comboBoxMemFees->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"$25", L"$100", L"$275", L"$1100" });
				this->comboBoxMemFees->Location = System::Drawing::Point(1013, 149);
				this->comboBoxMemFees->Name = L"comboBoxMemFees";
				this->comboBoxMemFees->Size = System::Drawing::Size(298, 37);
				this->comboBoxMemFees->TabIndex = 3;
				// 
				// comboBoxMemType
				// 
				this->comboBoxMemType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->comboBoxMemType->FormattingEnabled = true;
				this->comboBoxMemType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Weekly", L"Monthly", L"Quarterly", L"Annual" });
				this->comboBoxMemType->Location = System::Drawing::Point(1013, 101);
				this->comboBoxMemType->Name = L"comboBoxMemType";
				this->comboBoxMemType->Size = System::Drawing::Size(298, 37);
				this->comboBoxMemType->TabIndex = 3;
				// 
				// dateTime
				// 
				this->dateTime->Location = System::Drawing::Point(1013, 63);
				this->dateTime->Name = L"dateTime";
				this->dateTime->Size = System::Drawing::Size(298, 26);
				this->dateTime->TabIndex = 2;
				// 
				// btnSearch
				// 
				this->btnSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnSearch->Location = System::Drawing::Point(820, 1);
				this->btnSearch->Name = L"btnSearch";
				this->btnSearch->Size = System::Drawing::Size(187, 55);
				this->btnSearch->TabIndex = 0;
				this->btnSearch->Text = L"Search";
				this->btnSearch->UseVisualStyleBackColor = true;
				this->btnSearch->Click += gcnew System::EventHandler(this, &MyForm::btnSearch_Click);
				// 
				// txtAddress
				// 
				this->txtAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtAddress->Location = System::Drawing::Point(200, 143);
				this->txtAddress->Name = L"txtAddress";
				this->txtAddress->Size = System::Drawing::Size(614, 39);
				this->txtAddress->TabIndex = 1;
				// 
				// txtSearch
				// 
				this->txtSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtSearch->Location = System::Drawing::Point(1013, 8);
				this->txtSearch->Name = L"txtSearch";
				this->txtSearch->Size = System::Drawing::Size(320, 39);
				this->txtSearch->TabIndex = 1;
				this->txtSearch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtSearch_KeyPress);
				// 
				// txtLastName
				// 
				this->txtLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtLastName->Location = System::Drawing::Point(200, 92);
				this->txtLastName->Name = L"txtLastName";
				this->txtLastName->Size = System::Drawing::Size(240, 39);
				this->txtLastName->TabIndex = 1;
				// 
				// label11
				// 
				this->label11->AutoSize = true;
				this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label11->Location = System::Drawing::Point(832, 59);
				this->label11->Name = L"label11";
				this->label11->Size = System::Drawing::Size(162, 29);
				this->label11->TabIndex = 0;
				this->label11->Text = L"Date Of Birth";
				// 
				// label10
				// 
				this->label10->AutoSize = true;
				this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label10->Location = System::Drawing::Point(832, 99);
				this->label10->Name = L"label10";
				this->label10->Size = System::Drawing::Size(175, 29);
				this->label10->TabIndex = 0;
				this->label10->Text = L"Member Type";
				// 
				// label9
				// 
				this->label9->AutoSize = true;
				this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label9->Location = System::Drawing::Point(832, 144);
				this->label9->Name = L"label9";
				this->label9->Size = System::Drawing::Size(175, 29);
				this->label9->TabIndex = 0;
				this->label9->Text = L"Member Fees";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label4->Location = System::Drawing::Point(18, 149);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(109, 29);
				this->label4->TabIndex = 0;
				this->label4->Text = L"Address";
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label7->Location = System::Drawing::Point(446, 98);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(127, 26);
				this->label7->TabIndex = 0;
				this->label7->Text = L"Proof of ID";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label3->Location = System::Drawing::Point(18, 98);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(137, 29);
				this->label3->TabIndex = 0;
				this->label3->Text = L"Last Name";
				// 
				// txtDateReg
				// 
				this->txtDateReg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtDateReg->Location = System::Drawing::Point(574, 47);
				this->txtDateReg->Name = L"txtDateReg";
				this->txtDateReg->Size = System::Drawing::Size(240, 39);
				this->txtDateReg->TabIndex = 1;
				// 
				// txtFirstName
				// 
				this->txtFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtFirstName->Location = System::Drawing::Point(200, 47);
				this->txtFirstName->Name = L"txtFirstName";
				this->txtFirstName->Size = System::Drawing::Size(240, 39);
				this->txtFirstName->TabIndex = 1;
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label6->Location = System::Drawing::Point(446, 53);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(129, 29);
				this->label6->TabIndex = 0;
				this->label6->Text = L"Date Reg.";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label2->Location = System::Drawing::Point(18, 53);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(141, 29);
				this->label2->TabIndex = 0;
				this->label2->Text = L"First Name";
				// 
				// txtMobile
				// 
				this->txtMobile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtMobile->Location = System::Drawing::Point(574, 2);
				this->txtMobile->Name = L"txtMobile";
				this->txtMobile->Size = System::Drawing::Size(240, 39);
				this->txtMobile->TabIndex = 1;
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label5->Location = System::Drawing::Point(446, 8);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(93, 29);
				this->label5->TabIndex = 0;
				this->label5->Text = L"Mobile";
				// 
				// txtRef
				// 
				this->txtRef->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtRef->Location = System::Drawing::Point(200, 2);
				this->txtRef->Name = L"txtRef";
				this->txtRef->Size = System::Drawing::Size(240, 39);
				this->txtRef->TabIndex = 1;
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(18, 8);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(182, 29);
				this->label1->TabIndex = 0;
				this->label1->Text = L"Reference No:";
				// 
				// panel2
				// 
				this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				this->panel2->Controls->Add(this->btnExit);
				this->panel2->Controls->Add(this->btnReset);
				this->panel2->Controls->Add(this->btnDelete);
				this->panel2->Controls->Add(this->btnUpdate);
				this->panel2->Controls->Add(this->btnRefresh);
				this->panel2->Controls->Add(this->btnAddNew);
				this->panel2->Location = System::Drawing::Point(12, 238);
				this->panel2->Name = L"panel2";
				this->panel2->Size = System::Drawing::Size(1340, 66);
				this->panel2->TabIndex = 0;
				// 
				// btnExit
				// 
				this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnExit->Location = System::Drawing::Point(1108, 3);
				this->btnExit->Name = L"btnExit";
				this->btnExit->Size = System::Drawing::Size(215, 55);
				this->btnExit->TabIndex = 0;
				this->btnExit->Text = L"Exit";
				this->btnExit->UseVisualStyleBackColor = true;
				this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
				// 
				// btnReset
				// 
				this->btnReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnReset->Location = System::Drawing::Point(887, 3);
				this->btnReset->Name = L"btnReset";
				this->btnReset->Size = System::Drawing::Size(215, 55);
				this->btnReset->TabIndex = 0;
				this->btnReset->Text = L"Reset";
				this->btnReset->UseVisualStyleBackColor = true;
				this->btnReset->Click += gcnew System::EventHandler(this, &MyForm::btnReset_Click);
				// 
				// btnDelete
				// 
				this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnDelete->Location = System::Drawing::Point(666, 3);
				this->btnDelete->Name = L"btnDelete";
				this->btnDelete->Size = System::Drawing::Size(215, 55);
				this->btnDelete->TabIndex = 0;
				this->btnDelete->Text = L"Delete";
				this->btnDelete->UseVisualStyleBackColor = true;
				this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm::btnDelete_Click);
				// 
				// btnUpdate
				// 
				this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnUpdate->Location = System::Drawing::Point(445, 3);
				this->btnUpdate->Name = L"btnUpdate";
				this->btnUpdate->Size = System::Drawing::Size(215, 55);
				this->btnUpdate->TabIndex = 0;
				this->btnUpdate->Text = L"Update";
				this->btnUpdate->UseVisualStyleBackColor = true;
				this->btnUpdate->Click += gcnew System::EventHandler(this, &MyForm::btnUpdate_Click);
				// 
				// btnRefresh
				// 
				this->btnRefresh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnRefresh->Location = System::Drawing::Point(224, 3);
				this->btnRefresh->Name = L"btnRefresh";
				this->btnRefresh->Size = System::Drawing::Size(215, 55);
				this->btnRefresh->TabIndex = 0;
				this->btnRefresh->Text = L"Refresh";
				this->btnRefresh->UseVisualStyleBackColor = true;
				this->btnRefresh->Click += gcnew System::EventHandler(this, &MyForm::btnRefresh_Click);
				// 
				// btnAddNew
				// 
				this->btnAddNew->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnAddNew->Location = System::Drawing::Point(3, 3);
				this->btnAddNew->Name = L"btnAddNew";
				this->btnAddNew->Size = System::Drawing::Size(215, 55);
				this->btnAddNew->TabIndex = 0;
				this->btnAddNew->Text = L"Add New";
				this->btnAddNew->UseVisualStyleBackColor = true;
				this->btnAddNew->Click += gcnew System::EventHandler(this, &MyForm::btnAddNew_Click);
				// 
				// panel3
				// 
				this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				this->panel3->Controls->Add(this->dataGridView1);
				this->panel3->Location = System::Drawing::Point(12, 310);
				this->panel3->Name = L"panel3";
				this->panel3->Size = System::Drawing::Size(1340, 410);
				this->panel3->TabIndex = 0;
				// 
				// dataGridView1
				// 
				this->dataGridView1->AllowUserToAddRows = false;
				this->dataGridView1->AllowUserToDeleteRows = false;
				this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
				this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridView1->Location = System::Drawing::Point(21, 10);
				this->dataGridView1->Name = L"dataGridView1";
				this->dataGridView1->ReadOnly = true;
				this->dataGridView1->RowHeadersWidth = 62;
				this->dataGridView1->RowTemplate->Height = 28;
				this->dataGridView1->Size = System::Drawing::Size(1290, 409);
				this->dataGridView1->TabIndex = 0;
				this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellClick);
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1364, 732);
				this->Controls->Add(this->panel3);
				this->Controls->Add(this->panel2);
				this->Controls->Add(this->panel1);
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"MyForm";
				this->Text = L"Membership Registration";
				this->panel1->ResumeLayout(false);
				this->panel1->PerformLayout();
				this->panel2->ResumeLayout(false);
				this->panel3->ResumeLayout(false);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
				this->ResumeLayout(false);

			}
	#pragma endregion
		
		#pragma region Helper Functions
		//Opens the connection to the sql server and selects everything in the database.
		private: System::Void MembershipDB()
		{
			sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = password; database = membership";
			sqlConn->Open();

			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "select * from membership";

			sqlDtR = sqlCmd->ExecuteReader();

			sqlDt->Load(sqlDtR);

			sqlDtR->Close();

			sqlConn->Close();

			dataGridView1->DataSource = sqlDt;
		}

		//Refreshes the database.
		private: System::Void RefreshDB()
		{
			try
			{
				sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = password; database = membership";
				sqlCmd->Connection = sqlConn;

				MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter("select * from membership", sqlConn);
				DataTable^ sqlDt = gcnew DataTable();
				sqlDtA->Fill(sqlDt);
				dataGridView1->DataSource = sqlDt;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		#pragma endregion

		#pragma region Click Functions
		private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
		{
			System::Windows::Forms::DialogResult iExit;

			iExit = MessageBox::Show("Confirm if you want to exit the application.", "Data Entry Form", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question);

			try
			{
				if (iExit == System::Windows::Forms::DialogResult::Yes)
				{
					Application::Exit();
				}
			}
			catch(Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
			}
		}

		private: System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			try
			{
				txtRef->Text = "";
				txtFirstName->Text = "";
				txtLastName->Text = "";
				txtSearch->Text = "";
				txtAddress->Text = "";
				txtMobile->Text = "";
				txtDateReg->Text = "";
				comboBoxMemType->Text = "";
				comboBoxMemFees->Text = "";
				comboBoxProof->Text = "";
				dateTime->ResetText();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
			
		private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			try
			{
				sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = password; database = membership";
				sqlCmd->Connection = sqlConn;

				//Sets up command, and opens connection.
				MySqlCommand^ sqlCmd = gcnew MySqlCommand("delete from membership where RefNo = " + txtRef->Text + "", sqlConn);
				sqlConn->Open();

				//Executes command, and closes connection.
				sqlDtR = sqlCmd->ExecuteReader();
				MessageBox::Show("Record Deleted", "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
				sqlConn->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
				sqlConn->Close();
			}
			//Refreshes database.
			MembershipDB();
			RefreshDB();
		}
		private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			try
			{
				//Sets up the connection. and sets the command text.
				sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = password; database = membership";
				sqlCmd->Connection = sqlConn;
				
				sqlCmd->CommandText = "update membership set RefNo ='" + txtRef->Text + "', FirstName = '" + txtFirstName->Text + "', LastName = '" +
					txtLastName->Text + "', Address = '" + txtAddress->Text + "', Mobile = '" + txtMobile->Text + "', RegDate = '" + txtDateReg->Text +
					"', Prove = '" + comboBoxProof->Text + "', DOB = '" + dateTime->Text + "', MemberType = '" + comboBoxMemType->Text + "', MemberFees = '" +
					comboBoxMemFees->Text + "' WHERE RefNo =" + txtRef->Text + "", sqlConn;

				//Opens connection, executes command, then closes connection.
				sqlConn->Open();
				sqlCmd->ExecuteNonQuery();
				sqlConn->Close();

				//Refreshes database.
				MembershipDB();
				RefreshDB();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
				sqlConn->Close();
			}
		}
		private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
		{
			//Sets text from selected row.
			try
			{
				if (dataGridView1->SelectedRows->Count >= 1)
				{
					txtRef->Text = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
					txtFirstName->Text = dataGridView1->SelectedRows[0]->Cells[1]->Value->ToString();
					txtLastName->Text = dataGridView1->SelectedRows[0]->Cells[2]->Value->ToString();
					txtAddress->Text = dataGridView1->SelectedRows[0]->Cells[3]->Value->ToString();
					txtMobile->Text = dataGridView1->SelectedRows[0]->Cells[4]->Value->ToString();
					txtDateReg->Text = dataGridView1->SelectedRows[0]->Cells[5]->Value->ToString();
					comboBoxProof->Text = dataGridView1->SelectedRows[0]->Cells[6]->Value->ToString();
					dateTime->Text = dataGridView1->SelectedRows[0]->Cells[7]->Value->ToString();
					comboBoxMemType->Text = dataGridView1->SelectedRows[0]->Cells[8]->Value->ToString();
					comboBoxMemFees->Text = dataGridView1->SelectedRows[0]->Cells[9]->Value->ToString();
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			RefreshDB(); 
		}
		private: System::Void txtSearch_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
		{
			try
			{
				//If pressed enter, search by first name in search box.
				if (e->KeyChar == (Char)13)
				{
					DataView^ dv = sqlDt->DefaultView;
					dv->RowFilter = String::Format("Firstname like '%{0}%'", txtSearch->Text);
					dataGridView1->DataSource = dv->ToTable();
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}

		private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			//Searches by first name in search box.
			try
			{
				DataView^ dv = sqlDt->DefaultView;
				dv->RowFilter = String::Format("Firstname like '%{0}%'", txtSearch->Text);
				dataGridView1->DataSource = dv->ToTable();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}

		private: System::Void btnAddNew_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			try
			{
				//Setting the connection string to our mysql server.
				sqlConn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = password; database = membership";

				//Open SQL Connection
				sqlConn->Open();

				//Setting command connection equal to our connection.
				sqlCmd->Connection = sqlConn;

				//Insert SQL command.
				sqlCmd->CommandText = "insert into membership (RefNo, FirstName, LastName, Address, " +
					"Mobile, RegDate, Prove, DOB, MemberType, MemberFees)" +
					"values('" + txtRef->Text + "','"+ txtFirstName->Text + "','" + txtLastName->Text + "','" + 
					txtAddress->Text + "','" + txtMobile->Text + "','" + txtDateReg->Text + "','" + comboBoxProof->Text + "','" +
					dateTime->Text + "','" + comboBoxMemType->Text + "','" + comboBoxMemFees->Text + "')";

				//Executes command, then closes connection.
				sqlCmd->ExecuteNonQuery();
				sqlConn->Close();

				MembershipDB();
				RefreshDB();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
				sqlConn->Close();
			}
		}
		#pragma endregion
	};
}


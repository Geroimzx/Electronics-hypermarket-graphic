#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>

#include "Smartphone.h"
#include "Telephone.h"
#include "Cover.h"
#include "Headphone.h"
#include "PortableSpeakers.h"
#include "BluetoothHeadset.h"
#include "MemoryCard.h"
#include "ProtectiveGlass.h"
#include "SIMCard.h"

#include "Laptop.h"
#include "Printer.h"
#include "Router.h"
#include "Videocard.h"
#include "Processor.h"
#include "Motherboard.h"
#include "DDR.h"
#include "Storage.h"
#include "PowerSupplies.h"
#include "Accessories.h"

#include "Television.h"
#include "Multimedia.h"
#include "Projectors.h"
#include "TVAccessories.h"

#include "SmartWatches.h"
#include "Quadrocopter.h"
#include "Printer3D.h"

#include "Tablet.h"
#include "EBook.h"

#include "PhotoCamera.h"
#include "VideoCamera.h"

#include "ShoppingCart.h"

namespace EMarket {	
	using namespace std;
	using namespace msclr::interop;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Label^ titleLable;
	private: System::Windows::Forms::PictureBox^ logoMain;
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ category;
	private: System::Windows::Forms::ToolStripMenuItem^ shoppingCart;
	private: System::Windows::Forms::ToolStripMenuItem^ Exit;
	private: System::Windows::Forms::ToolStripMenuItem^ About;
	private: System::Windows::Forms::ToolStripMenuItem^ smartphonesAndTelephonesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ laptopsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tvsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ watchesStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tabletsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ photoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ smartphoneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ telephoneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ аксесуариДляСмартфонівToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ coverToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ headphonesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ portableSpeakersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ bluetoothToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ memoryCardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ protectiveGlassToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ simCardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ laptopToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ printerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ routerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pcComponentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ videocardToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ processorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ motherboardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ DDRToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ storageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ powerSuppliesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pcAccessoriesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tvToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mediaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ projectorsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tvAccessoriesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ watchesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quadrocoptersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ printer3DToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tabletToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eBookToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ photoCameraToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ videocameraToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ mainToolStripMenuItem;

	private: System::Windows::Forms::Label^ oplataLabelHead;
	private: System::Windows::Forms::Label^ oplataLabelControl;
	private: System::Windows::Forms::Button^ inCartButton;
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::Button^ buyButton;
	private: System::Windows::Forms::Button^ deleteCartButton;
	private: System::Windows::Forms::Button^ clearAllButton;


	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->titleLable = (gcnew System::Windows::Forms::Label());
			this->logoMain = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->mainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->category = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->smartphonesAndTelephonesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->smartphoneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->telephoneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->аксесуариДляСмартфонівToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->coverToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->headphonesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portableSpeakersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bluetoothToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->memoryCardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->protectiveGlassToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->simCardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->laptopsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->laptopToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->printerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->routerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pcComponentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->videocardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->motherboardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DDRToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->storageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->powerSuppliesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pcAccessoriesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tvsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tvToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mediaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->projectorsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tvAccessoriesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->watchesStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->watchesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quadrocoptersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->printer3DToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabletsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabletToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eBookToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->photoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->photoCameraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->videocameraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shoppingCart = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->About = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oplataLabelHead = (gcnew System::Windows::Forms::Label());
			this->oplataLabelControl = (gcnew System::Windows::Forms::Label());
			this->inCartButton = (gcnew System::Windows::Forms::Button());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->buyButton = (gcnew System::Windows::Forms::Button());
			this->deleteCartButton = (gcnew System::Windows::Forms::Button());
			this->clearAllButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoMain))->BeginInit();
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// titleLable
			// 
			this->titleLable->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->titleLable->AutoSize = true;
			this->titleLable->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->titleLable->ForeColor = System::Drawing::Color::RoyalBlue;
			this->titleLable->Location = System::Drawing::Point(357, 360);
			this->titleLable->Name = L"titleLable";
			this->titleLable->Size = System::Drawing::Size(399, 74);
			this->titleLable->TabIndex = 3;
			this->titleLable->Text = L"Гіпермаркет електроніки\r\nSilex";
			this->titleLable->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// logoMain
			// 
			this->logoMain->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->logoMain->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logoMain.Image")));
			this->logoMain->Location = System::Drawing::Point(450, 113);
			this->logoMain->Name = L"logoMain";
			this->logoMain->Size = System::Drawing::Size(193, 196);
			this->logoMain->TabIndex = 4;
			this->logoMain->TabStop = false;
			// 
			// menuStrip
			// 
			this->menuStrip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->menuStrip->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->menuStrip->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip->GripMargin = System::Windows::Forms::Padding(2);
			this->menuStrip->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->mainToolStripMenuItem,
					this->category, this->shoppingCart, this->Exit, this->About
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Padding = System::Windows::Forms::Padding(25, 15, 0, 15);
			this->menuStrip->Size = System::Drawing::Size(1064, 52);
			this->menuStrip->TabIndex = 5;
			this->menuStrip->Text = L"menuStrip";
			// 
			// mainToolStripMenuItem
			// 
			this->mainToolStripMenuItem->Name = L"mainToolStripMenuItem";
			this->mainToolStripMenuItem->Size = System::Drawing::Size(80, 22);
			this->mainToolStripMenuItem->Text = L"Головна";
			this->mainToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::mainToolStripMenuItem_Click);
			// 
			// category
			// 
			this->category->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->smartphonesAndTelephonesToolStripMenuItem,
					this->laptopsToolStripMenuItem, this->tvsToolStripMenuItem, this->watchesStripMenuItem, this->tabletsToolStripMenuItem, this->photoToolStripMenuItem
			});
			this->category->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->category->ForeColor = System::Drawing::Color::Black;
			this->category->Name = L"category";
			this->category->Size = System::Drawing::Size(145, 22);
			this->category->Text = L"Категорії товарів";
			// 
			// smartphonesAndTelephonesToolStripMenuItem
			// 
			this->smartphonesAndTelephonesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->smartphoneToolStripMenuItem,
					this->telephoneToolStripMenuItem, this->аксесуариДляСмартфонівToolStripMenuItem, this->simCardToolStripMenuItem
			});
			this->smartphonesAndTelephonesToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"smartphonesAndTelephonesToolStripMenuItem.Image")));
			this->smartphonesAndTelephonesToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::White;
			this->smartphonesAndTelephonesToolStripMenuItem->Name = L"smartphonesAndTelephonesToolStripMenuItem";
			this->smartphonesAndTelephonesToolStripMenuItem->Size = System::Drawing::Size(288, 22);
			this->smartphonesAndTelephonesToolStripMenuItem->Text = L"Смартфони та телефони";
			// 
			// smartphoneToolStripMenuItem
			// 
			this->smartphoneToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->smartphoneToolStripMenuItem->Name = L"smartphoneToolStripMenuItem";
			this->smartphoneToolStripMenuItem->Size = System::Drawing::Size(273, 22);
			this->smartphoneToolStripMenuItem->Text = L"Смартфони";
			this->smartphoneToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::smartphoneToolStripMenuItem_Click);
			// 
			// telephoneToolStripMenuItem
			// 
			this->telephoneToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->telephoneToolStripMenuItem->Name = L"telephoneToolStripMenuItem";
			this->telephoneToolStripMenuItem->Size = System::Drawing::Size(273, 22);
			this->telephoneToolStripMenuItem->Text = L"Телефони";
			this->telephoneToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::telephoneToolStripMenuItem_Click);
			// 
			// аксесуариДляСмартфонівToolStripMenuItem
			// 
			this->аксесуариДляСмартфонівToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->аксесуариДляСмартфонівToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->coverToolStripMenuItem,
					this->headphonesToolStripMenuItem, this->portableSpeakersToolStripMenuItem, this->bluetoothToolStripMenuItem, this->memoryCardToolStripMenuItem,
					this->protectiveGlassToolStripMenuItem
			});
			this->аксесуариДляСмартфонівToolStripMenuItem->Name = L"аксесуариДляСмартфонівToolStripMenuItem";
			this->аксесуариДляСмартфонівToolStripMenuItem->Size = System::Drawing::Size(273, 22);
			this->аксесуариДляСмартфонівToolStripMenuItem->Text = L"Аксесуари для смартфонів";
			// 
			// coverToolStripMenuItem
			// 
			this->coverToolStripMenuItem->Name = L"coverToolStripMenuItem";
			this->coverToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->coverToolStripMenuItem->Text = L"Чохли";
			this->coverToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::coverToolStripMenuItem_Click);
			// 
			// headphonesToolStripMenuItem
			// 
			this->headphonesToolStripMenuItem->Name = L"headphonesToolStripMenuItem";
			this->headphonesToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->headphonesToolStripMenuItem->Text = L"Навушники";
			this->headphonesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::headphonesToolStripMenuItem_Click);
			// 
			// portableSpeakersToolStripMenuItem
			// 
			this->portableSpeakersToolStripMenuItem->Name = L"portableSpeakersToolStripMenuItem";
			this->portableSpeakersToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->portableSpeakersToolStripMenuItem->Text = L"Портативні колонки";
			this->portableSpeakersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::portableSpeakersToolStripMenuItem_Click);
			// 
			// bluetoothToolStripMenuItem
			// 
			this->bluetoothToolStripMenuItem->Name = L"bluetoothToolStripMenuItem";
			this->bluetoothToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->bluetoothToolStripMenuItem->Text = L"Bluetooth-гарнітури";
			this->bluetoothToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::bluetoothToolStripMenuItem_Click);
			// 
			// memoryCardToolStripMenuItem
			// 
			this->memoryCardToolStripMenuItem->Name = L"memoryCardToolStripMenuItem";
			this->memoryCardToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->memoryCardToolStripMenuItem->Text = L"Карти пам\'яті";
			this->memoryCardToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::memoryCardToolStripMenuItem_Click);
			// 
			// protectiveGlassToolStripMenuItem
			// 
			this->protectiveGlassToolStripMenuItem->Name = L"protectiveGlassToolStripMenuItem";
			this->protectiveGlassToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->protectiveGlassToolStripMenuItem->Text = L"Захисні плівки та скло";
			this->protectiveGlassToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::protectiveGlassToolStripMenuItem_Click);
			// 
			// simCardToolStripMenuItem
			// 
			this->simCardToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->simCardToolStripMenuItem->Name = L"simCardToolStripMenuItem";
			this->simCardToolStripMenuItem->Size = System::Drawing::Size(273, 22);
			this->simCardToolStripMenuItem->Text = L"Стартові пакети";
			this->simCardToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::simCardToolStripMenuItem_Click);
			// 
			// laptopsToolStripMenuItem
			// 
			this->laptopsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->laptopToolStripMenuItem,
					this->printerToolStripMenuItem, this->routerToolStripMenuItem, this->pcComponentToolStripMenuItem, this->pcAccessoriesToolStripMenuItem
			});
			this->laptopsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"laptopsToolStripMenuItem.Image")));
			this->laptopsToolStripMenuItem->Name = L"laptopsToolStripMenuItem";
			this->laptopsToolStripMenuItem->Size = System::Drawing::Size(288, 22);
			this->laptopsToolStripMenuItem->Text = L"Ноутбуки та комп\'ютери";
			// 
			// laptopToolStripMenuItem
			// 
			this->laptopToolStripMenuItem->Name = L"laptopToolStripMenuItem";
			this->laptopToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->laptopToolStripMenuItem->Text = L"Ноутбуки";
			this->laptopToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::laptopToolStripMenuItem_Click);
			// 
			// printerToolStripMenuItem
			// 
			this->printerToolStripMenuItem->Name = L"printerToolStripMenuItem";
			this->printerToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->printerToolStripMenuItem->Text = L"Принтери";
			this->printerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::printerToolStripMenuItem_Click);
			// 
			// routerToolStripMenuItem
			// 
			this->routerToolStripMenuItem->Name = L"routerToolStripMenuItem";
			this->routerToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->routerToolStripMenuItem->Text = L"Роутери";
			this->routerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::routerToolStripMenuItem_Click);
			// 
			// pcComponentToolStripMenuItem
			// 
			this->pcComponentToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->videocardToolStripMenuItem,
					this->processorToolStripMenuItem, this->motherboardToolStripMenuItem, this->DDRToolStripMenuItem, this->storageToolStripMenuItem,
					this->powerSuppliesToolStripMenuItem
			});
			this->pcComponentToolStripMenuItem->Name = L"pcComponentToolStripMenuItem";
			this->pcComponentToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->pcComponentToolStripMenuItem->Text = L"Комплектуючі до ПК";
			// 
			// videocardToolStripMenuItem
			// 
			this->videocardToolStripMenuItem->Name = L"videocardToolStripMenuItem";
			this->videocardToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->videocardToolStripMenuItem->Text = L"Відеокарти";
			this->videocardToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::videocardToolStripMenuItem_Click);
			// 
			// processorToolStripMenuItem
			// 
			this->processorToolStripMenuItem->Name = L"processorToolStripMenuItem";
			this->processorToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->processorToolStripMenuItem->Text = L"Процесори";
			this->processorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::processorToolStripMenuItem_Click);
			// 
			// motherboardToolStripMenuItem
			// 
			this->motherboardToolStripMenuItem->Name = L"motherboardToolStripMenuItem";
			this->motherboardToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->motherboardToolStripMenuItem->Text = L"Материнські плати";
			this->motherboardToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::motherboardToolStripMenuItem_Click);
			// 
			// DDRToolStripMenuItem
			// 
			this->DDRToolStripMenuItem->Name = L"DDRToolStripMenuItem";
			this->DDRToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->DDRToolStripMenuItem->Text = L"Пам\'ять DDR";
			this->DDRToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::DDRToolStripMenuItem_Click);
			// 
			// storageToolStripMenuItem
			// 
			this->storageToolStripMenuItem->Name = L"storageToolStripMenuItem";
			this->storageToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->storageToolStripMenuItem->Text = L"SSD і HDD";
			this->storageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::storageToolStripMenuItem_Click);
			// 
			// powerSuppliesToolStripMenuItem
			// 
			this->powerSuppliesToolStripMenuItem->Name = L"powerSuppliesToolStripMenuItem";
			this->powerSuppliesToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->powerSuppliesToolStripMenuItem->Text = L"Блоки живлення";
			this->powerSuppliesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::powerSuppliesToolStripMenuItem_Click);
			// 
			// pcAccessoriesToolStripMenuItem
			// 
			this->pcAccessoriesToolStripMenuItem->Name = L"pcAccessoriesToolStripMenuItem";
			this->pcAccessoriesToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->pcAccessoriesToolStripMenuItem->Text = L"Аксесуари";
			this->pcAccessoriesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::pcAccessoriesToolStripMenuItem_Click);
			// 
			// tvsToolStripMenuItem
			// 
			this->tvsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->tvToolStripMenuItem,
					this->mediaToolStripMenuItem, this->projectorsToolStripMenuItem, this->tvAccessoriesToolStripMenuItem
			});
			this->tvsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tvsToolStripMenuItem.Image")));
			this->tvsToolStripMenuItem->Name = L"tvsToolStripMenuItem";
			this->tvsToolStripMenuItem->Size = System::Drawing::Size(288, 22);
			this->tvsToolStripMenuItem->Text = L"Телевізори та мультимедіа";
			// 
			// tvToolStripMenuItem
			// 
			this->tvToolStripMenuItem->Name = L"tvToolStripMenuItem";
			this->tvToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->tvToolStripMenuItem->Text = L"Телевізори";
			this->tvToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::tvToolStripMenuItem_Click);
			// 
			// mediaToolStripMenuItem
			// 
			this->mediaToolStripMenuItem->Name = L"mediaToolStripMenuItem";
			this->mediaToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->mediaToolStripMenuItem->Text = L"Мультимедіа та звук";
			this->mediaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::mediaToolStripMenuItem_Click);
			// 
			// projectorsToolStripMenuItem
			// 
			this->projectorsToolStripMenuItem->Name = L"projectorsToolStripMenuItem";
			this->projectorsToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->projectorsToolStripMenuItem->Text = L"Проектори та екрани";
			this->projectorsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::projectorsToolStripMenuItem_Click);
			// 
			// tvAccessoriesToolStripMenuItem
			// 
			this->tvAccessoriesToolStripMenuItem->Name = L"tvAccessoriesToolStripMenuItem";
			this->tvAccessoriesToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->tvAccessoriesToolStripMenuItem->Text = L"Аксесуари для ТВ";
			this->tvAccessoriesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::tvAccessoriesToolStripMenuItem_Click);
			// 
			// watchesStripMenuItem
			// 
			this->watchesStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->watchesToolStripMenuItem,
					this->quadrocoptersToolStripMenuItem, this->printer3DToolStripMenuItem
			});
			this->watchesStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"watchesStripMenuItem.Image")));
			this->watchesStripMenuItem->Name = L"watchesStripMenuItem";
			this->watchesStripMenuItem->Size = System::Drawing::Size(288, 22);
			this->watchesStripMenuItem->Text = L"Смарт-годинники та гаджети";
			// 
			// watchesToolStripMenuItem
			// 
			this->watchesToolStripMenuItem->Name = L"watchesToolStripMenuItem";
			this->watchesToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->watchesToolStripMenuItem->Text = L"Смарт-годинники";
			this->watchesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::watchesToolStripMenuItem_Click);
			// 
			// quadrocoptersToolStripMenuItem
			// 
			this->quadrocoptersToolStripMenuItem->Name = L"quadrocoptersToolStripMenuItem";
			this->quadrocoptersToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->quadrocoptersToolStripMenuItem->Text = L"Квадрокоптери";
			this->quadrocoptersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::quadrocoptersToolStripMenuItem_Click);
			// 
			// printer3DToolStripMenuItem
			// 
			this->printer3DToolStripMenuItem->Name = L"printer3DToolStripMenuItem";
			this->printer3DToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->printer3DToolStripMenuItem->Text = L"3D-принтери";
			this->printer3DToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::printer3DToolStripMenuItem_Click);
			// 
			// tabletsToolStripMenuItem
			// 
			this->tabletsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tabletToolStripMenuItem,
					this->eBookToolStripMenuItem
			});
			this->tabletsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabletsToolStripMenuItem.Image")));
			this->tabletsToolStripMenuItem->Name = L"tabletsToolStripMenuItem";
			this->tabletsToolStripMenuItem->Size = System::Drawing::Size(288, 22);
			this->tabletsToolStripMenuItem->Text = L"Планшети та електронні книги";
			// 
			// tabletToolStripMenuItem
			// 
			this->tabletToolStripMenuItem->Name = L"tabletToolStripMenuItem";
			this->tabletToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->tabletToolStripMenuItem->Text = L"Планшети";
			this->tabletToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::tabletToolStripMenuItem_Click);
			// 
			// eBookToolStripMenuItem
			// 
			this->eBookToolStripMenuItem->Name = L"eBookToolStripMenuItem";
			this->eBookToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->eBookToolStripMenuItem->Text = L"Електронні книги";
			this->eBookToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::eBookToolStripMenuItem_Click);
			// 
			// photoToolStripMenuItem
			// 
			this->photoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->photoCameraToolStripMenuItem,
					this->videocameraToolStripMenuItem
			});
			this->photoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"photoToolStripMenuItem.Image")));
			this->photoToolStripMenuItem->Name = L"photoToolStripMenuItem";
			this->photoToolStripMenuItem->Size = System::Drawing::Size(288, 22);
			this->photoToolStripMenuItem->Text = L"Фото та відео";
			// 
			// photoCameraToolStripMenuItem
			// 
			this->photoCameraToolStripMenuItem->Name = L"photoCameraToolStripMenuItem";
			this->photoCameraToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->photoCameraToolStripMenuItem->Text = L"Фотокамери";
			this->photoCameraToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::photoCameraToolStripMenuItem_Click);
			// 
			// videocameraToolStripMenuItem
			// 
			this->videocameraToolStripMenuItem->Name = L"videocameraToolStripMenuItem";
			this->videocameraToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->videocameraToolStripMenuItem->Text = L"Відеокамери";
			this->videocameraToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::videocameraToolStripMenuItem_Click);
			// 
			// shoppingCart
			// 
			this->shoppingCart->ForeColor = System::Drawing::Color::Black;
			this->shoppingCart->Name = L"shoppingCart";
			this->shoppingCart->Size = System::Drawing::Size(79, 22);
			this->shoppingCart->Text = L"Корзина";
			this->shoppingCart->Click += gcnew System::EventHandler(this, &MainForm::shoppingCart_Click);
			// 
			// Exit
			// 
			this->Exit->ForeColor = System::Drawing::Color::Black;
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(62, 22);
			this->Exit->Text = L"Вийти";
			this->Exit->Click += gcnew System::EventHandler(this, &MainForm::Exit_Click);
			// 
			// About
			// 
			this->About->ForeColor = System::Drawing::Color::Black;
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(121, 22);
			this->About->Text = L"Про програму";
			this->About->Click += gcnew System::EventHandler(this, &MainForm::About_Click);
			// 
			// oplataLabelHead
			// 
			this->oplataLabelHead->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->oplataLabelHead->AutoSize = true;
			this->oplataLabelHead->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->oplataLabelHead->Location = System::Drawing::Point(51, 703);
			this->oplataLabelHead->Name = L"oplataLabelHead";
			this->oplataLabelHead->Size = System::Drawing::Size(300, 33);
			this->oplataLabelHead->TabIndex = 7;
			this->oplataLabelHead->Text = L"Загальна сума до оплати:";
			this->oplataLabelHead->Visible = false;
			// 
			// oplataLabelControl
			// 
			this->oplataLabelControl->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->oplataLabelControl->AutoSize = true;
			this->oplataLabelControl->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->oplataLabelControl->Location = System::Drawing::Point(358, 703);
			this->oplataLabelControl->Name = L"oplataLabelControl";
			this->oplataLabelControl->Size = System::Drawing::Size(28, 33);
			this->oplataLabelControl->TabIndex = 8;
			this->oplataLabelControl->Text = L"0";
			this->oplataLabelControl->Visible = false;
			// 
			// inCartButton
			// 
			this->inCartButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->inCartButton->BackColor = System::Drawing::Color::Lime;
			this->inCartButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->inCartButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 21.75F));
			this->inCartButton->Location = System::Drawing::Point(418, 625);
			this->inCartButton->Name = L"inCartButton";
			this->inCartButton->Size = System::Drawing::Size(225, 58);
			this->inCartButton->TabIndex = 9;
			this->inCartButton->Text = L"В кошик";
			this->inCartButton->UseVisualStyleBackColor = false;
			this->inCartButton->Visible = false;
			this->inCartButton->Click += gcnew System::EventHandler(this, &MainForm::inCartButton_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeColumns = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			this->dataGridView->BackgroundColor = System::Drawing::Color::LightGreen;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dataGridView->Location = System::Drawing::Point(57, 81);
			this->dataGridView->MultiSelect = false;
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView->Size = System::Drawing::Size(948, 503);
			this->dataGridView->TabIndex = 1;
			this->dataGridView->TabStop = false;
			this->dataGridView->Visible = false;
			// 
			// buyButton
			// 
			this->buyButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->buyButton->BackColor = System::Drawing::Color::DarkGreen;
			this->buyButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->buyButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 21.75F));
			this->buyButton->Location = System::Drawing::Point(780, 612);
			this->buyButton->Name = L"buyButton";
			this->buyButton->Size = System::Drawing::Size(225, 58);
			this->buyButton->TabIndex = 10;
			this->buyButton->Text = L"Купити товари";
			this->buyButton->UseVisualStyleBackColor = false;
			this->buyButton->Visible = false;
			this->buyButton->Click += gcnew System::EventHandler(this, &MainForm::buyButton_Click);
			// 
			// deleteCartButton
			// 
			this->deleteCartButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->deleteCartButton->BackColor = System::Drawing::Color::GreenYellow;
			this->deleteCartButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->deleteCartButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 21.75F));
			this->deleteCartButton->Location = System::Drawing::Point(57, 612);
			this->deleteCartButton->Name = L"deleteCartButton";
			this->deleteCartButton->Size = System::Drawing::Size(225, 58);
			this->deleteCartButton->TabIndex = 11;
			this->deleteCartButton->Text = L"Видалити товар";
			this->deleteCartButton->UseVisualStyleBackColor = false;
			this->deleteCartButton->Visible = false;
			this->deleteCartButton->Click += gcnew System::EventHandler(this, &MainForm::deleteCartButton_Click);
			// 
			// clearAllButton
			// 
			this->clearAllButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->clearAllButton->BackColor = System::Drawing::Color::DarkOrange;
			this->clearAllButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->clearAllButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 21.75F));
			this->clearAllButton->Location = System::Drawing::Point(418, 612);
			this->clearAllButton->Name = L"clearAllButton";
			this->clearAllButton->Size = System::Drawing::Size(225, 58);
			this->clearAllButton->TabIndex = 12;
			this->clearAllButton->Text = L"Очистити корзину";
			this->clearAllButton->UseVisualStyleBackColor = false;
			this->clearAllButton->Visible = false;
			this->clearAllButton->Click += gcnew System::EventHandler(this, &MainForm::clearAllButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->ClientSize = System::Drawing::Size(1064, 761);
			this->Controls->Add(this->clearAllButton);
			this->Controls->Add(this->deleteCartButton);
			this->Controls->Add(this->buyButton);
			this->Controls->Add(this->inCartButton);
			this->Controls->Add(this->oplataLabelControl);
			this->Controls->Add(this->oplataLabelHead);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->logoMain);
			this->Controls->Add(this->titleLable);
			this->Controls->Add(this->menuStrip);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->MinimumSize = System::Drawing::Size(1080, 800);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Silex";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoMain))->EndInit();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: void changeVisible(bool value) {
		dataGridView->Visible = value;
		inCartButton->Visible = value;
		logoMain->Visible = !value;
		titleLable->Visible = !value;
		oplataLabelHead->Visible = false;
		oplataLabelControl->Visible = false;

		deleteCartButton->Visible = false;
		clearAllButton->Visible = false;
		buyButton->Visible = false;
	}

	private: void initDataGridView(std::string* arrColumn, int columnCount) {
		dataGridView -> Columns-> Clear();
		dataGridView -> Rows -> Clear();
		dataGridView -> ColumnCount = columnCount;
		
		for (int i = 0; i < columnCount; i++)
		{
			dataGridView->Columns[i]->Name = marshal_as<String^>(arrColumn[i]);
			dataGridView->Columns[i]->ReadOnly = true;
		}
		DataGridViewTextBoxColumn^ dataGridViewTextBox = gcnew DataGridViewTextBoxColumn();
		dataGridView->Columns->Add(dataGridViewTextBox);

		dataGridViewTextBox->HeaderText = "Кількість до покупки";
		
		dataGridViewTextBox->Name = "BuyAmount";

		dataGridViewTextBox->ReadOnly = false;
		
		dataGridViewTextBox->DefaultCellStyle->NullValue = "0";
	}
	/// <summary>
	/// main tool strip menu button visible changer
	/// </summary>

	private: System::Void inCartButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ShoppingCart shoppingCart;
		System::String^ tmp;
		System::String^ amount;
		System::String^ available;

		int size = dataGridView->RowCount;

		for (int i = 0; i < size; i++)
		{
			available = (System::String^)this->dataGridView->Rows[i]->Cells[1]->Value->ToString();
			amount = (System::String^)this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value->ToString();
			string tmpCheck = marshal_as<std::string>(amount);
			int tmpI = 0;
			bool onlyDigits = true;
			while (tmpCheck[tmpI] && onlyDigits)
			{
				if (isalpha(tmpCheck[tmpI]))
					onlyDigits = false;
				tmpI++;
			}
			if (onlyDigits) {
				if (stoi(marshal_as<std::string>(amount).c_str()) > 0 && stoi(marshal_as<std::string>(amount).c_str()) <= stoi(marshal_as<std::string>(available).c_str()))
				{
					tmp = (System::String^)this->dataGridView->Rows[i]->Cells[0]->Value->ToString() + " ";

					tmp += (System::String^)this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value->ToString() + " ";

					int update = stoi(marshal_as<std::string>(available).c_str()) - stoi(marshal_as<std::string>(amount).c_str());

					this->dataGridView->Rows[i]->Cells[1]->Value = marshal_as<String^>(to_string(update));

					this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";

					tmp += (System::String^)this->dataGridView->Rows[i]->Cells[2]->Value->ToString() + " ";
					tmp += (System::String^)this->dataGridView->Rows[i]->Cells[3]->Value->ToString() + " ";
					tmp += (System::String^)this->dataGridView->Rows[i]->Cells[4]->Value->ToString() + " ";
					shoppingCart.updateShoppingCartAdd(marshal_as<std::string>(tmp));
				}
				else {
					if (stoi(marshal_as<std::string>(amount).c_str()) != 0)
						this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "Помилка";
				}
			}
			else {
				this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "Помилка";
			}
		}
		MessageBox::Show("Вибрані товари куплено!", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void mainToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(false);
	}
	private: System::Void shoppingCart_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		inCartButton->Visible = false;
		oplataLabelHead->Visible = true;
		oplataLabelControl->Visible = true;

		deleteCartButton->Visible = true;
		clearAllButton->Visible = true;
		buyButton->Visible = true;
		std::string* arr = new std::string[6];

		arr[0] = "№";
		arr[1] = "ID";
		arr[2] = "Кількість";
		arr[3] = "Ціна";
		arr[4] = "Бренд";
		arr[5] = "Тип";

		dataGridView->Columns->Clear();
		dataGridView->Rows->Clear();
		dataGridView->ColumnCount = 6;

		for (int i = 0; i < 6; i++)
		{
			dataGridView->Columns[i]->Name = marshal_as<String^>(arr[i]);
			dataGridView->Columns[i]->ReadOnly = true;
		}

		delete[] arr;

		ShoppingCart shoppingCart;

		shoppingCart.viewShoppingCart(dataGridView, oplataLabelControl);
	}

	private: System::Void deleteCartButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ShoppingCart shoppingCart;

		shoppingCart.deleteProduct(this->dataGridView->CurrentRow->Index+1);
		
		shoppingCart_Click(sender, e);

		MessageBox::Show("Вибраний товар видалено!", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void clearAllButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ShoppingCart shoppingCart;

		shoppingCart.clearShoppingCart();
		shoppingCart_Click(sender, e);

		MessageBox::Show("Корзина очищена!", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void buyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ShoppingCart shoppingCart;

		shoppingCart.pay();
		shoppingCart.clearShoppingCart();
		shoppingCart_Click(sender, e);

		MessageBox::Show("Покупка здійснена!", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void About_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("©Михайло Щербан 2021", "Про програму", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	/// <summary>
	/// CATEGORY 1
	/// </summary>
	private: System::Void smartphoneToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[16];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";
		arr[5] = "ROM";
		arr[6] = "RAM";
		arr[7] = "Процесор";
		arr[8] = "ОС";
		arr[9] = "Діагональ екрану";
		arr[10] = "Тип екрану";
		arr[11] = "Основна камера";
		arr[12] = "Фронтальна камера";
		arr[13] = "Колір";
		arr[14] = "Ємність акумулятора";
		arr[15] = "Особливості";

		initDataGridView(arr, 16);

		delete[] arr;

		Smartphone smartphone;

		smartphone.viewProducts("SmartphonesList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void telephoneToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[5];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		initDataGridView(arr, 5);

		delete[] arr;

		Telephone telephone;

		telephone.viewProducts("TelephoneList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void coverToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[7];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";
		arr[5] = "Сумісність";
		arr[6] = "Колір";

		initDataGridView(arr, 7);

		delete[] arr;

		Cover cover;

		cover.viewProducts("CoverList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void headphonesToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[8];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Роз'єм";
		arr[6] = "Шумозаглушення";
		arr[7] = "Колір";

		initDataGridView(arr, 8);

		delete[] arr;

		Headphone headphone;

		headphone.viewProducts("HeadphoneList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void portableSpeakersToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[7];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Потужність";
		arr[6] = "Час роботи";

		initDataGridView(arr, 7);

		delete[] arr;

		PortableSpeakers portableSpeakers;

		portableSpeakers.viewProducts("PortableSpeakersList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void bluetoothToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[6];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Версія Bluetooth";

		initDataGridView(arr, 6);

		delete[] arr;

		BluetoothHeadset bluetoothHeadset;

		bluetoothHeadset.viewProducts("BluetoothHeadsetList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void memoryCardToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[7];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Об'єм";
		arr[6] = "Клас";

		initDataGridView(arr, 7);

		delete[] arr;

		MemoryCard memoryCard;

		memoryCard.viewProducts("MemoryCardList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void protectiveGlassToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[7];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Сумісність";
		arr[6] = "Тип покриття";


		initDataGridView(arr, 7);

		delete[] arr;

		ProtectiveGlass protectiveGlass;

		protectiveGlass.viewProducts("ProtectiveGlassList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void simCardToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[6];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "VIP";

		initDataGridView(arr, 6);

		delete[] arr;

		SIMCard simCard;

		simCard.viewProducts("SIMCardList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	/// <summary>
	/// CATEGORY 2
	/// </summary>
	private: System::Void laptopToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[16];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Діагональ екрану";
		arr[6] = "Тип матриці";
		arr[7] = "Роздільна здатність";
		arr[8] = "Серія процесора";
		arr[9] = "Кількість ядер";
		arr[10] = "Об'єм ОЗУ";
		arr[11] = "Відеокарта";
		arr[12] = "Об'єм пам'яті";
		arr[13] = "ОС";
		arr[14] = "Колір";
		arr[15] = "Вага";

		initDataGridView(arr, 16);

		delete[] arr;

		Laptop laptop;

		laptop.viewProducts("LaptopsList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void printerToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[8];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Технологія друку";
		arr[6] = "Формат паперу";
		arr[7] = "Колір друку";

		initDataGridView(arr, 8);

		delete[] arr;

		Printer printer;

		printer.viewProducts("PrintersList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void routerToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[8];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Призначення";
		arr[6] = "Частота Wi-Fi";
		arr[7] = "Макс. швидкість";

		initDataGridView(arr, 8);

		delete[] arr;

		Router router;

		router.viewProducts("RoutersList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void videocardToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[9];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Виробник чипа";
		arr[6] = "Серія";
		arr[7] = "Об. пам'яті";
		arr[8] = "Тип пам'яті";

		initDataGridView(arr, 9);

		delete[] arr;

		Videocard videocard;

		videocard.viewProducts("VideocardsList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void processorToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[9];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Серія";
		arr[6] = "Сокет";
		arr[7] = "Ядра";
		arr[8] = "Частота";

		initDataGridView(arr, 9);

		delete[] arr;

		Processor processor;

		processor.viewProducts("ProcessorsList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void motherboardToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[8];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Сокет";
		arr[6] = "Тип ОЗУ";
		arr[7] = "Форм-фактор";

		initDataGridView(arr, 8);

		delete[] arr;

		Motherboard motherboard;

		motherboard.viewProducts("MotherboardsList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void DDRToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[9];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Кількість модулів";
		arr[6] = "Ємність";
		arr[7] = "Частота";
		arr[8] = "Таймінги";

		initDataGridView(arr, 9);

		delete[] arr;

		DDR ddr;

		ddr.viewProducts("DDRsList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void storageToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[8];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Ємність";
		arr[6] = "Форм-фактор";
		arr[7] = "Інтерфейс";

		initDataGridView(arr, 8);

		delete[] arr;

		Storage storage;

		storage.viewProducts("StoragesList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void powerSuppliesToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[7];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Форм-фактор";
		arr[6] = "Потужність";

		initDataGridView(arr, 7);

		delete[] arr;

		PowerSupplies powerSupplies;

		powerSupplies.viewProducts("PowerSuppliesList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void pcAccessoriesToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		changeVisible(true);
		std::string* arr = new std::string[5];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		initDataGridView(arr, 5);

		delete[] arr;

		Accessories accessories;

		accessories.viewProducts("AccessoriesList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	/// <summary>
	/// CATEGORY 3
	/// </summary>
	private: System::Void tvToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[9];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Діагональ";
		arr[6] = "Роздільна здатність";
		arr[7] = "Технології";
		arr[8] = "ОС";

		initDataGridView(arr, 9);

		delete[] arr;

		Television television;

		television.viewProducts("TVsList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void mediaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[5];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		initDataGridView(arr, 5);

		delete[] arr;

		Multimedia multimedia;

		multimedia.viewProducts("MultimediasList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void projectorsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[7];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Роздільна здатність";
		arr[6] = "Інтерфейс";

		initDataGridView(arr, 7);

		delete[] arr;

		Projectors projectors;

		projectors.viewProducts("ProjectorsList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void tvAccessoriesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[5];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		initDataGridView(arr, 5);

		delete[] arr;

		TVAccessories tvAccessories;

		tvAccessories.viewProducts("TVAccessoriesList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	/// <summary>
	/// CATEGORY 4
	/// </summary>
	private: System::Void watchesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[10];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Призначення";
		arr[6] = "Форма дисплею";
		arr[7] = "Розмір дисплею";
		arr[8] = "Матеріал корпусу";
		arr[9] = "Час роботи";

		initDataGridView(arr, 10);

		delete[] arr;

		SmartWatches smartWatches;

		smartWatches.viewProducts("SmartWatchesList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void quadrocoptersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[9];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Камера";
		arr[6] = "Час польоту";
		arr[7] = "Максимальна відстань польоту";
		arr[8] = "Частота";

		initDataGridView(arr, 9);

		delete[] arr;

		Quadrocopter quadrocopter;

		quadrocopter.viewProducts("QuadrocoptersList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	
	private: System::Void printer3DToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[9];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Технологія друку";
		arr[6] = "Матеріал нитки";
		arr[7] = "Кількість сопел";
		arr[8] = "Макс. шв. друку";

		initDataGridView(arr, 9);

		delete[] arr;

		Printer3D printer3D;

		printer3D.viewProducts("Printer3DList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	/// <summary>
	/// CATEGORY 5
	/// </summary>
	private: System::Void tabletToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[16];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "ROM";
		arr[6] = "RAM";
		arr[7] = "Процесор";
		arr[8] = "ОС";
		arr[9] = "Діагональ екрану";
		arr[10] = "Тип екрану";
		arr[11] = "Основна камера";
		arr[12] = "Фронтальна камера";
		arr[13] = "Колір";
		arr[14] = "Ємність акумулятора";
		arr[15] = "Особливості";

		initDataGridView(arr, 16);

		delete[] arr;

		Tablet tablet;

		tablet.viewProducts("TabletsList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void eBookToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[13];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "ROM";
		arr[6] = "RAM";
		arr[7] = "Формати";
		arr[8] = "ОС";
		arr[9] = "Діагональ екрану";
		arr[10] = "Тип екрану";
		arr[11] = "Колір";
		arr[12] = "Ємність акумулятора";

		initDataGridView(arr, 13);

		delete[] arr;

		EBook eBook;

		eBook.viewProducts("EBooksList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
	/// <summary>
	/// CATEGORY 6
	/// </summary>
	private: System::Void photoCameraToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[10];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Роздільна здатність";
		arr[6] = "Розмір матриці";
		arr[7] = "Оптичний зум";
		arr[8] = "Тип живлення";
		arr[9] = "Колір";

		initDataGridView(arr, 10);

		delete[] arr;

		PhotoCamera photoCamera;

		photoCamera.viewProducts("PhotoCamerasList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}

	private: System::Void videocameraToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		changeVisible(true);
		std::string* arr = new std::string[13];
		arr[0] = "ID";
		arr[1] = "Наявність";
		arr[2] = "Ціна";
		arr[3] = "Бренд";
		arr[4] = "Тип";

		arr[5] = "Тип матриці";
		arr[6] = "Стабілізація";
		arr[7] = "Роздільна здатність";
		arr[8] = "Зум";
		arr[9] = "Сенсорний екран";
		arr[10] = "Аудіосистема";
		arr[11] = "Ємність акумулятора";
		arr[12] = "Колір";

		initDataGridView(arr, 13);

		delete[] arr;

		VideoCamera videoCamera;

		videoCamera.viewProducts("VideoCamerasList.txt", dataGridView);

		for (int i = 0; i < dataGridView->Rows->Count; i++)
		{
			this->dataGridView->Rows[i]->Cells["BuyAmount"]->Value = "0";
		}
	}
};
}

#include "MainWindow.h"

#define NotImplemented 0;

/// Constructors

MainWindow::MainWindow(){

    _mainFrame = new QGridLayout;

    _subMainFrame1 = new QVBoxLayout;
    _subMainFrame2 = new QVBoxLayout;

    _userDataMainGroup = new QGroupBox;
    _userDataMainLayout = new QGridLayout;

    _userDataOptionsGroup = new QGroupBox;
    _userDataOptionsLayout = new QGridLayout;

    _userDataDocGroup = new QGroupBox;
    _userDataDocLayout = new QGridLayout;

    _userDataMainForm  = new QFormLayout;
    _classNameEdit = new QLineEdit;
    _parentNameEdit = new QLineEdit;

    _headerIncCheckbox = new QCheckBox;
    _constructorCheckbox = new QCheckBox;
    _destructorCheckbox = new QCheckBox;

    _documentationForm = new QFormLayout;
    _authorEdit = new QLineEdit;
    _dateEdit = new QDateEdit;
    _roleEdit = new QTextEdit;

    _saveFileButton = new QPushButton;
    _saveIcon = new QIcon;

    _codeUpdateTimer = new QTimer;
    _codeBlockTab = new QTabWidget;
    _codeBlockFont = new QFont;

    _headerPage = new QWidget;
    _codeBlockLayoutHeader = new QVBoxLayout;
    _codeBlockHeader = new QTextEdit;
    _generatedCodeHeader = new QString;

    _cppPage = new QWidget;
    _codeBlockLayoutCpp = new QVBoxLayout;
    _codeBlockCpp = new QTextEdit;
    _generatedCodeCpp = new QString;

    Init_Attributes();

}

/// Destructors

MainWindow::~MainWindow(){

    // Frames
    if (_mainFrame != nullptr)
        delete _mainFrame; _mainFrame = nullptr;
    if (_subMainFrame1 != nullptr)
        delete _subMainFrame1; _subMainFrame1 = nullptr;
    if (_subMainFrame2 != nullptr)
        delete _subMainFrame2; _subMainFrame2 = nullptr;

    // User Data Areas
    if (_userDataMainGroup != nullptr)
        delete _userDataMainGroup; _userDataMainGroup = nullptr;
    if (_userDataMainLayout != nullptr)
        delete _userDataMainLayout; _userDataMainLayout = nullptr;

    if (_userDataOptionsGroup != nullptr)
        delete _userDataOptionsGroup; _userDataOptionsGroup = nullptr;
    if (_userDataOptionsLayout != nullptr)
        delete _userDataOptionsLayout; _userDataOptionsLayout = nullptr;

    if (_userDataDocGroup != nullptr)
        delete _userDataDocGroup; _userDataDocGroup = nullptr;
    if (_userDataDocLayout != nullptr)
        delete _userDataDocLayout; _userDataDocLayout = nullptr;

    // Main user datas
    if (_userDataMainForm != nullptr)
        delete _userDataMainForm; _userDataMainForm = nullptr;
    if (_classNameEdit != nullptr)
        delete _classNameEdit; _classNameEdit = nullptr;
    if (_parentNameEdit != nullptr)
        delete _parentNameEdit; _parentNameEdit = nullptr;

    // Options user datas
    if (_headerIncCheckbox != nullptr)
        delete _headerIncCheckbox; _headerIncCheckbox = nullptr;
    if (_constructorCheckbox != nullptr)
        delete _constructorCheckbox; _constructorCheckbox = nullptr;
    if (_destructorCheckbox != nullptr)
        delete _destructorCheckbox; _destructorCheckbox = nullptr;

    // Documentation user datas
    if (_documentationForm != nullptr)
        delete _documentationForm; _documentationForm = nullptr;
    if (_authorEdit != nullptr)
        delete _authorEdit; _authorEdit = nullptr;
    if (_dateEdit != nullptr)
        delete _dateEdit; _dateEdit = nullptr;
    if (_roleEdit != nullptr)
        delete _roleEdit; _roleEdit = nullptr;

    // Save button
    if (_saveFileButton != nullptr)
        delete _saveFileButton; _saveFileButton = nullptr;
    if (_saveIcon != nullptr)
        delete _saveIcon; _saveIcon = nullptr;

    // Generated code
    if (_codeUpdateTimer != nullptr)
        delete _codeUpdateTimer; _codeUpdateTimer = nullptr;
    if (_codeBlockTab != nullptr)
        delete _codeBlockTab; _codeBlockTab = nullptr;

        // header
    if (_headerPage != nullptr)
        delete _headerPage; _headerPage = nullptr;
    if (_codeBlockLayoutHeader != nullptr)
        delete _codeBlockLayoutHeader; _codeBlockLayoutHeader = nullptr;
    if (_codeBlockHeader != nullptr)
        delete _codeBlockHeader; _codeBlockHeader = nullptr;
    if (_generatedCodeHeader != nullptr)
        delete _generatedCodeHeader; _generatedCodeHeader = nullptr;

        // Cpp
    if (_cppPage != nullptr)
        delete _cppPage; _cppPage = nullptr;
    if (_codeBlockLayoutCpp != nullptr)
        delete _codeBlockLayoutCpp; _codeBlockLayoutCpp = nullptr;
    if (_codeBlockCpp != nullptr)
        delete _codeBlockCpp; _codeBlockCpp = nullptr;
    if (_generatedCodeCpp != nullptr)
        delete _generatedCodeCpp; _generatedCodeCpp = nullptr;

}

/// Initiators

void MainWindow::Init_Attributes(){

    Init_MainFrame();

    Init_SubMainFrames();

}


void MainWindow::Init_MainFrame(){
    _mainFrame->setParent(this);
    this->setLayout(_mainFrame);
    _mainFrame->addLayout(_subMainFrame1, 0, 0);
    _mainFrame->addLayout(_subMainFrame2, 0, 1);
}


void MainWindow::Init_SubMainFrames(){
    Init_SubMainFrame1();
    Init_SubMainFrame2();
}


void MainWindow::Init_SubMainFrame1(){
    _subMainFrame1->setParent(_mainFrame);
    _subMainFrame1->setObjectName("Sub Main Frame 1");

     Init_UserDataArea();
     Init_SaveFileButton();

    _subMainFrame1->addWidget(_userDataMainGroup);
    _subMainFrame1->addWidget(_userDataOptionsGroup);
    _subMainFrame1->addWidget(_userDataDocGroup);
    _subMainFrame1->addWidget(_saveFileButton);
}

void MainWindow::Init_SubMainFrame2(){
    _subMainFrame2->setParent(_mainFrame);
    _subMainFrame2->setObjectName("Sub Main Frame 2");

    Init_CodeBlockTab();

    _subMainFrame2->addWidget(_codeBlockTab);
}

void MainWindow::Init_UserDataArea(){
    Init_UserDataGroups();
    Init_UserDataLayouts();
}


void MainWindow::Init_UserDataGroups(){
    Init_UserDataMainGroup();
    Init_UserDataOptionsGroup();
    Init_UserDataDocGroup();
}

void MainWindow::Init_UserDataMainGroup(){
    _userDataMainGroup->setLayout(_userDataMainLayout);
    _userDataMainGroup->setTitle("Main informations");
}

void MainWindow::Init_UserDataOptionsGroup(){
    _userDataOptionsGroup->setLayout(_userDataOptionsLayout);
    _userDataOptionsGroup->setTitle("Header options");
}

void MainWindow::Init_UserDataDocGroup(){
    _userDataDocGroup->setLayout(_userDataDocLayout);
    _userDataDocGroup->setTitle("Documentation");
}


void MainWindow::Init_UserDataLayouts(){
    Init_UserDataMainLayout();
    Init_UserDataOptionsLayout();
    Init_UserDataDocLayout();
}

void MainWindow::Init_UserDataMainLayout(){
    _userDataMainLayout->setObjectName("UserDataMain Layout");

    Init_UserDataMainForm();

    _userDataMainLayout->addLayout(_userDataMainForm, 0, 0);
}

void MainWindow::Init_UserDataOptionsLayout(){
    _userDataOptionsLayout->setObjectName("UserDataOptions Layout");

    Init_HeaderIncCheckbox();
    Init_ConstructorCheckbox();
    Init_DestructorCheckbox();

    _userDataOptionsLayout->addWidget(_headerIncCheckbox);
    _userDataOptionsLayout->addWidget(_constructorCheckbox);
    _userDataOptionsLayout->addWidget(_destructorCheckbox);
}

void MainWindow::Init_UserDataDocLayout(){
    _userDataDocLayout->setObjectName("UserDataDoc Layout");

    Init_DocumentationForm();

    _userDataDocLayout->addLayout(_documentationForm, 0, 0);
}

void MainWindow::Init_UserDataMainForm(){
    _userDataMainForm->setObjectName("UserData Form");

    Init_ClassNameEdit();
    Init_ParentNameEdit();

    _userDataMainForm->addRow("Class name:", _classNameEdit);
    _userDataMainForm->addRow("Parent name (optional):", _parentNameEdit);
}


void MainWindow::Init_ClassNameEdit(){
    _classNameEdit->setObjectName("ClassName LineEdit");
}

void MainWindow::Init_ParentNameEdit(){
    _parentNameEdit->setObjectName("ParentName Edit");
}

void MainWindow::Init_HeaderIncCheckbox(){
    _headerIncCheckbox->setCheckState(Qt::Checked);
    _headerIncCheckbox->setText("Header single inclusion");
}

void MainWindow::Init_ConstructorCheckbox(){
    _constructorCheckbox->setCheckState(Qt::Checked);
    _constructorCheckbox->setText("Add a constructor");
}

void MainWindow::Init_DestructorCheckbox(){
    _destructorCheckbox->setCheckState(Qt::Unchecked);
    _destructorCheckbox->setText("Add a destructor");
}


void MainWindow::Init_DocumentationForm(){
    _documentationForm->setObjectName("Documentation form");

    Init_AuthorEdit();
    Init_DateEdit();
    Init_RoleEdit();

    _documentationForm->addRow("Author:", _authorEdit);
    _documentationForm->addRow("Date:", _dateEdit);
    _documentationForm->addRow("Class Role:", _roleEdit);
}

void MainWindow::Init_AuthorEdit(){
    _authorEdit->setObjectName("Author Edit");
}

void MainWindow::Init_DateEdit(){
    _dateEdit->setObjectName("Date Edit");
    _dateEdit->setDisplayFormat("dd/MM/yyyy");
    _dateEdit->setDate(QDate::currentDate());
}

void MainWindow::Init_RoleEdit(){
    _roleEdit->setObjectName("Role Edit");
    _roleEdit->setPlaceholderText("Describe your class here.");

}


void MainWindow::Init_SaveFileButton(){
    _saveFileButton->setObjectName("Save File Button");

    _saveFileButton->setText("Save as");
    *_saveIcon = QIcon("Icons/save.png");
    _saveFileButton->setIcon(*_saveIcon);

    this->connect(_saveFileButton, SIGNAL(clicked(bool)), this, SLOT(saveFiles()));
}


void MainWindow::Init_CodeBlockTab(){
    _codeBlockTab->setObjectName("Code Block Tab");

    Init_HeaderPage();
    Init_CppPage();
    Init_CodeUpdateTimer();
    Init_CodeBlockFont();

    _codeBlockTab->addTab(_headerPage, "Header");
    _codeBlockTab->addTab(_cppPage, "Cpp impl.");
}

void MainWindow::Init_CodeBlockFont(){
    _codeBlockFont->setFamily("Consolas");
}

void MainWindow::Init_CodeUpdateTimer(){
    // 100 ms periodic update
    _codeUpdateTimer->setParent(this);
    this->connect(_codeUpdateTimer, SIGNAL(timeout()), this, SLOT(updateCode()));
    _codeUpdateTimer->start(100);
}


void MainWindow::Init_HeaderPage(){
    _headerPage->setObjectName("Header Page");

    Init_CodeBlockLayoutHeader();

    _headerPage->setLayout(_codeBlockLayoutHeader);
}

void MainWindow::Init_CodeBlockLayoutHeader(){
    _codeBlockLayoutHeader->setObjectName("Code Block Layout Header");

    Init_CodeBlockHeader();

    _codeBlockLayoutHeader->addWidget(_codeBlockHeader, 0, 0);
}

void MainWindow::Init_CodeBlockHeader(){
    _codeBlockHeader->setObjectName("Code Block Header");

    _codeBlockHeader->setTextColor("#efefef");

    QPalette p = _codeBlockHeader->palette();
    p.setColor(QPalette::Base, "#2d2d2d");
    _codeBlockHeader->setPalette(p);
}


void MainWindow::Init_CppPage(){
    _cppPage->setObjectName("Cpp Page");

    Init_CodeBlockLayoutCpp();

    _cppPage->setLayout(_codeBlockLayoutCpp);
}

void MainWindow::Init_CodeBlockLayoutCpp(){
    _codeBlockLayoutCpp->setObjectName("Code Block Layout Cpp");

    Init_CodeBlockCpp();

    _codeBlockLayoutCpp->addWidget(_codeBlockCpp, 0, 0);
}

void MainWindow::Init_CodeBlockCpp(){
    _codeBlockCpp->setObjectName("Code Block Cpp");

    _codeBlockCpp->setTextColor("#efefef");

    QPalette p = _codeBlockCpp->palette();
    p.setColor(QPalette::Base, "#2d2d2d");
    _codeBlockCpp->setPalette(p);
}

/// Methods

void MainWindow::updateCode(){
    if (_classNameEdit->text() != ""){ // Primary condition
        updateCodeHeader();
        updateCodeCpp();
    }
}

void MainWindow::updateCodeHeader(){
    // Header
    *_generatedCodeHeader = "";

    // Documentation
    *_generatedCodeHeader += "/*\n   " + (_authorEdit->text() != "" ? ("Author: " + _authorEdit->text() + "\n   ") : "") +
        ("date: " + _dateEdit->date().toString()) +
        (_roleEdit->toPlainText() != "" ? ("\n   " + _roleEdit->toPlainText() + "\n */\n\n") : "\n */\n\n");

    // Header Inclusion Start
    if (_headerIncCheckbox->isChecked()) {
        *_generatedCodeHeader += ("#ifndef " + _classNameEdit->text().toUpper()) +
            ("_H_INCLUDED\n#define " + _classNameEdit->text().toUpper()) +
            ("_H_INCLUDED\n\n");
    }

    // Class start
    *_generatedCodeHeader += "class " + _classNameEdit->text() +
            (_parentNameEdit->text() != "" ? (" : public " + _parentNameEdit->text() + " ") : " ") +
            ("{\n\n");

    // Constructor
    *_generatedCodeHeader += "    public:\n";

    if (_constructorCheckbox->isChecked()) {
        *_generatedCodeHeader += "    " + _classNameEdit->text() + "();\n";
    }

    // Destructor
    if (_destructorCheckbox->isChecked()) {
        *_generatedCodeHeader += "    ~" + _classNameEdit->text() + "();\n";
    }

    *_generatedCodeHeader += "\n";

    // Class end
    *_generatedCodeHeader += "    protected:\n\n    private:\n\n};\n\n";

    // Header Inclusion End
    if (_headerIncCheckbox->isChecked())
        *_generatedCodeHeader += "#endif";

    _codeBlockHeader->setText(*_generatedCodeHeader);
}

void MainWindow::updateCodeCpp(){

    QString classname = _classNameEdit->text();

    *_generatedCodeCpp = ""; // reset

    *_generatedCodeCpp += "#include \"" +classname + ".h\"\n\n";

    if (_constructorCheckbox->isChecked()){
        *_generatedCodeCpp += classname + "::" + classname + "() {\n\n}\n\n";
    }

    if (_destructorCheckbox->isChecked()){
        *_generatedCodeCpp += classname + "::~" + classname + "() {\n\n}\n\n";
    }

    _codeBlockCpp->setText(*_generatedCodeCpp);
}

void MainWindow::saveFiles(){
    if (_classNameEdit->text() != ""){
        QString folderPath = QFileDialog::getExistingDirectory(this);
        QString filenameh   = _classNameEdit->text() + ".h";
        QString filenamecpp = _classNameEdit->text() + ".cpp";

        std::ofstream fileh;
        fileh.open((folderPath + "/" + filenameh).toStdString(), std::ofstream::app);
        std::ofstream filecpp;
        filecpp.open((folderPath + "/" + filenamecpp).toStdString(), std::ofstream::app);

        if (fileh && filecpp){
            fileh << _generatedCodeHeader->toStdString();
            filecpp << _generatedCodeCpp->toStdString();

            fileh.close();
            filecpp.close();

            QMessageBox::information(this, "Save success", "Your files have been successfully created");
        } else {
            QMessageBox::critical(this, "Unexpected error", "Sorry, there have been an error during the file saving process. Try again.");
        }
    } else {
        QMessageBox::critical(this, "Save error", "You didn't give any classname.");
    }
}

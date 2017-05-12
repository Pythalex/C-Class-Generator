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

    _codeUpdateTimer = new QTimer;
    _codeBlockGroup = new QGroupBox;
    _codeBlockLayout = new QVBoxLayout;
    _codeBlock = new QTextEdit;
    _codeBlockFont = new QFont;
    _generatedCode = new QString;

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

    // Generated code
    if (_codeUpdateTimer != nullptr)
        delete _codeUpdateTimer; _codeUpdateTimer = nullptr;
    if (_codeBlockGroup != nullptr)
        delete _codeBlockGroup; _codeBlockGroup = nullptr;
    if (_codeBlockLayout != nullptr)
        delete _codeBlockLayout; _codeBlockLayout = nullptr;
    if (_codeBlock != nullptr)
        delete _codeBlock; _codeBlock = nullptr;
    if (_generatedCode != nullptr)
        delete _generatedCode; _generatedCode = nullptr;

}

/// Initiators

void MainWindow::Init_Attributes(){

    Init_MainFrame();

    Init_SubMainFrames();

    Init_UserDataArea();
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

    _subMainFrame1->addWidget(_userDataMainGroup);
    _subMainFrame1->addWidget(_userDataOptionsGroup);
    _subMainFrame1->addWidget(_userDataDocGroup);
}

void MainWindow::Init_SubMainFrame2(){
    _subMainFrame2->setParent(_mainFrame);
    _subMainFrame2->setObjectName("Sub Main Frame 2");

    Init_CodeBlockGroup();

    _subMainFrame2->addWidget(_codeBlockGroup);
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


void MainWindow::Init_CodeBlockGroup(){
    _codeBlockGroup->setObjectName("Code Block Group");
    _codeBlockGroup->setTitle("Code");

    Init_CodeBlockLayout();

    _codeBlockGroup->setLayout(_codeBlockLayout);
}

void MainWindow::Init_CodeBlockLayout(){
    _codeBlockLayout->setObjectName("Code Block Layout");

    Init_CodeBlock();
    Init_CodeUpdateTimer();
    Init_CodeBlockFont();

    _codeBlockLayout->addWidget(_codeBlock, 0, 0);
}

void MainWindow::Init_CodeBlock(){
    _codeBlock->setObjectName("Code Block");
    _codeBlock->setTextColor("#efefef");
    QPalette p = _codeBlock->palette();
    p.setColor(QPalette::Base, "#2d2d2d");
    _codeBlock->setPalette(p);
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

/// Methods

void MainWindow::updateCode(){
    *_generatedCode = "";

    if (_classNameEdit->text() != ""){ // Primary condition

        // Documentation
        *_generatedCode += "/*\n   " + (_authorEdit->text() != "" ? ("Author: " + _authorEdit->text() + "\n   ") : "") +
            ("date: " + _dateEdit->date().toString()) +
            (_roleEdit->toPlainText() != "" ? ("\n   " + _roleEdit->toPlainText() + "\n */\n\n") : "\n */\n\n");

        // Header Inclusion Start
        if (_headerIncCheckbox->isChecked()) {
            *_generatedCode += ("#ifndef  " + _classNameEdit->text().toUpper()) +
                ("_H_INCLUDED\n#define " + _classNameEdit->text().toUpper()) +
                ("_H_INCLUDED\n\n");
        }

        // Class start
        *_generatedCode += "class " + _classNameEdit->text() +
                (_parentNameEdit->text() != "" ? (" : public " + _parentNameEdit->text() + " ") : " ") +
                ("{\n\n");

        // Constructor
        *_generatedCode += "    public:\n";

        if (_constructorCheckbox->isChecked()) {
            *_generatedCode += "    " + _classNameEdit->text() + "();\n";
        }

        // Destructor
        if (_destructorCheckbox->isChecked()) {
            *_generatedCode += "    ~" + _classNameEdit->text() + "();\n";
        }

        *_generatedCode += "\n";

        // Class end
        *_generatedCode += "    protected:\n\n    private:\n\n}\n\n";

        // Header Inclusion End
        if (_headerIncCheckbox->isChecked())
            *_generatedCode += "#endif";

    }

    _codeBlock->setText(*_generatedCode);
}

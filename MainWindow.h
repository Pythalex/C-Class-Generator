#ifndef MAIN_WINDOW_H_INCLUDED
#define MAIN_WINDOW_H_INCLUDED

#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QGroupBox>
#include <QCheckBox>
#include <QTimer>
#include <QDebug>
#include <QDate>
#include <QDateEdit>
#include <QColor>
#include <QPalette>

class MainWindow : public QWidget{

    Q_OBJECT

    public:
    MainWindow();
    ~MainWindow();

    protected:

    private slots:
    void updateCode();

    private:

    /// Initiators

    void Init_Attributes();

    void Init_MainFrame();

    void Init_SubMainFrames();

    void Init_SubMainFrame1();
    void Init_SubMainFrame2();

    void Init_UserDataArea();

    void Init_UserDataGroups();
    void Init_UserDataMainGroup();
    void Init_UserDataOptionsGroup();
    void Init_UserDataDocGroup();

    void Init_UserDataLayouts();
    void Init_UserDataMainLayout();
    void Init_UserDataOptionsLayout();
    void Init_UserDataDocLayout();

    void Init_UserDataMainForm();
    void Init_ClassNameEdit();
    void Init_ParentNameEdit();

    void Init_HeaderIncCheckbox();
    void Init_ConstructorCheckbox();
    void Init_DestructorCheckbox();

    void Init_DocumentationForm();
    void Init_AuthorEdit();
    void Init_DateEdit();
    void Init_RoleEdit();

    void Init_CodeBlockGroup();
    void Init_CodeBlockLayout();
    void Init_CodeUpdateTimer();
    void Init_CodeBlockFont();
    void Init_CodeBlock();


    /// Attributes

    // Frames
    QGridLayout* _mainFrame;

    QVBoxLayout* _subMainFrame1; // user data frame
    QVBoxLayout*  _subMainFrame2; // generated code display frame

    // User Data
    QGroupBox*   _userDataMainGroup;
    QGridLayout* _userDataMainLayout;

    QGroupBox*   _userDataOptionsGroup;
    QGridLayout* _userDataOptionsLayout;

    QGroupBox*   _userDataDocGroup;
    QGridLayout* _userDataDocLayout;

    // user Data Main
    QFormLayout* _userDataMainForm;
    QLineEdit*   _classNameEdit;
    QLineEdit*   _parentNameEdit;

    // user Data Options
    QCheckBox*   _headerIncCheckbox;
    QCheckBox*   _constructorCheckbox;
    QCheckBox*   _destructorCheckbox;

    // user Data Documentation
    QFormLayout* _documentationForm;
    QLineEdit*   _authorEdit;
    QDateEdit*   _dateEdit;
    QTextEdit*   _roleEdit;

    // Generated code
    QTimer*      _codeUpdateTimer;
    QGroupBox*   _codeBlockGroup;
    QVBoxLayout* _codeBlockLayout;
    QTextEdit*   _codeBlock;
    QFont*       _codeBlockFont;
    QString*     _generatedCode;
};

#endif

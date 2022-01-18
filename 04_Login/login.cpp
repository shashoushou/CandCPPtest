#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setMinimumSize(280,150);
    setMaximumSize(280,150);

    usrLabel = new QLabel(tr("name:     "));
    pwdLabel = new QLabel(tr("password: "));
    usrLineEdit = new QLineEdit;
    pwdLineEdit = new QLineEdit;
    pwdLineEdit->setEchoMode((QLineEdit::Password));
    usrLineEdit->setMaxLength(12);
    pwdLineEdit->setMaxLength(12);
    gridlayout = new QGridLayout;
    gridlayout->addWidget(usrLabel, 0, 0, 1, 1);
    gridlayout->addWidget(usrLineEdit, 0, 1, 1, 1);
    gridlayout->setSpacing(20);
    gridlayout->addWidget(pwdLabel, 1, 0, 1, 1);
    gridlayout->addWidget(pwdLineEdit, 1, 1, 1, 1);

    okBtn = new QPushButton(tr("Ok"));
    cancelBtn = new QPushButton(tr("Cancel"));
    connect(okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
    QHBoxLayout *hboxLayout = new QHBoxLayout;
    hboxLayout->setSpacing(60);
    hboxLayout->addWidget(okBtn);
    hboxLayout->addWidget(cancelBtn);

    vboxLayout = new QVBoxLayout;
    vboxLayout->addLayout(gridlayout);
    vboxLayout->addLayout(hboxLayout);
    this->setLayout(vboxLayout);
}

Login::~Login()
{
    delete ui;
}

void Login::accept()
{
    if(usrLineEdit->text().trimmed()=="admin" && pwdLineEdit->text().trimmed()=="admin")
    {
        Login::accept();

    } else {
        QMessageBox::warning(this, "warn!", "user name or password is wrong!", QMessageBox::Yes);
        usrLineEdit->setFocus();
    }
}


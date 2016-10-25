#include <QtWidgets>
#include "vnewfiledialog.h"

VNewFileDialog::VNewFileDialog(const QString &title, const QString &name, const QString &defaultName,
                             QWidget *parent)
    : QDialog(parent), title(title), name(name), defaultName(defaultName)
{
    setupUI();

    connect(nameEdit, &QLineEdit::textChanged, this, &VNewFileDialog::enableOkButton);
    connect(okBtn, &QPushButton::clicked, this, &VNewFileDialog::accept);
    connect(cancelBtn, &QPushButton::clicked, this, &VNewFileDialog::reject);
}

void VNewFileDialog::setupUI()
{
    nameLabel = new QLabel(name);
    nameEdit = new QLineEdit(defaultName);
    nameEdit->selectAll();
    nameLabel->setBuddy(nameEdit);

    okBtn = new QPushButton(tr("&OK"));
    okBtn->setDefault(true);
    cancelBtn = new QPushButton(tr("&Cancel"));

    QVBoxLayout *topLayout = new QVBoxLayout();
    topLayout->addWidget(nameLabel);
    topLayout->addWidget(nameEdit);

    QHBoxLayout *btmLayout = new QHBoxLayout();
    btmLayout->addStretch();
    btmLayout->addWidget(okBtn);
    btmLayout->addWidget(cancelBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(btmLayout);
    setLayout(mainLayout);

    setWindowTitle(title);
}

void VNewFileDialog::enableOkButton(const QString &editText)
{
    okBtn->setEnabled(!editText.isEmpty());
}

QString VNewFileDialog::getNameInput() const
{
    return nameEdit->text();
}

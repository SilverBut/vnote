#ifndef VNEWDIRDIALOG_H
#define VNEWDIRDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;
class QString;

class VNewDirDialog : public QDialog
{
    Q_OBJECT
public:
    VNewDirDialog(const QString &title, const QString &name,
                  const QString &defaultName, QWidget *parent = 0);
    QString getNameInput() const;

private slots:
    void enableOkButton(const QString &editText);

private:
    void setupUI();

    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    QString title;
    QString name;
    QString defaultName;
};

#endif // VNEWDIRDIALOG_H

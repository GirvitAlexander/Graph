#ifndef ADDGRAPHDIALOG_H
#define ADDGRAPHDIALOG_H

#include <QDialog>

namespace Ui {
class AddGraphDialog;
}

class AddGraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGraphDialog(QWidget *parent = nullptr);
    ~AddGraphDialog();

private:
    Ui::AddGraphDialog *ui;
};

#endif // ADDGRAPHDIALOG_H

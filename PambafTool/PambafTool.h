#ifndef PAMBAFTOOL_H
#define PAMBAFTOOL_H

#include <QMainWindow>

namespace Ui {
class PambafTool;
}

class PambafTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit PambafTool(QWidget *parent = 0);
    ~PambafTool();

private slots:
    void on_button_createKey_create_clicked();

    void on_button_encrypt_encrypt_clicked();

    void on_button_decrypt_decrypt_clicked();

private:
    Ui::PambafTool *ui;
};

#endif // PAMBAFTOOL_H

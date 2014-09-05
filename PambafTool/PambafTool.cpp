#include "PambafTool.h"
#include "ui_PambafTool.h"
#include "PambafLib.h"

PambafTool::PambafTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PambafTool)
{
    ui->setupUi(this);
    ui->label_about_about->setText(QString("PambafTool - The official tool of the Pambaf encryption\nVersion: %1\nCopyright (c) 2014 mh\nThis content is released under the MIT License. (See 'LICENSE' for further information.)").arg(PambafLib::getVersion()));
}

PambafTool::~PambafTool()
{
    delete ui;
}

void PambafTool::on_button_createKey_create_clicked()
{
    ui->label_createKey_key->setText(PambafLib::generateKey(ui->text_createKey_keyLength->text().toInt()));
}

void PambafTool::on_button_encrypt_encrypt_clicked()
{
    ui->label_encrypt_encryptedMessage->setText(PambafLib::encrypt(ui->text_encrypt_message->toPlainText().toUtf8().constData(), ui->text_encrypt_key->text().toUtf8().constData()));
}

void PambafTool::on_button_decrypt_decrypt_clicked()
{
    ui->label_decrypt_message->setText(PambafLib::decrypt(ui->text_decrypt_encryptedMessage->toPlainText().toUtf8().constData(), ui->text_decrypt_key->text().toUtf8().constData()));
}

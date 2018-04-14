/*******************************************************************************
 * Copyright [2018] <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     0.1
 * author:      zhaonanlin
 * brief:       警告提示框
*******************************************************************************/
#ifndef BOXMSG_H
#define BOXMSG_H

#include <QFile>
#include <QIcon>
#include <QLabel>
#include <QVariant>
#include <QGridLayout>
#include <QMessageBox>
#include <QApplication>
#include <QDialogButtonBox>

class BoxMsg : public QDialog
{
    Q_OBJECT

public:
    explicit BoxMsg(QWidget  *parent = 0, const QString &title = tr("Tip"),
                    const QString &text = "",
                    QMessageBox::StandardButtons buttons = QMessageBox::Ok,
                    QMessageBox::StandardButton defaultButton = QMessageBox::Ok);
    ~BoxMsg();
private slots:
    void initSkin();
    void onButtonClicked(QAbstractButton *button);
private:
    QDialogButtonBox *buttonBox;
    QLabel *textLabel;
};

#endif // BOXMSG_H

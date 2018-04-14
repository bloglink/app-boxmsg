/*******************************************************************************
 * Copyright [2018] <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     0.1
 * author:      zhaonanlin
 * brief:       警告提示框
*******************************************************************************/
#include "boxmsg.h"

BoxMsg::BoxMsg(QWidget *parent, const QString &title, const QString &text,
               QMessageBox::StandardButtons buttons,
               QMessageBox::StandardButton defaultButton)
    : QDialog(parent, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint)
{
    initSkin();
    this->setWindowTitle(title);
    this->setMinimumSize(400, 120);
    this->setStyleSheet("QDialog{border:2px solid gray;}");

    QLabel *iconLabel = new QLabel(this);
    iconLabel->setPixmap(QPixmap(":/logo_aip.png"));
    iconLabel->setFixedSize(113, 57);
    iconLabel->setScaledContents(true);

    QVBoxLayout *iconLayout = new QVBoxLayout;
    iconLayout->addWidget(iconLabel);
    iconLayout->addStretch();

    textLabel = new QLabel(this);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet("font:15pt");
    textLabel->setWordWrap(true);
    textLabel->setText(text);

    buttonBox = new QDialogButtonBox(this);
    buttonBox->setStandardButtons(QDialogButtonBox::StandardButtons(int(buttons)) |
                                  QDialogButtonBox::StandardButtons(int(defaultButton)));

    QVBoxLayout *textLayout = new QVBoxLayout;
    textLayout->addWidget(textLabel);
    textLayout->addWidget(buttonBox);
    textLayout->setStretch(0, 1);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addLayout(iconLayout);
    layout->addLayout(textLayout);

    connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), this,
            SLOT(onButtonClicked(QAbstractButton*)));
}

BoxMsg::~BoxMsg()
{
}

void BoxMsg::initSkin()
{
    QFile file;
    QString qss;
    file.setFileName(":/qss_black.css");
    file.open(QFile::ReadOnly);
    qss = QLatin1String(file.readAll());
    qApp->setStyleSheet(qss);
}

void BoxMsg::onButtonClicked(QAbstractButton *button)
{
    if (!buttonBox->buttons().contains(button))
        return;
    done(buttonBox->standardButton(button));
}

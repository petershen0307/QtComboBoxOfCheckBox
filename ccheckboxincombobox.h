#ifndef CCHECKBOXINCOMBOBOX_H
#define CCHECKBOXINCOMBOBOX_H

#include <QtGui/QDialog>
#include "ui_ccheckboxincombobox.h"
#include <QStandardItemModel>

class QComboBox;

class CCheckBoxInComboBox : public QDialog
{
    Q_OBJECT

public:
    CCheckBoxInComboBox(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~CCheckBoxInComboBox();

protected:
    virtual bool eventFilter(QObject* pObject, QEvent* pEvent);

private slots:
    void OnComboBoxCurrentIndexChanged(int index);
    void OnModelItemChanged(QStandardItem* pItem);

private:
    Ui::CCheckBoxInComboBoxClass ui;
    QStandardItemModel m_model;
    QComboBox* m_pComboBox;
};

#endif // CCHECKBOXINCOMBOBOX_H

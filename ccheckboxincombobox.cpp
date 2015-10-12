#include "ccheckboxincombobox.h"
#include <QComboBox>
#include <QListView>
#include <QTableView>
#include <QVBoxLayout>
#include <QMouseEvent>

CCheckBoxInComboBox::CCheckBoxInComboBox(QWidget *parent, Qt::WFlags flags)
    : QDialog(parent, flags)
    , m_model(3, 1)
    , m_pComboBox(new QComboBox())
{
    ui.setupUi(this);
    for (int r = 0; r < 3; ++r)
    {
        QStandardItem* item = new QStandardItem(QString("Item %0").arg(r));

        item->setFlags(/*Qt::ItemIsSelectable | */Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        item->setData(Qt::Unchecked, Qt::CheckStateRole);

        m_model.setItem(r, 0, item);
    }

//    QComboBox* combo = new QComboBox();
    m_pComboBox->setModel(&m_model);
    //combo->installEventFilter(this);
    m_pComboBox->view()->viewport()->installEventFilter(this);

    QListView* list = new QListView();
    list->setModel(&m_model);

    QTableView* table = new QTableView();
    table->setModel(&m_model);

    QVBoxLayout* containerLayout = new QVBoxLayout();
    containerLayout->addWidget(m_pComboBox);
    containerLayout->addWidget(list);
    containerLayout->addWidget(table);
    setLayout(containerLayout);


//    connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(OnComboBoxCurrentIndexChanged(int)));
    connect(m_pComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnComboBoxCurrentIndexChanged(int)));
    connect(&m_model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(OnModelItemChanged(QStandardItem*)));
}

CCheckBoxInComboBox::~CCheckBoxInComboBox()
{

}

bool CCheckBoxInComboBox::eventFilter(QObject* pObject, QEvent* pEvent)
{
//    QComboBox* pComboBox = qobject_cast<QComboBox*>(pObject);
    switch (pEvent->type())
    {
        case QEvent::MouseButtonDblClick:
        {
            QMouseEvent *m = static_cast<QMouseEvent *>(pEvent);
//            if (isVisible() && pComboBox->view()->rect().contains(m->pos()) && pComboBox->view()->currentIndex().isValid())
            if (isVisible() && m_pComboBox->view()->rect().contains(m->pos()) && m_pComboBox->view()->currentIndex().isValid())
            {
//                 pComboBox->hidePopup();
//                 pComboBox->setCurrentIndex(pComboBox->view()->currentIndex().row());
                m_pComboBox->hidePopup();
                m_pComboBox->setCurrentIndex(m_pComboBox->view()->currentIndex().row());
                return true;
            }
            return false;
        }
    }
    return QObject::eventFilter(pObject, pEvent);
}

void CCheckBoxInComboBox::OnComboBoxCurrentIndexChanged(int index)
{
    Q_UNUSED(index);
}

void CCheckBoxInComboBox::OnModelItemChanged(QStandardItem* pItem)
{
    Q_UNUSED(pItem);
}

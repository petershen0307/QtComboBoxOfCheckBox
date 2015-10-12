#include "ccheckboxincombobox.h"
#include <QtGui/QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    CCheckBoxInComboBox view;
    view.show();

    return app.exec();
}

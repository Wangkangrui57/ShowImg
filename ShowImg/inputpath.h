#ifndef INPUTPATH_H
#define INPUTPATH_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QFileInfo>
#include <QImage>
#include "showimg.h"

class InPutPath : public QDialog
{
    Q_OBJECT
public:
    InPutPath(QWidget *parent = 0);

public slots:
    void slot_open_file();
    void slot_browse_file();

private:
    QLabel *Label;
    QLineEdit *InPut;
    QPushButton *ConfirmButton;
    QPushButton *BrowseButton;
};

#endif

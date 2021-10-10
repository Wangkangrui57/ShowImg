#ifndef SHOWIMG_H
#define SHOWIMG_H

#include <stdio.h>
#include <QString>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QDir>
#include <QStringList>
#include <QListWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSize>

class QStringList;
class QListWidget;
class QListWidgetItem;

namespace Ui {
class ShowImg;
}

class ShowImg : public QWidget
{
    Q_OBJECT

public:
    ShowImg(QWidget *parent = 0);
    ~ShowImg();
    void getPath(QString String);
    void init();

private:

private slots:
    void slot_item_clicked(QListWidgetItem*);
    void slot_item_enlarge();
    void slot_item_shrink();

private:
    QStringList ImgList;
    QListWidget *ListWidget;
    QString DirPath;
    QLabel ShowWidget;
    QPushButton *EnlargeItem;
    QPushButton *ShrinkItem;
};

#endif // SHOWIMG_H

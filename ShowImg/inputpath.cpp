#include "inputpath.h"
#include "showimg.h"
InPutPath::InPutPath(QWidget *parent) : QDialog(parent)
{
    //控件基本设置
    Label=new QLabel(this);
    Label->setText(tr("请输入目标路径"));
    InPut=new QLineEdit(this);
    ConfirmButton=new QPushButton(this);
    ConfirmButton->setText(tr("确认"));
    BrowseButton=new QPushButton(this);
    BrowseButton->setText(tr("浏览.."));

    //布局设置
    QGridLayout *MainLayout=new QGridLayout(this);
    MainLayout->addWidget(Label,0,0);
    MainLayout->addWidget(InPut,0,1);
    MainLayout->addWidget(BrowseButton,1,0);
    MainLayout->addWidget(ConfirmButton,1,1);

    //信号与槽
    connect(ConfirmButton,SIGNAL(clicked(bool)),this,SLOT(slot_open_file()));
    connect(BrowseButton,SIGNAL(clicked(bool)),this,SLOT(slot_browse_file()));
}

void InPutPath::slot_open_file(){
    ShowImg *wShowImg=new ShowImg();
    wShowImg->getPath(InPut->text());
    wShowImg->init();
    wShowImg->show();
}

void InPutPath::slot_browse_file(){
    QString OpenFile;
    QString OpenFilePath;
    QFileInfo OpenFileInfo;
    OpenFile=QFileDialog::getExistingDirectory(this,
                                        "请选择文件夹",
                                        "./");
    OpenFileInfo=QFileInfo(OpenFile);
    OpenFilePath=OpenFileInfo.filePath();
    InPut->setText(OpenFilePath);
}

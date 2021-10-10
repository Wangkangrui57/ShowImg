#include "showimg.h"
#include "inputpath.h"

 QSize IMAGE_SIZE(240,160);
 //QSize ITEM_SIZE(240,160);
static int ImgWidth;
static int ImgHeight;
//static int ItemWidth;
//static int ItemHeight;

ShowImg::ShowImg(QWidget *parent) :
    QWidget(parent)
{
    //this->init();
}

ShowImg::~ShowImg()
{
}

void ShowImg::init(){
    //缩略图尺寸初始化
    ImgWidth=240;
    ImgHeight=160;
    //ItemWidth=240;
    //ItemHeight=160;

    this->setWindowTitle("ImagePreview");
    this->setMinimumSize(780,600);
    ShowWidget.setWindowTitle("ShowImg");
    ShowWidget.setAlignment(Qt::AlignCenter);

    //按输入路径显示图片列表并判断路径是否正确
    QDir Dir(DirPath);
    if(!Dir.exists()){
        //显示路径错误
    }

    //读取要求格式图片
    Dir.setFilter(QDir::Files|QDir::NoSymLinks);
    QStringList Filters;
    Filters<<"*.png"<<"*.jpg";
    Dir.setNameFilters(Filters);
    ImgList=Dir.entryList();
    if(ImgList.count()<=0){
        return;
    }

    //图片列表窗口设置
    ListWidget=new QListWidget(this);
    ListWidget->setIconSize(IMAGE_SIZE);
    ListWidget->setResizeMode(QListView::Adjust);
    ListWidget->setViewMode(QListView::IconMode);
    ListWidget->setMovement(QListView::Static);
    ListWidget->setSpacing(8);

    //列表窗口中单元设置
    for(int i=0;i<ImgList.count();i++){
        QPixmap Pixmap(DirPath+"//"+ImgList.at(i));
        QListWidgetItem *ListWidgetItem=new QListWidgetItem(QIcon(Pixmap.scaled(IMAGE_SIZE)),ImgList.at(i));
        //ListWidgetItem->setSizeHint(ITEM_SIZE);
        ListWidget->insertItem(i,ListWidgetItem);
    }

    //放大缩小按钮布局
    EnlargeItem=new QPushButton(this);
    ShrinkItem=new QPushButton(this);
    EnlargeItem->setText("+");
    ShrinkItem->setText("-");
    EnlargeItem->setFixedSize(50,30);
    ShrinkItem->setFixedSize(50,30);
    QHBoxLayout *ButtonLayout=new QHBoxLayout;
    ButtonLayout->addStretch();
    ButtonLayout->addWidget(EnlargeItem);
    ButtonLayout->addWidget(ShrinkItem);

    //主窗口布局
    QVBoxLayout *MainLayout=new QVBoxLayout;
    MainLayout->addLayout(ButtonLayout);
    MainLayout->addWidget(ListWidget);
    MainLayout->setMargin(0);
    this->setLayout(MainLayout);

    //信号与槽
    connect(ListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slot_item_clicked(QListWidgetItem*)));
    connect(EnlargeItem,SIGNAL(clicked(bool)),this,SLOT(slot_item_enlarge()));
    connect(ShrinkItem,SIGNAL(clicked(bool)),this,SLOT(slot_item_shrink()));
}

//显示图像SLOT
void ShowImg::slot_item_clicked(QListWidgetItem * item){
    QPixmap pixmap(DirPath+"//"+ImgList.at(ListWidget->row(item)));
    ShowWidget.setScaledContents(true);
    ShowWidget.setPixmap(pixmap);
    ShowWidget.showMaximized();
}

//获取文件路径
void ShowImg::getPath(QString String){
    DirPath=String;

}

//放大缩略图
void ShowImg::slot_item_enlarge(){
    ImgWidth=ImgWidth/0.8;
    ImgHeight=ImgHeight/0.8;
    //ItemWidth=ItemWidth/0.8;
    //ItemHeight=ItemHeight/0.8;
    IMAGE_SIZE.setWidth(ImgWidth);
    IMAGE_SIZE.setHeight(ImgHeight);
    //ITEM_SIZE.setWidth(ItemWidth);
    //ITEM_SIZE.setHeight(ItemHeight);
    ListWidget->clear();
    ListWidget->setIconSize(IMAGE_SIZE);
    for(int i=0;i<ImgList.count();i++){
        QPixmap Pixmap(DirPath+"//"+ImgList.at(i));
        QListWidgetItem *ListWidgetItem=new QListWidgetItem(QIcon(Pixmap.scaled(IMAGE_SIZE)),ImgList.at(i));
        //ListWidgetItem->setSizeHint(ITEM_SIZE);
        ListWidget->insertItem(i,ListWidgetItem);
    }
}

//缩小缩略图
void ShowImg::slot_item_shrink(){
    ImgWidth=ImgWidth*0.8;
    ImgHeight=ImgHeight*0.8;
    //ItemWidth=ItemWidth*0.8;
    //ItemHeight=ItemHeight*0.8;
    IMAGE_SIZE.setWidth(ImgWidth);
    IMAGE_SIZE.setHeight(ImgHeight);
    //ITEM_SIZE.setWidth(ItemWidth);
    //ITEM_SIZE.setHeight(ItemHeight);
    ListWidget->clear();
    ListWidget->setIconSize(IMAGE_SIZE);
    for(int i=0;i<ImgList.count();i++){
        QPixmap Pixmap(DirPath+"//"+ImgList.at(i));
        QListWidgetItem *ListWidgetItem=new QListWidgetItem(QIcon(Pixmap.scaled(IMAGE_SIZE)),ImgList.at(i));
        //ListWidgetItem->setSizeHint(ITEM_SIZE);
        ListWidget->insertItem(i,ListWidgetItem);

    }
}

#include "list.h"
#include "ui_list.h"

List::List(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::List)
{
    ui->setupUi(this);
    database = QSqlDatabase::database("DB0");
}

List::~List()
{
    qDebug() << "~List()";
    delete ui;
}

void List::on_btnAdd_clicked()
{
    addIngredient();
}


void List::on_btnRemove_clicked()
{
    removeIngredient();
}


void List::on_btnLoad_clicked()
{
    loadAllElements();
}


void List::on_listWidget_itemClicked(QListWidgetItem *item)
{
    showInfo();
}


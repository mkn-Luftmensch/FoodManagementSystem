#include "mealplan.h"
#include "ui_mealplan.h"

MealPlan::MealPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MealPlan)
{
    ui->setupUi(this);
    calendar = ui->calendarWidget;
    database = QSqlDatabase::database("DB0");
}

MealPlan::~MealPlan()
{
    qDebug() << "~MealPlan()";
    delete ui;
}

void MealPlan::on_btnLoad_clicked()
{
    QSqlQuery query(database);

    query.prepare("select RecipeName from Recipe");
    query.exec();
    while(query.next()) {
        ui->cmbBreakfast->addItem(query.value(0).toString());
        ui->cmbLunch->addItem(query.value(0).toString());
        ui->cmbDinner->addItem(query.value(0).toString());
        qDebug() << "Filling ComboBox" << query.value(0).toString();
    }

    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}


void MealPlan::on_calendarWidget_selectionChanged()
{
    ui->txtPlan->clear();
    qDebug() << ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    QString selectedDate = calendar->selectedDate().toString();
    ui->txtPlan->append(calendar->selectedDate().toString());
    QSqlQuery query(database);
    query.prepare("select Breakfast, Lunch, Dinner from MealPlan where Date like '%" + selectedDate + "%'");
    query.exec();
    if (query.next()) {
        QString breakfast = query.value(0).toString();
        QString lunch = query.value(1).toString();
        QString dinner = query.value(2).toString();
        ui->txtPlan->append("Breakfast: " + breakfast);
        ui->txtPlan->append("Lunch: " + lunch);
        ui->txtPlan->append("Dinner: " + dinner);
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}


void MealPlan::on_btnAdd_clicked() //TODO: cannot show info immediately
{
    QString date = calendar->selectedDate().toString();
    QString breakfast = ui->cmbBreakfast->currentText();
    QString lunch = ui->cmbLunch->currentText();
    QString dinner = ui->cmbDinner->currentText();
    QString addQuery = "insert into MealPlan (Date, Breakfast, Lunch, Dinner) "
                       "values('" + date + "','" + breakfast + "','" + lunch + "','" + dinner + "')";
    QSqlQuery query(database);


    query.prepare(addQuery);

    qDebug() << "Date: " << date << " Breakfast: " << breakfast << " Lunch: " << lunch << " Dinner: " << dinner;

    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last query: " << query.lastQuery();
    qDebug() << "Last error: " << query.lastError();
}


void MealPlan::on_btnDelete_clicked() //TODO: bug still show info until change to other date
{
    QString planToDelete = calendar->selectedDate().toString();
    QString deleteQuery = "delete from MealPlan where Date like '%" + planToDelete + "%'";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
}

//TODO create a refresh function
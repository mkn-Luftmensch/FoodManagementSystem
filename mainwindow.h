#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ingredient.h"
#include "recipe.h"
#include "mealplan.h"
#include "storage.h"
#include "onlineshopping.h"
#include "marketpurchasing.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    // open windows of features when clicking corresponding buttons

    void on_ingredientButton_clicked();

    void on_recipeButton_clicked();

    void on_mealplanButton_clicked();

    void on_storageButton_clicked();

    void on_shoppinglistButton_clicked();

private:
    // pointer to ui of MainWindow
    Ui::MainWindow *ui;

    // Declare pointer to all other features
    Ingredient *ptrIngredient;
    Recipe *ptrRecipe;
    MealPlan *ptrMealPlan;
    Storage *ptrStorage;
    OnlineShopping *ptrOnlineShopping;
    MarketPurchasing *ptrMarketPurchasing;

    QSqlDatabase database; // declare database
};
#endif // MAINWINDOW_H

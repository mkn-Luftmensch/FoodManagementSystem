#ifndef ADDTOSHOPPINGLIST_H
#define ADDTOSHOPPINGLIST_H

#include <QDialog>
#include "databaseheader.h"
#include "validation.h"

namespace Ui {
class AddToShoppingList;
}

class AddToShoppingList : public QDialog, public Validation
{
    Q_OBJECT

public:
    // constructor to open the ui for AddToShoppingList class
    explicit AddToShoppingList(QWidget *parent = nullptr);
    // destructor to delete ui pointer
    ~AddToShoppingList();
    // function to implement the signal function for the combo box
    void loadComboBox();
    // check user input validity
    bool validateUserInput();

private slots:
    // signal function to the accept button to add ingredient to the database
    void on_buttonBox_accepted();

private:
    // declare ui pointer
    Ui::AddToShoppingList *ui;
    // declare database
    QSqlDatabase database;
};

#endif // ADDTOSHOPPINGLIST_H

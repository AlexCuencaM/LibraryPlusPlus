#include <iostream>
#include <Views/MenuView.hpp>
#include <Controllers/BooksController.hpp>
#include <Controllers/UserController.hpp>
#include <MenuBuilder.hpp>
MenuBuilder::MenuBuilder(BooksController& booksController, UserController& userController, LoanBookController& loanBookController)
{
    this->booksController = &booksController;
    this->userController = &userController; // Initialize the UserController instance
    this->loanBookController = &loanBookController; // Initialize LoanBookController as nullptr
    this->menuView = new MenuView(booksController, userController, loanBookController); // Initialize the MenuView with the BooksController instance
}
void MenuBuilder::BuildMenu()
{
    bool continueMenu = true;
    while (continueMenu)
    {
        menuView->ShowMenu();
        int option = menuView->ChooseOption();
        continueMenu = menuView->SelectView(option);
    }
}

MenuBuilder::~MenuBuilder()
{
}

#include <iostream>
#include <Views/MenuView.hpp>
#include <Controllers/BooksController.hpp>
#include <Controllers/UserController.hpp>
#include <MenuBuilder.hpp>
MenuBuilder::MenuBuilder(BooksController& booksController, UserController& userController)
{
    this->booksController = &booksController;
    this->userController = &userController; // Initialize the UserController instance
    this->menuView = new MenuView(booksController, userController); // Initialize the MenuView with the BooksController instance
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

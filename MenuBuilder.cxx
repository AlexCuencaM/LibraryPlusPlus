#include <iostream>
#include <Controllers/BooksController.hpp>
#include <Views/MenuView.hpp>
#include <MenuBuilder.hpp>
MenuBuilder::MenuBuilder(BooksController& booksController)
{
    this->booksController = &booksController;
    this->menuView = new MenuView(booksController); // Initialize the MenuView with the BooksController instance
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

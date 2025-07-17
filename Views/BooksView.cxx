#include <Views/BooksView.hpp>
#include <iostream>
#include <Controllers/BooksController.hpp>
using namespace std;
BooksView::BooksView(BooksController& booksController)
{
    this->booksController = &booksController; // Initialize the booksController pointer
}

void BooksView::ShowBooks()
{
    this->booksController->PrintBooks(); // Call the PrintBooks method from BooksController
}

BooksView::~BooksView()
{
}
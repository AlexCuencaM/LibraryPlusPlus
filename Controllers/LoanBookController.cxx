#include <Controllers/LoanBookController.hpp>
#include <iostream>
using namespace std;
LoanBookController::LoanBookController(LoanBookService &loanBookService, LoanBookView &loanBookView, 
    BookService &bookService, BooksView &bookView,
    UserService &userService, UserView &userView)
{
    this->loanBookService = &loanBookService; // Initialize the loan book service
    this->bookService = &bookService; // Initialize the book service
    this->userService = &userService; // Initialize the user service
    this->loanBookView = &loanBookView; // Initialize the loan book view
    this->bookView = &bookView; // Initialize the book view
    this->userView = &userView; // Initialize the user view
}

LoanBookController::~LoanBookController()
{
}

void LoanBookController::LoanBookByCedula()
{
    //Search for the book by author or title
    string title, author, cedula;
    this->bookView->SearchBook(title, author); // Get search criteria from user
    Book* bookFiltered = this->bookService->SearchBook(title, author);
    this->bookView->ShowResultsBySearch(bookFiltered); // Show the results of the search
    bool isValidBook = this->bookService->ValidateBook(bookFiltered); // Validate the book
    if(!isValidBook) {
        return; // Exit if the book is not valid
    }
    this->userView->SearchCedula(cedula); // Get the cedula from user
    User* user = this->userService->GetUser(cedula); // Assuming title is used as a cedula for the user
    bool isValidUser = this->userView->ValidateUser(user); // Validate the user
    if (!isValidUser) {
        return; // Exit if the user is not valid
    }
    this->loanBookView->InsertLoan(this->loanBookService->InsertLoan(*bookFiltered, *user)); // Display the result of the loan operation
}

void LoanBookController::ReturnBookByCedula()
{
    string title, author;
    this->bookView->SearchBook(title, author); // Get search criteria from user
    Book* bookFiltered = this->bookService->SearchBook(title, author);
    this->bookView->ShowResultsBySearch(bookFiltered); // Show the results of the search
    bool isValidBook = this->bookService->ValidateBook(bookFiltered); // Validate the book
    if(!isValidBook) {
        return; // Exit if the book is not valid
    }
    this->loanBookView->InsertLoan(this->loanBookService->ReturnBook(*bookFiltered)); // Display the result of the loan operation
}

void LoanBookController::ModifyBook()
{
    string title, author;
    this->bookView->SearchBook(title, author); // Get search criteria from user
    Book* bookFiltered = this->bookService->SearchBook(title, author);
    this->bookView->ShowResultsBySearch(bookFiltered); // Show the results of the search
    bool isValidBook = this->bookService->ValidateBook(bookFiltered); // Validate the book
    if(!isValidBook) {
        return; // Exit if the book is not valid
    }
    this->loanBookView->InsertLoan(this->bookView->ModifyBook(bookFiltered));
}
void LoanBookController::DeleteBook()
{
    string isbn;
    this->bookView->SearchBookByIsbn(isbn); // Get search criteria from user
    Book* bookFiltered = this->bookService->SearchBookByIsbn(isbn);
    this->bookView->ShowResultsBySearch(bookFiltered); // Show the results of the search
    bool isValidBook = this->bookService->ValidateBook(bookFiltered); // Validate the book
    if(!isValidBook) {
        return; // Exit if the book is not valid
    }
    string loanBookResponse = this->loanBookService->DeleteLoanByIsbnBook(*bookFiltered);
    string bookResponse = this->bookService->DeleteBook(bookFiltered);
    this->loanBookView->RemoveLoan(loanBookResponse, bookResponse);
}

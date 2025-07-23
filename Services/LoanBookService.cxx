#include <Services/LoanBookService.hpp>
#include <DataStructure/ModernQueue.hpp>
#include <iostream>
using namespace std;
LoanBookService::LoanBookService(LinkedList<LoanBook> &loanBookList)
{
    this->loanBookList = &loanBookList; // Initialize the loan book list
}

LoanBookService::~LoanBookService()
{
}
bool LoanBookService::InsertLoan(Book &book, User &user)
{
    LoanBook* loanBook = SearchLoanBookByBook(book);
    if(loanBook == nullptr) {
        // If no existing loan book found, create a new one
        loanBook = new LoanBook(book);
        loanBook->userQueue = new ModernQueue<User>(); // Associate the user queue with the loan book
        loanBook->userQueue->Enqueue(user); // Enqueue the user into the queue
        this->loanBookList->InsertAtHead(*loanBook); // Insert the new LoanBook at the head of the list
        cout << "New loan book created for book: " << book.Title << endl;
        return true; // Successfully inserted the loan
    }
    cout << "Loan book already exists for book: " << book.Title << endl;
    User* existingUser = SearchUserByCedula(*loanBook, user);
    if (existingUser != nullptr) {
        std::cout << "El usuario ya existe en el préstamo de este libro." << endl;
        return false; // User already exists in the loan book
    }

    if(loanBook->userQueue == nullptr) {
        cout << "Queue not initialized" << user.Name << endl;
        return false;
    } 
    loanBook->userQueue->Enqueue(user); // If loan book exists, enqueue the user
    return false; // User already exists in the loan book
}

User *LoanBookService::SearchUserByCedula(LoanBook& loanBook,User& user)
{
    if (loanBook.userQueue == nullptr) {
        cout << "LoanBook has no associated user queue." << endl;
        return nullptr; // Return nullptr if the user queue is not initialized
    }
    for (auto &u : loanBook.userQueue->GetAll()) {
        std::cout << "Checking user: " << u.Cedula << endl;
        std::cout << "Comparing with user: " << user.Cedula << endl;
        if (u.Cedula == user.Cedula) { // Assuming Cedula is unique for each user
            return new User(u); // Return the found User
        }
    }
    return nullptr; // Return nullptr if no matching User is found
}

LoanBook *LoanBookService::SearchLoanBookByBook(Book &book)
{
    for (auto &loanBook : this->loanBookList->GetAll()) {
        if (loanBook.GetBook() == nullptr) {
            cout << "LoanBook has no associated book." << endl;
            continue; // Skip if the LoanBook has no book
        }
        cout << "Checking loan book for book: " << loanBook.GetBook()->ISBN << endl;
        cout << "Comparing with book: " << book.ISBN << endl;
        if (loanBook.GetBook()->ISBN == book.ISBN) { // Assuming ISBN is unique for each book
            return new LoanBook(loanBook); // Return the found LoanBook
        }
    }
    return nullptr; // Return nullptr if no matching LoanBook is found
}

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
    cout << "Searching for loan book by book: " << book.Title << endl;
    LoanBook* loanBook = SearchLoanBookByBook(book);
    if(loanBook == nullptr) {
        // If no existing loan book found, create a new one
        ModernQueue<User> userQueue; // Create a new queue for users
        userQueue.Enqueue(user); // Enqueue the user into the queue
        loanBook = new LoanBook(userQueue, book);
        this->loanBookList->InsertAtHead(*loanBook); // Insert the new LoanBook at the head of the list
        cout << "New loan book created for book: " << book.Title << endl;
        return true; // Successfully inserted the loan
    }
    User* existingUser = SearchUserByCedula(*loanBook, user);
    if (existingUser != nullptr) {
        std::cout << "El usuario ya existe en el préstamo de este libro." << endl;
        return false; // User already exists in the loan book
    }
    loanBook->userQueue->Enqueue(user); // If loan book exists, enqueue the user
    return false; // User already exists in the loan book
}

User *LoanBookService::SearchUserByCedula(LoanBook& loanBook,User& user)
{
    for (const auto &u : loanBook.userQueue->GetAll()) {
        if (u.Cedula == user.Cedula) { // Assuming Cedula is unique for each user
            return const_cast<User*>(&u); // Return the found User
        }
    }
    return nullptr; // Return nullptr if no matching User is found
}

LoanBook *LoanBookService::SearchLoanBookByBook(Book &book)
{
    if(this->loanBookList == nullptr) {
        cout << "Loan book list is not initialized." << endl;
        return nullptr; // Return nullptr if the loan book list is not initialized
    }

    for (auto &loanBook : this->loanBookList->GetAll()) {
        if (loanBook.GetBook() == nullptr) {
            cout << "LoanBook has no associated book." << endl;
            continue; // Skip if the LoanBook has no book
        }
        cout << "Checking loan book for book: " << loanBook.GetBook()->Title << endl;
        if (loanBook.GetBook()->ISBN == book.ISBN) { // Assuming ISBN is unique for each book
            return &loanBook; // Return the found LoanBook
        }
    }
    return nullptr; // Return nullptr if no matching LoanBook is found
}

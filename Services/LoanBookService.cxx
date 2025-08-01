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
string LoanBookService::InsertLoan(Book &book, User &user)
{
    LoanBook* loanBook = SearchLoanBookByBook(book);
    if(loanBook == nullptr) {
        // If no existing loan book found, create a new one
        loanBook = new LoanBook(book);
        loanBook->userQueue = new ModernQueue<User>(); // Associate the user queue with the loan book
        loanBook->userQueue->Enqueue(user); // Enqueue the user into the queue
        this->loanBookList->InsertAtHead(*loanBook); // Insert the new LoanBook at the head of the list
        return "Se ha prestado el libro: " + book.Title;
    }
    User* existingUser = SearchUserByCedula(*loanBook, user);
    if (existingUser != nullptr) {
        return "El usuario ya existe en el préstamo de este libro.";
    }
    loanBook->userQueue->Enqueue(user); // If loan book exists, enqueue the user
    return "El usuario: " + user.Name + " esta en la cola para el prestamo"; // User already exists in the loan book
}

string LoanBookService::DeleteLoanByIsbnBook(Book &book)
{
    LoanBook* loanBook = SearchLoanBookByBook(book);
    this->loanBookList->RemoveAt(loanBook);
    return "Prestamo eliminado correctamente";
}

string LoanBookService::ReturnBook(Book &book)
{
    LoanBook* loanBook = SearchLoanBookByBook(book);
    if(loanBook == nullptr) {
        return "El libro " + book.Title + " ya se encuentra en el inventario"; // No loan book found for the given book
    }
    if(loanBook->userQueue->IsEmpty()) {
        return "El libro " + book.Title + " ya se encuentra en el inventario"; // No loan book found for the given book
    } 
    User userDeleteFromQueue = loanBook->userQueue->Dequeue(); // Dequeue the user from the loan book
    if(loanBook->userQueue->IsEmpty()) {
        return "El usuario " + userDeleteFromQueue.Name + " ha devuelto el libro ";
    } 
    return "El usuario " + userDeleteFromQueue.Name + " ha devuelto el libro " + book.Title + ". Prestando libro al usuario en cola"; // Return success message
}

User *LoanBookService::SearchUserByCedula(LoanBook& loanBook,User& user)
{

    if (loanBook.userQueue == nullptr) {
        cout << "La cola de usuarios no está inicializada." << endl;
        return nullptr; // Return nullptr if the user queue is not initialized
    }
    for (auto &u : loanBook.userQueue->GetAll()) {
        if (u.Cedula == user.Cedula) { // Assuming Cedula is unique for each user
            return new User(u); // Return the found User
        }
    }
    return nullptr; // Return nullptr if no matching User is found
}

LoanBook *LoanBookService::SearchLoanBookByBook(Book &book)
{
    return this->loanBookList->firstOrDefault([book](LoanBook loanBook){
        return loanBook.GetBook() != nullptr && loanBook.GetBook()->ISBN == book.ISBN;
    });   
}

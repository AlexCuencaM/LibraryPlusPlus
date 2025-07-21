#include <Services/LoanBookService.hpp>
LoanBookService::LoanBookService(LinkedList<LoanBook> &loanBookList)
{
    this->loanBookList = &loanBookList; // Initialize the loan book list
}

LoanBookService::~LoanBookService()
{
}

#include <Controllers/LoanBookController.hpp>
LoanBookController::LoanBookController(LoanBookService &loanBookService, LoanBookView &loanBookView)
{
    this->loanBookService = &loanBookService; // Initialize the loan book service
    this->loanBookView = &loanBookView; // Initialize the loan book view
}

LoanBookController::~LoanBookController()
{
}

void LoanBookController::LoanBookByCedula()
{
}

void LoanBookController::ReturnBookByCedula()
{
}

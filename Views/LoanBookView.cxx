#include <Views/LoanBookView.hpp>
#include <iostream>
using namespace std;
void LoanBookView::InsertLoan(string responseMsg)
{
    cout << responseMsg << endl; // Display the message indicating whether a new loan was created or an existing user was added
    cin.ignore(); // Clear the input buffer
    cout << "Presione Enter para continuar...";
    cin.get(); // Wait for user input
}
void LoanBookView::RemoveLoan(string loanBookResponseMsg, string bookResponseMsg)
{
    cout << loanBookResponseMsg << endl << bookResponseMsg; // Display the message indicating whether a new loan was created or an existing user was added
    cin.ignore(); // Clear the input buffer
    cout << "Presione Enter para continuar...";
    cin.get(); // Wait for user input
}

void LoanBookView::DisplayReturnSuccess(const std::string &bookTitle, const std::string &userCedula)
{
}
#include <Views/LoanBookView.hpp>
#include <iostream>
using namespace std;
void LoanBookView::InsertLoan(bool isNewLoan)
{
    if (isNewLoan) {
        cout << "Préstamo realizado exitosamente." << endl;
    } else {
        cout << "El libro ya está prestado a otro usuario, está en cola." << endl;
    }
    cin.ignore(); // Clear the input buffer
    cout << "Presione Enter para continuar...";
    cin.get(); // Wait for user input
}
void LoanBookView::DisplayReturnSuccess(const std::string &bookTitle, const std::string &userCedula)
{
}

#include <Views/UserView.hpp>
#include <iostream>
using namespace std;
void UserView::InsertUser(User &newUser)
{
    cout << "agregando un nuevo usuario..." << endl;
    cout << "Ingrese cedula: ";
    cin >> newUser.Cedula;
    cin.ignore(); // Clear the input buffer
    cout << "Ingrese nombre: ";
    getline(cin, newUser.Name);
    cout << "Usuario agregado !" << endl;
    cout << "Cedula: " << newUser.Cedula << ", Nombre: " << newUser.Name << endl;
    cin.ignore(); // Clear the input buffer
}

void UserView::SearchCedula(std::string &cedula)
{
    cout << "Ingrese cedula del usuario a buscar: ";
    cin >> cedula;
}


bool UserView::ValidateUser(User const *user)
{
    if (user == nullptr) {
        cout << "Usuario no encontrado!" << endl;
        return false; // User not found
    }
    cout << "Usuario encontrado: " << *user << endl; //<< user->Name << " with cedula: " << user->Cedula << endl;
    return true; // User found
}

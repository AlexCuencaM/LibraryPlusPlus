#include <Services/UserService.hpp>
#include <vector>
#include <string>
using namespace std;
UserService::UserService(LinkedList<User> &userList)
{
    this->userList = &userList; // Initialize the user list
}
void UserService::AddUser(const User &user)
{
    userList->InsertAtHead(user); // Insert the user at the head of the list
}
User* UserService::GetUser(const string &cedula)
{
    for (auto &user : userList->GetAll()) {
        if (user.Cedula == cedula) {
            return &user; // Return the user if found
        }
    }
    return nullptr; // Return nullptr if user not found
}
UserService::~UserService()
{
}

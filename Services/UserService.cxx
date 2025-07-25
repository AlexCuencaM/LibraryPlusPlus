#include <Services/UserService.hpp>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
UserService::UserService(LinkedList<User> &userList)
{
    this->userList = &userList; // Initialize the user list
}
void UserService::AddUser(const User &user)
{
    userList->InsertAtHead(user); // Insert the user at the head of the list
}
// User const *UserService::GetUser(std::string &cedula)
// {
//     return nullptr;
// }
User *UserService::GetUser(string &cedula)
{
    for (auto &user : userList->GetAll()) {
        // Check if the cedula matches the user's cedula
        if (user.Cedula == cedula) {
            return new User(user); // Return the user if found
        }
    }
    return nullptr; // Return nullptr if user not found
}
UserService::~UserService()
{
}

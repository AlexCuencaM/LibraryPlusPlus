#include <Controllers/UserController.hpp>
using namespace std;
UserController::UserController(UserService &userService, UserView &userView)
{
    this->userService = &userService; // Initialize the UserService instance
    this->userView = &userView; // Initialize the UserView instance
}

void UserController::InsertUser()
{
    User newUser; // Create a new User instance
    userView->InsertUser(newUser); // Call the view to insert a new user
    userService->AddUser(newUser); // Add the new user to the service
}

UserController::~UserController()
{
}

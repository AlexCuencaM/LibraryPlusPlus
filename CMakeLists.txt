cmake_minimum_required(VERSION 3.10)
project(LibrarylusPlus)
# add_executable(LibrarylusPlus hello_world.cxx Bye.cxx Hello.cxx)
add_executable(LibrarylusPlus
    Entities/Book.cxx
    Entities/User.cxx
    Entities/LoanBook.cxx
    Services/BookService.cxx
    Services/UserService.cxx
    Services/LoanBookService.cxx
    Controllers/BooksController.cxx
    Controllers/UserController.cxx
    Controllers/LoanBookController.cxx
    Views/LoanBookView.cxx
    Views/BooksView.cxx
    Views/UserView.cxx
    Views/MenuView.cxx
    MenuBuilder.cxx
    main.cxx
)
target_include_directories(LibrarylusPlus PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
configure_file(Entities/Book.h.in Entities/Book.hpp)
configure_file(Entities/User.h.in Entities/User.hpp)
configure_file(Entities/LoanBook.h.in Entities/LoanBook.hpp)
#Binary tree moment
configure_file(DataStructure/BinaryTree.h.in DataStructure/BinaryTree.hpp)
configure_file(DataStructure/BinaryTreeImpl.h.in DataStructure/BinaryTreeImpl.hpp)
configure_file(DataStructure/Node.h.in DataStructure/Node.hpp)

configure_file(DataStructure/Queue.h.in DataStructure/Queue.hpp)
configure_file(DataStructure/ModernQueue.h.in DataStructure/ModernQueue.hpp)
configure_file(DataStructure/LinkedList.h.in DataStructure/LinkedList.hpp)
configure_file(DataStructure/ModernLinkedList.h.in DataStructure/ModernLinkedList.hpp)
configure_file(Controllers/BooksController.h.in Controllers/BooksController.hpp)
configure_file(Controllers/UserController.h.in Controllers/UserController.hpp)
configure_file(Controllers/LoanBookController.h.in Controllers/LoanBookController.hpp)
configure_file(Services/BookService.h.in Services/BookService.hpp)
configure_file(Services/UserService.h.in Services/UserService.hpp)
configure_file(Services/LoanBookService.h.in Services/LoanBookService.hpp)
configure_file(Views/BooksView.h.in Views/BooksView.hpp)
configure_file(Views/LoanBookView.h.in Views/LoanBookView.hpp)
configure_file(Views/UserView.h.in Views/UserView.hpp)
configure_file(Views/MenuView.h.in Views/MenuView.hpp)
configure_file(MenuBuilder.h.in MenuBuilder.hpp)
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_BUILD_TYPE Debug)
# add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
# add_link_options(-fsanitize=address)
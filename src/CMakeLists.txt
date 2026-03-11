cmake_minimum_required(VERSION 4.2.3)
add_executable (ToDoApp ToDoApp.cpp TaskList.cpp)
target_include_directories(ToDoApp PRIVATE ${CMAKE_SOURCE_DIR}/include)

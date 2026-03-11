#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include "TaskList.hpp"
class ToDoApp{
	TaskList taskList;
	bool receiveUserInput(){
		std::string userInput;
		std::cout <<  "Please enter an option: " << std::endl;
		std::cin >>	userInput;
		return processUserInput(userInput);
	}
	std::string promptForTaskTitle(){
		std::string taskTitle;
		std::cout << "Enter the task title: ";
		std::cin >> taskTitle;
		return taskTitle;
	}
	void showTasks(){
		auto currentTaskList = taskList.getTasks();
		for (Task task : currentTaskList){
			if (task.completed){
			std::cout << task.id << ": " << task.title <<" Status: Done" << std::endl;
			} else{
				std::cout << task.id << ": " << task.title << " Status: To do" << std::endl;
			}
		}
	}
	int  promptForTaskID(){
		int taskID;
		showTasks();
		std::cout << "Enter the ID for completed task: ";
		std::cin >> taskID;
		return taskID;
	}
	void markTaskCompleted(){
		int taskID = promptForTaskID();
		if(taskList.completeTask(taskID)){
			std::cout << "Task " << taskID << " has been completed." <<std::endl;
			
		}else{
			std::cout << "Task with ID: " << taskID << " could not be found." << std::endl;
		}
	}
	void deleteTask(){
		int taskID = promptForTaskID();
		if (taskList.deleteTask(taskID)){
			std::cout << "Task " << taskID << " has been deleted." << std::endl;
		} else{
			std::cout <<"Task with ID: " << taskID << " could not be found" <<std::endl;
		}
	}
	bool processUserInput(std::string userInput){
		int userInputValue;
		try {
			userInputValue = std::stoi(userInput);
			}	
		catch(const std::exception& e){
			std::cout << "Invalid entry." <<std::endl;
			return false;
		}
		switch(userInputValue){
		case 1://add_task
			{
				std::string taskTitle = promptForTaskTitle();
				taskList.addTask(taskTitle);
				//std::cout << "Adding a task" << std::endl;
				break;
			}
		case 2:{
			// Delete Task
			deleteTask();
			break;
		}
		case 3:{
			//mark task completed
			markTaskCompleted();
			break;
		}
		case 4:
			{	//Save tasks
				std::cout << "Saving Tasks" << std::endl;
				break;
			}
			
		case 5:{
			showTasks();
		}
			break;
		case 0:{
			std::cout << "Exiting application" << std::endl;
			exit(0);
		}
			default:
				std::cout << "Please input a valid number" << std::endl;
				return false;
	}
	return true;
}
public:
void runApp(){
	std::cout << "----Starting ToDo List----" << std::endl;
		
	while(true){
		std::cout << "-Menu-" << std::endl;
		std::cout << "1) Add Task" << std::endl;
		std::cout << "2) Delete Task" << std::endl;
		std::cout << "3) Complete Task" << std::endl;
		std::cout << "4) Save Task" << std::endl;
		std::cout << "5) Show Tasks" << std::endl;
		std::cout << "0) Exit application" << std::endl;
		auto success = receiveUserInput();
		if (!success){
			std::cout << "Something went wrong!" << std::endl;
		}
	}
}
};

int main(){
	std::cout << "----Starting ToDo List----" << std::endl;
	ToDoApp app;
	app.runApp();
	return 0;
}

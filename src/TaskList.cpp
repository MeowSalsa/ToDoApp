#include <vector>
#include <iostream>
#include <algorithm>
#include "Task.hpp"
#include "TaskList.hpp"

bool TaskList::addTask(std::string newTask) {
	Task task;
	task.title = newTask;
	task.id = nextTaskID;
	task.completed = false;
	taskVector.push_back(task);
	nextTaskID++;
	std::cout << "Added new task: "<< task.id << std::endl;
	return true;
}
bool TaskList::deleteTask(int taskID){
	auto it = std::find_if(taskVector.begin(), taskVector.end(), [taskID](const Task &task){
		return task.id == taskID;
	});
	if (it != taskVector.end()){
		taskVector.erase(it);
		return true;
	}
	return false;
}
bool TaskList::completeTask(int taskID){
	for(Task &task : taskVector){
		if (task.id == taskID){
			task.completed = true;
			return true;
		}
	}
	return false;
}
std::vector<Task> TaskList::getTasks(){
	return taskVector;
}

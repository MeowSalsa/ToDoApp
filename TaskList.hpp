#pragma once

#include <vector>
#include "Task.hpp"
class TaskList{
	std::vector<Task> taskVector;
	int nextTaskID;
 public:
	bool addTask(std::string newTaskTitle);
	bool deleteTask(int taskID);
	bool completeTask(int taskID);
	std::vector<Task>  getTasks();
};

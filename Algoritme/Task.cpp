#include "Task.h"

Task::Task(unsigned short taskId, unsigned short machineId, unsigned short time) :
	taskId(taskId), machineId(machineId), time(time)
{

}

Task::~Task()
{

}

const unsigned short Task::getTaskId() const
{
	return taskId;
}

const unsigned short Task::getTime() const
{
	return time;
}

TaskStatus Task::getTaskStatus()
{
	return taskStatus;
}

void Task::setTaskStatus(TaskStatus status)
{
	taskStatus = status;
}

const unsigned short Task::getMachineId() const
{
	return machineId;
}

void Task::setRunningTime(unsigned short time)
{
	runningTime += time;
}

const unsigned short Task::getRunningTime() const
{
	return runningTime;
}

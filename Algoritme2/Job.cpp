#include "Job.h"

Job::Job(unsigned short jobId) :
	jobId(jobId)
{

}

Job::~Job()
{

}

void Job::createTasks(std::vector<unsigned short>& tasksValues)
{
	unsigned short taskId = 0;
	for(std::vector<unsigned short>::iterator i = tasksValues.begin(); i != tasksValues.end(); ++i)
	{
		unsigned short machineId = *i;
		unsigned short time = *(++i);
		Task task(taskId, machineId, time);
		tasks.push_back(task);
		taskId++;
	}
}

void Job::calculateTasksTimeLeft()
{
	totalTimeLeft = 0;
	for(auto& task : tasks)
	{
		if(task.getTaskStatus() == TaskStatus::IN_PROGRESS)
		{
			totalTimeLeft += (task.getTime() - task.getRunningTime());
		} else
		{
			totalTimeLeft += task.getTime();
		}
	}
}

void Job::taskFinished()
{
	tasks.pop_front();
}

Task& Job::giveTask()
{
	return tasks.front();
}

const unsigned long long Job::getJobId() const
{
	return jobId;
}

const unsigned long long Job::getTotalTimeLeft() const
{
	return totalTimeLeft;
}

const bool Job::getIsStarted() const
{
	return isStarted;
}

void Job::setIsStarted()
{
	isStarted = true;
}

void Job::setStartTime(unsigned long long time)
{
	startTime = time;
}

const unsigned long long Job::getStartTime() const
{
	return startTime;
}

const unsigned long long Job::getTotalTime() const
{
	return totalTime;
}

void Job::setTotalTime(unsigned long long amount)
{
	totalTime += amount;
}

#include "JobShop.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <vector>

JobShop::JobShop(std::string inputFile) :
	inputFile(inputFile)
{

}

JobShop::~JobShop()
{

}

void JobShop::run()
{
	if(loadFile()) {
		createMachines();
		createJobs();
		calculateSlackTime();
		schedule();
		print();
	} else error();
}

bool JobShop::loadFile()
{
	std::ifstream ifs (inputFile , std::ifstream::in);
	if(ifs.good()) {
		char c;
		std::string buffer;
		std::vector<unsigned short> jobTasks;
		while(ifs.good())
		{
			c = ifs.get();
			if(c != ' ' && c != '\t' && c != '\n' && c != EOF)
			{
				if(!isdigit(c)) return false;
				buffer += c;
			} else if (buffer.size() > 0)
			{
				jobTasks.insert(jobTasks.end(), std::stoi(buffer));
				buffer.clear();
			}
			if(c == '\n' || c == '\0' || ifs.eof())
			{
				input.insert(input.end(), jobTasks);
				jobTasks.clear();
			}
		}
		return true;
	}
	return false;
}

void JobShop::createMachines()
{
	for(unsigned short i = 0; i < input[0][1]; i++)
	{
		machines[i] = false;
	}
}

void JobShop::createJobs()
{
	for(unsigned short i = 0; i < input[0][0]; i++)
	{
		Job job(i);
		job.createTasks(input[i+1]);
		jobs.push_back(job);
	}
}

void JobShop::calculateSlackTime()
{
	for(auto& job : jobs)
	{
		job.calculateTasksTimeLeft();
	}
	std::sort(jobs.begin(), jobs.end(),
		[](Job& a, Job& b) -> bool
	{
		return (a.getTotalTimeLeft() > b.getTotalTimeLeft())
				|| (a.getTotalTimeLeft() == b.getTotalTimeLeft() // als de totale tijd van a en b gelijk is, en niet gelijk aan 0:
						&& a.getTotalTimeLeft() != 0 			// kleinste job id heeft voorrang
						&& a.getJobId() < b.getJobId());
	});
}

bool JobShop::finished()
{
	for(auto& job : jobs)
	{
		if(job.getTotalTimeLeft() != 0)
		{
			return false;
		}
	}
	return true;
}

bool JobShop::isMachineRunning(unsigned short machineId)
{
	return machines[machineId];
}

void JobShop::schedule()
{
	while(!finished())
	{
		for(auto& job : jobs) // deze loop is om te checken welke taken er klaar zijn
		{
			if(job.getTotalTimeLeft() != 0)
			{
				if(job.getIsStarted())
				{
					job.setTotalTime(1);
				}
				if(job.giveTask().getTaskStatus() == TaskStatus::IN_PROGRESS)
				{
					job.giveTask().setRunningTime(1);
					if(job.giveTask().getRunningTime() == job.giveTask().getTime())
					{
						machines[job.giveTask().getMachineId()] = false;
						job.taskFinished();
					}
				}
			}
		}

		calculateSlackTime();

		for(auto& job : jobs) // deze loop is om de nieuwe taken te schedulen
		{
			if(job.getTotalTimeLeft() != 0)
			{
				if(job.giveTask().getTaskStatus() != TaskStatus::IN_PROGRESS
					&& !isMachineRunning(job.giveTask().getMachineId()))
				{
					scheduleTask(job);
				}
			}
		}

		timer++;
	}
}

void JobShop::scheduleTask(Job& job)
{
	if(!job.getIsStarted())
	{
		job.setIsStarted();
		job.setStartTime(timer);
	}

	machines[job.giveTask().getMachineId()] = true;
	job.giveTask().setTaskStatus(TaskStatus::IN_PROGRESS);
}

void JobShop::print()
{
	std::sort(jobs.begin(), jobs.end(),
		[](Job& a, Job& b) -> bool
	{
	    return a.getJobId() < b.getJobId();
	});
	for(auto& job : jobs)
	{
		std::cout << job.getJobId() << "  " << job.getStartTime() << "  " << job.getStartTime() + job.getTotalTime() << std::endl;
	}
}

void JobShop::error() {
	std::cout << "File not valid" << std::endl;
}

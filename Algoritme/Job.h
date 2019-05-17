#ifndef JOB_H_
#define JOB_H_
#include "Task.h"
#include <deque>
#include <vector>
#include <utility>
#include <iostream>

class Job
{
public:
	/**
	 * Constructor voor een job.
	 * Param jobId: het id dat deze job krijgt.
	 */
	Job(unsigned short jobId);


	/**
	 * Destructor voor een job.
	 */
	virtual ~Job();


	/**
	 * Deze functie maakt de taken aan die bij deze job horen
	 * param tasksValues: Deze vector bevat de waarden die in de taken komen
	 */
	void createTasks(std::vector<unsigned short>& tasksValues);


	/**
	 * Deze functie berekend de totale tijd die een job nog nodig heeft voordat hij gescheduled is
	 */
	void calculateTasksTimeLeft();


	/**
	 * getter voor het id van de job
	 */
	const unsigned long long getJobId() const;


	/**
	 * getter voor de totale tijd die de job nog nodig heeft
	 */
	const unsigned long long getTotalTimeLeft() const;


	/**
	 * getter voor de totale tijd dat een job op het moment bezig is
	 */
	const unsigned long long getTotalTime() const;


	/**
	 * setter waarmee de totale tijd die een job bezig is opgehoogd kan worden
	 * param amount: de waarde waarmee de totale tijd opgehoogd moet worden
	 */
	void setTotalTime(unsigned long long amount);


	/**
	 * bool functie die returned of er al begonnen is aan deze job te schedulen
	 */
	const bool getIsStarted() const;


	/**
	 * setter om in te stellen dat er begonnen is aan de job te schedulen
	 */
	void setIsStarted();


	/**
	 * functie die de eerste taak uit de deque "tasks" returned
	 */
	Task& giveTask();


	/**
	 * met deze functie valt de starttijd van een job in te stellen
	 * param time: de tijd wanneer er begonnen is aan de eerste taak van de job te schedulen
	 */
	void setStartTime(unsigned long long time);


	/**
	 * deze getter returned de starttijd van de job
	 */
	const unsigned long long getStartTime() const;


	/**
	 * als een taak gescheduled is kan hij uit de deque gehaald worden. Dat is wat deze functie doet.
	 */
	void taskFinished();
private:
	std::deque<Task> tasks;
	unsigned long long jobId;
	unsigned long long totalTime = 0;
	unsigned long long totalTimeLeft = 0;
	unsigned long long startTime = 0;
	bool isStarted = false;
};

#endif /* JOB_H_ */

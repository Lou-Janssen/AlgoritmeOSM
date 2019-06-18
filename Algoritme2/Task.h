#ifndef TASK_H_
#define TASK_H_

enum TaskStatus
{
	TODO,
	IN_PROGRESS,
	DONE
};

class Task {
public:
	/**
	 * constructor voor het maken van een object van de klasse Task
	 * param taskId: het id dat de taak krijgt
	 * param machineId: het id van de machine waar de taak uiteindelijk op gaat draaien
	 * param time: de tijd die nodig is voor het uitvoeren van de taak
	 */
	Task(unsigned short taskId, unsigned short machineId, unsigned short time);


	/**
	 * destructor van een taak
	 */
	virtual ~Task();


	/**
	 * getter die het id van de machine waar deze taak op draait returned
	 */
	const unsigned short getMachineId() const;


	/**
	 * getter die huidige status van een task returned: bijv. IN_PROGRESS, TODO etc.
	 */
	TaskStatus getTaskStatus();


	/**
	 * setter voor het veranderen van de status van een taak
	 * param status: enum van het type TaskStatus wat de nieuwe status van de taak gaat worden
	 */
	void setTaskStatus(TaskStatus status);


	/**
	 * getter die de tijd returned die een taak nodig heeft om uitgevoerd te worden
	 */
	const unsigned short getTime() const;


	/**
	 * setter voor het instellen van de tijd hoe lang een taak op dit moment bezig is
	 * param time: de tijd waarmee je de huidige runningTime wilt veranderen
	 */
	void setRunningTime(unsigned short time);


	/**
	 * getter voor het opvragen van hoelang een taak op dit moment bezig is
	 */
	const unsigned short getRunningTime() const;


	/**
	 * getter voor het opvragen van het id van de taak
	 */
	const unsigned short getTaskId() const;
private:
	unsigned short taskId;
	unsigned short machineId;
	unsigned short time;
	unsigned short runningTime = 0;
	TaskStatus taskStatus = TODO;
};

#endif /* TASK_H_ */

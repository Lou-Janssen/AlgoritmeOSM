#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <cctype>
#include "Job.h"
#include "Task.h"

class JobShop {
public:

	/**
	 * Constructor voor een JobShop. Deze klasse bevat alle logica tot het uitvoeren van het Least Slack algoritme op een invoerbestand met jobs en taken.
	 * Param inputFile: het invoerbestand dat de jobs en taken bevat die gescheduled moeten worden door het Least Slack algoritme
	 */
	JobShop(std::string inputFile);


	/**
	 * Destructor voor de klasse JobShop
	 */
	virtual ~JobShop();


	/**
	 * Roep deze functie aan voor het schedulen van het invoerbestand.
	 */
	void run();

private:
	std::vector<std::vector<unsigned short>> input;
	std::map<unsigned short, bool> machines;
	std::vector<Job> jobs;
	unsigned long long timer = 0;
	std::string inputFile;


	/**
	 * Deze functie zorgt ervoor dat het invoer bestand goed ingelezen wordt. Daarnaast worden eventuele fouten in het bestand in deze functie afgevangen
	 */
	bool loadFile();


	/**
	 * Deze functie maakt de machines aan op basis van het aantal machines dat in de configuratie is meegegeven
	 */
	void createMachines();


	/**
	 * Deze functie maakt de jobs aan, en daarbij de bijbehorende taken die in het invoer bestand staan.
	 */
	void createJobs();


	/**
	 * Deze functie sorteert de jobs vector. Hierdoor staat altijd de job met de hoogste slack tijd als eerste.
	 * In het geval dat er meerdere jobs zijn met dezelfde slack tijd wordt de job met het laagste id boven de andere gezet
	 */
	void calculateSlackTime();


	/**
	 * bool functie die returned of alle jobs gescheduled zijn.
	 * returned true in het geval dat alle jobs gescheduled zijn.
	*/
	bool finished();


	/**
	 * bool functie die returned of er op de meegegeven machine een taak bezig is
	 * return true in het geval een taak bezig is op de meegegeven machine, anders false.
	 * param MachineId: het id van de machine waarvan je wil weten of er een taak op bezig is
	 */
	bool isMachineRunning(unsigned short machineId);


	/**
	 * deze functie schedult elke keer nieuwe taken totdat alle taken geschedulet zijn.
	 * Hij hoeft voor 1 bestand maar 1 keer aangeroepen te worden.
	 */
	void schedule();


	/**
	 * de functie scheduleTask zorgt ervoor dat een nieuwe taak van de meegegeven job actief wordt gezet op
	 * de machine die die taak nodig heeft. Daarnaast wordt in het geval dat dit de eerste taak van de job is
	 * een timer binnen de job gestart.
	 * param job: de job waarvan de taak actief moet worden gezet
	 */
	void scheduleTask(Job& job);


	/**
	 * Deze functie sorteert de jobs zodat de job met het laagste id bovenaan komt te staan. Daarnaast print hij de
	 * job id, starttijd van de job, en de eindtijd van de job.
	 */
	void print();


	/**
	 * In het geval dat er een error optreed tijdens het lezen van het inputbestand kan de volgende functie worden aangeroepen
	 * print dat het bestand niet geldig is.
	 */
	void error();
};

#endif /* JOBSHOP_H_ */

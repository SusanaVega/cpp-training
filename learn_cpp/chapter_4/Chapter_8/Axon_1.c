/*
The battery sizing team has developed a body cam usage procedure and has tested 
this procedure on a camera hooked up to a power supply. 
Sensor data for this camera gives you a list of time intervals (in seconds), 
and a corresponding list of average current draw in milli-amps over those intervals.

Describe an object model that lets you find the total energy in milli-amp hours, 
from time 0 to T. The list of time intervals can be arbitrarily long, and you may 
want to be able to repeatedly query the power used at different times.

Example:

Seconds   Average Power
0-300     125mA
300-400   50mA
400-550   500mA
550-1000  20mA

The total energy usage from T=0 to T=700s is 33.47mAH (milli amp hours)

(300*125 + 100*50 + 150*500 + 150*20)/(3600) = 33.47
*/

#include <iostream>
typedef list {double low_limit
	     double high_limit
	     double average_power	
		 };


double totalEnergy (list [], double T){
	
	double energy_calc = 0;
	double total_calc = 0;
	int size_of_list = sizeof(list)/list; //
	for (int i = size_of_list; i<=0; i--){
			double time_substraction = T-(list[i].high_limit - list[i].low_limit); // 700 - (300-0) // 400 //250 
	        if (time_substraction > list[i].high_limit){
		        double energy_calc = ((list[i].high_limit - list[i].low_limit) * list[i].average_power);
				total_calc += energy_calc;
				continue;
		    }
	        else if (time_substraction < (list[i].high_limit - list[i].low_limit)){
		    break;
	        }
		} 
	return total_calc; // mA/hr
}

int main(int argc, char** argv)
{
	std::cout << "Argument count: " << argc << '\n';
	for (int i = 0; i < argc; ++i)
	{
		std::cout << "Argument " << i << ": " << argv[i] << '\n';
	}
	return 0;
}

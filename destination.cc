
#include "destination.h"
#include <iostream>
using namespace std;
int destination::display() const{
//	cout << "name: " << location_name
	cout << "DESTINATION - " << location_name <<", " << nationstate_identifier << endl
	<< "    You should really visit in the " << best_time_of_year << endl << "    It's best to get there by "
	<< how_to_get_there << endl << "    Beauty index: " << natural_beauty_index << "/10" << endl
	<< "    You can do the following activities: " << endl;

	for(int i = 0; i < things_to_do.size(); ++i){
		cout << "        - " << things_to_do[i] << endl;
	}
};

#ifndef SOURCE_DESTINATION_H // TODO Can I rename this implementation to _DESTINATION or DESTINATION or something and have these statements work?
#define SOURCE_DESTINATION_H

#include <vector> // todo Can I do this?
using namespace std;
class destination {
private:
	char * location_name;
	char * nationstate_identifier; // todo can I use string instead of this yet?
	char * best_time_of_year;
	char * how_to_get_there;

	vector<char *> things_to_do;

	int natural_beauty_index; // Number representing natural beauty of destination from 1..10

public:
	int display() const;

};


#endif //SOURCE_DESTINATION_H

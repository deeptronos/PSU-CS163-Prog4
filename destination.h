
#ifndef SOURCE_DESTINATION_H // TODO Can I rename this implementation to _DESTINATION or DESTINATION or something and have these statements work?
#define SOURCE_DESTINATION_H

#include <cstring>
#include <vector> // todo Can I do this?
using namespace std;

class destination {
private:
	char * location_name;
	char * nationstate_identifier; // todo can I use string instead of this yet?
	char * best_time_of_year;
	char * how_to_get_there;

	vector<char *>* things_to_do; // TODO allowed? should this not be a * to a vector<char *>?

	int natural_beauty_index; // Number representing natural beauty of destination from 1..10

public:
	destination();
//	destination(const char* name, const char* nationstate, const char* best_time, const char* getting_there, const vector<char *>* things, const int* natural_beauty);
	destination(const char* name, const char* nationstate, const char* best_time, const char* getting_there,  vector<char *>* things, const int* natural_beauty);
	~destination();


	int display() const;

	char * getLocationName() const;
	char * getNationstateIdentifier() const;
	char * getBestTimeOfYear() const;
	char * getHowToGetThere() const;
	vector<char *> getThingsToDo() const;
	int getNaturalBeautyIndex() const;

	void setNationstateIdentifier(const char* new_);
	void setBestTimeOfYear(const char* new_);
	void setHowToGetThere(const char* new_);
	void setThingsToDo(vector<char*>* new_); // TODO argument type OK? implicit deep copy...
	void setNaturalBeautyIndex(const int new_);

};


#endif //SOURCE_DESTINATION_H

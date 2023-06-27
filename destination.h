
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

	char ** things_to_do;
	int things_to_do_size;

	int natural_beauty_index; // Number representing natural beauty of destination from 1..10

public:
	destination();
//	destination(const char* name, const char* nationstate, const char* best_time, const char* getting_there, const vector<char *>* things, const int* natural_beauty);
	destination(const char* name, const  char* nationstate,  const char* best_time,  const char* getting_there,  char** things, int things_size, int natural_beauty);
	~destination();


	int display() const;

	char * getLocationName() const;
	char * getNationstateIdentifier() const;
	char * getBestTimeOfYear() const;
	char * getHowToGetThere() const;
	char** getThingsToDo() const;
	int getNaturalBeautyIndex() const;
	//TODO you should probably get rid of these, at least as public fields...
	void setNationstateIdentifier(const char* new_);
	void setBestTimeOfYear(const char* new_);
	void setHowToGetThere(const char* new_);
	void setThingsToDo(char** new_, const int size_); // TODO argument type OK? implicit deep copy...
	void setNaturalBeautyIndex(const int new_);

	friend std::ostream& operator<<(std::ostream& os, const destination& ds); //TODO why a friend...
};

#include "destination.cc" // todo Why this...
#endif //SOURCE_DESTINATION_H


#include "destination.h"
#include <iostream>


//destination::destination() : location_name(nullptr), nationstate_identifier(nullptr), best_time_of_year(nullptr), how_to_get_there(nullptr), things_to_do(nullptr), natural_beauty_index(-1)  {} // default constructor using initializers. Sets natural_beauty_index to a value representing a null destination.
destination::destination(){ // default
}

//destination::destination(const char *name, const char *nationstate, const char *best_time, const char *getting_there, // TODO this seems like a silly thing to do...
////                         const vector<char *> *things, const int *natural_beauty)
destination::destination(const char *name, const char *nationstate, const char *best_time, const char *getting_there, const char **things, int things_size, int natural_beauty) {
	location_name = new char[strlen(name) + 1];
	strcpy(location_name, name);

	nationstate_identifier = new char[strlen(nationstate) + 1];
	strcpy(nationstate_identifier, nationstate);

	best_time_of_year = new char[strlen(best_time) + 1];
	strcpy(best_time_of_year, best_time);

	how_to_get_there = new char[strlen(getting_there) + 1];
	strcpy(how_to_get_there, getting_there);

//	things_to_do(&things);
//	things_to_do things;
	things_to_do_size = things_size;
	things_to_do = new char *[things_size];
	for(int i = 0; i < things_to_do_size; ++i){
		things_to_do[i] = new char[255]; // Creating large buffer for each things_to_do entry bc we don't know size of each dynamic array entry...
		strcpy(things_to_do[i], things[i]);
		// TODO Can we trim off excess dynam char array characters?
	}

	natural_beauty_index = natural_beauty; // TODO problem?
}
//destination(const char* name, const char* nationstate, const char* best_time, const char* getting_there,  const char** things, int things_size, int natural_beauty)
//destination::destination(const char* name, const  char* nationstate,  const char* best_time,  const char* getting_there,  const char** things, int things_size, int natural_beauty)
//: location_name(name), nationstate_identifier(nationstate), best_time_of_year(best_time), how_to_get_there(getting_there), things_to_do(things), things_to_do_size(things_size), natural_beauty_index(natural_beauty) {}

destination::~destination() {
	// delete dynamic things:
//	delete location_name;
//	delete nationstate_identifier;
//	delete best_time_of_year;
//	delete how_to_get_there;

//	for(int i = 0; i < things_to_do_size; ++i){
//		delete[] things_to_do[i];
//	}
//	delete things_to_do;
}


using namespace std;
int destination::display() const{
//	cout << "name: " << location_name
	cout << "DESTINATION - " << location_name <<", " << nationstate_identifier << endl
	<< "    You should really visit in the " << best_time_of_year << endl << "    It's best to get there by "
	<< how_to_get_there << endl << "    Beauty index: " << natural_beauty_index << "/10" << endl
	<< "    You can do the following activities: " << endl;

	for(auto i = 0; i < things_to_do_size; ++i){
		cout << "        - " << &(things_to_do[i]) << endl;
	}
	return 1;
};

char * destination::getLocationName() const {
	return location_name;
}

char * destination::getNationstateIdentifier() const {
	return nationstate_identifier;
}

char * destination::getBestTimeOfYear() const {
	return best_time_of_year;
}

char * destination::getHowToGetThere() const {
	return how_to_get_there;
}

char** destination::getThingsToDo() const { // todo good?
	return things_to_do;
}

int destination::getNaturalBeautyIndex() const {
	return natural_beauty_index;
}


// todo these setters may be problematic...
void destination::setNationstateIdentifier(const char *new_) {
	nationstate_identifier = new char[strlen((new_)) + 1];
	strcpy(nationstate_identifier, new_);
}

void destination::setBestTimeOfYear(const char *new_) {
	best_time_of_year = new char[strlen((new_)) + 1];
	strcpy(best_time_of_year, new_);
}

void destination::setHowToGetThere(const char *new_) {
	how_to_get_there = new char[strlen((new_)) + 1];
	strcpy(how_to_get_there, new_);
}

void destination::setThingsToDo(char** new_, const int size_) {
	things_to_do = new_;
	things_to_do_size = size_;
} // todo only non-const setter...
//void destination::setThingsToDo(const vector<char *> *new_) {
//	things_to_do = new_;
//}

void destination::setNaturalBeautyIndex(const int new_) {
	natural_beauty_index = new_;
}



ostream& operator<<(ostream& os, const destination& ds){ // TODO this is the same as display() but it takes the ostream as an argument :P
	os << "DESTINATION - " << ds.location_name <<", " << ds.nationstate_identifier << endl
	     << "    You should really visit in the " << ds.best_time_of_year << endl << "    It's best to get there by "
	     << ds.how_to_get_there << endl << "    Beauty index: " << ds.natural_beauty_index << "/10" << endl
	     << "    You can do the following activities: " << endl;

	for(auto i = 0; i < ds.things_to_do_size  ; ++i){
		os << "        - " << (ds.things_to_do[i]) << endl;
	}
	return os;
}



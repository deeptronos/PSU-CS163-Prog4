//
// Created by Cole Nemec on 7/14/23.
//

#ifndef SOURCE_TREE_HEADER_HH
#define SOURCE_TREE_HEADER_HH

struct Destination{
	char * location_name;
	char * nationstate_identifier;
	char * best_time_of_year;
	char * how_to_get_there;

	char ** things_to_do;
	int things_to_do_size;

	int natural_beauty_index; // Number representing natural beauty of destination from 1..10
};

template <class ItemType>
struct Node{
//	struct Destination this_destination;
	ItemType data_;
	Node * left;
	Node * right;
};

#endif //SOURCE_TREE_HEADER_HH

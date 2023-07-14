// interface for table
// Created by Cole Nemec

//  table is an abstract data type which uses a binary search tree to store its data. For this project, the data is specifically "Destination" structs.
	//  table's private data is
		// A reference to a destination_name_tree, a binary search tree specified to keep data ordered by the Destination.location_name property of each Node's data.
		// A reference to a destination_beauty_tree, a binary search tree specified to keep data ordered by the Destination.natural_beauty_index property of each Node's data.
	//  table's public methods are
		// table: Constructor
		// ~table: Destructor
		// add: Add data
		// remove: Remove data by Destination name
		// display_by_name: Display all data, in sorted order by Destination name
		// display_by_beauty: Display all data, in sorted order by Destination natural beauty
		// get_data: Retrieve Destination information given a name
		// get_height: Get the height of the binary search tree
		// traverse: calls underlying BST's traverse method. Takes a method visit() as argument to apply to each node in the tree. // TODO implement?


// TODO NEX TIME: finish destination_name_tree implementation, create destination_beauty_tree, create table

#ifndef SOURCE_TABLE_HH
#define SOURCE_TABLE_HH



class table {

};


#endif //SOURCE_TABLE_HH

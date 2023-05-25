### Programming - Goal: Implement a Binary Search Tree (BST) and implement all BST methods recursively.
Our binary search tree is storing "Destination" data. Each Destination has the following properties:
* Name of the location (e.g. Sand Diego)
* State and/or Country (e.g. Sandifornia, USA)
* Best thing to do there (e.g. Lego Land)
* Best time of year to go (e.g. All year)
* How to travel there (e.g. car, plane, boat, walk, bike, etc.)
* One other property of your choice (hashed/concatenated key name?? see my Discussion post from 5/22)

Since we're using a BST, we can elegantly store this data in sorted order! This wasn't so achievable in a hash table.

***
# Programming Data Structure
We're implementing a **table** abstract data type using a binary search tree. The term "table ADT" means we're working with the "value" of the data. Each node is organized by **name**.

We must implement the following methods recursively, using a public "wrapper" function to call the private recursive methods:
1. Constructor
2. Add a new Destination from the client
3. Display all - in sorted order, by Destination's name 
4. Remove by Destination's name 
5. Retrieve the information for a given location (*not* the same as a display method)
6. Destructor
7. Display all - by another property of our choice (e.g. find all the matches for a particular attraction - Where are all the Disneylands in the data?)
8. Determine the height of the tree (used to assist in evaluating the software's performance)

Do we really need to implement the constructor/destructor recursively?? a bit confused about this one


***
# Program Design
* Components:
  * main
  * Entry interface/implementation - associates Destination with SearchKey
    * Destination interface/implementation
    * SearchKey
  * Table interface/implementation
    * BinarySearchTree interface/implementation
      * BinaryNode interface/implementation?
      * BinaryTreeInterface?? (Carrano 15.2.3)
  * Custom exceptions (exception.h)
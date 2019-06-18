#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
    
    // Create an empty vector
    vector<string> names;

    // This does not work because vector is empty
    // names[0] = "Joe";
    
    // Create a vector of 5 elements
    vector<string> names2 = vector<string>(5);
    
    cout << names.capacity() << endl;  // 0
    cout << names2.capacity() << endl; // 5
    
    names2[0] = "Joe";
    names2[1] = "Jill";

	// When vectors run out of space, they double their capacity
	// Below, we are pushing 5 elements in the names vector.
    
    names.push_back("Joe");		// size: 1, capacity: 1
    names.push_back("Jill");	// size: 2, capacity: 2
    names.push_back("Jack");	// size: 3, capacity: 4
    names.push_back("Jane");	// size: 4,	capacity: 4
    names.push_back("John");	// size: 5, capacity: 8
    
	// Print out size and capacity after the last insertion
    cout << names.size() << endl;
    cout << names.capacity() << endl;
    
	// To check if a vector is empty
	cout << names.empty() << endl;
    
	
	// Iterate over vector elements and print them out individually on a line
    for (int i = 0; i < names.size(); i++) {
        // Access individual elements with [], just like with arrays
		cout << names[i] << endl;
    }
    
    
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

// This is to keep track of the number of comparisons
int comp = 0;

// A function that check if two numbers are equal
bool equal (int lhs, int rhs){
    // We increment the number of comparisons
    // each time this function is called
    comp++;
    
    return lhs == rhs;
}

// The search algorithm seen in lectures
// It takes the list of numbers, the value we are
// looking for, and the size of the list
int search(int list[], int value, int size){
    for (int i = 0; i < size; i++) {
        // If we find a match, we immediately return
        // the position of the element that matched
        if (equal(list[i], value)){
            return i;
        }
    }
    
    // If the loop completes, and we have not returned
    // it means that the number we are looking for
    // is not in the list, so we return -1
    return -1;
}

int main(int argc, const char * argv[]) {
    // Instead of reading from the keyboard,
    // all user input will be read from a file
    // called input.txt, found in the same folder
    // as our executable
    ifstream in("search_input.txt");
    
    if (!in.is_open()){
        cout << "Can't find input file" << endl;
        return 1;
    }
    
    // We need to create a const because
    // the size of arrays in C++ is not
    // allowed to change
    const int size = 5;
    
    // Declare an array of the appropriate size
    int numbers[size];
    
    // Read in as many elements as specified
    // and fill up the array
    for (int i = 0; i < size; i++){
        int num;
        in >> num;
        
        numbers[i] = num;
    }
    
    // Now read in the value we are looking for
    int val;
    in >> val;
    
    // Call our search algorithm
    int pos = search(numbers, val, size);
    
    // Print out the number of comparison operations
    // that were performed
    cout << comp << " comparisons performed" << endl;
    
    return 0;
}

#include <iostream>
#include "InsertionSort.h"

using namespace std;

void display(int list[], int size, string message){
    cout << message << endl;
    
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int size;
    cin >> size;
    
    const int len = size;
    
    int numbers[len];
    
    for (int i = 0; i < len; i++) {
        int curr;
        cin >> curr;
        
        numbers[i] = curr;
    }
    
    display(numbers, len, "Before:");
    
    insertion_sort(numbers, len);
    
    display(numbers, len, "After:");
    
  
    
    return 0;
}

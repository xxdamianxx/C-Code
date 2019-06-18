#include <iostream>
#include "FindMin.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int size;
    cin >> size;

    const int len = size;
    
    int numbers[len];
    
    for (int i = 0; i < len; i++) {
        cin >> numbers[i];
    }
    
    int start;
    cin >> start;
    
    int end;
    cin >> end;
    
    int minIndex = findMin(numbers, start, end);
    
    cout << "Smallest number in range (" << start << " - " << end << "): " << numbers[minIndex] << endl;
    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

long binary_search(std::vector<int>& list, int val){
    long n = list.size();
    long lower = 0;
    long upper = n;
    
    while (lower < upper){
        
        long mid = lower + (upper-lower)/2;
        if (list[mid] == val){
            return mid;
        }
        else if (list[mid] < val){
            lower = mid + 1;
        }
        else {
            upper = mid;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    
    cout << binary_search(v, 4) << endl;
    
    cout << binary_search(v, 47) << endl;
    
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    vector<int> arr;
    arr.push_back(10);
    arr.push_back(66);
    arr.push_back(30);
    arr.push_back(88);
    arr.push_back(50);

    // Convert the vector into a heap.
    make_heap(arr.begin(), arr.end());
    
    // Printing the heap
    cout << "Heap after make_heap: ";
    for(int i : arr) {
        cout << i << " ";  // Only first element is guaranteed to be the largest.
    }
    cout << endl;

    // Add a new element to the vector
    arr.push_back(60);

    // Include the new element into the heap
    push_heap(arr.begin(), arr.end());

    // Print the heap after pushing the new element
    cout << "Heap after push_heap: ";
    for(int i : arr) {
        cout << i << " ";  // Again, only the heap property is maintained.
    }
    cout << endl;

    // Pop the largest element (front) and move it to the end
    pop_heap(arr.begin(), arr.end());

    // Remove the last element (which was the largest) from the vector
    arr.pop_back();

    // Print the heap after popping the largest element
    cout << "Heap after pop_heap: ";
    for(int i : arr) {
        cout << i << " ";  // Still maintains heap property.
    }
    cout << endl;


    sort_heap(arr.begin(),arr.end());
    for(int i: arr){
        cout<<i<<" ";
        
    }
}

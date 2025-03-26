#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void selection_sort(vector<int>& a, int min)

int main(){
    ifstream inFile;
    inFile.open("RF1.txt");
    vector<int> v;
    int num;
    int total = 0;

    while(inFile >> num){
        v.push_back(num);
    }

    inFile.close();

    for(int i = 0; i < 10; i++){
    auto start = chrono::high_resolution_clock::now();
    sort(v.begin(), v.end());
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::micro> time_ms = end - start;
    auto int_time = chrono::duration_cast<chrono::microseconds>(time_ms);
    cout << "time taken to sort: " << int_time.count() << "ms" << endl;
    total = total + int_time.count();
    }
    
    total = total/10;

    cout << "average time taken to sort: " << total << "ms" << endl;

    return 0;
}

void selection_sort(vector<int>& a, int min){
    
}
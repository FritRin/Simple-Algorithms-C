#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void selectionSort(vector<int>);

int main(){
    ifstream inFile;
    inFile.open("RF1.txt");
    vector<int> v;
    int num;
    int total = 0;
    int total2 = 0;

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
    
    for(int j = 0; j < 10; j++){
        auto start = chrono::high_resolution_clock::now();
        selectionSort(v);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> Stime_ms = end - start;
        auto sel_time = chrono::duration_cast<chrono::microseconds>(Stime_ms);
        cout << "time taken for selection sort: " << sel_time.count() << "ms" << endl;
        total2 = total2 + sel_time.count();
    }
    
    total = total/10;
    total2 = total2/10;

    cout << "average time taken to sort: " << total << "ms" << endl;
    cout << "average time taken for selection sort: " << total2 << "ms" << endl;

    return 0;
}

void selectionSort(vector<int> a){
    for(int i = 0; i < a.size(); i++){
        int min = i;
        for(int j = i+1; j < a.size(); j++){
            if(a[j] < a[i]){
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}
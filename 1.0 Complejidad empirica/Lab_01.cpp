#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> data;
    int sum = 0;

    cout<<"Amount of numbers"<<endl;
    cin >> n;

    //code to sum n random integers, given in an array DATA
    auto start = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < n; i++){
        data.push_back(rand()%100);
        cout << "data["<<i<<"]: "<< data[i] <<endl;
    }

    for(int i = 0; i < n ; i++){
        sum += data[i];
    }
    auto end = chrono::high_resolution_clock::now();

    /*clock_t end = clock();
    double elapsed_secs = double(end-begin)/ CLOCKS_PER_SEC;*/
    double elapsed_secs = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    //print result
    cout << "The sum is: " << sum<< endl; 
    cout << "Time taken in nanoseconds: " << elapsed_secs<< endl; 
}

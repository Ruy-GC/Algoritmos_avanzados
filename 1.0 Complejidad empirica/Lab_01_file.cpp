#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){

    cout << "You entered "<<argc<<" arguments"<<endl;

    int n;
    vector<int> data;
    int sum = 0;
    int number;

    string fn = argv[1];
    ifstream input_file(fn);

    if (!input_file.is_open()){
        cout<<"Could not open the file - '"<< fn <<"'"<<endl;
        return EXIT_FAILURE;
    }
    
    clock_t begin = clock();

    while(input_file >> number){
        data.push_back(number);
    }

    input_file.close();

    for(int i = 0; i < data.size() ; i++){
        cout << "data["<<i<<"]: "<< data[i] <<endl;
        sum += data[i];
    }

    clock_t end = clock();
    double elapsed_secs = double(end-begin)/ CLOCKS_PER_SEC;
    
    //print result
    cout << "The sum is: " << sum<< endl; 
    cout << "Time taken in seconds: " << elapsed_secs<< endl;

    return 0; 
}

/*
Actividad 4.3 Implementación Randomized Binary Search
Ruy Guzmán Camacho A1639912
14/11/2022
*/
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void printResults(int index){
    if(index != -1){
        cout<<"El elemento esta presente en el indice: "<<index<<endl;
    }else{
        cout<<"El elemento no esta presente en el arreglo"<<endl;
    }
}
int getRandomNumber(int start, int end){
    srand(time(NULL));
    return (start + rand() % (end-start+1));
}

//O(log n) siendo n el tamaño de la lista 
int randomBinarySearch(vector<int> list,int l, int r, int x){
    
    if(r >= l){
        int m = getRandomNumber(l,r);

        if(list[m] == x) return m;

        if(list[m] > x) return randomBinarySearch(list,l,m-1,x);

        return randomBinarySearch(list,m+1,r,x);

    }

    return -1;

}


int main(){
    int n;
    cin>>n;

    string list_commas;
    cin.ignore();
    getline(cin >> std::ws, list_commas);

    stringstream ss(list_commas);

    vector<int> nums ;

    for(int i; ss>> i;){
        nums.push_back(i);
        if (!isdigit(ss.peek())) ss.ignore();
    }

    printResults(randomBinarySearch(nums,0,nums.size()-1,n));
    return 0;
}
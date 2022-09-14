#include <iostream>
#include <vector>

using namespace std;

int longestPalindrome(string string){
    int n = string.length();
    int R = -1; 
    int P = 0;
    bool pair = false;
    vector<char> text;
    if(n%2 == 0) pair = true;

    for(int i = 0; i < string.length();i++){
        text.push_back('#');
        n++;
        text.push_back(string[i]);
    }

    text.push_back('#');
    n++;


    vector<int> A (n,-1);
    
    for(int i = 0; i < n-1;i++){
        if(i <= R){
            A[i] = max(0,min(A[2*P - i], R-i));
        }else{
            A[i] = 0;
        }

        while  (text[i-A[i]-1] == text[i+A[i]+1]){
            A[i] = A[i]+1;
        }

        if(i+A[i] > R) R = i+A[i];

        if(A[i] > A[P]) P = i;
    }
    
    return A[P];
}


int main(){

    
    cout<<"Longest palindrome: "
        <<longestPalindrome("santiago22ababbabaabcbabbcbaabadfdb121092983afedabd17171")
        <<"\n";
    return 0;
}
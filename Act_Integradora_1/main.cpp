//Santiago Gonzalez de Cosio Romero - A01640329
//Brandon Josue Magana Mendoza - A01640162
//Ruy Guzman Camacho - A01639912

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

string getText(string path){
  
  ifstream lector(path);
  string line;
  string text = "";
  while (getline(lector, line)){
            text += line;
        }
        lector.close();

  return text;
}

vector<int> getPreSufVec(string substring){
  
  int len = 0;
  vector<int> preSuf(substring.length());

  int i = 1;
  while(i < substring.length()){
    
    if (substring[i] == substring[len]) {
            len++;
            preSuf[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = substring[len - 1];
            }
            else 
            {
                preSuf[i] = 0;
                i++;
            }
        }
  }

  return preSuf;
}

void KMPAlgorithm(string substring, string text)
{
    int x = substring.length();
    int y = text.length();
 
    vector<int> preSuf(x);

    preSuf = getPreSufVec(substring);
 
    int i = 0;
    int j = 0; 
    bool found; 
    int place;
    while ((y - i) >= (x - j)) {
        if (substring[j] == text[i]) {
            j++;
            i++;
        }
 
        if (j == x) {
            //printf("Found pattern at index %d ", i - j);
            place = i -j;
            found = true;
            j = preSuf[j - 1];
        }
 
        else if (i < y && substring[j] != text[i]) {
            if (j != 0)
                j = preSuf[j - 1];
            else
                i = i + 1;
        }
    }
    if (found == true) {
      cout<<"True"<<" "<<place<<endl;
    }
    else{
      cout<<"False"<<endl;
    }
    
}

void Manacher(string text){
    int n = text.length();
    int R = -1; 
    int P = 0;
    bool pair = false;
    vector<char> textArr;
    if(n%2 == 0) pair = true;

    for(int i = 0; i < text.length();i++){
        textArr.push_back('#');
        n++;
        textArr.push_back(text[i]);
    }

    textArr.push_back('#');
    n++;

    vector<int> A (n,-1);
    
    for(int i = 0; i < n-1;i++){
        if(i <= R){
            A[i] = max(0,min(A[2*P - i], R-i));
        }else{
            A[i] = 0;
        }

        while  (textArr[i-A[i]-1] == textArr[i+A[i]+1]){
            A[i] = A[i]+1;
        }

        if(i+A[i] > R) R = i+A[i];

        if(A[i] > A[P]) P = i;

    }
    
    int longest_pali = *max_element(A.begin(), A.end());
    int lpIndex = max_element(A.begin(), A.end()) - A.begin();

    int index_low = lpIndex - longest_pali;
    int index_high = lpIndex + longest_pali;
    
    int indexL_half = index_low /2;
    int indexH_half = index_high /2;

    index_low = index_low - indexL_half;
    index_high = index_high - indexH_half - 1;
    
    cout<<index_low<<" "<<index_high<<endl;
}

void longestSubstring(string str1, string str2){

    vector<int>row(str1.length()+1,0);
    vector< vector<int> >LCSmatrix (str2.length()+1,row);
    tuple<int,int> longestIndex;
    int longest = 0;

    for(int i = 1; i < str2.length()+1;i++){

        for(int j = 1; j < str1.length()+1;j++){

            if (str1[j] == str2[i]) LCSmatrix[i][j] = LCSmatrix[i-1][j-1] + 1;
            if (LCSmatrix[i][j] > longest){
                longest = LCSmatrix[i][j];
                longestIndex = make_tuple(i,j);
            } 

        }

    }

    cout<<"transmision 1"<<endl;
    cout<<get<1>(longestIndex) +1 - longest<<" "<< get<1>(longestIndex) + 1 <<endl;

}

int main() {
  //KMP para parte 1
  string mcode1 = getText("mcode1.txt");
  string mcode2 = getText("mcode2.txt");
  string mcode3 = getText("mcode3.txt");
  string tr1 = getText("transmission1.txt");
  string tr2 = getText("transmission2.txt");

  cout<<"Parte 1 - Presencia de codigo maligno dentro de la transmision"<<endl;
  cout<<"transmision 1"<<endl;
  KMPAlgorithm(mcode1, tr1);
  KMPAlgorithm(mcode2, tr1);
  KMPAlgorithm(mcode3, tr1);

  cout<<"transmision 2"<<endl;
  KMPAlgorithm(mcode1, tr2);
  KMPAlgorithm(mcode2, tr2);
  KMPAlgorithm(mcode3, tr2);
  cout<<"------------------------------------------------------------------"<<endl;
  //Manacher para parte 2
  cout<<"Parte 2 - Palindromo mas largo dentro de ambas transmisiones"<<endl;
  cout<<"transmision 1"<<endl;
  Manacher(tr1);
  cout<<"transmision 2"<<endl;
  Manacher(tr2);

  cout<<"------------------------------------------------------------------"<<endl;
  cout<<"Parte 3 - Substring compun m??s largo entre archivos de transmisi??n"<<endl;

  longestSubstring(tr1,tr2);
  cout<<"------------------------------------------------------------------"<<endl;

  return 0;
}
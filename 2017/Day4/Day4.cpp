#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include<unordered_map>
using namespace std;
class Day4{
    ifstream fil;
    string line;
    string word;
    int count = 0;
    
    public:
    Day4(){
        cout<<"Reading file "<<endl;
        fil.open("Day4_part2.txt");
        
    }
    void passPhrase(){
        while(!fil.eof()){
            ++count;
            unordered_map<string, int> umap;
            unordered_map<string, int> :: iterator itr;
           
            getline(fil,line);
           // line>>word;
            stringstream wordsplitter(line);
            while(!wordsplitter.eof()){
                wordsplitter>>word;
                sort(word.begin(),word.end());
               // cout<<word<<endl;
                umap[word] = umap[word] + 1;
            }
            for (itr = umap.begin(); itr != umap.end(); itr++) {
                cout << itr->first << "  " << itr->second << endl;
                if(itr->second>1){
                    count = count -1;
                    break;
                }
            }

        
        }
        cout<<"the no.of correct passphrases are "<<count<< endl;
    }

};
int main(){
    Day4 hi;
    hi.passPhrase();
    return 0;
}
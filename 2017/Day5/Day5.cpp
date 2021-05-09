#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class Day5{
    public:
    ifstream files;
    string test;
    int nums=0,count=0;
    string line;
    int *array ;
    Day5(){
        string x;
        cout<<"enter file name \t";
        cin>>x;
        files.open(x);
        cout<<"reading files"<<endl;
        Read_lines();
        Reading_and_creating_array();
       
     
    }
    void Read_lines(){
            while(getline(files,test)){
                ++count;
                               
        }
        array = new int[count];
        files.clear();
        files.seekg(0);
        cout<<"no.of lines "<<count<<endl;
    }
    void Reading_and_creating_array(){
        int i = 0;
        while(!files.eof()){
            getline(files,line);
            stringstream Numi(line);
            Numi>>nums;
            array[i]=nums;
          //  cout<< " i  "<<i << " :"<< array[i]<<endl;
            ++i;
            };
        //cout<<"hi:"<<count<<endl;

    }
    void solving(){
        int j =0,i =0;
        int steps =0;
        while(i<count){
            j = array[i]++;
            i = i + j;
            ++steps;
          //  cout<<"order : "<<j<<"index "<< i  <<endl;


        }
        cout<<"No.of steps for part1 :"<<steps<<endl;
    }
    void solving_2(){
        int j =0,i =0;
        int steps =0;
        while(i<count){
            j = array[i];
            //cout<<"order : "<<j<<"index "<< i  <<endl;
            if(j>=3){
                --array[i];
            }
            else{
                ++array[i];
            }
            i = i + j;
            ++steps;


        }
        cout<<"No.of steps part 2:"<<steps<<endl;

    }

};
int main(){
    
    Day5 obj1;
    obj1.solving();
    Day5 obj2;
    obj2.solving_2();

    return 0;
}
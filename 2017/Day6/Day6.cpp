#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<unordered_map>
using namespace std;
class Day6{
    public:
    int count =0;
    int final_count =0;
    int count_2 = 0;
    int num_part2=0;
    ifstream file;
    string line;
    int array[100] = {0};
    int stringify =0;
    int i =0;
    int time=1;
    bool found =false;
    Day6(){
        cout<<"Reading the file"<<endl;
        file.open("Day6.txt");
        Reading();
        show();
        calculate();
    }
    void Reading(){
        while(!file.eof()){
            getline(file,line);
            stringstream helo(line);
            while(!helo.eof()){
                
                helo>> array[i];
                i++;
            }
        }
        cout<<"size of array input"<<i<<endl;
    }
    void show(){
        for(int j =0;j<i;j++){
            cout<<array[j]<<"\t";
        }cout<<endl;
    }
    void calculate(){

        
        unordered_map<int,int> umap;
        unordered_map<int ,int> :: iterator itr;
        int timessss = 50;
           // cout<<endl<<number<<"\t "<<index<<endl;
         while(!found ){
        int  highest = array[0];
        int highest_index = 0;
        for(int k =0;k<i;k++){
            if(array[k]>highest){ 
            highest = array[k];
            highest_index =k;
            }
            else{
            continue;
            }

        }
        //    int  * arr = find_biggest();
            int number = highest;
            int index = highest_index;
            cout<<"number "<<number<<"index"<<index<<endl;
            array[index] = 0;
            for(int l =++index;number>0;l++){
              //  cout<<"index : "<<index<<endl;
                    if(l>i-1){
                       // cout<<"in there "<<l<<endl;
                        l=0;
                        index=0;
                        array[l] = array[l]+1;
                        number--;
                    }
                    else{
                     //   cout<<"noob "<<l<<endl;
                        array[l] = array[l]+1;
                        number--;
                    }
            } 
            //show();
            ////STRINGYFY ARRAY////
            for(int l =0;l<i;l++){
                stringstream ss;
                ss <<array[l];
                int h =0;
                ss>>h;
                stringify = stringify*10+ h;
            }
          cout<<"sss : "<<stringify<<endl;
            umap[stringify] += 1 ; 
            
          

        
        ++count;
        if(umap[stringify] == 2 && (time!=0)){
            final_count = count;
            num_part2 = stringify;
            time--;
            cout<<"time "<<time<<"finalcount " <<final_count<<endl;
        }
        if(final_count){
            count_2++;
        }
        if(stringify == num_part2 && umap[stringify]==3){
            cout<<"NO.OF Redistribution cycles happened :"<<final_count<<"time"<<time<<endl;
            cout<<"NO.OF Redistribuiton cycles happended for part2 "<<count_2-1<<endl;
            found = true;
            break;

        }
        stringify = 0;
        }
        
        }
        
};
int main(){
    Day6 obj;
    return 0;
}
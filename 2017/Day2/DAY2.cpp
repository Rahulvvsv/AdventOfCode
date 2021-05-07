#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
class Day2{
	public:
	int final_result =0;
	int final_result_division=0;
	
	ifstream fin;
	string line;
	Day2(string s){
		fin.open(s);
		cout<<"file is being read"<<endl;
	}
	int matrix[18][18];
	int i,j;
	void Reading2(){
		i=0;
		do{
		j=0;
		int temp_res;
		getline(fin,line);
		stringstream ssin(line);
		int x =0;
		do{
		ssin >> matrix[i][j];
			j=j+1;
			//cout<<"wo"<<j<<endl;
			}
		while(!ssin.eof());
		i = i +1;
		//cout<<"i"<<i<<endl;
	}
	while(!fin.eof());}
	void show(){
	//cout<<"he"<<endl;
	for(int i =0;i<16;i++){
			int temp_result,max,min;
			max=matrix[i][0] ; min = matrix[i][0];
			for(int j =0;j<16;j++){
				int numi = matrix[i][j];
				//cout<<"n"<<numi<<endl;
				if(numi <= min){
				min = numi;
				
				}
				if(numi > max){
				max = numi;
				}
				
				cout<<matrix[i][j]<<"\t";
			}
			temp_result = max - min;
			final_result  = final_result + temp_result;
			cout<<"\t"<<"max: "<<max<<"\t"<<"min "<<min <<"\t"<<"temp result "<< temp_result<<"\t"<< "final_Result:"<<final_result;
			cout<<endl;
		}
		}
		
		//////////////PART2///////////////////////
	void divisible(){
	
			for(int i =0;i<16;i++){
			int temp_result,divisor,dividend;
			bool found = false;
			
			for(int j =0;j<16;j++){
				int numi = matrix[i][j];
					for(int k=j+1;k<16;k++){
						int new_num = matrix[i][k];
						if(new_num%numi ==0){
							divisor=numi;
							dividend = new_num;
							found = true;
							break;
							 
						}
						if(numi%new_num ==0){
							divisor = new_num;
							dividend = numi;
							found = true;
							break;
						}
						else{
							continue;
						}
						
					}
				
				if(found){
					break;
				}
				//cout<<matrix[i][j]<<"\t";
			}
			temp_result = dividend/divisor;
			final_result_division  = final_result_division + temp_result;
			cout<<"\t"<<"divisor: "<<divisor<<"\t"<<"dividend "<<dividend <<"\t"<<"temp result "<< temp_result<<"\t"<< "final_Result:"<<final_result_division<<endl;
		}
	
	
	}
	};
int main(){
Day2 hello("DAY2.txt");
hello.Reading2();
cout<<"are you workign:"<<endl;
hello.show();
cout<<"final_result "<< hello.final_result<<endl;
cout<<endl<<"///////////////part2////////////////////"<<endl;
/////part2
Day2 part("DAY2_part2.txt");
part.Reading2();
part.show();
part.divisible();
cout<<"final result "<<part.final_result_division;

return 0;
}


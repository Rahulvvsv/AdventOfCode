	void Reading(){
		while(!fin.eof()){
			int temp_res;
			 fin>> line;
			 cout<<line<<endl;
			// cout<<int(line[0]) -48<<endl;
			//cout<<  line[0] << endl;
			//cout<<(line.length() )<<endl;
				
			int least = int(line[0]) - 48  ;
			int max = int(line[0]) - 48;
			for(int  i =0; i < line.length();i++){
				if(int(line[i]) -48 < least){
					least =  int(line[i])-48;
					cout<<"l"<<least<<endl;
					continue;	
				}
				if(int(line[i])-48 >max){
					max =  int(line[i])-48;
					cout<<"m"<<max<<endl;
					continue;
				}
				
					
				
			}
			temp_res = max - least;
					final_result = final_result + temp_res;
					cout<<"temp = "<<temp_res<<endl<<"final = "<<final_result<<endl;
				
		}
		cout<<"The final answer is "<<final_result<<endl;
	

	}

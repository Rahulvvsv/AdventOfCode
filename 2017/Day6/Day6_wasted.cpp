    for (itr = umap.begin(); itr != umap.end(); itr++) {
            //cout << itr->first << "  " << itr->second <<"  count: "<<count << endl;
            if(itr->second == 2 && (time!=0)){
                final_count=count;
               // cout<<"NO.OF Redistribution cycles happened :"<<count<<endl;
               num_part2 = itr->first;
                count_2++ ;
                time--;
            }
          
            if(itr->first==num_part2 && itr->second ==3 ){
                found = true;
                cout<<"NO.OF Redistribution cycles happened :"<<final_count<<"time"<<time<<endl;
                cout<<"NO.OF Redistribuiton cycles happended for part2 "<<count_2<<endl;
                break;
                
            }

            
        }
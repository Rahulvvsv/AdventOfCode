#include<iostream>
#include<cmath>
using namespace std;
class Day3{
    public:
    int x;
    int d;
    float  ints;
    int ** matrix  ;
    int ** matrix_2;
    int original;
    int dimension;
    int location_out[2];
    int location_num[2];
    Day3(){
        cout<<"Enter the nuber: "<<endl;
        cin>>x;
        original = x;
    }
    
   
    int find_dimension(){
        float num = sqrt(x);
        float decimal = modf(num,&ints);
        if(decimal){
            d = ints  + 1 ;
            x = d*d;           
        } 
        else{

            d = num;
            if(d%2 == 0){
                d = num+1;
                x = d*d;
            }
            
        }
        return d;
    }
    void construct_matrix(){
        dimension = find_dimension();
        matrix = new  int*[dimension];
        cout<<"dimension: "<<dimension<<endl;
        int level = dimension;
        bool already_started = false;
        int starting_index_i ;
        int starting_index_j;
        int ending_index_j;
        int ending_index_i;
        int count = x;
        ///constructing a empty matrix
        for(int i =0;i<dimension;i++){
            matrix[i] = new int[dimension];
        }
        //Before initialing array
        //show();
        cout<<"empty matrix created;"<<endl;;
       while(level > 0){
            if(!already_started){
                if(dimension%2==0) {
                    starting_index_i = 0;
                    starting_index_j = 0;
                    ending_index_i=dimension;
                    ending_index_j= dimension;

                      already_started = true;
                }
                if(dimension%2 != 0){
                    starting_index_i = dimension-1;
                    starting_index_j = dimension-1;
                    ending_index_i=0;
                    ending_index_j=0;
                    already_started = true;
                }
            }
            if(level%2 == 0){
                int j;
                int i ;
                for( i = starting_index_i;i<ending_index_i;i++){
                    if(i == starting_index_i){
                        for( j = starting_index_j;j<ending_index_j;j++){
                            matrix[i][j] = count--;
                          
                        }
                        j--;
                      
                    }
                    else{
                        matrix[i][j] = count--;
                       
                    }
                }
                i--;
                starting_index_i =i;
                starting_index_j = j-1;
                ending_index_i = dimension - i-1;
                ending_index_j = dimension - j;
                level = level -1;
            }
            if(level%2 != 0){
                int j,i ;
                for( i = starting_index_i;i>=ending_index_i;i--){
                    if(i == starting_index_i){
                        for( j = starting_index_j;j>=ending_index_j;j--){
                                matrix[i][j] = count--;
                        }
                        j++;
                    }
                    else{
                        matrix[i][j] = count--;
                    }
                }
                i++;
                starting_index_j = j+1;
                starting_index_i = i;
                ending_index_i = dimension -i-1;
                ending_index_j = dimension -j;
                level = level-1;

            }
        
            
        }   
        
    }
    void show(){
            cout<<"printing matrix"<<endl;
             for(int i =0;i<dimension;i++){
            for(int j =0;j<dimension;j++){

                cout<<matrix[i][j]<<"\t";
                
            }cout<<endl;
            }

    }
    void show2(){
            cout<<"printing matrix"<<endl;
             for(int i =0;i<dimension;i++){
            for(int j =0;j<dimension;j++){

                cout<<matrix_2[i][j]<<"\t";
                
            }cout<<endl;
            }

    }
    void find_manhattan_distance(){
        
        
        cout<<"original :"<<original<<endl;
        for(int i =0;i<dimension;i++){
            for(int j =0;j<dimension;j++){
                if(matrix[i][j] == 1){
                    location_out[0] = i;
                    location_out[1] = j;
                }
                if(matrix[i][j] == original){
                   
                    location_num[0] = i;
                    location_num[1] = j;
                }
                
            }
            }
        cout<<"x_1: "<<location_out[0]<< " x_2: "<<location_num[0]<<endl;
        cout<<"x_2: "<<location_out[1]<< " y_2: "<<location_num[1]<<endl;
        cout<<((location_out[0]-location_num[0]))<<endl;
        cout<<((location_out[1]-location_num[1]))<<endl;

        int x_dist = abs((location_out[0]-location_num[0]));
        int y_dist = abs((location_out[1]-location_num[1]));
        cout<<"manhattan distance is: "<< (x_dist+y_dist)<<endl;

    }
    /////PART2/////
    bool found = false;
    int  neighbors[8][2];
    void set_neighbots(){
        for(int i =0;i<8;i++){
            for(int j =0;j<2;j++){
                neighbors[i][j] = 0;
              //  cout<<neighbors[i][j];
            }
        }
    }
   
    void find_num_great_original(){
        matrix_2 = new  int*[dimension];
        for(int i =0;i<dimension;i++){
            matrix_2[i] = new int[dimension];
        }
        
            
            int visited_array[original]= {0}; 
            
            int k =0;
            int times = 15;
            
        ///traversal///
            int pos_x = location_out[0];
            int pos_y = location_out[1]+1;
            matrix_2[location_out[0]][location_out[1]] = 1;
            int pos_next_x;
            int pos_next_y;
            visited_array[1] = 1;
            while(!found ){
              //  show();
                k=0;
                set_neighbots();
               // cout<<"posx"<<pos_x<<"posy"<<pos_y<<endl;
                    for(int l =-1;l<=1;l++){
                        for(int m = -1;m<=1;m++){
                            if(l==0 && m==0){
                                  continue;
                                }
                            if(pos_x+l < dimension && pos_y+m<dimension && pos_y+m>=0 && pos_x+l>=0){
                                  neighbors[k][0] = pos_x+l;
                                    neighbors[k][1] = pos_y+m;
                                 //  cout<<"k"<<k<<endl;
                                  // cout<<"i :" <<l <<" j "<<m<<endl;
                                   // cout<<"neigh ;"<<neighbors[k][0]<<"  "<<neighbors[k][1]<<endl;
                                    k++;
                            }
                        }
                    }
                
               int result =0;
           //    int  matrix_prev_value = matrix[pos_x][pos_y];
               int matrix_n_val=0;
               int matrix_n_val2=0;
                visited_array[matrix[pos_x][pos_y]] =1;
                for(int i =0;i<k;i++){
                    matrix_n_val = matrix[neighbors[i][0]][neighbors[i][1]];
                     matrix_n_val2 = matrix_2[neighbors[i][0]][neighbors[i][1]];
                 //   cout<<"matrix_n_val "<<matrix_n_val<<" matrix pos value"<<matrix[pos_x][pos_y]<<endl;
                   // cout<<"matrix_n_value:"<<matrix_n_val<<endl;
                    if(visited_array[matrix_n_val] == 1){
                     //   cout<< "posx x"<<neighbors[i][0]<<"posy "<<  neighbors[i][1]<<endl;
                        result= result + matrix_n_val2;
                     
                      //   cout<<"result: "<<result<<endl;
                      
                    }
                    
                    if((matrix_n_val) - (matrix[pos_x][pos_y]) == 1){
                        pos_next_x = neighbors[i][0];
                        pos_next_y = neighbors[i][1];
                        //cout<<"pos next y"<<pos_next_y<<endl;


                }
                }
                matrix_2[pos_x][pos_y] = result;
            
     
            if(result > original){
                cout<<"result of number greater than original :" <<result<<endl;
                found = true;
                break;
            }
            pos_x = pos_next_x;
            pos_y = pos_next_y;
            
            

        }
        cout<<endl;
        cout<<"visited array:     ";
        for(int i =0;i<original;i++){
          //  cout<<visited_array[i]<<"\t";
        }      
    }




};





int main(){
    Day3 sq;
    sq.construct_matrix();
 //  sq.show();
   sq.find_manhattan_distance();
   sq.find_num_great_original();
  // sq.show2();
    return 0;
}
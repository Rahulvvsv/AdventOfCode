int dd = find_dimension();
        float half_size = float(dd)/2;
        cout<<dd<<endl<<half_size<<endl;
        //Created Square of size d
        for(int i =0;i<dd;i++){
            matrix[i] = new int[dd];
        }
        //NOw constructing matrix needed;
        for(int i =0;i<dd;i++){
            for(int j =0;j<dd;j++){
                if(j==i){
                    if(j<half_size){
                        matrix[i][j] = (2*dd) - j-i-1;
                    }
                    if(j>half_size){
                        matrix[i][j] = (2*dd) + j+i-1;
                    }
                    if(i == dd/2 && j == dd/2){
                        matrix[i][j] =1;
                    }

                }
                if(j<i){
                    matrix[i][j] = (2*dd) + j+i-1;
                }
                if(j>i){
                    matrix[i][j] = (2*dd) - j- i-1;
                }
                cout<<matrix[i][j]<<"\t";

            }
with open("day1.txt","r") as x :
    lines = x.readlines()
    count =0
    current = 0
    prev =0
    data = []
    for line in lines:
    #    print(line,end=" ")
       data.append(int(line[0:-1]))
    
    #    print(line[0:-1],line,"hi")
    for i in range(len(data)-3):
        current = 0
        current += data[i]
        for j in range(1,3):
            if i+j < len(data):
                print(str(data[i+j])+" hello")
                current += data[i+j]
                # print(current,"ciree")

        if current>prev:
            count +=1
        print(current,prev)
        prev = current
        

    print(count)
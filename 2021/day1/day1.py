data  = []
with open("day1_test.txt","r") as x :
    lines = x.readlines()
    count =-1
    current = 0
    prev =0
    for line in lines:
    #    print(line,end=" ")
       current = int(line[0:-1])
       if(current>prev):
           count += 1
       prev = current
    #    print(line[0:-1],line,"hi")
    print(count)


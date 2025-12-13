import numpy as np
r=int(input("Enter order: "))
# c=int(input("Enter columns: "))
arr=np.zeros([r,r],int)
f=0
for i in range(r):
    for j in range(r):
        arr[i][j]=int(input("Enter the number: "))
for i in range(r):
    for j in range(r):
        if(i==j and arr[i][j]==1):
            f=f+1
        if(i!=j and arr[i][j]!=0):
            continue
        else:
            break        
if(f==r):
    print("Identity Matrix")
else:
    print("Not Identity Matrix")    
a=int(input("enter a no."))
c=0
for i in range(2,a):
    if(a%i==0):
        c=1
        break
if(c==0):
    print("it is a prime no.")
else:
    print("it is not a prime no.")
                

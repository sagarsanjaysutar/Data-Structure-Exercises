print ("PE-1")
sum=0
y=5
z=3
x=False
for i in range(1000):
	if(i%y==0):
		x=True 
		print(i)
		sum=sum+i
		
	if(i%z==0 and x==False):
		print(i)
		sum=sum+i
	x=False		
print(sum)
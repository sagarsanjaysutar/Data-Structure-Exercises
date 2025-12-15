print ("PE.4")
def checkPalindrome():	
	final=[]
	for i in range (100,1000):
		for j in range (100,1000):
			mul=i*j
			temp=mul
			sum=0
			rem=0
			while temp!=0:
				rem=temp%10
				sum=(sum*10)+rem
				temp=temp/10
			if(sum==mul):
				final.append(sum)
	final.sort(reverse=True)
	print('The largest palindrome made from the product of two 3-digit numbers,',i,'x',j,'=',final[0])

checkPalindrome()
    
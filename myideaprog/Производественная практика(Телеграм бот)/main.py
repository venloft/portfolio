import numpy
import numpy as np
from numpy import linalg as LA
import random


def main():
	print('Start')
	n=int(input("Razmer "))
	
	a = numpy.zeros((n, n))
	maxmatr = numpy.zeros((n, n))
	#lowerBound = int(input("Введите нижнюю границу. "))
	#upperBound = int(input("Введите верхнюю границу. "))
	#for p in range(3600):
	max=0
	p=0
	for p in range (10000):
	 p+=1
	 for i in range(n): 
	   for j in range(n):
	    a[i][j] = random.randint(1, n*n)  
	    if LA.det(a)>max:
	     max=LA.det(a)
	     for i1 in range(n): 
	       for j1 in range(n):
	        maxmatr[i1][j1] = a[i1][j1] 
	print(maxmatr)
	print(max)



if __name__ =='__main__':
	main()
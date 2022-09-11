import math

from django.shortcuts import render
from django.http import HttpResponse
import numpy as np
import sys
import random
from random import randint
from numpy import linalg as LA
# Create your views here.
from math import comb
r = 0

spis=list()
iter1=0



def is_prime(k):
    if k > 1:
        for i in range(2, int(pow(k, 0.5))+1):
            if (k % i) == 0:
                return 'Нет'
                break
        else:
            return 'Да'

    else:
        return 'Нет'


def primfacs(n):
   i = 2
   primfac = []
   while i * i <= n:
       while n % i == 0:
           primfac.append(int(i))
           n = n / i
       i = i + 1
   if n > 1:
       primfac.append(int(n))
   return primfac


def perfect_number(n):
    sum = 0
    for x in range(1, n):
        if n % x == 0:
            sum += x
    if sum == n:
        return 'Да'
    else:
        return 'Нет'


def chet(n):
    if n % 2 == 0:
        return 'Четно'
    else:
        return 'Нечетно'

def radix(n):
    d=len(str(n))
    return d

def sumdig(a):
    result = 0
    while a > 0:
        result += a % 10
        a //= 10
    return result



def index(request):
    return render(request,'main/index.html')



def zadchisla(request):
    return render(request, 'main/zadchisla.html')

def zadmatr(request):
    return render(request, 'main/zadmatr.html')

def zadcomb(request):
    return render(request, 'main/zadcomb.html')

def matr(request):
    n = 1
    global r
    flag=False
    det=''
    if request.method == "POST":
        d = request.POST.get('tex')
        n=''
        if not request.POST.get('tex'):
            d = r
            n = 1
        #print(d)
        matr = list()
        for i in range(1, int(d)+1):
            temp = []
            for j in range(1, int(d)+1):
                    n=request.POST.get(str(i)+','+ str(j))
                    print(n)
                    if n is None:
                        n=0
                        temp.append(n)
                        flag=False

                    else:
                        if len(n)==0:
                            n=0
                            temp.append(n)
                            flag=True
                        else:
                            temp.append(int(n))
                            flag = True

            matr.append(temp)
            n=i

        r=n
        if flag==False:
            det=''
        else:
           # print(matr)
            matr1= np.array(matr)

            det=int(np.linalg.det(matr1))
    rows = np.zeros((n, n))
    return render(request, 'main/matr.html', {'rows': rows,'n': n,'det': det})


def comb(request):
    num = ''
    n='0'
    m='0'
    res=''
    if request.method == "POST":

       num = request.POST.get('numb')
       if len(num) == 0:
           n=request.POST.get('n')
           m=request.POST.get('m')
       else:
           num = int(num)

           if len(request.POST.get('n')) != 0 and len(request.POST.get('m')) != 0:
            n = int(request.POST.get('n'))
            m = int(request.POST.get('m'))

            if m > n:
               n = ''
               m = ''
            else:
                if num == 1:
               #  n! / (n-m)!
                    res = 1
                    for i in range(n-m,n+1):
                        res=res*i

                elif num == 2:
                # n^m
                    res=n**m
                elif num == 3:
                # n!
                    res = 1
                    for i in range(1,n+1):
                        res=res*i

                elif num == 4:
                    res = math.comb(n,m)
               # n! / (m!(n-m)!)
                elif num == 5:
                    ress1=1
                    ress2=1
               # (n+m-1)! / (m!(n-1)!)
                    for i in range(1, m+1):
                        ress1=ress1*i
                    for i in range(n, n+m):
                        ress2 = ress2 * i
                    res=int(ress2/ress1)


    return render(request, 'main/comb.html',{'res'+str(num):res,'n':n,'m':m,'num':num})

def digsumm(request):
    r=''
    r1=1
    r2=10
    if request.method == "POST":

        r1 = request.POST.get('1')
        r2 = request.POST.get('2')
        if len(r1) == 0 or len(r2) == 0 or int(r2) > 1000000 - 1 or int(r1) > int(r2):
            r1=1
            r2=10
        else:
            r1 = int(r1)
            r2 = int(r2)
            if (r2-r1+1)%2==0:
                r = int((r2-r1+1) / 2) * (r1 + r2)
            else:
                r = (int((r2-r1) / 2)) * (r1 + r2) + (r2+r1)/2


    return render(request, 'main/digsumm.html',{'r':r,'r1':r1,'r2':r2})

def palin(request):
    n=''
    d=''
    color=''
    if request.method == "POST":
        d = request.POST.get('pal')
        if len(d)==0:
            n = 'Пустая'
            color = 'red'
        else:
            reversed_string = ''.join(reversed(d))
            if reversed_string == d:
                n = 'Является палиндромом'
                color = 'green'
            else:
                n = 'Не является палиндромом'
                color = 'red'
    return render(request, 'main/palin.html',{'n': n,'d': d,'color': color})

def gen(request):
    st=''
    global iter1
    min=1
    max=10
    if request.method == "POST":
        min = request.POST.get('1')
        max = request.POST.get('2')
        if max==min or len(max)==0 or len(min)==0 or int(max)>100000-1 or int(min)>int(max):
            st='Некорректный ввод'
            iter1 = 0
            return render(request, 'main/gen.html',{'st':st,'min': min,'max': max,})
        d=request.POST.get('result1')


        if  d == 'Создать список чисел':
            l = list(range(int(min), int(max)))

            random.shuffle(l)
            for i in l:
                st=st+str(i)+' '
            iter1 = 0
        d = request.POST.get('result2')
        if d == 'Выводить числа по одному':


            global spis

            if iter1 == 0:

                spis=list(range(int(min), int(max)))
                random.shuffle(spis)
                st = spis[iter1]
                iter1 = iter1+1
            else:
                print(min)
                print(iter1)
                if int(min)+iter1 > int(max)-1:
                    st = "Конец"
                    iter1=0
                    return render(request, 'main/gen.html', {'st': st, 'min': min, 'max': max})
                else:
                    st = spis[iter1]
                    iter1 = iter1 + 1

    return render(request, 'main/gen.html',{'st':st,'min': min,'max': max})

def chislo(request):
    d=randint(0, 10000)

    if request.method == "POST":
        d = request.POST.get('chisl')
        if len(d)==0 or int(d)>10000000:
            d=1

    ans = list()
    ans.append(radix(int(d)))
    ans.append(is_prime(int(d)))
    ans.append(perfect_number(int(d)))
    ans.append(primfacs(int(d)))
    ans.append(chet(int(d)))
    ans.append(sumdig(int(d)))

    return render(request, 'main/chislo.html',{ 'n0': ans[0],
                                                'n1': ans[1],
                                                'n2': ans[2],
                                                'n3': ans[3],
                                                'n4': ans[4],
                                                'n5': ans[5],
                                                'chisl': d,
                                                })
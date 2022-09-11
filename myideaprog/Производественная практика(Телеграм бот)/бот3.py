import telebot
from telebot import apihelper
import numpy
import numpy as np
from numpy import linalg as LA
import random


token = '1829115054:AAE85LAr6g_M9rj-paRszxFwTSZKr9IKZOM'

bot = telebot.TeleBot(token)
pali=0
prost=0


def prime(number):
    n = number
    counter = 0
    for i in range(1, n + 1):
        if n % i == 0:
            counter += 1
    return 'Простое число' if counter == 2 else 'Составное число'


def palindrome(data):
    data = data.replace(' ','').lower()
    return 'Палиндром' if data == data[::-1] else 'Не палиндром'



def opr(n):
     a = numpy.zeros((n, n))
     maxmatr = numpy.zeros((n, n))
     max=0
     p=0
     for p in range (10000):
        for i in range(n): 
         for j in range(n):
          a[i][j] = random.randint(1, n*n)  
          if LA.det(a)>max:
           max=LA.det(a)
           for i1 in range(n): 
               for j1 in range(n):
                maxmatr[i1][j1] = a[i1][j1] 
     return max
def opr1(n):
     a = numpy.zeros((n, n))
     maxmatr = numpy.zeros((n, n))
     max=0
     p=0
     for p in range (20000):
        for i in range(n): 
         for j in range(n):
          a[i][j] = random.randint(1, n*n)  
          if LA.det(a)>max:
           max=LA.det(a)
           for i1 in range(n): 
               for j1 in range(n):
                maxmatr[i1][j1] = a[i1][j1] 
     return maxmatr


@bot.message_handler(commands=['start'])
def start_message(message):
    bot.send_message(message.chat.id, 'Подсчитать макс определитель /matr')
    bot.send_message(message.chat.id, 'Определить ли палиндром это число /pal')
    bot.send_message(message.chat.id, 'Определить является ли число простым /prost')
    bot.send_message(message.chat.id, 'Автор: /a')
    keyboard = telebot.types.ReplyKeyboardMarkup(True)
    keyboard.row('/matr', '/pal','/prost')
    bot.send_message(message.chat.id, 'Привет!', reply_markup=keyboard)

@bot.message_handler(commands=['pal'])
def pal_message(message):
    bot.send_message(message.chat.id, text="Введите число")
    global pali
    pali=1


@bot.message_handler(commands=['prost'])
def pal_message(message):
    bot.send_message(message.chat.id, text="Введите число")
    global prost
    prost=1


@bot.message_handler(commands=['matr'])
def matr_message(message):
    markup = telebot.types.InlineKeyboardMarkup()
    markup.add(telebot.types.InlineKeyboardButton(text='2*2', callback_data=2))
    markup.add(telebot.types.InlineKeyboardButton(text='3*3', callback_data=3))
    markup.add(telebot.types.InlineKeyboardButton(text='4*4', callback_data=4))
    bot.send_message(message.chat.id, text="Размер матрицы", reply_markup=markup)

@bot.message_handler(commands=['a'])
def help(message):
    bot.send_message(message.chat.id, 'Огорелков Артем ИП-813')


@bot.message_handler(content_types=['text'])
def send_text(message):
    global pali
    global prost
    print(pali)
    if pali == 1:
        if 'Палиндром'==palindrome(message.text):
         bot.send_message(message.chat.id, 'Это палиндром')
         pali=0
        else:
         bot.send_message(message.chat.id, 'Это не палиндром!')
         pali=0
    elif prost == 1:
        if 'Простое число'==prime(int(message.text)):
         bot.send_message(message.chat.id, 'Это простое число')
         prost=0
        else:
         bot.send_message(message.chat.id, 'Это составное число')
         prost=0
    

@bot.callback_query_handler(func=lambda call: True)
def query_handler(call):

    bot.answer_callback_query(callback_query_id=call.id, text='Выбор сделан')
    answer = ''
    if call.data == '3':
     answer = 'Матрица: \n'+str(opr1(int(call.data)))+'\nОпределитель: '+str(opr(int(call.data)))
    elif call.data == '4':
     answer = 'Матрица: \n'+str(opr1(int(call.data)))+'\nОпределитель: '+str(opr(int(call.data)))
    elif call.data == '2':
     answer = 'Матрица: \n'+str(opr1(int(call.data)))+'\nОпределитель: '+str(opr(int(call.data)))
    bot.send_message(call.message.chat.id, answer)
    bot.edit_message_reply_markup(call.message.chat.id, call.message.message_id)

bot.polling()
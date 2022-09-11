import telebot

token='1829115054:AAE85LAr6g_M9rj-paRszxFwTSZKr9IKZOM'
bot= telebot.TeleBot(token)

keyboard = telebot.types.ReplyKeyboardMarkup(True)
keyboard.row('Найти максимальный определитель','Определить ли палиндром это')

otvet = types.InlineKeyboardMarkup(row_width=2)
button1 = types.InlineKeyboardButton("Повторящиеся", callback_data='good')
button2 = types.InlineKeyboardButton("Неповторящиеся", callback_data='bad')
otvet.add(button1,button2)

@bot.message_handler(commands = ['start'])
def answer(message):
	bot.send_message(message.chat.id,'Привет, выбери то что нужно сделать?',reply_markup= keyboard)

#@bot.message_handler(content_types = ['text'])	
def menu2(message):
	
		bot.send_message(message.chat.id, 'Введите размер матрицы')
		if message.text.isnumeric()==True:
			m=int(message.text)
			bot.send_message(message.chat.id, 'размер матрицы '+ str(m))


def menu3(message):
	#@bot.message_handler(content_types = ['text'])	
	bot.send_message(message.chat.id, 'Введите размер матрицы')
	if message.text.isnumeric()==True:
		m=int(message.text) 
		bot.send_message(message.chat.id, 'размер матрицы '+ str(m))

#@bot.message_handler(content_types = ['text'])	
def menu(message):
		keyboard=telebot.types.ReplyKeyboardMarkup(True)
		keyboard.row('Да','Нет')
		bot.send_message(message.chat.id, 'Элементы матрицы повторяются?', reply_markup=keyboard)
		keyboard = telebot.types.ReplyKeyboardRemove()
		#if message.text=='Да':
				
		#if message.text=='Нет':
				

@bot.message_handler(content_types = ['text'])	
def main(message):
	 
	msg=message.text
	if msg == 'Найти максимальный определитель':
		keyboard = telebot.types.ReplyKeyboardRemove()	
		bot.send_message(message.chat.id, 'Введите размер матрицы')
		if message.text.isnumeric()==True:
			m=int(message.text)
			bot.send_message(message.chat.id, 'размер матрицы '+ str(m))

		#menu()
	else:
		bot.send_message(message.chat.id, 'Не понял')





bot.polling(none_stop =True)
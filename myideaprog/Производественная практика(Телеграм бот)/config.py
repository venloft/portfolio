from telegram import Bot
from telegram import Update
from telegram import KeyboardButton
from telegram import ReplyKeyboardMarkup
from telegram.ext import Updater
from telegram.ext import CallbackContext
from telegram.ext import MessageHandler
from telegram.ext import Filters
import sys


button_help = 'Помощь'

def button_help_handler(update: Update, context: CallbackContext):
	update.message.reply_text(
		text='Помощь',
		reply_markup=ReplyKeyboardRemove(),
	)

def message_handler(update: Update, context: CallbackContext):
	text = update.mesage.text
	if text == button_help:
		return button_help_handler(update=update,context=context)

	reply_markup= ReplyKeyboardMarkup(
		keyboard=[
			[
				KeyboardButton(text=button_help),
			],
		],
		resize_keyboaed=True,
	)
	update.message.reply_text(
		text="Привет!",
		reply_markup=reply_markup,
	)

def main():
	updater = Updater(
		token='1789418065:AAE0Wdo9Gtdi72vR8DMEnoo9LP1y6Za5KlY',
		use_context=True,
		)
	print(updater.bot.get_me())
	updater.dispatcher.add_handler(MessageHandler(filters=Filters.all, callback=message_handler))


	updater.start_polling()
	updater.idle()



if __name__ =='__main__':
	main()

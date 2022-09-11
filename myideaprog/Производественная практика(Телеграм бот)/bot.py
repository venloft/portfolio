from telegram import Update, InlineKeyboardButton, InlineKeyboardMarkup
from telegram.ext import Updater, MessageHandler, CommandHandler, Filters, CallbackQueryHandler


CALLBACK_GOOD = "good"
CALLBACK_BAD = "bad"

GOOD_STICKER = "CAACAgIAAxkBAAJX_16nCRx3_yNcHjGJJ8UkEk62o0MTAAIXAAN_gBAunKNhxU-S6OIZBA"
BAD_STICKER = "CAACAgIAAxkBAAJYAV6nCSUZKTelneyyMG6wcXKM5u4VAAImAAN_gBAuCDLXyOyP3gYZBA"


def generate_keyboard():
    keyboard = [
        [InlineKeyboardButton("Палиндром", callback_data=CALLBACK_GOOD),
         InlineKeyboardButton("Нахождение максимального определителя", callback_data=CALLBACK_BAD)]
    ]

    return InlineKeyboardMarkup(keyboard)

def generate_keyboard1():
    keyboard = [
        [InlineKeyboardButton("С неповторяющимся элементами", callback_data=CALLBACK_GOOD),
         InlineKeyboardButton("С повторяющимся элементами", callback_data=CALLBACK_BAD)]
    ]

    return InlineKeyboardMarkup(keyboard)



def keyboard_regulate(update: Update, context):
    query = update.callback_query
    current_callback = query.data

    chat_id1 = update.effective_message.chat_id

    query.edit_message_text(
        text=update.effective_message.text
    )

    if current_callback == CALLBACK_GOOD:
        context.bot.send_sticker(
            chat_id=chat_id1,
            sticker=GOOD_STICKER
        )

    elif current_callback == CALLBACK_BAD:
        context.bot.send_sticker(
            chat_id=chat_id1,
            sticker=BAD_STICKER
        )


def hello(update: Update, context):
    context.bot.send_message(
        chat_id=update.effective_message.chat_id,
        text="введите: /start"
    )


def start(update: Update, context):
    user_name = update.effective_user.first_name
    context.bot.send_message(
        chat_id=update.effective_message.chat_id,
        text=f"Привет, {user_name}!\nВыбери тип задачки",
        reply_markup=generate_keyboard()
    )


def main():
    my_update = Updater(
        token='1789418065:AAHp-2_XoqFdooC9oka4tS8RXUjcB1xMhcc',
    #   base_url=config.PROXI,
        use_context=True
    )

    keyboard_handler = CallbackQueryHandler(callback=keyboard_regulate, pass_chat_data=True)
    keyboard_handler1 = CallbackQueryHandler(callback=keyboard_regulate1, pass_chat_data=True)
    my_handler = MessageHandler(Filters.all, hello)
    start_handler = CommandHandler("start", start)

    my_update.dispatcher.add_handler(keyboard_handler1)
    my_update.dispatcher.add_handler(keyboard_handler)
    my_update.dispatcher.add_handler(start_handler)
    my_update.dispatcher.add_handler(my_handler)

    my_update.start_polling()
    my_update.idle()


if __name__ == "__main__":
    main() 
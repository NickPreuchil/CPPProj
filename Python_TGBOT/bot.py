import telebot
import randomframe
import datetime
import google_sheets_api

TOKEN = TOKEN
bot = telebot.TeleBot(TOKEN)


def get_frame() -> str:
	return randomframe.construct_frame()


@bot.message_handler(commands=['start'])
def send_welcome(message):
	cid = message.chat.id
	bot.send_message(cid, "Привет!")
	bot.send_message(cid, "Я - Генератор случайных фреймов.")
	bot.send_message(cid, "Нажимай кнопку и получи случайный фрейм.", reply_markup=board)


# Ключевое слово для разработчиков
@bot.message_handler(commands=['alltables'])
def send_welcome(message):
	cid = message.chat.id
	time = google_sheets_api.get_last_updated_time(google_sheets_api.TABLE_WHICH)
	bot.send_message(cid, "С последнего обновления таблицы " + google_sheets_api.TABLE_WHICH + " прошло " + f'\r{datetime.datetime.now() - time}')
	time = google_sheets_api.get_last_updated_time(google_sheets_api.TABLE_HOW)
	bot.send_message(cid, "С последнего обновления таблицы " + google_sheets_api.TABLE_HOW + " прошло " + f'\r{datetime.datetime.now() - time}')
	time = google_sheets_api.get_last_updated_time(google_sheets_api.TABLE_FRAME)
	bot.send_message(cid, "С последнего обновления таблицы " + google_sheets_api.TABLE_FRAME + " прошло " + f'\r{datetime.datetime.now() - time}')


@bot.message_handler()
def send_frame(message):
	cid = message.chat.id
	if message.text == "Случайный фрейм":
		newframe = get_frame()
		bot.send_message(cid, newframe)
	else:
		bot.send_message(cid, "Не понимаю :(")

	bot.send_message(cid, "Нажимай кнопку и получи случайный фрейм.", reply_markup=board)


def start():
	global board

	board = telebot.types.ReplyKeyboardMarkup(resize_keyboard=True)
	board.add("Случайный фрейм")
	bot.infinity_polling()

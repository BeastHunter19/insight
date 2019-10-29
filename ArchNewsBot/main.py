import telegram
from telegram import Update, Bot
from telegram.ext import Updater, CommandHandler, CallbackContext

import logging
import feedparser

TOKEN = "958605948:AAGnoWO5lyj3QdSIQ1scGvJ4srnaQGnZ3pQ"
chatid = "574802840"
bot = telegram.Bot(TOKEN)

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', level=logging.INFO)
logger = logging.getLogger(__name__)

d = feedparser.parse(r'19Rp_Xn5.rss')
r = feedparser.parse('https://www.reddit.com/r/linux/.rss')

def start(update: Update, context: CallbackContext):
    context.bot.sendMessage(chat_id=update.message.chat_id, text="Questo è l'ArchNewsBot, ti invierà tutti gli aggiornamenti provenienti dal feed rss di Arch")

def update_feed(context: CallbackContext):
    job = context.job
    context.bot.sendMessage(chat_id=chatid, text=r.entries[0].title + '\n' + r.entries[0].description + '\n' + r.entries[0].link)
    logger.info('Job "%s" executed', job)

def error(update: Update, context: CallbackContext):
    logger.warning('Update "%s" caused error "%s"', update, context.error)

def main():
    updater = Updater(TOKEN, use_context=True)
    dp = updater.dispatcher

    dp.add_handler(CommandHandler('start', start))

    j = updater.job_queue
    j.run_repeating(update_feed, interval=10, first=0)

    dp.add_error_handler(error)

    updater.start_polling()
    updater.idle()

if __name__ == '__main__':
    main()

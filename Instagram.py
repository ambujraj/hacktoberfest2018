#installation Required
#pip install instabot

from instabot import Bot
bot = Bot( )

bot.login(username = "code_owl", password = "**********")

#keep your picture & program file in same folder Eg:IG
#After uploading you will recieve a config folder which will include your login data in Folder IG
#After uploading your jpg file might get converted into REMOVE_ME file 

bot.upload_photo("wp6195493.jpg",caption = "This was uploaded using Python program")

#This is basically just for fun 
#change your password after Upload is finished
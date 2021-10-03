# -*- coding: utf-8 -*-
"""
Created on Tue Jul 27 10:39:21 2021

@author: hp
"""

import tkinter
import os, shutil
from tkinter import *
from tkinter import messagebox
from tkinter import filedialog
import io




#Creating root window
root=Tk()
root.geometry("400x400")
root.title("File Manager")
my_menu=Menu(root)
root.config(menu=my_menu)
root.iconbitmap("oo.ico")

#about me
def details():
    messagebox.showinfo("Python Project","Made By : \nSreeparno Dhar")




#Create menu item
about_menu=Menu(my_menu, tearoff=0)
my_menu.add_cascade(label="Help", menu=about_menu)
about_menu.add_command(label="About",command=details)
about_menu.add_separator()
about_menu.add_command(label="Exit", command=root.quit)



#function to sort the files into folders
def movefile(filename,ext,folders,directory):
    flag=False
    for foldername in folders:
        if(('.'+ext.lower()) in folders[foldername]):
            # print(foldername)
            if(foldername not in os.listdir(directory)):
                os.mkdir(os.path.join(directory,foldername))
            shutil.move(os.path.join(directory,filename),os.path.join(directory,foldername))
            flag=True
            break
    if(flag==False):   
        if('Others' not in os.listdir(directory)):
            os.mkdir(os.path.join(directory,'Others'))
        shutil.move(os.path.join(directory,filename),os.path.join(directory,'Others'))

#function to extracct files from the path and send individually to fn movefile()
def sort():

    folders={
    'images':['.jpeg','.jpg','.tiff','.tif','.bmp','.gif','.png','.raw','.nef','.cr2','.cr3'],
    'videos':['.mp4','.mov','.wmv','.flv','.avi','.avchd','.mkv'],
    'music':['.3ga','.aa','.aa3','.ac3','.avr','.caf','.m4a','.mp3','.mp2','.mpa','.wav'],
    'documents':['.pdf','.doc','.docx','.odt','.xls','.xlsx','.ppt','.pptx','.txt','.rtf'],
    }



    directory=filedialog.askdirectory()
    allfiles=os.listdir(directory)

    count=0
    messagebox.askokcancel("Message", "Do you want to continue?") 
    for i in allfiles:
        if (os.path.isfile(os.path.join(directory,i))==True):
            count=count+1
            movefile(i,i.split('.')[-1],folders,directory)

    messagebox.showinfo("Successful","Total File count: "+str(count))


label1=Label(root,text="Sort Files into Folders", width=20, font=("bold", 15))
label1.place(x=80, y=80)

Button(root,text="Location", width=20, height=2, bg="blue", fg="white",command=sort).place(x=120,y=200)



root.mainloop()
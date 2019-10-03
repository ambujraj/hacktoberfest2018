
#This is a kind of xy-plotter developed using the matplotlib library and tkinter.

import tkinter as tk
from matplotlib import pyplot as plt

window=tk.Tk()


def EXIT():
    window.destroy()


def plot():
    x=[0 for i in range(5)]
    y=[0 for i in range(5)]

    for i in range(5):

        x[i]=int(xentries[i].get())
        y[i]=int(yentries[i].get())

    plt.plot(x,y)
    plt.show()
    

label1=tk.Label(window,text='XY PLOTER',bg='black',fg='white',font='HELVITICA 20 bold')
label1.grid(row=0,column=2)

xlabels=[tk.Label for i in range(5)]
ylabels=[tk.Label for i in range(5)]

xentries=[tk.Entry for i in range(5)]
yentries=[tk.Entry for i in range(5)]

for i in range(5):
    xlabels[i]=tk.Label(window,text='X'+str(i+1),fg='black',font='HELVITICA 12 bold')
    xlabels[i].grid(row=(i+2),column=0)


    ylabels[i]=tk.Label(window,text='Y'+str(i+1),fg='black',font='HELVITICA 12 bold')
    ylabels[i].grid(row=(i+2),column=2)

    xentries[i]=tk.Entry(window)
    xentries[i].grid(row=(i+2),column=1)

    yentries[i]=tk.Entry(window)
    yentries[i].grid(row=(i+2),column=3)


btn1=tk.Button(window,text='PLOT',font='HELVITICA 15 bold',bg='green',fg='white',command=plot)
btn1.grid(row=7,column=0)


btn2=tk.Button(window,text='EXIT',font='HELVITICA 15 bold',bg='red2',fg='white',command=EXIT)
btn2.grid(row=7,column=4)

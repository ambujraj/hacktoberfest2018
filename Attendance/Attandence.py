import pandas as pd
import openpyxl
import time
import datetime
from openpyxl import load_workbook as workbook
now = time.strftime("%x")
fil = 'ATTANDENCE_0201IT193D09.xlsx'
book = workbook(fil)
sheet = book.active
nowd = datetime.datetime.now()
day = nowd.strftime("%A")
dbms = input("DBMS : ")
acd = input("ACD :")
os = input("OS : ")
cn = input("CN : ")
eees = input("EEES : ")
row = (now, day, dbms, acd, os, cn, eees)
sheet.append(row)
book.save(fil)
#To access a database modules that confirm to the Python Database API(DB-ABI) specification can be used to access
#relational database from python
#It ois documented in PEP 249 (Python Database Specification v2.0 Introduction)
#Python Database API supports a wide range of datbase servers
#Gadfly
#SQLite 3
#mSQL
#MySQL
#PostgreSQL
#Microsoft SQL server 2000
#Informix
#Interbase
#Oracle
#Sybas
 
#Every database module provides a module level function connect(parameter)
# The exact parameter depends on the database
# Example: conn = connect(dsn="hostname:DBNAME", user = "Jaypatel", password="****")
# If successful, a connection object(here conn) is returned 
# Following methods are to be called using connection object:
# c.close(): Closes the connection to the server
# c.commit(): Commits all pending transaction to the database
# c.rollback():Rollsback the database to the start of any pending transaction
#c.cursor(): Craetes a new cursor object that uses the connectio. Acursor is an object that you can use 
#to execute SQL queries ad obtain results.

#More on cursor
#An instance cur of a cursor has a number of standard method and attribute:
#cur.close(): Closes the cursor preventing any further operation on it
#cur.execute(query, [parameters]): Executes a query or command query to the database
#cur.fetchone(): Returns the next row of the result set produced by execute()
#cur.fetchmany([size]): returns a sequence of row(example, a list of tuple) size the number of rows\
#to return
#cur.fetchall():Returns a sequence of all remaining result rows (eg,a list of tuples)
#SQLite3 is an easy to use datbase engine
#It is very fast, and lightweight and the entire database is stored in a single disk file
#The Python has a standard module for SQLite intended to work with the databases.


#Using SQLite Module
import sqlite3
#Creating a DB in RAM
#db = sqlite3.connect('memory:')

#Creating and Opening of Database

db = sqlite3.connect('Android')

#Creating a cursor object
cursor = db.cursor()

#Executing a sql statement to create a table
#cursor.execute('''CREATE TABLE custs(id INTEGER PRIMARY KEY, name TEXT, phone TEXT, email TEXT unique, password TEXT)''')

#cursor.execute('''CREATE TABLE custs(name, course)''')

#Inserting records in Table custs
if cursor.execute('''INSERT INTO custs(name, course) VALUES(?,?)''', ('John', 'Python')):
     print ("Record inserted successfully!")

if cursor.execute('''INSERT INTO custs(name, course) VALUES(?,?)''', ('Shawn', 'Hadoop')):
     print ("Record inserted successfully!")

#Fetching of Data
if cursor.execute('''SELECT name, course FROM custs'''):
     print ("Record fetched successfully!")

#Retrieving the Data


record1 = cursor.fetchall()
print (record1)     

#recordAll = cursor.fetchall()
#for recordAll in recordAll:
    #print('{0}', '{1}'.format(record[0], record[1]))

#Dropping of table(Deletion)
#cursor.execute('''DROP TABLE custs''')

db.commit()

#Closing the connection
#db.close()





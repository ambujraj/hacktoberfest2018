from ftplib import FTP

ftp = FTP('ftp.cwi.nl')   # connect to host, default port

ftp.login()               # user anonymous, passwd anonymous@

ftp.retrlines('LIST')     # list directory contents

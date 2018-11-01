""" A simple script to remove all non-alphanumeric characters in text files with some readable text  
and LOTS of random characters. Works decently but doesn't catch everything. 
Encoding is set to latin-1 because otherwise it throws a "UnicodeDecodeError". """

# Potential changes: Refactor so it doesn't require the user to manually change the directory for every new use, 
# improve the regex so it catches most/all non-alphanumeric characters. 


import re # Regular expressions package

# The "r" before the directory makes it a raw string, elminating the need for escape chars.
origin = open(r"C:\Users\Sam\Desktop\Quarantine\origin.dat", "r+", encoding="latin-1") # Original file
subtitles = open(r"C:\Users\Sam\Desktop\Quarantine\subtitles.dat", "r+", encoding="latin-1") # file to which processed output is appended
subtitles.write(re.sub('[^a-zA-Z0-9_\s:]', '',origin.read())) # I have no goddamn idea how that regex works, just took it from stackoverflow                              
origin.close()
subtitles.close()

# Create a function which lists all the files in current directory.
#Create another function to verify whether current python program file (.py) is listed in the above returned list of files. Modify first function to accept two arguments, first - path to list the files from, second - filter to limit the specific extension files (i.e. function('c:\test', '*.txt') should list all *.txt files from c:\test directory.)

# display_files.py

import os,sys

if len(sys.argv) < 3:
    print 'Usage:-- python display_files.py <path of direcotry> <* followed by extention of file >'
    sys.exit()

# for listing the files in current directory
def list_currentdir():
    return os.listdir('.')

# for checking if file is present or not 
def check_file(list1):
    """
    :param list1: list of files
    """
    return True if __file__ in list1 else False
 
# this function will return the list of all file with extention in current directory.
def list_directory(path_file,extention):
    """
    :param path_file : path from command line
    :param extention : file extention
    """
    list_dir1 = os.listdir(path_file)
    list2 = [i for i in list_dir1 if i.endswith(sys.argv[2])]
    return list2    
    

if __name__ == '__main__':

    # check for the list of files in mentioned directory
    try:
        list_files = list_currentdir()
        if check_file(list_files):                                            #check if file is present or not in current directory
           print 'Current File is present'
        else:
           print 'Current File is not present'

        print 'File in the corresponding path are:-- ',list_directory(sys.argv[1],sys.argv[2])           #list all the file ending with the extention in the directory

    except Exception as error_message:
        print "Error received:-- ",error_message

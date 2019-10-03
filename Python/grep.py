#!/usr/bin/env python3

import sys
import argparse
import os
import re

# Init arg parser
ap = argparse.ArgumentParser()
ap.add_argument("-f", "--files", required=True, help="The files or folders", nargs='+')

# Add search args
search_args = ap.add_mutually_exclusive_group(required=True)
search_args.add_argument("-q", "--query", help="Search query")
search_args.add_argument("-r", "--regex", help="Regular expression")
search_args.add_argument("-b", "--between", help="Provide two string and the text inbetween will be outputted", nargs=2)

args = vars(ap.parse_args())

def main():
    for file_name in args["files"]:
        # Remove trailing directory indicator
        if file_name.startswith("./") or file_name.startswith(".\\"):
            file_name = file_name[2:]

        # Check if the current file is a file or directory and act accordingly
        if os.path.isfile(file_name):
            search_in_file(file_name)
        elif os.path.isdir(file_name):
            for curr_file_name in os.listdir(file_name):
                search_in_file(file_name + "/" + curr_file_name)

def search_in_file(file_name):
    # Check if we should use the between one
    if args["between"] == None:    
        with open(file_name) as file:
            # Loop over each line
            for i, line in enumerate(file):
                # Check if a normal string query or regex should be used and print the results
                if args["query"] != None:
                    if args["query"] in line:
                        print(f"[{file_name}] Line {i + 1}: {line}")
                elif args["regex"] != None:
                    matches = re.findall(args["regex"], line)
                    print(f"[{file_name}] Line {i + 1}: {', '.join(matches)}")
    # If between is given
    elif args["between"] != None:
        # Open the file and print in between text
        with open(file_name) as file:
            file_content = file.read().replace('\n', '')
            matches = re.findall(args["between"][0] + "(.+?)" + args["between"][1], file_content)
            for match in matches:
                print(f"[{file_name}] {match}")

if __name__ == "__main__":
    main()
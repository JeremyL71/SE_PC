import sys
import os, fnmatch

def lire_dossier(path: str):
    # List of files in complete directory
    file_list = []
    
    """
        Loop to extract files inside a directory
    
        path --> Name of each directory
        folders --> List of subdirectories inside current 'path'
        files --> List of files inside current 'path'
    
    """
    for path, folders, files in os.walk(path):
        for file in files:
            file_list.append(os.path.join(path, file))
    
    # Loop to print each filename separately
    for filename in file_list:
        print(filename)

if __name__ == '__main__':
    # Local test
    path = sys.argv[1]
    lire_dossier(path)
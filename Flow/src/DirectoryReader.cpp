/* 
 * File:   DirectoryReader.cpp
 * Author: janbednarik
 * 
 * Created on 1. březen 2014, 0:53
 */

#include <dirent.h>
#include <iostream>
#include <sys/stat.h>
#include "DirectoryReader.h"
#include "Exceptions.h"

using namespace std;

list<string> *DirectoryReader::getFiles() {
    parseDir(root);
    return files;
}

void DirectoryReader::parseDir(string newRoot) {
    DIR *d;
    struct dirent *dEntry;
    struct stat sb;
    
    if (newRoot.rfind('/') == newRoot.length() - 1) {
        newRoot.erase(newRoot.length() - 1);
    }
    
    if ((d = opendir(newRoot.c_str())) != NULL) {
        while ((dEntry = readdir(d)) != NULL) {
            string filepath(newRoot + "/" + (dEntry->d_name));
            stat(filepath.c_str(), &sb);
            // TODO muze spadnou            

            if (S_ISDIR(sb.st_mode)) {
                //            if (dEntry->d_type == DT_DIR) {
//                cout << "je to dir" << endl;
                //                if ((THIS_DIR.compare(dEntry->d_name) != 0) &&
                //                    (PARENT_DIR.compare(dEntry->d_name) != 0)) {
                //                        parseDir(newRoot + "/" + (dEntry->d_name));
                //                }
                string filename(dEntry->d_name);
                if ((filename.compare(".") != 0) && (filename.compare("..") != 0)) {
                    parseDir(filepath);
                }

            } else if (S_ISREG(sb.st_mode)) {
                files->push_back(newRoot + "/" + dEntry->d_name);
//                cout << "je to file: " << endl;
            } else {
//                cout << "je to neco jineho" << endl;
            }
        }
        closedir(d);
    } else {
        throw ECantOpenDirectory(newRoot);
    }
}
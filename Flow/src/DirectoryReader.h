/* 
 * File:   DirectoryReader.h
 * Author: janbednarik
 *
 * Created on 1. březen 2014, 0:53
 */

#ifndef DIRECTORYREADER_H
#define	DIRECTORYREADER_H

#include <list>
#include <string>

using namespace std;

const string THIS_DIR(".");
const string PARENT_DIR("..");


class DirectoryReader {
private:
    string root;
    list<string> *files;
    
    void parseDir(string newRoot);

public:
    DirectoryReader(string _root): root(_root) {
        files = new list<string>();
    }
    
    ~DirectoryReader() {
        delete files;
    }
    
    list<string> *getFiles();   
};

#endif	/* DIRECTORYREADER_H */


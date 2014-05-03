        /* 
 * File:   Exceptions.h
 * Author: Jan
 *
 * Created on 24. únor 2014, 0:19
 */

#ifndef EXCEPTIONS_H
#define	EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class EBad_Params: public exception 
{
public:
    const char *what() {
        return "Exception EBad_Params caught: Wrong parameters.";
    }    
};

class ECantOpenDirectory: public exception {
public:
    ECantOpenDirectory(string& _dir): dir(_dir) {}
    ~ECantOpenDirectory() throw() {}
    
    
    const char *what() {
        return string("Exception ECantOpenDirectory caught: Cannot open directory " + dir + ".")
                .c_str();                
    }
    
private:
    string dir;
};

class ECantOpenFile: public exception {
public:
    ECantOpenFile(string& _file): file(_file) {}
    ~ECantOpenFile() throw() {}
    
    const char *what() {
        return string("Exception ECantOpenFile caught: Cannot open file " + file + ".")
                .c_str();                
    }
    
private:
    string file;
};

#endif	/* EXCEPTIONS_H */


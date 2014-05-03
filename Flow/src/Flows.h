/* 
 * File:   Flows.h
 * Author: Jan
 *
 * Created on 22. únor 2014, 19:33
 */

#ifndef FLOWS_H
#define	FLOWS_H

#include "Parameters.h"

class Flows {
public:
    Flows();    
    virtual ~Flows();
    
    virtual void printSorted(Parameters &) = 0;       
};

#endif	/* FLOWS_H */


/* 
 * File:   FlowProcessor.cpp
 * Author: Jan
 * 
 * Created on 22. únor 2014, 19:32
 */

#include "FlowProcessor.h"
#include "Exceptions.h"

using namespace std;

void FlowProcessor::process(string& inFile) {
    FILE *f;
    if ((f = fopen(inFile.c_str(), "rb")) == NULL)
        throw ECantOpenFile(inFile);

    while (fread(&flData, sizeof (struct flowData), 1, f) != 0) {
        if (isCorrectSAFamily(params->getIPVersion(), __builtin_bswap32(flData.sa_family))) {           
            edit();
            save();            
        }
    }
    
    fclose(f);
}

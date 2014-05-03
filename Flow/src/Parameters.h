/* 
 * File:   Parameters.h
 * Author: Jan
 *
 * Created on 22. únor 2014, 19:28
 */

#ifndef PARAMETERS_H
#define	PARAMETERS_H

#include <string>
#include <iostream>

using namespace std;

const string SRCIP("srcip");
const string SRCIP4("srcip4");
const string SRCIP6("srcip6");
const string DSTIP("dstip");
const string DSTIP4("dstip4");
const string DSTIP6("dstip6");
const string SRCPORT("srcport");
const string DSTPORT("dstport");
const string BYTES("bytes");
const string PACKETS("packets");

class Parameters {
public:

    enum AggregationBy {
        E_IP, E_PORT
    };

    enum Direction {
        E_SRC, E_DST
    };
    
    enum IPversion {
        E_IPV4, E_IPV6, E_IPVALL
    };
    
    enum SortingBy {
        E_BYTES, E_PACKETS
    };


private:
    int argc;
    char** argv;
    AggregationBy aggrBy;
    Direction direction;
    IPversion ipVersion;
    SortingBy sortBy;
    unsigned short ipMask;
    string rootDir;

public:

    Parameters(int _argc, char** _argv) : argc(_argc), argv(_argv), ipMask(128) {
    }
    
    void process();    
    string& getRootDir() { return rootDir; }
    AggregationBy getAggregation() { return aggrBy; }
    SortingBy getSorting() { return sortBy; }
    Direction getDirection() { return direction; }
    IPversion getIPVersion() { return ipVersion; }
    unsigned short getIPMask() { return ipMask; }
    

private:
    void setDir(const char* path);
    void setAggregation(const char* aggregation);
    void setSort(const char* sort);
    void check();
    
// DEBUG    
public: 
    void debug_printParams() {
        cout << "dir: " << rootDir << endl;
        cout << "agregation: " << aggrBy << endl;
        cout << "ip mask: " << ipMask << endl;
        cout << "sort: " << sortBy << endl;
    }

};

#endif	/* PARAMETERS_H */


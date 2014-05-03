/* 
 * File:   Parameters.cpp
 * Author: Jan
 * 
 * Created on 22. únor 2014, 19:29
 */

#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include "Parameters.h"
#include "Exceptions.h"

using namespace std;

void Parameters::process() {
    // ./Flow -f directory -a aggregation -s sort        
    if (argc != 7)
        throw EBad_Params();

    int opt;
    while ((opt = getopt(argc, argv, "f:a:s:")) != -1) {
        switch (opt) {
            case 'f': setDir(optarg);
                break;
            case 'a': setAggregation(optarg);
                break;
            case 's': setSort(optarg);
                break;
            default:
                throw EBad_Params();
        }
    }
    
    check();
}

void Parameters::setDir(const char* path) {
    rootDir = path;
}

void Parameters::setAggregation(const char* aggregation) {
    string aggr(aggregation);

    // srcip4/mask, srcip6/mask
    if (aggr.find_first_of('/', 6) == 6) {
        aggrBy = E_IP;
        if (aggr.substr(0, 6).compare(SRCIP4) == 0) {
            direction = E_SRC;
            ipVersion = E_IPV4;
        } else if (aggr.substr(0, 6).compare(SRCIP6) == 0) {
            direction = E_SRC;
            ipVersion = E_IPV6;
        } else if (aggr.substr(0, 6).compare(DSTIP4) == 0) {
            direction = E_DST;
            ipVersion = E_IPV4;
        } else if (aggr.substr(0, 6).compare(DSTIP6) == 0) {
            direction = E_DST;
            ipVersion = E_IPV6;
        } else {
            throw EBad_Params();
        }
        
        try {
            ipMask = atoi(aggr.substr(7).c_str());
        } catch (out_of_range& e) {
            throw EBad_Params();
        }
    // srcip
    } else if (aggr.compare(SRCIP) == 0) {
        aggrBy = E_IP;        
        direction = E_SRC;
        ipVersion = E_IPVALL;
    // dstip
    } else if (aggr.compare(DSTIP) == 0) {
        aggrBy = E_IP;        
        direction = E_DST;
        ipVersion = E_IPVALL;
    // srcport
    } else if (aggr.compare(SRCPORT) == 0) {
        aggrBy = E_PORT;
        direction = E_SRC;
    // dstport
    } else if (aggr.compare(DSTPORT) == 0) {
        aggrBy = E_PORT;
        direction = E_DST;
    } else {
        throw EBad_Params();
    }
}

void Parameters::setSort(const char* sort) {
    string s(sort);
    
    if (s.compare(BYTES) == 0) {
        sortBy = E_BYTES;
    } else if (s.compare(PACKETS) == 0) {
        sortBy = E_PACKETS;
    } else {
        throw EBad_Params();
    }
}

void Parameters::check() {
    // IPv4 mask - <1; 32>, IPv6 mask <1; 128>    
    if (aggrBy == E_IP) {
        if (ipVersion == E_IPV4) {
            if (ipMask < 1 || ipMask > 32)
                throw EBad_Params();
        } else {
            if (ipMask < 1 || ipMask > 128)
                throw EBad_Params();
        }
    }
}
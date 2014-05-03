/* 
 * File:   FlowsIP.h
 * Author: Jan
 *
 * Created on 26. únor 2014, 14:07
 */

#ifndef FLOWSIP_H
#define	FLOWSIP_H

#include <unordered_map>
#include <array>
#include <vector>
#include <stdint.h>
#include <utility>
#include <algorithm>
#include <arpa/inet.h>
#include <cstring>
#include "Flows.h"
#include "IP.h"
#include "Parameters.h"
#include "PacketsBytes.h"

using namespace std;

class Hasher {
public:
    size_t operator() (const IP& ip) const {        
        uint32_t* ip8 = (uint32_t*)ip.ip128bit;
        size_t hash = 0;
        
        hash += (71 * hash + ip8[0]);
        hash += (71 * hash + ip8[1]);
        hash += (71 * hash + ip8[2]);
        hash += (71 * hash + ip8[3]);
        
        return hash;
    }        
};

class EqualFn {
public:
    bool operator() (const IP& ip1, const IP& ip2) const {        
        return (ip1.ip128bit[0] == ip2.ip128bit[0]) && 
               (ip1.ip128bit[1] == ip2.ip128bit[1]);
    }
};

class FlowsIP : public Flows {
public:

    FlowsIP() {
        aggregatedFlows = new unordered_map<IP, PacketsBytes, Hasher, EqualFn>;
    }

    ~FlowsIP() {
        delete aggregatedFlows;
    }

    void insert(IP key, PacketsBytes pb);
    void printSorted(Parameters & par);

private:
    unordered_map<IP, PacketsBytes, Hasher, EqualFn> *aggregatedFlows;

    void printFlow6(IP ip, uint64_t packets, uint64_t bytes) {
        struct in6_addr in6addr;
        char ipStr[INET6_ADDRSTRLEN];

        memcpy(&(in6addr.__in6_u), &(ip.ip128bit), 16 * sizeof (uint8_t));
        inet_ntop(AF_INET6, &in6addr, ipStr, INET6_ADDRSTRLEN);

        cout << ipStr << "," << packets << "," << bytes << endl;
    }

    void printFlow4(uint8_t* ip, uint64_t packets, uint64_t bytes) {
        struct in_addr in4addr;
        char ipStr[INET_ADDRSTRLEN];

        memcpy(&(in4addr.s_addr), ip, 4 * sizeof (uint8_t));
        inet_ntop(AF_INET, &in4addr, ipStr, INET_ADDRSTRLEN);

        cout << ipStr << "," << packets << "," << bytes << endl;
    }

    void sortFlows(vector<pair<IP, PacketsBytes> >* flows, Parameters::SortingBy sortBy) {
        if (sortBy == Parameters::E_BYTES) {
            sort(flows->begin(), flows->end(), &FlowsIP::compareFlowsByBytes);
        } else {
            sort(flows->begin(), flows->end(), &FlowsIP::compareFlowsByPackets);
        }
    }

    static bool compareFlowsByBytes(pair<IP, PacketsBytes> left, pair<IP, PacketsBytes> right) {
        return left.second.bytes > right.second.bytes;
    }

    static bool compareFlowsByPackets(pair<IP, PacketsBytes> left, pair<IP, PacketsBytes> right) {
        return left.second.packets > right.second.packets;
    }
};

#endif	/* FLOWSIP_H */

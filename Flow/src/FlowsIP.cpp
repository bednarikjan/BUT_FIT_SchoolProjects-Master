/* 
 * File:   FlowsIP.cpp
 * Author: Jan
 * 
 * Created on 26. únor 2014, 14:07
 */

#include "FlowsIP.h"
#include <vector>

using namespace std;

void FlowsIP::insert(IP ip, PacketsBytes pb) {
    if (aggregatedFlows->count(ip) > 0) {
        (*aggregatedFlows)[ip].packets += pb.packets;
        (*aggregatedFlows)[ip].bytes += pb.bytes;
    } else {
        (*aggregatedFlows)[ip] = pb;
    }
}

void FlowsIP::printSorted(Parameters & par) {
    vector<pair<IP, PacketsBytes> > *flows =
            new vector<pair<IP, PacketsBytes> >(aggregatedFlows->begin(), aggregatedFlows->end());

    sortFlows(flows, par.getSorting());

    cout << "#" << (par.getDirection() == Parameters::E_SRC ? "srcip" : "dstip") << ",packets,bytes" << endl;

//    Parameters::IPversion ipv = par.getIPVersion();
    for (vector<pair<IP, PacketsBytes> >::iterator it = flows->begin(); it < flows->end(); ++it) {
        if (it->first.sa_family == AF_INET6) {
            printFlow6(it->first, it->second.packets, it->second.bytes);
        } else {
            printFlow4(&(((uint8_t*)(&(it->first)))[12]), it->second.packets, it->second.bytes);
        }
    }

    delete flows;
}

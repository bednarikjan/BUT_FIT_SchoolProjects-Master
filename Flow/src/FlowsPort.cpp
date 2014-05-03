/* 
 * File:   FlowsPort.cpp
 * Author: Jan
 * 
 * Created on 26. únor 2014, 14:08
 */

#include "FlowsPort.h"

using namespace std;

void FlowsPort::insert(Port p, PacketsBytes pb) {
    if (aggregatedFlows->count(p) > 0) {
        (*aggregatedFlows)[p].packets += pb.packets;
        (*aggregatedFlows)[p].bytes += pb.bytes;
    } else {
        (*aggregatedFlows)[p] = pb;
    }
}

void FlowsPort::printSorted(Parameters & par) {
    vector<pair<Port, PacketsBytes> > *flows =
            new vector<pair<Port, PacketsBytes> >(aggregatedFlows->begin(), aggregatedFlows->end());

    sortFlows(flows, par.getSorting());

    cout << "#" << (par.getDirection() == Parameters::E_SRC ? "srcport" : "dstport") << ",packets,bytes" << endl;
    for (vector<pair<Port, PacketsBytes> >::iterator it = flows->begin(); it < flows->end(); ++it) {
        printFlow(it->first, it->second.packets, it->second.bytes);
    }

    delete flows;
}


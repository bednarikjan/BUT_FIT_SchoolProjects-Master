/* 
 * File:   FlowsPort.h
 * Author: Jan
 *
 * Created on 26. únor 2014, 14:08
 */

#ifndef FLOWSPORT_H
#define	FLOWSPORT_H

#include <unordered_map>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include "Flows.h"
#include "PacketsBytes.h"
#include "Parameters.h"

using namespace std;

typedef uint16_t Port;

class FlowsPort : public Flows {
public:    
    FlowsPort() {
        aggregatedFlows = new unordered_map<Port, PacketsBytes >;
    }

    ~FlowsPort() {
        delete aggregatedFlows;
    }
    
    void insert(Port p, PacketsBytes pb);
    void printSorted(Parameters & par);
    
private:
    unordered_map<Port, PacketsBytes>* aggregatedFlows;     
    
    void printFlow(Port p, uint64_t packets, uint64_t bytes) {
        cout << p << "," << packets << "," << bytes << endl;
    }
    
    void sortFlows(vector<pair<Port, PacketsBytes> >* flows, Parameters::SortingBy sortBy) {
        if (sortBy == Parameters::E_BYTES) {
            sort(flows->begin(), flows->end(), &FlowsPort::compareFlowsByBytes);
        } else {
            sort(flows->begin(), flows->end(), &FlowsPort::compareFlowsByPackets);
        }
    }
    
    static bool compareFlowsByBytes(pair<Port, PacketsBytes> left, pair<Port, PacketsBytes> right) {
        return left.second.bytes > right.second.bytes;
    }

    static bool compareFlowsByPackets(pair<Port, PacketsBytes> left, pair<Port, PacketsBytes> right) {
        return left.second.packets > right.second.packets;
    }
};

#endif	/* FLOWSPORT_H */


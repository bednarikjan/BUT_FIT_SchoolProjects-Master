/* 
 * File:   FlowProcessor.h
 * Author: Jan
 *
 * Created on 22. únor 2014, 19:32
 */

#ifndef FLOWPROCESSOR_H
#define	FLOWPROCESSOR_H

#include <string>
#include <netinet/in.h>
#include "Parameters.h"

using namespace std;

struct flowData {
    uint32_t sa_family;
    struct in6_addr src_addr;
    struct in6_addr dst_addr;
    uint16_t src_port;
    uint16_t dst_port;
    uint64_t packets;
    uint64_t bytes;
};

class FlowProcessor {
public:

    int count;
    
    
    FlowProcessor(Parameters *_params): params(_params) {
        count = 0;
    }

    virtual ~FlowProcessor() {
    }
    
    virtual void process(string&);

protected:
    struct flowData flData;
    Parameters *params;
        
    virtual void save() = 0;    
    virtual void edit() = 0;    
    
    bool isCorrectSAFamily(Parameters::IPversion wanted, uint32_t received) {
        return ((wanted == Parameters::E_IPV4 && received == AF_INET6) || 
                (wanted == Parameters::E_IPV6 && received == AF_INET)) ?
                    false : true;            
    }
};

#endif	/* FLOWPROCESSOR_H */


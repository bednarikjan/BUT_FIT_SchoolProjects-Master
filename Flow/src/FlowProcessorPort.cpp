/* 
 * File:   FlowProcessorPort.cpp
 * Author: Jan
 * 
 * Created on 22. únor 2014, 19:32
 */

#include "FlowProcessorPort.h"

void FlowProcessorPort::edit() {
    // intended nothing :-)
}

void FlowProcessorPort::save() {    
    uint16_t port = (params->getDirection() == params->E_SRC) ?
            __bswap_16(flData.src_port) : __bswap_16(flData.dst_port);

    PacketsBytes packetsBytes = {__bswap_64(flData.packets), __bswap_64(flData.bytes)};
    flows->insert(port, packetsBytes);
}

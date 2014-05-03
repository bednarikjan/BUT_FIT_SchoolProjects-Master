/* 
 * File:   FlowProcessorIP.cpp
 * Author: Jan
 * 
 * Created on 22. únor 2014, 19:32
 */

#include "FlowProcessorIP.h"
#include "Exceptions.h"
#include <utility>

//debug
#include <iostream>
#include <endian.h>

using namespace std;

// Adjusts the IP address according to the given IP mask

void FlowProcessorIP::edit() {
//    uint64_t *ip = (params->getDirection() == params->E_SRC) ?
//            (uint64_t*) (flData.src_addr.__in6_u.__u6_addr8) :
//            (uint64_t*) (flData.dst_addr.__in6_u.__u6_addr8);
    uint8_t *ip = (params->getDirection() == params->E_SRC) ?
            (uint8_t*) (flData.src_addr.__in6_u.__u6_addr8) :
            (uint8_t*) (flData.dst_addr.__in6_u.__u6_addr8);

//    int mask = (params->getIPVersion() == params->E_IPV4) ?
//            ((128 - 32) + params->getIPMask()) :
//            params->getIPMask();   
    
//    maskIPv6(ip, mask);    
    maskIP(ip);
}

void FlowProcessorIP::save() {
    uint64_t *ip = (params->getDirection() == params->E_SRC) ?
            (uint64_t*) (flData.src_addr.__in6_u.__u6_addr8) :
            (uint64_t*) (flData.dst_addr.__in6_u.__u6_addr8);

    FlowProcessorIP::ip.ip128bit[0] = ip[0];
    FlowProcessorIP::ip.ip128bit[1] = ip[1];
    FlowProcessorIP::ip.sa_family = __bswap_32(flData.sa_family);

    PacketsBytes packetsBytes = {__bswap_64(flData.packets), __bswap_64(flData.bytes)};
    flows->insert(FlowProcessorIP::ip, packetsBytes);
}


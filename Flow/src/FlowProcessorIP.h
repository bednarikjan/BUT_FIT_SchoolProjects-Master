/* 
 * File:   FlowProcessorIP.h
 * Author: Jan
 *
 * Created on 22. únor 2014, 19:32
 */

#ifndef FLOWPROCESSORIP_H
#define	FLOWPROCESSORIP_H

#include <array>
#include <sys/socket.h>
#include "FlowsIP.h"
#include "FlowProcessor.h"
#include "IP.h"

//debug
#include <cmath>

using namespace std;

class FlowProcessorIP : public FlowProcessor {
public:
    FlowProcessorIP(Parameters* params, FlowsIP* _flows) : FlowProcessor(params), flows(_flows) {
        int maskOnes = (params->getIPVersion() == params->E_IPV4) ?
            ((128 - 32) + params->getIPMask()) :
            params->getIPMask();
        
        maskOffset = maskOnes / 8;
        mask8bit = make8bitMask(maskOnes % 8);
    }

    virtual ~FlowProcessorIP() {
    }

private:
    FlowsIP *flows;
    IP ip;
    
    unsigned short maskOffset;
    uint8_t mask8bit;

    void edit();
    void save();

    void maskIP(uint8_t* ip) {
        ip[maskOffset] &= mask8bit;
        for(int i = maskOffset + 1; i < 16; i++) {
            ip[i] &= 0x00;
        }
    }
    
//    void maskIPv6(uint64_t* ip, int mask) {
//        uint8_t* ip8 = (uint8_t*) ip;
//        
//        unsigned short i = 0;
//        while ((mask -= 8) >= 0)
//            ip8[i++] &= 0xff;
//        if (i < 16)
//            ip8[i++] &= make8bitMask(8 + mask);
//        while (i < 16)
//            ip8[i++] &= 0x0;
//    }

    uint8_t make8bitMask(unsigned short ones) {
        uint8_t mask = (uint8_t) 0;
        for (unsigned short i = 0; i < ones; i++)
            mask |= ((uint8_t) 1 << (7 - i));

        return mask;
    }

    void debug_printIPv6(uint64_t *ipv6) {
        uint16_t *ip16bitArray = (uint16_t*) ipv6;

        for (int i = 0; i < 8; i++) {
            cout << ip16bitArray[i];
            if (i < 7)
                cout << ":";
        }
        cout << endl;
    }

    void debug_printIPv4(uint64_t *ipv4) {
        for (int i = 0; i < 16; i++) {
            cout << (int) ((uint8_t *) ipv4)[i] << ".";
        }
        cout << endl;
    }
    
    template<typename T>
    void debug_printBits(T num) {
        int bits = 8 * sizeof(T);
        for (int i = 0; i < bits; i++) {
            cout << ((num >> ((bits-1) - i)) & 1);
        }
        cout << endl;
    }
};
#endif	/* FLOWPROCESSORIP_H */


/* 
 * File:   IP.h
 * Author: janbednarik
 *
 * Created on 1. březen 2014, 21:27
 */

#ifndef IP_H
#define	IP_H

#include <stdint.h>

struct IP {
    uint64_t ip128bit[2];
    uint32_t sa_family;
    
//    bool operator< (const IP& that) const {
//        for (int i = 0; i < 2; i++) {
//            if (ip128bit[i] < that.ip128bit[i]) return true;
//            if (ip128bit[i] > that.ip128bit[i]) return false;            
//        }
//        return false;
//    }
};

#endif	/* IP_H */


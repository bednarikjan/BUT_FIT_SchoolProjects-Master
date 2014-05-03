/* 
 * File:   FlowProcessorPort.h
 * Author: Jan
 *
 * Created on 22. únor 2014, 19:32
 */

#ifndef FLOWPROCESSORPORT_H
#define	FLOWPROCESSORPORT_H

#include "FlowsPort.h"
#include "FlowProcessor.h"

using namespace std;

class FlowProcessorPort : public FlowProcessor {
public:

    FlowProcessorPort(Parameters* params, FlowsPort* _flows) : FlowProcessor(params), flows(_flows) {
    };

    virtual ~FlowProcessorPort() {
    };        

private:
    FlowsPort* flows;
    
    void edit();
    void save();
};

#endif	/* FLOWPROCESSORPORT_H */
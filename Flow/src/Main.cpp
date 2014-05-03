/* 
 * Project:     Flow 
 * File:        Main.cpp
 * Author:      Jan Bednarik
 */

#include <iostream>
#include <cstdint>
#include <cstdio>
#include <map>
#include <list>
#include "FlowProcessor.h"
#include "FlowProcessorIP.h"
#include "FlowProcessorPort.h"
#include "FlowsIP.h"
#include "FlowsPort.h"
#include "Parameters.h"
#include "Exceptions.h"
#include "DirectoryReader.h"

using namespace std;

/**
 * Main program
 */
class Main {    
private:
    list<string> *files;    
    FlowsIP* flowsIP;
    FlowsPort* flowsPort;
    FlowProcessorIP* fProcIP;
    FlowProcessorPort* fProcPort;

    void help() {
        cout << \
        "Usage:\n"
        "\tflow -f directory -a aggregation -s sort\n"
        "\n"
        "\t-a\n"
        "\t\tsrcip = IPv4/32 or IPv6/128\n"
        "\t\tsrcip4/mask = IPv4/1-32\n"
        "\t\tsrcip6/mask = IPv6/1-128\n"
        "\t-s\n"
        "\t\tbytes\n"
        "\t\tpackets\n";
    }
    
    void debug_printFiles() {
        for(list<string>::iterator it = files->begin(); it != files->end(); ++it) {
            cout << *it << endl;
        }
    }

public:        
    Main(): flowsIP(NULL), flowsPort(NULL), fProcIP(NULL), fProcPort(NULL) {}
    
    ~Main() {
        if (flowsIP) delete flowsIP;
        if (flowsPort) delete flowsPort;
        if (fProcIP) delete fProcIP;
        if (fProcPort) delete fProcPort;
    }
    
    int main(int argc, char** argv) {
        try {
            Parameters parameters(argc, argv);
            parameters.process();            
            
            DirectoryReader directoryReader(parameters.getRootDir());
            files = directoryReader.getFiles();
            
            // aggregation by IP
            if (parameters.getAggregation() == parameters.E_IP) {    
                flowsIP = new FlowsIP; 
                fProcIP = new FlowProcessorIP(&parameters, flowsIP);
                
                for(list<string>::iterator it = files->begin(); it != files->end(); ++it) {
                    fProcIP->process(*it);
                }                 
                
                flowsIP->printSorted(parameters);                
            // aggregation byt Port
            } else {
                flowsPort = new FlowsPort;
                fProcPort = new FlowProcessorPort(&parameters, flowsPort);
                
                for(list<string>::iterator it = files->begin(); it != files->end(); ++it) {
                    fProcPort->process(*it);
                }                
                
                flowsPort->printSorted(parameters);
            }
            
        } catch (EBad_Params e) {
            cout << e.what() << endl;
            help();
        } catch (ECantOpenDirectory e)  {
            cout << e.what() << endl;        
        } catch (ECantOpenFile e) {
            cout << e.what() << endl;
        } catch (bad_alloc e) {
            cout << e.what() << endl;
        }        
        
        return 0;
    }    
};

int main(int argc, char** argv) {
    Main main;

    return main.main(argc, argv);
}
#ifndef _REMOTECONTROL_H_
#define _REMOTECONTROL_H_

#include "BridgeSwitch.h"

class RemoteControl : public BridgeSwitch
{
 
public:
        RemoteControl(IAppliance* appliance):
        BridgeSwitch(appliance)
        {
        }
         
        void turnOn()
        {
            std::cout << "Using Remote ";
            m_pIAppliance->run();
        }
        void turnOff()
        {
            std::cout << "Using Remote ";
            m_pIAppliance->stop();
        }
};

#endif //_REMOTECONTROL_H_


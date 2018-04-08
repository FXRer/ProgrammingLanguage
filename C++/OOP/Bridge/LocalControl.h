#ifndef _LOCALCONTROL_H_
#define _LOCALCONTROL_H_

#include "BridgeSwitch.h"

class LocalControl : public BridgeSwitch
{
public:
        LocalControl(IAppliance* appliance):BridgeSwitch(appliance)
        {
        }
         
        void turnOn()
        {
            std::cout << "Using Local  ";
            m_pIAppliance->run();
        }
        void turnOff()
        {
            std::cout << "Using Local  ";
            m_pIAppliance->stop();
        }
};

#endif //_LOCALCONTROL_H_


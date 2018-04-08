#ifndef _BRIDGESWITCH_H_
#define _BRIDGESWITCH_H_

#include "Switch.h"
#include "IAppliance.h"

class BridgeSwitch : public Switch
{
    protected:
        IAppliance* m_pIAppliance;

    public:
        BridgeSwitch(IAppliance* backend)
        {
            m_pIAppliance = backend;
        }
        void turnOn()
        {
            std::cout << "Bridge on ";
            m_pIAppliance->run();
        }
        void turnOff()
        {
            std::cout << "Bridge off";
            m_pIAppliance->stop();
        }
};
#endif //_BRIDGESWITCH_H_


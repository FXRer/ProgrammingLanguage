#ifndef _IAPPLIANCE_H_
#define _IAPPLIANCE_H_

class IAppliance
{
public:
       virtual void run()=0;
       virtual void stop()=0;
};
#endif //_IAPPLIANCE_H_


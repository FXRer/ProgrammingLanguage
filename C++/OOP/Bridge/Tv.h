#ifndef _TV_H_
#define _TV_H_

#include <string>
#include "IAppliance.h"

class TV : public IAppliance
{
private:
        std::string m_Name;
public:
        TV(std::string _name)
        {
            m_Name = _name;
        }
         
        void run()
        {
            std::cout << m_Name <<" is Switch-On" << std::endl;
        }
        void stop()
        {
            std::cout << m_Name <<" is Switch-Off" << std::endl;
        }
     };  

#endif //_TV_H_


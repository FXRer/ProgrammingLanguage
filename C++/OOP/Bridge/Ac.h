#ifndef _AC_H_
#define _AC_H_

#include "IAppliance.h"
#include <string.h>

class AC : public IAppliance
{
private:
        std::string m_Name;

public:
        AC(std::string _name)
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
#endif //_AC_H_

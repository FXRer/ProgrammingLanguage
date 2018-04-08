#include <iostream>
#include <string>

#include "Tv.h"
#include "Ac.h"

#include "RemoteControl.h"
#include "LocalControl.h"

int main()
{
        Switch* switch1;

        IAppliance* tv = new TV("BedRoom TV");
        IAppliance* ac = new AC("AC");

        switch1 = new RemoteControl(tv);
        switch1->turnOn();

        switch1 = new RemoteControl(ac);
        switch1->turnOn();

        switch1 = new LocalControl(tv);
        switch1->turnOff();

        switch1 = new LocalControl(ac);
        switch1->turnOff();
return 1;
}


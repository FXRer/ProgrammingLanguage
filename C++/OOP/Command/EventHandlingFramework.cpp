#include <iostream>
#include <memory>
#include <map>

// Source: http://thispointer.com/designing-event-handling-framework-using-command-design-pattern/

/*
 * Framework Code Starts
 */
enum EVENTS
{
    USB_ATTACHED,
    USB_DETTACHED,
    WIFI_CONNECTED,
    WIFI_DISCONNECTED,
     
};



class Command
{
public:
    virtual void execute() = 0;
};


 
class HardwareEventInvoker 
{
    std::map<EVENTS, std::shared_ptr<Command> > m_registeredCommands;
public:
    /*
     * This function will be called from framework to handle the event  
     */
    void handleEvent(EVENTS event)
    {
        auto it = m_registeredCommands.find(event);
        if( it != m_registeredCommands.end())
        {
            std::shared_ptr<Command> cmdPtr = it->second;
            if(cmdPtr)
                cmdPtr->execute();
             
        }
    }
    /*
     * This function is called by the appication to register its command for Events.  
     */
    void registerEvent(EVENTS event, std::shared_ptr<Command> cmdPtr)
    {
        m_registeredCommands.insert(std::pair<EVENTS, std::shared_ptr<Command> >(event, cmdPtr));
    }
};
 

 
//----------------------------
class USBConnectedCommand : public Command
{
public:
    void execute()
    {
        std::cout<<"USBConnectedCommand\n";
    }
};
class USBDisconnectedCommand : public Command
{
public:
    void execute()
    {
        std::cout<<"USBDisconnectedCommand\n";
    }
};



class WifiConnectedCommand : public Command
{
public:
    void execute()
    {
        std::cout<<"WifiConnectedCommand\n";
    }
};
class WifiDisconnectedCommand : public Command
{
public:
    void execute()
    {
        std::cout<<"WifiDisconnectedCommand\n";
    }
};
 

 
//------------------------------------------------------------------------------//
int main()
{
    HardwareEventInvoker hrdwrEvntInvokerObj;
    hrdwrEvntInvokerObj.registerEvent(USB_ATTACHED, std::make_shared<USBConnectedCommand>());
    hrdwrEvntInvokerObj.registerEvent(USB_DETTACHED, std::make_shared<USBDisconnectedCommand>());
    hrdwrEvntInvokerObj.registerEvent(WIFI_CONNECTED, std::make_shared<WifiConnectedCommand>());
    hrdwrEvntInvokerObj.registerEvent(WIFI_DISCONNECTED, std::make_shared<WifiDisconnectedCommand>());
     
    // Fire the Events here.
    // In real enviornment these Events will be fired from inside the framework when actual
    // hardware action takes place. But here we will simulate by invoking them manually.
     
    // At the time of invokation we dont know which command is going to execute.
    // So. invoker is completely unaware of actual receiver.
     
    hrdwrEvntInvokerObj.handleEvent(USB_ATTACHED);
    hrdwrEvntInvokerObj.handleEvent(USB_DETTACHED);
    hrdwrEvntInvokerObj.handleEvent(WIFI_CONNECTED);
    hrdwrEvntInvokerObj.handleEvent(WIFI_DISCONNECTED);
     
    return 0;
}

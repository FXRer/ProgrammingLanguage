#include "EventDispatcher.h"

class MenuState : public AppState
{
	
public:
	MenuState();
private:
	std::vector<Button> mButtons;
	
	// Event Listeners
	// Buttons
	class ButtonListener : public Listener
	{
		PrefListState* parent;
	public:
		ButtonListener( PrefListState* p ){ parent = p; }
		void handleEvent( int ID )
		{
			std::cout << "Button Pressed: " << ID << std::endl;
		}
	} mButtonListener;
};

#include "Listener.h"
#include <stdio.h>
#include <vector>
#include <algorithm>

class EventDispatcher {
public:
	void addListener( Listener* );
	void removeListener( Listener* );
	
protected:
	std::vector<Listener*> mListeners;
	virtual void dispatchEvent();
};

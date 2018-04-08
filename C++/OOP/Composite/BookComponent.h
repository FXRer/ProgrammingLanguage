#ifndef _BOOKCOMPONENT_H_
#define _BOOKCOMPONENT_H_

class BookComponent
{
public:
	BookComponent()
	{

	}

	virtual ~BookComponent()
	{
	}

	virtual void add(BookComponent * newComponent)
	{
	}

	virtual void remove(BookComponent * componentToRemove)
	{
	}

	virtual void displayInfo() = 0;
};

#endif //_BOOKCOMPONENT_H_

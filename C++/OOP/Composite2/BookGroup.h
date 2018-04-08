#ifndef _BOOKGROUP_H_
#define _BOOKGROUP_H_

#include <vector>
#include <string>

#include "BookComponent.h"

class BookGroup : public BookComponent {
public:
	BookGroup(std::string groupName);
	virtual ~BookGroup();

	virtual void add(BookComponent * newComponent);
	virtual void remove(BookComponent * componentToRemove);
	virtual void displayInfo();


private:
	std::string m_groupName;
	std::vector<BookComponent*> m_bookComponents;
};
#endif //_BOOKGROUP_H_

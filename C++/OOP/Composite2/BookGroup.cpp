#include <iostream>
#include <memory>
#include <algorithm>

#include "BookGroup.h"

BookGroup::BookGroup(std::string groupName)
: m_groupName(groupName){
}

BookGroup::~BookGroup() {
  std::vector<BookComponent *>::iterator pos;

  for(pos = m_bookComponents.begin();
      pos != m_bookComponents.end(); ++pos)
  {
     BookComponent * bookComponent = *pos;

     delete bookComponent;
  }

  m_bookComponents.clear();
}

void BookGroup::add(BookComponent * newComponent)
{
  m_bookComponents.push_back(newComponent);
}

void BookGroup::remove(BookComponent * componentToRemove)
{
  std::vector<BookComponent *>::iterator pos;

  for(pos = m_bookComponents.begin();
      pos != m_bookComponents.end(); ++pos)
  {
    if(*pos == componentToRemove)
    {
      m_bookComponents.erase(pos);
      break;
    }
  }
}

void BookGroup::displayInfo()
{
  static std::string spaces;

  std::cout << "Group : " << m_groupName << "\n";

  spaces += std::string("    ");

  std::vector<BookComponent *>::iterator pos;

  for(pos = m_bookComponents.begin();
      pos != m_bookComponents.end(); ++pos)
  {
    std::cout << spaces;

    BookComponent * bookComponent = *pos;

    bookComponent->displayInfo();
  }

  spaces.pop_back();
  spaces.pop_back();
  spaces.pop_back();
  spaces.pop_back();
}

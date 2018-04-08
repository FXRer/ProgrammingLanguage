#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>

#include "BookComponent.h"

class Book : public BookComponent {
public:
  Book(std::string bookTitle, std::string bookAuthor);
  virtual ~Book();

  virtual void displayInfo();

private:
  std::string m_Title;
  std::string m_Author;
};

#endif //_BOOK_H_

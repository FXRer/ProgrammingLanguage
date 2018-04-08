#include <iostream>

#include "Book.h"

Book::Book(std::string title, std::string author)
: m_Title(title),
  m_Author(author)
{
}

Book::~Book()
{
}

void Book::displayInfo()
{
	std::cout << "Book  : " << m_Title << " by " << m_Author << "\n";
}

#ifndef _LIBRARIAN_H_
#define _LIBRARIAN_H_

#include <string>
#include "BookComponent.h"

class Librarian {
public:
	Librarian();
	virtual ~Librarian();

	void displayBookCollection();

private:
    void buildBookCollection();
    BookComponent * buildFictionGroup();
    BookComponent * buildNonfictionGroup();

    BookComponent * buildKidsGroup();
    BookComponent * buildKidsAges3To5Group();
    BookComponent * buildBiographyGroup();

    void addBookToGroup(BookComponent * group,
    		            std::string bookTitle,
    		            std::string author);

    BookComponent * m_pBookCollection;
};

#endif //_LIBRARIAN_H_

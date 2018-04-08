#include<iostream>

#include "Librarian.h"
#include "BookGroup.h"
#include "Book.h"

Librarian::Librarian()
: m_pBookCollection(new BookGroup(std::string("Book Collection")))
{
	buildBookCollection();
}

Librarian::~Librarian() {
	delete m_pBookCollection;
}

void Librarian::buildBookCollection()
{
	addBookToGroup(m_pBookCollection,
				   std::string("Merriam-Webster's Collegiate Dictionary"),
			       std::string("Merriam-Webster"));

	m_pBookCollection->add(buildFictionGroup());
	m_pBookCollection->add(buildNonfictionGroup());

}

BookComponent * Librarian::buildFictionGroup()
{
	BookComponent * fictionGroup = new BookGroup(std::string("Fiction"));

	fictionGroup->add(buildKidsGroup());

    	return fictionGroup;
}

BookComponent * Librarian::buildNonfictionGroup()
{
	BookComponent * nonfictionGroup = new BookGroup(std::string("Nonfiction"));

	nonfictionGroup->add(buildBiographyGroup());

    	return nonfictionGroup;
}

BookComponent * Librarian::buildKidsGroup()
{
	BookComponent * kidsGroup =
		new BookGroup(std::string("Kids"));

	addBookToGroup(kidsGroup,
			       std::string("Green Eggs and Ham"),
				   std::string("Dr. Suess"));

	kidsGroup->add(buildKidsAges3To5Group());

	return kidsGroup;
}

BookComponent * Librarian::buildKidsAges3To5Group()
{
	BookComponent * kidsAges3To5Group =
		new BookGroup(std::string("Kids (Ages 3-5)"));

	addBookToGroup(kidsAges3To5Group,
			       std::string("Goodnight Moon"),
				   std::string("Margaret Wise Brown"));

	return kidsAges3To5Group;
}

BookComponent * Librarian::buildBiographyGroup()
{
	BookComponent * biographyGroup = new BookGroup(std::string("Biography"));

	addBookToGroup(biographyGroup,
			       std::string("Steve Jobs"),
			       std::string("Walter Isaacson"));

	return biographyGroup;
}

void Librarian::addBookToGroup(BookComponent * group,
		std::string bookTitle, std::string author)
{
	BookComponent * book = new Book(bookTitle, author);
    	group->add(book);
}

void Librarian::displayBookCollection()
{
	m_pBookCollection->displayInfo();
}

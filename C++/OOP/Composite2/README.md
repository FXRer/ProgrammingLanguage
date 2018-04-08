Composite Pattern Example

I decided to demonstrate the Composite Pattern with a Librarian’s Book Collection. So I created a Librarian class that will act as the Client class of the pattern. I wanted to be able to display their book collection, which can include individual books and different book groups (Fiction, Nonfiction, etc). To see the book collection it has a DisplayBookCollection() method. I also created a Book object that will act as the Leaf object of the Composite Pattern and as the Composite class I have BookGroup. Each would be derived from a common abstract base class BookComponent. BookComponent would have empty implementations for an Add and Remove method that BookGroup would override with its own implementation. BookComponent also has an abstract method, DisplayInfo(). The BookComponent allows the BookGroup and Book classes be treated uniformly by its client, Librarian. 

NOTE: This example is built with C++11
      g++ -std=c++11 -g Main.cpp Book.cpp BookGroup.cpp Librarian.cpp -o Composite.o

======
Source: https://www.robertlarsononline.com/2017/05/01/composite-pattern-using-cplusplus/

#include <cstring> // for strlen()
#include <cassert> // for assert()
#include <iostream> // for cout(), endl()

class MyString
{ 
public:
    MyString(const char *data="")
    {
        assert(data); // make sure data isn't a null string
 
        // Find the length of the string
        // Plus one character for a terminator
        mLength = strlen(data) + 1;
        
        // Allocate a buffer equal to this length
        mData = new char[mLength];
        
        // Copy the parameter string into our internal buffer
        for (int i=0; i < mLength; ++i)
            mData[i] = data[i];
    
        // Make sure the string is terminated
        mData[mLength-1] = '\0';
    }

#ifdef CUSTOM_COPY_CONSTRUCTOR    
    MyString(const MyString& str) {
		mLength = str.mLength;
		
		if (str.mData != nullptr) {
			mData =  new char[mLength];
			
			for (int i=0; i<mLength; ++i) {
				mData[i] = str.mData[i];
			}
		}
		else 
			mData = nullptr;
	}
#endif

#ifdef CUSTOM_ASSIGNMENT_OPERATOR
	MyString& operator=(const MyString& str) {
		if (this == &str)
			return *this;
			
		delete []mData;
		
		mLength =  str.mLength;
		if (str.mData != nullptr) {
			mData = new char[mLength];
			
			for (int i=0; i<mLength; ++i) {
				mData[i] = str.mData[i];
			}
		}
		else 
			mData = nullptr;
			
		return *this;;		
	}
#endif
 
    ~MyString() // destructor
    {
        // We need to deallocate our string
        delete[] mData;
    }
 
    char* getString() { return mData; }
    int getLength() { return mLength; }

private:
    char *mData;
    int mLength;
};


int main()
{
    MyString hello("Hello, world!");
    {
        MyString copy = hello; // use default copy constructor
    } // copy is a local variable, so it gets destroyed here.  The destructor deletes copy's string, which leaves hello with a dangling pointer
 
    std::cout << hello.getString() << '\n'; // this will have undefined behavior
 
    return 0;
}

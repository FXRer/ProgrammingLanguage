Let’s take an example, suppose we have database application with some database as it’s back end(say MYSQL or ORACLE) and we are using a library say ‘X’ for database operation later after writing the application, we decided to change the library used for database operation,now we will use the library ‘Y’ for database operation.
Library ‘Y’ has different interfaces for Database operation.It will be difficult to change all calls for database operation from library ‘X’ to library ‘y’.
Adapter design pattern can be used is such situation.Here will keep the interface of library X as it is now.we will define an adapter for library ‘Y’ by using the calls of library ‘X’.

Steps can be summarized as follows.
1) Define an Interface by adding all the calls that library X uses in the application(Itarget).
2) Define the adapter class by implementing the interface Itarget and we will use the class Y inside this adapter class to implement each interface calls.
In other words we changed the calls of library Y to library X as application expects.

======
Source: https://cppcodetips.wordpress.com/2014/12/24/adapter-pattern-using-c/

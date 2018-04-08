 Bridge Design Pattern

The bridge design pattern allows you to separate the abstraction from the implementation.
 In the bridge pattern, there are 2 parts - 
                           1.  Abstraction
                           2.  Implementation. 

The bridge pattern allows the Abstraction and the Implementation to be developed independently, and the client code can access only the Abstraction part without being concerned about the Implementation part.


Let's look at an example to see the concept behind the bridge pattern. For example, inside a house, there are appliances that you can turn on or off, such as the floor lamp, the TV, and the vacuum cleaner. There are different ways to turn the appliance on or off, such as using the on/off switch, the pull switch, or using a remote control. The concept of turning the appliance on or off is the Abstraction part in the bridge pattern, and the user only needs to know the Abstraction part. This is the first part of the bridge pattern.

The key benefit :

    It allows you to develop the Abstraction and the Implementation parts independently.
    It also cuts down on the number of classes that you need to create to fulfill all the possible combinations of the Abstractions (user interface concepts) and the Implementations (actual actions behind the scene).



Sample example which describe Bridge Design Pattern.

======
Source: http://notes4programs.blogspot.com/2013/06/bridge-design-pattern.html

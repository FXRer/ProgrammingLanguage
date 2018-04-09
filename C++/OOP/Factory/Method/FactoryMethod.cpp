/* Assume that we are an online Music Store . We every kind of music be 
 * it Rock, Classical, Jazz, Reggae, Techno and what not. Of course, to
 *  organize these we need categories based on different genres. Lets 
 * design this model using factory design pattern. Our base class is 
 * what we do. We provide music, so say "Music" is our base class.
 * 
 * Now Music can be classified into multiple categories . We for the 
 * time being assume only three.
 * 
 *     Rock
 *     Pop
 *     Reggae
 * 
 * Here Rock, Pop and Reggae are the derived classes from base class 
 * Music.
 * 
 * We create a factory pattern for this class structure in which we 
 * provide a factory method getMusic(genre_e genre) to the user. Using 
 * this method, one can instantiate the object of any subclass by 
 * choosing the genre.
 * 
 * Here genre is the logic based on which any particular subclass is 
 * instantiated. Advantage of this pattern is that outer world need not 
 * instantiate specific objects using the different sub-class 
 * constructors. It is being masked in the implementation of factory 
 * method.
 * 
 * Moreover if any new genre needs to be added, that can be done easily 
 * just by adding a new case in Factory method.
 */ 


#include <iostream>
using namespace std;
 
enum genre_e{ROCK,POP, REGGAE, INVALID};
 
/*Base Class*/
class Music {
public:
 virtual void song() = 0;
};
 
/*Derived class Rock from Music*/
class Rock: public Music
{
public:
 void song()
 {
  cout<<"Nirvana: Smells like a teen spirit\n";
 }
};
 
/*Derived class Pop from Music*/
class Pop: public Music
{
public:
 void song()
 {
  cout<<"Michael Jackson: Billie Jean\n";
 }
};
 
/*Derived class Reggae from Music*/
class Reggae: public Music
{
public:
 void song()
 {
  cout<<"Bob Marley: No woman, No cry\n";
 }
};
 
/*Factory Class*/
class MusicFactory
{
public:
 /*Factory Method*/
 Music *getMusic(genre_e genre)
 {
  Music *music = NULL;
 
  /*Logic based on Genre*/
  switch(genre)
  {
  case ROCK:
   music = new Rock();
   break;
  case POP:
   music = new Pop();
   break;
  case REGGAE:
   music = new Reggae();
   break;
  default:
   music = NULL;
   break;
  }
  return music;
 }
};
 
int main()
{
 /*Create factory*/
 MusicFactory *musicFactory = new MusicFactory();
 
 /*Factory instantiating an object of type ROCK*/
 Music *music = musicFactory->getMusic(ROCK);
 
 cout<<"Song: ";
 if(music)
  music->song();
 else
  cout<<"Wrong selection dude/dudette !!";
}

// OUTPUT:
// Song: Nirvana: Smells like a teen spirit


// Source: http://simplestcodings.blogspot.com/2013/12/factory-method-design-pattern-in-cplusplus.html

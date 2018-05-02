// Source: http://www.cpphub.com/2015/02/proxy-design-pattern-with-example.html

#include <iostream>
#include <stdio.h>

using namespace std;
class ICar
{
public:
    virtual void identify() = 0; 
};

/* Complex class */
class Santro : public ICar {
public:
    Santro ()
        { }
    void identify () { 
        cout << "I am in the Santro class"<<endl;
    } 
};
class Audi : public ICar {
public:
    Audi ()
        { }
    void identify () { 
        cout << "I am in the Audi class"<<endl;
    } 
};

class Benz : public ICar {
public:
    Benz ()
        { }
    void identify () { 
        cout << "I am in the Benz class" <<endl;
    } 
};

class Proxy : public ICar {
private:
    ICar* m_pICar;
public:
    Proxy (ICar* pICar) : m_pICar (pICar) {}
    void identify () { 
        m_pICar->identify ();
    }
};

int main ()
{
   /* calling the Audi class */
    ICar *pcIcar = new Audi;
    Proxy objProxy (pcIcar);
    objProxy.identify();

    /* calling the Benz class */
    ICar *pcIcar1 = new Benz;
    Proxy objProxy1 (pcIcar1);
    objProxy1.identify ();

    /* calling the Santro class */
    ICar *pcIcar2 = new Santro;
    Proxy objProxy2 (pcIcar2);
    objProxy2.identify ();

    return 0;
}

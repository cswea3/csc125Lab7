#include <iostream>
#include "Array.h"

using namespace std;

int main() {

Array<float> a(3);
a.add( 1.1);
a.add( 2.2);
a.add(3.3);

Array<float> b(3);
b.add( 1.1);
b.add( 2.2);
b.add(3.3);

cout << "a: " << endl << a << endl;
cout << "b:" << endl << b << endl;

Array<float> c(3);

c = a + b;

cout << "c: " << endl << c << endl;
cout << "a: " << endl << a << endl;
cout << "b:" << endl << b << endl;


Array<int> d(3);
d.add( 1);
d.add( 2);
d.add(3);

Array<int> e(3);
e.add( 1);
e.add( 2);
e.add(3);

Array<int> f(3);

f = d + e; 

cout << f;
return 0;
}

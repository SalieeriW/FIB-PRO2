#include <list>
#include <iostream>
using namespace std;

void inter(list<int>& uno, const list<int>& dos )
 /* Pre: uno = U */
 /* Post: uno pasa a ser la interseccion de U y dos */
 {
        list<int>::iterator it_uno = uno.begin();
        list<int>::const_iterator it_dos = dos.begin();

        if (uno.empty() or dos.empty()) {
            while (it_uno != uno.end()) it_uno = uno.erase(it_uno);
        } else {
            while (it_uno != uno.end() and it_dos != dos.end()) {

                if ((*it_uno) < (*it_dos)) it_uno = uno.erase(it_uno);

                else if ((*it_uno) == (*it_dos)) {
                    ++it_dos;
                    ++it_uno;
                }
                else ++it_dos;
            }
            while (it_uno != uno.end()) it_uno = uno.erase(it_uno);
        }
 }
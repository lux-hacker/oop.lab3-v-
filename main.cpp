#include <iostream>
#include "Vector/Vector.h"

using namespace Collection;
using namespace std;

void menu();

int main() {
    Vector v;
    while(true){
        menu();
        int n;
        cin >> n;
        switch (n) {
            case 0:{
                return 0;
            }
            case 1:{
                v.setSize(0);
                break;
            }
            case 2:{
                v.setSize(1);
                cin >> v;
                break;
            }
            case 3:{
                int size;
                cout << "Enter size of vector: ";
                cin >> size;
                try{
                    v.setSize(size);
                    cout << "Enter new vector:" << endl << "--> ";
                    cin >> v;
                } catch (const invalid_argument& e) {
                    cout << "# " << e.what() << endl;
                }
                break;
            }
            case 4:{
                Vector d;
                int size;
                cout << "Enter size of second vector: ";
                cin >> size;
                try{
                    d.setSize(size);
                    cout << "Enter second vector:" << endl << "--> ";
                    cin >> d;
                    v = v + d;
                } catch (const invalid_argument& e) {
                    cout << "# " << e.what() << endl;
                }
                break;
            }
            case 5:{
                cout << "Enter new element: ";
                int a; cin >> a;
                v = v + a;
                break;
            }
            case 6:{
                cout << "Increasing (1) or decreasing (2) sub-vector?";
                int a; cin >> a;
                Vector d = v.findFirstSub(a == 1);
                cout << d << endl;
                break;
            }
            case 7:{
                cout << v.countUniq() << endl;
                break;
            }
            case 8:{
                cout << "Enter number: ";
                int a; cin >> a;
                cout << v.count(a) << endl;
                break;
            }
            case 9:{
                cout << v << endl;
                break;
            }
            default:{
                cout << "# ControllerException::invalid_argument" << endl;
            }
        }
    }
}

void menu(){
    cout << "======[MAIN MENU]======" << endl;
    cout << "0) Exit" << endl;
    cout << "1) Create empty vector" << endl;
    cout << "2) Create 1-D vector" << endl;
    cout << "3) Create n-D vector" << endl;
    cout << "4) Sum vector" << endl;
    cout << "5) Add to end" << endl;
    cout << "6) Find first sort sub-vector" << endl;
    cout << "7) Count uniq values" << endl;
    cout << "8) Count element" << endl;
    cout << "9) Print vector" << endl;
    cout << "--> ";
}

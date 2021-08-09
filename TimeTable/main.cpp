#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "Header.h"
#include "one more header.h"
 
using namespace std;

int main() {
    vector<Tutu> time_table(0);
    for(int i = 0; i < 5; i++)
        time_table.push_back(Tutu());
    time_table = QckSort(time_table);
    for(int i = 0; i < 5; i++)
        cout << time_table[i].get_time().first << ' ' << time_table[i].get_time().second << endl;
    int c;
    Tutu a;

    do
    {
        cout << "Enter 0, if you want print regular timetable, enter 1, if you want to fill in the timetable, enter 2, if you want to see an arbitraty (random) timetable \n" ;
        cin >> c;
    } while (c != 0 && c != 1 && c != 2 );
    
    switch (c)
    {
        case 0:
            QckSort({time_table.cbegin(), time_table.cbegin() + time_table.size()});
            a.get();
            do
            {
                cout << "Enter 3, if you want to fill in the timetable or if you want to close the prog, just enter 4 \n";
                cin >> c;
            } while (c != 3 && c != 4);
            switch (c)
            {
                case 3:
                    a.set();
                    a.get();
                    break;
                case 4:
                    return 0;
            }
        case 1:
            a.set();
            QckSort({time_table.cbegin(), time_table.cbegin() + time_table.size()});
            a.get();
            break;
            
        case 2:
            a.random_route();
            a.get();
            QckSort({time_table.cbegin(), time_table.cbegin() + time_table.size()});
            do
            {
                cout << "Enter 3, if you want to fill in the timetable, or if you want to close the prog, just enter 4 \n";
                cin >> c;
            } while (c != 3 && c != 4);
            switch (c){
                case 3:
                    a.set();
                    a.get();
                    break;
                case 4:
                    break;
            }


    }
    return 0;
}




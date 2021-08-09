#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "Header.h"
#include "one more header.h"
using namespace std;


vector<Tutu> QckSort(vector<Tutu> voyage){
    unsigned long n = voyage.size();
    if (n == 1 || n == 0){
        return voyage;
    }
    unsigned long i = 0, j = 0;
    pair<int, int> x = voyage[n - 1].get_time();
    i = 0; //start
    j = n - 2; //start
    while (i < j)
    {
        if ((comparator(voyage[i].get_time(), x)) && (comparator(voyage[j].get_time(), x)))
            j--;
        else if ((comparator(voyage[i].get_time(), x)) && (comparator(x, voyage[j].get_time()))){
            swap(voyage[i], voyage[j]);
            i++;
            j--;
        }
        else if ((comparator(x, voyage[i].get_time())) && (comparator(voyage[j].get_time(), x))){
            i++;
            j--;
        }
        else
            i++;
    }
    if (comparator(voyage[i].get_time(), x)) {
        swap(voyage[j], voyage[n - 1]);
        QckSort({voyage.cbegin(), voyage.cbegin() + j});
        QckSort({voyage.cbegin()+ j + 1, voyage.cbegin() + n - j - 1});
    }
    else{
        swap(voyage[j + 1], voyage[n - 1]);
        QckSort({voyage.cbegin(), voyage.cbegin() + j + 1});
        QckSort({voyage.cbegin()+ j + 2, voyage.cbegin() + n - j - 2});
    }
    return voyage;
}



Tutu::Tutu(){

    random_route();

}

void Tutu::get(){
    cout << "Train #" << name.second << " named " << name.first << endl;
    cout << "Depart from " << route.first << " arrive to " << route.second << endl;
    cout << "Departure time " << departure.first << ":" << departure.second << endl;
    cout << "Arrival time " << arrival.first << ":" << arrival.second << endl;
}

void Tutu::set(){
    cout << "Please enter train number(int) and name(string)";
    cin >> name.second >> name.first;
    cout << "Please enter departure(string) and arrival(string)";
    cin >> route.first >> route.second;
    cout << "Please enter departure time(two int values)";
    cin >> departure.first >> departure.second;
    cout << "Please enter arrival time(two int values)";
    cin >> arrival.first >> arrival.second;
}

void Tutu::random_route(){
    int i, j, k;
    do{
        i = rand()%10;
        j = rand()%10;
        k = rand()%3;
    }while(i == j);
    string city_array[10] = {"Moscow", "Kiev", "Orel", "Leningrad", "Novosibirsk", "Kalinigrad", "Ryazan", "Samara", "Volgograd", "Ekaterininburg"};
    string nom[3] = {"Sapsan", "Firmenniy", "Skoriy"};
    name.first = nom[k];
    name.second = rand()%500  + 500;
    route.first = city_array[i];
    route.second = city_array[j];
    departure.first = rand()%23;
    departure.second = rand()%60;
    arrival.first = rand()%23;
    arrival.second = rand()%60;
}

pair<int, int> Tutu::get_time(){
    return departure;
}

bool comparator(pair<int, int> x, pair<int, int> y) {
    if ((x.first > y.first) || (x.first == y.first && x.second > y.second))
        return true;
    return false;
}

//void file_out(FILE* f, class Tutu *voyage, int n)
//{
//    int i;
//    if ((f = fopen("/Users/kristinaTsulaya/Documents/file.txt", "w")) == NULL)
//        printf("error");
//    for (i = 0; i < n; i++)
//    {
//        fprintf(f,"Train %s\t", (*(voyage + i)).name);
//        fprintf(f,"number %d\n", (*(voyage + i)).number);
//        fprintf(f,"%s\n", (*(voyage + i)).departure);
//        fprintf(f,"Departure time %d:%d\n", (*(voyage + i)).departurehours, (*(voyage + i)).departureminuts);
//        fprintf(f,"%s\n", (*(voyage + i)).arrival);
//        fprintf(f,"Arrival time %d:%d\n", (*(voyage + i)).arrivalhours, (*(voyage + i)).arrivalminuts);
//    }
//    fclose(f);
//}

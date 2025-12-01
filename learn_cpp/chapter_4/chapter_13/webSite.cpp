#include <iostream>
using namespace std;
//You are running a website, and you are trying to calculate your advertising revenue. Write a program that allows you to enter 3 pieces of data:

// How many ads were watched.
// What percentage of users clicked on an ad.
// The average earnings per clicked ad.

// Store those 3 values in a struct. Pass that struct to another function that prints each of the values.
// The print function should also print how much you made for that day (multiply the 3 fields together).
struct webSite
{
    double adsWatched {};
    double usersClicks {};
    double avgEarning {};
};

void printValues(const webSite& ads)
{
    cout << "adsWatched: " << ads.adsWatched << endl;
    cout << "avgEarning: " << ads.avgEarning << endl;
    cout << "usersClicks: " << ads.usersClicks << endl;
    cout << "Total earning for the day = " << ads.adsWatched * ads.avgEarning * ads.usersClicks;
}

void dataInput (webSite& input)
{
    cout << "Enter How many ads were watched" << endl;
    cin >> input.adsWatched;
    cout << "What percentage of users clicked on an ad" << endl;
    cin >> input.avgEarning;
    cout << "The average earnings per clicked ad" << endl;   
    cin >> input.usersClicks;
}

int main ()
{
    webSite firstwebsite {};
    dataInput(firstwebsite);
    printValues(firstwebsite);
    return 0;
}
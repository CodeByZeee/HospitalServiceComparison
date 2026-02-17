#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    ifstream file("hospitals.txt");

    if(!file){
        cout<<"File not opened\n";
        return 0;
    }

    string userLocation, userTest;

    cout<<"Enter your location: ";
    getline(cin,userLocation);

    cout<<"Enter test name (CBC/XRay/ECG etc): ";
    getline(cin,userTest);

    string line;
    string hospital, location, test;
    int price;

    int minPrice = 999999;
    string bestHospital = "";

    while(getline(file,line)){

        if(line=="") continue;

        stringstream ss(line);

        getline(ss,hospital,',');
        getline(ss,location,',');
        getline(ss,test,',');
        ss>>price;

        // filtering
        if(location==userLocation && test==userTest){

            if(price < minPrice){
                minPrice = price;
                bestHospital = hospital;
            }
        }
    }

    if(bestHospital=="")
        cout<<"No hospital found in your area\n";
    else{
        cout<<"\nBest Hospital: "<<bestHospital<<endl;
        cout<<"Lowest Price: "<<minPrice<<endl;
    }

    return 0;
}
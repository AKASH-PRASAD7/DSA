#include<iostream>
#include <map> 
#include <set>
using namespace std;


int main(){

    map<string,int> myMpa;

    myMpa.insert({"Akash",69});
    myMpa.insert({"josn",29});
    myMpa.insert({"sosn",233});
    myMpa.insert({"so34n",433});

    cout<<myMpa.at("Akash");
    cout<<endl;
    // cout<<myMpa.at("Akas"); // will throw error
    cout<<endl;
    cout<<myMpa["Akash"]; 
    cout<<endl;
    cout<<myMpa["Akas"]; // will not throw error
    cout<<endl;

    cout<<myMpa.size();
    cout<<endl;
    cout<<myMpa.max_size();
    cout<<endl;
    cout<<myMpa.empty();
    cout<<endl;
    cout<<myMpa.count("Akash");
    cout<<endl;
    cout<<myMpa.count("Akas");
    cout<<endl;
    cout<<myMpa.find("Akash")->first;
    cout<<endl;

    set<string> mySet;
    mySet.insert("Akash");
    mySet.insert("Akash");
    mySet.insert("Akash");
    mySet.insert("Akash");

    cout<<mySet.size();
    cout<<endl;
    cout<<mySet.max_size();
    cout<<endl;
    cout<<mySet.empty();
    cout<<endl;
 

}
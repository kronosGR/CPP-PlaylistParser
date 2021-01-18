/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kronos
 *
 * Created on March 19, 2020, 6:22 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;
string artist ="";
string title="";

void splitName(string sep, string fullname){
    if (sep==":"){
        int pos = fullname.find(sep);
        artist = fullname.substr(0, pos);
        title = fullname.substr(pos+1, fullname.length());
    }
    else if (sep == "-"){
        int pos = fullname.find(sep);
        title = fullname.substr(0, pos);
        artist = fullname.substr(pos+1, fullname.length());        
    }
    else if (sep == " by "){
        int pos = fullname.rfind(sep);
        title = fullname.substr(0, pos);
        artist = fullname.substr(pos+3, fullname.length());          
    }    
}

/**
 * stripes of spaces from both ends
 * @param stringToStripped - the string
 * @return - stripped string
 */
string trim(string stringToStripped){
    string retValue = stringToStripped;
    int lastPosition = retValue.length() -1;    
    bool found = true;
    
    while (found == true && lastPosition >= 0)
    {
        if (retValue.substr(lastPosition,1) == " "){
            retValue = retValue.erase(lastPosition,1);
        }
        else if (retValue.substr(0,1) == " ")
        {            
            retValue = retValue.erase(0,1);
        } 
        else {
            found = false;
        }
        lastPosition =  retValue.length() -1;
    }
    
    
    return retValue;
}

/*
 * 
 */
int main(int argc, char** argv) {

    while(true){
        title = "";
        artist = "";
        cout << "Enter a track or 'Q' to quit." << endl;
        string fullname;
        getline(cin, fullname);
        
        if (fullname == "q"){
            break;
        } 
        if (fullname.length() <5){
            cout << "Please enter a track with more than five characters." << endl;
        } 
        else 
        {
            //check for colon :
            if (fullname.find(":") != string::npos){
                splitName(":", fullname);
            }
            //check for hyphen -
            else if (fullname.find("-") != string::npos){
                splitName("-", fullname);                
            }
            //check
            else if (fullname.find(" by ")  != string::npos){
                splitName(" by ", fullname);                   
            }
        }
        cout << "TITLE: " << trim(title) << endl;
        cout << "ARTIST: " << trim(artist) << endl;
    }
    return 0;
}


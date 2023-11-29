/*==========================================================

 Title:     Assignment 10 (Final) - C++ Currency Translation Machine
 Course:  	CIS 2252
 Author:  	<mohammed tanvvir>
 Date:    	< 8/10 /23 >
 Description: This program ....

 ==========================================================
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class ctm{
    public:
    string ctype;
    float amm;
    float cfactor;
    float ammInD;
    float tax;
    float tAmm;
    ctm(){
        ctype = "";
        amm = 0;
    }
    void intro(){
        while(1){
            int t;cin>>t;
            if(t == 1){
                ctype = "Yuan";
                cfactor = 6.77;
                break;
            }
            else if(t == 2){
                ctype = "Euro";
                cfactor = 0.98;
                break;
            }
            else if(t == 3) {
                ctype = "Pounds";
                cfactor = 0.83;
                break;
        }
        cout << "Invalid Entry, please enter a number 1-3:\n";
    }
    }
};
class amount: public ctm{
    public:
    void calculations(){
        cin>>amm;
        ammInD = amm/cfactor;
        tax = ammInD*0.05;
        tAmm = ammInD + tax;
    }
};
class rc:public amount{
    public:
    void rctype(){
        ofstream MyFile("filename.txt");
        MyFile<<fixed;
        MyFile<<setprecision(2);
        MyFile<<ammInD<<" "<<"dollars\n";
        MyFile<<tax<<" dollars\n";
        MyFile<<tAmm<<" dollars\n";
        MyFile.close();
        cout<<fixed;
        cout<<setprecision(2);
        cout<<amm<<" "<<ctype<<"\n";
        cout<<ammInD<<" " <<"dollars \n";
        cout<<tax<<" dollars\n";
        cout<<tAmm<<" dollars\n";
        
        
    }
};



int main(){
    //No need to modify main as everything should be handled in the classes
    rc obj; 
    obj.ctm::intro();
    obj.amount::calculations();
    obj.rctype();
    
}


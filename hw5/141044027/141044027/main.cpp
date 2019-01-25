/**
 * Homework5_Burak_Özdemir_141044027
 ****************************************
 * Created on 26.11.2017 by Burak_Özdemir
 ****************************************
 * Bu program ConnectFour adlı bir oyunun C++ dilinde
 * yazılmış ufak bir simulasyonudur.Oyunun oynanısına ve
 * kurallarına internetten bakabilirsniz.
 ******************************************
 *              ==Notes==
 */
#include <iostream>
#include <fstream>
#include "Cell.h"
#include "ConnectFourAbstract.h"
#include "ConnectFourDiag.h"
#include "ConnectFourPlusUndo.h"
#include "ConnectFourPlus.h"
using namespace std;
using namespace ConnectSpace;
int testP();
int testD();
int testU();
int main() {
    string temp;
    bool flag=true;
    cout<<"Welcome to ConnectFour Game !!"<<endl;
    while(flag){
        cout<<"MOd girin:";getline(cin, temp);cout<<endl;
        if(temp=="P"){
            testP();
            flag=false;
        }
        if(temp=="D"){
            testD();
            flag=false;
        }
        if(temp=="U"){
            testU();
            flag=false;
        }
        if(cin.eof()==true){
            cout<<"oyun sonlanıyor.."<<endl;
            exit(1);
        }
    }
    cout<<"Game is finished!!"<<endl;

}

int testP(){
    ConnectFourPlus object;
    object.playGame();
}
int testD(){
    ConnectFourDiag object;
    object.playGame();
}
int testU(){
    ConnectFourPlusUndo object;
    object.playGame();
}


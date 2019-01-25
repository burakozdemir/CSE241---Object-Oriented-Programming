#include <iostream>
#include <iostream>
#include "ConnectFour.h"

using namespace std;
int testSingle();
int testMulti();
int main() {
    string temp;
    bool flag=true;
    cout<<"Welcome to ConnectFour Game !!"<<endl;
    while(flag){
        cout<<"MOd girin:";getline(cin, temp);cout<<endl;
        if(temp=="S"){
            testSingle();
            flag=false;
        }
        if(temp=="M"){
            testMulti();
            flag=false;
        }
        if(cin.eof()==true){
            cout<<"oyun sonlanıyor.."<<endl;
            exit(1);
        }
    }
    cout<<"Game is finished!!"<<endl;
}

int testSingle(){
    string temp;
    ConnectFour object;
    object.playGame();
}

int testMulti(){
    string temp;
    bool flag=true;
    ConnectFour objArr[5];
    for (int i = 0; i < 5; ++i) {
        if(cin.eof()==true){
            cout<<"oyun sonlanıyor.."<<endl;
            exit(1);
        }
        cout<<"dosya adı:";getline(cin, temp);cout<<endl;
        objArr[i].setObject(temp);
        flag=true;
        while(flag){
            cout<<"user mod:";getline(cin, temp);cout<<endl;
            if(temp=="P" || temp=="C"){
                objArr[i].setUserMod(temp);
                flag=false;
            }
            if(cin.eof()==true){
                cout<<"oyun sonlanıyor.."<<endl;
                exit(1);
            }
        }
    }
    //ConnectFour tempObj;
    objArr[0].playGameMulti(objArr);
}

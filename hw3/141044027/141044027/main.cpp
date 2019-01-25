#include <iostream>
#include "ConnectFour.h"

using namespace std;


int main(){

    /*
    vector<vector<int>> a(10,vector<int>(5));
    vector<vector<int>> b=a;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            b[i][j]=5;
        }
    }
    cout<<b.size()<<endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }*/
    /*
    ConnectFour mainobject(10,5,"S","P",0);
    for (int i = 0; i < mainobject.getHeight(); ++i) {
        for (int j = 0; j < mainobject.getWidth(); ++j) {
            cout<<mainobject.getCellContent(mainobject.getGameCells(i,j))<<" ";
        }
        cout<<endl;
    }*/

    ConnectFour mainobject;
    mainobject.playGame();

    ConnectFour::getAliveCellsOfObjects();
     return 0;
}
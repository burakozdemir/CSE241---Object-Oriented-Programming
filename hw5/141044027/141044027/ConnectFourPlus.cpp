//
// Created by burki on 23.11.2017.
//

#include "ConnectFourPlus.h"
namespace ConnectSpace {
    ConnectFourPlus::ConnectFourPlus():ConnectFourAbstract(){}
    ConnectFourPlus::ConnectFourPlus(const int numberRow, const int numberCol) :
            ConnectFourAbstract(numberRow, numberCol){
    }
    ConnectFourPlus::ConnectFourPlus(string filename) : ConnectFourAbstract(filename){}
    ConnectFourPlus::ConnectFourPlus(const ConnectFourPlus &object) : ConnectFourAbstract(object){}
    ConnectFourPlus::~ConnectFourPlus() {}
    ConnectFourPlus &ConnectFourPlus::operator=(const ConnectFourPlus &object) {
        ConnectFourAbstract::operator =(object);
        return *this;
    }
    int ConnectFourPlus::checkWin(int user) {
        if(user==1){
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    if(gameBoard[i][j].getContent()=='X'){
                        if(control8Way('X',i,j)) {
                            return 1;
                        }
                    }
                }
            }
        }
        if(user==2){
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    if(gameBoard[i][j].getContent()=='O'){
                        if(control8Way('O',i,j)){
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    int ConnectFourPlus::control8Way(char user, int coord1, int coord2) {
        if(coord1-1>=0 && gameBoard[coord1-1][coord2].getContent()==user ){
            if(coord1-2>=0 && gameBoard[coord1-2][coord2].getContent()==user){
                if(coord1-3>=0 && gameBoard[coord1-3][coord2].getContent()==user){
                    return 1;
                }
            }
        }
        //sag yatay
        if(coord2+1<width && gameBoard[coord1][coord2+1].getContent()==user ){
            if(coord2+2<width && gameBoard[coord1][coord2+2].getContent()==user){
                if(coord2+3<width && gameBoard[coord1][coord2+3].getContent()==user){
                    return 1;
                }
            }
        }
        //alt dikey
        if(coord1+1<height && gameBoard[coord1+1][coord2].getContent()==user ){
            if(coord1+2<height && gameBoard[coord1+2][coord2].getContent()==user){
                if(coord1+3<height && gameBoard[coord1+3][coord2].getContent()==user){
                    return 1;
                }
            }
        }
        //sol yatay
        if(coord2-1>=0 && gameBoard[coord1][coord2-1].getContent()==user ){
            if(coord2-2>=0 && gameBoard[coord1][coord2-2].getContent()==user){
                if(coord2-3>=0 && gameBoard[coord1][coord2-3].getContent()==user){
                    return 1;
                }
            }
        }
        return 0;
    }
}
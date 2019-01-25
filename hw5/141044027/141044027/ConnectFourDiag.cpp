//
// Created by burki on 23.11.2017.
//

#include "ConnectFourDiag.h"

namespace ConnectSpace {
    ConnectFourDiag::ConnectFourDiag():ConnectFourAbstract(){}
    ConnectFourDiag::ConnectFourDiag(const int numberRow, const int numberCol) :
            ConnectFourAbstract(numberRow, numberCol){
    }
    ConnectFourDiag::ConnectFourDiag(string filename) : ConnectFourAbstract(filename){}
    ConnectFourDiag::ConnectFourDiag(const ConnectFourDiag &object) : ConnectFourAbstract(object){}
    ConnectFourDiag::~ConnectFourDiag() {}
    ConnectFourDiag &ConnectFourDiag::operator=(const ConnectFourDiag &object) {
        ConnectFourAbstract::operator =(object);
        return *this;}
    int ConnectFourDiag::checkWin(int user) {
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
    int ConnectFourDiag::control8Way(char user, int coord1, int coord2) {
        //ust sag kose
        if(coord1-1>=0 && coord2+1<width && gameBoard[coord1-1][coord2+1].getContent()==user ){
            if(coord1-2>=0 && coord2+2<width && gameBoard[coord1-2][coord2+2].getContent()==user){
                if(coord1-3>=0 && coord2+3<width && gameBoard[coord1-3][coord2+3].getContent()==user){
                    return 1;
                }
            }
        }
        //alt sag kose
        if(coord1+1<height && coord2+1<width && gameBoard[coord1+1][coord2+1].getContent()==user ){
            if(coord1+2<height && coord2+2<width && gameBoard[coord1+2][coord2+2].getContent()==user){
                if(coord1+3<height && coord2+3<width && gameBoard[coord1+3][coord2+3].getContent()==user){
                    return 1;
                }
            }
        }
        //sol alt kose
        if(coord1+1<height && coord2-1>=0 && gameBoard[coord1+1][coord2-1].getContent()==user ){
            if(coord1+2<height && coord2-2>=0 && gameBoard[coord1+2][coord2-2].getContent()==user){
                if(coord1+3<height && coord2-3>=0 && gameBoard[coord1+3][coord2-3].getContent()==user){
                    return 1;
                }
            }
        }
        //sol ust kose
        if(coord1-1>=0 && coord2-1>=0 && gameBoard[coord1-1][coord2-1].getContent()==user ){
            if(coord1-2>=0 && coord2-2>=0 && gameBoard[coord1-2][coord2-2].getContent()==user){
                if(coord1-3>=0 && coord2-3>=0 && gameBoard[coord1-3][coord2-3].getContent()==user){
                    return 1;
                }
            }
        }
        return 0;
    }
}
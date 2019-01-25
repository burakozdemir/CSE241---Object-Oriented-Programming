//
// Created by burki on 14.10.2017.
//
/**
 * Homework3_Burak_Özdemir_141044027
 ****************************************
 * Created on 19.10.2017 by Burak_Özdemir
 ****************************************
 * Bu program ConnectFour adlı bir oyunun C dilinde
 * yazılmış ufak bir simulasyonudur.Oyunun oynanısına ve
 * kurallarına internetten bakabilirsniz.
 ******************************************
 *              ==Notes==
 *Multi mod için çalıştırılacak obje sayısı userdan alınır .
 * deneme.txt useruser
 * deneme2.txt usercomputer
 * deneme3.txt emptyfile
 */

#ifndef HW3_CONNECTFOUR_H
#define HW3_CONNECTFOUR_H

#include <vector>
#include <string>
using namespace std;


class ConnectFour {
private:
    class Cell {
    public:
        Cell();
        inline string getContent()const{return content;}
        inline int getCol()const{return col;}
        inline int getRow()const{return row;}
        void setContent(string value){content=value;}
        void setCol(int value){col=value;}
        void setRow(int value){row=value;}
    private:
        string content;
        int col;
        int row;
    };
    static vector<ConnectFour> objects;
    int height;
    int width;
    string gameMod;
    string userMod;
    int objectNumber;
    vector<vector<Cell>> gameCells;
    int userSira;
    bool gameEnded;
    static int aliveCell;
    ///my other functions
    int helperForCompareFunc(string user,int &count)const;///compare fonskyionu için yardımcı
    int isCellEmpty(int choice);///hücrenin bos olup olmaması kontrolü
    int isChoiceKontrol(string value);///inputun legal olup olmaması
    int isBoardEmpty();///boardun dolulugunu kontrol edilmesi
    int isColumnEmpty(int choice);//////seçilen kolonun dolu olup olmaması
    int charToInt(char value);///karakterden integera cevirme
    int checkWin(int user);///herhangi bir kullanıcının oyunu bitirme kontrolü
    int gameSingle();///single mod
    int gameMulti();///multi mod
    int UUMulti();///user vs user multi mod
    int UCMulti();///user vs comp multi mod
    int UUSingle(int user=0);///user vs user single mod
    int UCSingle(int user=0);///user vs comp single mod
    int refactorObjects(int objectNumber);///objeleri düzenleyip kullanıma hazır hale getirir
    int objectInputKontrol(int &en,int &boy,string &usermod);///objelerin inputlarını kontrol eder
    int startInputTakeSingle(string &usermod,int &width, int &height);///kullanıcıdan ınput alırken kontrol yapar
    int startingGame();///oyun baslarken gamecells in doldurulması
    int control8Way(string user,int coord1,int coord2);/////CheckWin fonksiyonu ıcın 8 yonu kontrol eder
    int columnKontrol(string value);///seçilen kolonun dolu olup olmaması
    ///-------------------
    int computer();///USER Computer modu için Computer FOnksıyonu
    int kontrolComputer(int &coord2);///Computer tas gruplarının oncelık sırasına gore davranır
    int kontrol3tas(int &targetCoord2);///3lü tas grubu belırler
    int kontrol2tas(int &targetCoord2);///2li tas grubu belırler
    int kontrol1tas(int &targetCoord2);///1li tas grubu belırler
    int engelleme2();////userin 3 tasi kznmk icin dzlyse ona krsi hmle yptrir
    int engelleme();///userin 3 tasi kznmk icin dzlyse ona krsi hmle yptrir
    int engelleme3();///sinirda 2li tas engelliyo
    int firstMove();///Computerın ilk hareketi
    ///---------------
    //////////////////////
public:
    ///constructors
    ConnectFour();
    ConnectFour(const int &width,const int &height,const string &usermod,const int &objectNumber);
    ConnectFour(const int &width,const int &height,const string &gamemod,const string &usermod,const int &objectNumber);
    ConnectFour(const ConnectFour &object);
    ///setters and getters
    void setAliveCells(int value){aliveCell=value;}
    void setGameEnded(bool value){gameEnded=value;}
    void setUserMod(string value){userMod=value;}
    void setGameCells(Cell value);
    void setObjectNumber(int value){objectNumber=value;}
    void setGameMod(string value){gameMod=value;}
    void setWidth(int value){width=value;}
    void setHeight(int value){height=value;}
    void setUserSira(int value){userSira=value;}
    inline bool getGameEnded()const{return gameEnded;}
    inline int getUserSira()const{return userSira;}
    inline int getObjectNumber()const{return objectNumber;}
    inline string getUserMod()const{return userMod;}
    inline string getGameMod()const{return gameMod;}
    inline Cell getGameCells(int i,int j)const{return gameCells.at(i).at(j);}
    inline string getCellContent(Cell obj)const{return obj.getContent();}
    static int getAliveCells(){return aliveCell;}
    ///other functions
    bool isGameEnded();
    static int getAliveCellsOfObjects();
    int readFileMulti(string filename);
    int readFile(string filename);
    int writeFile(string filename,int user,int userMod);
    int writeFileMulti(string filename,int user,string userMod);
    int getHeight()const{return height;}
    int getWidth()const{return width;}
    int play();///it plays computer
    int play(int cellPos);///it plays user(user hedefini alır)
    int playGame();///ana fonksiyon gibi
    bool compare(const ConnectFour &object)const;///iki objecti karşılaştrır
    void printBoard();
};


#endif //HW3_CONNECTFOUR_H

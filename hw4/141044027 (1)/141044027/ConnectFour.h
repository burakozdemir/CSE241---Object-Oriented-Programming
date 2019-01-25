/**
 * Homework4_Burak_Özdemir_141044027
 ****************************************
 * Created on 17.11.2017 by Burak_Özdemir
 ****************************************
 * Bu program ConnectFour adlı bir oyunun C++ dilinde
 * yazılmış ufak bir simulasyonudur.Oyunun oynanısına ve
 * kurallarına internetten bakabilirsniz.
 ******************************************
 *              ==Notes==
 *Multi mod için çalıştırılacak obje sayısı SABİT 5 TİR.
 */
#ifndef HW4_CONNECTFOUR_H
#define HW4_CONNECTFOUR_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class ConnectFour{
private :
    class Cell{
    public:
        Cell();
        Cell(char content,int row,int col,int cellcontent);
        inline char getContent()const{return content;}
        inline int getCol()const{return col;}
        inline int getRow()const{return row;}
        inline int getCellContent()const{return cellContent;}
        void setCellContent(int value){cellContent=value;}
        void setContent(char value){content=value;}
        void setCol(int value){col=value;}
        void setRow(int value){row=value;}
        ///operator overloaded
        bool operator ==(const Cell& obj);
        Cell operator ++();
        Cell operator ++(int);
        Cell operator --();
        Cell operator --(int);
        istream & operator >>(istream& result);
        ostream & operator <<(ostream& result);
    private:
        char content;
        int col;
        int row;
        int cellContent;
    };
    Cell ** gameBoard;
    string userMod;
    int height;
    int width;
    int objectNumber;
    int numberOfObject;
    int userSira;
    bool gameEnded;
    static int aliveCell;
    ///myother functions
    int UUMulti();///user vs user multi mod
    int UCMulti();///user vs comp multi mod
    int UUSingle(int user=0);///user vs user single mod
    int UCSingle(int user=0);///user vs comp single mod
    int isCellEmpty(int choice);///hücrenin bos olup olmaması kontrolü
    int isChoiceKontrol(string value);///inputun legal olup olmaması
    int isBoardEmpty();///boardun dolulugunu kontrol edilmesi
    int isColumnEmpty(int choice);//////seçilen kolonun dolu olup olmaması
    int charToInt(char value);///karakterden integera cevirme
    int checkWin(int user);///herhangi bir kullanıcının oyunu bitirme kontrolü
    int control8Way(char user,int coord1,int coord2);/////CheckWin fonksiyonu ıcın 8 yonu kontrol eder
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
    int boslukKontrolComp(int indis);///boarddaki space kontrol
    int boslukKontrol(string choice);///boarddaki space kontrol
    int cinKontrol();///inputları dosyadan alrkken eof kontrol
public:
    ConnectFour();///5 ConnectFour oyun olusturcak
    ConnectFour(const int numberRow,const int numberCol);///genislik ve yukselige gore bos board olusturur
    ConnectFour(string filename);///dosyaya gore board olusturur

    ///big tree
    ConnectFour(const ConnectFour & object);///copy constructor
    ~ConnectFour();///destructor
    ConnectFour& operator =(const ConnectFour& object);///assignment operator overload
    ///setters and getters
    void setAliveCells(int value){aliveCell=value;}
    void setGameEnded(bool value){gameEnded=value;}
    void setUserMod(string value){userMod=value;}
    void setObjectNumber(int value){objectNumber=value;}
    void setWidth(int value){width=value;}
    void setHeight(int value){height=value;}
    void setUserSira(int value){userSira=value;}
    inline bool getGameEnded()const{return gameEnded;}
    inline int getUserSira()const{return userSira;}
    inline int getObjectNumber()const{return objectNumber;}
    inline string getUserMod()const{return userMod;}
    inline Cell getGameCells(int i,int j)const{return gameBoard[i][j];}
    inline char getCellContent(Cell obj)const{return obj.getContent();}
    static int getAliveCells(){return aliveCell;}
    ///operator overloads
    friend bool operator ==(const ConnectFour& obj1,const ConnectFour& obj2);
    friend bool operator !=(const ConnectFour& obj1,const ConnectFour& obj2);
    ///other functions
    void setObject(string filename);///olusturulan objeyi dosyaya gore tekrar resize ediyor
    bool isGameEnded();///oyun bitmisse true dondurur.multi mod icin gerekli
    int readFileMulti(string filename);///multi modda input dosya ismi ise o objeyi dosyaya gore duzneler
    int readFile(string filename);///single mod icin input dosya ismi ise o objeyi dosyaya gore duzneler
    int writeFile(string filename,int user,int userMod);///single modda objeyi dosyaya yazar
    int writeFileMulti(string filename,int user,string userMod);///multi modda objeyi dosyaya yazar
    void printBoard();///board ı ekrana basar
    inline int getHeight()const{return height;}
    inline int getWidth()const{return width;}
    int play();///it plays computer
    int play(int cellPos);///it plays user(user hedefini alır)
    int playGame();///single game icin ana fonksyion
    int playGameMulti(ConnectFour objects[5]);///multi game icin ana fonksyion
    ///my other functions
};
#endif //HW4_CONNECTFOUR_H

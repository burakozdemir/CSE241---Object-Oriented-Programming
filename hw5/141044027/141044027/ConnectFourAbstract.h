//
// Created by burki on 23.11.2017.
//

#ifndef HW5_CONNECTFOURABSTRACT_H
#define HW5_CONNECTFOURABSTRACT_H
#include "Cell.h"

namespace ConnectSpace {
    class ConnectFourAbstract {
    public:
        ConnectFourAbstract();///
        ConnectFourAbstract(const int numberRow,const int numberCol);///genislik ve yukselige gore bos board olusturur
        ConnectFourAbstract(string filename);///dosyaya gore board olusturur
        ///big tree
        ConnectFourAbstract(const ConnectFourAbstract & object);///copy constructor
        ~ConnectFourAbstract();///destructor
        ConnectFourAbstract& operator =(const ConnectFourAbstract & object);///assignment operator
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
        ///other functions
        void setObject(const int width, const int height);///olusturulan objeyi dosyaya gore tekrar resize ediyor
        bool isGameEnded();///oyun bitmisse true dondurur.multi mod icin gerekli
        virtual int readFile(string filename);///single mod icin input dosya ismi ise o objeyi dosyaya gore duzneler
        virtual int writeFile(string filename,int user,int userMod);///single modda objeyi dosyaya yazar
        void printBoard();///board ı ekrana basar
        inline int getHeight()const{return height;}
        inline int getWidth()const{return width;}
        virtual int play();///it plays computer
        virtual int play(int cellPos);///it plays user(user hedefini alır)
        virtual int playGame();///single game icin ana fonksyion
    protected:
        Cell ** gameBoard;
        string userMod;
        int height;
        int width;
        int objectNumber;
        int userSira;
        bool gameEnded;
        static int aliveCell;
        ///myother functions
        int startInputTakeSingle(string &usermod,int &width, int &height);
        virtual int SingleP(int user=0);///user vs user single mod
        virtual int SingleC(int user=0);///user vs comp single mod
        int isCellEmpty(int choice);///hücrenin bos olup olmaması kontrolü
        int isChoiceKontrol(string value);///inputun legal olup olmaması
        int isBoardEmpty();///boardun dolulugunu kontrol edilmesi
        int isColumnEmpty(int choice);//////seçilen kolonun dolu olup olmaması
        int charToInt(char value);///karakterden integera cevirme
        virtual int checkWin(int user)=0;///herhangi bir kullanıcının oyunu bitirme kontrolü
        virtual int control8Way(char user,int coord1,int coord2)=0;/////CheckWin fonksiyonu ıcın 8 yonu kontrol eder
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

    };
}


#endif //HW5_CONNECTFOURABSTRACT_H

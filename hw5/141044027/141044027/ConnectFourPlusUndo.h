//
// Created by burki on 23.11.2017.
//

#ifndef HW5_CONNECTFOURPLUSUNDO_H
#define HW5_CONNECTFOURPLUSUNDO_H
#include "ConnectFourPlus.h"
namespace ConnectSpace {

    class ConnectFourPlusUndo : public ConnectFourPlus {
    public:
        ConnectFourPlusUndo();///
        ConnectFourPlusUndo(const int numberRow,const int numberCol);///genislik ve yukselige gore bos board olusturur
        ConnectFourPlusUndo(string filename);///dosyaya gore board olusturur
        ///big tree
        ConnectFourPlusUndo(const ConnectFourPlusUndo & object);///copy constructor
        ~ConnectFourPlusUndo();///destructor
        ConnectFourPlusUndo& operator =(const ConnectFourPlusUndo & object);///assignment operator
        int play();///it plays computer
        int play(int cellPos);///it plays user(user hedefini alır)
        int readFile(string filename);///single mod icin input dosya ismi ise o objeyi dosyaya gore duzneler
        int writeFile(string filename,int user,int userMod);///single modda objeyi dosyaya yazar
        int undo();
        int SingleP(int user=0);///user vs user single mod
        int SingleC(int user=0);///user vs comp single mod
    private:
        Cell *canliHucreler;
        int hamleSayisi;

    };
}


#endif //HW5_CONNECTFOURPLUSUNDO_H

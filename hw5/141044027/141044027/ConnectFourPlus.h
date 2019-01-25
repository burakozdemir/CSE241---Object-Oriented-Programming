//
// Created by burki on 23.11.2017.
//

#ifndef HW5_CONNECTFOURPLUS_H
#define HW5_CONNECTFOURPLUS_H
#include "ConnectFourAbstract.h"

namespace ConnectSpace {

    class ConnectFourPlus : public ConnectFourAbstract{
    protected:
        virtual int checkWin(int user);///herhangi bir kullanıcının oyunu bitirme kontrolü
        virtual int control8Way(char user,int coord1,int coord2);/////CheckWin fonksiyonu ıcın 8 yonu kontrol eder
    public:
        ConnectFourPlus();///
        ConnectFourPlus(const int numberRow,const int numberCol);///genislik ve yukselige gore bos board olusturur
        ConnectFourPlus(string filename);///dosyaya gore board olusturur
        ///big tree
        ConnectFourPlus(const ConnectFourPlus & object);///copy constructor
        ~ConnectFourPlus();///destructor
        ConnectFourPlus& operator =(const ConnectFourPlus & object);///assignment operator
    };
}

#endif //HW5_CONNECTFOURPLUS_H

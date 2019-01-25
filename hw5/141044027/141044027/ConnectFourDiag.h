//
// Created by burki on 23.11.2017.
//

#ifndef HW5_CONNECTFOURDIAG_H
#define HW5_CONNECTFOURDIAG_H
#include "ConnectFourAbstract.h"
namespace ConnectSpace {

    class ConnectFourDiag : public ConnectFourAbstract{
    protected:
        virtual int checkWin(int user);///herhangi bir kullanıcının oyunu bitirme kontrolü
        virtual int control8Way(char user,int coord1,int coord2);/////CheckWin fonksiyonu ıcın 8 yonu kontrol eder
    public:
        ConnectFourDiag();///
        ConnectFourDiag(const int numberRow,const int numberCol);///genislik ve yukselige gore bos board olusturur
        ConnectFourDiag(string filename);///dosyaya gore board olusturur
        ///big tree
        ConnectFourDiag(const ConnectFourDiag & object);///copy constructor
        ~ConnectFourDiag();///destructor
        ConnectFourDiag& operator =(const ConnectFourDiag & object);///assignment operator
    };
}



#endif //HW5_CONNECTFOURDIAG_H

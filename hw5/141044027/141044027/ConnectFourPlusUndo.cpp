//
// Created by burki on 23.11.2017.
//

#include "ConnectFourPlusUndo.h"

namespace ConnectSpace {
    ConnectFourPlusUndo::ConnectFourPlusUndo():ConnectFourPlus(),hamleSayisi(0){
        ///YER ALMA
        canliHucreler=new Cell[height*width];

        /// boardı yıldızla doldurma
        for (int i = 0; i < height*width; ++i) {
            canliHucreler[i].setContent('*');
        }
    }
    ConnectFourPlusUndo::ConnectFourPlusUndo(const int numberRow, const int numberCol) :
            ConnectFourPlus(numberRow, numberCol),hamleSayisi(0){
        ///YER ALMA
        canliHucreler=new Cell[numberRow*numberCol];
        /// boardı yıldızla doldurma
        for (int i = 0; i < numberRow*numberCol; ++i) {
            canliHucreler[i].setContent('*');
        }
    }
    ConnectFourPlusUndo::ConnectFourPlusUndo(string filename) : ConnectFourPlus(filename) {
        ///YER ALMA
        canliHucreler=new Cell[height*width];
        /// boardı yıldızla doldurma
        for (int i = 0; i < height*width; ++i) {
            canliHucreler[i].setContent('*');
        }
    }
    ConnectFourPlusUndo::ConnectFourPlusUndo(const ConnectSpace::ConnectFourPlusUndo &object):ConnectFourPlus(object){
        ///yer alma
        canliHucreler=new Cell[width*height];
        this->hamleSayisi=object.hamleSayisi;
        ///doldurma
        for (int i = 0; i < width*height; ++i) {
            canliHucreler[i].setContent(object.canliHucreler[i].getContent());
            canliHucreler[i].setCol(object.canliHucreler[i].getCol());
            canliHucreler[i].setRow(object.canliHucreler[i].getRow());
        }
    }
    ConnectFourPlusUndo::~ConnectFourPlusUndo() {
       delete [] canliHucreler;
    }
    ConnectFourPlusUndo& ConnectFourPlusUndo::operator=(const ConnectSpace::ConnectFourPlusUndo &object){
        ConnectFourPlus::operator =(object);
        if(this->width!=object.width || this->height!=object.height ||
                this->hamleSayisi!=object.hamleSayisi) {
            ///boardu temizleme
            delete [] canliHucreler;
            this->height=object.height;
            this->width=object.width;
            this->hamleSayisi=object.hamleSayisi;
            ///yer alma
            canliHucreler=new Cell[width*height];
            ///doldurma
            for (int i = 0; i < width*height; ++i) {
                canliHucreler[i].setContent(object.canliHucreler[i].getContent());
                canliHucreler[i].setCol(object.canliHucreler[i].getCol());
                canliHucreler[i].setRow(object.canliHucreler[i].getRow());
            }
        }
        else{
            for (int i = 0; i < width*height; ++i) {
                canliHucreler[i].setContent(object.canliHucreler[i].getContent());
                canliHucreler[i].setCol(object.canliHucreler[i].getCol());
                canliHucreler[i].setRow(object.canliHucreler[i].getRow());
            }
        }

        return *this;
    }
    int ConnectFourPlusUndo::play() {
        int choice=computer();
        choice=boslukKontrolComp(choice-1);
        int row=isCellEmpty(choice);//row indis turunden choice ise user secımı turunden
        if(row==-1)
            cout<<"Full Colums"<<endl;
        else {
            gameBoard[row][choice - 1].setContent('O');
            gameBoard[row][choice - 1].setCol(choice - 1);
            gameBoard[row][choice - 1].setRow(row);
            setUserSira(getUserSira() + 1);
            aliveCell++;
            hamleSayisi+=1;
            canliHucreler[hamleSayisi-1].setContent('O');
            canliHucreler[hamleSayisi-1].setCol(choice - 1);
            canliHucreler[hamleSayisi-1].setRow(row);
        }
    }
    int ConnectFourPlusUndo::play(int cellPos) {
        int row=isCellEmpty(cellPos);//row indis turunden choice ise user secımı turunden
        if(row==-1)
            cout<<"Full Colums"<<endl;
        else {
            if ((getUserSira()%2)==1) {
                gameBoard[row][cellPos-1].setContent('X');
                gameBoard[row][cellPos-1].setCol(cellPos-1);
                gameBoard[row][cellPos-1].setRow(row);
                setUserSira(getUserSira()+1);
                aliveCell++;
                hamleSayisi+=1;
                canliHucreler[hamleSayisi-1].setContent('X');
                canliHucreler[hamleSayisi-1].setCol(cellPos - 1);
                canliHucreler[hamleSayisi-1].setRow(row);
            }
            else
            {
                gameBoard[row][cellPos-1].setContent('O');
                gameBoard[row][cellPos-1].setCol(cellPos-1);
                gameBoard[row][cellPos-1].setRow(row);
                setUserSira(getUserSira()+1);
                aliveCell++;
                hamleSayisi+=1;
                canliHucreler[hamleSayisi-1].setContent('O');
                canliHucreler[hamleSayisi-1].setCol(cellPos - 1);
                canliHucreler[hamleSayisi-1].setRow(row);
            }
        }
        return 1;
    }
    int ConnectFourPlusUndo::readFile(string filename) {
        int size;
        auto mod=0,user=1;
        ifstream myfile(filename);
        ifstream myfile2(filename);
        string content;

        if (myfile.is_open())
        {
            myfile2.seekg(0,ios::end);
            size_t size = myfile2.tellg();
            if( size == 0)
            {
                cerr << "File is empty\n";
                return -1;
            }

            for (int i = 0; i < height; ++i) {
                delete [] this->gameBoard[i];
            }
            ///bordun yenilenmesi
            delete []gameBoard;
            delete []canliHucreler;

            myfile>>width>>height>>user>>mod;
            setUserSira(user);

            hamleSayisi=0;
            canliHucreler=new Cell[height*width];
            gameBoard=new Cell*[height];
            for (int j = 0; j < height; ++j) {
                gameBoard[j]= new Cell[width];
            }
            //boardun doldurulması
            setAliveCells(0);
            cout<<"Yeni oyun yüklenirken LivinCells sıfırlanıyor.."<<endl;
            int k=0;
            int count;
            getline(myfile, content);
            while (!myfile.eof() ) {
                getline(myfile, content);
                count=0;
                for (int i = 0; i < content.size(); ++i) {
                    if(i%2==0){
                        gameBoard[k][count].setContent(content[i]);
                        count++;
                    }
                    if(content[i]=='X' || content[i]=='O'){
                        aliveCell++;
                        gameBoard[k][count-1].setCol(count-1);
                        gameBoard[k][count-1].setRow(k);

                    }
                }
                k++;
            }
            int canlihucre=0;
            for (int l = height-1; l >=0; --l) {
                for (int i = width-1; i >=0; --i) {
                    if(gameBoard[l][i].getContent()=='X' || gameBoard[l][i].getContent()=='O'){
                        hamleSayisi++;
                        canliHucreler[canlihucre].setContent(gameBoard[l][i].getContent());
                        canliHucreler[canlihucre].setCol(i);
                        canliHucreler[canlihucre].setRow(l);
                        canlihucre++;
                    }
                }
            }

            if(mod==1)
                SingleC(user);
            else
                SingleP(user);
        }
        else{
            setGameEnded(true);
            setAliveCells(0);
            cerr<<"Failed to open file"<<endl;
        }
        myfile.close();
        myfile2.close();
    }
    int ConnectFourPlusUndo::writeFile(string filename, int user, int userMod) {
        ofstream file(filename);

        if(file.is_open()){
            file<<getWidth()<<" "<<getHeight()<<" "<<user<<" "<<userMod<<"\n";
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    file<<gameBoard[i][j].getContent()<<' ';
                }
                file<<"\n";
            }
        }
        else
            cerr<<"Failed to open"<<endl;
        file.close();
    }
    int ConnectFourPlusUndo::undo() {
        if(hamleSayisi!=0){
            int x=canliHucreler[hamleSayisi-1].getCol();
            int y=canliHucreler[hamleSayisi-1].getRow();
            gameBoard[y][x].setContent('*');
            canliHucreler[hamleSayisi-1].setContent('*');
            hamleSayisi-=1;
            userSira--;
            aliveCell--;
        }
        else{
            cerr<<"cannot go to back"<<endl;
        }
    }
    int ConnectFourPlusUndo::SingleP(int user){
        int winControl=0;//oyunun kazanılıp kazanılmamamsı
        int choice;//userların hangi konumu sectgi
        int myundo;
        bool flagLoaded=true;
        string choiceChar;
        string choiceChar2;
        int flag,sira;
        if(user==0){
            cout<<"User1 : 'X' , User2 : 'O'"<<endl;
            cout<<"First start User1 !!"<<endl;
        }
        if(user==0 || user==1){
            sira=1;
        }
        else if(user==2){
            sira=2;
        }
        if(getGameEnded()==true){
            flagLoaded=false;
        }
        while(!winControl && flagLoaded){
            /*
            for (int i= hamleSayisi-1; i>=0; --i) {
                cout<<canliHucreler[hamleSayisi-1].getRow()<<" "<<canliHucreler[hamleSayisi-1].getCol()<<endl;
            }
             */
            cinKontrol();
            myundo=0;
            choice=0;
            flag=1;
            printBoard();
            cout<<"LivingCell:"<<getAliveCells()<<endl;
            if(sira%2==1){
                user=1;
                cout<<"User1:";
                while(flag){
                    cin>>choiceChar;
                    if(isChoiceKontrol(choiceChar)){
                        if(choiceChar=="LOAD"){
                            cin>>choiceChar2;
                            cout<<"Game is loading"<<endl;
                            cout<<"when game is loading , LivingCells are zero"<<endl;
                            setAliveCells(0);
                            readFile(choiceChar2);
                            flagLoaded=false;
                        }
                        if(choiceChar=="SAVE"){
                            cin>>choiceChar2;
                            writeFile(choiceChar2,user,0);
                            cout<<"Game Saved . Please choose column:"<<endl;
                        }
                        if(choiceChar=="UNDO"){
                            undo();
                            myundo=1;
                            flag=0;
                        }
                    }
                    if(choiceChar.length()==1){
                        choice=charToInt(choiceChar[0]);
                    }
                    if(choice>=1 && choice<=width){
                        if(boslukKontrol(choiceChar)){
                            flag=0;
                        }
                        else {
                            if(myundo==0){
                                sira--;
                                cerr << "Spaces is not legal to move!" << endl;
                            }
                        }
                    }
                    else if((choiceChar.length()==1 || choice==0) && flagLoaded!=false && myundo==0){
                        cerr<<"Wrong Choice! Please try again ."<<endl;
                    }
                }
            }
            else{
                user=2;
                cout<<"User2:";
                while(flag){
                    cin>>choiceChar;
                    if(isChoiceKontrol(choiceChar)){
                        if(choiceChar=="LOAD"){
                            cin>>choiceChar2;
                            cout<<"Game is loading"<<endl;
                            readFile(choiceChar2);
                            flagLoaded=false;
                        }
                        if(choiceChar=="SAVE"){
                            cin>>choiceChar2;
                            writeFile(choiceChar2,user,0);
                            cout<<"Game Saved . Please choose column:"<<endl;
                        }
                        if(choiceChar=="UNDO"){
                            undo();
                            myundo=1;
                            flag=0;
                        }
                    }
                    if(choiceChar.length()==1)
                        choice=charToInt(choiceChar[0]);
                    if(choice>=1 && choice<=width){
                        if(boslukKontrol(choiceChar)){
                            flag=0;
                        }
                        else {
                            if(myundo==0){
                                sira--;
                                cerr << "Spaces is not legal to move!" << endl;
                            }
                        }
                    }
                    else if((choiceChar.length()==1 || choice==0) && flagLoaded!=false && myundo==0){
                        cerr<<"Wrong Choice! Please try again ."<<endl;
                    }
                }
            }
            cout<<endl;
            if(isBoardEmpty())
                if(isColumnEmpty(choice)){
                    play(choice);
                }
                else{
                    if(myundo==0){
                        sira--;
                        cout<<"Column is full . Please try again !"<<endl;
                    }
                }
            else
                cerr<<"Board is FULL , Game finished , None is winner !";
            if(checkWin(user)){
                printBoard();
                cout<<"LivingCell:"<<getAliveCells()<<endl;
                cout<<"User";
                cout<<user;
                cout<<" Win !!!"<<endl;
                winControl=1;
                setGameEnded(true);
            }
            sira++;
        }
    }
    int ConnectFourPlusUndo::SingleC(int user){
        int winControl=0;//oyunun kazanılıp kazanılmamamsı
        int sira=1;//sıranın hangi oyuncuda oldgu
        int choice;//userların hangi konumu sectgi
        int flag,myundo;
        bool flagLoaded=true;
        string choiceChar;
        string choiceChar2;
        if(user==0){
            cout<<"User1 : 'X' , User2 : 'O'"<<endl;
            cout<<"First start User1 !!"<<endl;
        }
        if(user==0 || user==1){
            sira=1;
        }
        else if(user==2){
            sira=2;
        }
        if(getGameEnded()==true){
            flagLoaded=false;
        }
        while(!winControl && flagLoaded){
            cinKontrol();
            myundo=0;
            choice=0;
            flag=1;
            printBoard();
            cout<<"LivingCell:"<<getAliveCells()<<endl;
            if(sira%2==1){
                user=1;
                cout<<"User1:";
                while(flag){
                    cin>>choiceChar;
                    if(isChoiceKontrol(choiceChar)){
                        if(choiceChar=="LOAD"){
                            cin>>choiceChar2;
                            cout<<"Game is loading"<<endl;
                            cout<<"when game is loading , LivingCells are zero"<<endl;
                            setAliveCells(0);
                            readFile(choiceChar2);
                            flagLoaded=false;
                        }
                        if(choiceChar=="SAVE"){
                            cin>>choiceChar2;
                            writeFile(choiceChar2,user,1);
                            cout<<"Game Saved . Please choose column:"<<endl;
                        }
                        if(choiceChar=="UNDO"){
                            undo();
                            myundo=1;
                            flag=0;
                        }
                    }
                    if(choiceChar.length()==1)
                        choice=charToInt(choiceChar[0]);
                    if(choice>=1 && choice<=width){
                        if(boslukKontrol(choiceChar)){
                            flag=0;
                        }
                        else {
                            if(myundo==0){
                                sira--;
                                cerr << "Spaces is not legal to move!" << endl;
                            }
                        }
                    }
                    else if((choiceChar.length()==1 || choice==0) && flagLoaded!=false && myundo==0){
                        cerr<<"Wrong Choice! Please try again ."<<endl;
                    }
                }
            }
            else{
                user=2;
                choice=computer();//choice secim türünden
                choice=boslukKontrolComp(choice-1);
                cout<<"Choice of computer:"<<(char)(choice+96)<<endl;
            }
            cout<<endl;
            if(isBoardEmpty()) {
                if(isColumnEmpty(choice)){
                    if(user==2)
                        play();
                    else
                        play(choice);
                }
                else {
                    if(myundo==0){
                        sira--;
                        cerr << "Column is full . Please try again !" << endl;
                    }
                }
            }
            else
                cerr<<"Board is FULL , Game finished , None is winner !";

            if(checkWin(user)){
                setGameEnded(true);
                if(user==1) {
                    printBoard();
                    cout<<"LivingCell:"<<getAliveCells()<<endl;
                    cout << "User1 Win !!!";
                }
                else{
                    printBoard();
                    cout<<"LivingCell:"<<getAliveCells()<<endl;
                    cout<<"Computer Win !!!"<<endl;}

                winControl=1;
            }
            sira++;
        }
    }
}

//
// Created by burki on 29.10.2017.
//

#include <iostream>
#include "ConnectFour.h"
int ConnectFour::aliveCell= 0;
ConnectFour::Cell::Cell():col(0),row(0),content(' '),cellContent(0){}

ConnectFour::Cell::Cell(char content, int row, int col, int cellcontent):
content(content),row(row),col(col),cellContent(cellcontent){}
bool ConnectFour::Cell::operator==(const ConnectFour::Cell &obj) {
    return (this->getRow()==obj.getRow() && this->getCol()==obj.getCol() && this->getContent()==obj.getContent()
    && this->getCellContent()==obj.getCellContent());
}
ConnectFour::Cell ConnectFour::Cell::operator++() {
    if(this->getContent()=='*')
        this->setContent('X');
    if(this->getContent()=='x')
        this->setContent('O');
    if(this->getContent()=='O')
        this->setContent('*');
    return ConnectFour::Cell(getContent(),getRow(),getCol(),0);
}
ConnectFour::Cell ConnectFour::Cell::operator++(int) {
    char temp=getContent();
    if(this->getContent()=='*')
        this->setContent('X');
    if(this->getContent()=='X')
        this->setContent('O');
    if(this->getContent()=='O')
        this->setContent('*');
    return ConnectFour::Cell(temp,getRow(),getCol(),0);
}
ConnectFour::Cell ConnectFour::Cell::operator--() {
    if(this->getContent()=='*')
        this->setContent('O');
    if(this->getContent()=='X')
        this->setContent('*');
    if(this->getContent()=='O')
        this->setContent('X');
    return ConnectFour::Cell(getContent(),getRow(),getCol(),0);
}
ConnectFour::Cell ConnectFour::Cell::operator--(int) {
    char temp=getContent();
    if(this->getContent()=='*')
        this->setContent('O');
    if(this->getContent()=='X')
        this->setContent('*');
    if(this->getContent()=='O')
        this->setContent('X');
    return ConnectFour::Cell(temp,getRow(),getCol(),0);
}
istream& ConnectFour::Cell::operator>>(istream &result) {
    char temp;
    result >> temp;
    this->setContent(temp);
    return result;
}
ostream& ConnectFour::Cell::operator<<(ostream &result){
    result<<"Content of Cell:"<<this->getContent()<<" ";
    result<<"Row of Cell:"<<this->getRow()+1<<" ";
    result<<"Col of Cell:"<<this->getCol()+1<<endl;
    return result;
}
ConnectFour::ConnectFour():width(5),height(5),userMod(""),objectNumber(0),userSira(1),gameEnded(false),
                           numberOfObject(0){
    ///YER ALMA
    gameBoard=new Cell*[height];
    for (int j = 0; j < height; ++j) {
        gameBoard[j]= new Cell[width];
    }
    /// boardı yıldızla doldurma
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            gameBoard[i][j].setContent('*');
        }
    }
}
ConnectFour::ConnectFour(const int numberRow,const int numberCol):height(numberRow),width(numberCol){
    ///yer alma
    gameBoard=new Cell*[height];
    for (int j = 0; j < height; ++j) {
        gameBoard[j]= new Cell[width];
    }
    ///boardı doldruma
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            gameBoard[i][j].setContent('*');
        }
    }
}
ConnectFour::ConnectFour(string filename):userMod(""),objectNumber(0),userSira(1),gameEnded(false),numberOfObject(0){
    ifstream myfile(filename);
    ifstream myfile2(filename);
    ifstream myfile3(filename);
    string content;
    string temp;
    int roww=0,coll=0;
    int k=0;

    if(myfile.is_open()){
        ///dosya bos kontrol
        myfile2.seekg(0,ios::end);
        size_t size = myfile2.tellg();
        if( size == 0)
        {
            cerr << "File is empty\n";
        }

        ///height ve width degıskenlerıne deger almak ıcın
        while(!myfile3.eof()){
            getline(myfile3, content);
            roww++;
            if(content==""){

            }
            else
                coll=content.size();
        }
        height=--roww;
        width=coll;
        ///yer alma
        gameBoard=new Cell*[height];
        for (int j = 0; j < height; ++j) {
            gameBoard[j]= new Cell[width];
        }
        ///board doldurma
        while (!myfile.eof() ) {
            getline(myfile, content);
            for (int i = 0; i < content.size(); ++i) {
                gameBoard[k][i].setContent(content[i]);
            }
            k++;
        }
    }else {
        ///obje sıfırlanması
        setGameEnded(true);
        setAliveCells(0);
        cerr<<"Failed to open file"<<endl;
    }
    myfile.close();
    myfile2.close();
    myfile3.close();
}
void ConnectFour::printBoard() {
    cout<<endl;
    for(auto i=0;i<width;i++){
        cout << (char)(i+97) << " " ;
    }
    cout<<endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout<<gameBoard[i][j].getContent();
            cout<<" ";
        }
        cout<<endl;
    }

}
ConnectFour::ConnectFour(const ConnectFour &object) {
    this->height=object.height;
    this->width=object.width;
    this->gameEnded=object.gameEnded;
    this->aliveCell=object.aliveCell;
    this->numberOfObject=object.numberOfObject;
    this->userMod=object.userMod;
    this->userSira=object.userSira;
    this->gameBoard= new Cell*[this->height];
    for (int i = 0; i < this->height; ++i) {
        this->gameBoard[i]=new Cell[this->width];
    }
    for (int j = 0; j < this->height; ++j) {
        for (int i = 0; i < this->width; ++i) {
            this->gameBoard[j][i]=object.gameBoard[j][i];
        }
    }
}
ConnectFour::~ConnectFour() {
    for (int i = 0; i < height; ++i) {
        delete[] gameBoard[i];
    }
    //delete []objects;
    delete[] gameBoard;
}
ConnectFour &ConnectFour::operator=(const ConnectFour &object) {
    if(*this==object)
        return *this;
    else{
        this->gameEnded=object.gameEnded;
        this->aliveCell=object.aliveCell;
        this->numberOfObject=object.numberOfObject;
        this->userMod=object.userMod;
        this->userSira=object.userSira;
        if(this->width!=object.width || this->height!=object.height){
            ///boardu temizleme
            for (int i = 0; i < this->height; ++i) {
                delete [] this->gameBoard[i];
            }
            delete [] this->gameBoard;
            this->height=object.height;
            this->width=object.width;
            ///boarda tekrar yer alma
            this->gameBoard = new Cell*[this->height];
            for (int j = 0; j < this->height; ++j) {
                this->gameBoard[j]=new Cell[object.width];
            }
        }
        ///boardın doldurulması
        for (int k = 0; k < this->height; ++k) {
            for (int i = 0; i < this->width; ++i) {
                gameBoard[k][i]=object.gameBoard[k][i];
            }
        }

    }
    return *this;
}
void ConnectFour::setObject(string filename){
    ifstream myfile(filename);
    ifstream myfile2(filename);
    ifstream myfile3(filename);
    string content;
    string temp;
    int roww=0,coll=0;
    int k=0;

    for (int i = 0; i < height; ++i) {
        delete [] this->gameBoard[i];
    }
    //delete []objects;
    delete []gameBoard;

    if(myfile.is_open()){
        myfile2.seekg(0,ios::end);
        size_t size = myfile2.tellg();
        if( size == 0)
        {
            cerr << "File is empty\n";
        }

        while(!myfile3.eof()){
            getline(myfile3, content);
            roww++;
            if(content==""){

            }
            else
                coll=content.size();
        }
        height=--roww;
        width=coll;

        gameBoard=new Cell*[height];
        for (int j = 0; j < height; ++j) {
            gameBoard[j]= new Cell[width];
        }

        while (!myfile.eof() ) {
            getline(myfile, content);
            for (int i = 0; i < content.size(); ++i) {
                gameBoard[k][i].setContent(content[i]);
            }
            k++;
        }

    }else{
        setGameEnded(true);
        setAliveCells(0);
        cerr<<"Failed to open file"<<endl;
    }
    myfile.close();
    myfile2.close();
    myfile3.close();
}
bool operator==(const ConnectFour &obj1, const ConnectFour &obj2){
    if(obj1.height==obj2.height && obj1.width==obj2.width && obj1.objectNumber==obj2.objectNumber
           && obj1.userSira==obj2.userSira && obj1.gameEnded==obj2.gameEnded && obj1.aliveCell==obj2.aliveCell){
        for (int i = 0; i < obj1.height; ++i) {
            for (int j = 0; j < obj1.width; ++j) {
                if(obj1.gameBoard[i][j].getContent()!=obj2.gameBoard[i][j].getContent()){
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}
bool operator!=(const ConnectFour &obj1, const ConnectFour &obj2){
    return !(obj2==obj1);
}
bool ConnectFour::isGameEnded() {
    if(getGameEnded()==true)true;
    else
        false;
}
int ConnectFour::play() {
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
    }
}
int ConnectFour::play(int cellPos) {
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

        }
        else
        {
            gameBoard[row][cellPos-1].setContent('O');
            gameBoard[row][cellPos-1].setCol(cellPos-1);
            gameBoard[row][cellPos-1].setRow(row);
            setUserSira(getUserSira()+1);
            aliveCell++;
        }
    }
    return 1;
}
int ConnectFour::playGame() {
    string temp;
    bool flag=true;
    while(flag){
        cout<<"dosya adı:";getline(cin, temp);cout<<endl;
        setObject(temp);
        cout<<"user mod:";getline(cin, temp);cout<<endl;
        setUserMod(temp);
        if(this->userMod=="P"){
            UUSingle();
            flag=false;
        }
        else if(this->userMod=="C"){
            UCSingle();
            flag=false;
        }
        else
            cerr<<"Wrong user mod.Please try again"<<endl;
    }
}
int ConnectFour::playGameMulti(ConnectFour objects[5]) {
    bool mainFlag=true,objectNumberFlag=true,choiceObjectsFlag;
    int objectNumber=0;
    int choiceObject;

    cout<<"Multigame is starting..."<<endl;
    while (mainFlag){
        choiceObjectsFlag=true;
        cout<<"Obje seciniz:";
        while(choiceObjectsFlag){
            cinKontrol();
            cin>>choiceObject;
            cout<<choiceObject<<endl;
            if(!cin.fail()){
                if(choiceObject>=1 && choiceObject<=5)
                    choiceObjectsFlag=false;
                else
                    cerr<<"Wrong width value"<<endl;
            }
            cin.clear();
            cin.ignore(10, '\n');
        }
        //user secimi indis turunden degil o yuzden -1
        if(!(objects[choiceObject-1].isGameEnded())){
            if(objects[choiceObject-1].getUserMod()=="P")
                objects[choiceObject-1].UUMulti();
            else
                objects[choiceObject-1].UCMulti();
        }else
            cout<<"This game is ended . Please choose another object."<<endl;

        cout<<"LivingCell:"<<getAliveCells()<<endl;

        int count=0;
        for (int i = 0; i < 5; ++i) {
            if(objects[i].getGameEnded())
                count++;
        }
        if(count==5){
            cout<<"MultiGame is ended.All of game is ended."<<endl;
            mainFlag=false;
        }

    }
    return 1;
}
int ConnectFour::UUMulti() {
    bool mainflag=true,flag1=true,flag2=true;
    string choice,choice2;
    int mychoice,ind=0;
    int user;

    while(ind<=1 && mainflag){
        cinKontrol();
        printBoard();
        if(getUserSira()%2==1){
            user=1;
            cout<<"User1:";
            while(flag1){
                cin>>choice;
                if(columnKontrol(choice)){
                    mychoice=charToInt(choice[0]);
                    if(mychoice>=1 && mychoice<=getWidth()) {
                        if(isBoardEmpty()){
                            if(isColumnEmpty(mychoice)){
                                play(mychoice);
                                flag1=false;
                            }
                            else {
                                cerr << "Column is full . Please try again !" << endl;
                            }
                        }
                        else{
                            cerr<<"Board is FULL , Game finished , None is winner !";
                            setGameEnded(true);
                            flag1=false;
                            mainflag=false;
                        }
                    }
                    else{cerr<<"Wrong range . Please try again ."<<endl;}
                }
                else if (choice=="LOAD"){
                    cin>>choice2;
                    cout<<"Game is loading"<<endl;
                    cout<<"when game is loading , LivingCells of object will zero"<<endl;
                    int count=readFileMulti(choice2);
                    setAliveCells(getAliveCells()-count);
                    flag1=false;
                    mainflag=false;
                }
                else if(choice=="SAVE"){
                    cin>>choice2;
                    cout<<"Game saved"<<endl;
                    writeFileMulti(choice2,1,getUserMod());
                    cout<<"please choice again:";
                }
                else
                    cerr<<"Wrong command.PLease try again!"<<endl;
            }
            if(checkWin(user)){
                printBoard();
                cout<<"User"<<user<<" Win!!"<<endl;
                setGameEnded(true);
                mainflag= false;
            }
        }
        else{
            user=2;
            cout<<"User2:";
            while(flag2){
                cin>>choice;
                if(columnKontrol(choice)){
                    mychoice=charToInt(choice[0]);
                    if(mychoice>=1 && mychoice<=getWidth()){
                        if(isBoardEmpty()){
                            if(isColumnEmpty(mychoice)){
                                play(mychoice);
                                printBoard();
                                flag2=false;
                            }
                            else {
                                cerr << "Column is full . Please try again !" << endl;
                            }
                        }
                        else{
                            cerr<<"Board is FULL , Game finished , None is winner !";
                            setGameEnded(true);
                            flag2=false;
                            mainflag=false;
                        }
                    }
                    else{cerr<<"Wrong range. Pleae try again"<<endl;}
                }
                else if (choice=="LOAD"){
                    cin>>choice2;
                    cout<<"Game is loading"<<endl;
                    cout<<"when game is loading , LivingCells of object will refactoring."<<endl;
                    int count=readFileMulti(choice2);
                    setAliveCells(getAliveCells()-count);
                    flag2=false;
                    mainflag=false;
                }
                else if(choice=="SAVE"){
                    cin>>choice2;
                    cout<<"Game saved"<<endl;
                    writeFileMulti(choice2,2,getUserMod());
                    cout<<"please choice again:";
                }
                else{
                    cerr<<"Wrong command.PLease try again!"<<endl;
                }
            }
            if(checkWin(user)){
                printBoard();
                cout<<"User"<<user<<" Win!!"<<endl;
                setGameEnded(true);
                mainflag= false;
            }
        }
        ind++;
    }
}
int ConnectFour::UCMulti() {
    bool flag1=true,mainflag=true;
    string choice,choice2;
    int mychoice,ind=0,user;

    while(ind<=1 && mainflag){
        cinKontrol();
        printBoard();
        if(getUserSira()%2==1){
            user=1;
            cout<<"User1:";
            while(flag1){
                cin>>choice;
                if(columnKontrol(choice)){
                    mychoice=charToInt(choice[0]);
                    if(mychoice>=1 && mychoice<=getWidth()){
                        if(isBoardEmpty()){
                            if(isColumnEmpty(mychoice)){
                                play(mychoice);
                                flag1=false;
                            }
                            else {
                                cerr << "Column is full . Please try again !" << endl;
                            }
                        }
                        else{
                            cerr<<"Board is FULL , Game finished , None is winner !";
                            setGameEnded(true);
                            flag1=false;
                        }
                    }
                    else{cerr<<"Wrong range.Please try again."<<endl;}
                }
                else if (choice=="LOAD"){
                    cin>>choice2;
                    cout<<"Game is loading"<<endl;
                    cout<<"when game is loading , LivingCells of object will zero"<<endl;
                    int count=readFileMulti(choice2);
                    setAliveCells(getAliveCells()-count);
                    flag1=false;
                    mainflag=false;
                }
                else if(choice=="SAVE"){
                    cin>>choice2;
                    cout<<"Game saved"<<endl;
                    writeFileMulti(choice2,1,getUserMod());
                    cout<<"please choice again:";
                }
                else{
                    cerr<<"Wrong command.PLease try again!"<<endl;
                }
            }
            if(checkWin(user)){
                printBoard();
                cout<<"User"<<user<<" Win!!"<<endl;
                setGameEnded(true);
                mainflag= false;
            }
        }
        else{
            user=2;
            mychoice=computer();//choice secim türünden
            mychoice=boslukKontrolComp(mychoice-1);
            cout<<"Choice of computer:"<<(char)(mychoice+96)<<endl;
            if(isBoardEmpty()){
                if(isColumnEmpty(mychoice)){
                    play();
                }else {
                    cerr << "Column is full . Please try again !" << endl;
                }
            }
            else{
                cerr<<"Board is FULL , Game finished , None is winner !";
                setGameEnded(true);
                flag1=false;
            }
            if(checkWin(user)){
                printBoard();
                cout<<"User"<<user<<" Win!!"<<endl;
                setGameEnded(true);
                mainflag= false;
            }
        }

        ind++;
    }
    printBoard();
}
int ConnectFour::UUSingle(int user) {
    int winControl=0;//oyunun kazanılıp kazanılmamamsı
    int choice;//userların hangi konumu sectgi
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
        cinKontrol();
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
                }
                if(choiceChar.length()==1){
                    choice=charToInt(choiceChar[0]);
                }
                if(choice>=1 && choice<=width){
                    if(boslukKontrol(choiceChar)){
                        flag=0;
                    }
                    else {
                        sira--;
                        cerr << "Spaces is not legal to move!" << endl;
                    }
                }
                else if((choiceChar.length()==1 || choice==0) && flagLoaded!=false){
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
                }
                if(choiceChar.length()==1)
                    choice=charToInt(choiceChar[0]);
                if(choice>=1 && choice<=width){
                    if(boslukKontrol(choiceChar)){
                        flag=0;
                    }
                    else {
                        sira--;
                        cerr << "Spaces is not legal to move!" << endl;
                    }
                }
                else if((choiceChar.length()==1 || choice==0) && flagLoaded!=false){
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
                sira--;
                cout<<"Column is full . Please try again !"<<endl;
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
        }
        sira++;
    }
}
int ConnectFour::UCSingle(int user) {
    int winControl=0;//oyunun kazanılıp kazanılmamamsı
    int sira=1;//sıranın hangi oyuncuda oldgu
    int choice;//userların hangi konumu sectgi
    int flag;
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
                }
                if(choiceChar.length()==1)
                    choice=charToInt(choiceChar[0]);
                if(choice>=1 && choice<=width){
                    if(boslukKontrol(choiceChar)){
                        flag=0;
                    }
                    else {
                        sira--;
                        cerr << "Spaces is not legal to move!" << endl;
                    }
                }
                else if((choiceChar.length()==1 || choice==0) && flagLoaded!=false){
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
                sira--;
                cerr << "Column is full . Please try again !" << endl;
            }
        }
        else
            cerr<<"Board is FULL , Game finished , None is winner !";

        if(checkWin(user)){
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
int ConnectFour::readFileMulti(string filename) {
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
        //delete []objects;
        delete []gameBoard;

        string temp;
        string temp2;
        myfile>>width>>height>>temp>>temp2;
        if(temp=="1")
            setUserSira(1);
        else
            setUserSira(2);
        setUserMod(temp2);

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
                    gameBoard[k][count-1].setRow(count-1);
                }
                cout<<endl;
            }
            k++;
        }
    }
    else{
        setGameEnded(true);
        setAliveCells(0);
        cerr<<"Failed to open file"<<endl;
    }
    myfile2.close();
    myfile.close();
}
int ConnectFour::readFile(string filename) {
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
        //delete []objects;
        delete []gameBoard;

        myfile>>width>>height>>user>>mod;
        setUserSira(user);
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
                    gameBoard[k][count-1].setRow(count-1);
                }
            }
            k++;
        }
        if(mod==1)
            UCSingle(user);
        else
            UUSingle(user);
    }
    else{
        setGameEnded(true);
        setAliveCells(0);
        cerr<<"Failed to open file"<<endl;
    }
    myfile.close();
    myfile2.close();
}
int ConnectFour::writeFile(string filename, int user, int userMod) {
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
int ConnectFour::writeFileMulti(string filename, int user, string userMod) {
    ofstream file(filename);
    if(file.is_open()){
        file<<getWidth()<<" "<<getHeight()<<" "<<user<<" "<<userMod<<"\n";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                file<<gameBoard[i][j].getContent()<<" ";
            }
            file<<"\n";
        }
    }
    else{cerr<<"Failed to open"<<endl;}
    file.close();
    return 1;
}
int ConnectFour::isCellEmpty(int choice) {
    for(int i=height-1;i>=0;i--){
        if(gameBoard[i][choice-1].getContent()=='*')
            return i;
    }
    return -1;
}
int ConnectFour::isChoiceKontrol(string value) {
    if(value.length()!=1){
        if( !(value[0]>='A' && value[0]<='Z') || !((value[0]>='a' && value[0]<='z')) )
            return 1;
    }
    return 0;
}
int ConnectFour::isBoardEmpty() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(gameBoard[i][j].getContent()=='*')
                return 1;
        }
    }
    return 0;
}
int ConnectFour::isColumnEmpty(int choice) {
    for (int i = 0; i < height; ++i) {
        if(gameBoard[0][choice-1].getContent()=='*' || gameBoard[0][choice-1].getContent()==' '){}
        else
            return 0;
    }
    return 1;
}
int ConnectFour::charToInt(char value) {
    auto result=0;
    if((int)value>96 && (int)value<123 ){
        result=(int)value-96;
        return result;
    }
    if((int)value>64 && (int)value<91){
        result=(int)value-64;
        return result;
    }
    return 0;
}
int ConnectFour::checkWin(int user) {
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
int ConnectFour::control8Way(char user, int coord1, int coord2) {
    if(coord1-1>=0 && gameBoard[coord1-1][coord2].getContent()==user ){
        if(coord1-2>=0 && gameBoard[coord1-2][coord2].getContent()==user){
            if(coord1-3>=0 && gameBoard[coord1-3][coord2].getContent()==user){
                return 1;
            }
        }
    }
    //ust sag kose
    if(coord1-1>=0 && coord2+1<width && gameBoard[coord1-1][coord2+1].getContent()==user ){
        if(coord1-2>=0 && coord2+2<width && gameBoard[coord1-2][coord2+2].getContent()==user){
            if(coord1-3>=0 && coord2+3<width && gameBoard[coord1-3][coord2+3].getContent()==user){
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
    //alt sag kose
    if(coord1+1<height && coord2+1<width && gameBoard[coord1+1][coord2+1].getContent()==user ){
        if(coord1+2<height && coord2+2<width && gameBoard[coord1+2][coord2+2].getContent()==user){
            if(coord1+3<height && coord2+3<width && gameBoard[coord1+3][coord2+3].getContent()==user){
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
    //sol alt kose
    if(coord1+1<height && coord2-1>=0 && gameBoard[coord1+1][coord2-1].getContent()==user ){
        if(coord1+2<height && coord2-2>=0 && gameBoard[coord1+2][coord2-2].getContent()==user){
            if(coord1+3<height && coord2-3>=0 && gameBoard[coord1+3][coord2-3].getContent()==user){
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
int ConnectFour::columnKontrol(string value) {
    if(value.length()==1){
        if( (value[0]>='A' && value[0]<='Z') || ((value[0]>='a' && value[0]<='z')) )
            return 1;
    }
    return 0;
}
int ConnectFour::computer() {
    int choiceCoord2;
    int choice=(-1);
    switch (kontrolComputer(choiceCoord2)){
        case 0: choice=engelleme();
            if(choice!=-1)
                return (choice+1);
            choice=engelleme2();
            if(choice!=-1)
                return (choice+1);
            choice=engelleme3();
            if(choice!=-1)
                return (choice+1);
            choice= firstMove();break;
        case 1: choice=engelleme();
            if(choice!=-1)
                return (choice+1);
            choice=engelleme2();
            if(choice!=-1)
                return (choice+1);
            choice=engelleme3();
            if(choice!=-1)
                return (choice+1);
            choice= (choiceCoord2);break;
        case 2: choice=engelleme();
            if(choice!=-1)
                return (choice+1);
            choice=engelleme2();
            if(choice!=-1)
                return (choice+1);
            choice=engelleme3();
            if(choice!=-1)
                return (choice+1);
            choice= (choiceCoord2);break;
        case 3: choice= (choiceCoord2);break;
        default:return -1;
    }
    return choice+1;
}
int ConnectFour::kontrolComputer(int &coord2) {
    if(kontrol3tas(coord2))
        return 3;
    else if(kontrol2tas(coord2))
        return 2;
    else if(kontrol1tas(coord2))
        return 1;
    return 0;
}
int ConnectFour::kontrol3tas(int &targetCoord2) {
    for (auto i = 0; i <height ; ++i) {
        for (auto j = 0; j <width ; ++j) {
            if(gameBoard[i][j].getContent()=='O'){
                //yukari yon
                if(i-1>=0 && gameBoard[i-1][j].getContent()=='O' ){
                    if(i-2>=0 && gameBoard[i-2][j].getContent()=='O'){
                        if(i-3>=0 && gameBoard[i-3][j].getContent()=='*'){
                            targetCoord2=(j);
                            return 1;
                        }
                    }
                }
                //yukari sag yon
                if(i-1>=0 && j+1<width && gameBoard[i-1][j+1].getContent()=='O' ){
                    if(i-2>=0 && j+2<width && gameBoard[i-2][j+2].getContent()=='O'){
                        if(i-3>=0 && j+3<width && gameBoard[i-3][j+3].getContent()=='*' &&
                           gameBoard[i-2][j+3].getContent()!='*'){
                            targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //yukari sag yon 2
                if(i-1>=0 && j+1<width && gameBoard[i-1][j+1].getContent()=='O' ){
                    if(i-3>=0 && j+3<width && gameBoard[i-3][j+3].getContent()=='O'){
                        if(gameBoard[i-2][j+2].getContent()=='*' && gameBoard[i-1][j+2].getContent()!='*'){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag yon
                if(j+1<width && gameBoard[i][j+1].getContent()=='O'){
                    if(j+2<width && gameBoard[i][j+2].getContent()=='O'){
                        if(j+3<width && gameBoard[i][j+3].getContent()=='*' && i+1<height &&
                           gameBoard[i+1][j+3].getContent()!='*'){
                            targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag yon 2
                if(j+1<width && gameBoard[i][j+1].getContent()=='O'){
                    if(j+3<width && gameBoard[i][j+3].getContent()=='O'){
                        if(gameBoard[i][j+2].getContent()=='*' && i+1<height && gameBoard[i+1][j+2].getContent()!='*'){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag yon sinir
                if(j+1<width && gameBoard[i][j+1].getContent()=='O' ){
                    if(j+2<width && gameBoard[i][j+2].getContent()=='O'){
                        if(j+3<width && gameBoard[i][j+3].getContent()=='*' && (height-i)==1){
                            targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag yon sinir 2
                if(j+1<width && gameBoard[i][j+1].getContent()=='O'){
                    if(j+3<width && gameBoard[i][j+3].getContent()=='O'){
                        if(gameBoard[i][j+2].getContent()=='*' && (height-i)==1){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag alt yon
                if(i+1<height && j+1<width && gameBoard[i+1][j+1].getContent()=='O'){
                    if(i+2<height && j+2<width && gameBoard[i+2][j+2].getContent()=='O'){
                        if(i+3<height && j+3<width && gameBoard[i+3][j+3].getContent()=='*' && i+4<height &&
                           gameBoard[i+4][j+3].getContent()!='*'){
                            targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag alt yon 2
                if(i+1<height && j+1<width && gameBoard[i+1][j+1].getContent()=='O'){
                    if(i+3<height && j+3<width && gameBoard[i+3][j+3].getContent()=='O'){
                        if(gameBoard[i+2][j+2].getContent()=='*' && gameBoard[i+3][j+2].getContent()!='*'){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sol alt yon
                if(i+1<height && j-1>=0 && gameBoard[i+1][j-1].getContent()=='O' ){
                    if(i+2<height && j-2>=0 && gameBoard[i+2][j-2].getContent()=='O'){
                        if(i+3<height && j-3>=0 && gameBoard[i+3][j-3].getContent()=='*' && i+4<height &&
                           gameBoard[i+4][j-3].getContent()!='*'){
                            targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol alt yon 2
                if(i+1<height && j-1>=0 && gameBoard[i+1][j-1].getContent()=='O'){
                    if(i+3<height && j-3>=0 && gameBoard[i+3][j-3].getContent()=='O'){
                        if(gameBoard[i+2][j-2].getContent()=='*' && gameBoard[i+3][j-2].getContent()!='*'){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol yon
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='O'){
                    if(j-2>=0 && gameBoard[i][j-2].getContent()=='O'){
                        if(j-3>=0 && gameBoard[i][j-3].getContent()=='*' && i+1<height &&
                           gameBoard[i+1][j-3].getContent()!='*'){
                            targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol yon 2
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='O'){
                    if(j-3>=0 && gameBoard[i][j-3].getContent()=='O'){
                        if(gameBoard[i][j-2].getContent()=='*' && i+1<height && gameBoard[i+1][j-2].getContent()!='*'){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol yon sinir
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='O'){
                    if(j-2>=0 && gameBoard[i][j-2].getContent()=='O'){
                        if(j-3>=0 && gameBoard[i][j-3].getContent()=='*' && (height-i)==1){
                            targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                // sol yon sinir 2
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='O'){
                    if(j-3>=0 && gameBoard[i][j-3].getContent()=='O'){
                        if(gameBoard[i][j-2].getContent()=='*' && (height-i)==1){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && gameBoard[i-1][j-1].getContent()=='O'){
                    if(i-2>=0 && j-2>=0 && gameBoard[i-2][j-2].getContent()=='O'){
                        if(i-3>=0 && j-3>=0 && gameBoard[i-3][j-3].getContent()=='*' && gameBoard[i-2][j-3].getContent()!='*'){
                            targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol ust yon 2
                if(i-1>=0 && j-1>=0 && gameBoard[i-1][j-1].getContent()=='O'){
                    if(i-3>=0 && j-3>=0 && gameBoard[i-3][j-3].getContent()=='O'){
                        if(gameBoard[i-2][j-2].getContent()=='*' && gameBoard[i-1][j-2].getContent()!='*'){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int ConnectFour::kontrol2tas(int &targetCoord2) {
    for (auto i = 0; i <height ; ++i) {
        for (auto j = 0; j <width ; ++j) {
            if(gameBoard[i][j].getContent()=='O'){
                //yukari yon
                if(i-1>=0 && gameBoard[i-1][j].getContent()=='O' ){
                    if(i-2>=0 && gameBoard[i-2][j].getContent()=='*'){
                        targetCoord2=(j);
                        return 1;
                    }
                }
                //sag yukarı yon
                if(i-1>=0 && j+1<width && gameBoard[i-1][j+1].getContent()=='O' ){
                    if(i-2>=0 && j+2<width && gameBoard[i-2][j+2].getContent()=='*' &&
                       gameBoard[i-1][j+2].getContent()!='*'){
                        targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag yon
                if(j+1<width && gameBoard[i][j+1].getContent()=='O' ){
                    if(j+2<width && gameBoard[i][j+2].getContent()=='*'&& i+1<height &&
                       gameBoard[i+1][j+2].getContent()!='*'){
                        targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag yon (sinir)
                if(j+1<width && gameBoard[i][j+1].getContent()=='O' ){
                    if(j+2<width && gameBoard[i][j+2].getContent()=='*' && (height-i)==1){
                        targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag asagı yon
                if(i+1<height && j+1<width && gameBoard[i+1][j+1].getContent()=='O' ){
                    if(i+2<height && j+2<width && gameBoard[i+2][j+2].getContent()=='*' && i+3<height &&
                       gameBoard[i+3][j+2].getContent()!='*'){
                        targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sol asagı yon
                if(i+1<height && j-1>=0 && gameBoard[i+1][j-1].getContent()=='*' ){
                    if(i+2<height && j-2>=0 && gameBoard[i+2][j-2].getContent()=='*' && i+3<height &&
                       gameBoard[i+3][j-2].getContent()!='*'){
                        targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol yon
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='O' ){
                    if(j-2>=0 && gameBoard[i][j-2].getContent()=='*' && i+1<height && gameBoard[i+1][j-2].getContent()!='*'){
                        targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol yon sinir
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='O' ){
                    if(j-2>=0 && gameBoard[i][j-2].getContent()=='*' && (height-i)==1){
                        targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && gameBoard[i-1][j-1].getContent()=='O' ){
                    if(i-2>=0 && j-2>=0 && gameBoard[i-2][j-2].getContent()=='*' && gameBoard[i-1][j-2].getContent()!='*'){
                        targetCoord2=(j-2);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int ConnectFour::kontrol1tas(int &targetCoord2) {
    for (auto i = 0; i <height ; ++i) {
        for (auto j = 0; j <width; ++j) {
            if(gameBoard[i][j].getContent()=='O'){
                //yukari yon
                if(i-1>=0 && gameBoard[i-1][j].getContent()=='*'){
                    targetCoord2=j;
                    return 1;
                }
                //yukari sag yon
                if(i-1>=0 && j+1<width && gameBoard[i-1][j+1].getContent()=='*' && i<height
                   && gameBoard[i][j+1].getContent()!='*' ){
                    targetCoord2=(j+1);
                    return 1;
                }
                //sag yon
                if(j+1<width && gameBoard[i][j+1].getContent()=='*' && i+1<height && gameBoard[i+1][j+1].getContent()!='*' ){
                    targetCoord2=(j+1);
                    return 1;
                }
                //sag yon(sinir)
                if(j+1<width && gameBoard[i][j+1].getContent()=='*' && (height-i)==1 ){
                    targetCoord2=(j+1);
                    return 1;
                }

                //sag alt yon
                if(i+1<height && j+1<width && gameBoard[i+1][j+1].getContent()=='*' && i+2<height
                   && gameBoard[i+2][j+1].getContent()!='*' ){
                    targetCoord2=(j+1);
                    return 1;
                }
                //sol alt yon
                if(i+1<height && j-1>=0 && gameBoard[i+1][j-1].getContent()=='*' && i+2<height
                   && gameBoard[i+2][j-1].getContent()!='*' ){
                    targetCoord2=(j-1);
                    return 1;
                }
                //sol yon
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='*' && i+1<height && gameBoard[i+1][j-1].getContent()!='*' ){
                    targetCoord2=(j-1);
                    return 1;
                }
                //sol yon sinir
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='*' && (height-i)==1){
                    targetCoord2=(j-1);
                    return 1;
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && gameBoard[i-1][j-1].getContent()=='*' && i<height
                   && gameBoard[i][j-1].getContent()!='*' ){
                    targetCoord2=(j-1);
                    return 1;
                }
            }
        }
    }
    return 0;
}
int ConnectFour::engelleme2() {
    for (auto i = 0; i < height; ++i) {
        for (auto j = 0; j < width; ++j) {
            if (gameBoard[i][j].getContent()=='X') {
                //yukari sag yon
                if (i - 1 >= 0 && j + 1 < width && gameBoard[i - 1][j + 1].getContent() == 'X') {
                    if (i - 3 >= 0 && j + 3 < width && gameBoard[i - 3][j + 3].getContent() == 'X') {
                        if (gameBoard[i - 2][j + 2].getContent() == '*' && gameBoard[i - 1][j + 2].getContent() != '*')
                            return (j + 2);

                    }
                }
                //sag yon
                if (j + 1 < width && gameBoard[i][j + 1].getContent() =='X') {
                    if (j + 3 < width && gameBoard[i][j + 3].getContent() == 'X') {
                        if (gameBoard[i][j + 2].getContent() == '*' && i + 1 <height && gameBoard[i + 1][j + 2].getContent() !='*')
                            return (j + 2);
                    }
                }
                //sag yon sinir
                if (j + 1 < width && gameBoard[i][j + 1].getContent() == 'X') {
                    if (j + 3 < width && gameBoard[i][j + 3].getContent() == 'X') {
                        if (gameBoard[i][j + 2].getContent() == '*'&& (height - i == 1))
                            return (j + 2);
                    }
                }
                //sag alt yon
                if (i + 1 < height && j + 1 < width && gameBoard[i + 1][j + 1].getContent() == 'X') {
                    if (i + 3 < height && j + 3 < width && gameBoard[i + 3][j + 3].getContent() == 'X') {
                        if (gameBoard[i + 2][j + 2].getContent() == '*' && i + 4 < height && gameBoard[i + 4][j + 2].getContent() != '*')
                            return (j + 2);
                    }
                }
                //sag alt yon 2
                if (i + 1 < height && j + 1 < width && gameBoard[i + 1][j + 1].getContent() == 'X') {
                    if (i + 3 == height -1 && j + 3 < width && gameBoard[i + 3][j + 3].getContent() == 'X') {
                        if (gameBoard[i + 2][j + 2].getContent() == '*' )
                            return (j + 2);
                    }
                }
                //sol alt yon
                if (i + 1 < height && j - 1 >= 0 && gameBoard[i + 1][j - 1].getContent() == 'X') {
                    if (i + 3 < height && j - 3 >= 0 && gameBoard[i + 3][j - 3].getContent() == 'X') {
                        if (gameBoard[i + 2][j - 2].getContent() =='*'&& i + 4 < height && gameBoard[i + 4][j - 2].getContent() != '*')
                            return (j - 2);
                    }
                }
                //sol alt yon 2
                if (i + 1 < height && j - 1 >= 0 && gameBoard[i + 1][j - 1].getContent() == 'X') {
                    if (i + 3 == height-1 && j - 3 >= 0 && gameBoard[i + 3][j - 3].getContent() == 'X') {
                        if (gameBoard[i + 2][j - 2].getContent() == '*' && i + 4 < height)
                            return (j - 2);
                    }
                }
                //sol yon
                if (j - 1 >= 0 && gameBoard[i][j - 1].getContent() == 'X') {
                    if (j - 3 >= 0 && gameBoard[i][j - 3].getContent() == 'X') {
                        if (gameBoard[i][j - 2].getContent() == '*' && i + 1 < height && gameBoard[i + 1][j - 2].getContent() != '*')
                            return (j - 2);
                    }
                }
                //sol yon sinir
                if (j - 1 >= 0 && gameBoard[i][j - 1].getContent() == 'X') {
                    if (j - 3 >= 0 && gameBoard[i][j - 3].getContent() == 'X') {
                        if (gameBoard[i][j - 2].getContent() == '*'&& (height - i) == 1)
                            return (j - 2);
                    }
                }
                //yukarı sol yon
                if (i - 1 >= 0 && j - 1 >= 0 && gameBoard[i - 1][j - 1].getContent() == 'X') {
                    if (i - 3 >= 0 && j - 3 >= 0 && gameBoard[i - 3][j - 3].getContent() == 'X') {
                        if (gameBoard[i - 2][j - 2].getContent() =='*' && gameBoard[i - 1][j - 2].getContent() != '*')
                            return (j - 2);
                    }
                }
            }
        }
    }
    return -1;
}
int ConnectFour::engelleme() {
    for (auto i = 0; i < height; ++i) {
        for (auto j = 0; j < width; ++j) {
            if(gameBoard[i][j].getContent()=='X'){
                //yukari yon
                if(i-1>=0 && gameBoard[i-1][j].getContent()=='X' ){
                    if(i-2>=0 && gameBoard[i-2][j].getContent()=='X'){
                        if(i-3>=0 && gameBoard[i-3][j].getContent()=='*')
                            return j;
                    }
                }
                //yukari sag yon
                if(i-1>=0 && j+1<width && gameBoard[i-1][j+1].getContent()=='X' ){
                    if(i-2>=0 && j+2<width && gameBoard[i-2][j+2].getContent()=='X'){
                        if(i-3>=0 && j+3<width && gameBoard[i-3][j+3].getContent()=='*'&& gameBoard[i-2][j+3].getContent()!='*')
                            return (j+3);
                    }
                }
                //sag yon
                if(j+1<width && gameBoard[i][j+1].getContent()=='X'){
                    if(j+2<width && gameBoard[i][j+2].getContent()=='X'){
                        if(j+3<width && gameBoard[i][j+3].getContent()=='*'&& i+1<height && gameBoard[i+1][j+3].getContent()!='*')
                            return (j+3);
                    }
                }
                //sag yon sinir
                if(j+1<width && gameBoard[i][j+1].getContent()=='X'){
                    if(j+2<width && gameBoard[i][j+2].getContent()=='X'){
                        if(j+3<width && gameBoard[i][j+3].getContent()=='*' && (height-i)==1 )
                            return (j+3);
                    }
                }
                //sag alt yon
                if(i+1<height && j+1<width && gameBoard[i+1][j+1].getContent()=='X' ){
                    if(i+2<height && j+2<width && gameBoard[i+2][j+2].getContent()=='X'){
                        if(i+3<height && j+3<width && gameBoard[i+3][j+3].getContent()=='*'&& i+4<height &&
                           gameBoard[i+4][j+3].getContent()!='*')
                            return (j+3);
                    }
                }
                //sag alt yon 2
                if(i+1<height && j+1<width && gameBoard[i+1][j+1].getContent()=='X'){
                    if(i+2<height && j+2<width && gameBoard[i+2][j+2].getContent()=='X'){
                        if(i+3==height-1 && j+3<width && gameBoard[i+3][j+3].getContent()=='*')
                            return (j+3);
                    }
                }
                //sol alt yon
                if(i+1<height && j-1>=0 && gameBoard[i+1][j-1].getContent()=='X'){
                    if(i+2<height && j-2>=0 && gameBoard[i+2][j-2].getContent()=='X'){
                        if(i+3<height && j-3>=0 && gameBoard[i+3][j-3].getContent()=='*' && i+4<height &&  gameBoard[i+4][j-3].getContent()!='*' )
                            return (j-3);
                    }
                }
                //sol alt yon2
                if(i+1<height && j-1>=0 && gameBoard[i+1][j-1].getContent()=='X'){
                    if(i+2<height && j-2>=0 && gameBoard[i+2][j-2].getContent()=='X'){
                        if(i+3==height-1 && j-3>=0 && gameBoard[i+3][j-3].getContent()=='*')
                            return (j-3);
                    }
                }
                //sol yon
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='X'){
                    if(j-2>=0 && gameBoard[i][j-2].getContent()=='X'){
                        if(j-3>=0 && gameBoard[i][j-3].getContent()=='*' && i+1<height && gameBoard[i+1][j-3].getContent()!='*')
                            return (j-3);
                    }
                }
                //sol yon sinir
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='X'){
                    if(j-2>=0 && gameBoard[i][j-2].getContent()=='X'){
                        if(j-3>=0 && gameBoard[i][j-3].getContent()=='*' && (height-i)==1)
                            return (j-3);
                    }
                }
                //yukarı sol yon
                if(i-1>=0 && j-1>=0 && gameBoard[i-1][j-1].getContent()=='X'){
                    if(i-2>=0 && j-2>=0 && gameBoard[i-2][j-2].getContent()=='X'){
                        if(i-3>=0 && j-3>=0 && gameBoard[i-3][j-3].getContent()=='*' && gameBoard[i-2][j-3].getContent()!='*')
                            return (j-3);
                    }
                }
            }
        }
    }
    return -1;
}
int ConnectFour::engelleme3() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(height-i==1 &&  gameBoard[i][j].getContent()=='X'){
                //sag sinir
                if(j+1<width && gameBoard[i][j+1].getContent()=='X'){
                    if(j+2<width && gameBoard[i][j+2].getContent()=='*')
                        return j+2;
                }
                //sol sinir
                if(j-1>=0 && gameBoard[i][j-1].getContent()=='X'){
                    if(j-2>=0 && gameBoard[i][j-2].getContent()=='*')
                        return j-2;
                }
            }
        }
    }
    return -1;
}
int ConnectFour::firstMove() {
    for (auto i = 0; i < height; ++i) {
        for (auto j = 0; j < width; ++j) {
            if(gameBoard[i][j].getContent()=='X'){
                //sol yon
                if( (height-i==1) && j-1>=0 && gameBoard[i][j-1].getContent()=='X'){
                    return (j-1);
                }
                //sag yon
                if( (height-i==1) && j+1<width && gameBoard[i][j+1].getContent()=='X'){
                    return (j+1);
                }
            }
        }
    }
    return 0;
}
int ConnectFour::cinKontrol() {
    if(cin.eof()==true){
        cout<<"oyun sonlanıyor.."<<endl;
        exit(1);
    }
    return 1;
}
int ConnectFour::boslukKontrol(string choice) {
    int secim=charToInt(choice[0]);
    secim--;
    for (int i = 0; i < height; ++i) {
        if(gameBoard[i][secim].getContent()=='*'){
            return 1;
        }
    }
    return 0;
}
int ConnectFour::boslukKontrolComp(int indis) {
    for (int i = 0; i < height; ++i) {
        if(gameBoard[i][indis].getContent()=='*')
            return indis+1;
    }
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            if(gameBoard[j][i].getContent()=='*')
                return (i+1);
        }
    }
    return 1;
}







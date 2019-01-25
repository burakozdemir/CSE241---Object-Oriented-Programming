//
// Created by burak on 19.10.2017.
//

#include <iostream>
#include "ConnectFour.h"
#include <fstream>


int ConnectFour::aliveCell=0;
vector<ConnectFour> ConnectFour::objects;
ConnectFour::Cell::Cell():col(0),row(0),content(""){}

ConnectFour::ConnectFour():width(0),height(0),gameMod(""),userMod(""),objectNumber(0),userSira(1),gameEnded(false){
    vector<vector<Cell>> a(height,vector<Cell>(width));
    gameCells=a;

}
ConnectFour::ConnectFour(const int &width, const int &height, const string &usermod, const int &objectNumber):
width(width),height(height),userMod(usermod),objectNumber(objectNumber),gameEnded(false),userSira(1){
    vector<vector<Cell>> a(height,vector<Cell>(width));
    gameCells=a;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            gameCells.at(i).at(j).setContent(".");
            gameCells.at(i).at(j).setRow(i);
            gameCells.at(i).at(j).setCol(j);
        }
    }
}
ConnectFour::ConnectFour(const int &width,const int &height,const string &gamemod,const string &usermod,
                         const int &objectNumber):width(width),
height(height),gameMod(gamemod),userMod(usermod),objectNumber(objectNumber),userSira(1),gameEnded(false){
    vector<vector<Cell>> a(height,vector<Cell>(width));
    gameCells=a;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            gameCells.at(i).at(j).setContent(".");
            gameCells.at(i).at(j).setRow(i);
            gameCells.at(i).at(j).setCol(j);
        }
    }

}
ConnectFour::ConnectFour(const ConnectFour &object){

}
void ConnectFour::setGameCells(Cell value) {

}
bool ConnectFour::compare(const ConnectFour &object)const{
    int object1Count=0,object2Count=0;
    if(getHeight()==object.getHeight() || getWidth()==object.getWidth()){
        helperForCompareFunc("X",object1Count);
        object.helperForCompareFunc("X",object2Count);
    }
    else{
        cerr<<"dont compatible width or height values"<<endl;
        return 0;
    }
    if(object1Count>object2Count) return true;
    else return false;

}
int ConnectFour::helperForCompareFunc(string user,int &count)const{
    for (auto i = 0; i <height ; ++i) {
        for (auto j = 0; j <width ; ++j) {
            if(gameCells[i][j].getContent()==user){
                //yukari yon
                if(i-1>=0 && gameCells[i-1][j].getContent()==user ){
                    if(i-2>=0 && gameCells[i-2][j].getContent()==user){
                        if(i-3>=0 && gameCells[i-3][j].getContent()=="."){
                            count++;
                        }
                    }
                }
                //yukari sag yon
                if(i-1>=0 && j+1<width && gameCells[i-1][j+1].getContent()==user ){
                    if(i-2>=0 && j+2<width && gameCells[i-2][j+2].getContent()==user){
                        if(i-3>=0 && j+3<width && gameCells[i-3][j+3].getContent()=="." &&
                           gameCells[i-2][j+3].getContent()!="."){
                            count++;
                        }
                    }
                }
                //yukari sag yon 2
                if(i-1>=0 && j+1<width && gameCells[i-1][j+1].getContent()==user ){
                    if(i-3>=0 && j+3<width && gameCells[i-3][j+3].getContent()==user){
                        if(gameCells[i-2][j+2].getContent()=="." && gameCells[i-1][j+2].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sag yon
                if(j+1<width && gameCells[i][j+1].getContent()==user){
                    if(j+2<width && gameCells[i][j+2].getContent()==user){
                        if(j+3<width && gameCells[i][j+3].getContent()=="." && i+1<height &&
                           gameCells[i+1][j+3].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sag yon 2
                if(j+1<width && gameCells[i][j+1].getContent()==user ){
                    if(j+3<width && gameCells[i][j+3].getContent()==user){
                        if(gameCells[i][j+2].getContent()=="." && i+1<height && gameCells[i+1][j+2].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sag yon sinir
                if(j+1<width && gameCells[i][j+1].getContent()==user ){
                    if(j+2<width && gameCells[i][j+2].getContent()==user){
                        if(j+3<width && gameCells[i][j+3].getContent()=="." && (height-i)==1){
                            count++;
                        }
                    }
                }
                //sag yon sinir 2
                if(j+1<width && gameCells[i][j+1].getContent()==user ){
                    if(j+3<width && gameCells[i][j+3].getContent()==user){
                        if(gameCells[i][j+2].getContent()=="." && (height-i)==1){
                            count++;
                        }
                    }
                }
                //sag alt yon
                if(i+1<height && j+1<width && gameCells[i+1][j+1].getContent()==user){
                    if(i+2<height && j+2<width && gameCells[i+2][j+2].getContent()==user){
                        if(i+3<height && j+3<width && gameCells[i+3][j+3].getContent()=="." && i+4<height &&
                           gameCells[i+4][j+3].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sag alt yon 2
                if(i+1<height && j+1<width && gameCells[i+1][j+1].getContent()==user){
                    if(i+3<height && j+3<width && gameCells[i+3][j+3].getContent()==user){
                        if(gameCells[i+2][j+2].getContent()=="." && gameCells[i+3][j+2].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sol alt yon
                if(i+1<height && j-1>=0 && gameCells[i+1][j-1].getContent()==user){
                    if(i+2<height && j-2>=0 && gameCells[i+2][j-2].getContent()==user){
                        if(i+3<height && j-3>=0 && gameCells[i+3][j-3].getContent()=="." && i+4<height &&
                           gameCells[i+4][j-3].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sol alt yon 2
                if(i+1<height && j-1>=0 && gameCells[i+1][j-1].getContent()==user){
                    if(i+3<height && j-3>=0 && gameCells[i+3][j-3].getContent()==user){
                        if(gameCells[i+2][j-2].getContent()=="." && gameCells[i+3][j-2].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sol yon
                if(j-1>=0 && gameCells[i][j-1].getContent()==user){
                    if(j-2>=0 && gameCells[i][j-2].getContent()==user){
                        if(j-3>=0 && gameCells[i][j-3].getContent()=="." && i+1<height &&
                           gameCells[i+1][j-3].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sol yon 2
                if(j-1>=0 && gameCells[i][j-1].getContent()==user){
                    if(j-3>=0 && gameCells[i][j-3].getContent()==user){
                        if(gameCells[i][j-2].getContent()=="." && i+1<height && gameCells[i+1][j-2].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sol yon sinir
                if(j-1>=0 && gameCells[i][j-1].getContent()==user){
                    if(j-2>=0 && gameCells[i][j-2].getContent()==user){
                        if(j-3>=0 && gameCells[i][j-3].getContent()=="." && (height-i)==1){
                            count++;
                        }
                    }
                }
                // sol yon sinir 2
                if(j-1>=0 && gameCells[i][j-1].getContent()==user){
                    if(j-3>=0 && gameCells[i][j-3].getContent()==user){
                        if(gameCells[i][j-2].getContent()=="." && (height-i)==1){
                            count++;
                        }
                    }
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getContent()==user){
                    if(i-2>=0 && j-2>=0 && gameCells[i-2][j-2].getContent()==user){
                        if(i-3>=0 && j-3>=0 && gameCells[i-3][j-3].getContent()=="." && gameCells[i-2][j-3].getContent()!="."){
                            count++;
                        }
                    }
                }
                //sol ust yon 2
                if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getContent()==user){
                    if(i-3>=0 && j-3>=0 && gameCells[i-3][j-3].getContent()==user){
                        if(gameCells[i-2][j-2].getContent()=="." && gameCells[i-1][j-2].getContent()!="."){
                            count++;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
void ConnectFour::printBoard() {
    for(auto i=0;i<width;i++){
        cout << (char)(i+97) << " " ;
    }
    cout<<endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout<<gameCells.at(i).at(j).getContent();
            cout<<" ";
        }
        cout<<endl;
    }
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

        myfile>>width>>height>>user>>mod;

        vector<vector<Cell>> a(height,vector<Cell>(width));
        gameCells=a;
        //boardun doldurulması
        setAliveCells(0);
        cout<<"Yeni oyun yüklenirken LivinCells sıfırlanıyor.."<<endl;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                myfile>>content;
                gameCells.at(i).at(j).setContent(content);
                gameCells.at(i).at(j).setRow(i);
                gameCells.at(i).at(j).setCol(j);
                if(content=="X" || content=="O")
                    aliveCell++;
            }
        }
        myfile.close();

        if(mod==1)
            UCSingle(user);
        else
            UUSingle(user);
    }
    else
        cerr<<"Failed to open file"<<endl;
}
int ConnectFour::writeFile(string filename,int user,int userMod) {
    ofstream file(filename);

    if(file.is_open()){
        file<<getWidth()<<" "<<getHeight()<<" "<<user<<" "<<userMod<<"\n";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                file<<gameCells.at(i).at(j).getContent()<<" ";
            }
            file<<"\n";
        }
    }
    else
        cerr<<"Failed to open"<<endl;
    file.close();
}
int ConnectFour::readFileMulti(string filename) {
    int size;
    auto mod=0,user=1;
    ifstream myfile(filename);
    ifstream myfile2(filename);
    string content;
    int count=0;

    if (myfile.is_open())
    {
        myfile2.seekg(0,ios::end);
        size_t size = myfile2.tellg();
        if( size == 0)
        {
            setGameEnded(true);
            cerr << "File is empty\n";
            return -1;
        }

        for (int k = 0; k < height; ++k) {
            for (int i = 0; i < width; ++i) {
                if(gameCells.at(k).at(i).getContent()=="O" || gameCells.at(k).at(i).getContent()=="X"){
                    count++;
                }
            }
        }
        string temp;
        string temp2;
        myfile>>width>>height>>temp>>temp2;
        if(temp=="1")
            setUserSira(1);
        else
            setUserSira(2);

        setUserMod(temp2);

        vector<vector<Cell>> a(height,vector<Cell>(width));
        gameCells=a;
        //boardun doldurulması
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                myfile>>content;
                gameCells.at(i).at(j).setContent(content);
                gameCells.at(i).at(j).setRow(i);
                gameCells.at(i).at(j).setCol(j);
                if(content=="X" || content=="O")
                    aliveCell++;
            }
        }
        myfile.close();
    }
    else
        cerr<<"Failed to open file"<<endl;

    return count;
}
int ConnectFour::writeFileMulti(string filename, int user,string userMod) {
    ofstream file(filename);

    if(file.is_open()){
        file<<getWidth()<<" "<<getHeight()<<" "<<user<<" "<<userMod<<"\n";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                file<<gameCells.at(i).at(j).getContent()<<" ";
            }
            file<<"\n";
        }
    }
    else
        cerr<<"Failed to open"<<endl;
    file.close();
}
bool ConnectFour::isGameEnded() {
    if(getGameEnded()==true)true;
    else
        false;
}
int ConnectFour::play() {
    int choice=computer();
    int row=isCellEmpty(choice);//row indis turunden choice ise user secımı turunden
    if(row==-1)
        cout<<"Full Colums";
    else {
        gameCells[row][choice - 1].setContent("O");
        gameCells[row][choice - 1].setCol(choice - 1);
        gameCells[row][choice - 1].setRow(row);
        setUserSira(getUserSira() + 1);
        aliveCell++;
    }
}
int ConnectFour::play(int cellPos) {
    int row=isCellEmpty(cellPos);//row indis turunden choice ise user secımı turunden
    if(row==-1)
        cout<<"Full Colums";
    else {
        if ((getUserSira()%2)==1) {
            gameCells[row][cellPos-1].setContent("X");
            gameCells[row][cellPos-1].setCol(cellPos-1);
            gameCells[row][cellPos-1].setRow(row);
            setUserSira(getUserSira()+1);
            aliveCell++;

        }
        else
        {
            gameCells[row][cellPos-1].setContent("O");
            gameCells[row][cellPos-1].setCol(cellPos-1);
            gameCells[row][cellPos-1].setRow(row);
            setUserSira(getUserSira()+1);
            aliveCell++;
        }
    }
    return 1;
}
int ConnectFour::playGame() {
    bool mainFlag=true,flagGm;
    char control;
    int width,height;
    string gamemod,usermod;
    while(mainFlag){
        flagGm=true;
        cout << "Welcome to ConnectFour" << endl;
        cout<<"Oyun Modunu Seçiniz ( Single ('S') or Multi ('M') ):";
        while(flagGm){
            cin>>gamemod;
            if(gamemod=="S" || gamemod=="M"){
                setGameMod(gamemod);
                flagGm=false;
            }
            else
                cerr<<"Wrong game mod. Please try again!."<<endl;
        }
        if(getGameMod()=="S"){
            if(startInputTakeSingle(usermod,width, height)) {
                setHeight(height);
                setWidth(width);
                setUserMod(usermod);
                startingGame();
            }
            gameSingle();
        }
        else if(getGameMod()=="M"){
            gameMulti();
        }

        cout<<"Oyun basa donerken LivingCells sıfırlanıyor"<<endl;
        cout<<"Do you want to exit ? Press to 'e' :";
        cin>>control;
        if(control == 'e')
            mainFlag= false;
        setAliveCells(0);
        setUserSira(1);
    }
    return 1;
}
int ConnectFour::startInputTakeSingle(string &usermod,int &width, int &height) {
    bool mainflag=true,flagEn,flagBoy,flagUm;
    while(mainflag){
        flagEn=true,flagBoy=true,flagUm=true;
        while(flagEn){
            cout<<"En giriniz:";
            cin>>width;
            if(!cin.fail()){
                if(width>=4 && width<=50)
                    flagEn= false;
                else
                    cerr<<"Wrong width value"<<endl;
            }
            cin.clear();
            cin.ignore(10, '\n');
        }
        while(flagBoy){
            cout<<"Boy giriniz:";
            cin>>height;
            if(!cin.fail()){
                if(height>=4 && height<=50)
                    flagBoy= false;
                else
                    cerr<<"Wrong height value."<<endl;
            }
            cin.clear();
            cin.ignore(10, '\n');
        }
        cout << "If you want (User vs User) mode , press to 'P'" << endl;//mode 0
        cout << "If you want (User vs Computer) mode , press to 'C'" << endl;//mode 1
        while(flagUm){
            cout << "Your choice:";
            cin >> usermod;
            if (usermod == "P" || usermod=="C") {
                flagUm=false;
            }
            else
                cerr<<"Wrong Choice ! . Please enter the mode again ."<<endl;
        }
        mainflag=false;
    }
    return 1;
}
int ConnectFour::startingGame() {
    vector<vector<Cell>> a(height,vector<Cell>(width));
    gameCells=a;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            gameCells.at(i).at(j).setContent(".");
            gameCells.at(i).at(j).setRow(i);
            gameCells.at(i).at(j).setCol(j);
        }
    }
}
int ConnectFour::gameSingle() {
    if(userMod=="P")
        UUSingle();
    if(userMod=="C")
        UCSingle();
}
int ConnectFour::gameMulti() {
    bool mainFlag=true,objectNumberFlag=true,choiceObjectsFlag;
    int objectNumber=0;
    int choiceObject;
    while(objectNumberFlag){
        cout<<"Lütfen çaıştırılacak object sayısını seçiniz:";
        cin>>objectNumber;
        if(!cin.fail()){
            if(objectNumber>=0 && objectNumber<=20 ){
                objectNumberFlag=false;
            }
            else
                cerr<<"Wrong object number value"<<endl;
        }
        cin.clear();
        cin.ignore(10, '\n');
    }
    refactorObjects(objectNumber);
    cout<<"Multigame is starting..."<<endl;
    while (mainFlag){
        choiceObjectsFlag=true;
        cout<<"Obje seciniz:";
       while(choiceObjectsFlag){
           cin>>choiceObject;
           if(!cin.fail()){
               if(choiceObject>=1 && choiceObject<=objects.size())
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
        cout<<"COMPARE Function(objeclerin 3lü('X') tas sayılarını karsilastırır)==>"<<"object1vsobject2:"<<objects[0].compare(objects[1])<<endl;

        int count=0;
        for (int i = 0; i < objects.size(); ++i) {
            if(objects[i].getGameEnded())
                count++;
        }
        if(count==objects.size()){
            cout<<"MultiGame is ended."<<endl;
            mainFlag=false;
        }

    }
}
int ConnectFour::objectInputKontrol(int &en, int &boy, string &usermod) {
    bool mainflag=true,flagBoy,flagUm,flagEn;
    while(mainflag){
        flagEn=true,flagBoy=true,flagUm=true;
        while(flagEn){
            cout<<"En giriniz:";
            cin>>en;
            if(!cin.fail()){
                if(en>=4 && en<=50)
                    flagEn= false;
                else
                    cerr<<"Please enter true range of value"<<endl;
            }
            cin.clear();
            cin.ignore(10, '\n');
        }
        while(flagBoy){
            cout<<"Boy giriniz:";
            cin>>boy;
            if(!cin.fail()){
                if(boy>=4 && boy<=50)
                    flagBoy= false;
                else
                    cerr<<"Please enter true range of value"<<endl;
            }
            cin.clear();
            cin.ignore(10, '\n');
        }
        cout << "If you want (User vs User) mode , press to 'P'" << endl;//mode 0
        cout << "If you want (User vs Computer) mode , press to 'C'" << endl;//mode 1
        while(flagUm){
            cout << "Your choice:";
            cin >> usermod;
            if (usermod == "P" || usermod=="C") {
                flagUm=false;
            }
            else
                cerr<<"Wrong Choice ! . Please enter the mode again ."<<endl;
        }
        mainflag=false;
    }
    return 1;
}
int ConnectFour::refactorObjects(int objectNumber) {
    int en,boy;
    string usermod;

    objects.resize(objectNumber);
    for (int i = 0; i < objectNumber; ++i) {
        cout<<"Object"<<i+1<<":"<<endl;
        if(objectInputKontrol(en,boy,usermod)){
            ConnectFour temp(en,boy,usermod,i);
            //cout<<"temp"<<temp.getObjectNumber()<<" height"<<temp.getHeight()<<" width"<<temp.getWidth()<<" usermod"<<temp.getUserMod()<<endl;
            objects[i]=temp;
                    }
    }
}
int ConnectFour::UUMulti() {
    bool mainflag=true,flag1=true,flag2=true;
    string choice,choice2;
    int mychoice,ind=0;
    int user;

    while(ind<=1 && mainflag){
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
            mychoice=computer();
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
    while(!winControl && flagLoaded){
        choice=0;
        flag=1;
        printBoard();
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
                if(choiceChar.length()==1)
                    choice=charToInt(choiceChar[0]);
                if(choice>=1 && choice<=width)
                    flag=0;
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
                if(choice>=1 && choice<=width)
                    flag=0;
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
            cout<<"User";
            cout<<user;
            cout<<" Win !!!"<<endl;
            winControl=1;
        }
        sira++;
        cout<<"LivingCell:"<<getAliveCells()<<endl;
    }

    return 0;
}
int ConnectFour::UCSingle(int user){
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
    while(!winControl && flagLoaded){
        choice=0;
        flag=1;
        printBoard();
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
                if(choice>=1 && choice<=width)
                    flag=0;
                else if((choiceChar.length()==1 || choice==0) && flagLoaded!=false){
                    cerr<<"Wrong Choice! Please try again ."<<endl;
                }
            }
        }
        else{
            user=2;
            choice=computer();
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
                cout << "User1 Win !!!";
            }
            else{
                printBoard();
                cout<<"Computer Win !!!"<<endl;}

            winControl=1;
        }
        sira++;
        cout<<"LivingCell:"<<getAliveCells()<<endl;
    }
}
int ConnectFour::isBoardEmpty() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(gameCells[i][j].getContent()==".")
                return 1;
        }
    }
    return 0;
}
int ConnectFour::isColumnEmpty(int choice) {
    if(gameCells[0][choice-1].getContent()==".")
        return 1;
    else
        return 0;
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
int ConnectFour::columnKontrol(string value) {
    if(value.length()==1){
        if( (value[0]>='A' && value[0]<='Z') || ((value[0]>='a' && value[0]<='z')) )
            return 1;
    }
    return 0;
}
int ConnectFour::checkWin(int user) {
    if(user==1){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(gameCells[i][j].getContent()=="X"){
                    if(control8Way("X",i,j)) {
                        return 1;
                    }
                }
            }
        }
    }
    if(user==2){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(gameCells[i][j].getContent()=="O"){
                    if(control8Way("O",i,j)){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int ConnectFour::isCellEmpty(int choice) {
    for(int i=height-1;i>=0;i--){
        if(gameCells[i][choice-1].getContent()==".")
            return i;
    }
    return -1;
}
int ConnectFour::isChoiceKontrol(string value) {
    if(value.length()!=1){
        if( !(value[0]>='A' && value[0]>='Z') || !((value[0]>='a' && value[0]>='z')) )
            return 1;
    }
    return 0;
}
int ConnectFour::control8Way(string user, int coord1, int coord2) {
    //ust dıkey
    if(coord1-1>=0 && gameCells[coord1-1][coord2].getContent()==user ){
        if(coord1-2>=0 && gameCells[coord1-2][coord2].getContent()==user){
            if(coord1-3>=0 && gameCells[coord1-3][coord2].getContent()==user){
                return 1;
            }
        }
    }
    //ust sag kose
    if(coord1-1>=0 && coord2+1<width && gameCells[coord1-1][coord2+1].getContent()==user ){
        if(coord1-2>=0 && coord2+2<width && gameCells[coord1-2][coord2+2].getContent()==user){
            if(coord1-3>=0 && coord2+3<width && gameCells[coord1-3][coord2+3].getContent()==user){
                return 1;
            }
        }
    }
    //sag yatay
    if(coord2+1<width && gameCells[coord1][coord2+1].getContent()==user ){
        if(coord2+2<width && gameCells[coord1][coord2+2].getContent()==user){
            if(coord2+3<width && gameCells[coord1][coord2+3].getContent()==user){
                return 1;
            }
        }
    }
    //alt sag kose
    if(coord1+1<height && coord2+1<width && gameCells[coord1+1][coord2+1].getContent()==user ){
        if(coord1+2<height && coord2+2<width && gameCells[coord1+2][coord2+2].getContent()==user){
            if(coord1+3<height && coord2+3<width && gameCells[coord1+3][coord2+3].getContent()==user){
                return 1;
            }
        }
    }
    //alt dikey
    if(coord1+1<height && gameCells[coord1+1][coord2].getContent()==user ){
        if(coord1+2<height && gameCells[coord1+2][coord2].getContent()==user){
            if(coord1+3<height && gameCells[coord1+3][coord2].getContent()==user){
                return 1;
            }
        }
    }
    //sol alt kose
    if(coord1+1<height && coord2-1>=0 && gameCells[coord1+1][coord2-1].getContent()==user ){
        if(coord1+2<height && coord2-2>=0 && gameCells[coord1+2][coord2-2].getContent()==user){
            if(coord1+3<height && coord2-3>=0 && gameCells[coord1+3][coord2-3].getContent()==user){
                return 1;
            }
        }
    }
    //sol yatay
    if(coord2-1>=0 && gameCells[coord1][coord2-1].getContent()==user ){
        if(coord2-2>=0 && gameCells[coord1][coord2-2].getContent()==user){
            if(coord2-3>=0 && gameCells[coord1][coord2-3].getContent()==user){
                return 1;
            }
        }
    }
    //sol ust kose
    if(coord1-1>=0 && coord2-1>=0 && gameCells[coord1-1][coord2-1].getContent()==user ){
        if(coord1-2>=0 && coord2-2>=0 && gameCells[coord1-2][coord2-2].getContent()==user){
            if(coord1-3>=0 && coord2-3>=0 && gameCells[coord1-3][coord2-3].getContent()==user){
                return 1;
            }
        }
    }

    return 0;
}
int ConnectFour::getAliveCellsOfObjects() {
    int result=0;
    for (int i = 0; i < objects.size(); ++i) {
        result+=objects[i].getAliveCells();
    }
}
///Computer fonksiyonlarııı
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
            if(gameCells[i][j].getContent()=="O"){
                //yukari yon
                if(i-1>=0 && gameCells[i-1][j].getContent()=="O" ){
                    if(i-2>=0 && gameCells[i-2][j].getContent()=="O"){
                        if(i-3>=0 && gameCells[i-3][j].getContent()=="."){
                            targetCoord2=(j);
                            return 1;
                        }
                    }
                }
                //yukari sag yon
                if(i-1>=0 && j+1<width && gameCells[i-1][j+1].getContent()=="O" ){
                    if(i-2>=0 && j+2<width && gameCells[i-2][j+2].getContent()=="O"){
                        if(i-3>=0 && j+3<width && gameCells[i-3][j+3].getContent()=="." &&
                                gameCells[i-2][j+3].getContent()!="."){
                            targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //yukari sag yon 2
                if(i-1>=0 && j+1<width && gameCells[i-1][j+1].getContent()=="O" ){
                    if(i-3>=0 && j+3<width && gameCells[i-3][j+3].getContent()=="O"){
                        if(gameCells[i-2][j+2].getContent()=="." && gameCells[i-1][j+2].getContent()!="."){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag yon
                if(j+1<width && gameCells[i][j+1].getContent()=="O" ){
                    if(j+2<width && gameCells[i][j+2].getContent()=="O"){
                        if(j+3<width && gameCells[i][j+3].getContent()=="." && i+1<height &&
                           gameCells[i+1][j+3].getContent()!="."){
                            targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag yon 2
                if(j+1<width && gameCells[i][j+1].getContent()=="O" ){
                    if(j+3<width && gameCells[i][j+3].getContent()=="O"){
                        if(gameCells[i][j+2].getContent()=="." && i+1<height && gameCells[i+1][j+2].getContent()!="."){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag yon sinir
                if(j+1<width && gameCells[i][j+1].getContent()=="O" ){
                    if(j+2<width && gameCells[i][j+2].getContent()=="O"){
                        if(j+3<width && gameCells[i][j+3].getContent()=="." && (height-i)==1){
                            targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag yon sinir 2
                if(j+1<width && gameCells[i][j+1].getContent()=="O" ){
                    if(j+3<width && gameCells[i][j+3].getContent()=="O"){
                        if(gameCells[i][j+2].getContent()=="." && (height-i)==1){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag alt yon
                if(i+1<height && j+1<width && gameCells[i+1][j+1].getContent()=="O" ){
                    if(i+2<height && j+2<width && gameCells[i+2][j+2].getContent()=="O"){
                        if(i+3<height && j+3<width && gameCells[i+3][j+3].getContent()=="." && i+4<height &&
                           gameCells[i+4][j+3].getContent()!="."){
                            targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag alt yon 2
                if(i+1<height && j+1<width && gameCells[i+1][j+1].getContent()=="O"){
                    if(i+3<height && j+3<width && gameCells[i+3][j+3].getContent()=="O"){
                        if(gameCells[i+2][j+2].getContent()=="." && gameCells[i+3][j+2].getContent()!="."){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sol alt yon
                if(i+1<height && j-1>=0 && gameCells[i+1][j-1].getContent()=="O" ){
                    if(i+2<height && j-2>=0 && gameCells[i+2][j-2].getContent()=="O"){
                        if(i+3<height && j-3>=0 && gameCells[i+3][j-3].getContent()=="." && i+4<height &&
                           gameCells[i+4][j-3].getContent()!="."){
                            targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol alt yon 2
                if(i+1<height && j-1>=0 && gameCells[i+1][j-1].getContent()=="O"){
                    if(i+3<height && j-3>=0 && gameCells[i+3][j-3].getContent()=="O"){
                        if(gameCells[i+2][j-2].getContent()=="." && gameCells[i+3][j-2].getContent()!="."){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol yon
                if(j-1>=0 && gameCells[i][j-1].getContent()=="O"){
                    if(j-2>=0 && gameCells[i][j-2].getContent()=="O"){
                        if(j-3>=0 && gameCells[i][j-3].getContent()=="." && i+1<height &&
                           gameCells[i+1][j-3].getContent()!="."){
                            targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol yon 2
                if(j-1>=0 && gameCells[i][j-1].getContent()=="O"){
                    if(j-3>=0 && gameCells[i][j-3].getContent()=="O"){
                        if(gameCells[i][j-2].getContent()=="." && i+1<height && gameCells[i+1][j-2].getContent()!="."){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol yon sinir
                if(j-1>=0 && gameCells[i][j-1].getContent()=="O"){
                    if(j-2>=0 && gameCells[i][j-2].getContent()=="O"){
                        if(j-3>=0 && gameCells[i][j-3].getContent()=="." && (height-i)==1){
                            targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                // sol yon sinir 2
                if(j-1>=0 && gameCells[i][j-1].getContent()=="O"){
                    if(j-3>=0 && gameCells[i][j-3].getContent()=="O"){
                        if(gameCells[i][j-2].getContent()=="." && (height-i)==1){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getContent()=="O"){
                    if(i-2>=0 && j-2>=0 && gameCells[i-2][j-2].getContent()=="O"){
                        if(i-3>=0 && j-3>=0 && gameCells[i-3][j-3].getContent()=="." && gameCells[i-2][j-3].getContent()!="."){
                            targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol ust yon 2
                if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getContent()=="O"){
                    if(i-3>=0 && j-3>=0 && gameCells[i-3][j-3].getContent()=="O"){
                        if(gameCells[i-2][j-2].getContent()=="." && gameCells[i-1][j-2].getContent()!="."){
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
int ConnectFour::kontrol2tas(int &targetCoord2){
    for (auto i = 0; i <height ; ++i) {
        for (auto j = 0; j <width ; ++j) {
            if(gameCells[i][j].getContent()=="O"){
                //yukari yon
                if(i-1>=0 && gameCells[i-1][j].getContent()=="O" ){
                    if(i-2>=0 && gameCells[i-2][j].getContent()=="."){
                        targetCoord2=(j);
                        return 1;
                    }
                }
                //sag yukarı yon
                if(i-1>=0 && j+1<width && gameCells[i-1][j+1].getContent()=="O" ){
                    if(i-2>=0 && j+2<width && gameCells[i-2][j+2].getContent()=="." &&
                            gameCells[i-1][j+2].getContent()!="."){
                        targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag yon
                if(j+1<width && gameCells[i][j+1].getContent()=="O" ){
                        if(j+2<width && gameCells[i][j+2].getContent()=="." && i+1<height &&
                                gameCells[i+1][j+2].getContent()!="."){
                        targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag yon (sinir)
                if(j+1<width && gameCells[i][j+1].getContent()=="O" ){
                    if(j+2<width && gameCells[i][j+2].getContent()=="." && (height-i)==1){
                        targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag asagı yon
                if(i+1<height && j+1<width && gameCells[i+1][j+1].getContent()=="O" ){
                    if(i+2<height && j+2<width && gameCells[i+2][j+2].getContent()=="." && i+3<height &&
                       gameCells[i+3][j+2].getContent()!="."){
                        targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sol asagı yon
                if(i+1<height && j-1>=0 && gameCells[i+1][j-1].getContent()=="." ){
                    if(i+2<height && j-2>=0 && gameCells[i+2][j-2].getContent()=="." && i+3<height &&
                       gameCells[i+3][j-2].getContent()!="."){
                        targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol yon
                if(j-1>=0 && gameCells[i][j-1].getContent()=="O" ){
                    if(j-2>=0 && gameCells[i][j-2].getContent()=="." && i+1<height && gameCells[i+1][j-2].getContent()!="O"){
                        targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol yon sinir
                if(j-1>=0 && gameCells[i][j-1].getContent()=="O" ){
                    if(j-2>=0 && gameCells[i][j-2].getContent()=="." && (height-i)==1){
                        targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getContent()=="O" ){
                    if(i-2>=0 && j-2>=0 && gameCells[i-2][j-2].getContent()=="." && gameCells[i-1][j-2].getContent()!="."){
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
            if(gameCells[i][j].getContent()=="O"){
                //yukari yon
                if(i-1>=0 && gameCells[i-1][j].getContent()=="." ){
                    targetCoord2=j;
                    return 1;
                }
                //yukari sag yon
                if(i-1>=0 && j+1<width && gameCells[i-1][j+1].getContent()=="." && i<height
                   && gameCells[i][j+1].getContent()!="." ){
                    targetCoord2=(j+1);
                    return 1;
                }
                //sag yon
                if(j+1<width && gameCells[i][j+1].getContent()=="." && i+1<height && gameCells[i+1][j+1].getContent()!="." ){
                    targetCoord2=(j+1);
                    return 1;
                }
                //sag yon(sinir)
                if(j+1<width && gameCells[i][j+1].getContent()=="." && (height-i)==1 ){
                    targetCoord2=(j+1);
                    return 1;
                }

                //sag alt yon
                if(i+1<height && j+1<width && gameCells[i+1][j+1].getContent()=="." && i+2<height
                   && gameCells[i+2][j+1].getContent()!="." ){
                    targetCoord2=(j+1);
                    return 1;
                }
                //sol alt yon
                if(i+1<height && j-1>=0 && gameCells[i+1][j-1].getContent()=="." && i+2<height
                   && gameCells[i+2][j-1].getContent()!="." ){
                    targetCoord2=(j-1);
                    return 1;
                }
                //sol yon
                if(j-1>=0 && gameCells[i][j-1].getContent()=="." && i+1<height && gameCells[i+1][j-1].getContent()!="." ){
                    targetCoord2=(j-1);
                    return 1;
                }
                //sol yon sinir
                if(j-1>=0 && gameCells[i][j-1].getContent()=="." && (height-i)==1){
                    targetCoord2=(j-1);
                    return 1;
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getContent()=="." && i<height
                   && gameCells[i][j-1].getContent()!="." ){
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
            if (gameCells[i][j].getContent()=="X") {
                //yukari sag yon
                if (i - 1 >= 0 && j + 1 < width && gameCells[i - 1][j + 1].getContent() == "X") {
                    if (i - 3 >= 0 && j + 3 < width && gameCells[i - 3][j + 3].getContent() == "X") {
                        if (gameCells[i - 2][j + 2].getContent() == "." && gameCells[i - 1][j + 2].getContent() != ".")
                            return (j + 2);

                    }
                }
                //sag yon
                if (j + 1 < width && gameCells[i][j + 1].getContent() =="X") {
                    if (j + 3 < width && gameCells[i][j + 3].getContent() == "X") {
                        if (gameCells[i][j + 2].getContent() == "." && i + 1 <height && gameCells[i + 1][j + 2].getContent() !=".")
                            return (j + 2);
                    }
                }
                //sag yon sinir
                if (j + 1 < width && gameCells[i][j + 1].getContent() == "X") {
                    if (j + 3 < width && gameCells[i][j + 3].getContent() == "X") {
                        if (gameCells[i][j + 2].getContent() == "." && (height - i == 1))
                            return (j + 2);
                    }
                }
                //sag alt yon
                if (i + 1 < height && j + 1 < width && gameCells[i + 1][j + 1].getContent() == "X") {
                    if (i + 3 < height && j + 3 < width && gameCells[i + 3][j + 3].getContent() == "X") {
                        if (gameCells[i + 2][j + 2].getContent() == "." && i + 4 < height && gameCells[i + 4][j + 2].getContent() != ".")
                            return (j + 2);
                    }
                }
                //sag alt yon 2
                if (i + 1 < height && j + 1 < width && gameCells[i + 1][j + 1].getContent() == "X") {
                    if (i + 3 == height -1 && j + 3 < width && gameCells[i + 3][j + 3].getContent() == "X") {
                        if (gameCells[i + 2][j + 2].getContent() == "." )
                            return (j + 2);
                    }
                }
                //sol alt yon
                if (i + 1 < height && j - 1 >= 0 && gameCells[i + 1][j - 1].getContent() == "X") {
                    if (i + 3 < height && j - 3 >= 0 && gameCells[i + 3][j - 3].getContent() == "X") {
                        if (gameCells[i + 2][j - 2].getContent() =="." && i + 4 < height && gameCells[i + 4][j - 2].getContent() != ".")
                            return (j - 2);
                    }
                }
                //sol alt yon 2
                if (i + 1 < height && j - 1 >= 0 && gameCells[i + 1][j - 1].getContent() == "X") {
                    if (i + 3 == height-1 && j - 3 >= 0 && gameCells[i + 3][j - 3].getContent() == "X") {
                        if (gameCells[i + 2][j - 2].getContent() == "." && i + 4 < height)
                            return (j - 2);
                    }
                }
                //sol yon
                if (j - 1 >= 0 && gameCells[i][j - 1].getContent() == "X") {
                    if (j - 3 >= 0 && gameCells[i][j - 3].getContent() == "X") {
                        if (gameCells[i][j - 2].getContent() == "." && i + 1 < height && gameCells[i + 1][j - 2].getContent() != ".")
                            return (j - 2);
                    }
                }
                //sol yon sinir
                if (j - 1 >= 0 && gameCells[i][j - 1].getContent() == "X") {
                    if (j - 3 >= 0 && gameCells[i][j - 3].getContent() == "X") {
                        if (gameCells[i][j - 2].getContent() == "." && (height - i) == 1)
                            return (j - 2);
                    }
                }
                //yukarı sol yon
                if (i - 1 >= 0 && j - 1 >= 0 && gameCells[i - 1][j - 1].getContent() == "X") {
                    if (i - 3 >= 0 && j - 3 >= 0 && gameCells[i - 3][j - 3].getContent() == "X") {
                            if (gameCells[i - 2][j - 2].getContent() == "." && gameCells[i - 1][j - 2].getContent() != ".")
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
            if(gameCells[i][j].getContent()=="X"){
                //yukari yon
                if(i-1>=0 && gameCells[i-1][j].getContent()=="X" ){
                    if(i-2>=0 && gameCells[i-2][j].getContent()=="X"){
                        if(i-3>=0 && gameCells[i-3][j].getContent()==".")
                            return j;
                    }
                }
                //yukari sag yon
                if(i-1>=0 && j+1<width && gameCells[i-1][j+1].getContent()=="X" ){
                    if(i-2>=0 && j+2<width && gameCells[i-2][j+2].getContent()=="X"){
                        if(i-3>=0 && j+3<width && gameCells[i-3][j+3].getContent()=="." && gameCells[i-2][j+3].getContent()!="." )
                            return (j+3);
                    }
                }
                //sag yon
                if(j+1<width && gameCells[i][j+1].getContent()=="X" ){
                    if(j+2<width && gameCells[i][j+2].getContent()=="X"){
                        if(j+3<width && gameCells[i][j+3].getContent()=="." && i+1<height && gameCells[i+1][j+3].getContent()!=".")
                            return (j+3);
                    }
                }
                //sag yon sinir
                if(j+1<width && gameCells[i][j+1].getContent()=="X" ){
                    if(j+2<width && gameCells[i][j+2].getContent()=="X"){
                        if(j+3<width && gameCells[i][j+3].getContent()=="." && (height-i)==1 )
                            return (j+3);
                    }
                }
                //sag alt yon
                if(i+1<height && j+1<width && gameCells[i+1][j+1].getContent()=="X" ){
                    if(i+2<height && j+2<width && gameCells[i+2][j+2].getContent()=="X"){
                        if(i+3<height && j+3<width && gameCells[i+3][j+3].getContent()=="." && i+4<height &&
                           gameCells[i+4][j+3].getContent()!="." )
                            return (j+3);
                    }
                }
                //sag alt yon 2
                if(i+1<height && j+1<width && gameCells[i+1][j+1].getContent()=="X" ){
                    if(i+2<height && j+2<width && gameCells[i+2][j+2].getContent()=="X"){
                        if(i+3==height-1 && j+3<width && gameCells[i+3][j+3].getContent()=="." )
                            return (j+3);
                    }
                }
                //sol alt yon
                if(i+1<height && j-1>=0 && gameCells[i+1][j-1].getContent()=="X" ){
                    if(i+2<height && j-2>=0 && gameCells[i+2][j-2].getContent()=="X"){
                        if(i+3<height && j-3>=0 && gameCells[i+3][j-3].getContent()=="." && i+4<height &&  gameCells[i+4][j-3].getContent()!="." )
                            return (j-3);
                    }
                }
                //sol alt yon2
                if(i+1<height && j-1>=0 && gameCells[i+1][j-1].getContent()=="X" ){
                    if(i+2<height && j-2>=0 && gameCells[i+2][j-2].getContent()=="X"){
                        if(i+3==height-1 && j-3>=0 && gameCells[i+3][j-3].getContent()==".")
                            return (j-3);
                    }
                }
                //sol yon
                if(j-1>=0 && gameCells[i][j-1].getContent()=="X" ){
                    if(j-2>=0 && gameCells[i][j-2].getContent()=="X"){
                        if(j-3>=0 && gameCells[i][j-3].getContent()=="." && i+1<height && gameCells[i+1][j-3].getContent()!=".")
                            return (j-3);
                    }
                }
                //sol yon sinir
                if(j-1>=0 && gameCells[i][j-1].getContent()=="X"){
                    if(j-2>=0 && gameCells[i][j-2].getContent()=="X"){
                        if(j-3>=0 && gameCells[i][j-3].getContent()=="." && (height-i)==1)
                            return (j-3);
                    }
                }
                //yukarı sol yon
                if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getContent()=="X"){
                    if(i-2>=0 && j-2>=0 && gameCells[i-2][j-2].getContent()=="X"){
                        if(i-3>=0 && j-3>=0 && gameCells[i-3][j-3].getContent()=="." && gameCells[i-2][j-3].getContent()!="." )
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
            if(height-i==1 &&  gameCells[i][j].getContent()=="X"){
                //sag sinir
                if(j+1<width && gameCells[i][j+1].getContent()=="X"){
                    if(j+2<width && gameCells[i][j+2].getContent()==".")
                        return j+2;
                }
                //sol sinir
                if(j-1>=0 && gameCells[i][j-1].getContent()=="X"){
                    if(j-2>=0 && gameCells[i][j-2].getContent()==".")
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
            if(gameCells[i][j].getContent()=="X"){
                //sol yon
                if( (height-i==1) && j-1>=0 && gameCells[i][j-1].getContent()=="."){
                    return (j-1);
                }
                //sag yon
                if( (height-i==1) && j+1<width && gameCells[i][j+1].getContent()=="." ){
                    return (j+1);
                }
            }
        }
    }
    return 0;
}













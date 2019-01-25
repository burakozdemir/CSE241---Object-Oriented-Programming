//
// Created by burki on 23.11.2017.
//

#include "ConnectFourAbstract.h"

namespace ConnectSpace {
    int ConnectFourAbstract::aliveCell= 0;
    ConnectFourAbstract::ConnectFourAbstract():width(5),height(5),userMod(""),objectNumber(0),userSira(1),
                                               gameEnded(false){
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
    ConnectFourAbstract::ConnectFourAbstract(const int numberRow, const int numberCol):height(numberRow),width(numberCol){
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
    ConnectFourAbstract::ConnectFourAbstract(string filename):userMod(""),objectNumber(0),userSira(1),gameEnded(false){
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
    ConnectFourAbstract::ConnectFourAbstract(const ConnectFourAbstract &object) {
        this->height=object.height;
        this->width=object.width;
        this->gameEnded=object.gameEnded;
        this->aliveCell=object.aliveCell;
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
    ConnectFourAbstract::~ConnectFourAbstract() {
        for (int i = 0; i < height; ++i) {
            delete[] gameBoard[i];
        }
        //delete []objects;
        delete[] gameBoard;
    }
    ConnectFourAbstract &ConnectFourAbstract::operator=(const ConnectFourAbstract &object) {
        this->gameEnded=object.gameEnded;
        this->aliveCell=object.aliveCell;
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

        return *this;
    }
    bool ConnectFourAbstract::isGameEnded() {
        if(getGameEnded()==true)true;
        else
            false;
    }
    void ConnectFourAbstract::printBoard() {
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
    int ConnectFourAbstract::play() {
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
    int ConnectFourAbstract::play(int cellPos) {
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
    int ConnectFourAbstract::SingleP(int user) {
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
                    cinKontrol();
                    cin>>choiceChar;
                    if(isChoiceKontrol(choiceChar)){
                        if(choiceChar=="LOAD"){
                            cinKontrol();
                            cin>>choiceChar2;
                            cout<<"Game is loading"<<endl;
                            cout<<"when game is loading , LivingCells are zero"<<endl;
                            setAliveCells(0);
                            readFile(choiceChar2);
                            flagLoaded=false;
                        }
                        if(choiceChar=="SAVE"){
                            cinKontrol();
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
                    cinKontrol();
                    cin>>choiceChar;
                    if(isChoiceKontrol(choiceChar)){
                        if(choiceChar=="LOAD"){
                            cinKontrol();
                            cin>>choiceChar2;
                            cout<<"Game is loading"<<endl;
                            readFile(choiceChar2);
                            flagLoaded=false;
                        }
                        if(choiceChar=="SAVE"){
                            cinKontrol();
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
                setGameEnded(true);
            }
            sira++;
        }
    }
    int ConnectFourAbstract::SingleC(int user) {
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
                    cinKontrol();
                    cin>>choiceChar;
                    if(isChoiceKontrol(choiceChar)){
                        if(choiceChar=="LOAD"){
                            cinKontrol();
                            cin>>choiceChar2;
                            cout<<"Game is loading"<<endl;
                            cout<<"when game is loading , LivingCells are zero"<<endl;
                            setAliveCells(0);
                            readFile(choiceChar2);
                            flagLoaded=false;
                        }
                        if(choiceChar=="SAVE"){
                            cinKontrol();
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
                setGameEnded(true);
            }
            sira++;
        }
    }
    int ConnectFourAbstract::isCellEmpty(int choice) {
        for(int i=height-1;i>=0;i--){
            if(gameBoard[i][choice-1].getContent()=='*')
                return i;
        }
        return -1;
    }
    int ConnectFourAbstract::isChoiceKontrol(string value) {
        if(value.length()!=1){
            if( !(value[0]>='A' && value[0]<='Z') || !((value[0]>='a' && value[0]<='z')) )
                return 1;
        }
        return 0;
    }
    int ConnectFourAbstract::isBoardEmpty() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(gameBoard[i][j].getContent()=='*')
                    return 1;
            }
        }
        return 0;
    }
    int ConnectFourAbstract::isColumnEmpty(int choice) {
        for (int i = 0; i < height; ++i) {
            if(gameBoard[0][choice-1].getContent()=='*' || gameBoard[0][choice-1].getContent()==' '){}
            else
                return 0;
        }
        return 1;
    }
    int ConnectFourAbstract::charToInt(char value) {
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
    int ConnectFourAbstract::columnKontrol(string value) {
        if(value.length()==1){
            if( (value[0]>='A' && value[0]<='Z') || ((value[0]>='a' && value[0]<='z')) )
                return 1;
        }
        return 0;
    }
    int ConnectFourAbstract::computer() {
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
    int ConnectFourAbstract::kontrolComputer(int &coord2) {
        if(kontrol3tas(coord2))
            return 3;
        else if(kontrol2tas(coord2))
            return 2;
        else if(kontrol1tas(coord2))
            return 1;
        return 0;
    }
    int ConnectFourAbstract::kontrol3tas(int &targetCoord2) {
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
    int ConnectFourAbstract::kontrol2tas(int &targetCoord2) {
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
    int ConnectFourAbstract::kontrol1tas(int &targetCoord2) {
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
    int ConnectFourAbstract::engelleme2() {
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
    int ConnectFourAbstract::engelleme() {
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
    int ConnectFourAbstract::engelleme3() {
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
    int ConnectFourAbstract::firstMove() {
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
    int ConnectFourAbstract::boslukKontrolComp(int indis) {
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
    int ConnectFourAbstract::boslukKontrol(string choice) {
        int secim=charToInt(choice[0]);
        secim--;
        for (int i = 0; i < height; ++i) {
            if(gameBoard[i][secim].getContent()=='*'){
                return 1;
            }
        }
        return 0;
    }
    int ConnectFourAbstract::cinKontrol() {
        if(cin.eof()==true){
            cout<<"oyun sonlanıyor.."<<endl;
            exit(1);
        }
        return 1;
    }
    int ConnectFourAbstract::startInputTakeSingle(string &usermod, int &width, int &height) {
        bool mainflag=true,flagEn,flagBoy,flagUm;
        while(mainflag){
            cinKontrol();
            flagEn=true,flagBoy=true,flagUm=true;
            while(flagEn){
                cinKontrol();
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
                cinKontrol();
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
            cout << "UserMod:" << endl;
            while(flagUm){
                cinKontrol();
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
    void ConnectFourAbstract::setObject(const int width,const int height) {
        for (int i = 0; i < 5; ++i) {
            delete[] gameBoard[i];
        }
        //delete []objects;
        delete[] gameBoard;
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
    int ConnectFourAbstract::readFile(string filename) {
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
    int ConnectFourAbstract::writeFile(string filename, int user, int userMod) {
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
    int ConnectFourAbstract::playGame() {
        bool flagGm=true;
        char control;
        int width,height;
        string gamemod,usermod;
        flagGm=true;
        while(flagGm){
            cinKontrol();
            if(startInputTakeSingle(usermod,width, height)) {
                setHeight(height);
                setWidth(width);
                setUserMod(usermod);
                setObject(getWidth(),getHeight());
            }
            if(getUserMod()=="C")
                SingleC();
            if(getUserMod()=="P")
                SingleP();
            if(isGameEnded()==true){
                cout<<"Game is Ended"<<endl;
                flagGm=false;
            }
        }
        return 1;
    }

}

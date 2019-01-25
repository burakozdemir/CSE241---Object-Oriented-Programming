/**
 * Homework1_Burak_Özdemir_141044027
 ****************************************
 * Created on 30.09.2017 by Burak_Özdemir
 ****************************************
 * Bu program ConnectFour adlı bir oyunun C dilinde
 * yazılmış ufak bir simulasyonudur.Oyunun oynanısına ve
 * kurallarına internetten bakabilirsniz.
 ******************************************
 *              ==Notes==
 */
#include <iostream>
using namespace std;

/**************************Function Prototypes*****************/
int start();///Mainde oyunu baslatan fonksiyon
int userVsComp(char **board,int boardSize);///User Vs Computer Mod
int userVsUser(char **board,int boardSize);////User Vs User Mod

int charToInt(char value);///Girileni int deger dondurur
void printBoard(char **board,int size);///Tabloyu ekrana basar
void playGame(int size,int mode);///Tablonun olusumu ve içinin doldurulması
int checkWin(char **board,int size,int player);///Kazananın belirlenmesş
int fixBoard(char **board,int size,int player,int choice);///Hamlenin tabloya islenmesi
int isBoardEmpty(char **board,int size);///Tablonun dolu olup olmaması
int isCellEmpty(char **board,int choice,int size);///Hucrein dolu olup olmaması kontrolu
int control8Way(char **board,int size, char user,int coord1,int coord2);///CheckWin fonksiyonu ıcın 8 yonu kontrol eder
int iscolumnEmpty(char **board,int choice);///Sutunun dolulugunu kontrol eder

///-------------Computer Hareket Kismi------------
int computer(char **board,int boardsize);///USER Computer modu için Computer FOnksıyonu
int kontrolComputer(char **board,int boardsize,int *coord2);///Computer tas gruplarının oncelık sırasına gore davranır
int kontrol3tas(char **board,int boardsize,int *targetCoord2);///3lü tas grubu belırler
int kontrol2tas(char **board,int boardsize,int *targetCoord2);///2li tas grubu belırler
int kontrol1tas(char **board,int boardsize,int *targetCoord2);///1li tas grubu belırler
int engelleme2(char **board,int boardsize);////userin 3 tasi kznmk icin dzlyse ona krsi hmle yptrir
int engelleme(char **board,int boardsize);///userin 3 tasi kznmk icin dzlyse ona krsi hmle yptrir
int engelleme3(char **board,int boardsize);///sinirda 2li tas engelliyo
int firstMove(char **board, int boardsize);///Computerın ilk hareketi
///*******************************End Of Prototypes**********************************
int main() {
    start();
    return 0;
}
int start(){
    int boardSize;
    bool flag,flag2,flag3;
    char choice;
    char control;

    while(flag) {
        flag= true,flag2=true,flag3=true;
        cout << "Welcome to ConnectFour" << endl;
        while(flag2) {
            cout << "Please enter the size of the board :";
            cin >> boardSize;
            if(!cin.fail()){
                if(boardSize>=4 && boardSize<=20)
                    flag2= false;
                else
                    cout<<"Wrong boardsize value"<<endl;
            }
            cin.clear();
            cin.ignore(10, '\n');
            cout<<endl;
        }
        while(flag3){
            cout << "If you want (User vs User) mode , press to 'P'" << endl;//mode 0
            cout << "If you want (User vs Computer) mode , press to 'C'" << endl;//mode 1
            cout << "Your choice:";
            cin >> choice;
            if (choice == 'P') {
                playGame(boardSize,0);
                flag3=false;
            }
            else if(choice == 'C'){
                playGame(boardSize,1);
                flag3= false;
            }
            else
                cout<<"Wrong Choice ! . Please enter the mode again ."<<endl;
        }
        cout<<"Do you want to exit ? Press to 'e' or press to 'n' :";
        cin>>control;
        if(control == 'e')
            flag= false;
    }
    return 1;
}
int charToInt(char value){
    int result;
    if((int)value>96 && (int)value<123 ){
        result=(int)value-96;
        return result;
    }
    if((int)value>64 && (int)value<91){
        result=(int)value-64;
        return result;
    }
}

void playGame(int boardsize,int mode){
    char **board;

//boarda alan acma
    board = (char **) malloc(boardsize * sizeof(char*) );
    for(int i=0;i<boardsize;i++){
        board[i]=(char*)malloc(boardsize*sizeof(char));
    }

//board un doldurulması
    for(int i=0;i<boardsize;i++){
        for(int k=0;k<boardsize;k++){
            board[i][k]='.';
        }
    }

    if(mode==1)
        userVsComp(board,boardsize);
    else
        userVsUser(board,boardsize);


//board un free edilmesi
    for(int i=0;i<boardsize;i++){
        free(board[i]);
    }
    free(board);

}
int checkWin(char **board,int size,int player){
    if(player==1){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(board[i][j]=='X'){
                    if(control8Way(board,size,'X',i,j)) {
                        return 1;
                    }
                }
            }
        }
    }
    if(player==2){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(board[i][j]=='O'){
                    if(control8Way(board,size,'O',i,j)){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int control8Way(char **board,int size , char user,int coord1,int coord2){
    //ust dıkey
    if(coord1-1>=0 && board[coord1-1][coord2]==user ){
        if(coord1-2>=0 && board[coord1-2][coord2]==user){
            if(coord1-3>=0 && board[coord1-3][coord2]==user){
                return 1;
            }
        }
    }
    //ust sag kose
    if(coord1-1>=0 && coord2+1<size && board[coord1-1][coord2+1]==user ){
        if(coord1-2>=0 && coord2+2<size && board[coord1-2][coord2+2]==user){
            if(coord1-3>=0 && coord2+3<size && board[coord1-3][coord2+3]==user){
                return 1;
            }
        }
    }
    //sag yatay
    if(coord2+1<size && board[coord1][coord2+1]==user ){
        if(coord2+2<size && board[coord1][coord2+2]==user){
            if(coord2+3<size && board[coord1][coord2+3]==user){
                return 1;
            }
        }
    }
    //alt sag kose
    if(coord1+1<size && coord2+1<size && board[coord1+1][coord2+1]==user ){
        if(coord1+2<size && coord2+2<size && board[coord1+2][coord2+2]==user){
            if(coord1+3<size && coord2+3<size && board[coord1+3][coord2+3]==user){
                return 1;
            }
        }
    }
    //alt dikey
    if(coord1+1<size && board[coord1+1][coord2]==user ){
        if(coord1+2<size && board[coord1+2][coord2]==user){
            if(coord1+3<size && board[coord1+3][coord2]==user){
                return 1;
            }
        }
    }
    //sol alt kose
    if(coord1+1<size && coord2-1>=0 && board[coord1+1][coord2-1]==user ){
        if(coord1+2<size && coord2-2>=0 && board[coord1+2][coord2-2]==user){
            if(coord1+3<size && coord2-3>=0 && board[coord1+3][coord2-3]==user){
                return 1;
            }
        }
    }
    //sol yatay
    if(coord2-1>=0 && board[coord1][coord2-1]==user ){
        if(coord2-2>=0 && board[coord1][coord2-2]==user){
            if(coord2-3>=0 && board[coord1][coord2-3]==user){
                return 1;
            }
        }
    }
    //sol ust kose
    if(coord1-1>=0 && coord2-1>=0 && board[coord1-1][coord2-1]==user ){
        if(coord1-2>=0 && coord2-2>=0 && board[coord1-2][coord2-2]==user){
            if(coord1-3>=0 && coord2-3>=0 && board[coord1-3][coord2-3]==user){
                return 1;
            }
        }
    }
    return 0;
}
int isCellEmpty(char **board,int choice,int size){
    for(int i=size-1;i>=0;i--){
        if(board[i][choice-1]=='.')
            return i;
    }
    return -1;
}
int fixBoard(char **board,int size,int player,int choice){
    int row=isCellEmpty(board,choice,size);//row indis turunden choice ise user secımı turunden
    if(row==-1)
        cout<<"Full Colums";
    else {
        if (player == 1) {
            board[row][choice-1]='X';
        }
        if(player == 2){
            board[row][choice-1]='O';
        }
    }
    return 1;
}
int isBoardEmpty(char **board,int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(board[i][j]=='.')
                return 1;
        }
    }
    return 0;
}
int iscolumnEmpty(char **board,int choice){
    if(board[0][choice-1]=='.')
        return 1;
    else
        return 0;
}
//User1 : 'X' (1) , User2 : 'O' (2)
int userVsUser(char **board,int boardSize){
    int winControl=0;//oyunun kazanılıp kazanılmamamsı
    int sira=1;//sıranın hangi oyuncuda oldgu
    int user;
    int choice;//userların hangi konumu sectgi
    char choiceChar;
    int flag,flag2=true;
    cout<<"User1 : 'X' , User2 : 'O'"<<endl;
    cout<<"First start User1 !!"<<endl;
    while(!winControl && flag2){
        flag=1;
        printBoard(board,boardSize);
        if(sira%2==1){
            cout<<"User1:";
            while(flag){
                cin>>choiceChar;
                choice=charToInt(choiceChar);
                if(choice>=1 && choice<=boardSize )
                    flag=0;
                else
                    cout<<"Wrong Choice! Please try again ."<<endl;
            }
            user=1;
        }
        else{
            cout<<"User2:";
            while(flag){
                cin>>choiceChar;
                choice=charToInt(choiceChar);
                if(choice>=1 && choice<=boardSize)
                    flag=0;
                else
                    cout<<"Wrong Choice! Please try again ."<<endl;
            }
            user=2;
        }
        cout<<endl;
        if(isBoardEmpty(board,boardSize))
            if(iscolumnEmpty(board,choice)){
                fixBoard(board, boardSize, user, choice);
            }
            else{
                sira--;
                cout<<"Column is full . Please try again !"<<endl;
            }
        else{
            cout<<"Board is FULL , Game finished , None is winner !";
            flag2=false;
        }
        if(checkWin(board,boardSize,user)){
            printBoard(board,boardSize);
            cout<<"User";
            cout<<user;
            if(user==1)
                cout<<" (X)";
            else
                cout<<" (O)";
            cout<<" Win !!!"<<endl;
            winControl=1;
        }
        sira++;
    }
    return 1;
}
//User1 : 'X' (1) , Computer : 'O' (2)
int userVsComp(char **board,int boardSize){
    int winControl=0;//oyunun kazanılıp kazanılmamamsı
    int sira=1;//sıranın hangi oyuncuda oldgu
    int user;
    int choice;//userların hangi konumu sectgi
    int flag,flag2=true;
    char choiceChar;
    cout<<"User1 : 'X' , Computer : 'O'"<<endl;
    cout<<"First start User1 !!"<<endl;
    while(!winControl && flag2){
        flag=1;
        printBoard(board,boardSize);
        if(sira%2==1){
            cout<<"User1:";
            while(flag){
                cin>>choiceChar;
                choice=charToInt(choiceChar);
                if(choice>=1 && choice<=boardSize)
                    flag=0;
                else
                    cout<<"Wrong Choice! Please try again ."<<endl;
            }
            user=1;
        }
        else{
            user=2;
            choice=computer(board,boardSize);
        }
        cout<<endl;
        if(isBoardEmpty(board,boardSize)) {
            if(iscolumnEmpty(board,choice)){
                fixBoard(board, boardSize, user, choice);
            }
            else {
                sira--;
                cout << "Column is full . Please try again !" << endl;
            }
        }
        else{
            cout<<"Board is FULL , Game finished , None is winner !";
            flag2=false;
        }
        if(checkWin(board,boardSize,user)){
            if(user==1) {
                printBoard(board, boardSize);
                cout << "User1 Win !!!";
            }
        else{
            printBoard(board,boardSize);
            cout<<"Computer Win !!!"<<endl;}

        winControl=1;
        }
        sira++;
    }
}
int computer(char **board,int boardsize){
    int choiceCoord2;
    int choice=(-1);
    switch (kontrolComputer(board,boardsize,&choiceCoord2)){
        case 0: choice=engelleme(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice=engelleme2(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice=engelleme3(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice= firstMove(board, boardsize);break;
        case 1: choice=engelleme(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice=engelleme2(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice=engelleme3(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice= (choiceCoord2);break;
        case 2: choice=engelleme(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice=engelleme2(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice=engelleme3(board,boardsize);
                if(choice!=-1)
                    return (choice+1);
                choice= (choiceCoord2);break;
        case 3: choice= (choiceCoord2);break;
        default:return -1;
    }
    cout<<endl;
    cout<<"Choice of Computer:"<<(char)(choice+97)<<endl;
    return choice+1;
}
//FOnksiyon ustten kontrol etmeye basliyor . oynana bilcek tas grubu varsa o kordinatlari pointer degiskene atar.
int kontrolComputer(char **board,int boardsize,int *coord2){
    if(kontrol3tas(board,boardsize,coord2))
        return 3;
    else if(kontrol2tas(board,boardsize,coord2))
        return 2;
    else if(kontrol1tas(board,boardsize,coord2))
        return 1;
    return 0;
}
int kontrol3tas(char **board,int boardsize,int *targetCoord2){
    for (int i = 0; i <boardsize ; ++i) {
        for (int j = 0; j <boardsize ; ++j) {
            if(board[i][j]=='O'){
                //yukari yon
                if(i-1>=0 && board[i-1][j]=='O' ){
                    if(i-2>=0 && board[i-2][j]=='O'){
                        if(i-3>=0 && board[i-3][j]=='.'){
                            *targetCoord2=(j);
                            return 1;
                        }
                    }
                }
                //yukari sag yon
                if(i-1>=0 && j+1<boardsize && board[i-1][j+1]=='O' ){
                    if(i-2>=0 && j+2<boardsize && board[i-2][j+2]=='O'){
                        if(i-3>=0 && j+3<boardsize && board[i-3][j+3]=='.' && board[i-2][j+3]!='.'){
                            *targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //yukari sag yon 2
                if(i-1>=0 && j+1<boardsize && board[i-1][j+1]=='O' ){
                    if(i-3>=0 && j+3<boardsize && board[i-3][j+3]=='O'){
                        if(board[i-2][j+2]=='.' && board[i-1][j+2]!='.'){
                            *targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag yon
                if(j+1<boardsize && board[i][j+1]=='O' ){
                    if(j+2<boardsize && board[i][j+2]=='O'){
                        if(j+3<boardsize && board[i][j+3]=='.' && i+1<boardsize &&
                           board[i+1][j+3]!='.'){
                            *targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag yon 2
                if(j+1<boardsize && board[i][j+1]=='O' ){
                    if(j+3<boardsize && board[i][j+3]=='O'){
                        if(board[i][j+2]=='.' && i+1<boardsize && board[i+1][j+2]!='.'){
                            *targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag yon sinir
                if(j+1<boardsize && board[i][j+1]=='O' ){
                    if(j+2<boardsize && board[i][j+2]=='O'){
                        if(j+3<boardsize && board[i][j+3]=='.' && (boardsize-i)==1){
                            *targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag yon sinir 2
                if(j+1<boardsize && board[i][j+1]=='O' ){
                    if(j+3<boardsize && board[i][j+3]=='O'){
                        if(board[i][j+2]=='.' && (boardsize-i)==1){
                            *targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sag alt yon
                if(i+1<boardsize && j+1<boardsize && board[i+1][j+1]=='O' ){
                    if(i+2<boardsize && j+2<boardsize && board[i+2][j+2]=='O'){
                        if(i+3<boardsize && j+3<boardsize && board[i+3][j+3]=='.' && i+4<boardsize &&
                           board[i+4][j+3]!='.'){
                            *targetCoord2=(j+3);
                            return 1;
                        }
                    }
                }
                //sag alt yon 2
                if(i+1<boardsize && j+1<boardsize && board[i+1][j+1]=='O' ){
                    if(i+3<boardsize && j+3<boardsize && board[i+3][j+3]=='O'){
                        if(board[i+2][j+2]=='.' && board[i+3][j+2]!='.'){
                            *targetCoord2=(j+2);
                            return 1;
                        }
                    }
                }
                //sol alt yon
                if(i+1<boardsize && j-1>=0 && board[i+1][j-1]=='O' ){
                    if(i+2<boardsize && j-2>=0 && board[i+2][j-2]=='O'){
                        if(i+3<boardsize && j-3>=0 && board[i+3][j-3]=='.' && i+4<boardsize &&
                           board[i+4][j-3]!='.'){
                            *targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol alt yon 2
                if(i+1<boardsize && j-1>=0 && board[i+1][j-1]=='O' ){
                    if(i+3<boardsize && j-3>=0 && board[i+3][j-3]=='O'){
                        if(board[i+2][j-2]=='.' && board[i+3][j-2]!='.'){
                            *targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol yon
                if(j-1>=0 && board[i][j-1]=='O' ){
                    if(j-2>=0 && board[i][j-2]=='O'){
                        if(j-3>=0 && board[i][j-3]=='.' && i+1<boardsize &&
                           board[i+1][j-3]!='.'){
                            *targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol yon 2
                if(j-1>=0 && board[i][j-1]=='O' ){
                    if(j-3>=0 && board[i][j-3]=='O'){
                        if(board[i][j-2]=='.' && i+1<boardsize && board[i+1][j-2]!='.'){
                            *targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol yon sinir
                if(j-1>=0 && board[i][j-1]=='O' ){
                    if(j-2>=0 && board[i][j-2]=='O'){
                        if(j-3>=0 && board[i][j-3]=='.' && (boardsize-i)==1){
                            *targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                // sol yon sinir 2
                if(j-1>=0 && board[i][j-1]=='O' ){
                    if(j-3>=0 && board[i][j-3]=='O'){
                        if(board[i][j-2]=='.' && (boardsize-i)==1){
                            *targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]=='O' ){
                    if(i-2>=0 && j-2>=0 && board[i-2][j-2]=='O'){
                        if(i-3>=0 && j-3>=0 && board[i-3][j-3]=='.' && board[i-2][j-3]!='.'){
                            *targetCoord2=(j-3);
                            return 1;
                        }
                    }
                }
                //sol ust yon 2
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]=='O' ){
                    if(i-3>=0 && j-3>=0 && board[i-3][j-3]=='O'){
                        if(board[i-2][j-2]=='.' && board[i-1][j-2]!='.'){
                            *targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
int kontrol2tas(char **board,int boardsize,int *targetCoord2){
    for (int i = 0; i <boardsize ; ++i) {
        for (int j = 0; j <boardsize ; ++j) {
            if(board[i][j]=='O'){
                //yukari yon
                if(i-1>=0 && board[i-1][j]=='O' ){
                    if(i-2>=0 && board[i-2][j]=='.'){
                        *targetCoord2=(j);
                        return 1;
                    }
                }
                //sag yukarı yon
                if(i-1>=0 && j+1<boardsize && board[i-1][j+1]=='O' ){
                    if(i-2>=0 && j+2<boardsize && board[i-2][j+2]=='.' && board[i-1][j+2]!='.'){
                        *targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag yon
                if(j+1<boardsize && board[i][j+1]=='O' ){
                    if(j+2<boardsize && board[i][j+2]=='.' && i+1<boardsize && board[i+1][j+2]!='.'){
                        *targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag yon (sinir)
                if(j+1<boardsize && board[i][j+1]=='O' ){
                    if(j+2<boardsize && board[i][j+2]=='.' && (boardsize-i)==1){
                        *targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sag asagı yon
                if(i+1<boardsize && j+1<boardsize && board[i+1][j+1]=='O' ){
                    if(i+2<boardsize && j+2<boardsize && board[i+2][j+2]=='.' && i+3<boardsize &&
                       board[i+3][j+2]!='.'){
                        *targetCoord2=(j+2);
                        return 1;
                    }
                }
                //sol asagı yon
                if(i+1<boardsize && j-1>=0 && board[i+1][j-1]=='O' ){
                    if(i+2<boardsize && j-2>=0 && board[i+2][j-2]=='.' && i+3<boardsize &&
                       board[i+3][j-2]!='.'){
                        *targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol yon
                if(j-1>=0 && board[i][j-1]=='O' ){
                    if(j-2>=0 && board[i][j-2]=='.' && i+1<boardsize && board[i+1][j-2]!='.'){
                        *targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol yon sinir
                if(j-1>=0 && board[i][j-1]=='O' ){
                    if(j-2>=0 && board[i][j-2]=='.' && (boardsize-i)==1){
                        *targetCoord2=(j-2);
                        return 1;
                    }
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]=='O' ){
                    if(i-2>=0 && j-2>=0 && board[i-2][j-2]=='.' && board[i-1][j-2]!='.'){
                        *targetCoord2=(j-2);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int kontrol1tas(char **board,int boardsize,int *targetCoord2){
    for (int i = 0; i <boardsize ; ++i) {
        for (int j = 0; j < boardsize; ++j) {
            if(board[i][j]=='O'){
                //yukari yon
                if(i-1>=0 && board[i-1][j]=='.' ){
                    *targetCoord2=j;
                    return 1;
                }
                //yukari sag yon
                if(i-1>=0 && j+1<boardsize && board[i-1][j+1]=='.' && i<boardsize
                   && board[i][j+1]!='.' ){
                    *targetCoord2=(j+1);
                    return 1;
                }
                //sag yon
                if(j+1<boardsize && board[i][j+1]=='.' && i+1<boardsize && board[i+1][j+1]!='.' ){
                    *targetCoord2=(j+1);
                    return 1;
                }
                //sag yon(sinir)
                if(j+1<boardsize && board[i][j+1]=='.' && (boardsize-i)==1 ){
                    *targetCoord2=(j+1);
                    return 1;
                }

                //sag alt yon
                if(i+1<boardsize && j+1<boardsize && board[i+1][j+1]=='.' && i+2<boardsize
                   && board[i+2][j+1]!='.' ){
                    *targetCoord2=(j+1);
                    return 1;
                }
                //sol alt yon
                if(i+1<boardsize && j-1>=0 && board[i+1][j-1]=='.' && i+2<boardsize
                   && board[i+2][j-1]!='.' ){
                    *targetCoord2=(j-1);
                    return 1;
                }
                //sol yon
                if(j-1>=0 && board[i][j-1]=='.' && i+1<boardsize && board[i+1][j-1]!='.' ){
                    *targetCoord2=(j-1);
                    return 1;
                }
                //sol yon sinir
                if(j-1>=0 && board[i][j-1]=='.' && (boardsize-i)==1){
                    *targetCoord2=(j-1);
                    return 1;
                }
                //sol ust yon
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]=='.' && i<boardsize
                   && board[i][j-1]!='.' ){
                    *targetCoord2=(j-1);
                    return 1;
                }
            }
        }
    }
    return 0;
}
///Userın taslarını engellemek ıcın yazılmıs fonksıyonlar
int engelleme(char **board,int boardsize){
    for (int i = 0; i < boardsize; ++i) {
        for (int j = 0; j < boardsize; ++j) {
            if(board[i][j]=='X'){
                //yukari yon
                if(i-1>=0 && board[i-1][j]=='X' ){
                    if(i-2>=0 && board[i-2][j]=='X'){
                        if(i-3>=0 && board[i-3][j]=='.')
                            return j;
                    }
                }
                //yukari sag yon
                if(i-1>=0 && j+1<boardsize && board[i-1][j+1]=='X' ){
                    if(i-2>=0 && j+2<boardsize && board[i-2][j+2]=='X'){
                        if(i-3>=0 && j+3<boardsize && board[i-3][j+3]=='.' && board[i-2][j+3]!='.' )
                            return (j+3);
                    }
                }
                //sag yon
                if(j+1<boardsize && board[i][j+1]=='X' ){
                    if(j+2<boardsize && board[i][j+2]=='X'){
                        if(j+3<boardsize && board[i][j+3]=='.' && i+1<boardsize && board[i+1][j+3]!='.')
                            return (j+3);
                    }
                }
                //sag yon sinir
                if(j+1<boardsize && board[i][j+1]=='X' ){
                    if(j+2<boardsize && board[i][j+2]=='X'){
                        if(j+3<boardsize && board[i][j+3]=='.' && (boardsize-i)==1 )
                            return (j+3);
                    }
                }
                //sag alt yon
                if(i+1<boardsize && j+1<boardsize && board[i+1][j+1]=='X' ){
                    if(i+2<boardsize && j+2<boardsize && board[i+2][j+2]=='X'){
                        if(i+3<boardsize && j+3<boardsize && board[i+3][j+3]=='.' && i+4<boardsize &&
                                board[i+4][j+3]!='.' )
                            return (j+3);
                    }
                }
                //sag alt yon 2
                if(i+1<boardsize && j+1<boardsize && board[i+1][j+1]=='X' ){
                    if(i+2<boardsize && j+2<boardsize && board[i+2][j+2]=='X'){
                        if(i+3==boardsize-1 && j+3<boardsize && board[i+3][j+3]=='.' )
                            return (j+3);
                    }
                }
                //sol alt yon
                if(i+1<boardsize && j-1>=0 && board[i+1][j-1]=='X' ){
                    if(i+2<boardsize && j-2>=0 && board[i+2][j-2]=='X'){
                        if(i+3<boardsize && j-3>=0 && board[i+3][j-3]=='.' && i+4<boardsize &&  board[i+4][j-3]!='.' )
                            return (j-3);
                    }
                }
                //sol alt yon2
                if(i+1<boardsize && j-1>=0 && board[i+1][j-1]=='X' ){
                    if(i+2<boardsize && j-2>=0 && board[i+2][j-2]=='X'){
                        if(i+3==boardsize-1 && j-3>=0 && board[i+3][j-3]=='.')
                            return (j-3);
                    }
                }
                //sol yon
                if(j-1>=0 && board[i][j-1]=='X' ){
                    if(j-2>=0 && board[i][j-2]=='X'){
                        if(j-3>=0 && board[i][j-3]=='.' && i+1<boardsize && board[i+1][j-3]!='.')
                            return (j-3);
                    }
                }
                //sol yon sinir
                if(j-1>=0 && board[i][j-1]=='X' ){
                    if(j-2>=0 && board[i][j-2]=='X'){
                        if(j-3>=0 && board[i][j-3]=='.' && (boardsize-i)==1)
                            return (j-3);
                    }
                }
                //yukarı sol yon
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]=='X' ){
                    if(i-2>=0 && j-2>=0 && board[i-2][j-2]=='X'){
                        if(i-3>=0 && j-3>=0 && board[i-3][j-3]=='.' && board[i-2][j-3]!='.' )
                            return (j-3);
                    }
                }
            }
        }
    }
    return -1;
}
int engelleme2(char **board,int boardsize) {
    for (int i = 0; i < boardsize; ++i) {
        for (int j = 0; j < boardsize; ++j) {
            if (board[i][j] == 'X') {
                //yukari sag yon
                if (i - 1 >= 0 && j + 1 < boardsize && board[i - 1][j + 1] == 'X') {
                    if (i - 3 >= 0 && j + 3 < boardsize && board[i - 3][j + 3] == 'X') {
                        if (board[i - 2][j + 2] == '.' && board[i - 1][j + 2] != '.')
                            return (j + 2);

                    }
                }
                //sag yon
                if (j + 1 < boardsize && board[i][j + 1] == 'X') {
                    if (j + 3 < boardsize && board[i][j + 3] == 'X') {
                        if (board[i][j + 2] == '.' && i + 1 < boardsize && board[i + 1][j + 2] != '.')
                            return (j + 2);
                    }
                }
                //sag yon sinir
                if (j + 1 < boardsize && board[i][j + 1] == 'X') {
                    if (j + 3 < boardsize && board[i][j + 3] == 'X') {
                        if (board[i][j + 2] == '.' && (boardsize - i == 1))
                            return (j + 2);
                    }
                }
                //sag alt yon
                if (i + 1 < boardsize && j + 1 < boardsize && board[i + 1][j + 1] == 'X') {
                    if (i + 3 < boardsize && j + 3 < boardsize && board[i + 3][j + 3] == 'X') {
                        if (board[i + 2][j + 2] == '.' && i + 4 < boardsize && board[i + 4][j + 2] != '.')
                            return (j + 2);
                    }
                }
                //sag alt yon 2
                if (i + 1 < boardsize && j + 1 < boardsize && board[i + 1][j + 1] == 'X') {
                    if (i + 3 == boardsize -1 && j + 3 < boardsize && board[i + 3][j + 3] == 'X') {
                        if (board[i + 2][j + 2] == '.' )
                            return (j + 2);
                    }
                }
                //sol alt yon
                if (i + 1 < boardsize && j - 1 >= 0 && board[i + 1][j - 1] == 'X') {
                    if (i + 3 < boardsize && j - 3 >= 0 && board[i + 3][j - 3] == 'X') {
                        if (board[i + 2][j - 2] == '.' && i + 4 < boardsize && board[i + 4][j - 2] != '.')
                            return (j - 2);
                    }
                }
                //sol alt yon 2
                if (i + 1 < boardsize && j - 1 >= 0 && board[i + 1][j - 1] == 'X') {
                    if (i + 3 == boardsize-1 && j - 3 >= 0 && board[i + 3][j - 3] == 'X') {
                        if (board[i + 2][j - 2] == '.' && i + 4 < boardsize)
                            return (j - 2);
                    }
                }
                //sol yon
                if (j - 1 >= 0 && board[i][j - 1] == 'X') {
                    if (j - 3 >= 0 && board[i][j - 3] == 'X') {
                        if (board[i][j - 2] == '.' && i + 1 < boardsize && board[i + 1][j - 2] != '.')
                            return (j - 2);
                    }
                }
                //sol yon sinir
                if (j - 1 >= 0 && board[i][j - 1] == 'X') {
                    if (j - 3 >= 0 && board[i][j - 3] == 'X') {
                        if (board[i][j - 2] == '.' && (boardsize - i) == 1)
                            return (j - 2);
                    }
                }
                //yukarı sol yon
                if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 'X') {
                    if (i - 3 >= 0 && j - 3 >= 0 && board[i - 3][j - 3] == 'X') {
                        if (board[i - 2][j - 2] == '.' && board[i - 1][j - 2] != '.')
                            return (j - 2);
                    }
                }
            }
        }
    }
    return -1;
}
int engelleme3(char **board,int boardsize){
    for (int i = 0; i < boardsize; ++i) {
        for (int j = 0; j < boardsize; ++j) {
            if(boardsize-i==1 &&  board[i][j]=='X'){
                //sag sinir
                if(j+1<boardsize && board[i][j+1]=='X'){
                    if(j+2<boardsize && board[i][j+2]=='.')
                        return j+2;
                }
                //sol sinir
                if(j-1>=0 && board[i][j-1]=='X'){
                    if(j-2>=0 && board[i][j-2]=='.')
                        return j-2;
                }
            }
        }
    }
    return -1;
}
int firstMove(char **board, int boardsize){
    for (int i = 0; i < boardsize; ++i) {
        for (int j = 0; j < boardsize; ++j) {
            if(board[i][j]=='X'){
                //sol yon
                if( (boardsize-i==1) && j-1>=0 && board[i][j-1]=='.' ){
                    return (j-1);
                }
                //sag yon
                if( (boardsize-i==1) && j+1<boardsize && board[i][j+1]=='.' ){
                    return (j+1);
                }
            }
        }
    }
}
void printBoard(char **board,int size){
    for(int i=0;i<size;i++){
        cout << (char)(i+97) << " " ;
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        for(int k=0;k<size;k++){
            cout<<board[i][k];
            cout<<" ";
        }
        cout<<endl;
    }
}

package connectfour;

public class komputer  {
    public static Connectfour.Tile gameCells[][];
    public static Directions checkWin(int user) {
        Directions dir;
        if(user==1){
            for (int i = 0; i < gameCells.length; ++i) {
                for (int j = 0; j < gameCells[i].length; ++j) {
                    if(gameCells[i][j].getValue().equals("X")){
                        if((dir = control8Way("X", i, j)) != Directions.NONE) {
                            return dir;
                        }
                    }
                }
            }
            return Directions.USER1NONE;
        }
        if(user==2){
            for (int i = 0; i < gameCells.length; ++i) {
                for (int j = 0; j < gameCells[i].length; ++j) {
                    if(gameCells[i][j].getValue().equals("O")){
                        if((dir = control8Way("O",i,j) ) != Directions.NONE){
                            return dir;
                        }
                    }
                }
            }
            return Directions.USER2NONE;
        }
        return Directions.NONE;
    }
    public static Directions control8Way(String user, int coord1, int coord2) {
        //ust dıkey
        if(coord1-1>=0 && gameCells[coord1-1][coord2].getValue().equals(user) ){
            if(coord1-2>=0 && gameCells[coord1-2][coord2].getValue().equals(user)){
                if(coord1-3>=0 && gameCells[coord1-3][coord2].getValue().equals(user)){
                    return Directions.USTDIKEY;
                }
            }
        }
        //ust sag kose
        if(coord1-1>=0 && coord2+1<gameCells.length && gameCells[coord1-1][coord2+1].getValue().equals(user) ){
            if(coord1-2>=0 && coord2+2<gameCells.length && gameCells[coord1-2][coord2+2].getValue().equals(user)){
                if(coord1-3>=0 && coord2+3<gameCells.length && gameCells[coord1-3][coord2+3].getValue().equals(user)){
                    return Directions.USTSAGKOSE;
                }
            }
        }
        //sag yatay
        if(coord2+1<gameCells.length && gameCells[coord1][coord2+1].getValue().equals(user) ){
            if(coord2+2<gameCells.length && gameCells[coord1][coord2+2].getValue().equals(user)){
                if(coord2+3<gameCells.length && gameCells[coord1][coord2+3].getValue().equals(user)){
                    return Directions.SAGYTATAY;
                }
            }
        }
        //alt sag kose
        if(coord1+1<gameCells.length && coord2+1<gameCells.length && gameCells[coord1+1][coord2+1].getValue().equals(user) ){
            if(coord1+2<gameCells.length && coord2+2<gameCells.length && gameCells[coord1+2][coord2+2].getValue().equals(user)){
                if(coord1+3<gameCells.length && coord2+3<gameCells.length && gameCells[coord1+3][coord2+3].getValue().equals(user)){
                    return Directions.ALTSAGKOSE;
                }
            }
        }
        //alt dikey
        if(coord1+1<gameCells.length && gameCells[coord1+1][coord2].getValue().equals(user) ){
            if(coord1+2<gameCells.length && gameCells[coord1+2][coord2].getValue().equals(user)){
                if(coord1+3<gameCells.length && gameCells[coord1+3][coord2].getValue().equals(user)){
                    return Directions.ALTDIKEY;
                }
            }
        }
        //sol alt kose
        if(coord1+1<gameCells.length && coord2-1>=0 && gameCells[coord1+1][coord2-1].getValue().equals(user) ){
            if(coord1+2<gameCells.length && coord2-2>=0 && gameCells[coord1+2][coord2-2].getValue().equals(user)){
                if(coord1+3<gameCells.length && coord2-3>=0 && gameCells[coord1+3][coord2-3].getValue().equals(user)){
                    return Directions.SOLALTKOSE;
                }
            }
        }
        //sol yatay
        if(coord2-1>=0 && gameCells[coord1][coord2-1].getValue().equals(user) ){
            if(coord2-2>=0 && gameCells[coord1][coord2-2].getValue().equals(user)){
                if(coord2-3>=0 && gameCells[coord1][coord2-3].getValue().equals(user)){
                    return Directions.SOLYATAY;
                }
            }
        }
        //sol ust kose
        if(coord1-1>=0 && coord2-1>=0 && gameCells[coord1-1][coord2-1].getValue().equals(user) ){
            if(coord1-2>=0 && coord2-2>=0 && gameCells[coord1-2][coord2-2].getValue().equals(user)){
                if(coord1-3>=0 && coord2-3>=0 && gameCells[coord1-3][coord2-3].getValue().equals(user)){
                    return Directions.SOLUSTKOSE;
                }
            }
        }

        return Directions.NONE;
    }
    public static int kontrol(){
        int choiceCoord2=0;
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
    public static int kontrolComputer(int coord2) {
        if(kontrol3tas(coord2)==1)
            return 3;
        else if(kontrol2tas(coord2)==1)
            return 2;
        else if(kontrol1tas(coord2)==1)
            return 1;
        return 0;
    }

    public static int kontrol3tas(int targetCoord2) {
        for (int i = 0; i <gameCells.length ; ++i) {
            for (int j = 0; j <gameCells[i].length ; ++j) {
                if(gameCells[i][j].getValue().equals("O")){
                    //yukari yon
                    if(i-1>=0 && gameCells[i-1][j].getValue().equals("O") ){
                        if(i-2>=0 && gameCells[i-2][j].getValue().equals("O")){
                            if(i-3>=0 && gameCells[i-3][j].getValue().equals("")){
                                targetCoord2=(j);
                                return 1;
                            }
                        }
                    }
                    //yukari sag yon
                    if(i-1>=0 && j+1<gameCells[i].length && gameCells[i-1][j+1].getValue().equals("O") ){
                        if(i-2>=0 && j+2<gameCells[i].length && gameCells[i-2][j+2].getValue().equals("O")){
                            if(i-3>=0 && j+3<gameCells[i].length && gameCells[i-3][j+3].getValue().equals("") &&
                                    !gameCells[i-2][j+3].getValue().equals("")){
                                targetCoord2=(j+3);
                                return 1;
                            }
                        }
                    }
                    //yukari sag yon 2
                    if(i-1>=0 && j+1<gameCells[i].length && gameCells[i-1][j+1].getValue().equals("O") ){
                        if(i-3>=0 && j+3<gameCells[i].length && gameCells[i-3][j+3].getValue().equals("O")){
                            if(gameCells[i-2][j+2].getValue().equals("") && !gameCells[i-1][j+2].getValue().equals("")){
                                targetCoord2=(j+2);
                                return 1;
                            }
                        }
                    }
                    //sag yon
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("O") ){
                        if(j+2<gameCells[i].length && gameCells[i][j+2].getValue().equals("O")){
                            if(j+3<gameCells[i].length && gameCells[i][j+3].getValue().equals("") && i+1<gameCells.length &&
                                    !gameCells[i+1][j+3].getValue().equals("")){
                                targetCoord2=(j+3);
                                return 1;
                            }
                        }
                    }
                    //sag yon 2
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("O") ){
                        if(j+3<gameCells[i].length && gameCells[i][j+3].getValue().equals("O")){
                            if(gameCells[i][j+2].getValue().equals("") && i+1<gameCells.length && !gameCells[i+1][j+2].getValue().equals("")){
                                targetCoord2=(j+2);
                                return 1;
                            }
                        }
                    }
                    //sag yon sinir
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("O") ){
                        if(j+2<gameCells[i].length && gameCells[i][j+2].getValue().equals("O")){
                            if(j+3<gameCells[i].length && gameCells[i][j+3].getValue().equals("") && (gameCells.length-i)==1){
                                targetCoord2=(j+3);
                                return 1;
                            }
                        }
                    }
                    //sag yon sinir 2
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("O") ){
                        if(j+3<gameCells[i].length && gameCells[i][j+3].getValue().equals("O")){
                            if(gameCells[i][j+2].getValue().equals("") && (gameCells.length-i)==1){
                                targetCoord2=(j+2);
                                return 1;
                            }
                        }
                    }
                    //sag alt yon
                    if(i+1<gameCells.length && j+1<gameCells[i].length && gameCells[i+1][j+1].getValue().equals("O") ){
                        if(i+2<gameCells.length && j+2<gameCells[i].length && gameCells[i+2][j+2].getValue().equals("O")){
                            if(i+3<gameCells.length && j+3<gameCells[i].length && gameCells[i+3][j+3].getValue().equals("") && i+4<gameCells.length &&
                                    !gameCells[i+4][j+3].getValue().equals("")){
                                targetCoord2=(j+3);
                                return 1;
                            }
                        }
                    }
                    //sag alt yon 2
                    if(i+1<gameCells.length && j+1<gameCells[i].length && gameCells[i+1][j+1].getValue().equals("O")){
                        if(i+3<gameCells.length && j+3<gameCells[i].length && gameCells[i+3][j+3].getValue().equals("O")){
                            if(gameCells[i+2][j+2].getValue().equals("") && !gameCells[i+3][j+2].getValue().equals("")){
                                targetCoord2=(j+2);
                                return 1;
                            }
                        }
                    }
                    //sol alt yon
                    if(i+1<gameCells.length && j-1>=0 && gameCells[i+1][j-1].getValue().equals("O") ){
                        if(i+2<gameCells.length && j-2>=0 && gameCells[i+2][j-2].getValue().equals("O")){
                            if(i+3<gameCells.length && j-3>=0 && gameCells[i+3][j-3].getValue().equals("") && i+4<gameCells.length &&
                                    !gameCells[i+4][j-3].getValue().equals("")){
                                targetCoord2=(j-3);
                                return 1;
                            }
                        }
                    }
                    //sol alt yon 2
                    if(i+1<gameCells.length && j-1>=0 && gameCells[i+1][j-1].getValue().equals("O")){
                        if(i+3<gameCells.length && j-3>=0 && gameCells[i+3][j-3].getValue().equals("O")){
                            if(gameCells[i+2][j-2].getValue().equals("") && !gameCells[i+3][j-2].getValue().equals("")){
                                targetCoord2=(j-2);
                                return 1;
                            }
                        }
                    }
                    //sol yon
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("O")){
                        if(j-2>=0 && gameCells[i][j-2].getValue().equals("O")){
                            if(j-3>=0 && gameCells[i][j-3].getValue().equals("") && i+1<gameCells.length &&
                                    !gameCells[i+1][j-3].getValue().equals("")){
                                targetCoord2=(j-3);
                                return 1;
                            }
                        }
                    }
                    //sol yon 2
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("O")){
                        if(j-3>=0 && gameCells[i][j-3].getValue().equals("O")){
                            if(gameCells[i][j-2].getValue().equals("") && i+1<gameCells.length && !gameCells[i+1][j-2].getValue().equals("")){
                                targetCoord2=(j-2);
                                return 1;
                            }
                        }
                    }
                    //sol yon sinir
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("O")){
                        if(j-2>=0 && gameCells[i][j-2].getValue().equals("O")){
                            if(j-3>=0 && gameCells[i][j-3].getValue().equals("") && (gameCells.length-i)==1){
                                targetCoord2=(j-3);
                                return 1;
                            }
                        }
                    }
                    // sol yon sinir 2
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("O")){
                        if(j-3>=0 &&
                                gameCells[i][j-3].getValue().equals("O")){
                            if(gameCells[i][j-2].getValue().equals("") && (gameCells.length-i)==1){
                                targetCoord2=(j-2);
                                return 1;
                            }
                        }
                    }
                    //sol ust yon
                    if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getValue().equals("O")){
                        if(i-2>=0 && j-2>=0 && gameCells[i-2][j-2].getValue().equals("O")){
                            if(i-3>=0 && j-3>=0 && gameCells[i-3][j-3].getValue().equals("") && !gameCells[i-2][j-3].getValue().equals("")){
                                targetCoord2=(j-3);
                                return 1;
                            }
                        }
                    }
                    //sol ust yon 2
                    if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getValue().equals("O")){
                        if(i-3>=0 && j-3>=0 && gameCells[i-3][j-3].getValue().equals("O")){
                            if(gameCells[i-2][j-2].getValue().equals("") && !gameCells[i-1][j-2].getValue().equals("")){
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
    public static int kontrol2tas(int targetCoord2){
        for (int i = 0; i <gameCells.length ; ++i) {
            for (int j = 0; j <gameCells[i].length ; ++j) {
                if(gameCells[i][j].getValue().equals("O")){
                    //yukari yon
                    if(i-1>=0 && gameCells[i-1][j].getValue().equals("O") ){
                        if(i-2>=0 && gameCells[i-2][j].getValue().equals("")){
                            targetCoord2=(j);
                            return 1;
                        }
                    }
                    //sag yukarı yon
                    if(i-1>=0 && j+1<gameCells[i].length && gameCells[i-1][j+1].getValue().equals("O") ){
                        if(i-2>=0 && j+2<gameCells[i].length && gameCells[i-2][j+2].getValue().equals("") &&
                                !gameCells[i-1][j+2].getValue().equals("")){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                    //sag yon
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("O") ){
                        if(j+2<gameCells[i].length && gameCells[i][j+2].getValue().equals("") && i+1<gameCells.length &&
                                !gameCells[i+1][j+2].getValue().equals("")){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                    //sag yon (sinir)
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("O") ){
                        if(j+2<gameCells[i].length && gameCells[i][j+2].getValue().equals("") && (gameCells.length-i)==1){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                    //sag asagı yon
                    if(i+1<gameCells.length && j+1<gameCells[i].length && gameCells[i+1][j+1].getValue().equals("O") ){
                        if(i+2<gameCells.length && j+2<gameCells[i].length && gameCells[i+2][j+2].getValue().equals("") && i+3<gameCells.length &&
                                !gameCells[i+3][j+2].getValue().equals("")){
                            targetCoord2=(j+2);
                            return 1;
                        }
                    }
                    //sol asagı yon
                    if(i+1<gameCells.length && j-1>=0 && gameCells[i+1][j-1].getValue().equals("") ){
                        if(i+2<gameCells.length && j-2>=0 && gameCells[i+2][j-2].getValue().equals("") && i+3<gameCells.length &&
                                !gameCells[i+3][j-2].getValue().equals("")){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                    //sol yon
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("O") ){
                        if(j-2>=0 && gameCells[i][j-2].getValue().equals("") && i+1<gameCells.length && !gameCells[i+1][j-2].getValue().equals("O")){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                    //sol yon sinir
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("O") ){
                        if(j-2>=0 && gameCells[i][j-2].getValue().equals("") && (gameCells.length-i)==1){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                    //sol ust yon
                    if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getValue().equals("O") ){
                        if(i-2>=0 && j-2>=0 && gameCells[i-2][j-2].getValue().equals("") && !gameCells[i-1][j-2].getValue().equals("")){
                            targetCoord2=(j-2);
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    public static int kontrol1tas(int targetCoord2) {
        for (int i = 0; i <gameCells.length ; ++i) {
            for (int j = 0; j <gameCells[i].length; ++j) {
                if(gameCells[i][j].getValue().equals("O")){
                    //yukari yon
                    if(i-1>=0 && gameCells[i-1][j].getValue().equals("") ){
                        targetCoord2=j;
                        return 1;
                    }
                    //yukari sag yon
                    if(i-1>=0 && j+1<gameCells[i].length && gameCells[i-1][j+1].getValue().equals("") && i<gameCells.length
                            && !gameCells[i][j+1].getValue().equals("") ){
                        targetCoord2=(j+1);
                        return 1;
                    }
                    //sag yon
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("") && i+1<gameCells.length && !gameCells[i+1][j+1].getValue().equals("") ){
                        targetCoord2=(j+1);
                        return 1;
                    }
                    //sag yon(sinir)
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("") && (gameCells.length-i)==1 ){
                        targetCoord2=(j+1);
                        return 1;
                    }

                    //sag alt yon
                    if(i+1<gameCells.length && j+1<gameCells[i].length && gameCells[i+1][j+1].getValue().equals("") && i+2<gameCells.length
                            && !gameCells[i+2][j+1].getValue().equals("") ){
                        targetCoord2=(j+1);
                        return 1;
                    }
                    //sol alt yon
                    if(i+1<gameCells.length && j-1>=0 && gameCells[i+1][j-1].getValue().equals("") && i+2<gameCells.length
                            && !gameCells[i+2][j-1].getValue().equals("")){
                        targetCoord2=(j-1);
                        return 1;
                    }
                    //sol yon
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("") && i+1<gameCells.length && !gameCells[i+1][j-1].getValue().equals("") ){
                        targetCoord2=(j-1);
                        return 1;
                    }
                    //sol yon sinir
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("") && (gameCells.length-i)==1){
                        targetCoord2=(j-1);
                        return 1;
                    }
                    //sol ust yon
                    if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getValue().equals("") && i<gameCells.length
                            && !gameCells[i][j-1].getValue().equals("") ){
                        targetCoord2=(j-1);
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    public static int engelleme2() {
        for (int i = 0; i < gameCells.length; ++i) {
            for (int j = 0; j < gameCells[i].length; ++j) {
                if (gameCells[i][j].getValue().equals("X")) {
                    //yukari sag yon
                    if (i - 1 >= 0 && j + 1 < gameCells[i].length && gameCells[i - 1][j + 1].getValue().equals("X")) {
                        if (i - 3 >= 0 && j + 3 < gameCells[i].length && gameCells[i - 3][j + 3].getValue().equals("X")) {
                            if (gameCells[i - 2][j + 2].getValue().equals("") && !gameCells[i - 1][j + 2].getValue().equals(""))
                                return (j + 2);

                        }
                    }
                    //sag yon
                    if (j + 1 < gameCells[i].length && gameCells[i][j + 1].getValue().equals("X")) {
                        if (j + 3 < gameCells[i].length && gameCells[i][j + 3].getValue().equals("X")) {
                            if (gameCells[i][j + 2].getValue().equals("") && i + 1 <gameCells.length && !gameCells[i + 1][j + 2].getValue().equals(""))
                                return (j + 2);
                        }
                    }
                    //sag yon sinir
                    if (j + 1 < gameCells[i].length && gameCells[i][j + 1].getValue().equals("X")) {
                        if (j + 3 <
                                gameCells[i].length && gameCells[i][j + 3].getValue().equals("X")) {
                            if (gameCells[i][j + 2].getValue().equals("") && (gameCells.length - i == 1))
                                return (j + 2);
                        }
                    }
                    //sag alt yon
                    if (i + 1 < gameCells.length && j + 1 < gameCells[i].length && gameCells[i + 1][j + 1].getValue().equals("X")) {
                        if (i + 3 < gameCells.length && j + 3 < gameCells[i].length && gameCells[i + 3][j + 3].getValue().equals("X")) {
                            if (gameCells[i + 2][j + 2].getValue().equals("") && i + 4 < gameCells.length && !gameCells[i + 4][j + 2].getValue().equals(""))
                                return (j + 2);
                        }
                    }
                    //sag alt yon 2
                    if (i + 1 < gameCells.length && j + 1 < gameCells[i].length && gameCells[i + 1][j + 1].getValue().equals("X")) {
                        if (i + 3 == gameCells.length -1 && j + 3 < gameCells[i].length && gameCells[i + 3][j + 3].getValue().equals("X")) {
                            if (gameCells[i + 2][j + 2].getValue().equals("") )
                                return (j + 2);
                        }
                    }
                    //sol alt yon
                    if (i + 1 < gameCells.length && j - 1 >= 0 && gameCells[i + 1][j - 1].getValue().equals("X")) {
                        if (i + 3 < gameCells.length && j - 3 >= 0 && gameCells[i + 3][j - 3].getValue().equals("X")) {
                            if (!gameCells[i + 2][j - 2].getValue().equals("") && i + 4 < gameCells.length && !gameCells[i + 4][j - 2].getValue().equals(""))
                                return (j - 2);
                        }
                    }
                    //sol alt yon 2
                    if (i + 1 < gameCells.length && j - 1 >= 0 && gameCells[i + 1][j - 1].getValue().equals("X")) {
                        if (i + 3 == gameCells.length-1 && j - 3 >= 0 && gameCells[i + 3][j - 3].getValue().equals("X")) {
                            if (gameCells[i + 2][j - 2].getValue().equals("") && i + 4 < gameCells.length)
                                return (j - 2);
                        }
                    }
                    //sol yon
                    if (j - 1 >= 0 && gameCells[i][j - 1].getValue().equals("X")) {
                        if (j - 3 >= 0 && gameCells[i][j - 3].getValue().equals("X")) {
                            if (gameCells[i][j - 2].getValue().equals("") && i + 1 < gameCells.length && !gameCells[i + 1][j - 2].getValue().equals(""))
                                return (j - 2);
                        }
                    }
                    //sol yon sinir
                    if (j - 1 >= 0 && gameCells[i][j - 1].getValue().equals("X")) {
                        if (j - 3 >= 0 && gameCells[i][j - 3].getValue().equals("X")) {
                            if (gameCells[i][j - 2].getValue().equals("") && (gameCells.length - i) == 1)
                                return (j - 2);
                        }
                    }
                    //yukarı sol yon
                    if (i - 1 >= 0 && j - 1 >= 0 && gameCells[i - 1][j - 1].getValue().equals("X")) {
                        if (i - 3 >= 0 && j - 3 >= 0 && gameCells[i - 3][j - 3].getValue().equals("X")) {
                            if (gameCells[i - 2][j - 2].getValue().equals("") && !gameCells[i - 1][j - 2].getValue().equals(""))
                                return (j - 2);
                        }
                    }
                }
            }
        }
        return -1;
    }
    public static int engelleme() {
        for (int i = 0; i < gameCells.length; ++i) {
            for (int j = 0; j < gameCells[i].length; ++j) {
                if(gameCells[i][j].getValue().equals("X")){
                    //yukari yon
                    if(i-1>=0 && gameCells[i-1][j].getValue().equals("X") ){
                        if(i-2>=0 && gameCells[i-2][j].getValue().equals("X")){
                            if(i-3>=0 && gameCells[i-3][j].getValue().equals(""))
                                return j;
                        }
                    }
                    //yukari sag yon
                    if(i-1>=0 && j+1<gameCells[i].length && gameCells[i-1][j+1].getValue().equals("X") ){
                        if(i-2>=0 && j+2<gameCells[i].length && gameCells[i-2][j+2].getValue().equals("X")){
                            if(i-3>=0 && j+3<gameCells[i].length && gameCells[i-3][j+3].getValue().equals("") && !gameCells[i-2][j+3].getValue().equals("") )
                                return (j+3);
                        }
                    }
                    //sag yon
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("X") ){
                        if(j+2<gameCells[i].length && gameCells[i][j+2].getValue().equals("X")){
                            if(j+3<gameCells[i].length && gameCells[i][j+3].getValue().equals("") && i+1<gameCells.length && !gameCells[i+1][j+3].getValue().equals(""))
                                return (j+3);
                        }
                    }
                    //sag yon sinir
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("X") ){
                        if(j+2<gameCells[i].length && gameCells[i][j+2].getValue().equals("X")){
                            if(j+3<gameCells[i].length && gameCells[i][j+3].getValue().equals("") && (gameCells.length-i)==1 )
                                return (j+3);
                        }
                    }
                    //sag alt yon
                    if(i+1<gameCells.length && j+1<gameCells[i].length && gameCells[i+1][j+1].getValue().equals("X") ){
                        if(i+2<gameCells.length && j+2<gameCells[i].length && gameCells[i+2][j+2].getValue().equals("X")){
                            if(i+3<gameCells.length && j+3<gameCells[i].length && gameCells[i+3][j+3].getValue().equals("") && i+4<gameCells.length &&
                                    !gameCells[i+4][j+3].getValue().equals("") )
                                return (j+3);
                        }
                    }
                    //sag alt yon 2
                    if(i+1<gameCells.length && j+1<gameCells[i].length && gameCells[i+1][j+1].getValue().equals("X") ){
                        if(i+2<gameCells.length && j+2<gameCells[i].length && gameCells[i+2][j+2].getValue().equals("X")){
                            if(i+3==gameCells.length-1 && j+3<gameCells[i].length && gameCells[i+3][j+3].getValue().equals("") )
                                return (j+3);
                        }
                    }
                    //sol alt yon
                    if(i+1<gameCells.length && j-1>=0 && gameCells[i+1][j-1].getValue().equals("X") ){
                        if(i+2<gameCells.length && j-2>=0 && gameCells[i+2][j-2].getValue().equals("X")){
                            if(i+3<gameCells.length && j-3>=0 && gameCells[i+3][j-3].getValue().equals("") && i+4<gameCells.length &&  !gameCells[i+4][j-3].getValue().equals("") )
                                return (j-3);
                        }
                    }
                    //sol alt yon2
                    if(i+1<gameCells.length && j-1>=0 && gameCells[i+1][j-1].getValue().equals("X") ){
                        if(i+2<gameCells.length && j-2>=0 && gameCells[i+2][j-2].getValue().equals("X")){
                            if(i+3==gameCells.length-1 && j-3>=0 && gameCells[i+3][j-3].getValue().equals(""))
                                return (j-3);
                        }
                    }
                    //sol yon
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("X") ){
                        if(j-2>=0 && gameCells[i][j-2].getValue().equals("X")){
                            if(j-3>=0 && gameCells[i][j-3].getValue().equals("") && i+1<gameCells.length && !gameCells[i+1][j-3].getValue().equals(""))
                                return (j-3);
                        }
                    }
                    //sol yon sinir
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("X")){
                        if(j-2>=0 && gameCells[i][j-2].getValue().equals("X")){
                            if(j-3>=0 && gameCells[i][j-3].getValue().equals("") && (gameCells.length-i)==1)
                                return (j-3);
                        }
                    }
                    //yukarı sol yon
                    if(i-1>=0 && j-1>=0 && gameCells[i-1][j-1].getValue().equals("X")){
                        if(i-2>=0 && j-2>=0 && gameCells[i-2][j-2].getValue().equals("X")){
                            if(i-3>=0 && j-3>=0 && gameCells[i-3][j-3].getValue().equals("") && !gameCells[i-2][j-3].getValue().equals("") )
                                return (j-3);
                        }
                    }
                }
            }
        }
        return -1;
    }
    public static int engelleme3() {
        for (int i = 0; i < gameCells.length; ++i) {
            for (int j = 0; j < gameCells[i].length; ++j) {
                if(gameCells.length-i==1 &&  gameCells[i][j].getValue().equals("X")){
                    //sag sinir
                    if(j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("X")){
                        if(j+2<gameCells[i].length && gameCells[i][j+2].getValue().equals(""))
                            return j+2;
                    }
                    //sol sinir
                    if(j-1>=0 && gameCells[i][j-1].getValue().equals("X")){
                        if(j-2>=0 && gameCells[i][j-2].getValue().equals(""))
                            return j-2;
                    }
                }
            }
        }
        return -1;
    }
    public static int firstMove() {
        for (int i = 0; i < gameCells.length; ++i) {
            for (int j = 0; j < gameCells[i].length; ++j) {
                if(gameCells[i][j].getValue().equals("X")){
                    //sol yon
                    if( (gameCells.length-i==1) && j-1>=0 && gameCells[i][j-1].getValue().equals("")){
                        return (j-1);
                    }
                    //sag yon
                    if( (gameCells.length-i==1) && j+1<gameCells[i].length && gameCells[i][j+1].getValue().equals("") ){
                        return (j+1);
                    }
                }
            }
        }
        return 0;
    }


}

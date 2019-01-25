
package connectfour;

import java.util.logging.Level;
import java.util.logging.Logger;


import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;

import javafx.geometry.Insets;
import javafx.geometry.Pos;

import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseButton;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.control.Label;

import javafx.scene.control.TextField;

import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;


import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;

import javafx.scene.text.Text;

import javafx.stage.Modality;
import javafx.stage.Stage;

/**
 *
 * @author burki
 */
public class Connectfour extends Application {
    
    private boolean isEnd = true;
    private boolean sira = true;
    private Tile[][] board;

    private Scene scene2;
    private Stage window2;
    private String mod;
    private Integer size;
    private boolean isGameOn = false;
    private Stage gameStage;
    private Pane root;

    private Parent createContent() {
        sira=true;
        root = new Pane();
        board=new Tile[size][size];
        root.setPrefSize(50*size, 50*size);

        for (int i = 0; i<size; i++) {
            for (int j = 0; j<size; j++) {
                Tile tile = new Tile(i,j);
                tile.setTranslateX(j * 50);
                tile.setTranslateY(i * 50);

                root.getChildren().add(tile);

                board[i][j] = tile;
            }
        }
        komputer.gameCells = board;
        return root;
    }  

    /**
     *
     * @param mesaj
     */
    public void displayResult(String mesaj){
        Stage wind=new Stage();
        wind.initModality(Modality.APPLICATION_MODAL);
        wind.setTitle("Result Of Game");
        wind.setMinWidth(250);

        Label labe=new Label();
        labe.setText(mesaj);
        Button closeButton = new Button("OK");
        closeButton.setOnAction(e -> {
            wind.close();
            gameStage.close();
        });

        VBox layout = new VBox(10);
        layout.getChildren().addAll(labe,closeButton);
        layout.setAlignment(Pos.CENTER);

        Scene scene = new Scene (layout);
        wind.setScene(scene);
        wind.showAndWait();

    }
    private void youCantMoveThere(){
        new SimpleAlertBox("Illegal Move !!!", " You Can't Move There \nTry Another").show();
    }
    private void checkState(int user) {
        Directions dir = komputer.checkWin(user);
        if(user == 1 && dir != Directions.USER1NONE && dir != Directions.USER2NONE){
            displayResult("Player X is Win !!!!! ");
            isGameOn = false;
        }
        if(user == 2 && dir != Directions.USER2NONE && dir != Directions.USER1NONE){
            displayResult("Player O is Win !!!!! ");
            isGameOn = false;
        }
    }
    private boolean tabloyaKoy(int x , int y){
        for (int i = board.length-1; i >=0 ; i--) {
            if(board[i][y].getValue() == null || board[i][y].getValue().equals("") ) {
                if (sira) {
                    board[i][y].drawX();
                    return true;
                }
                if (!sira){
                    board[i][y].drawO();
                    return true;
                }
            }
        }
        if ( (mod.equals("C") && sira) || mod.equals("P") )
            youCantMoveThere();
        return false;
    }

    /**
     *
     */
    public class Tile extends StackPane {
        private Text text = new Text();
        private int xKor;
        private int yKor;

        /**
         *
         * @param x
         * @param y
         */
        public Tile(int x,int y) {
            xKor=x;
            yKor=y;
            Rectangle border = new Rectangle(50, 50);
            border.setFill(null);
            border.setStroke(Color.BLACK);

            text.setFont(Font.font(40));

            setAlignment(Pos.CENTER);
            getChildren().addAll(border, text);

            setOnMouseClicked(event -> {
                if (!isEnd && !isGameOn)
                    return;

                //turnX true ise X oynar False ise O oynar
                if (event.getButton() == MouseButton.PRIMARY) {
                    if (sira){
                        if(tabloyaKoy(getxKor(),getyKor())) {
                            checkState(sira ? 1 : 2);
                            if (mod.equals("C")) {
                                    computer();
                                }
                                else
                                    sira=false;
                        }
                    }else if(!sira) {
                        if (tabloyaKoy(getxKor(), getyKor())) {
                            checkState(sira ? 1 : 2);
                            sira = true;
                        }
                    }

                }
                if(isGameOn && !isThereAvailableMove())
                {
                    new SimpleAlertBox("Game Is Over.","    DRAW ..!").show();
                    gameStage.close();
                    isGameOn = false;
                }
            });
        }

        /**
         *
         * @return
         */
        public boolean isThereAvailableMove(){
            for (int i = 0; i < board.length; ++i){
                if(board[0][i].getValue().equals("")){
                    return true;
                }
            }
            return false;
        }

        /**
         *
         */
        public void computer(){
            sira = false;
            Integer targetY = komputer.kontrol()-1;
            int x = 0;
            System.out.println("Computer choice :"+targetY);
            while(!tabloyaKoy(getxKor(),targetY) && x < board.length) {
                if (targetY + 1 == board.length)
                    targetY = 0;
                else
                    targetY++;
                x++;
            }
            if (x == board.length){
                new SimpleAlertBox("Game Is Over.","    DRAW ..!").show();
                gameStage.close();
                isGameOn = false;
                // no place left to play
            }
            else
                checkState(sira ? 1 : 2);
            sira=true;
        }

        /**
         *
         * @return
         */
        public double getCenterX() {
            return getTranslateX() +  25;
        }

        /**
         *
         * @return
         */
        public double getCenterY() {
            return getTranslateY() + 25;
        }

        /**
         *
         * @return
         */
        public String getValue() {
            return text.getText();
        }

        private void drawX() {
            text.setText("X");
        }

        private void drawO() {
            text.setText("O");
        }

        /**
         *
         * @return
         */
        public int getxKor() {
            return xKor;
        }

        /**
         *
         * @param xKor
         */
        public void setxKor(int xKor) {
            this.xKor = xKor;
        }

        /**
         *
         * @return
         */
        public int getyKor() {
            return yKor;
        }

        /**
         *
         * @param yKor
         */
        public void setyKor(int yKor) {
            this.yKor = yKor;
        }
    }
    private boolean isInt(TextField input,String message){
        try{
                int number = Integer.parseInt(input.getText());
                
                if(number<4 || number >20)
                    throw new Error("Wrong range");
                else        
                    size= new Integer(number);
                
                System.out.println("Size is:" + size);
                return true;
            }
            catch(NumberFormatException e){
                System.out.println("Error :"+message + " is not a number or Wrong Range");
                return false;
            }
            catch(Throwable e){
                System.out.println("Error :"+message + " Wrong Range");
                return false;
            }
        }
    private boolean isString(TextField input,String message){
        try{
                String str = input.getText();
                if(!str.equals("P") && !str.equals("C") )
                    throw new Throwable();
                mod=new String(str);
                System.out.println("User mod is : " + mod);
                return true;
                
            }
            catch(Throwable e){
                System.out.println("Error :"+message + " Wrong Mod");
                return false;
            }
        }
    private boolean control(){
        if(mod.equals("C") || mod.equals("P")){
            if(size>=4 && size<20){
                return true;
            }
        }
        return false;
    }
     @Override
    public void start(Stage primaryStage) {
        window2 = primaryStage;
        window2.setTitle("ConnectFour");
        
        //Form
        TextField sizeInput = new TextField();
        TextField modInput = new TextField();

        Label labelSize = new Label();
        labelSize.setText("Enter The Board Size");

        Label labelMode = new Label();
        labelMode.setText("Enter Mode");

        Button btn = new Button();
        btn.setText("Start Game");

         //Layout
        VBox layout = new VBox(10);
        layout.setPadding(new Insets(20,20,20,20));
        layout.getChildren().addAll(labelSize,sizeInput,labelMode,modInput,btn);
        btn.setOnAction((ActionEvent event) -> {
                if( isInt(sizeInput,sizeInput.getText()) &&
                    isString(modInput,modInput.getText()) &&
                    control()){
                
                Scene secondScene = new Scene(createContent());

                gameStage = new Stage();
                gameStage.setTitle("Game");
                gameStage.setScene(secondScene);
                gameStage.show();
                /// tekrar baslatmaya bak
                isGameOn = true;
                }
                else
                    try {
                        throw new Throwable();
                    }catch (Throwable ex){
                    Logger.getLogger(Connectfour.class.getName()).log(Level.SEVERE, null, ex);
                    }   

            });
        
        scene2 = new Scene(layout,300,250);
        window2.setScene(scene2);
        window2.show();
        window2.setOnCloseRequest(e -> {
            Platform.exit();
        });
        /////////////////////////////

    }

    /**
     *
     * @param args
     */
    public static void main(String[] args) {
        launch(args);
    }
     
    
    
        
}

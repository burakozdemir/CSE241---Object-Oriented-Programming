package connectfour;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;

import javax.swing.*;
import java.awt.event.ActionEvent;

public class SimpleAlertBox {
    private Stage wind;
    public SimpleAlertBox(String title, String message){
        wind=new Stage();

        wind.initModality(Modality.APPLICATION_MODAL);
        wind.setTitle(title);
        wind.setMinWidth(250);

        Label labe=new Label();
        labe.setText(message);
        Button closeButton = new Button("OK");
        closeButton.setOnAction(e -> {
            wind.close();
        });

        VBox layout = new VBox(10);
        layout.getChildren().addAll(labe,closeButton);
        layout.setAlignment(Pos.CENTER);

        Scene scene = new Scene (layout);
        wind.setScene(scene);

    }

    public void show(){
        wind.showAndWait();
    }
}

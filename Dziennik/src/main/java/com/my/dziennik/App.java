package com.my.dziennik;

import com.my.model.Event;
import com.my.model.EventList;
import com.my.model.Grade;
import com.my.model.GradeList;
import com.my.model.IncorrectInputTypeException;
import com.my.model.NullStringInputException;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.io.IOException;
import static javafx.application.Application.launch;
import javafx.scene.Parent;

public class App extends Application {
    private static GradeList grades;
    private static EventList events;
    private static Scene scene;

    @Override
    public void start(Stage stage) throws IOException {
    FXMLLoader loader = new FXMLLoader(getClass().getResource("/com/my/view/main.fxml"));
    Parent root = loader.load();

    MainController mainController = loader.getController();
    mainController.setGradeList(grades);
    mainController.setEventList(events);
    scene = new Scene(root, 640, 480);
    stage.setScene(scene);
    stage.show();
}

    static void setRoot(Parent fxml) throws IOException {
        scene.setRoot(fxml);
    }
    
    private static Parent loadFXML(String fxml) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource(fxml + ".fxml"));
        return fxmlLoader.load();
    }

    public static void main(String[] args) throws NullStringInputException, IncorrectInputTypeException {
        grades = new GradeList();
        
        grades.AddGrade(new Grade("Math", 5));
        grades.AddGrade(new Grade("Math", 4));
        grades.AddGrade(new Grade("Physics", 3));
        grades.AddGrade(new Grade("Science", 4));
        grades.AddGrade(new Grade("Math", 2));
        events = new EventList();
        events.AddEvent(new Event(1, "tytul", "no11"));
        events.AddEvent(new Event(4, "tytul2", "no22"));
        events.AddEvent(new Event(10, "tytul3", "no33"));
        events.AddEvent(new Event(5, "tytul4", "no44"));
        events.AddEvent(new Event(3, "tytul5", "no55"));
        launch();
    }
}
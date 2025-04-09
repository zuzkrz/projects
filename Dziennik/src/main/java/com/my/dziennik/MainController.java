package com.my.dziennik;


import com.my.model.EventList;
import com.my.model.GradeList;
import java.io.IOException;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.control.Tooltip;
import javafx.scene.layout.AnchorPane;

/**
 * FXML Controller class
 *  Controller for Main page
 * @author Zuza
 */
public class MainController {
    private GradeList grades;
    private EventList events;

    /**
     * Standard setter that sets a List of grades
     * @param grades Grade List
     */
    public void setGradeList(GradeList grades) {
        this.grades = grades;
    }
    /**
     * Standard updates a List of grades
     * @param grades Grade List
     */
    public void upgrateGrades(GradeList grades) {
        this.grades = grades;
    }
    /**
     * Standard setter that sets a List of events
     * @param events Event List
     */
    public void setEventList(EventList events) {
        this.events = events;
    }
    /**
     * Standard updates a List of events
     * @param events Event List
     */
    public void upgrateEvent(EventList events) {
        this.events = events;
    }
    
    @FXML
    public AnchorPane sceneMain;
    @FXML
    private Button gradesButton;
    @FXML
    private Button eventsButton;
    public void initialize() {
        var tooltip = new Tooltip("Press to go to grades page");
        gradesButton.setTooltip(tooltip);
        var tooltip2 = new Tooltip("Press to go to event page");
        eventsButton.setTooltip(tooltip2);
    }
    /**
     * Method that allows switching from main page to grade page
     * @throws IOException 
     */
    @FXML
    void goGrades() throws IOException {
        System.out.println(grades.sizeof());
        System.out.println(events.sizeof());
        
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/com/my/view/grades.fxml"));
        Parent gradesView = loader.load();

        GradesController gradesController = loader.getController();
        gradesController.upgradeGrades(grades); 
        gradesController.upgradeEvent(events); 

        App.setRoot(gradesView);
    }
    /**
     * Method that allows switching from main page to event page
     * @throws IOException 
     */
    @FXML
    void goEvent() throws IOException {
        System.out.println(grades.sizeof());
        System.out.println(events.sizeof());
        
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/com/my/view/event.fxml"));
        Parent eventView = loader.load();

        EventController eventController = loader.getController();
        eventController.upgradeEvent(events); 
        eventController.upgradeGrades(grades); 


        App.setRoot(eventView);
    }
    
}

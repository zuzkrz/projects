package com.my.dziennik;

import com.my.model.AverageGrade;
import com.my.model.AverageGradeList;
import com.my.model.EventList;
import com.my.model.Grade;
import com.my.model.GradeList;
import com.my.model.IncorrectInputTypeException;
import com.my.model.NullStringInputException;
import com.my.model.WrongIndexException;
import java.io.IOException;
import java.util.List;
import javafx.collections.FXCollections;
import javafx.collections.ListChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.Tooltip;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.input.KeyCombination;
import javafx.scene.layout.AnchorPane;
import javafx.util.StringConverter;
import javafx.util.converter.IntegerStringConverter;

/**
 * FXML Controller class
 * Controller for Grades page
 * @author Zuza
 */
public class GradesController {
    private ObservableList<Grade> data; 
    private EventList events;
    private GradeList grades = new GradeList();
    @FXML
    private Button avgButton;
    /**
     * Class constructor.
     */
    public GradesController() {
        doIt();
    }
    
    @FXML
    public AnchorPane gradesScene;
    @FXML
    public TableView table;
    @FXML
    public TableColumn<Grade, String> subject;
    @FXML
    public TableColumn<Grade, Integer> grade;
    @FXML
    public Button addButton;
    @FXML
    public Button remove;
    @FXML
    public Button backButton;
    @FXML
    public TextField subjectEdit;
    @FXML
    public TextField gradeEdit;

    /**
     * 
     */
    public void doIt() {
        
        data = FXCollections.observableArrayList(grades.getGrades());
        if (data==null){
        data.addListener((ListChangeListener.Change<? extends Grade> change) -> {
            while (change.next()) {
                if (change.wasPermutated()) {
                    for (int i = change.getFrom(); i < change.getTo(); ++i) {
                        System.out.println("zamiana");
                    }
                } else if (change.wasUpdated()) {
                    System.out.println("uaktualnienie");
                } else {
                    for (var remitem : change.getRemoved()) {
                        grades.getGrades().remove(remitem);
                    }
                    for (var additem : change.getAddedSubList()) {
                        grades.getGrades().add(additem);
                    }
                }
            }
        });
        }
    }
    /**
     * Method that initializes table 
     */
    public void initialize() {
        var tooltip = new Tooltip("Add new grade here!");
        addButton.setTooltip(tooltip);
        var tooltip2 = new Tooltip("Remove grade here!");
        remove.setTooltip(tooltip2);
        var tooltip3 = new Tooltip("Go back to main page");
        backButton.setTooltip(tooltip3);
        
        
        table.setItems(data);
        table.setEditable(true);
        
        subject.setCellValueFactory(new PropertyValueFactory<>("subject"));
        subject.setCellFactory(TextFieldTableCell.forTableColumn());
        subject.setOnEditCommit(t -> {
            try {
                (t.getTableView().getItems().get(t.getTablePosition().getRow())).setSubject(t.getNewValue());
            } catch (NullStringInputException ex) {
                showErrorWindow("Null input!");
            }
        });
        
        grade.setCellValueFactory(new PropertyValueFactory<>("grade"));
        grade.setCellFactory(TextFieldTableCell.forTableColumn(new StringConverter<Integer>() {
            @Override
            public String toString(Integer object) {
                return object == null ? "" : object.toString();
            }
            @Override
            public Integer fromString(String string) {
                try {
                    return Integer.valueOf(string);
                } catch (NumberFormatException ex) {
                    showErrorWindow("Wrong input");
                    return null; 
                }
            }
        }));

        grade.setOnEditCommit(t -> {
            int oldValue = t.getOldValue();
            Integer newValue = t.getNewValue();
            if (newValue != null) {
                t.getTableView().getItems().get(t.getTablePosition().getRow()).setGrade(newValue);
            }
            else{
                t.getTableView().getItems().get(t.getTablePosition().getRow()).setGrade(oldValue);
            }
        });

        initializeHotkeys();
    }    
    private void initializeHotkeys(){
        Scene addScene = addButton.getScene();
        Scene delScene = remove.getScene();
        if(addScene != null){
            addScene.getAccelerators().put(
                new KeyCodeCombination(KeyCode.ENTER),
                () -> {
                try {
                    add();
                } catch (NullStringInputException ex) {
                    showErrorWindow("Wrong input");
                }
            }
            );
        }
        
        if(delScene != null){
            delScene.getAccelerators().put(
                new KeyCodeCombination(KeyCode.DELETE),
                () -> {try {
                    remove();
                } catch (WrongIndexException ex) {
                    showErrorWindow("Wrong input");
                }
                }
            );
        }
    }
    
    /**
     * Method that is activated when addButton is pressed
     */
    @FXML
    private void add() throws NullStringInputException {
        addGrade();
    }
    /**
     * Method that is activated when removeButton is pressed
     * removes selected object
     */
    @FXML
    private void remove() throws WrongIndexException {
        int index = table.getSelectionModel().getSelectedIndex();
        Grade gra = (Grade) table.getSelectionModel().getSelectedItem();
        if (gra == null){
            showErrorWindow("Nothing selected");
        }
        else{
            if(index != -1){
                data.remove(index);
                grades.remove(index);
            }
        }    

        
    }
    /**
     * Method that allows to switch from grades page to main page
     * @throws IOException 
     */
    @FXML
    void back() throws IOException{
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/com/my/view/main.fxml"));
        Parent gradesView = loader.load();

        MainController mainController = loader.getController();
        mainController.upgrateGrades(grades);
        mainController.upgrateEvent(events);

        App.setRoot(gradesView);
    }
    /**
     * Method that adds grade
     */
    public void addGrade() throws NullStringInputException {
        try{
            data.add(new Grade(subjectEdit.getText(), Integer.parseInt(gradeEdit.getText())));
            grades.AddGrade(new Grade(subjectEdit.getText(), Integer.parseInt(gradeEdit.getText())));
        } catch(NumberFormatException ex) {
            showErrorWindow("Could not add new grade");
        }
    }
    /**
     * Method that upgrades grades, data and initializes table again
     */
    public void upgradeGrades(GradeList grades) {
    this.grades = grades;
    doIt();
    initialize();
    }
    /**
     * Method that returns Grade List
     * @return GradeList
     */
    public GradeList upgradeGrades(){
        return grades;
    }
    /**
     * Method that upgrades events
     */
    public void upgradeEvent(EventList events) {
    this.events = events;
    }
    /**
     * Method that upgrades events
     * @returns EventList
     */
    public EventList upgradeEvent(){
        return events;
    }
    public void showErrorWindow(String errorMessage){
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("ERROR");
        alert.setHeaderText("An error has occured");
        alert.setContentText(errorMessage);
        alert.showAndWait();
    }

    @FXML
    private void avg() {
        AverageGradeList avg= new AverageGradeList(grades);
        showRaportWindow(avg);
    }
    
    public void showRaportWindow(AverageGradeList avg){
        Alert alert  = new Alert(Alert.AlertType.INFORMATION);
        alert.setWidth(300);
        alert.setHeight(400);
        alert.setTitle("RAPORT");
        alert.setHeaderText("List of average grade per subject");
        StringBuilder temp = new StringBuilder("[subject]\t[grade]\n");
        avg.getData().forEach(x -> temp.append(x.classID()).append("\t").append(Double.toString(x.average())).append("\n"));
        alert.setContentText(temp.toString());
        alert.showAndWait();
    }
}

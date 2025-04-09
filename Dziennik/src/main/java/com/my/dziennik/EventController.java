package com.my.dziennik;

import com.my.model.Event;
import com.my.model.EventList;
import com.my.model.GradeList;
import com.my.model.IncorrectInputTypeException;
import com.my.model.NullStringInputException;
import com.my.model.Status;
import com.my.model.WrongIndexException;
import java.io.IOException;
import javafx.beans.property.SimpleObjectProperty;
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
import javafx.scene.control.cell.ComboBoxTableCell;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.layout.AnchorPane;
import javafx.util.StringConverter;
import javafx.util.converter.IntegerStringConverter;
/**
 * FXML Controller class
 * Controller for Event page
 * @author Zuza
 */
public class EventController {
    private ObservableList<Event> data; 
    private GradeList grades;
    private EventList events = new EventList();
    
    /**
     * Class constructor.
     */
    public EventController() {
        doIt();
    }
    /**
     * 
     */
    public void doIt() {
        data = FXCollections.observableArrayList(events.getEvents());
        if (data == null) {
        data.addListener((ListChangeListener.Change<? extends Event> change) -> {
            while (change.next()) {
                if (change.wasPermutated()) {
                    for (int i = change.getFrom(); i < change.getTo(); ++i) {
                        System.out.println("zamiana");
                    }
                } else if (change.wasUpdated()) {
                    System.out.println("uaktualnienie");
                } else {
                    for (var remitem : change.getRemoved()) {
                        events.getEvents().remove(remitem);
                    }
                    for (var additem : change.getAddedSubList()) {
                        events.getEvents().add(additem);
                    }
                }
            }
        });
        }
    }
    
    @FXML
    public AnchorPane eventScene;
    @FXML
    public TableView table;
    @FXML
    public TableColumn<Event, String> evName;
    @FXML
    public TableColumn<Event, Integer> daysTo;
    @FXML
    public TableColumn<Event, String> descp;
    @FXML
    private TableColumn<Event, Status> status;
    @FXML
    public Button addButton;
    @FXML
    public Button delButton;
    @FXML
    public Button backButton;
    @FXML
    public TextField eventEdit;
    @FXML
    public TextField daysEdit;
    @FXML
    public TextField descriptionEdit;
    
    /**
     * Method that initializes table 
     */
    public void initialize() {
        var tooltip = new Tooltip("Add new event here!");
        addButton.setTooltip(tooltip);
        var tooltip2 = new Tooltip("Remove event here!");
        delButton.setTooltip(tooltip2);
        var tooltip3 = new Tooltip("Go back to main page");
        backButton.setTooltip(tooltip3);
        
        table.setItems(data);
        table.setEditable(true);
        
        evName.setCellValueFactory(new PropertyValueFactory<>("title"));
        evName.setCellFactory(TextFieldTableCell.forTableColumn());
        evName.setOnEditCommit(t -> {
            
            try {
                (t.getTableView().getItems().get(t.getTablePosition().getRow())).setTitle(t.getNewValue());
            } catch (NullStringInputException ex) {
                showErrorWindow("Title has no name!");
            }
        });
        
        daysTo.setCellValueFactory(new PropertyValueFactory<>("daysTo"));
        daysTo.setCellFactory(TextFieldTableCell.forTableColumn(new StringConverter<Integer>() {
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
        daysTo.setOnEditCommit(t -> {
            int oldValue = t.getOldValue();
            Integer newValue = t.getNewValue();
            if (newValue != null) {
                try {
                    t.getTableView().getItems().get(t.getTablePosition().getRow()).setDaysTo(newValue);
                } catch (IncorrectInputTypeException ex) {
                    showErrorWindow("Wrong input");
                }
            }
            else{
                try {
                    t.getTableView().getItems().get(t.getTablePosition().getRow()).setDaysTo(oldValue);
                } catch (IncorrectInputTypeException ex) {
                    showErrorWindow("Wrong input");
                }
            }
        });

        
        
        descp.setCellValueFactory(new PropertyValueFactory<>("description"));
        descp.setCellFactory(TextFieldTableCell.forTableColumn());
        descp.setOnEditCommit(t -> {
            (t.getTableView().getItems().get(t.getTablePosition().getRow())).setDescription(t.getNewValue());
        });
        status.setCellValueFactory(cellData -> new SimpleObjectProperty<>(cellData.getValue().getStatus()));
        status.setCellFactory(column -> {
            ComboBoxTableCell<Event, Status> cell = new ComboBoxTableCell<>(FXCollections.observableArrayList(Status.values())) {
            @Override
            public void updateItem(Status status, boolean empty) {
                super.updateItem(status, empty);}
            }; 
            return cell;
        });
        
        initializeHotkeys();
    }    
    private void initializeHotkeys(){
        Scene addScene = addButton.getScene();
        Scene delScene = delButton.getScene();
        if(addScene != null){
            addScene.getAccelerators().put(
                new KeyCodeCombination(KeyCode.ENTER),
                () -> {
                try {
                    add();
                } catch (NullStringInputException ex) {
                    showErrorWindow("Null input");
                } catch (IncorrectInputTypeException ex) {
                    showErrorWindow("Wrong number");
                }
            }
            );
        }
        
        if(delScene != null){
            delScene.getAccelerators().put(
                new KeyCodeCombination(KeyCode.DELETE),
                () -> {try {
                    delete();
                } catch (WrongIndexException ex) {
                    showErrorWindow("Wrong index");
                }
                }
            );
        }
    }
    
    /**
     * Method that is activated when addButton is pressed
     */
    @FXML
    private void add() throws NullStringInputException, IncorrectInputTypeException {
        addEvent();
    }
    /**
     * Method that is activated when delateButton is pressed
     * removes selected object
     */
    @FXML
    private void delete() throws WrongIndexException {
        int index = table.getSelectionModel().getSelectedIndex();
        Event gra = (Event) table.getSelectionModel().getSelectedItem();
        if (gra == null){
            showErrorWindow("Nothing selected");
        }
        else {
            if(index != -1) {
            data.remove(index);
            events.remove(index);
            }
        }
    }
    /**
     * Method that allows to switch from event page to main page
     * @throws IOException 
     */
    @FXML
    void back() throws IOException  {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/com/my/view/main.fxml"));
        Parent eventView = loader.load();

        MainController mainController = loader.getController();
        mainController.upgrateEvent(events);
        mainController.upgrateGrades(grades);

        App.setRoot(eventView);
    }
    /**
     * Method that adds event
     */
    public void addEvent() throws NullStringInputException, IncorrectInputTypeException {
        try{
            String temp = descriptionEdit.getText();
            if (temp.equals("")) {
                temp = "No description";
            }
            data.add(new Event(Integer.parseInt(daysEdit.getText()), eventEdit.getText(), temp));
            events.AddEvent(new Event(Integer.parseInt(daysEdit.getText()), eventEdit.getText(), temp));
        } catch(NumberFormatException ex) {
            showErrorWindow("Could not add new event");
        }
    }
    /**
     * Method that upgrades events, data and initializes table again
     */
    public void upgradeEvent(EventList events) {
    this.events = events;
    doIt();
    initialize();
    }
    /**
     * Method that upgrades events
     * @returns EventList
     */
    public EventList upgradeEvent(){
        return events;
    }
    /**
     * Method that upgrades grades
     */
    public void upgradeGrades(GradeList grades) {
    this.grades = grades;
    }
    /**
     * Method that returns Grade List
     * @return GradeList
     */
    public GradeList upgradeGrades(){
        return grades;
    }
    public void showErrorWindow(String errorMessage){
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("ERROR");
        alert.setHeaderText("An error has occured");
        alert.setContentText(errorMessage);
        alert.showAndWait();
    }
}

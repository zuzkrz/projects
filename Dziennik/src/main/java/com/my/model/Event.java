package com.my.model;
import static com.my.model.Status.NOT_DONE;
import lombok.*;
/**
 * Class that represents Event
 * @author Zuza
 */
@AllArgsConstructor
@Getter
@EqualsAndHashCode
@ToString
public class Event {
    @Setter
    private Status status;
    private int daysTo;
    private String title;
    private String description;
    
    public Event(int daysTo, String title, String description) throws NullStringInputException, IncorrectInputTypeException{
        if (title == null || title.trim().isEmpty()) throw new NullStringInputException("Title empty!");
        if (description == null || description.trim().isEmpty()) throw new NullStringInputException("Description empty!");
        if (daysTo <0) throw new IncorrectInputTypeException("Wrong number of days! Cannot be less than zero");
        this.daysTo = daysTo;
        this.description = description;
        this.title = title;
        this.status = NOT_DONE;
    }
    public Event(int daysTo, String title) throws NullStringInputException, IncorrectInputTypeException{
        if (title == null || title.trim().isEmpty()) throw new NullStringInputException("Title empty!");
        if (daysTo <0) throw new IncorrectInputTypeException("Wrong number of days! Cannot be less than zero");
        this.daysTo = daysTo;
        this.description = "No description.";
        this.title = title;
        this.status = NOT_DONE;
    }
    
    public void setDaysTo(int daysTo) throws IncorrectInputTypeException {
        if (daysTo <0) throw new IncorrectInputTypeException("Wrong number of days! Cannot be less than zero");
        try{
            this.daysTo = daysTo;
        }
        catch (NumberFormatException ex){
            throw new IncorrectInputTypeException("Wrong Number!", ex);
        }
    }
    public void setTitle(String title) throws NullStringInputException {
        if (title == null || title.trim().isEmpty()) throw new NullStringInputException("Title has no name!");
        this.title = title;
    }
    public void setDescription(String descrp) {
        if (descrp == null || descrp.trim().isEmpty()) {
            this.description = "No description.";
        }
        else {
            this.description = descrp;
        }
    }
}

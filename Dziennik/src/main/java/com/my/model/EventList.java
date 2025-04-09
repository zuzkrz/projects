package com.my.model;

import java.util.ArrayList;
import java.util.List;

/**
 *  Container for Events
 * @author Zuza
 */
public class EventList {
    /**
     * Container for events
     */
    private List<Event> events = new ArrayList<>();
    /**
     * Class constructor.
     */
    public EventList() {
    }
    /**
     * Standard getter that returns a List of events
     * @return Event List
     */
    public List<Event> getEvents() {
        return events;
    }
    /**
     * Method that allows to add event to the list
     * @param ev Event Object
     */
    public void AddEvent(Event ev) {
        events.add(ev);
    }
    /**
     * Method that allows to remove event from the list
     * @param index 
     * @throws com.my.model.WrongIndexException 
     */
    public void remove(int index) throws WrongIndexException {
        try{
            events.remove(index);
        }
        catch (IndexOutOfBoundsException ex){
            throw new WrongIndexException("Wrong index", ex);
        }
    }
    /**
     * Method that return size of container
     * @return size of list
     */
    public int sizeof() {
         return events.size();
    }
}

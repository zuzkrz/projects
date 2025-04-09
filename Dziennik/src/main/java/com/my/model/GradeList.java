package com.my.model;

import java.util.ArrayList;
import java.util.List;

/**
 *  Container for grades
 * @author Zuza
 */
public class GradeList {
    /**
     * Container for grades
     */
    private final List<Grade> grades = new ArrayList<>();
    /**
     * Class constructor.
     */
    public GradeList() {
    }            
    /**
     * Standard getter that returns a List of grades
     * @return Grade List
     */
    public List<Grade> getGrades() {
        return grades;
    }
    /**
     * Method that allows to add grade to the list
     * @param grade Grade object
     */
    public void AddGrade(Grade grade) {
         grades.add(grade);
    }
    /**
     * Method that allows to remove grade from the list
     * @param index 
     * @throws com.my.model.WrongIndexException 
     */
    public void remove(int index) throws WrongIndexException{
        try{
            grades.remove(index);
        } catch (IndexOutOfBoundsException ex){
            throw new WrongIndexException("Wrong index", ex);
        }  
    }
    public Grade getGrade(int index) {
        return grades.get(index);
    }
    /**
     * Method that return size of container
     * @return size of list
     */
    public int sizeof() {
         return grades.size();
    }
}

package com.my.model;

/**
 * Exception made to check if user put correct data to program
 * @author Zuza
 */
public class IncorrectInputTypeException extends Exception{
    public IncorrectInputTypeException(String message){
        super(message);
    }
    public IncorrectInputTypeException(String message, Throwable cause) {
        super(message, cause);
    }
}

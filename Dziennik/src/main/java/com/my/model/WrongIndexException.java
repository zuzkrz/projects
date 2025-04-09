package com.my.model;

/**
 * Exception made to check if index is right
 * @author Zuza
 */
public class WrongIndexException extends Exception{
    public WrongIndexException(String message){
        super(message);
    }
    public WrongIndexException(String message, Throwable cause) {
        super(message, cause);
    }
}


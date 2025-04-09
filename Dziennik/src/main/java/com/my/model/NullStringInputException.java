package com.my.model;

/**
 *
 * @author Zuza
 */
public class NullStringInputException extends Exception{
    public NullStringInputException(String message){
        super(message);
    }
    public NullStringInputException(String message, Throwable cause) {
        super(message, cause);
    }
    public NullStringInputException(){
        super("Null input!");
    }
}

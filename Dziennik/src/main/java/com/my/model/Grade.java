package com.my.model;
import lombok.*;
/**
 * Class that represents Grade
 * @author Zuza
 */

@EqualsAndHashCode
@ToString

public class Grade {
    @Getter
    private String subject;
    @Setter
    @Getter
    private int grade;
    
    public Grade (String subject, int grade) throws NullStringInputException {
        if (subject == null || subject.trim().isEmpty()) throw new NullStringInputException("Subject has no name!");
        this.subject = subject;
        this.grade = grade;
    }
    
    public void setSubject(String subject)throws NullStringInputException{
        if (subject == null || subject.trim().isEmpty()) throw new NullStringInputException("Subject has no name!");
        this.subject = subject;
    }
}


package com.my.tests;

import com.my.model.Grade;
import com.my.model.NullStringInputException;
import org.junit.jupiter.api.AfterEach;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.EmptySource;
import org.junit.jupiter.params.provider.NullSource;
import org.junit.jupiter.params.provider.ValueSource;
import org.junit.platform.commons.util.StringUtils;


public class GradeTest {
    @BeforeEach
    public void setUp() {
    }
    
    @AfterEach
    public void tearDown() {
    }
    @ParameterizedTest
    @NullSource
    @EmptySource
    @ValueSource(strings = {"", " ", "\n"})
    public void incorrectubjectTest(String sub) {
     try {
            Grade grade = new Grade(sub, 5);
            fail("An exception should be thrown when the first name is incorrect.");
        } catch (NullStringInputException ex) {
        }    
    }
    @ParameterizedTest
    @NullSource
    @EmptySource
    @ValueSource(strings = {"", " ", "\n"})
    public void incorrectubjectTestv2(String sub) {
     NullStringInputException exception = assertThrows(
                NullStringInputException.class,
                () -> new Grade(sub, 5),
                "An exception should be thrown when the subject is incorrect.");
        assertEquals("Subject has no name!", exception.getMessage());
    }
    @ParameterizedTest
    @ValueSource(strings = {"Test", "Janu"})
    public void correctSubjectTest(String subject) {
        assertDoesNotThrow(() -> new Grade(subject, 5), "An exception should not be thrown!");
    }
    @ParameterizedTest
    @CsvSource({"jan,1", "test,5", "A,7"})
    public void correctGradeParamTest(String subject, int gra) {
        try {
            Grade grade = new Grade(subject, gra);          
        } catch (Exception ex) {
            fail("An exception should not be thrown!");
        }    
    }
    @ParameterizedTest
    @ValueSource(strings = {"", " ", "\n"})
    public void settingSubjectWrongTest(String temp) throws NullStringInputException {
        Grade grade = new Grade("Math", 1);
        try {
            grade.setSubject(temp);
            fail("An exception should be thrown if strings are 'null'!");
        } catch (NullStringInputException ex) {            
        }  
    }
    @ParameterizedTest
    @ValueSource(strings = {"Math", "History", "ttr"})
    public void settingSubjectOkTest(String temp) throws NullStringInputException {
        Grade grade = new Grade("Math", 1);
        try {
            grade.setSubject(temp);
            
        } catch (NullStringInputException ex) {        
            fail("An exception should not be thrown!");
        }  
    }
    
    
}

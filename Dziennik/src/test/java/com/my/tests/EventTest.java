
package com.my.tests;

import com.my.model.Event;
import com.my.model.IncorrectInputTypeException;
import com.my.model.NullStringInputException;
import org.junit.jupiter.api.AfterEach;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.fail;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.EmptySource;
import org.junit.jupiter.params.provider.NullSource;
import org.junit.jupiter.params.provider.ValueSource;

public class EventTest {
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
    public void incorrectEventTitleTest(String title) throws IncorrectInputTypeException {
        try {
            Event ev = new Event(10, title);
            fail("An exception should be thrown when the title is incorrect.");
        } catch (NullStringInputException ex) {
        }        
    }
    @ParameterizedTest
    @ValueSource(strings = {"title", "tytul"})
    public void correctEventTitleTest(String title) throws IncorrectInputTypeException {
        assertDoesNotThrow(() -> new Event(10, title), "An exception should not be thrown!");
    }
    @ParameterizedTest
    @CsvSource({"-1", "-5", "-7"})
    public void incorrectEventDaysToTest(int day) { 
        IncorrectInputTypeException exception = assertThrows(
                IncorrectInputTypeException.class,
                () -> new Event(day, "Title"),
                "An exception should be thrown when the subject is incorrect.");
        assertEquals("Wrong number of days! Cannot be less than zero", exception.getMessage());
    }
    @Test
    public void allDataCorrectTest() {
        assertDoesNotThrow(
                () -> new Event(2, "Title"), 
                "All the data is correct, an exception should not be thrown.");
    } 
    @ParameterizedTest
    @CsvSource({"title,1,desc", "test,5,opis"})
    public void allDataCorrectTestv2(String title, int day, String opis) {
        assertDoesNotThrow(
                () -> new Event(day, title, opis), 
                "All the data is correct, an exception should not be thrown.");
    } 
    @ParameterizedTest
    @ValueSource(strings = {"Math", "History", "ttr"})
    public void settingSubjectOkTest(String temp) throws IncorrectInputTypeException, NullStringInputException{
        Event even = new Event(1, "Title", "Non");
        try {
            even.setTitle(temp);
            
        } catch ( NullStringInputException ex) {        
            fail("An exception should not be thrown!");
        }  
    }
    @ParameterizedTest
    @NullSource
    @EmptySource
    @ValueSource(strings = {"", " ", "\n"})
    public void settingSubjectWrongTest(String temp) throws IncorrectInputTypeException, NullStringInputException{
        Event even = new Event(1, "Title", "Non");
        try {
            even.setTitle(temp);
            fail("An exception should be thrown!");
        } catch ( NullStringInputException ex) {                   
        }  
    }
    @ParameterizedTest
    @CsvSource({"-1", "-5", "-7"})
    public void settingDaysToWrongTest(int temp) throws IncorrectInputTypeException, NullStringInputException{
        Event even = new Event(1, "Title", "Non");
        try {
            even.setDaysTo(temp);
            fail("An exception should be thrown!");
        } catch ( IncorrectInputTypeException ex) {        
        }  
    }
    @ParameterizedTest
    @CsvSource({"1", "5", "7"})
    public void settingDaysToOKTest(int temp) throws IncorrectInputTypeException, NullStringInputException{
        Event even = new Event(1, "Title", "Non");
        try {
            even.setDaysTo(temp);
            
        } catch ( IncorrectInputTypeException ex) {   
            fail("An exception should not be thrown!");     
        }  
    }
    @ParameterizedTest
    @CsvSource({"Math,Math", "History,History", "ttr,ttr", ",No description.", " ,No description."})
    public void settingDescriptionTest(String temp, String expected) throws IncorrectInputTypeException, NullStringInputException{
        Event even = new Event(1, "Title", "Non");
        even.setDescription(temp);
        assertEquals(even.getDescription(),expected);
    }
}

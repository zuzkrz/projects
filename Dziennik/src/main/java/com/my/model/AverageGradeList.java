package com.my.model;

import java.util.ArrayList;
import java.util.List;



public class AverageGradeList {
    private final List<AverageGrade>  list = new ArrayList();
    public AverageGradeList(GradeList passedGrades) {
        List<Grade> grades = passedGrades.getGrades();
        List<String> subjects = new ArrayList();
        if (!grades.isEmpty())
        {
            for (Grade grade: grades) {
                if (subjects.isEmpty()){
                    subjects.add(grade.getSubject());
                }
                else {
                    boolean  ifis = false;
                    for (String s : subjects) {
                        if (s.equals(grade.getSubject())){
                            ifis=true;
                        }
                    }
                    if(!ifis){
                        subjects.add(grade.getSubject());
                    }
                }
            }
            for (String s : subjects){
                double sum = 0;
                int counter = 0;
                for (Grade grade : grades){
                    if (s.equals(grade.getSubject())){
                        sum += grade.getGrade();
                        counter++;
                    }
                }
                double roundedNum = Math.round(sum/counter*100) / 100.0;
                list.add(new AverageGrade(s, roundedNum));
            }
        }       
    }
    public int sizeof() {
         return list.size();
    }

   public AverageGrade getAvg(int index){
       return list.get(index);
   }
   public List<AverageGrade> getData(){
       return list;
   }
}

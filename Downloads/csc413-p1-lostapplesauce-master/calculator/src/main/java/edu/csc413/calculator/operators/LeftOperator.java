package edu.csc413.calculator.operators;

import edu.csc413.calculator.evaluator.Operand;

public class LeftOperator extends Operator {
    @Override
    public int priority(){return 0;}

    public Operand execute(Operand op1, Operand op2) {
        return null;
    }
}

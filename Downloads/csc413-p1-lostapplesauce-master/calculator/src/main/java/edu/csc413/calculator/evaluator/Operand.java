package edu.csc413.calculator.evaluator;

/**
 * Operand class used to represent an operand
 * in a valid mathematical expression.
 */
public class Operand {
    static int operand;
    /**
     * construct operand from string token.
     */
    public Operand(String token) {
        operand = Integer.parseInt(token);
    }

    /**
     * construct operand from integer
     */
    public Operand(int value) {
        operand = value;
    }

    public Operand() {
    }

    /**
     * return value of operand
     */
    public int getValue() {
        return operand;
    }

    /**
     * Check to see if given token is a valid
     * operand.
     */
    public static boolean check(String token) {
        if(operand == Integer.parseInt(token)){
            return true;
        }
        return false;
    }
}

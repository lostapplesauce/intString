package edu.csc413.calculator.operators;

import edu.csc413.calculator.evaluator.Operand;

import java.util.HashMap;

public abstract class Operator {
    // The Operator class should contain an instance of a HashMap.
    // The keys of the map will be the tokens we're interested in,
    // and values will be instances of Operator.
    // ALL subclasses of operator MUST be in their own file.
    // 
    // Where does this declaration go?
    // What should its access level be?
    // Class or instance variable?
    // Is this the right declaration?
    // HashMap operators = new HashMap();
    // operators.put( "+", new AdditionOperator() );
    // operators.put( "-", new SubtractionOperator() );

    /**
     * used to get the priority of an operator
     *
     * @return as an int, priority of operator
     */

    private static HashMap <String, Operator> oper;
    static{
        oper.put("+",new AddOperator());
        oper.put("-",new SubtractOperator());
        oper.put("*",new MultiplyOperator());
        oper.put("/",new DivideOperator());
        oper.put("^",new PowerOperator());
        oper.put("(",new LeftOperator());
        oper.put(")",new RightOperator());
    }
    public abstract int priority();

    public abstract Operand execute(Operand op1, Operand op2);


    /**
     * determines if a given token is a valid operator.
     * please do your best to avoid static checks
     * for example token.equals("+") and so on.
     * Think about what happens if we add more operators.
     */
    public static boolean check(String token) {
        return oper.containsKey(token);
    }

    /**
     * used to retrieve an operator from our HashMap.
     * This will act as out publicly facing function,
     * granting access to the Operator HashMap.
     *
     * @param token key of the operator we want to retrieve
     * @return reference to a Operator instance.
     */
    public static Operator getOperator(String token) {
        if (Operator.check(token)) {
            return oper.get(token);
        } else {
            return null;
        }
    }
}

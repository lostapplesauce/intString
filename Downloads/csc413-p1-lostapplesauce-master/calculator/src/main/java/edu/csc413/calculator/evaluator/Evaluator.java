package edu.csc413.calculator.evaluator;


import edu.csc413.calculator.operators.LeftOperator;
import edu.csc413.calculator.operators.Operator;

import java.util.Stack;
import java.util.StringTokenizer;


public class Evaluator extends Operand {
    private Stack<Operand> operandStack;
    private Stack<Operator> operatorStack;
    private StringTokenizer tokenizer;
    private static final String DELIMITERS = "+-*^/ ";

    public Evaluator() {
        operandStack = new Stack<>();
        operatorStack = new Stack<>();

    }

    public int eval(String expression) {
        String token;

        // The 3rd argument is true to indicate that the delimiters should be used
        // as tokens, too. But, we'll need to remember to filter out spaces.
        this.tokenizer = new StringTokenizer(expression, DELIMITERS, true);


        while (this.tokenizer.hasMoreTokens()) {
            // filter out spaces
            if (!(token = this.tokenizer.nextToken()).equals(" ")) {
                // check if token is an operand
                if (Operand.check(token)) {
                     Operand push = operandStack.push(new Operand(token));
                } else {
                   if (!Operator.check(token))
                {
                        System.out.println("*****invalid token******");
                        throw new RuntimeException("*****invalid token******");
                    }
                    Operator newOperator = Operator.getOperator(token);
                    while (!operatorStack.isEmpty()&& operatorStack.peek().priority()
                    >=newOperator.priority()){
                        if (operatorStack.peek().equals("(")) {
                            while (operatorStack.peek().priority() != 0) {

                            }
                        } else {
                                    Operator oldOpr = operatorStack.pop();
                                    Operand op2 = operandStack.pop();
                                    Operand op1 = operandStack.pop();
                                    operandStack.push(oldOpr.execute(op1, op2));


                                }
                            }
                            operatorStack.push(newOperator);
                        }
                    }
                    // TODO Operator is abstract - these two lines will need to be fixed:

                }
        return (operandStack.pop().getValue());
            }

            }

            //Don't forget to change the return value!




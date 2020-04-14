

public class intString {
    private static final String numberNames[] ={
        "zero","one","two","three","four","five","six",
            "seven","eight","nine"
    };

    private String convert(int number){
        String current;
        current = numberNames[number%10];

        return numberNames[number];
    }
    public static void main(String args[]){
        intString obj = new intString();
        int word = 8;
        String change;
        change = Integer.toString(word);
        System.out.println("The apple was " + obj.convert(word));
    }
}

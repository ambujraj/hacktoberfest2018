import java.text.ParseException;

public class Main {

    public static void main(String[] args) throws ParseException {
	 ExpressionTree e = new ExpressionTree();
	 e.parse("( 9 + 5 ) * 2");
	 System.out.println(e.evaluate());
    }
}

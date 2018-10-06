class ReverseString {
	public static String reverseString(String s) {
        char [] testArray = s.toCharArray();
        int size = testArray.length / 2;
        int i;
        char temp;
        
        for(i = 0; i<size; i++){
            temp = testArray[i];
            testArray[i] = testArray[testArray.length - i - 1];
            testArray[testArray.length - i - 1] = temp;
        }
        
        return new String(testArray);
    }

    public static void main(String[] args) {
        System.out.println(reverseString("test"));
    }
}
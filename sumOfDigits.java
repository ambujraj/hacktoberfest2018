public class sumOfDigits {

    /**sumOfDigits reads a long number and returns the sum of its digits
     *
     * @param number        number of which the digits are summed up
     * @return sumOfDigits sum of the digits in number
     */
    static long sumOfDigits(long number) {
        long sumOfDigits = 0;

        String numberString = String.valueOf(number);

        for (int i = 0; i < numberString.length(); i++) {
            sumOfDigits += Character.getNumericValue(numberString.charAt(i));
        }

        return sumOfDigits;
    }
}

package java;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

/**
 * This class tests the java fibonacci algorithm.
 */
public class FibonacciTest {
    @Test
    public void testFibonacci() {
        assertEquals(0, Fibonacci.fibonacci(0));
        assertEquals(1, Fibonacci.fibonacci(1));
        assertEquals(34, Fibonacci.fibonacci(9));
        assertEquals(144, Fibonacci.fibonacci(12));
    }
}

/*Formula inventor: Hasin Israk Toaha (Constant T)-  SSC '25
 Java program wittten by: Hasin Israk Toaha
 Compiled in: Termux (Android 11)
 Compiler: javac (OpenJDK-17)

  Please give me credit if you use it anywhere
  Contact: toaha.banaripara@gmail.com

*/

import java.math.*;
import java.util.*;

public class ToahaSBitwiseRule
{
    public static boolean isPrime(BigDecimal num) 
    {
        if (num.compareTo(BigDecimal.ONE) <= 0) return false;
        BigDecimal two = BigDecimal.valueOf(2);
        for (BigDecimal i = two; i.multiply(i).compareTo(num) <= 0; i = i.add(BigDecimal.ONE)) 
        {
            if (num.remainder(i).compareTo(BigDecimal.ZERO) == 0) return false;
        }
        return true;
    }

    public static void main(String[] args)
    {
        System.out.print("Enter the terms: ");
        Scanner sc = new Scanner(System.in);
        BigDecimal terms = sc.nextBigDecimal();

        long startTime = System.currentTimeMillis();

        for (BigDecimal i = BigDecimal.ONE; i.compareTo(terms) <= 0; i = i.add(BigDecimal.ONE)) 
        {
            if (i.remainder(BigDecimal.valueOf(2)).compareTo(BigDecimal.ZERO) == 0) 
            {
                BigDecimal next = i.add(BigDecimal.ONE); 
                if (isPrime(next) || next.remainder(BigDecimal.valueOf(3)).compareTo(BigDecimal.ZERO) == 0) 
                {
                    BigDecimal andResult = new BigDecimal(i.toBigInteger().and(next.toBigInteger()));
                    BigDecimal orResult = new BigDecimal(i.toBigInteger().or(next.toBigInteger())); 
                    System.out.printf("%s & %s = %s%n%s | %s = %s%n%n", i, next, andResult, i, next, orResult);
                }
            }
        }

        long endTime = System.currentTimeMillis();

        System.out.printf("Time taken: %.8f Seconds%n",(endTime - startTime) / 1000.0);
        sc.close();
    }
}
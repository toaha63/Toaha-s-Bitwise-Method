# Toaha-s-Bitwise-Method
**Written by:** Hasin Israk Toaha (Constant T) (SSC 25) 
/*

জীবন কতদিন জানি না, তাই পাবলিশ করে দেই, দয়াকরে কোথাও লিখলে আমাকে ক্রেডিট দিবেনঃ

শিরোনামঃ Toaha's Bitwise Method.

বিস্তারিতঃ

যদি x একটি ধনাত্মক জোড় পূর্ণসংখ্যা হয় এবং (x+1) যদি মৌলিক সংখ্যা ∪ 3 দ্বারা নিঃশেষে বিভাজ্য সংখ্যা হয়,তাহলে x ও (x+1) এর Bitwise and করলে x আসবে এবং or করলে x+1 আসবে।

সমীকরণঃ
```Latex
x∈{x:x=2N,N∈N}
(x+1)∈{x:x∈P∪A}
P={2,3,5,7,11,13,17,19,23,29... ...}
A={3,6,9, 12,15,18,21... ...}


* x & (x+1) = x
* x | (x+1) = (x+1)
```

বিশেষ দ্রষ্টব্যঃ মৌলিক সংখ্যা ২ এর ব্যাপারটা ভিন্ন।

এই সমীকরণের প্রমাণ এই সি প্রোগ্রামঃ
*/
```C
#
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

bool is_prime(unsigned long long int num)
{
    if (num <= 1) 
    {
        return false;
    }
    if (num <= 3) 
    {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) 
    {
        return false;
    }

    for (unsigned long long int i = 5; i * i <= num; i += 6) 
    {
        if (num % i == 0 || num % (i + 2) == 0) 
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    puts("Enter terms: ");
    unsigned long long int terms = 0;
    scanf("%llu", &terms);
    
    clock_t start_time = clock();

    for (unsigned long long int i = 1; i <= terms; i++) 
    {
        if (i % 2 == 0) 
        {
            unsigned long long int next = i + 1;
            if (is_prime(next) || next % 3 == 0) 
            {
                unsigned long long int and_result = i & next;
                unsigned long long int or_result = i | next;
                printf("%llu & %llu = %llu\n%llu | %llu = %llu\n\n", i, next, and_result, i, next, or_result);
            }
        }
    }

    clock_t end_time = clock();

    printf("Time taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    exit(EXIT_SUCCESS);
}


/*

#Credit: হাসিন ইশরাক ত্বোয়াহা (Constant T), SSC '25
ঘুছিয়ে লিখতে পারিনি, সংশোধন করে দিবেন আশাকরি।

*/
```

জাভা প্রোগ্রামঃ

```Java

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
```

পাইথন প্রোগ্রামঃ

```Python


#Formula inventor: Hasin Israk Toaha (Constant T)

#Python code written by: Hasin Israk Toaha

#Executed in: Termux (Android 11)


from decimal import *
from time import *

class ToahaSBitwiseRule:
    def __init__(self, terms):
        self.terms = Decimal(terms)

    def is_prime(self, num):
        if num <= 1:
            return False
        for i in range(2, int(num.sqrt()) + 1):
            if num % i == 0:
                return False
        return True

    def calculate_bitwise_operations(self):
        start_time = time()

        for i in range(1, int(self.terms) + 1):
            if i % 2 == 0:
                next_num = i + 1
                if self.is_prime(Decimal(next_num)) or next_num % 3 == 0:
                    and_result = i & next_num
                    or_result = i | next_num
                    print(f"{i} & {next_num} = {and_result}")
                    print(f"{i} | {next_num} = {or_result}\n")

        end_time = time()
        print(f"Time taken: {end_time - start_time:.8f} Seconds")

def main():
    terms = input("Enter the terms: ")
    bitwise_rule = ToahaSBitwiseRule(terms)
    bitwise_rule.calculate_bitwise_operations()

if __name__ == "__main__":
    main()


```

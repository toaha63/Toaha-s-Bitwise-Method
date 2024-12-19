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
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool is_prime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    for (int i = 1; i <= 5000; i++)
    {
        if (i % 2 == 0)
        {
            int next = i + 1;
            if (is_prime(next) || next % 3 == 0)
            {
                int and_result = i & next;
                int or_result = i | next;
                printf("%d & %d = %d\n%d | %d = %d\n\n",i,i+1,and_result,i,i+1,or_result);
            }
        }
    }
    exit(EXIT_SUCCESS);
}

/*

#Credit: হাসিন ইশরাক ত্বোয়াহা (Constant T), SSC '25
ঘুছিয়ে লিখতে পারিনি, সংশোধন করে দিবেন আশাকরি।

*/
```

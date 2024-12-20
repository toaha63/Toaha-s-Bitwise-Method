/*
জীবন কতদিন জানি না, তাই পাবলিশ করে দেই, দয়াকরে কোথাও লিখলে আমাকে ক্রেডিট দিবেনঃ

শিরোনামঃ Toaha's Bitwise Method.
বিস্তারিতঃ

যদি x একটি ধনাত্মক জোড় পূর্ণসংখ্যা হয় এবং (x+1) যদি মৌলিক সংখ্যা ∪ 3 দ্বারা নিঃশেষে বিভাজ্য সংখ্যা হয়,তাহলে x ও (x+1) এর Bitwise and করলে x আসবে এবং or করলে x+1 আসবে।

সমীকরণঃ
x∈{x:x=2N,N∈N}
(x+1)∈{x:x∈P∪A}
P={2,3,5,7,11,13,17,19,23,29... ...}
A={3,6,9, 12,15,18,21... ...}

* x & (x+1) = x
* x | (x+1) = (x+1)

বিশেষ দ্রষ্টব্যঃ মৌলিক সংখ্যা ২ এর ব্যাপারটা ভিন্ন।

এই সমীকরণের প্রমাণ এই সি প্রোগ্রামঃ
*/

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

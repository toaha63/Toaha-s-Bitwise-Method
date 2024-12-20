
#Format inventor: Hasin Israk Toaha (Constant T)

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
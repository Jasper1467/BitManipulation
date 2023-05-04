#pragma once


namespace BitManipulation
{
	/*
	 * If a number N is a power of 2, then the bitwise AND of N and N-1 will be 0.
	 * But this will not work if N is 0. So just check these two conditions,
	 * if any of these two conditions is true.
	 */
	inline bool IsPowerOfTwo(const int x)
	{
		return x && (!x & (x - 1));
	}

	/*
	 * https://betterexplained.com/articles/swap-two-variables-using-xor/
	 *
	 * This method works because XOR is both commutative and associative,
	 * so a ^= b sets a to a XOR b, then b ^= a sets b to b XOR (a XOR b)
	 * (which simplifies to a) and finally a ^= b sets a to
	 * (a XOR b) XOR a (which simplifies to b).
	 */
	inline void SwapNumbers(int* a, int* b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}

	/*
	 * First, the function computes a new unsigned integer num by
	 * performing a bitwise XOR between n and n shifted to the right by one bit.
	 * This operation essentially "flips" every other bit in n,
	 * creating a new integer where adjacent bits are always different.
	 * For example, if n were originally 10101010, then num would become 01010101.
	 * Next, the function checks whether num+1 AND num is equal to zero.
	 * The & operator performs a bitwise AND operation between num+1 and num,
	 * and the result will only be zero if the two numbers have no overlapping 1 bits.
	 * If this condition is true, then it means that num has no consecutive 1 bits,
	 * which is only possible if the bits in n are in alternating order.
	 */
	inline bool BitsAreInAltOrder(const unsigned int n)
	{
		const unsigned int num = n ^ (n >> 1);
		return (((num + 1) & num) == 0);
	}

	/*
	 * The XOR operator can also be used to quickly check if two integers are equal,
	 * without having to do an explicit comparison. This can be useful in some algorithms
	 * to optimize performance. To check if two integers a and b are equal,
	 * you can simply use a ^ b == 0. If a and b are equal, the result will be 0,
	 * otherwise it will be a non-zero value.
	 */
	inline bool CompareIntegers(const int a, const int b)
	{
		return ((a ^ b) == 0);
	}

	inline int GeneratePseudoRandomNumber(const unsigned int nSeed)
	{
		int x = nSeed;
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		return x;
	}

	/*
	 * This technique is faster than using the modulo operator (%)
	 * to check for evenness or oddness, because bitwise operations
	 * are generally faster than arithmetic operations.
	 */
	inline bool IsNumberEven(const int x)
	{
		return (x & 1) == 0;
	}

	/*
	 * To check if at least one bit in an integer n is set to 1,
	 * you can use the bitwise OR operator with the value 0.
	 * If the result is 0, then none of the bits in n are set to 1,
	 * otherwise at least one bit is set.
	 * This technique is faster than checking
	 * each bit individually or using the != 0 comparison operator,
	 * because bitwise operations are generally faster than logical or arithmetic operations.
	 */
	inline bool IsAtLeastOneBitSet(const int x)
	{
		return (x | 0);
	}

	/*
	 * Counting the number of set bits in an integer can be a useful operation
	 * in some algorithms, such as Hamming distance calculations
	 * or error correction codes. There are several ways to count the
	 * number of set bits, including using lookup tables, bit manipulation tricks,
	 * or hardware instructions. Here is an example of a bit manipulation trick
	 * that counts the number of set bits in an integer.
	 * This code repeatedly clears the least significant bit of n
	 * and increments a counter until n becomes zero,
	 * effectively counting the number of set bits in n.
	 * This technique is known as the "Brian Kernighan's algorithm".
	 */
	inline int GetBitCount(const unsigned int x)
	{
		int nCount = 0;
		unsigned int nCopy = x;

		while (nCopy != 0)
		{
			nCount++;
			nCopy &= (nCopy - 1);
		}

		return nCount;
	}
}
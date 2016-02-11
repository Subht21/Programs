/*
 * utils.h
 *
 *  Created on: Feb 11, 2016
 *      Author: Subhash C Thakur
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

/*
 * Given a positive integer N, this function returns the length of its longest
 * binary gap. The function should return 0 if N doesn't contain a binary gap.
 *
 *  Assume that:
 *      N is an integer within the range [1..2,147,483,647].
 *
 *  Complexity:
 *      expected worst-case time complexity is O(log(N));
 *      expected worst-case space complexity is O(1).
 *
 *  A binary gap within a positive integer N is any maximal sequence of
 *  consecutive zeros that is surrounded by ones at both ends in the binary
 *  representation of N.
 *
 *  For example, number 9 has binary representation 1001 and contains a binary
 *  gap of length 2. The number 529 has binary representation 1000010001 and
 *  contains two binary gaps: one of length 4 and one of length 3. The number
 *  20 has binary representation 10100 and contains one binary gap of length 1.
 *  The number 15 has binary representation 1111 and has no binary gaps.
 */

int binary_gap(int N);

#endif /* UTILITIES_H_ */

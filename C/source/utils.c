/*
 * utils.c
 *
 *  Created on: Feb 11, 2016
 *      Author: Subhash C Thakur
 */

int binary_gap(int N) {
    // write your code in C99 (gcc 4.8.2)
    char binary_gap = 0;
        char binary_gap_temp = 0;
        char first1 = 0;

        /*
         * Find the first least significant 1 bit. Start counting number of zeros
         * till another 1 is hit. If new gap is greater than old, replace old with
         * new. Repeat this process till the Most Significant bit.
         *
         */
        while (N>0)
        {
            if (N%2 == 1) {
                first1 = 1;
                if(binary_gap_temp > binary_gap)
                {
                    binary_gap = binary_gap_temp;
                }
                binary_gap_temp = 0;
            } else {
                if (first1)
                    binary_gap_temp++;
            }
            N = N/2;
        }

        return(binary_gap);
}

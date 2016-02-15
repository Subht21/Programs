/*
 * utils.c
 *
 *  Created on: Feb 11, 2016
 *      Author: Subhash C Thakur
 */

#include <stdio.h>
#include <math.h>

#include "utils.h"

// A function to print all prime factors of a given number n
void prime_factors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0) {
        printf("(1)%d ", 2);
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    //int i;
    for (int i = 3; i <= sqrt(n); i = i+2) {
        // While i divides n, print i and divide n
        while (n%i == 0) {
            printf("(2)%d ", i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2)
        printf ("(3)%d ", n);
}


// Bubble Sort
void bubble_sort(int list[], int n) {
	long c, d, t;

	for (c = 0 ; c < ( n - 1 ); c++) {
		for (d = 0 ; d < n - c - 1; d++) {
			if (list[d] > list[d+1]) {
				/* Swapping */
				t         = list[d];
				list[d]   = list[d+1];
				list[d+1] = t;
			}
		}
	}
}

// Merge Sort
void merge_sort(int a[],int i,int j) {
    int mid;

    if(i<j){
        mid=(i+j)/2;
        merge_sort(a,i,mid);    //left recursion
        merge_sort(a,mid+1,j);	//right recursion
        merge(a,i,mid,mid+1,j); //merging of two sorted sub-arrays
    }
}

void merge(int a[],int i1,int j1,int i2,int j2) {
    int temp[50];	//array used for merging
    int i,j,k;
    i=i1;    		//beginning of the first list
    j=i2;    		//beginning of the second list
    k=0;

    while(i<=j1 && j<=j2) {    //while elements in both lists
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];

    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];

    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}

Impact

int get_impact(char Cval) {
    int impact = -1;
    switch (Cval) {
        case 'A': impact = 1;
            break;
        case 'C': impact = 2;
            break;
        case 'G': impact = 3;
            break;
        case 'T': impact = 4;
            break;
        default: impact = -1;
            break;
    }
    return(impact);
}

int *AI;

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 4.8.2)
    
    // Get the miminum possible impact from *S;
    int sidx = 0;
    int min_impact = 1;

    int tmp_impact = get_impact(S[sidx]);
    while (1) {
        if (S[sidx] == '\0')
            break;
        if (1 <= tmp_impact && tmp_impact <= 4) {
            if (tmp_impact < min_impact) {
                min_impact = tmp_impact;
            }
        } else {
            break;
        }
        sidx++;
    }

    AI = malloc(sizeof(int)*M);
    
    int pval, qval, kidx;
    for (kidx=0; kidx<M; kidx++) {
        pval = P[kidx];
        qval = Q[kidx];
        
        int impact = 9999;
        for (sidx=pval; sidx<=qval; sidx++) {
            // Find the minimum impact.
            int tmpimp = get_impact(S[sidx]);
            if (tmpimp < impact) impact = tmpimp;
            // Since the minimum impact possible is 1. No need to work any more.
            if (impact == min_impact) break;
        }
        AI[kidx] = impact;        
    }

    result.A = AI;
    result.M = M;
    return result;
}


Fish Eat
int solution(int A[], int B[], int N) {
    // write your code in C99 (gcc 4.8.2)
    
    int idx;
    int afish = 0;
    int eating = 0;
 
    int start, end;
    start=0; end=N-1;

    // Remove fishes thar are never going to meet.
    idx=0;
    while(B[idx]==0) {
        afish++;
        start++;
        idx++;
    }
    idx=N-1;
    while(B[idx]==1) {
        afish++;
        end--;
        idx--;
    }
        
    // Do the operation for downstream.
    for (idx=start; idx<end; idx++) { // Do for the last fish***
        if (B[idx] == 1) // DS fish
        {
            eating = 1;
            if (A[idx] > A[idx+1]) {
                B[idx+1] = 1;
            } else {
                eating = 0;
            }
        }
        if (B[idx]==0 && eating==0) {
            afish++;
        }
    }
    //afish++; // Last fish.
    if (B[idx]==0 && eating==0) {
        afish++;
    }
    return(afish);
}


Demo Test 

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    
    int eqi = -1;

    // Empty input array.
    if (N==0) return(eqi);
    
    double sum = 0;
    
    for (int idx=0; idx<N; idx++) {
        sum+=A[idx];
    }
    
    // For corner cases.
    if (sum-A[0] == 0) return(0);
    if (sum-A[N-1] == 0) return(N-1);
    
    double ls, rs;
    int pv;
    ls = 0; rs = sum-A[0]; pv = A[0];
    for (int idx=1; idx<N-1; idx++) {
        ls += pv;
        pv = A[idx];
        rs -= A[idx];

        if (ls == rs) {
            eqi = idx;
            break;
        }
    }
    
    return(eqi);
}




// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <math.h>
int *AI;

struct Results solution(int A[], int M) {
    struct Results result;
    // write your code in C99 (gcc 4.8.2)
    
    int base = -2;

    long long int inval = 0;
    for (int i=0; i<M; i++) {
        inval += A[i]*pow(base, i);
    }
    
    long long int outval = -1*inval;
    
    // At this point size of B is unknown.  So find the value of N first.
    int osl = 0;
    while (1) {
        osl++;    
        if (outval == 0) break;
        outval = outval/base;
    }
        
    AI = malloc(sizeof(int)*osl);
    // Start breaking the outval into bits.
    outval = -1*inval;
    for(int i=0; i<osl;i++) {
        AI[i] = outval%base;
        outval = outval/base;
    }
    
    result.B = AI;
    result.N = osl;
    return result;
}
#include <stdio.h>

int pair(int n[], int size, int target) {
    int hash[size];
    int complement, count = 0;
    int i;
    for (i = 0; i < size; i++) hash[i] = 0;
    
    for (i = 0; i < size; i++) {
        complement = target - n[i];
        if (hash[complement] > 0) {
            count += hash[complement];
        }
        hash[n[i]]++;
    }
    return count;
}

int main() {
    int n[] = {1, 5, 10, 20, 80};
    int size = sizeof(n) / sizeof(n[0]);
    int target = 90;
    int ans=pair(n, size, target);
    printf("%d",ans);
    return 0;
}

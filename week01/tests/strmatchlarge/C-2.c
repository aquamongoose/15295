#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char A[1000002];
char B[1000002];
int  T[1000002];

static inline int kmp() {
  int count = 0;
  {
    // Do the precomputation
    int pos = 2;
    int cnd = 0;
    T[0] = -1; T[1] = 0;
    while (B[pos]) {
      if (B[pos-1] == B[cnd]) { cnd = cnd + 1; T[pos] = cnd; pos++; }
      else if (cnd > 0) { cnd = T[cnd]; }
      else { T[pos] = 0; pos++; }
    } 
  }
  int st = 0;
  int i = 0;
  while (A[st + i]) {
    if (B[i] == A[st + i]) {
      if (!B[i+1]) {
        count++;
        i = 0;
        st = st + 1;
      } else {
        i++;
      }
    } else {
      if (T[i] > -1) { st = st + i - T[i]; i = T[i]; }
      else { i = 0; st++; }
    }
  } 
  return count;
}

static inline int count_chars() {
  char c = B[0];
  int i = 0;
  int count = 0;
  for (i = 0; A[i]; i++)
    if (A[i] == c) count++;
  return count;
}

int main() {
  scanf("%s", A);
  scanf("%s", B);
  printf("%d\n", kmp());
  return 0;
}

 

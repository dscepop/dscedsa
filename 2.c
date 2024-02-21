#include <stdio.h>

#include <string.h>

char str[50], pat[20], rep[20], ans[50];
int c = 0, m = 0, i = 0, j = 0, flag = 0;

void stringmatch() {
  while (str[c] != '\0') {
    if (str[m] == pat[i]) {
      i++;
      m++;
      if (pat[i] == '\0') {
        flag = 1;
        for (int k = 0; rep[k] != '\0'; k++, j++) {
          ans[j] = rep[k];
        }
        i = 0;
        c = m;
      }
    } else {
      ans[j] = str[c];
      j++;
      c++;
      m = c;
      i = 0;
    }
  }
  ans[j] = '\0';
}

int main() {
  printf("\nEnter the main string:");
  fgets(str, sizeof(str), stdin);
  printf("\nEnter the pat string:");
  fgets(pat, sizeof(pat), stdin);
  printf("\nEnter the replace string:");
  fgets(rep, sizeof(rep), stdin);

  // Removing newline characters from input strings
  str[strcspn(str, "\n")] = '\0';
  pat[strcspn(pat, "\n")] = '\0';
  rep[strcspn(rep, "\n")] = '\0';

  stringmatch();
  if (flag == 1)
    printf("\nResultant string is %s", ans);
  else
    printf("\nPattern string is not found");

  return 0;
}
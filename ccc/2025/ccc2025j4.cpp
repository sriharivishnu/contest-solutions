#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int a = -1, b = -1, ans = 0;
  char ch;
  for (int i = 0; i < n; ++i) {
    getchar();
    ch = getchar();
    if (ch == 'P') {
      a = b;
      b = i;
    }
    if (i - a > ans)
      ans = i - a;
  }

  if (b == -1)
    --ans;
  printf("%d\n", ans);
}

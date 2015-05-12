#include <stdio.h>

/* Лаб. работа 4
 Вариант 23
 ИВБ-3-14
 Шмидт Максим */

int main(int argc, char *argv[])
{
    
    int n;
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
    int *a;
    a = new int[n];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int f = 0, s = 0, l, r, t;
    if (n % 2 != 0) {
        t = ((n - 1) / 2);
        s = a[t];
        l = t - 1;
        r = t + 1;
        bool flag = false;
        while (!flag) {
            if (a[l] > a[r]) {
                f += a[l];
                s += a[r];
            } else {
                f += a[r];
                s += a[l];
            }
            l--;
            r++;
            if (l == 0 || r == n) {
                flag = true;
            }
        }
    } else {
        l = (n - 1) / 2;
        r = l + 1;
        bool flag = false;
        while (!flag) {
            if (a[l] > a[r]) {
                f += a[l];
                s += a[r];
            } else {
                f += a[r];
                s += a[l];
            }
            l--;
            r++;
            if (l == 0 || r == n) {
                flag = true;
            }
        }
    }
    if (f > s)
        printf("1");
    if (f < s)
        printf("2");
    if (f == s)
        printf("0");
}

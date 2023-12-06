#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef long long ll;
bool is_palindrome(ll n);

int main()
{
    ll n;
    scanf("%Ld", &n);
    (is_palindrome(n)) ? printf("True\n") : printf("False\n");
    return 0;
}
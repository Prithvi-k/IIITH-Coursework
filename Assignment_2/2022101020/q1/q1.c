#include <stdio.h>
#include <stdbool.h>

#define int long long int

bool is_balanced(int n, char * input);

signed main()
{
    int n;
    scanf("%lld", &n);

    char input[n+1];
    scanf("%s", input);

    bool res = is_balanced(n, input);
    if(res)printf("Balanced\n");
    else printf("Not balanced\n");

    return 0;
}
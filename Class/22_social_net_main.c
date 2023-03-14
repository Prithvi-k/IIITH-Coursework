#include "Class/22_social_net.h"

int main()
{
    SocialNet sn;   
    sn.size = 0;
    setup_ABCDE_network(&sn);
    
    print_network(&sn);

    printf("%d\n",check_degree_of_seperation(&(sn.members[0]), &(sn.members[1]), 3));

    
    return 0;
}

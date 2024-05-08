/*
    Made by latas_dev,
    on a boring tuesday afternoon.
*/

// 07/05/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"

int main(void)
{   
    User *pedro     = newUser("Pedro");
    User *andres    = newUser("Andres");

    newMessage(pedro, andres);
    newMessage(andres, pedro);
    newMessage(pedro, andres);

    printMessageList(pedro);
    
    // dealloc
    freeUser(pedro);
    freeUser(andres);

    return 0;
}
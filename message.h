#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

typedef struct User User;
typedef struct Message Message;

struct User
{
    char    *name;
    size_t  nMessages;
    Message **messageList;

};

struct Message {
    User *sender;
    User *receiver;

    char *body;
};

// Struct Functions

void freeUser(User *user);
User *newUser(char *name);
void newMessage(User *sender, User *receiver);
void addToMessageList(Message *message);
Message *createMessage(User *sender, User *receiver);

// DEBUG UTILITIES

void printMessageList(User *user);
void printMessage(Message *message);
char *inputMessage();

#endif
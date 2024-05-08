#include "message.h"

void freeUser(User *user)
{
    size_t nMessages        = user->nMessages;
    Message **messageList   = user->messageList;

    for (int i = 0; i < nMessages; ++i)
    {
        if (messageList[i] == NULL) // message has already been freed
            continue;
        
        free(messageList[i]->body);
        free(messageList[i]);
    }
    free(messageList);

    free(user->name);
    free(user);
}

User *newUser(char *name)
{
    User *user = (User *)malloc(sizeof(User));
    
    size_t len = strlen(name);
    user->name = (char *)malloc((len + 1) * sizeof(char));
    strcpy(user->name, name);

    size_t nMessages = 0;
    user->nMessages  = nMessages;

    Message **messages = (Message **)malloc(sizeof(Message *) * nMessages);
    user->messageList = messages;

    return user;
}

void newMessage(User *sender, User *receiver)
{
    Message *message = createMessage(sender, receiver);
    addToMessageList(message);
}

void addToMessageList(Message *message)
{
    User *sender    = message->sender;
    User *receiver  = message->receiver;

    sender->nMessages++;
    receiver->nMessages++;

    sender->messageList = (Message **)realloc(sender->messageList, sizeof(Message *) * sender->nMessages);
    receiver->messageList = (Message **)realloc(receiver->messageList, sizeof(Message *) * receiver->nMessages);

    if (sender->messageList && receiver->messageList) 
    {
        sender->messageList[sender->nMessages -1] = message;
        receiver->messageList[receiver->nMessages -1] = message;
    } else 
    {
        printf("Memory Allocation Failed");
        // TODO:
        // MANAGE ERROR
    }
}

Message *createMessage(User *sender, User *receiver)
{
    Message *message    = (Message *)malloc(sizeof(Message));
    message->body       = inputMessage();

    message->sender     = sender;   
    message->receiver   = receiver;
    
    return message;
}

// DEBUG UTILITIES

void printMessageList(User *user)
{
    size_t nMessages        = user->nMessages;
    Message **messageList   = user->messageList;
    
    system("cls");
    for (size_t i = 0; i < nMessages; ++i)
    {
        printf("Message #%i\n", i + 1);
        printMessage(messageList[i]);
        printf("\n");
    }
}

void printMessage(Message *message)
{
    // I don't know why i just can't:
    //      message->sender->name
    User *sender    = message->sender;
    User *receiver  = message->receiver;

    printf("%s to: %s\n", sender->name, receiver->name);
    printf("%s\n", message->body);
}

char *inputMessage()
{
    char    buffer[BUFFER_SIZE];
    char   *message;
    size_t  len;

    printf("Type your message below:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // flush the last '\n'

    len = strlen(buffer);
    message = (char *)malloc((len + 1) * sizeof(char));
    strcpy(message, buffer);

    system("cls");

    return message;
}
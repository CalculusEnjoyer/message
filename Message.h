#ifndef DZ2004_MESSAGE_H
#define DZ2004_MESSAGE_H

#include <iostream>
#include <wchar.h>
#include <chrono>

class Message{
private:
    bool isEdited= false;
    bool isDeleted=false;
    time_t wroteTime;
    Message* reply= nullptr;
    Message* comment= nullptr;
    wchar_t text[280];
public:
    Message(){ wroteTime=time(0);}
    Message(wchar_t* text);
    void addReply(Message reply);
    void addComment(Message comment);
    wchar_t* getText();
    void settext(wchar_t* text);
    Message* getReply(unsigned int number);
    Message* getComment(unsigned int number);
    bool editMessage(wchar_t* text);
    bool deleteMessage();
    bool getIsEdited();
};

void convertToWchar(char* input, wchar_t * result);
#endif //DZ2004_MESSAGE_H

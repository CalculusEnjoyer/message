#include "Message.h"

Message::Message(wchar_t* text) {
    wroteTime = time(0);
    wcscpy(this->text,text);
}

void Message::addReply(Message reply) {
    Message* copy;
    copy=this;
    Message* copyofptr=this->reply;
    while(copyofptr!=nullptr){
        copy=copyofptr;
        copyofptr=copyofptr->reply;
    }
    copy->reply = new Message(reply.getText());
}

void Message::addComment(Message comment) {
    Message* copy;
    copy=this;
    Message* copyofptr=this->comment;
    while(copyofptr!=nullptr){
        copy=copyofptr;
        copyofptr=copyofptr->reply;
    }
    copy->comment = new Message(comment.getText());
}

wchar_t* Message::getText() {
    if(!isDeleted) {
        return text;
    }else{
        return L"This message was deleted";
    }
}

void Message::settext(wchar_t* text) {
    wcscpy(this->text,text);
}

Message* Message::getComment(unsigned int number) {
    if(number==0) return this;
    else{
        Message* copy=this;
        for(int i=0;i<number;i++){
            copy=copy->comment;
            if(copy== nullptr) throw std::logic_error("There are less comments then N");
        }
        return copy;
    }
}

Message* Message::getReply(unsigned int number) {
    if(number==0) return this;
    else{
        Message* copy=this;
        for(int i=0;i<number;i++){
            copy=copy->reply;
            if(copy== nullptr) throw std::logic_error("There are less replies then N");
        }
        return copy;
    }
}

bool Message::editMessage(wchar_t* text) {
    if(difftime(time(0), wroteTime) < 60){
        isEdited=true;
        wcscpy(this->text,text);
    }else return false;
}

bool Message::deleteMessage() {
    if(!isDeleted) {
        isDeleted = true;
    }else return false;
}

bool Message::getIsEdited() {
    return isEdited;
}

void convertToWchar(char* input,wchar_t* result) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] < 127) result[i]=input[i];
        else if (191<input[i]&&input[i]<256) {
            result[i]=input[i]+848;
        }else if(input[i]==191){
            result[i]=1111;
        }else if(input[i]==179){
            result[i]=1110;
        }else if(input[i]==178){
            result[i]=1030;
        }else if(input[i]==175){
            result[i]=1031;
        }else if(input[i]==186){
            result[i]=1108;
        }else if(input[i]==170){
            result[i]=1028;
        }else if(input[i]==180){
            result[i]=1169;
        }else result[i]=input[i];
        i++;
    }
}


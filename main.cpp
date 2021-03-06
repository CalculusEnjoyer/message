#include "Message.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    wchar_t mainm[280],rep1[280],rep2[280],rep3[280],edit[280];
    cout<<"Text main message:"<<endl;
    wcin.getline(mainm,280);
    cout<<"Text first reply:"<<endl;
    wcin.getline(rep1,280);
    cout<<"Text second reply:"<<endl;
    wcin.getline(rep2,280);
    cout<<"Text third reply:"<<endl;
    wcin.getline(rep3,280);
    Message mainM(mainm);
    Message reply1(rep1);
    Message reply2(rep2);
    Message reply3(rep3);
    mainM.addReply(reply1);
    mainM.addReply(reply2);
    mainM.addReply(reply3);
    cout<<"Main message:"<<endl;
    setlocale(LC_ALL, "");
    wcout<<mainM.getText()<<endl;
    int n;
    cout<<"Enter a sequence number of a reply to display:"<<endl;
    cin>>n;
    cin.ignore();
    cout<<"Reply №"<<n<<":"<<endl;
    setlocale(LC_ALL, "");
    wcout<<(*mainM.getReply(n)).getText()<<endl;
    cout<<"Enter new text to edit reply:"<<endl;
    wcin.getline(edit,280);
    if((*mainM.getReply(n)).editMessage(edit)) {
        cout << "Edited reply №" << n << ":" << endl;
        setlocale(LC_ALL, "");
        wcout << (*mainM.getReply(n)).getText() << endl;
    }else cout<<"Time for editing that message has expired"<<endl;
    cout<<"Press Y to delete this message:"<<endl;
    string answer;
    cin>>answer;
    if(answer=="Y"||answer=="y") {
        (*mainM.getReply(n)).deleteMessage();
        wcout << (*mainM.getReply(n)).getText() << endl;
    }
}


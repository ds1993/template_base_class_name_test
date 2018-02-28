#include <stdio.h>
#include <iostream>
#include <string>

class CompanyA {
public:
    void sendCleartext();
    void sendEncrypted();
};

class CompanyB {
public:
    void sendCleartext();
    void sendEncrypted();
};

template<typename Company>
class MsgSender {
public:
    void sendClear();
    void sendSecret();
};

template<typename Company>
class LoggingMsgSender: public MsgSender<Company> {
public:
    using MsgSender<Company>::sendClear;
    using MsgSender<Company>::sendSecret;
    void sendClearMsg();
    void sendSecretMsg();
};

void CompanyA::sendCleartext()
{
    printf("sendCleartext for CompanyA\n");
}

void CompanyA::sendEncrypted()
{
    printf("sendEncrypted for CompanyA\n");
}

void CompanyB::sendCleartext()
{
    printf("sendCleartext for CompanyB\n");
}

void CompanyB::sendEncrypted()
{
    printf("sendEncrypted for CompanyB\n");
}

template<typename Company>
void MsgSender<Company>::sendClear()
{
    Company c;
    c.sendCleartext();
}

template<typename Company>
void MsgSender<Company>::sendSecret()
{
    Company c;
    c.sendEncrypted();
}

template<typename Company>
void LoggingMsgSender<Company>::sendClearMsg()
{
    sendClear();
    //this->sendClear();
}

template<typename Company>
void LoggingMsgSender<Company>::sendSecretMsg()
{
    sendSecret();
    //this->sendSecret();
}

int main()
{
    LoggingMsgSender<CompanyA> msgA;
    msgA.sendClearMsg();
}

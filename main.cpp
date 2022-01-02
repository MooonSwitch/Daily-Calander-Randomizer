// 1 is School
// 2 is Engineering
// 3 is Coding
// 4 is Japanese
// 5 is Music

// noteworthy parts:
// use of std::count
// class usage
// -Tristen

#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "schedulebot_func.h"

int main()
{
    timeClass timeC;
    botProcedures resp;
    srand(time(NULL));
    std::string inp;
    //                                      additional setup
    {
        std::cout << "To exit the conversation, please enter `!\n";
        int first = std::rand() % 2 + 4;
        int second = std::rand() % 1 + 4;
        int third = std::rand() % 1 + 3;
        int fourth = std::rand() % 1 + 3;
        int fifth = std::rand() % 1 + 2;
        timeC.setLengths(first, second, third, fourth, fifth);
        timeC.setInitialTime(timeStartFunc(0));
        timeC.setInitialTime(timeStartFunc(1));
        timeC.setMinutesAndHours();
        timeC.setTimeStamp();
        resp.setGreeting();
        std::vector<std::string> transfer = { "", "", "", "", "", "" };
        for (int x = 0; x < 6; x++) {
            transfer[x] = timeC.getTimeStamps(x);
            resp.setFinalTime(transfer[x], x);
        }
    }

    do {
        std::cout << resp.getResp() << " >";
        std::cin >> inp;
        resp.expectInputGate(lowercase(inp));
    } while (inp != "`");

    return 0;
}
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "schedulebot_func.h"

//class scheduleSubRecord
std::string scheduleSubRecord::intToSub(int x) {
    switch (x) {
    case 0:
        return "case 0???";
        break;
    case 1:
        return "Art";
        break;
    case 2:
        return "Engineering";
        break;
    case 3:
        return "Coding";
        break;
    case 4:
        return "Japanese";
        break;
    case 5:
        return "Music";
        break;
    case 6:
        return "case 6???";
        break;
    default:
        return "ooops intToString\n";
        break;
    }
};
void scheduleSubRecord::setSubs(int a, int b, int c, int d, int e) {
        firstSub = intToSub(a);
        secondSub = intToSub(b);
        thirdSub = intToSub(c);
        fourthSub = intToSub(d);
        fifthSub = intToSub(e);
};
std::string scheduleSubRecord::getSub(int x) {
        switch (x) {
        case 1:
            return firstSub;
            break;
        case 2:
            return secondSub;
            break;
        case 3:
            return thirdSub;
            break;
        case 4:
            return fourthSub;
            break;
        case 5:
            return fifthSub;
            break;
        default:
            return "please input a number between 1 and 5!";
            break;
        }
    };
void timeClass::setLengths(int a, int b, int c, int d, int e) {
    lengths[0] = a;
    lengths[1] = b;
    lengths[2] = c;
    lengths[3] = d;
    lengths[4] = e;
}

//class timeClass
//                                      Sets vectors for minutes and hours
void timeClass::setMinutesAndHours() {
        for (int x = 1; x < 6; x++) {
            switch (lengths[x - 1]) {
            case 1:
                if (minutes[x - 1] == 30) {
                    minutes[x] = 0;
                    hours[x] = hours[x - 1] + 1;
                }
                else {
                    minutes[x] = 30;
                }
                if (hours[x] > 12) {
                    hours[x] = hours[x] - 12;
                }
                break;
            case 2:
                hours[x] = hours[x - 1] + 1;
                if (hours[x] > 12) {
                    hours[x] = hours[x] - 12;
                }
                break;
            case 3:
                if (minutes[x - 1] == 30) {
                    minutes[x] = 0;
                    hours[x] = hours[x - 1] + 2;
                }
                else {
                    minutes[x] = 30;
                    hours[x] = hours[x - 1] + 1;
                }
                if (hours[x] > 12) {
                    hours[x] = hours[x] - 12;
                }
                break;
            case 4:
                hours[x] = hours[x - 1] + 2;
                if (hours[x] > 12) {
                    hours[x] = hours[x] - 12;
                }
                break;
            case 5:
                if (minutes[x - 1] == 30) {
                    minutes[x] = 0;
                    hours[x] = hours[x - 1] + 3;
                }
                else {
                    minutes[x] = 30;
                    hours[x] = hours[x - 1] + 2;
                }
                if (hours[x] > 12) {
                    hours[x] = hours[x] - 12;
                }
                break;
            case 6:
                hours[x] = hours[x - 1] + 3;
                if (hours[x] > 12) {
                    hours[x] = hours[x] - 12;
                }
                break;
            default:
                break;
            }
        }
    }
void timeClass::setTimeStamp() {
        for (int x = 0; x < 6; x++) {
            std::string h = std::to_string(hours[x]);
            std::string m;
            if (minutes[x] == 0) {
                m = "00";
            }
            else {
                m = "30";
            }
            std::string t;
            t = h + ":" + m;
            timeStamps[x] = t;
        }
    }
//                                  Set inital relativeHour and relativeMinute
void timeClass::setInitialTime(int x) {
        if (x == 30 || x == 0) {
            minutes[0] = x;
        }
        else {
            hours[0] = x;
        }
    }
std::string timeClass::getTimeStamps(int x) {
        return timeStamps[x];
    }

//class botProcedures
void botProcedures::setGreeting() {
        time_t now = time(0);
        tm localTime;
        now = time(NULL);
        localtime_s(&localTime, &now);
        std::string today;
        switch ((&localTime)->tm_wday) {
        case 0:
            today = "Sunday";
            break;
        case 1:
            today = "Monday";
            break;
        case 2:
            today = "Tuesday";
            break;
        case 3:
            today = "Wednesday";
            break;
        case 4:
            today = "Thursday";
            break;
        case 5:
            today = "Friday";
            break;
        case 6:
            today = "Saturday";
            break;
        };
        greeting = "Hello, and happy " + today + "!\n";
    };
//                                          sees if your response matches what is expected
bool botProcedures::isCorrect(std::vector<std::string> list, std::string resp) {
        if (std::count(list.begin(), list.end(), resp)) {
            return true;
        }
        else {
            return false;
        }
    }
//                                          updates conversation progress
void botProcedures::expectInputGate(std::string inp) {
        switch (convProgress) {
        case 0:
            if (isCorrect(greetingList, inp)) {
                convProgress++;
                break;
            }
        case 1:
            if (isCorrect(topicOfInt, inp)) {
                schedOrder(inp);
                setFinalOutput();
                convProgress++;
                break;
            }
            break;
        case 2:
            std::cout << "oopsies got 2 in expectInputGate";
            break;
        default:
            std::cout << "ruh roh expectInputGate\n";
            break;
        }
    }
//                                          function that outputs responses
std::string botProcedures::getResp() {
        switch (convProgress) {
        case 0:
            return greeting;
            break;
        case 1:
            return topicChoice;
            break;
        case 2:
            return finalOutput;
            break;
        default:
            return goodbye;
            break;
        };
    };
//                                          Sets up subject order from input
void botProcedures::orderSubs(int priority) {
        std::vector<int> vec = { priority, 6, 6, 6, 6 };
        for (int x = 1; x < 5; x++) {
            int r = std::rand() % 5 + 1;
            if (std::count(vec.begin() + 1, vec.end(), r)) {
                x--;
            }
            else if (priority == r) {
                x--;
            }
            else {
                vec[x] = r;
            }
        };
        scheduleSubRecord::setSubs(vec[0], vec[1], vec[2], vec[3], vec[4]);
    }
//                                      Quick function between orderSubs ^^^ and setFinalSchedTop vvvv
void botProcedures::schedOrder(std::string t) {
        orderSubs(stoi(t));
        setFinalSchedTop(getSub(1), getSub(2), getSub(3), getSub(4), getSub(5));
    }
//                                      Gives string finalSchedTop a value
void botProcedures::setFinalSchedTop(std::string a, std::string b, std::string c, std::string d, std::string e) {
        finalSchedTop = { a, b, c, d, e };
    }
void botProcedures::setFinalTime(std::string x, int y) {
        finalTime[y] = x;
    }
void botProcedures::setFinalOutput() {
        for (int x = 1; x <= 5; x++) {
            finalOutput = finalOutput + finalSchedTop[x - 1] + " -> " + finalTime[x - 1] + " - " + finalTime[x] + '\n';
        }
    }

//                                      function that records initial time
int timeStartFunc(int x) {
    timeClass timeC;
    time_t now = time(0);
    tm localTime;
    now = time(NULL);
    localtime_s(&localTime, &now);
    int localHours = (&localTime)->tm_hour;
    int localMinutes = (&localTime)->tm_min;
    if (localMinutes <= 30) {
        localMinutes = 30;
    }
    else {
        localMinutes = 00;
        localHours++;
    }
    if (localHours > 12) {
        localHours = localHours - 12;
    }
    if (x == 0) {
        return localHours;
    }
    else {
        return localMinutes;
    }
}

//                                      function to change input to lowercase for easier translation
std::string lowercase(std::string word)
{
    int x = 0;
    do {
        word[x] = tolower(word[x]);
        x++;
    } while (x <= word.length());

    return word;
}
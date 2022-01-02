#pragma once
#include <iostream>
#include <string>

class scheduleSubRecord {
private:
	std::string firstSub;
	std::string secondSub;
	std::string thirdSub;
	std::string fourthSub;
	std::string fifthSub;
	std::string intToSub(int x);
public:
	void setSubs(int a, int b, int c, int d, int e);
	std::string getSub(int x);
};

class timeClass {
private:
	std::vector<int> hours{ 0, 0, 0, 0, 0, 0 };
	std::vector<int> minutes{ 0, 0, 0, 0, 0, 0 };
	std::vector<int> lengths{ 0, 0, 0, 0, 0 };
	std::vector<std::string> timeStamps = { "", "", "", "", "", "" };
	int relativeHour;
	int relativeMinute;
public:
	void setLengths(int a, int b, int c, int d, int e);
	void setMinutesAndHours();
	void setTimeStamp();
	void setInitialTime(int x);
	std::string getTimeStamps(int x);
};

class botProcedures : public scheduleSubRecord, public timeClass {
private:
	int convProgress = 0;
	std::vector<std::string> greetingList = { "hello", "hi", "aloha" , "hey" };
	std::vector<std::string> topicOfInt = { "1", "2", "3", "4", "5", "art", "engineering", "coding", "japanese", "music" };
	std::string greeting;
	std::string topicChoice = "Which topic would you like to focus on today?\n1)Art\n2)Engineering\n3)Coding\n4)Japanese\n5)Music\n";
	std::vector<std::string> finalSchedTop = { "", "", "", "", "", "" };
	std::vector<std::string> finalTime = { "", "", "", "", "", "" };
	std::string finalOutput;
	std::string goodbye = "Goodbye!\n";
	std::string lastResort = "Ruh Roh private_botProcedures";
public:
	void setGreeting();
	bool isCorrect(std::vector<std::string> list, std::string resp);
	void expectInputGate(std::string inp);
	std::string getResp();
	void orderSubs(int priority);
	void schedOrder(std::string t);
	void setFinalSchedTop(std::string a, std::string b, std::string c, std::string d, std::string e);
	void setFinalTime(std::string x, int y);
	void setFinalOutput();
};

int timeStartFunc(int x);

std::string lowercase(std::string word);
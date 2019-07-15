#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <mysql/mysql.h>

#define HOST "204.152.211.39"
#define USER "bsimsekc_obw"
#define PASSWD "e3obw123**"
#define DB "bsimsekc_obw"

using std::string;
using std::map;

class Benchy
{
	private:
	// Holds the time durations for various operations tested
	// key, time value
	map<string, double> timings;

	string schemeID = "0";
	string schemeName = "0";
	string schemeZip;

	MYSQL *connection, mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	int query_state;

	public:
	// Constructor
	Benchy(){};

	// Destructor
	~Benchy(){};

	bool initDB();

	bool fetchNextScheme();

	bool sendToDB(string value);

	void addTiming(string key, double value);

	void messageLn(string value);

	string jsonify();

	bool writeToFile(string value, string fileName);
};

#include "benchy-jr.h"

void Benchy::messageLn(string value) {
	std::cout << "## " << value << '\n';
}

void Benchy::addTiming(string key, double value) {
	Benchy::timings.insert({key, value});
}

string Benchy::jsonify() {

	string json = "{";

	json = json + "'schemeID': '";
	json = json + Benchy::schemeID;
	json = json + "'}{";

	for (auto& t : Benchy::timings){
	    json = json + "'";
	    json = json + t.first;
            json = json + "':'";
	    json = json + std::to_string(t.second);
            json = json + "',";
	}

	json = json + "}";


	return json;
}

bool Benchy::writeToFile(string value, string fileName) {

	Benchy::messageLn("Finished benchmarking, writing to " + fileName);
	std::ofstream myfile;
	myfile.open("../tests/user/extern/benchmark/" + fileName, std::ios::trunc);
	myfile << value;
	myfile.close();

	return 1;
}

bool Benchy::initDB() {

	//initialize database connection
	mysql_init(&mysql);

	// the three zeros are: Which port to connect to, which socket to connect to
	// and what client flags to use.  unless you're changing the defaults you only need to put 0 here
	connection = mysql_real_connect(&mysql,HOST,USER,PASSWD,DB,0,0,0);
	// Report error if failed to connect to database
	if (connection == NULL) {
		std::cout << mysql_error(&mysql) << '\n';
		mysql_close(&mysql);
		throw "Database connection problem";

	} else {
		Benchy::messageLn("Database connection works...");
		return 1;

	}
}

bool Benchy::fetchNextScheme() {

	// Send query to database
	query_state = mysql_query(connection,
	"SELECT DISTINCT schemes.id, schemes.title, schemes.attached_files, queue.processed FROM schemes INNER JOIN queue on schemes.id = queue.scheme_id WHERE queue.processed = '0' ORDER BY queue.updated_at ASC"
	);

	// Store results
	result = mysql_store_result(connection);

	// Get the first one in the list
	while ( ( row = mysql_fetch_row(result)) != NULL ) {
		Benchy::schemeID = row[0];
		Benchy::schemeName = row[1];
		Benchy::schemeZip = row[2];

		break;
	}

	mysql_close(&mysql);

	if(std::stoi(Benchy::schemeID) == 0){
		throw "There are no schemes in the queue!";

	} else {
		Benchy::messageLn("There are schemes in the queue...");
		Benchy::messageLn("Now benchmarking " + Benchy::schemeName + "...");
		return 1;
	}

}

bool Benchy::sendToDB(string value) {

	//Send query to database
	query_state = mysql_query(connection, "select * from pinDays");
	mysql_close(&mysql);
	return 1;

}

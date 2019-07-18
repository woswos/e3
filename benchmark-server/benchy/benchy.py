import os
import mysql.connector
import json

def main():

    # In microseconds
    # 10000000 microseconds = 1 seconds
    gateTestDuration = 100
    circuitTestDuration = 100

    # MySQL DB details
    mydb = mysql.connector.connect(
      host="204.152.211.39",
      user="bsimsekc_obw",
      passwd="e3obw123**",
      database="bsimsekc_obw"
    )

    queue = queryNextScheme(mydb)

    if(queue):
        schemeID  = queue[0][0]
        schemeZip = queue[0][1]
        queueID   = queue[0][3]

        prepareNextScheme(schemeZip)

        runBenchmark(gateTestDuration, circuitTestDuration)

        results = getResults()

        uploadResults(mydb, queueID, schemeID, results)

    else:
        print("There is no scheme waiting in the queue")



def queryNextScheme(mydb):
    mycursor = mydb.cursor()

    try:
        query = """SELECT DISTINCT benchmarks.scheme_id, benchmarks.attached_files,
                            queue.processed, queue.id FROM benchmarks
                            INNER JOIN queue on benchmarks.scheme_id = queue.scheme_id
                            WHERE queue.processed = '0' ORDER BY queue.updated_at ASC"""

        mycursor.execute(query)

        myresult = mycursor.fetchall()

        return myresult

    except:
        print("Database connection error")


def uploadResults(mydb, queueID, schemeID, results):

    try:
        mycursor = mydb.cursor()

        query = "UPDATE benchmarks SET speed = '" + results + "' where scheme_id = '" + schemeID + "'"
        mycursor.execute(query)

        query = "UPDATE queue SET processed = '1' where id = '" + str(queueID) + "'"
        mycursor.execute(query)

        print("Updated database...")

    except:
        print("Database connection error")


def prepareNextScheme(schemeZip):
    removeTempFolder()
    fetchNextScheme(schemeZip)
    unZip(schemeZip)
    fixNestedFolders()
    moveCipherbit()


def removeTempFolder():
    command = 'rm -rf temp'
    os.system(command)


def fetchNextScheme(schemeZip):
    command = 'wget http://obw.barkin.io/storage/attached_files_benchmark/' + schemeZip
    os.system(command)


def unZip(schemeZip):
    command = 'unzip ' + schemeZip + ' -d temp && rm -rf ' + schemeZip
    os.system(command)


def fixNestedFolders():
    directory = os.listdir('temp')

    # If there is only one folder, move contents of that folder to the parent folder,
    #   including the hidden files
    if((len(directory) == 1) and (os.path.isdir('temp/' + directory[0]))):
        command = 'cd temp/' + directory[0] + ' && find . -maxdepth 1 -exec mv {} .. \; && cd .. && rm -rf ' + directory[0]
        os.system(command)
        print('Moved contents of ' + directory[0] + ' to temp')


def createEvalKey():
    command = 'cd ../../.. && cd src && rm eval.key'
    os.system(command)

    command = 'cd ../../.. && cd src && touch eval.key'
    os.system(command)


def moveCipherbit():
    command = 'rm cipherbit.h && rm cipherbit.cpp && cd temp && mv cipherbit.h .. && mv cipherbit.cpp ..'
    os.system(command)


def runBenchmark(gate_time, circuit_time):
    createEvalKey()
    # add make clean remove_before_flight
    command = 'cd ../../.. && cd src && make USER=../tests/user/extern && ./bob.exe ' + str(gate_time) + ' ' + str(circuit_time)
    os.system(command)
    fixStrings()


def fixStrings():
    f = open("benchmark_result.txt")
    s = f.read()
    s = s.replace("'", '"')
    s = s.replace(",}", "}")
    f.close()

    f = open("benchmark_result.txt","w")
    f.write(s)
    f.close()


def getResults():
    print('Reading file...\n')
    f = open('benchmark_result.txt', 'r')
    print('Results...')
    reading = f.read()
    print(reading + '\n')
    return reading


if __name__ == '__main__':
    main()

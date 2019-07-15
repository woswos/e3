import os
import mysql.connector

def main():

    queue = queryNextScheme()
    schemeID    = queue[0][0]
    schemeTitle = queue[0][1]
    schemeZip   = queue[0][2]

    schemeZip = "bootstrap-tagsinput-latest_1563099663.zip"

    #prepareNextScheme(schemeZip)

    runBenchmark()

    showResults()

def queryNextScheme():
    mydb = mysql.connector.connect(
      host="204.152.211.39",
      user="bsimsekc_obw",
      passwd="e3obw123**",
      database="bsimsekc_obw"
    )

    mycursor = mydb.cursor()

    mycursor.execute("""SELECT DISTINCT schemes.id,
                        schemes.title, schemes.attached_files,
                        queue.processed FROM schemes
                        INNER JOIN queue on schemes.id = queue.scheme_id
                        WHERE queue.processed = '0' ORDER BY queue.updated_at ASC""")

    myresult = mycursor.fetchall()

    return myresult

def prepareNextScheme(schemeZip):
    removeTempFolder()
    fetchNextScheme(schemeZip)
    unZip(schemeZip)
    fixNestedFolders()


def removeTempFolder():
    command = 'rm -rf temp'
    os.system(command)


def fetchNextScheme(schemeZip):
    command = 'wget http://obw.barkin.io/storage/attached_files_implementation/' + schemeZip
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


def runBenchmark():
    command = 'cd ../../.. && cd src && make USER=../tests/user/extern && ./bob.exe'
    os.system(command)


def showResults():
    print('Reading file...')
    f = open('benchmark_result.txt', 'r')

    print('Results...')
    print(f.read())


if __name__ == '__main__':
    main()

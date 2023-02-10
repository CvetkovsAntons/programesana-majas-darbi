#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <conio.h>

using namespace std;

fstream file;
// funkcija, kas atver failu prieks lasisanas
bool openFileForReading(const string& filename) {
    file.open(filename, ios::in);

    if (!file.is_open()) {    // ja fails neekiste tad izvadam kludu
        system("CLS");

        cout << "!!! CRITICAL ERROR !!!" << endl;
        cout << "Couldn't open file " << filename << " for reading. Probably it is missing!" << endl;

        system("pause");

        file.close();

        return false;
    }

    return true;
}
// funkcija, kas atver failu prieks ierakstes
bool openFileForAppend(const string& filename) {
    file.open(filename, ios::app);

    if (!file.is_open()) {    // ja fails neekiste tad izvadam kludu
        system("CLS");

        cout << "!!! CRITICAL ERROR !!!" << endl;
        cout << "Couldn't open file " << filename << " for writing. Probably it is missing!" << endl;

        system("pause");

        file.close();

        return false;
    }

    return true;
}

void goBack() {
    cout << "-----------------------------------------------------" << endl;
    cout << "Press any button to return to the main menu!";
    system("pause > nul");
    cout << endl;
}
// funkcija, kas nolasa DB datus
vector<clientData> readData() {
    string line;
    vector<clientData> clientsArray;
    clientData clients{};

    while (getline(file, line)) {
        istringstream lineStream(line);
        string item;

        getline(lineStream, item, ',');
        stringstream accNum(item);
        accNum >> clients.accNum;

        getline(lineStream, item, ',');
        stringstream sur(item);
        sur >> clients.Sur;

        getline(lineStream, item, ',');
        stringstream name(item);
        name >> clients.Name;

        getline(lineStream, item, ',');
        stringstream balance(item);
        balance >> clients.balance;

        clientsArray.push_back(clients);
    }

    return clientsArray;
}
// funkcija, kas parbauda vai lietotajs eksiste
clientData checkIfClientExists(int id, const vector<clientData>& clients, int type) {
    clientData findClient{};

    int match = 0;

    while (match < 1) { // cikls izpildisies, kamer nebus atrasts leitotajs
        for (auto & client : clients) {
            if (id == client.accNum) { // ja lietotajs eksiste, tad pievienojam to datus struct mainigajam un partraucam for cikla darbibu
                findClient.accNum = client.accNum;
                strcpy(findClient.Sur, client.Sur);
                strcpy(findClient.Name, client.Name);
                findClient.balance = client.balance;

                match+=1;
                break;
            }
        }

        if (match < 1) { // ja nav atrast lietotajs, tad izvadam kludu un pieprasam lietotaju ievadit jaunu id
            system("CLS");

            cout << "ERROR! The user with the Account Number '" << id << "' doesn't exist!" << endl;

            system("pause");

            if (type == 1) {
                id = inputAccountNumberError(inputAccountNumber());
            }

            if (type == 2) {
                id = changeBalanceAccountNumberError(changeBalanceAccountNumber());
            }

            if (type == 3) {
                id = inputDeleteAccountNumberError(inputDeleteAccountNumber());
            }
        }
    }

    return findClient;
}
// funkcija, kas pievieno lietotaju
void addData() {
    clientData newClient{};

    system("CLS");

    vector<clientData> clients = readData();

    if (clients.empty()) {
        newClient.accNum = 1;
    } else {
        newClient.accNum = clients.back().accNum + 1;
    }

    cout << "-----------------------------------------------------" << endl;
    cout << "                 New client creation                 " << endl;
    cout << "-----------------------------------------------------" << endl;

    string Sur;
    cout << "Surname:";
    cin >> Sur;
    strcpy(newClient.Sur, Sur.c_str());

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "                 New client creation                 " << endl;
    cout << "-----------------------------------------------------" << endl;

    string Name;
    cout << "Name:";
    cin >> Name;
    strcpy(newClient.Name, Name.c_str());

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "                 New client creation                 " << endl;
    cout << "-----------------------------------------------------" << endl;

    newClient.balance = balanceInputError(balanceInput());

    file.close();

    if (!openFileForAppend(FILENAME)) {
        return;
    }

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "                 New client creation                 " << endl;
    cout << "-----------------------------------------------------" << endl;

    file << "\n" << newClient.accNum << "," << newClient.Sur << "," << newClient.Name << "," << newClient.balance;

    cout << "-----------------------------------------------------" << endl;
    cout << "New client has been added to the database!" << endl;

    goBack();

    file.close();
}
// funkcija, kas dzes lietotajus
void deleteData(int id) {
    vector<clientData> clients = readData();
    clientData client = checkIfClientExists(id, clients, 3); // parbaudam vai lietotajs eksiste un saglabajam vajadziga lietotaja datus mainigaja

    const char *copyName = "dbcopy.csv"; // saglabajam izmainas izveidojot jaunu failu

    ofstream fileCopy(copyName);

    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].accNum == id) { // ja lietotaja ID vienads ar i tad ne pievienojam to faila
            continue;
        }

        if (i == 0) {
            fileCopy << clients[i].accNum << "," << clients[i].Sur << "," << clients[i].Name << "," << clients[i].balance;
        } else {
            fileCopy << "\n" << clients[i].accNum << "," << clients[i].Sur << "," << clients[i].Name << "," << clients[i].balance;
        }
    }

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << client.Sur << " " << client.Name << " was deleted from the database" << endl;

    goBack();

    file.close();
    fileCopy.close();

    remove(FILENAME); // nodzesam originalu failu
    rename(copyName, FILENAME); // izmainam jauna faila nosaukumu
}
// funkcija, kas izvada visus lietotajus
void showData() {
    vector<clientData> clients = readData(); // saglabajma visus lietotajus masivaa

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "                Full List of Clients                 " << endl;
    cout << "-----------------------------------------------------" << endl;

    if (clients.empty()) {
        cout << "There is no clients" << endl; // ja nav klientu, tad atgriezam pazinojumu, ka klientu nav
    } else {
        cout << left << setw(20) << "Account Number"
             << left << setw(13) << "Surname"
             << left << setw(10) << "Name"
             << left << setw(13) << "Balance"
             << endl;

        cout << "-----------------------------------------------------" << endl;

        for (auto & i : clients) {
            cout << left << setw(20) << i.accNum
                 << left << setw(13) << i.Sur
                 << left << setw(10) << i.Name
                 << left << setw(13) << i.balance
                 << endl;
        }
    }

    goBack();

    file.close();
}
// funkcija, kas izvada vienu lietotaju
void findClient(int id) {
    clientData client = checkIfClientExists(id, readData(), 1); // parbaudam vai lietotajs eksiste un saglabajam vajadziga lietotaja datus mainigaja

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "           Find Client by Account Number             " << endl;
    cout << "-----------------------------------------------------" << endl;

    cout << left << setw(20) << "Account Number"
         << left << setw(13) << "Surname"
         << left << setw(10) << "Name"
         << left << setw(13) << "Balance"
         << endl;

    cout << "-----------------------------------------------------" << endl;

    cout << left << setw(20) << client.accNum
         << left << setw(13) << client.Sur
         << left << setw(10) << client.Name
         << left << setw(13) << client.balance
         << endl;

    goBack();

    file.close();
}
// funkcija, kas izmaina lietotaja balansu
void editBalance(int id) {
    vector<clientData> clients = readData();
    clientData client = checkIfClientExists(id, clients, 2); // parbaudam vai lietotajs eksiste un saglabajam vajadziga lietotaja datus mainigaja

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "               Editing Client Balance                " << endl;
    cout << "-----------------------------------------------------" << endl;

    if (increaseDecreaseBalanceError(increaseDecreaseBalance()) == 1) {
        client.balance = client.balance + increaseBalanceInputError(increaseBalanceInput()); // palielinajam balansu
    } else {
        client.balance = client.balance - decreaseBalanceInputError(decreaseBalanceInput()); // samzinam balansu
    }

    const char *copyName = "dbcopy.csv"; // saglabajam izmainas izveidojot DB kopiju ar izmainam

    ofstream fileCopy(copyName);

    for (auto & i : clients) {
        if (i.accNum == id) { // ja lietotaja ID ir vienad ar i, tad pievienojam datus no struct mainiga
            fileCopy << client.accNum << "," << client.Sur << "," << client.Name << "," << client.balance << endl;

            continue;
        }
        fileCopy << i.accNum << "," << i.Sur << "," << i.Name << "," << i.balance << endl;
    }

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << client.Sur << " " << client.Name << "s new balance is " << client.balance;

    goBack();

    file.close();
    fileCopy.close();

    remove(FILENAME); // nodzesam originalu failu
    rename(copyName, FILENAME); // izmainam jauna faila nosaukumu
}
// funkcija, kas atgriez paradnieus
void showDebtors() {
    vector<clientData> clients = readData();
    vector<clientData> debtors;

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "                       Debtors                       " << endl;
    cout << "-----------------------------------------------------" << endl;

    for (auto & client : clients) { // visus klientus, kam balanss ir mazaks par nuli pievienojam saraksta
        if (client.balance < 0) {
            debtors.push_back(client);
        }
    }

    system("CLS");

    if (debtors.empty()) { // ja nav paradnieku, tad atgrizam pazinojumu, ka paradnieku nav
        cout << "There is no debtors!" << endl;
    } else {

        cout << left << setw(20) << "Account Number"
             << left << setw(13) << "Surname"
             << left << setw(10) << "Name"
             << left << setw(13) << "Balance"
             << endl;

        cout << "-----------------------------------------------------" << endl;

        for (auto & i : debtors) {
            cout << left << setw(20) << i.accNum
                 << left << setw(13) << i.Sur
                 << left << setw(10) << i.Name
                 << left << setw(13) << i.balance
                 << endl;
        }
    }

    goBack();

    file.close();
}
// funkcija, kas izvada lietotaju skaitu
void numOfClients() {
    vector<clientData> clients = readData();

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "                 Number of Clients                   " << endl;
    cout << "-----------------------------------------------------" << endl;

    cout << "Number of clients: " << clients.size() << endl;

    goBack();

    file.close();
}
// funkcija, kas taisa DB kopiju
void copyFile() {
    vector<clientData> clients = readData();

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "           Creating copy of the database             " << endl;
    cout << "-----------------------------------------------------" << endl;

    string copyName;
    cout << "Enter the name of the database copy: ";
    cin >> copyName;

    ofstream fileCopy(copyName + ".csv");

    for (auto & client : clients) {
        fileCopy << client.accNum << "," << client.Sur << "," << client.Name << "," << client.balance << "\n";
    }

    system("CLS");

    cout << "-----------------------------------------------------" << endl;
    cout << "The copy of the database has been created!" << endl;

    goBack();

    file.close();
}
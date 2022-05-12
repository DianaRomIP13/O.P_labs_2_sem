#include "Header.h"

Client::Client(string line) { 
    strcpy_s(sec_name, split(line)[0].c_str());
    sex = split(line)[1][0];  
    strcpy_s(date_of_birth, split(line)[2].c_str()); 
    amount = stoi(split(line)[3]);
    spent = amount * (100 - (this->GetAge() >= 60 ? this->GetAge() + 5 : this->GetAge()));
}

int Client::GetAge() {
    SYSTEMTIME current_date; 
    GetLocalTime(&current_date);
    int day = stoi(split(date_of_birth, ':')[0]); 
    int month = stoi(split(date_of_birth, ':')[1]);
    int year = stoi(split(date_of_birth, ':')[2]);
    return ((current_date.wMonth > month || current_date.wMonth == month && current_date.wDay >= day) ?
        (current_date.wYear - year) : (current_date.wYear - year - 1)); 
}

void inFile(string path, bool format) {
    ofstream ouf(path, ios::binary | (format ? ios::app : ios::trunc)); 
    cout << "Enter the amount of clients: ";
    int n; cin >> n;
    cin.ignore();
    string client;
    cout << "Enter the data in the following format:\n[name sex DD:MM:YYYY amount]\n";
    for (size_t i = 0; i < n; i++) { 
        getline(cin, client);
        Client temp(client);
        ouf.write((char*)&temp, sizeof(Client));
    }
    ouf.close();
}

void inNewFile(string SourcePath, string DestinationPath) {
    ifstream inf(SourcePath, ios::binary);
    ofstream ouf(DestinationPath, ios::binary);
    Client temp;
    while (inf.read((char*)&temp, sizeof(Client))) { 
        if (temp.spent > 250) {
            ouf.write((char*)&temp, sizeof(Client));
        }
    }
    inf.close();
    ouf.close();
}

void outFile(string path) {
    ifstream inf(path, ios::binary);
    Client temp;
    cout << endl << "---------------------------------------" << endl;
    while (inf.read((char*)&temp, sizeof(Client))) {
        cout << temp.sec_name << ' ' << temp.sex << ' ' << temp.date_of_birth << ' ' << temp.amount << endl;
    }
    inf.close();
    cout << "---------------------------------------" << endl;
}

int StoreProfit(string path) {
    ifstream inf(path, ios::binary);
    vector <Client> base; 
    Client temp;
    while (inf.read((char*)&temp, sizeof(Client))) {
        base.push_back(temp);
    }
    int sum = 0;
    for (auto i : base) {
        sum += i.spent;
    }
    return sum;
}

vector<string> split(string line, char sep) { 
    vector<string> words;
    string temp_word = ""; 
    line += sep;
    for (int i = 0; i < line.length(); i++) { 
        if (line[i] == sep) { 
            if (temp_word.length() > 0) { 
                words.push_back(temp_word);
            }
            temp_word = ""; 
        }
        else {
            temp_word += line[i]; 
        }
    }
    return words;
}
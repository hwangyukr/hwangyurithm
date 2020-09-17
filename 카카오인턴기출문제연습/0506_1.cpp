#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

void parse(string src, string& command, string&id, string& name) {
    
    char c[100] = "";
    char i[100];
    char n[100];
    sscanf(src.c_str(), "%s", c);
    if (string(c) == "Enter" || string(c) == "Change") {
        sscanf(src.c_str(), "%s %s %s", c, i, n);
        command = string(c);
        id = string(i);
        name = string(n);
    }
    else if (string(c) == "Leave") {
        sscanf(src.c_str(), "%s %s", c, i);
        command = string(c);
        id = string(i);
        name = "";
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> id_map;

    for (int i = 0; i < record.size(); i++) {
        string command, id, name;
        parse(record[i], command, id, name);
        if (command == "Enter") {
            id_map[id] = name;
        }
        if (command == "Change") {
            id_map[id] = name;
        }
    }

    for (int i = 0; i < record.size(); i++) {
        string command, id, name;
        parse(record[i], command, id, name);
        if (command == "Enter") {
            answer.push_back(id_map[id] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        }
        if (command == "Change") {
        }
        if (command == "Leave") {
            answer.push_back(id_map[id] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        }
    }

    return answer;
}

int main() {
    vector<string> record = {
        "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"
    };
    vector<string> answer = solution(record);
    return 0;
}
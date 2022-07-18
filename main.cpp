#include <iostream>
#include<fstream>
#include<string>
#include <regex>
#include <vector>

using namespace std;

fstream CodeFile("../test.y");

string MainKey[] = {"int", "return"};
string Identifier[] = {"#", "->", "(", ")", "{", "}", "\""};
string Functions[] = {"main", "print"};
string Delimiter[] = {" ", ";"};
string Preprocessing[] = {"import"};


std::vector<std::string> split(std::string str, std::string pattern) {
    std::string::size_type pos;
    std::vector<std::string> result;
    str += pattern;//扩展字符串以方便操作
    int size = str.size();
    for (int i = 0; i < size; i++) {
        pos = str.find(pattern, i);
        if (pos < size) {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}

vector<string> *RegularMatch(string str, string patterns) {
    smatch result;
    regex pattern(patterns);
    regex_match(str, result, pattern);
    vector<string> ret[result.size()];
    for (int i = 0; i < result.size(); ++i) {
//        ret[i] = result[i].str();
        ret->push_back(result[i]);
    }
    return ret;
}

int main() {
    string CodeLine;
    string YLM;
    while (getline(CodeFile, CodeLine)) {                                                 //逐行读取字符串
        vector<string> result = split(CodeLine, " ");
        for (int i = 0; i < result.size(); ++i) {
            if (result[i] == (Identifier[0] + Preprocessing[0])) {                                  //判断预处理命令的import关键字
//                cout<<"include"<<endl;
                vector<string> Library = split(result[i + 1], "->");
                vector<string> YLML;
                if (Library[0] == "system") {
                    fstream YLanguageMap("../system.ylm");
                    while (getline(YLanguageMap, YLM)) {
                        YLML = split(YLM, " ");
                    }
                }
                for (int j = 1; j < Library.size(); ++j) {
                    if (Library[j] == "All") {
                        cout << "import all" << endl;
                        break;
                    }
                    for (int k = 0; k < YLML.size(); ++k) {
                        if (Library[j] == YLML[k]) {
                            cout << "import " << YLML[k] << endl;
                        }
                    }

                }
            }

        }
    }
    CodeFile.close();
    return 0;
}

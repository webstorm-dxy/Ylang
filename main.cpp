#include <iostream>
#include<fstream>
#include<string>
#include <regex>
#include <vector>

#include "YMain.h"

using namespace std;

fstream CodeFile("../test.y");

string MainKey[] = {"int", "return"};
string Identifier[] = {"#", "->", "(", ")", "{", "}", "\""};
string Functions[] = {"main", "print"};
string Delimiter[] = {" ", ";"};
string Preprocessing[] = {"import"};

Ymain ym;

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

void YMain(){
    ym.yMain();
}

int main() {
    string CodeLine;
    string YLM;
    while (getline(CodeFile, CodeLine)) {                                                 //逐行读取字符串
        vector<string> result = split(CodeLine, " ");
        for (int i = 0; i < result.size(); ++i) {
            cout<<"|"<<result[i]<<endl;
            if (result[i]!=""){
                ym.GetCode(result[i]);
            }
            if (result[i] == (Identifier[0] + Preprocessing[0])) {                                  //判断预处理命令的import关键字
//                cout<<"include"<<endl;
                vector<string> Library = split(result[i + 1], "->");
                vector<string> YLML;
                if (Library[0] == "system") {
                    fstream YLanguageMap("../system.ylm");                                //与语言标识库中的函数文件进行比对
                    while (getline(YLanguageMap, YLM)) {
                        YLML = split(YLM, " ");
                    }
                }
                for (int j = 1; j < Library.size(); ++j) {
                    if (Library[j] == "All") {
                        cout << "import all" << endl;
                        break;
                    }
                    for (int k = 0; k < YLML.size(); ++k) {                                             //导入对应的类
                        if (Library[j] == YLML[k]) {
                            cout << "import " << YLML[k] << endl;
                        }
                    }

                }
            }
            if (result[i]==MainKey[0]){                                                                     //判断值的类型
                cout << "type is int"<<endl;
                if (result[i+1].find("(") != string::npos && result[i+1].find(")") != string::npos){            //处理值是用于返回值的情况
                    vector<string> FuncName = split(result[i+1],"()");                                          //判断是否为成对的括号，如果不是则报错
                    if (FuncName[0]==Functions[0]){                                                                                         //处理主函数入口
                        YMain();
                        cout<<"enter main function"<<endl;
                    }
                    cout<<FuncName[0]<<endl;
                }
                else if (result[i+1].find("(")!=string::npos && result[i+1].find(")")== string::npos){
                    cout<<"错误：缺少对应的括号\")\""<<endl;
                }
                else if (result[i+1].find("(")==string::npos && result[i+1].find(")")!= string::npos){
                    cout<<"错误：缺少对应的括号\"(\""<<endl;
                }
            }

        }

    }
    ym.ParenthesIsLegality();                                                                               //判断花括号是否成对
    CodeFile.close();
    return 0;
}

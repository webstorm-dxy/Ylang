//
// Created by 达星屹 on 2022/7/18.
//

#ifndef CPS1_YMAIN_H
#define CPS1_YMAIN_H

#include <stack>

using namespace std;

class Ymain{
public:
    void yMain(){

    }
    void GetCode(string Code){
        if (Code=="{"){                                                                                 //将括号分别依次入栈
            Brackets.push("{");
        }
        if (Code=="}"){
            Brackets.push("}");
        }
    }

    void ParenthesIsLegality(){
        if (Brackets.size() % 2 == 0){                                                                  //成对弹出栈
            int mid = Brackets.size() / 2;
            for (int i = 0; i < mid; ++i) {
                if (Brackets.top() == "}"){
                    Brackets.pop();
                }
            }
            for (int i = 0; i < mid; ++i) {
                if (Brackets.top() == "{"){
                    Brackets.pop();
                }
            }
            if (!Brackets.empty()){                                                                         //如果栈不为空，则不是成对的花括号，报错
                cout<<"错误:  你的花括号不成对"<<endl;
                BracketIsCorrect=false;
            }
            else
                BracketIsCorrect= true;
        }
        else
        {
            cout<<"错误:  你的花括号不成对"<<endl;
        }
    }

private:
    stack<string> Brackets;
    bool BracketIsCorrect;
    void start(){

    }
};

#endif //CPS1_YMAIN_H

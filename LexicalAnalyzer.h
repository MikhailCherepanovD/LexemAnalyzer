#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include "algorithm"
using namespace std;


class LexicalAnalyzer {
    enum State{
        S0,           //0
        S_DO1,        //1
        S_DO_FINAL,   //2
        S_W1,         //3
        S_W2,         //4
        S_W3,         //5
        S_W4,         //6
        S_WHILE_FINAL,//7
        S_VARIABLE,        //8
        S_INTEGER,    //9
        S_FLOAT_VAL,      //10
        S_COMMENT,    //11

        S_ASSIGN,     //12
        S_ERROR,    //13
        S_COMPARE, //14
        S_SEMICOLON
    };
    enum lexem_type{
        S_KEY,        //0
        S_CMP,        //1
        S_VAR,        //2
        S_FLOAT,      //3
        S_INT,        //4
        S_ASS,        //5
        S_SEM         //6
    };

    char EMPTY_ELEMENTS[4]{'\n','\t',' ','\0'};
    const int AMOUNT_STATES=14;
    const int AMOUNT_CHARS=128;
    vector<vector<int>> table_state;
    int curr_state;
    int prev_state;
    string curr_str;
    pair<string,string> GenerateOutput();

public:
    void CreateTable();
    LexicalAnalyzer();
    vector<pair<string,string>>  Analyse(string);
    string Preproccessing(string str);
    vector<int> GetOrderTypes(vector<pair<string,string>> vec);

};



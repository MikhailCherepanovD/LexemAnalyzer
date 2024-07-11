#include <iostream>
#include <vector>
#include <set>
#include "LexicalAnalyzer.h"
#include "fstream"
using namespace std;
void PrintVP( vector<pair<string,string>>  sp){
    for(auto p:sp ) {
        cout << p.first << ":  " << p.second;
        cout<<endl;
    }
    cout<<endl<<endl;

}
void PrintVP( set<pair<string,string>>  sp){
    for(auto p:sp ) {
        cout << p.first << ":  " << p.second;
        cout<<endl;
    }
    cout<<endl<<endl;

}
string ReadFile(string file_name){
    ifstream fin(file_name);

    string strh;
    string str;

    while(!fin.eof()){
        getline(fin, strh);
        str += strh;
        if (!fin.eof()){
            str += '\n';
        }
    }
    return str;
}




vector<pair<pair<string,string>,int>>  FromPairToTr(vector<pair<string,string>> vp){
    vector<pair<string,string>> ret;
    vector<pair<pair<string,string>,int>> vtr;
    for(int i=0;i<vp.size();i++){
        int counter=1;
        bool flag=1;
        for(int j=0;j<i;j++){
            /* if(vp[i].first==vp[j].first &&vp[i].second!=vp[j].second)
                 counter++;*/
            if(vp[i].first==vp[j].first &&vp[i].second==vp[j].second) {
                counter = vtr[j].second;
                flag=0;
                break;
            }
        }
        if(flag && !vtr.empty()) {
            int comp_counter = 1;
            bool flag1=0;
            for (int k = vtr.size(); k >= 0; k--) {
                if (vtr[k].first.first == vp[i].first) {
                    comp_counter = max(comp_counter, vtr[k].second);
                    flag1=1;
                }
            }
            if(flag1)
                counter=comp_counter+1;
            else
                counter=comp_counter;
        }
        vtr.push_back(make_pair(vp[i],counter));

    }
    return vtr;
}


void OutputToMarkdown(const std::vector<std::pair<std::pair<std::string, std::string>, int>>& data, const std::string& filename) {
    std::ofstream markdownFile(filename);

    // Записываем заголовки таблицы
    markdownFile << "| Тип лексемы | Лексема  | Номер|\n";
    markdownFile << "| ----------- | ----------- | -------- |\n";

    // Записываем данные в таблицу
    for (const auto& item : data) {
        const auto& pair = item.first;
        markdownFile << "| " << pair.first << " | " << (pair.second == ">" ? "\\>" : pair.second)<< " | " << item.second << " |\n";
    }
}





int main() {
    LexicalAnalyzer LA;
    

    string test_str=ReadFile("input1.txt");
    cout<<test_str<<endl;
    vector<pair<string,string>>  vp=LA.Analyse(test_str);
    vector<int> order=LA.GetOrderTypes(vp);
    set<pair<string,string>>mp(vp.begin(),vp.end());
    vector<pair<pair<string,string>,int>> out= FromPairToTr(vp);
    OutputToMarkdown(out, "output.md");
    return 0;
}

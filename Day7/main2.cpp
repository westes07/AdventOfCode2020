#include "graph.hpp"
#include <map>

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode7.txt");
    map<string, string> lines;
    string line, color;
    int num;
    string key, value;
    BagTree bags;
    int count = -1;

    while (getline(in, line)){
        key = line.substr(0, line.find(" bags "));
        bags.addBag(key);
        value = line.substr(line.find("contain ")+7);
        lines.insert(std::pair<string, string>(key, value));
    }

    for (int i = 0; i < lines.size(); i++){
        key = bags.graph[i]->color;
        stringstream ss(lines.at(key));
        while (getline(ss, line, ',')){
            // cout << line.substr(1, 2) << endl;
            if(line.substr(1, 2) != "no"){
                num = stoi(line.substr(1,2));
            }else {
                num = 0;
            }
            line = line.substr(3, line.find("bag")-4);
            bags.addConnection(key, line, num);
        }
    }
    count = bags.countContents("shiny gold");
    std::cout << count << endl;

    return 0;
}
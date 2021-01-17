#include "bag.cpp"
#include <map>

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode7.txt");
    map<string, string> lines;
    string line, color;
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
            line = line.substr(3, line.find("bag")-4);
            bags.addConnection(key, line);
        }
    }
    
    for (int i = 0; i < bags.graph.size(); i++){
        cout << bags.graph[i]->color << " -> ";
        for (int j = 0; j < bags.graph[i]->contents.size(); j++){
            cout << bags.graph[i]->contents[j].b->color << " : ";
        }
        cout << "END" << endl;
        if (bags.traverseSearch(bags.graph[i]->color, "shiny gold")){
            count++;
        }
    }
    std::cout << count << endl;

    return 0;
}
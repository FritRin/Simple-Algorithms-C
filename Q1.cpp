#include <iostream>
#include <stack>
#include <string>

using namespace std;
string modifyLine(string);

int main(int argc, char * argv[]){
    string line;

    cout << "input one line to modify: " << endl;
    getline(cin, line);

    string modifiedLine = modifyLine(line);

    cout << "original line : " << line << endl;
    cout << "modified line: " << modifiedLine << endl;
    
}

string modifyLine(string line){
    string reverse;
    stack<char> charStack;
    char Ch;

    for(int x = 0; x < line.size(); x++){
        Ch = line[x];
        charStack.push(Ch);
    }
    while(!charStack.empty()){
        reverse.push_back(charStack.top());
        charStack.pop();
    }
    for(int y = 0; y < reverse.size(); ){
        if(reverse[y] == ',' || reverse[y] == '.'){
            reverse.erase(y, 1);
        } else y++;
    }

    return reverse;
}
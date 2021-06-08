//
//  10828스택.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/08.
//

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    string instruction;
    int input;
    stack<int> s;
    for(int i = 0; i < N; ++i) {
        cin >> instruction;
        
        if (instruction.front() == 'p') {
            if (instruction[1] == 'u') { // push
                cin >> input;
                s.push(input);
            } else { // pop
                if (s.empty() == true) cout << -1 << endl;
                else {
                    cout << s.top() << endl;
                    s.pop();
                }
            }
        } else if (instruction.front() == 's') { // size
            cout << s.size() << endl;
        } else if (instruction.front() == 'e') { // empty
            if (s.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        } else { // top
            if (s.empty()) cout << -1 << endl;
            else cout << s.top() << endl;
        }
    }
    return 0;
}

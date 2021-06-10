//
//  10845큐.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/06/09.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
    int N, input;
    string instruction;
    cin >> N;
    
    queue<int> que;
    for(int i = 0; i < N; ++i) {
        cin >> instruction;
        
        switch (instruction.front()) {
            case 'p':
                if (instruction[1] == 'u') { // push
                    cin >> input;
                    que.push(input);
                } else { // pop
                    if (que.empty()) cout << -1 << endl;
                    else {
                        cout << que.front() << endl;
                        que.pop();
                    }
                }
                break;

            case 's': // size
                cout << que.size() << endl;
                break;

            case 'e': // empty
                if (que.empty()) cout << 1 << endl;
                else cout << 0 << endl;
                break;
                
            case 'f': // front
                if (que.empty()) cout << -1 << endl;
                else cout << que.front() << endl;
                break;

            case 'b': // back
                if (que.empty()) cout << -1 << endl;
                else cout << que.back() << endl;
                break;
                
            default:
                break;
        }
    }
    return 0;
}

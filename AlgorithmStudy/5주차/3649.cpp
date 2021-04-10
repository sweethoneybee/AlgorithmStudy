//
//  3649.cpp
//  AlgorithmStudy
//
//  Created by 정성훈 on 2021/04/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void testCase(int holeWidth, int n) {
    vector<int> legos;
    for(int i = 0; i < n; i++) {
        int legoWidth;
        cin >> legoWidth;
        legos.push_back(legoWidth);
    }
    
    if (n < 2) {
        cout << "danger";
        return;
    }
    
    sort(legos.begin(), legos.end());
    int smallIndex = 0;
    int bigIndex = legos.size() - 1;
    while (smallIndex < bigIndex) {
        const int& smallLego = legos[smallIndex];
        const int& bigLego = legos[bigIndex];
        const int needLegoWidth = holeWidth - bigLego;
        
        if (smallLego < needLegoWidth) {
            smallIndex += 1;
        } else if (smallLego > needLegoWidth) {
            bigIndex -= 1;
        } else {
            break;
        }
    }
    
    if (smallIndex < bigIndex) {
        cout << "yes " << legos[smallIndex] << " " << legos[bigIndex];
    } else {
        cout << "danger";
    }
}

int main(void) {
    int holeWidth, n;
    
    while(cin >> holeWidth >> n) {
        holeWidth = holeWidth * 10000000;
        testCase(holeWidth, n);
    }

    cout << "wow";
    return 0;
}

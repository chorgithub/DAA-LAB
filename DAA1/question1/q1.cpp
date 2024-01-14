#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("q1_in.txt");

    ofstream out("q1_out.txt");

    if (!in.is_open()) {
        cerr << "Error" << endl;
        return 1; 
    }

    if (!out.is_open()) {
        cerr << "Error " << endl;
        return 1;
    }

    int size;
    in >> size;

    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        in >> v[i];
    }

    in.close();

    if (size < 2) {
        cerr << "Array should have atleat two integer." << endl;
        return 1; 
    }

   
    int firstmax=max(v[0],v[1]);
    int secondmax=min(v[0],v[1]);
    for(int i=2;i<size;i++){
        if(v[i]>firstmax){
           secondmax=firstmax;
           firstmax=v[i];
        }else if(v[i]>secondmax){
            secondmax=v[i];
        }
    }

    out<< "Maximum Possible sum of two integer is: " << firstmax+secondmax << endl;

    out.close();


    return 0; 
}

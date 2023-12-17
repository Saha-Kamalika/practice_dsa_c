/*for positive add 1 to score 
  for negative sub 1 from score
  for neutral score=0
*/
#include<bits/stdc++.h>
using namespace std;
int finalScore(string& s){
    int score=0;
    stringstream ss(s);
    string temp;
    while(getline(ss,temp,';')){
        if(temp=="positive") score+=1;
        else if(temp=="negative") score-=1;
    }
    return score;
}
int main(){
    string s="neutral;positive;negative";
    cout<<finalScore(s)<<endl;
}

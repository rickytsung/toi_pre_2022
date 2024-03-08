#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

string& trim(string &s){
    if(s.empty()) 
        return s;
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

int abs(int x){
  if(x<0)return -x;
  return x;
}

int main(int argc, char **argv){
	string ans,out;
	int index = 0,ok = 1,n,k,m,x,y,u,v,idx = 0;
    int prex = 100000,prey = 1000000;
    int sx, sy;
	pair<string,string> result[5]={{"$JUDGE_RESULT",""},{"$LINECOUNT",""},{"$USEROUT",""},{"$SYSTEMOUT",""},{"$MESSAGE",""}};
	ifstream infile(argv[1]),ansfile(argv[2]),outfile(argv[3]);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int arr[1005][1005];  
    infile >> u >> v;
    ansfile >> n;
    if(n==-1){
        outfile >> k;
        if(k != -1){
           ok = 0;
           result[0].second = "WA";
		   result[1].second = to_string(index);
		   result[2].second = to_string(n);
		   result[3].second = "答案錯誤。";
		   result[4].second = "答案錯誤。";
        }
   }
   else{
      for(int i=0;i<=n*m;i++){
            if(outfile >> x >> y){
              index++;
              if(x < 1 || x > u || y < 1 || y > v){
                result[0].second = "WA";
                result[1].second = to_string(index+1);
                result[2].second = trim(out);
                result[4].second = "答案錯誤。";
                ok = 0;
                break;
              }
              if(i == 0){
                sx=x;
                sy=y;
              }
              if(i == n*m){
                if(sx == x && sy == y){
                  // correct
                }
                else{
                  result[0].second = "WA";
                  result[1].second = to_string(index+1);
                  result[2].second = trim(out);
                  result[4].second = "答案錯誤。";
                  ok = 0;
                break;
                }
              }
              if(!arr[x][y] && i < n*m){
                result[0].second = "WA";
                result[1].second = to_string(index+1);
                result[2].second = trim(out);
                result[4].second = "答案錯誤。";
                ok = 0;
                break;
              }
              if(abs(x-prex) == abs(y-prey)||x == prex||y == prey){
                result[0].second = "WA";
                result[1].second = to_string(index+1);
                result[2].second = trim(out);
                result[4].second = "答案錯誤。";
                ok = 0;
                break;
              }
              arr[x][y]=0;
              prex=x;
              prey=y;
              
            }
            else{
               result[0].second = "WA";
               result[1].second = to_string(index+1);
               result[4].second = "沒有完整輸出答案。";
               ok = 0;
               break;
            }            
      }
   }  

	if(ok){
		result[0].second = "AC";
	}
	for(int i=0;i<5;i++){
		cout << result[i].first << '=' << result[i].second <<'\n';
	}
}

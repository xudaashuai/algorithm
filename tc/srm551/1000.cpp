#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 51;
long long int dp[MAXN][MAXN][MAXN][3];
long long int MOD = 1000000007;
int sz;
int As=0, Bs=0, Cs=0;
class ColorfulCupcakesDivTwo {
    public:
        long long int get_ans(int start_with){
            memset(dp,0,sizeof(dp));
            if(start_with == 0){
                if(As<1)return 0;
                dp[0][1][0][0] = 1;
            }else if(start_with ==1){
                if(Bs<1)return 0;
                dp[0][0][1][1] = 1;
            }else if(start_with==2){
                if(Cs<1)return 0;
                dp[0][0][0][2] = 1;
            }

            for(int i=1; i<sz; i++){
                for(int pA=0; pA<=As; pA++){
                    for(int pB=0; pB<=Bs; pB++){
                        int pC = i-pA-pB;
                        //A
                        if(i==sz-1){
                            if(start_with==0){
                                if( pB<Bs){
                                    dp[i][pA][pB+1][1] += dp[i-1][pA][pB][0] + dp[i-1][pA][pB][2];
                                    dp[i][pA][pB+1][1] %=MOD;
                                }
                                if (pC<Cs){
                                    dp[i][pA][pB][2] += dp[i-1][pA][pB][0] + dp[i-1][pA][pB][1];
                                    dp[i][pA][pB][2] %= MOD;
                                }
                            }else if(start_with==1){
                                if( pA<As){
                                    dp[i][pA+1][pB][0] += dp[i-1][pA][pB][1]+dp[i-1][pA][pB][2];
                                    dp[i][pA+1][pB][0]%=MOD;
                                }
                                if (pC<Cs){
                                    dp[i][pA][pB][2] += dp[i-1][pA][pB][0] + dp[i-1][pA][pB][1];
                                    dp[i][pA][pB][2] %= MOD;
                                }
                            }else{
                                if( pA<As){
                                    dp[i][pA+1][pB][0] += dp[i-1][pA][pB][1]+dp[i-1][pA][pB][2];
                                    dp[i][pA+1][pB][0]%=MOD;
                                }
                                if( pB<Bs){
                                    dp[i][pA][pB+1][1] += dp[i-1][pA][pB][0] + dp[i-1][pA][pB][2];
                                    dp[i][pA][pB+1][1] %=MOD;
                                }
                            }
                        }else{
                            if( pA<As){
                                dp[i][pA+1][pB][0] += dp[i-1][pA][pB][1]+dp[i-1][pA][pB][2];
                                dp[i][pA+1][pB][0]%=MOD;
                            }
                            if( pB<Bs){
                                dp[i][pA][pB+1][1] += dp[i-1][pA][pB][0] + dp[i-1][pA][pB][2];
                                dp[i][pA][pB+1][1] %=MOD;
                            }
                            if (pC<Cs){
                                dp[i][pA][pB][2] += dp[i-1][pA][pB][0] + dp[i-1][pA][pB][1];
                                dp[i][pA][pB][2] %= MOD;
                            }
                        }
                    }
                }
            }
            long long int t_sum = dp[sz-1][As][Bs][0] + dp[sz-1][As][Bs][1]+dp[sz-1][As][Bs][2];
            return t_sum%MOD;
            //return (dp[sz-1][As][Bs][0]+dp[sz-1][As][Bs][1]+dp[sz-1][As][Bs][2])%MOD;
        }
        int countArrangements(string cupcakes) {
            As = 0, Bs = 0, Cs = 0;
            sz = cupcakes.size();
            for(int i=0; i<cupcakes.size(); i++){
                if(cupcakes[i]=='A'){
                    As+=1;
                }else if(cupcakes[i]=='B'){
                    Bs+=1;
                }else{
                    Cs+=1;
                }
            }
            cout<<"As = "<<As<<endl;
            cout<<"Bs = "<<Bs<<endl;
            cout<<get_ans(0)<<endl;
            cout<<get_ans(1)<<endl;
            cout<<get_ans(2)<<endl;
            cout<<"~~~"<<endl;
            long long int sum = (get_ans(0)+get_ans(1)+get_ans(2))%MOD;
            return sum;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
    cout << "]" << endl;
    ColorfulCupcakesDivTwo *obj;
    int answer;
    obj = new ColorfulCupcakesDivTwo();
    clock_t startTime = clock();
    answer = obj->countArrangements(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    string p0;
    int p1;
    /*
       {
    // ----- test 0 -----
    p0 = "ABAB";
    p1 = 2;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
    }
    */
    {
        // ----- test 1 -----
        p0 = "ABABA";
        p1 = 0;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        p0 = "ABC";
        p1 = 6;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = "ABABABABABABABABABABABABABABABABABABABABABABABABAB";
        p1 = 2;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = "BCBABBACBABABCCCCCAABBAACBBBBCBCAAA";
        p1 = 741380640;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING

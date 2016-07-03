#include<string.h>  
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f  
const int maxn = 110;
int B[maxn];
int C[maxn];
int A[maxn];

int main() {
	
	int t; 
	cin >> t;
	
	while (t--) {
		
		int n; 
		cin >> n; 
		memset(A, INF, sizeof(A)); 
		for (int i = 1; i <= n; i++) 
			cin >> B[i] >> C[i]; 
		A[0] = 0; 
		for (int i = 1; i <= n; i++) 
		{
			
			int r = B[i] + C[i]; 
			for (int j = i; j <= n; j++) 
			{
				
				if (B[j]<r) {
					
					A[j] = min(A[j], A[i - 1] + 1); 
					r = max(B[j] + C[j], r); 
				}
				else    
					break; 
			}
			int l = B[i]; 
			for (int j = i; j <= n; j++) {
				
				if (B[j] - C[j] < l) {
					
					A[j] = min(A[j], A[i - 1] + 1); 
					l = B[j];
					for(int vv=0;vv<1;vv++){}
				}
				
			}
		}
		cout << A[n] << endl; 
	}
	return 0;
}
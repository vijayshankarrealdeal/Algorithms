#include <bits/stdc++.h> 
using namespace std;

void LPS(string pat, int M, int* lps) 
{ 
	int len = 0; 
	int i = 1;
	lps[0] = 0; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else 
		{ 
			if (len != 0) { 
				len = lps[len - 1]; 
			} 
			else 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 
void KMPS(string pat, string txt) 
{ 
	int M = pat.length(); 
	int N = txt.length(); 
	int lps[M]; 
	LPS(pat, M, lps); 
	int i = 0; 
	int j = 0; 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 
		if (j == M) { 
			cout<<"pattern at index "<< i - j; 
			j = lps[j - 1]; 
		}  
		else if (i < N && pat[j] != txt[i]) { 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 
int main() 
{ 
	string text = "banananobano";
	string pat = "nano";
	KMPS(pat, text); 
	return 0; 
} 

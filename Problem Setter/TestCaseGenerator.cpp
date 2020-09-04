/*
  Author: Sahil Yadav, IIITM Gwalior
*/
#include <bits/stdc++.h>
#include <unistd.h>
#include <windows.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
#define MAX 200005
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
const ll MOD=1e9+7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool dirExists(const std::string& dirName_in)
{
  DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    return false;  //something is wrong with your path!

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return true;   // this is a directory!

  return false;    // this is not a directory!
}
string suffix(int x){
	string ans="";
	while(x){
		char a='0'+x%10;
		ans+=a;
		x/=10;
	}
	while(ans.length()<2)
		ans+="0";

	reverse(all(ans));
	ans+=".txt";
	return ans;
}

void populateInput(){
	
}

void populateOutput(string inputFile){
	freopen(inputFile.c_str(),"r",stdin);
	/* Problem Setter code*/
	

	/* Problem Setter code*/
	fclose(stdin);
}

void genInput(int test){
	string fileName="TestCase/in"+suffix(test);
	freopen(fileName.c_str(),"w",stdout);
	populateInput();
	fclose(stdout);
}

void genOutput(int test){
	string fileName="TestCase/out"+suffix(test);
	freopen(fileName.c_str(),"w",stdout);
	populateOutput("TestCase/in"+suffix(test));
	fclose(stdout);
}

int main()
{
	if(dirExists("TestCase"))
		system("rmdir /s /q TestCase");
	mkdir("TestCase");

	// number of testcase from st to en.
	int st=0,en=10;
	for(int test=st;test<=en;++test){
		genInput(test);
		genOutput(test);
	}
	return 0;
}
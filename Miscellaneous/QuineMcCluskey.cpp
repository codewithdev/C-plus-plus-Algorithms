#include <bits/stdc++.h>
using namespace std;

//Helper class for utilities
class Helper{
public:
	//Converting Integer to String
	string intToBin(int val){
		int mod;
		string bin="";
		while(val!=0){
			mod = val%2;
			if(mod){
				bin = bin + "1";
			}
			else bin = bin + "0";
			val/=2;
		}
		reverse(bin.begin(),bin.end());
		return bin;
	}

	//Padding zeros to accomodate all variables
	string pad(string bin, int no_var){
		int m = no_var - bin.size();
		for(int i=0;i<m;i++){
			bin = "0" + bin;
		}
		return bin;
	}

	//Getting number of 1's in a string
	int getOnes(string a){
		int cnt=0;
		for(int i=0;i<a.size();i++){
			if(a[i]=='1'){cnt++;}
		}
		return cnt;
	}

	//Checking if pair is grey code or not
	bool compare(string a, string b){
		int cnt=0;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){cnt++;}
		}
		if(cnt==1){return true;}
		return false;
	}

	//Reducing the differing location with don't care (*)
	string reduce(string a, string b){
		string x="";
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){x = x + "*";}
			else x = x + a[i];
		}
		return x;
	}

	//Checking if the Table is empty
	bool isEmpty(vector < vector <string> > &table){
		for(int i=0;i<table.size();i++){
			if(table[i].size()!=0){
				return false;
			}
		}
		return true;
	}

	//Converting string of 1's and 0's to A's & B's
	string expression(string a){
		string x="";
		char c;
		for(int i=0;i<a.size();i++){
			if(a[i]=='0'){
				c = 65 + i;
				x = x + c;
				x = x + '\'';
			}
			else if(a[i]=='1'){
				c = 65 + i;
				x = x + c;
			}
		}
		return x;
	}

	//Checking if a minterm is satisfied by the Prime Implicant
	bool primeImpIncludes(string imp, string minterm){
		for(int i=0;i<minterm.size();i++){
			if(imp[i]=='*'){continue;}
			else{
				if(imp[i]!=minterm[i]){
					return false;
				}
			}
		}
		return true;
	}

	//Returns number of variables in a Petrick method combination
	int getNumVar(vector <int> comb, vector <string> primeImp){
		int cnt=0;
		for(int i=0;i<comb.size();i++){
			int implicant = comb[i];
			for(int j=0;j<primeImp[implicant].size();j++){
				if(primeImp[implicant][j]!='*'){
					cnt++;
				}
			}
		}
		return cnt;
	}

};

//Class to solve the boolean expression using Quine-McCluskey followed by Petrick's Method
class QMSolver{
private:
	Helper helper;
	vector <int> minInt; //Minterms as Integers
	vector <string> minBin; //Minterms in Binary representation
	int no_var;
	int no_minterms;
	vector < vector <string> > table; 
	vector <string> primeImp;
	vector <string> essPrimeImp;
	vector < vector <int> > finalImp;
	vector <int> afterRemImp;
	vector <int> afterRemMinterm;

public:

	bool init(){
		cout<<"Enter number of variables (1-20) : ";
		cin>>no_var;
		while(no_var > 20 || no_var < 1){
			cout<<"\nEnter valid number of variables!\n\n";
			cout<<"Enter number of variables (1-20) : ";
			cin>>no_var;
		}

		string minterm,mt;
		bool flag = false;
		long long int range = pow(2,no_var)-1;
		cout<<"Enter minterms (Range from 0-"<<range<<") separated by commas:\n";
		cin>>minterm;
		//Splitting the minterms
		stringstream checker(minterm);
		while(getline(checker,mt,',')){
			int number = atoi(mt.data());
			if(number > range){
				cout<<"\nError, minterm out of range!\n\n";
				return false;
			}
			if(find(minInt.begin(),minInt.end(),number)!=minInt.end()){cout<<"\nDuplicate value of minterm "<<number<<"!\n\n"; return false;}
			minInt.push_back(number);
			minBin.push_back(helper.pad(helper.intToBin(number),no_var));
			//cout<<solver.pad(solver.bin(number),n)<<endl;
		}
		sort(minBin.begin(),minBin.end());
		sort(minInt.begin(),minInt.end());
		no_minterms = minInt.size();

		table = vector< vector<string> >(no_var+1);
		return true;

	}

	//Creating Table based number of one's
	void createTable(){
		for(int i=0;i<no_minterms;i++){
			int x = helper.getOnes(minBin[i]);
			table[x].push_back(minBin[i]);
		}
	}

	//Matching pairs between every consequent rows in the table and condensing them into a new table
	vector < vector <string> > matchPairs(vector < vector <string> > &table, vector <string> &primeImp){
		bool checked[table.size()][no_minterms]={false};
		vector < vector<string> > newTable(table.size()-1);

		for(int i=0;i<table.size()-1;i++){
			for(int j=0;j<table[i].size();j++){
				for(int k=0;k<table[i+1].size();k++){
					if(helper.compare(table[i][j],table[i+1][k])){
						checked[i][j] = true;
						checked[i+1][k] = true;
						newTable[i].push_back(helper.reduce(table[i][j],table[i+1][k]));
					}
				}
			}
		}

		//Adding the implicants that couldn't be condensed
		for(int i=0;i<table.size();i++){
			for(int j=0;j<table[i].size();j++){
				if(!checked[i][j]){
					if(find(primeImp.begin(),primeImp.end(),table[i][j])!=primeImp.end()){continue;}
					primeImp.push_back(table[i][j]);
				}
			}
		}

		return newTable;
	}

	//Getting the Prime Implicants
	void getPrimeImp(){
		createTable();

		while(!helper.isEmpty(table)){
			table = matchPairs(table,primeImp);
		}

		sort(primeImp.begin(),primeImp.end());

		cout<<"\nThe Prime Implicants are :\n\n";
		for(int i=0;i<primeImp.size();i++){
			cout<<helper.expression(primeImp[i])<<endl;
		}
		cout<<endl;
	}

	void finalMinimise(){
		//Making the table to find cover for prime Implicants
		int primeImpTable[primeImp.size()][no_minterms];
		int counter[no_minterms];
		memset(primeImpTable,0,sizeof(primeImpTable));
		memset(counter,0,sizeof(counter));

		for(int i=0;i<primeImp.size();i++){
			for(int j=0;j<no_minterms;j++){
				if(helper.primeImpIncludes(primeImp[i],minBin[j])){
					primeImpTable[i][j] = 1;
					counter[j]++;
				}
			}
		}

		//Pushing Essential Prime Implicants first
		for(int j=0;j<no_minterms;j++){
			if(counter[j]==1){
				for(int i=0;i<primeImp.size();i++){
					if(primeImpTable[i][j]==1){
						if(find(essPrimeImp.begin(),essPrimeImp.end(),primeImp[i])!=essPrimeImp.end()){continue;}
						essPrimeImp.push_back(primeImp[i]);
					}
					else{
						afterRemImp.push_back(i);
					}
				}
			}
		}

		//Removing Minterms
		set <int> remMinterm;
		for(int i=0;i<essPrimeImp.size();i++){
			for(int j=0;j<no_minterms;j++){
				if(helper.primeImpIncludes(essPrimeImp[i],minBin[j])){
					remMinterm.insert(j);
				}	
			}
		}

		if(essPrimeImp.size()==0){
			cout<<"There are no essential prime implicants!\n\n";
			for(int i=0;i<primeImp.size();i++){
				afterRemImp.push_back(i);
			}

		}
		else{
			cout<<"The Essential Prime Implicants are :\n\n";
			for(int i=0;i<essPrimeImp.size();i++){
				cout<<helper.expression(essPrimeImp[i])<<"\n";	
			}
		}

		for(int i=0;i<no_minterms;i++){
			if(find(remMinterm.begin(),remMinterm.end(),i)!=remMinterm.end()){
				continue;
			}
			else{
				afterRemMinterm.push_back(i);
			}
		}

		int afterRemImpTable[afterRemImp.size()][afterRemMinterm.size()];
		memset(afterRemImpTable,0,sizeof(afterRemImpTable));

		//Building the table again
		for(int i=0;i<afterRemImp.size();i++){
			for(int j=0;j<afterRemMinterm.size();j++){
				if(helper.primeImpIncludes(primeImp[afterRemImp[i]],minBin[afterRemMinterm[j]])){
					afterRemImpTable[i][j] = 1;
				}
			}
		}

		//Using Petrick's Method on the remaining Minterms and Implicants
		vector < vector <int> > petrick;
		for(int j=0;j<afterRemMinterm.size();j++){
			vector <int> temp;
			for(int i=0;i<afterRemImp.size();i++){
				if(afterRemImpTable[i][j]){
					temp.push_back(afterRemImp[i]);
				}
			}
			if(find(petrick.begin(),petrick.end(),temp)!=petrick.end()){
				continue;
			}
			petrick.push_back(temp);
		}
		sort(petrick.begin(),petrick.end());

		//Getting all combinations
		vector < vector <int> > possComb;
		vector <int> product;
		getAllComb(petrick,0,product,possComb);
		int min=INT_MAX;

		//Finding the minimum no of terms
		for(int i=0;i<possComb.size();i++){
			int x = possComb[i].size();
			if(x < min){min = x;}
		}

		//Combination with minimum terms
		vector < vector <int> > miniComb;
		for(int i=0;i<possComb.size();i++){
			if(possComb[i].size()==min){
				// if(find(miniComb.begin(),miniComb.end(),possComb[i])!=miniComb.end()){continue;}
				miniComb.push_back(possComb[i]);
			}
		}

		min=INT_MAX;
		for(int i=0;i<miniComb.size();i++){
			int x = helper.getNumVar(miniComb[i],primeImp);
			if(x < min){ min = x;}
		} 

		for(int i=0;i<miniComb.size();i++){
			int x = helper.getNumVar(miniComb[i],primeImp);
			if(x == min){
				if(find(finalImp.begin(),finalImp.end(),miniComb[i])!=finalImp.end()){continue;}
				finalImp.push_back(miniComb[i]);
			}
		} 

	}

	void getAllComb(vector < vector <int> > &petrick, int minT, vector <int> &product, vector < vector <int> > &possComb){
		if(minT == petrick.size()){
			vector <int> temp = product;
			sort(temp.begin(),temp.end());
			if(find(possComb.begin(),possComb.end(),temp)!=possComb.end()){return;}
			possComb.push_back(temp);
			return;
		}
		else{
			for(int i=0;i<petrick[minT].size();i++){
				int x = petrick[minT][i];
				bool flag=true;
				if(find(product.begin(),product.end(),x)!=product.end()){flag = false;}
				if(flag){product.push_back(x);}
				//recursing to get all possible combinations
				getAllComb(petrick,minT+1,product,possComb);
				if(flag){
					product.erase(remove(product.begin(), product.end(), x), product.end());
				}
			}
		}
	}

	void result(){
		string ess="";
		for(int i=0;i<essPrimeImp.size();i++){
			ess = ess + helper.expression(essPrimeImp[i]) + " + ";
		}
		cout<<"\nThe possible canonical forms is/are :\n\n";
		for(int i=0;i<finalImp.size();i++){
			cout<<i+1<<". ";
			string s = ess;
			for(int j=0;j<finalImp[i].size();j++){
				if(find(essPrimeImp.begin(),essPrimeImp.end(),primeImp[finalImp[i][j]])!=essPrimeImp.end()){continue;}
				s = s + helper.expression(primeImp[finalImp[i][j]]) + " + ";	
			}
			s = s.erase(s.size()-3,2);
			cout<<s<<endl;
		}
	}

	void clear(){
		minInt.clear();
		minBin.clear(); 
		table.clear(); 
		primeImp.clear();
		finalImp.clear();
		afterRemImp.clear();
		afterRemMinterm.clear();
		essPrimeImp.clear();
	}

};

int main(){
	QMSolver solver;
	char c='y';
	while(c=='y'){
		bool flg = solver.init();
		while(!flg){
			solver.clear();
			flg = solver.init();
		}
		solver.getPrimeImp();
		solver.finalMinimise();
		solver.result();
		solver.clear();
		cout<<"\n\nDo you want to enter another expression? (y/n) : ";
		cin>>c;
	}
	return 0;
}

/*

test 1
number of variables - 4
minterms - 0,1,3,7,8,9,11,15

test 2
number of variables - 4
minterms - 0,1,2,5,6,7,8,9,10,14

test 3
number of variables - 3
minterms - 0,1,2,5,6,7

*/

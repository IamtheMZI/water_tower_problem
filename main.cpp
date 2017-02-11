#include <iostream>
#include <vector>

#define SUCCESS 0
#define FAILURE 1

using namespace std;

class Interval{
	public:
		int start;
		int end;
};

int twer[] = {5,3,7,2,6,4,5,9,1,2};
vector<Interval> interval;

int interval_mapping(vector<Interval> &ival){
	int big = -1;
	int id = -1;
	int size = sizeof(twer)/sizeof(int);
	for (int k=0; k<size;k++){
		cout << twer[k]<<" ";
		if(k==0) {
			big=twer[k];
			id = k;

		}
		else{
			if(twer[k]> big && k>id+1){
				Interval p;
				p.start = id;
				p.end = k;
				id = k;
				big = twer[k];
				ival.push_back(p);
				
			}else if((k+1)==size && twer[k] > twer[k-1]){
				Interval p;
				p.start = id;
				p.end = k;
				id = k;
				big = twer[k];
				ival.push_back(p);
			}
		}
	}
	return SUCCESS;
}

int print_intervals(vector<Interval>& iv){
	for(int i = 0; i < iv.size(); i++){
	   cout << "[" << twer[iv[i].start] << "," << twer[iv[i].end] << "]" << endl;
	}
	return SUCCESS;

}

int calculation(vector<Interval>& iv){
	int total = 0;
	int s = iv.size();
	for(int i=0; i < s; i++){
		int diff = twer[iv[i].start] - twer[iv[i].end];
		if(diff < 0){
			diff = twer[iv[i].start];
		}else if(diff > 0){
			diff = twer[iv[i].end];
		}
				cout << "->" <<diff << endl;
		for(int m = iv[i].start+1;m<iv[i].end;m++){
			
			int res = (diff - twer[m]);
			total = total + res;
			cout << res << endl;
		}
	}
	return total;
}


int main()
{
	interval_mapping(interval);
	print_intervals(interval);
	int s_total = calculation(interval);
	std::cout << s_total << std::endl;
}

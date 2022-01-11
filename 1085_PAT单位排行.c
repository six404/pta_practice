#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct node {
	string school;
	int tws, ns;
};
bool cmp(node a, node b) {
	if (a.tws != b.tws) return a.tws > b.tws;
	else if (a.ns != b.ns) return a.ns < b.ns;
	else return a.school < b.school;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;

	unordered_map<string, int> cnt;
	unordered_map<string, double> sum;

	string id, school;
	double score;
	int count = 1;
	for (int i = 0; i < n; i++) {
		cin >> id >> score >> school;
		for (int j = 0; j < school.length(); j++) school[j] = tolower(school[j]);
		if (id[0] == 'B') score = score / 1.5;
		else if (id[0] == 'T') score = score * 1.5;
		sum[school] += score;
		cnt[school]++;
	}

	vector<node> ans;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		ans.push_back(node{ it->first,(int)sum[it->first],cnt[it->first] });
	}
	sort(ans.begin(), ans.end(), cmp);
	int rank = 0, pre = -1;
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		if (pre != ans[i].tws) rank = i + 1;
		pre = ans[i].tws;
		cout << rank << " " << ans[i].school << " " << ans[i].tws << " " << ans[i].ns << endl;
	}

	return 0;
}

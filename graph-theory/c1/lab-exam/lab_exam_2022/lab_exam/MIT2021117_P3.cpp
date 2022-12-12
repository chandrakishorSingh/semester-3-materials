#include "iostream"

using namespace std;

void printMatrix(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void findFriendsOfEachPerson(int** adjMat, int n) {
	for (int i = 0; i < n; i++) {
		int count = 0;
		cout << "Friends of person " << (i + 1) << " are as follows : ";
		for (int j = 0; j < n; j++) {
			if (adjMat[i][j] == 1) {
				cout << "person " << (j + 1) << " ";
				count++;
			}
		}

		cout << endl << "Person " << (i + 1) << " has " << count << " friends." << endl;
	}
}

void printComplementaryGraph(int** adjMat, int n) {
	cout << "Adjacency matrix of the complement of the given graph is as follows" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << 1 - adjMat[i][j] << " ";
		}

		cout << endl;
	}
}

int main() {
	cout << "Enter number of nodes : " << endl;
	int n;
	cin >> n;

	int** adjMat = new int*[n];
	for (int i = 0; i < n; i++) {
		adjMat[i] = new int[n];
	}

	cout << "Enter number of edges : " << endl;
	int edgeCount;
	cin >> edgeCount;

	cout << "Enter " << edgeCount << " edges in u v format : " << endl;
	for (int i = 0; i < edgeCount; i++) {
		int u, v;
		cin >> u >> v;

		adjMat[u - 1][v - 1] = 1;
		adjMat[v - 1][u - 1] = 1;
	}

	cout << "Adjacency matrix of the given grapg is as follows" << endl;

	printMatrix(adjMat, n);

	findFriendsOfEachPerson(adjMat, n);

	printComplementaryGraph(adjMat, n);


	return 0;
}
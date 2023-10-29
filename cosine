#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

double calculateCosineSimilarity(int n, int counts[][100], int sentence1, int sentence2) {
    double dotProduct = 0.0;
    double normA = 0.0;
    double normB = 0.0;

    for (int i = 0; i < n; i++) {
        dotProduct += counts[sentence1][i] * counts[sentence2][i];
        normA += counts[sentence1][i] * counts[sentence1][i];
        normB += counts[sentence2][i] * counts[sentence2][i];
    }

    if (normA == 0 || normB == 0) {
        return 0.0;
    }

    return dotProduct / (sqrt(normA) * sqrt(normB));
}

int main() {
    int n;
    cout << "Enter the number of sentences: ";
    cin >> n;
    cin.ignore();
    string arr[100];

    cout << "Enter " << n << " sentences:" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
        for (char& c : arr[i]) {
            c = tolower(c);
        }
    }

    set<string> uniqueWords;
    int counts[n][100] = {0};
    int uniqueWordCount = 0;

    for (int i = 0; i < n; i++) {
        istringstream iss(arr[i]);
        string word;

        while (iss >> word) {
            uniqueWords.insert(word);
        }
    }
    uniqueWordCount = uniqueWords.size();

    string uniqueWordsArray[uniqueWordCount];
    int wordIndex = 0;
    for (const string& word : uniqueWords) {
        uniqueWordsArray[wordIndex] = word;
        wordIndex++;
    }

    for (int i = 0; i < n; i++) {
        istringstream iss(arr[i]);
        string word;

        while (iss >> word) {
            int index = -1;
            for (int j = 0; j < uniqueWordCount; j++) {
                if (uniqueWordsArray[j] == word) {
                    index = j;
                    break;
                }
            }
            if (index != -1) {
                counts[i][index]++;
            }
        }
    }

    cout << "unique = " << uniqueWordCount << endl;
    for (int i = 0; i < uniqueWordCount; i++) {
        cout << uniqueWordsArray[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < uniqueWordCount; j++) {
            cout << counts[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double similarity = calculateCosineSimilarity(uniqueWordCount, counts, i, j);
            cout << "Cosine Similarity between sentence " << i + 1 << " and sentence " << j + 1 << " = " << similarity << endl;
        }
    }
}

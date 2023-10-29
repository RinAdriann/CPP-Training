#include <iostream>
#include <string>
using namespace std;

double sqrt(double x){
    double test, lowest = 0.00001;
    if(x<0){
        return 0.0;
    }
    while((test*test - x) > lowest){
        if((test*test - x) > 0){
            test = 0.5 * (test + x/test);
        }else{
            -1 * (test*test -x);
            test = 0.5 * (test + x/test);
        }
    }
    return test;
}

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
        string uniqueWords[100];
        int counts[100][100] = {0};
        int uniqueWordCount = 0;

        for (int i = 0; i < n; i++) {
            string word;
            int startIndex = 0;

            for (int j = 0; j <= arr[i].length(); j++) {
                if (j == arr[i].length() || isspace(arr[i][j])) {
                    word = arr[i].substr(startIndex, j - startIndex);
                    startIndex = j + 1;

                    bool isUnique = true;
                    for (int k = 0; k < uniqueWordCount; k++){
                        if (uniqueWords[k] == word) {
                            isUnique = false;
                            break;
                        }
                    }
                    if (isUnique){
                        uniqueWords[uniqueWordCount] = word;
                        uniqueWordCount++;
                    }
                }
            }
        }

    for (int i = 0; i < n; i++) {
        string word;
        int startIndex = 0;

        for (int j = 0; j <= arr[i].length(); j++) {
            if (j == arr[i].length() || isspace(arr[i][j])) {
                word = arr[i].substr(startIndex, j - startIndex);
                startIndex = j + 1;

                for (int k = 0; k < uniqueWordCount; k++) {
                    if (uniqueWords[k] == word) {
                        counts[i][k]++;
                        break;
                    }
                }
            }
        }
    }

    cout << "unique = " << uniqueWordCount << endl;
    for (int i = 0; i < uniqueWordCount; i++) {
        cout << uniqueWords[i] << " ";
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

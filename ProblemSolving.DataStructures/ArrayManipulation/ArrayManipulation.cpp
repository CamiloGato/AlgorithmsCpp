#include "ArrayManipulation.h"
#include "../_Common/ArrayCommon.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

long arrayManipulation(int n, std::vector<std::vector<int>> queries)
{
    std::vector<long> arr(n+2, 0);
    long maxValue = 0;
    
    for(auto &query : queries) {
        int a = query[0];
        int b = query[1];
        int k = query[2];

        arr[a] += k;
        arr[b+1] -= k;
    }

    for(int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
        maxValue = std::max(maxValue, arr[i]);
    }
    
    return maxValue;
}

int arrayManipulation()
{

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

    cout << result << "\n";

    return 0;
}

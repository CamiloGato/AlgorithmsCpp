#include "DynamicArray.h"

#include <iostream>

#include "../_Common/ArrayCommon.h"

using namespace std;

std::vector<int> dynamicArray(int n, std::vector<std::vector<int>> queries)
{
    vector<vector<int>> arr;
    vector<int> answers;
    int lastAnswer = 0;

    arr.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        arr.emplace_back();
    }

    for (auto vec : queries)
    {
        int query = vec.at(0);
        int x = vec.at(1);
        int y = vec.at(2);
        
        int idx = ( x ^ lastAnswer ) % n ;

        switch (query)
        {
        case 1:
            arr[idx].emplace_back(y);
            break;
        case 2:
            lastAnswer = arr[idx][y % arr[idx].size()];
            answers.emplace_back(lastAnswer);
            break;
        default:
            break;
        }

    }
    return answers;
}

int dynamicArray()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = dynamicArray(n, queries);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";
    
    return 0;
}


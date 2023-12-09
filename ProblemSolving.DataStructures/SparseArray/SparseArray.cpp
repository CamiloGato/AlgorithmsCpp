#include "SparseArray.h"
#include <iostream>
#include <map>

#include "../_Common/ArrayCommon.h"

using namespace std;

std::vector<int> matchingStrings(std::vector<std::string> stringList, std::vector<std::string> queries)
{
    map<string, int> freq;
    for (const auto &str : stringList) {
        freq[str]++;
    }

    vector<int> result;
    for (const auto &query : queries) {
        result.push_back(freq[query]);
    }

    return result;
}

int sparseArray()
{
    string stringList_count_temp;
    getline(cin, stringList_count_temp);

    int stringList_count = stoi(ltrim(rtrim(stringList_count_temp)));

    vector<string> stringList(stringList_count);

    for (int i = 0; i < stringList_count; i++) {
        string stringList_item;
        getline(cin, stringList_item);

        stringList[i] = stringList_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(stringList, queries);

    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i];

        if (i != res.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

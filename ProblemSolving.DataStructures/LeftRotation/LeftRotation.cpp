#include "LeftRotation.h"

#include <iostream>

#include "../_Common/ArrayCommon.h"

using namespace std;

std::vector<int> rotateLeft(int d, std::vector<int> arr)
{
    vector<int> arrRotated;
    int size = static_cast<int>(arr.size());
    arrRotated.reserve(size);
    
    for (int i = 0; i < size; ++i)
    {
        arrRotated.emplace_back(0);
    }
    
    for (int i = 0; i < size; ++i)
    {
        int newIndex = ((i - d) + size) % size;
        arrRotated[newIndex] = arr[i];
    }

    return arrRotated;
}

int leftRotation()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = rotateLeft(d, arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";


    return 0;
}

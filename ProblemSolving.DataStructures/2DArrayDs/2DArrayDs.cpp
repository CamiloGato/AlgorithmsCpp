#include "2DArrayDs.h"
#include "..\_Common\ArrayCommon.h"

#include <iostream>

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int biggestHourglassSum = 0;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; j++)
        {
            int totalSum =
                arr[i][j] + arr[i][j+1] + arr[i][j+2]
                + arr[i+1][j+1]
                + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (biggestHourglassSum <= totalSum || i == 0 && j == 0)
                biggestHourglassSum = totalSum;
        }
    }
    
    return biggestHourglassSum;
    
}

int arrayDs2D()
{
    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}

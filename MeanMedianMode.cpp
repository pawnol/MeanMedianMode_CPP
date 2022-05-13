/*
Mean Median Mode
Pawelski
5/13/2022
Please follow the instructions on the activity sheet!
*/

#include <iostream>
#include <vector>
#include <algorithm>

/// <summary>
/// Finds the mean of a data set.
/// </summary>
/// <param name="n">The data set consisting of integers.</param>
/// <returns>The mean of the data set. Will include decimals.</returns>
double Mean(std::vector<int> n)
{
    double sum = 0.0;
    for (int i = 0; i < n.size(); i++)
    {
        sum += n[i];
    }
    return sum / n.size();
}

/// <summary>
/// Finds the median of a data set.
/// </summary>
/// <param name="n">The data set consisting of integers.</param>
/// <returns>The median of the data set.</returns>
int Median(std::vector<int> n)
{
    // This sorts the list in order to find the median.
    std::sort(n.begin(), n.end());

    int middle = n.size() / 2;
    if (n.size() % 2 == 0)
    {
        return (n[middle - 1] + n[middle]) / 2.0;
    }
    return n[middle];
}

/// <summary>
/// Finds the mode of a data set.
/// </summary>
/// <param name="n">The data set consisting of integers.</param>
/// <returns>The mode of the data set.</returns>
int Mode(std::vector<int> n)
{
    // This sorts the vector to make it easier to find the mode.
    std::sort(n.begin(), n.end());

    int highest_count = 0;
    int highest_number = n[0];
    int current_highest_count = 1;
    int current_highest_number = n[0];
    for (int i = 1; i < n.size(); i++)
    {
        // Checks if the number matches the previous. If it does, add 1 to count.
        if (n[i] == current_highest_number)
        {
            current_highest_count++;
        }
        // If the numbers are different, this will run.
        else
        {
            // Checks if the current mode count bets the previous.
            // If it does, a new mode has been found and we adjust.
            if (current_highest_count > highest_count)
            {
                highest_count = current_highest_count;
                highest_number = current_highest_number;
            }
            // Resets the current count to start looking for a possible new mode.
            current_highest_count = 1;
            current_highest_number = n[i];
        }
    }
    return highest_number;
}

int main()
{
    const int SENTINEL = -1;
    int user_input = 0;
    std::vector<int> numbers_vector;

    std::cout << "Enter a positive number (-1 to stop) >> ";
    std::cin >> user_input;
    while (user_input != SENTINEL)
    {
        numbers_vector.push_back(user_input);
        std::cout << "Enter a positive number (-1 to stop) >> ";
        std::cin >> user_input;
    }

    std::cout << "Mean: " << Mean(numbers_vector) << "\n";
    std::cout << "Median: " << Median(numbers_vector) << "\n";
    std::cout << "Mode: " << Mode(numbers_vector) << "\n";
    return 0;
}

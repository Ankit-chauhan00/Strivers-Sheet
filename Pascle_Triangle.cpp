// Function to generate a specific row of Pascal's Triangle
vector<int> generateRow(int row) {
    vector<int> temp;
    long long ans = 1;
    temp.push_back(1); // First element is always 1
    for (int i = 1; i < row; i++) {
        // Calculate next element using binomial coefficient formula
        ans = ans * (row - i);
        ans = ans / i;
        temp.push_back(ans);
    }
    return temp;
}

// Function to generate Pascal's Triangle up to numRows
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascle;
    for (int i = 1; i <= numRows; i++) {
        // Add each row to the triangle
        pascle.push_back(generateRow(i));
    }
    return pascle;
}
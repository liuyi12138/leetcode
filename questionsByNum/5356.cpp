class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> mininLine(matrix.size(),100000);
        vector<int> maxinCol(matrix[0].size(),0);
        for(int i = 0; i < matrix.size(); ++i){
            mininLine[i] = matrix[i][0];
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] < mininLine[i])
                    mininLine[i] = matrix[i][j];
                if(matrix[i][j] > maxinCol[j])
                    maxinCol[j] = matrix[i][j];
            }
        }
        vector<int> result;
        for(int i = 0; i < mininLine.size(); ++i){
            for(int j = 0; j < maxinCol.size(); ++j){
                if(mininLine[i] == maxinCol[j])
                    result.push_back(mininLine[i]);
            }
        }
        return result;
    }
};
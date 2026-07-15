class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int box=(i/3)*3+(j/3);
                char num=board[i][j];

                if(rows[i].find(num)!=rows[i].end()||cols[j].find(num)!=cols[j].end()||boxes[box].find(num)!=boxes[box].end()){
                    return false;
                }
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }
        return true;
    }
};

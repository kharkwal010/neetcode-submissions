class TrieNode{
    public:
        unordered_map<char, TrieNode*> child;
        bool end = false;
};

class Solution {
public:
    set<pair<int, int>> visited;
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>& board, TrieNode* root, int r, int c, vector<string>& ans, string str){
        if(r<0 || c<0 || r>=board.size()|| c>=board[0].size() || visited.count({r,c})) return;
        if(root->child.find(board[r][c])==root->child.end()) return;
        visited.insert({r,c});
        root = root->child[board[r][c]];
        str.push_back(board[r][c]);
        if(root->end){
            ans.push_back(str);
            root->end = false;
        }
        for(int i=0; i<4; i++){
            dfs(board, root, r+dir[i][0], c+dir[i][1], ans, str);
        }
        visited.erase({r,c});
        return;       
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word: words){
            TrieNode* curr = root;  
            for(char w: word){
                if(curr->child.find(w)==curr->child.end()){
                    curr->child[w]= new TrieNode();
                }
                curr= curr->child[w];
            }
            curr->end = true;
        }
        vector<string> ans;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                dfs(board, root, i, j, ans, "");
            }
        }
        return ans;        
    }
};

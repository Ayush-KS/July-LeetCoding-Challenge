# Word Search

class Solution:
    def dfs(self, board: List[List[str]], word: str, i: int, j: int, x: int, visited: List[List[bool]]):
        
        if x == len(word):
            return 1
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or visited[i][j]:
            return 0
    
        if board[i][j] != word[x]:
            return 0
        
        visited[i][j] = 1
        
        if self.dfs(board, word, i + 1, j, x + 1, visited) or self.dfs(board, word, i - 1, j, x + 1, visited) or self.dfs(board, word, i, j + 1, x + 1, visited) or self.dfs(board, word, i, j - 1, x + 1, visited):
            return 1
        
        visited[i][j] = 0
        return 0
    
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        rows, cols = (len(board), len(board[0]))
        visited = [[0 for i in range(cols)] for j in range(rows)] 
        
        for i in range(rows):
            for j in range(cols):
                if self.dfs(board, word, i, j, 0, visited):
                    return 1
        
        return 0
        
        
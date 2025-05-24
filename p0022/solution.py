class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.result = []
        def backtrack(s, open_count, close_count):
            if len(s) == 2*n:
                self.result.append(s)
                return
            if open_count < n:
                backtrack(s + "(" , open_count+1, close_count)
            if close_count < open_count:
                backtrack(s + ")" , open_count, close_count + 1)
        backtrack("", 0, 0)
        return self.result
    
# Example usage:
if __name__ == "__main__":
    for i in range(1, 9):
        print(f"n = {i}:")
        solution = Solution()
        print(solution.generateParenthesis(i))
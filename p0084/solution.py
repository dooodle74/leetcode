class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        # index is the left point of the bar (helps with bounds - shape strictly between 0.0 and n.0)
        # observation: in forward-pass stack, we already know the left-limit 
        # in increasing sequence, the previous stack element (index + 1) is farthest left it can go
        # if this is first of stack, no previous elements are lower that can block, thus index 0 is farthest left

        n = len(heights)
        stack = []
        max_area = 0

        for i in range(n):
            while stack and heights[stack[-1]] > heights[i]:
                j = stack.pop()
                # left limit: 0 (INCLUSIVE) if end of stack (nothing blocks to the left)
                # else, left limit is next stack element (NOT INCLUSIVE)
                left_limit = 0
                if stack:
                    left_limit = stack[-1] + 1
                # area starting including left_limit expanding to i (EXCLUSIVE), maximum height j
                max_area = max(max_area, (i - left_limit) * heights[j])
            # branch taken: append current increasing after all higher has popped
            # branch not taken: append increasing seq as usual
            stack.append(i)

        # end loop - save additional results if final sequence is increasing (unfinished stack)
        while stack:
            i = stack.pop()
            left_limit = 0
            if stack:
                left_limit = stack[-1] + 1
            # use n here as the end of array
            max_area = max(max_area, (n - left_limit) * heights[i])

        return max_area         

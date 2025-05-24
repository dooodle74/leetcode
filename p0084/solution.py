class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        # observation: in forward-pass stack, we already know the left-limit 
        # in increasing sequence, current is precisely the left limit
        # upon decrease, use index at top of stack to determine left limit

        n = len(heights)
        stack = []
        max_area = 0

        for i in range(n):
            while stack and heights[stack[-1]] > heights[i]:
                j = stack.pop()
                # area starting including j expanding to i, maximum height j
                max_area = max(max_area, (i-j) * heights[j])
            # branch taken: append current increasing after all higher has popped
            # branch not taken: append increasing seq as usual
            stack.append(i)
            # update max given left limit from top of stack (first (leftmost) smaller element)
            # add 1 to include this as bar as well
            left_idx = 0
            if stack:
                left_idx = stack[-1]
            max_area = max(max_area, (i - left_idx + 1) * heights[i])

        # end loop - save additional results if final sequence is increasing (unfinished stack)
        while stack:
            i = stack.pop()
            max_area = max(max_area, (n-i) * heights[i])

        return max_area         

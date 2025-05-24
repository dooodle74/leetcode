class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        # observation: in forward-pass stack, we already know the left-limit 
        # in increasing sequence, current is precisely the left limit
        # upon decrease, count number of pops made to determine left limit

        n = len(heights)
        stack = []
        max_area = 0

        for i in range(n):
            count_pops = 0
            while stack and heights[stack[-1]] > heights[i]:
                j = stack.pop()
                count_pops += 1
                # area starting including j expanding to i, maximum height j
                max_area = max(max_area, (i-j) * heights[j])
            # branch taken: append current increasing after all higher has popped
            # branch not taken: append increasing seq as usual
            stack.append(i)
            # update max given left limit by counting left-pops until smaller
            # add 1 to include this as bar as well
            max_area = max(max_area, (count_pops + 1) * heights[i])

        # end loop - save additional results if final sequence is increasing (unfinished stack)
        while stack:
            i = stack.pop()
            max_area = max(max_area, (n-i) * heights[i])

        return max_area         

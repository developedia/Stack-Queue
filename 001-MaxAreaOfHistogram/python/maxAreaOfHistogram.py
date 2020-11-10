# Given histogram
histogram = [6, 2, 5, 4, 5, 1, 6]
n = len(histogram)

# Update maxArea
def updateMaxArea(maxArea, stk, rightMost):
    h = histogram[stk[-1]]
    stk.pop()
    l = 0 if not stk else stk[-1] + 1
    r = rightMost - 1
    return max(maxArea, h * (r - l + 1))

# Get maximum rectangular area in O(n) time
def getMaxRectangularArea():
    stk = []
    maxArea = 0

    # Push all the elements in the stack exactly once
    for rightMost in range(n):
        while stk and histogram[stk[-1]] > histogram[rightMost]:
            maxArea = updateMaxArea(maxArea, stk, rightMost)
        stk.append(rightMost)

    # Pop elements out of the stack until it's empty
    while stk:
        maxArea = updateMaxArea(maxArea, stk, n)

    return maxArea

if __name__ == '__main__':
    print(getMaxRectangularArea())

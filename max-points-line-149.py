import math

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        lines = dict()
        length = len(points)
        for i in range(0, length - 1):
            for j in range(i + 1, length):
                x1, y1 = points[i]
                x2, y2 = points[j]
                line = Line(x1, y1, x2, y2)
                if line in lines:
                    lines[line].add(tuple(points[i]))
                    lines[line].add(tuple(points[j]))
                else:
                    lines[line] = {tuple(points[i]), tuple(points[j])}
        if len(lines) == 0:
            return 1
        return max(len(lines[i]) for i in lines)

class Line:
    def __init__(self, x1, y1, x2, y2):
        if x1 == x2:
            self.slope = None
            self.intercept = x1
        else:
            self.slope = (y2 - y1)/(x2 - x1)
            self.intercept = y1 - self.slope*x1
    def fits(self, x, y):
        if self.slope == None:
            return x == slope.intercept
        return math.isclose(y, self.slope*x + self.intercept)
    def __repr__(self):
        return f'{self.slope=}, {self.intercept=}'
    def __hash__(self):
        return hash((self.slope, self.intercept))
    def __eq__(self, other):
        if self.slope == None or other.slope == None:
            if self.slope == other.slope:
                return self.intercept == other.intercept
            return False
        return (math.isclose(self.slope, other.slope) 
                and math.isclose(self.intercept, other.intercept))

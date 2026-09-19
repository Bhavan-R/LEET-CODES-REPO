class Solution(object):
    def checkOverlap(self, radius, xCenter, yCenter, x1, y1, x2, y2):
        closestX = max(x1, min(xCenter, x2))
        closestY = max(y1, min(yCenter, y2))
        
        distX = xCenter - closestX
        distY = yCenter - closestY
        
        return (distX ** 2 + distY ** 2) <= (radius ** 2)

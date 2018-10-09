
#Imports
import numpy
import cv2
import queue
import math
#import matplotlib.pyplot as plt
import time
import csv
import cProfile, pstats, io
sqrt2 = math.sqrt(2)


def findPath(m, start, goal, freespace = 0):
    '''
    Finds the path using an A* algorithm
    
    :param filename: name of file for use of pathfinding
    :param origin: a tuple with the X and Y coordinates of the origin
    :param goal: a tuple with the X and Y coordinates of the goal
    :param freespace: optional param for an array of acceptable values
    
    :return current, parents, costs[current]: returns a list of the parents, the current(goal achieved) point, ans its cost
    :return parents, costs: returns the explored area and its costs if no goal found
    '''

    
    #start = (origin_x, origin_y)            #sets origin, goal points
    #goal = (goal_x, goal_y)

    frontier = queue.PriorityQueue()        #uses prioirty queue to prioritize points closer to the goal
    for point in start:
        frontier.put((0, point))

    parents = {}                            #list of parents for traceback of goalpoint
    for point in start:
        parents[point] = None

    costs = {}                              #list of costs to keep track of previous locations
    for point in start:
        costs[point] = 0
    
    current = (0,0)
    while not frontier.empty():             #loop through frontier
        current = frontier.get()[1]         #acquire a block

        #if current == goal :                #check if its the goal
        #    print("\n Path found ! ")
        #    return current, parents, costs


        if  current[0] >= len(m) or current[0] < 0 or current[1] >= len(m[0]) or current[1] < 0:
            #print("out of bounds")
            continue        #if the index is out of bounds even though maps should be completely enclosed...


        if numpy.all(m[current[0]][current[1]] != freespace):
            continue
        
        #print(current)
        #print(costs[current])
 
        for next in neighbors(current):     #iterate through the neighbors of a point

            
            this_cost = costs[current] + dist(current, next) #calculate cost for minimal distance
            
            

            
            if not next in costs or this_cost < costs[next]: #if neighbor is new / has new low cost
                
                costs[next] = this_cost
                
                p = this_cost + heur(next, goal)
                
                frontier.put((p, next))
                parents[next] = current
               

    #print("Failed")

    return goal, parents, costs

    


def neighbors(point):
    '''
    returns the eight nearby points of one point
    
    :param point: the point to be analyzed
    
    :return result: a tuple of the neighbors 
    '''
    x,y = point
    result =   [ (x-1 , y-1) , (x , y-1) , (x+1 , y-1) ,      #all nearby indicies
                 (x-1 , y  ) ,             (x+1 , y  ) ,
                 (x-1 , y+1) , (x , y+1) , (x+1 , y+1) ]
    
    #OLD
    #for near in neighbors:                          #iterate through indecies list
    #    result.append(( point[0] + near[0] , point[1] + near[1] ))      #Add all indecies to point, append
    return result

def heur(end, check):
    '''
    returns the goemetric distance between two points using diagonal and grid lines for distance
    
    :param end: the end point to be compared
    :param check: the point to be checked
    
    :return distance: the distance between the two points
    '''
    #old manhattan
    #result = math.fabs(end[0] - check[0]) + math.fabs(end[1] - check[1])
    #old pythagoran
    #result = math.sqrt((end[0] - check[0])**2 + (end[1] - check[1]) **2) 
    
    #new - from Hunter cause its smart
    dx = abs(end[0] - check[0])
    dy = abs(end[1] - check[1])

    result = min(dx, dy) * sqrt2 + abs(dx-dy)     

    return result


def dist(start, end): 
    '''
    returns the distance to a neighbor
    
    :param start: the original point
    :param end: the point to be measured to
    
    :return distance: returns the neighboring distance
    '''

    
    if start[0] == end[0] or start[1] == end[1]: #if not on the same line
        return 1
    else: 
        return sqrt2


def aStar(start, goal, occupancyGrid, free = 255):
    win, parents, cost = findPath(occupancyGrid, start, goal, freespace = free)
    #print(parents)
    if not win in cost.keys():
        l = [(0,0)]
        l.extend(start)
        return l, parents, cost, max(cost.values())
    else:
        path = []
        trace = win
        while trace != None:
            path.append(trace)
            trace = parents[trace]
        return path, parents, cost, max(cost.values())


def getColor(cost, maxCost):
    section = cost/maxCost*4
    #print(section)
    diff    = int(   ( cost%(maxCost/4) )/maxCost*4*255   )
    #print(diff)
    if section< 1:
        return(255, diff, 0)
    elif section < 2:
        return(255-diff, 255, 0)
    elif section < 3:
        return(0, 255, diff)
    else:
        return (0, 255-diff, 255)        



if __name__ == "__main__":

    maze = 1
    profile = False

    if maze ==0:
        freespace = 255
        map = cv2.imread("Maze.png", 1)
        begin   = [(1,155)]                 
        end     = (319, 168)

    elif maze==1:
        freespace = 255
        map = cv2.imread("BigMaze.png", 1)
        begin   = [(3,3)]                
        end     = (1785, 1799)

    elif maze==2:
        freespace = 255
        map = cv2.imread("NotMaze.jpg", 1)
        begin   = [(1,1)]                
        end     = (423, 1068)
    elif maze==3:
        freespace = 0
        map = cv2.imread("Maze.png", 1)
        begin   = [(1,1), (1, 321)]                 
        end     = (322, 322)

    elif maze==4:
        freespace = 0
        map = cv2.imread("BigMaze.png", 1)
        begin   = [(1,10), (1,1)]                 
        end     = (1801, 1801)
    else:
        print("unknown Maze")
        

    
    
    newMap = map
    
    	
    
    if profile:
        pr = cProfile.Profile()
        pr.enable()
    else:
        start = time.time()

    path, parents, costs, maxCost = aStar(begin, end, map, free = freespace)

    if profile:
        pr.disable()
        s = io.StringIO()
        sortby = 'cumulative'
        ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
        ps.print_stats()
        print(s.getvalue())
    else:
        length = time.time() - start
        print("Took this much time: {}".format(length))


    for point in parents.keys():
        if  point[0] >= len(map) or point[0] < 0 or point[1] >= len(map[0]) or point[1] < 0:
            #print("out of bounds")
            continue  
        if numpy.all(map[point[0]][point[1]] == freespace):
            #print (getColor(costs[(point[0],point[1])], maxCost))
            newMap[point[0]][point[1]] = getColor(costs[(point[0],point[1])], maxCost)
    

    for point in path:
        if  point[0] >= len(map) or point[0] < 0 or point[1] >= len(map[0]) or point[1] < 0:
            #print("out of bounds")
            continue
        #print(point)
        newMap[point[0]][point[1]] = (255, 0, 255)

    cv2.namedWindow("AStar", cv2.WINDOW_NORMAL)

    cv2.imshow("AStar", newMap)
    cv2.waitKey(0)
    

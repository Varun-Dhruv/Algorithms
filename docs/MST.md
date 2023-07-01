## Definition

### Spanning Tree

A tree in which we have N nodes and N-1 edges && all nodes are reachable from each other.

### Minimum Spanning Tree

Any Spanning tree with the least sum is called Minimum spanning tree.

## MST Algorithms

### Prims Algorithm

#### Required data structures

1. Min heap
2. Visited array
3. Mst list that will store all the edges that are a part of MST

Datatypes of our data structures
Visited array => int
Mst list => (weight , node name , node parent)

Steps

1. Mark the visited array as 0 for all the nodes

2. Start with 0th node and push
   (0,0,-1)
   explanation: -1 means 0 is the genesis node
   Mark 0 as visited

3. Push all the neighbours of 0 in pq Do not mark them visited (footnote 1)
   Since its a min heap the edge with minimum weight will be at the top

4. Pick up the top edge , insert it in the mst , mark the picked node as visited , insert all neighbours of picked node into pq

5. keep repeating steps 3 and 4 untill all the nodes have been picked up and thats when the algorithm ends

#### Footnote:

1. why to not mark it visited?
   in bfs , when we push the element inside a queue we mark it as visited cause that element will be picked up later for sure (algorithm ends only when the queue is empty )
   but in msts case even if we push the edge into pq , theres no surety that the edge will be picked up . when prims algo ends there are still a few non accepted edges present in the pq hence we only mark it visited once its picked up from pq

### Kruskal Algorithm

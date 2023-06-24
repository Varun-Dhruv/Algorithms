## Topological Sort

In a topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

Points to remember-

<ul>
<li>Topolgical Sort can only be applied in Directed Acyclic Graph</li>
<li>If the graph has a cycle the size of topologicalSort vector will be less than total number of nodes
i.e topoSort.size() < V </li>
</ul>

from collections import defaultdict, deque
from Queue import Queue
import unittest


class Graph:
    def __init__(self, adj_list):
        """
        Process the graph with the given adjacent list.
        :param adj_list:
            The given adjacent list. A dictionary with parent node as keys and
            values as set of the adjacent nodes.
        """
        self.adj_list = adj_list

    def bfs(self, start):
        node_q = Queue()
        node_q.put(start)
        visited = set()
        while not node_q.empty():
            node = node_q.get()   # FIFO
            if node not in visited:
                yield node
                visited.add(node)
                node_q.queue.extend(self.adj_list[node] - visited)

    def bfs_path(self, start, end):
        node_q = Queue()
        node_q.put((start, [start]))
        visited = {start}

        while not node_q.empty():
            parent, path = node_q.get()
            for child in self.adj_list[parent]:
                if child not in visited:
                    if child == end:
                        yield path + [child]
                    else:
                        visited.add(child)
                        node_q.put((child, path + [child]))

    def connected_component(self):
        count = 0
        visited = set()
        connected_components = []

        for node in self.adj_list.keys():
            if node not in visited:
                count += 1
                bfs_nodes = list(self.bfs(node))
                for node in bfs_nodes:
                    visited.add(node)
                connected_components.append(bfs_nodes)

        return count, connected_components

    def dfs(self, start, adj_list, visited=None):
        node_s = deque()
        node_s.append(start)
        if visited is None:
            visited = set()

        while node_s:
            node = node_s.pop()
            if node not in visited:
                yield node
                visited.add(node)
                node_s.extend(adj_list[node] - visited)

    def strongly_connected_component(self):
        """
        Kosaraju's Algorithm.
        """
        finish_time_stack = []
        strongly_connected_components = []
        visited = set()

        def dfs_util(start):
            """
            Subroutine to compute the finishing time stack. Iterative approach
            is preferred to avoid exceeding recursion depth.
            """
            node_s = deque()
            node_s.append(start)
            pop_set = set() # for memoization of the processed elements.
            while node_s:
                node = node_s[-1]
                visit_next = None   # for boundary condition.
                if node not in visited:
                    visited.add(node)
                    visit_next = self.adj_list[node] - visited
                    node_s.extend(visit_next)

                if not visit_next:
                    node = node_s.pop()
                    if node not in pop_set:
                        finish_time_stack.append(node)
                        pop_set.add(node)

        # d.keys() creates a static list of the dictionary keys.
        # Otherwise, we get a pretty neat exception while processing
        # large graphs.
        # "RuntimeError: dictionary changed size during iteration".
        for node in self.adj_list.keys():
            if node not in visited:
                dfs_util(node)

        # Graph transpose can also be done while reading the file for optimisation.
        adj_list_invert = defaultdict(set)
        for head, tail in self.adj_list.items():
            for node in tail:
                adj_list_invert[node].add(head)

        visited = set()
        while finish_time_stack:
            start = finish_time_stack.pop()
            if start not in visited:
                newly_visited = set(self.dfs(start, adj_list_invert, visited))
                visited.update(newly_visited)
                strongly_connected_components.append(newly_visited)

        return strongly_connected_components


class GraphTest(unittest.TestCase):
    def setUp(self):
        self.graph = Graph({'A': set(['B', 'C']),
                            'B': set(['A', 'D', 'E']),
                            'C': set(['A', 'F']),
                            'D': set(['B']),
                            'E': set(['B', 'F', 'G']),
                            'F': set(['C', 'E']),
                            'G': set()})

    def test_bfs(self):
        self.assertEqual(list(self.graph.bfs('A')),
                         ['A', 'C', 'B', 'F', 'E', 'D', 'G'])

    def test_bfs_path(self):
        self.assertEqual(list(self.graph.bfs_path('A', 'E')),
                         [['A', 'B', 'E'], ['A', 'C', 'F', 'E']])

    def test_connected_component(self):
        self.graph = Graph({'A': set(['B', 'C']),
                            'B': set(['C', 'A']),
                            'C': set(['A', 'B']),
                            'D': set(),
                            'E': set(['F']),
                            'F': set(['E'])})
        self.assertEqual(self.graph.connected_component(),
                         (3, [['A', 'C', 'B'],
                              ['E', 'F'],
                              ['D']]))
    def test_dfs(self):
        self.graph = Graph({'A': set(['B']),
                            'B': set(['C', 'D']),
                            'C': set(['A']),
                            'D': set('E'),
                            'E': set()})
        self.assertEqual(list(self.graph.dfs('A', self.graph.adj_list)),
                         ['A', 'B', 'D', 'E', 'C'])

    def test_strongly_connected_components(self):
        self.graph = Graph({1: set([2]),
                            2: set([3,4,6]),
                            3: set([1,4]),
                            4: set([5]),
                            5: set([4]),
                            6: set([5,7]),
                            7: set([6,8]),
                            8: set([5,7])})

        self.assertEqual(self.graph.strongly_connected_component(),
                         [{1,3,2}, {6,7,8}, {5,4}])


if __name__ == "__main__":
    unittest.main()

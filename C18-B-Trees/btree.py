import bisect

# See Cormen et al, chapter 18 B-Trees
# This is an implementation of B-Tree with satellite information stored in internal nodes
# as well as in leaves.

def main():
    def allocme():
        nonlocal blocks
        idx = len(blocks)
        blocks.append(None)
        print("a new block #{} has been allocated.".format(idx))
        return idx

    def freeme(page, root):
        print("the block #{} has been deallocated".format(page))
        nonlocal blocks
        nonlocal treeroot
        blocks[page] = None
        if (treeroot != root):
            print("new root is: #{}".format(root))
            treeroot = root

    def writeme(page, root, *node):  # page - what allocme() returns,
                                     # treeroot - the reference to the root of the btree
                                     # *node - serialized key-value
                                     # pairs of BTree node's params (keys)
        print("write me to block #{}: ".format(page), node)
        nonlocal blocks
        nonlocal treeroot
        blocks[page] = node
        treeroot = root

    def readme(page):  # page - what allocme() returns. The method must return keys, childpages
        # if no leaf, childpage[i] with keys < keys[i], childpages[i+1] with keys > keys[i]
        nonlocal blocks
        data = blocks[page]
        print("read me from block #{}: ".format(page), data[0], data[1])
        return data[0], data[1]

    blocks = []
    treeroot = 0

# check the page format
#    blocks.append(([('a',), ('b',)], [1]))
#    print(blocks)
#    tree = BTree(t = 4, allocate = allocme, read = readme, write = writeme)
#    tree.load(treeroot)
#    tree.insert('c', 10)
#    print(blocks)

    tree = BTree(allocate = allocme)
    tree.create()
    tree.create()
    tree.create()
    print(blocks)
    print(treeroot)

    blocks = []
    treeroot = 0

    tree2 = BTree(t = 2, allocate = allocme, free = freeme, read = readme, write = writeme)
    tree2.create()
    ins = tree2.insert('a', 10)
    print("'a' inserted:", ins)
    ins = tree2.insert('a', 11)
    print("'a' inserted:", ins)
    value = tree2.find('a')
    print("value for 'a':", value)
    ins = tree2.insert('a', 1)
    print("'a' inserted:", ins)
    tree2.insert('b', 2)
    tree2.insert('c', 3)
    # firstly, split root here
    tree2.insert('f', 6)
    print(blocks)
    print(treeroot)
    # insert in a non full node
    tree2.insert('d', 4)
    # insert in a full node
    tree2.insert('e', 5)
    print(blocks)
    print(treeroot)
    ins = tree2.insert('g', 7)
    print(ins)
    print(blocks)
    print(treeroot)
    ins = tree2.insert('g', 8)
    print(ins)
    print(blocks)
    print(treeroot)
    ins = tree2.insert('g', 9)
    print(ins)
    print(blocks)
    print(treeroot)
    tree2.insert('h', 10)
    tree2.insert('k', 11)
    tree2.insert('l', None)
    print(blocks)
    print(treeroot)

    tree3 = BTree(t = 2, allocate = allocme, free = freeme, read = readme, write = writeme)
    tree3.load(treeroot)
    tree3.insert('m', 13)
    print(blocks)
    print(treeroot)

    # let's find something
    print("find nodes")
    tree4 = BTree(t = 2, allocate = allocme, free = freeme, read = readme, write = writeme)
    tree4.load(treeroot)
    print("value for 'a':", tree4.find('a'), "(True, 1)")
    print("value for 'b':", tree4.find('b'), "(True, 2)")
    print("value for 'c':", tree4.find('c'), "(True, 3)")
    print("value for 'd':", tree4.find('d'), "(True, 4)")
    print("value for 'e':", tree4.find('e'), "(True, 5)")
    print("value for 'g':", tree4.find('g'), "(True, 9)")
    print("value for 'h':", tree4.find('h'), "(True, 10)")
    print("value for 'k':", tree4.find('k'), "(True, 11)")
    print("value for 'm':", tree4.find('m'), "(True, 13)")
    print("value for 'l':", tree4.find('l'), "(True, None)")
    print("value for 'f':", tree4.find('f'), "(True, 6)")
    print("value for 'z':", tree4.find('z'), "(False, None)")
    print(blocks)
    print(treeroot)

    tree4.insert('o', 14)
    tree4.insert('p', 15)
    tree4.insert('n', 16)
    print(blocks)
    print(treeroot)

    print("remove something")
    print("removing 'g'")                      # 3a, 3b
    removed = tree4.remove('g')
    print("removing 'g', removed:", removed)
    print(blocks)
    print(treeroot)
    print("removing 'e'")                      # 3b, 3a
    removed = tree4.remove('e')
    print("removing 'e', removed:", removed)
    print(blocks)
    print(treeroot)
    print("removing 'o'")                      # 2a
    removed = tree4.remove('o')
    print("removing 'o', removed:", removed)
    print(blocks)
    print(treeroot)
    print("removing 'a'")                      # 3a 3b (preparing for 2c, see bellow)
    removed = tree4.remove('a')
    print("removing 'a', removed:", removed)
    print(blocks)
    print(treeroot)
    print("removing 'h'")                      # 2b
    removed = tree4.remove('h')
    print("removing 'h', removed:", removed)
    print(blocks)
    print(treeroot)
    print("removing root")
    print("removing 'f'")                      # changing root
    removed = tree4.remove('f')
    print("removing 'f', removed:", removed)
    print(blocks)
    print(treeroot)
    print("removing 'z'")
    removed = tree4.remove('z')
    print("removing 'z', removed:", removed)
    print(blocks)
    print(treeroot)
    print("removing 'b'")
    removed = tree4.remove('b')
    print("removing 'b', removed:", removed)
    print(blocks)
    print(treeroot)
    print("removing 'd'")                      # 2c
    removed = tree4.remove('d')
    print("removing 'd', removed:", removed)
    print(blocks)
    print(treeroot)

class BTree:
    def __init__(self, t = 2, allocate = None, free = None, read = None, write = None):
        """
        Constructs a new btree with the minimum degree (t) = 't'. The methods of the btree are
        going to use the 'allocate', 'write' and 'read' methods to work with the storage the tree is
        persisted to.

        Args:
        -----
        t (int) - the minimum degree of the btree (see the definition of b-trees in Cormen et al, 18.1)
        allocate (function) - a callback that allocates a new storage page to be used as a new node.
        free (function) - a callback that removes pages from the storage
        read (function) - a callback that reads pages from the storage.
        write (function) - a callback that writes pages into the storage.
        """
        self.__allocate = allocate
        self.__free = free
        self.__write = write
        self.__read = read
        self.__t = t         # TODO 't' can be calculated based on page-size, key-size, ptr-size and satellite-data-size
        self.__root = None

    def find(self, key):
        """
        Takes as input a key 'key' to be searched for in this tree. If 'key' is in the tree, the method
        returns 'True' and the value associated with the key. Otherwise, the method returns 'False, None'.

        Args:
        -----
        key - an input keey to be searched for in the tree.

        Returns:
        --------
        'found, value' where 'found' (True/False) whether the key is in the tree, 
        'value' is the value associated with the key 'key'.

        Exceptions:
        -----------
        BTreeNotInitializedError if the method is invoked on an unitialized (created or loaded) btree.

        BTreeInvalidNodeError while a btree that doesn't have btree property five described in Cormen et al 18.1:
        (t - the minimum degree of the btree) the root may contain at most '2t - 1' keys, if the root is an internal
        node, it may have at most '2t' children.
        """
        if not self.__root:
            raise BTreeNotInitializedError()

        return self.__find(self.__root, key)

    def create(self):
        """
        Creates an empty root node for the tree. To build a b-tree, we first use the method to create
        an empty root node and then call 'insert' to add new keys. Both of these methods use an auxiliary
        function 'allocate', a parameter of the object 'self'.
        """
        del self.__root
        self.__root = self.Node(self.__t, self.__allocate())
        return

    def load(self, root):
        """
        Loads the root of the tree. Before searching through the tree, the root must be loaded into the main
        memory otherwise a BTreeNotInitializedError will be raised. The method uses an auxiliary function 'read'
        to load pages into the main memory.

        Args:
        -----
        root - a reference to the root in the storage. The reference must be matched with the value returned
        by the axiliary function 'allocate' during the invocation of the 'create' method.

        Exceptions:
        -----------
        BTreeInvalidNodeError while a btree that doesn't have btree property five described in Cormen et al 18.1:
        (t - the minimum degree of the btree) the root may contain at most '2t - 1' keys, if the root is an internal
        node, it may have at most '2t' children.
        """
        del self.__root
        self.__root = self.Node(self.__t, root)
        self.__read_page(self.__root, True)

    def insert(self, key, value):
        """
        Inserts the new key 'key' and associated with it satellite data 'value' in a leaf as well as an intermediate
        node. So, the simplest btree (not a b+ tree) strategy is implemented. Value 'value' can be any satellite data,
        but take into account the data will be stored in pages increasing by themselves the minimum degree of the btree
        (t) and thus the fragmentation.

        'None' cannot be used as a key. 'None' can be used as a value but the method 'find' returns
        'None' if the key is out of the tree.

        Args:
        -----
        key - a key for the being stored value 'value'.
        value - a value associated with the key.

        Returns:
        --------
        'True' if the key has actually been added to the tree, 'False' otherwise but the value for the key will
        be overwritten in any case.

        Exceptions:
        -----------
        BTreeNotInitializedError if the method is invoked on an unitialized (created or loaded) btree.

        BTreeInvalidNodeError while a btree that doesn't have btree property five described in Cormen et al 18.1:
        (t - the minimum degree of the btree) every node other than the root must have at least 't - 1' keys. Every
        internal node other than the root thus has at least 't' children. Every node may have at most '2t - 1' keys
        and if it is an internal node, it may have at most '2t' children.
        """
        if not self.__root:
            raise BTreeNotInitializedError()

        if self.__root.full():
            self.__split_root()

        return self.__insert_in_nonfull(self.__root, key, value)

    def remove(self, key):
        """
        Removes the key 'key' from the tree. Before searching through the tree, the root must be loaded into the main
        memory otherwise a BTreeNotInitializedError will be raised. The method uses the following auxiliary functions:
        'read' to load pages into the main memory, 'write' to save changed pages into the storage, and 'free' to remove
        a page from the storage.

        Args:
        -----
        key - a key for being removed.

        Returns:
        --------
        'True' if the key has actually been removed from the tree, 'False' otherwise.

        Exceptions:
        -----------
        BTreeNotInitializedError if the method is invoked on an unitialized (created or loaded) btree.

        BTreeInvalidNodeError while a btree that doesn't have btree property five described in Cormen et al 18.1:
        (t - the minimum degree of the btree) the root may contain at most '2t - 1' keys, if the root is an internal
        node, it may have at most '2t' children.
        """
        if not self.__root:
            raise BTreeNotInitializedError()

        result = self.__remove(self.__root, key)
        if self.__root.empty():
            exroot = self.__root
            self.load(exroot.major().page()) # invariant: root is always in the mm
            self.__free_page(exroot)
        return result

    def __find(self, node, key):
        found, value, child = node.find(key)
        self.__flush_page(node)
        if not found and not node.leaf():
            self.__read_page(child)
            return self.__find(child, key)
        return found, value

    def __split_root(self):
        exroot = self.__root
        newroot = self.Node(self.__t, self.__allocate(), False)
        newroot.insert(None, None, exroot)
        _, newright = self.__split_child(newroot, exroot)
        self.__root = newroot
        self.__flush_page(exroot)
        self.__flush_page(newright)

    def __insert_in_nonfull(self, node, key, value):
        dest = node
        while not dest.leaf():
            _, _, child = dest.find(key)
            self.__read_page(child)
            if child.full():
                median, next = self.__split_child(dest, child)
                if key > median:
                    self.__flush_page(child)
                    child = next
                else:
                    self.__flush_page(next)
            self.__flush_page(dest)  # both pages: dest and its child must be keep
                                     # loaded in the main memory during a split
            dest = child

        result = dest.insert(key, value)
        self.__write_page(dest)
        self.__flush_page(dest)
        return result

    def __split_child(self, node, child):
        # returns median, newnode
        if node.leaf():
            return None, None
        newnode = self.Node(self.__t, self.__allocate(), child.leaf())
        median = child.split(node, newnode)
        self.__write_page(node)
        self.__write_page(child)
        self.__write_page(newnode)
        return median, newnode

    def __remove(self, node, key):
        found, value, child = node.find(key)
        if found:
            if node.leaf():
                # case 1
                result = node.remove(key)
            else:
                self.__read_page(child)
                if child.hasminimum():
                    # case 2a
                    newkey, newvalue = self.__remove_predecessor(child)
                    result = node.replace(key, newkey, newvalue)
                else:
                    _, follow = node.siblings(key)
                    _, _, follow = follow
                    self.__read_page(follow)
                    if follow.hasminimum():
                        # case 2b
                        self.__flush_page(child)
                        newkey, newvalue = self.__remove_successor(follow)
                        result = node.replace(key, newkey, newvalue)
                    else:
                        # case 2c
                        child.join(key, value, follow)
                        # special case, we will go into recursion thus all pages must be flushed (exc. child)
                        self.__write_page(child)
                        self.__free_page(follow)
                        node.remove(key)
                        self.__write_page(node)
                        self.__flush_page(node)
                        return self.__remove(child, key)
            self.__write_page(node)
            self.__flush_page(node)
            return result
        else:
            if node.leaf():
                # do nothing, the key is out of the tree
                return False
            self.__read_page(child)
            if not child.hasminimum():
                left, right = node.siblings(key)
                child = self.__extend_child(node, child, left, right)  # the left sibling can be the new child
            self.__flush_page(node)
            return self.__remove(child, key)

    def __remove_predecessor(self, node):
        # returns the predecessor key,value
        current = node
        while not current.leaf():
            right_child = current.minor()
            self.__read_page(right_child)
            if not right_child.hasminimum():
                left_sibling = current.second_rightest()
                right_child = self.__extend_child(current, right_child, left = left_sibling)
            self.__flush_page(current)
            current = right_child

        right_key, right_value = current.remove_rightest()
        self.__write_page(current)
        self.__flush_page(current)
        return right_key, right_value

    def __remove_successor(self, node):
        # returns the successor key,value
        current = node
        while not current.leaf():
            left_child = current.major()
            self.__read_page(left_child)
            if not left_child.hasminimum():
                right_sibling = current.second_leftest()
                left_child = self.__extend_child(current, left_child, right = right_sibling)
            self.__flush_page(current)
            current = left_child

        left_key, left_value = current.remove_leftest()
        self.__write_page(current)
        self.__flush_page(current)
        return left_key, left_value

    def __extend_child(self, node, child, left = None, right = None):
        good_sibling = None
        if left:
            leftkey, leftval, left = left
            self.__read_page(left)
        if left and left.hasminimum():
            good_sibling = left
            sibling_extra = left.rightest()
            remove_right = True # rightest() returns a reference to the right
            parentkey, parentval = leftkey, leftval
        else:
            if right:
                rightkey, rightval, right = right
                self.__read_page(right)
            if right and right.hasminimum():
                if left:
                    self.__flush_page(left)
                good_sibling = right
                sibling_extra = right.leftest()
                remove_right = False # leftest() returns a reference to the left
                parentkey, parentval = rightkey, rightval

        if good_sibling:
            # case 3a
            siblkey, siblval, siblchild = sibling_extra
            child.insert(parentkey, parentval, siblchild)
            node.replace(parentkey, siblkey, siblval)
            good_sibling.remove(siblkey, remove_right = remove_right)
            self.__write_page(good_sibling)
            self.__flush_page(good_sibling)
            self.__write_page(child)
        else:
            # case 3b
            if right:
                child.join(rightkey, rightval, right)
                node.remove(rightkey)
                self.__write_page(child)
                self.__free_page(right)
                if left:
                    self.__flush_page(left)
            else:
                if left:
                    left.join(leftkey, leftval, child)
                    node.remove(leftkey)
                    self.__write_page(left)
                    self.__free_page(child)
                    child = left  # will find in the left sibling instead of child
                    if right:
                        self.__flush_page(right)
        self.__write_page(node)
        return child

    def __write_page(self, node):
        self.__write(node.page(),                                    # page returned by __allocate()
                     self.__root.page(),                             # special reference to root
                     node.entries(),                                 # key/value pairs as an array
                     list(map(lambda n: n.page(), node.children()))) # child pages - references to the pages in the store

    def __read_page(self, node, root = False):
        # reads keys, values and references (page()) to children and builds the node in the main memory
        keyvalues, childpages = self.__read(node.page())  # keyvalues [0..n], childpages [0..n+1], childpages[i] for keys < key[i],
                                                          # childpages[i+1] for keys > key[i], if childpages = None or [] - leaf
        node.read(not childpages or len(childpages) == 0,            # is leaf
                  root,                                              # is root
                  keyvalues,                                         # key/value pairs
                  list(map(lambda p: self.Node(self.__t, p), childpages))) # children

    def __free_page(self, node):
        self.__flush_page(node)
        self.__free(node.page(), self.__root.page())

    def __flush_page(self, node):
        # removes the node from the main memory. We also can use LRU for the hottest nodes
        # convention: root should always be in the main memory
        if self.__root != node:
            node.free()

    class Node:
        def __init__(self, t, page, leaf = True):
            self.__t = t
            self.__page = page
            self.__leaf = leaf
            # len(__values) == len(__keys), by the same index, if no value for a key - None
            # for non leaf: len(__children) == len(__keys) + 1, idx = index in __keys for a key
            # __children[key] - the left child of the node for key (< key),
            # __children[key+1] - the right one (> key)
            self.__keys = []
            self.__values = []
            self.__children = []

        def leaf(self):
            return self.__leaf

        def empty(self):
            return len(self.__keys) == 0

        def full(self):
            return len(self.__keys) == 2 * self.__t - 1

        def hasminimum(self):
            return len(self.__keys) >= self.__t

        def page(self):
            return self.__page

        def entries(self):
            return list(zip(self.__keys, self.__values))

        def children(self):
            return self.__children

        def major(self):
            # major is the oldest children
            return self.__children[0] if not self.leaf() and len(self.__children) > 0 else None

        def minor(self):
            # minor is the youngest children
            return self.__children[-1] if not self.leaf() and len(self.__children) > 0 else None

        def leftest(self):
            # returns the first key, his value and the reference to the page with keys < the first one
            # (if the node is not a leaf, otherwise the reference is None).
            # If the node has only one key, the leftest can be equal to the rightest.
            key = self.__keys[0] if len(self.__keys) > 0 else None
            value = self.__values[0] if len(self.__values) > 0 else None
            child = self.major()
            return key, value, child

        def second_leftest(self):
            # returns the first key, his value and the reference to the page with keys > the
            # first one and < the key after the first one (if the node is not a leaf, otherwise the reference
            # is None). The difference between the 'leftest' and 'second_leftest' methods is only the reference
            # to a child page, the key and value are the same.
            key = self.__keys[0] if len(self.__keys) > 0 else None
            value = self.__values[0] if len(self.__values) > 0 else None
            child = self.__children[1] if not self.leaf() and len(self.__children) > 1 else None
            return key, value, child

        def rightest(self):
            # returns the last key, his value and the reference to the page with keys > the last one
            # (if the node is not a leaf, otherwise the reference is None).
            # if the node has only one key, the leftest can be equal to the rightest.
            key = self.__keys[-1] if len(self.__keys) > 0 else None
            value = self.__values[-1] if len(self.__values) > 0 else None
            child = self.minor()
            return key, value, child

        def second_rightest(self):
            # returns the last key, his value and the reference to the page with
            # keys < the last one and > the key just before the last one (if the node is not a leaf,
            # otherwise the reference is None). The difference between the 'rightest' and 'second_rightest'
            # methods is only the reference to a child page, the key and value are the same.
            key = self.__keys[-1] if len(self.__keys) > 0 else None
            value = self.__values[-1] if len(self.__values) > 0 else None
            child = self.__children[-2] if not self.leaf() and len(self.__children) > 1 else None
            return key, value, child

        def find(self, key):
            # binary-searches for the key 'key' in the node and returns
            # whether the key is in the node at all, the value associates with the key,
            # and the child (Node) that is staying for the 'key'.
            idx = self.__position(key)
            if idx == len(self.__keys) or self.__keys[idx] != key:
                value = None
                found = False
            else:
                value = self.__values[idx]
                found = True
            child = self.__children[idx] if not self.leaf() else None
            return found, value, child

        def siblings(self, key):
            # binary-searches for the key 'key' in the node and returns
            # the left key, his value, and immediate left sibling as a tuple
            # along with the right key, hist value, and immediate right sibling as another tuple
            # of the child that is staying for the 'key'. If there is not a sibling, returns 'None'
            # for the tuple this direction.
            idx = self.__position(key)
            left = (self.__keys[idx - 1], self.__values[idx - 1], self.__children[idx - 1]) if idx > 1 else None
            right = (self.__keys[idx], self.__values[idx], self.__children[idx + 1]) if idx + 1 < len(self.__children) else None
            return left, right

        def insert(self, key, value, right = None):
            result = False
            if key:
                idx = self.__position(key)
                if len(self.__keys) < idx + 1 or self.__keys[idx] != key:
                    self.__keys.insert(idx, key)
                    self.__values.insert(idx, value)
                    result = True
                else:  # replace the value
                    self.__values[idx] = value
            else:
                idx = 0
            if not self.leaf() and right:
                if len(self.__children) < idx + 2 or self.__children[idx] != right:
                    self.__children.insert(idx + 1, right)
            return result

        def remove_leftest(self):
            # removes the leftest key, value and child and returns the removed key and value
            # the complexity is O(len(__keys)) since the first element will be removed
            key = value = None
            if len(self.__keys) > 0:
                key = self.__keys[0]
                self.__keys.pop(0)
            if len(self.__values) > 0:
                value = self.__values[0]
                self.__values.pop(0)
            if not self.leaf() and len(self.__children) > 0:
                self.__children.pop(0)
            return key, value

        def remove_rightest(self):
            # removes the rightest key, valye and child and returns the removed key and value
            # the compexity is O(1) since the last element will be removed
            key = value = None
            if len(self.__keys) > 0:
                key = self.__keys[-1]
                self.__keys.pop()
            if len(self.__values) > 0:
                value = self.__values[-1]
                self.__values.pop()
            if not self.leaf() and len(self.__children) > 0:
                self.__children.pop()
            return key, value

        def remove(self, key, remove_right = True):
            if not key:
                return False
            idx = self.__position(key)
            if len(self.__keys) < idx + 1 or self.__keys[idx] != key:
                return False

            self.__keys.pop(idx)
            self.__values.pop(idx)
            if not self.leaf():
               idx = idx + 1 if remove_right else idx # if remove_right - remove the right reference otherwise - the left one 
               self.__children.pop(idx)
            return True

        def replace(self, key, newkey, newvalue):
            if not key:
                return False
            idx = self.__position(key)
            if len(self.__keys) > idx and self.__keys[idx] == key:
                self.__keys[idx] = newkey
                self.__values[idx] = newvalue
                return True
            return False

        def split(self, parent, newnode):
            # copy a half of keys and children to newnode
            median_key = self.__keys[self.__t - 1]
            median_value = self.__values[self.__t - 1]
            newnode.__keys = self.__keys[self.__t:]
            newnode.__values = self.__values[self.__t:]
            self.__keys = self.__keys[:self.__t - 1]
            self.__values = self.__values[:self.__t - 1]
            if not self.leaf():
                newnode.__children = self.__children[self.__t:]
                self.__children = self.__children[:self.__t]
            # insert the median and newnode to the parent node
            parent.insert(median_key, median_value, newnode) # if key > median_key, welcome to newnode
            return median_key

        def join(self, newkey, newvalue, right = None):
            # join newkey/newvalue and keys/values from the right node ('right) to the RIGHT of 'self'
            self.__keys.append(newkey)
            self.__values.append(newvalue)
            if right:
                self.__keys.extend(right.__keys)
                self.__values.extend(right.__values)
                if not self.leaf() and not right.leaf():
                    self.__children.extend(right.__children)

        def read(self, leaf, root, keyvalues, children):
            if len(keyvalues) > 2 * self.__t - 1:
                raise BTreeInvalidNodeError("a page may have at most '2t - 1' ({}) keys but has {}."
                                            .format(2 * self.__t - 1, len(keyvalues)),
                                            self.__page)
            if not root and len(keyvalues) < self.__t - 1:
                raise BTreeInvalidNodeError("the page is not the root; therefore, it may have at least "\
                                            "'t - 1' ({}) keys but has only {}."
                                            .format(self.__t - 1, len(keyvalues)),
                                            self.__page)
            if not leaf:
                if len(children) != len(keyvalues) + 1:
                    raise BTreeInvalidNodeError("every internal node may have a number of children ({}) "\
                                                "exactly equals to a number of keys ({}) plus one."
                                                .format(len(children), len(keyvalues)),
                                                self.__page)
            self.__leaf = leaf
            self.__keys = list(map(lambda p: p[0], keyvalues))
            self.__values = list(map(lambda p: p[1] if len(p) > 1 else None, keyvalues))
            self.__children = children

        def free(self):
            del self.__keys
            self.__keys = []
            del self.__children
            self.__children = []

        def __position(self, key):
            # binary-searches for the index for the key 'key' in the array of keys (O(lg n)).
            return bisect.bisect_left(self.__keys, key)

class BTreeNotInitializedError(Exception):
    def __init__(self):
        super(BTreeNotInitializedError, self).__init__("create a new or load an existing "\
                                                       "btree to start working with it.")

class BTreeInvalidNodeError(Exception):
    def __init__(self, warning, page):
        super(BTreeInvalidNodeError, self).__init__(warning)
        self.__page = page

    def page(self):
        return self.__page

if __name__ == "__main__":
    main()

#!/usr/bin/env python
# coding=utf-8

class Deque:

    def __init__(self, size):
        self.N = 0
        self.head = 0
        self.tail = size-1
        self.array = [0]*size
        self.size = size

    def addFirst(self, item):
        self.array[self.head] = item
        self.N += 1
        self.head = (self.head+1)%self.size

    def addLast(self, item):
        self.array[self.tail] = item
        self.N += 1
        self.tail = (self.tail-1)%self.size

    def removeFirst(self):
        self.N -= 1
        self.head = (self.head-1)%self.size
        v = self.array[self.head]
        return v

    def removeLast(self):
        self.N -= 1
        self.tail = (self.tail+1)%self.size
        v = self.array[self.tail]
        return v

    def seeAll(self):
        print self.head,self.tail,self.N
        print self.array

myqueue = Deque(10)
myqueue.addFirst(2)
myqueue.addFirst(3)
myqueue.addFirst(4)
myqueue.addLast(5)
myqueue.addLast(6)
myqueue.addLast(6)
myqueue.seeAll()
print myqueue.removeLast()
print myqueue.removeFirst()
#User function Template for python3

#User function Template for python3
class Solution:
    def mergeResult(self, node1, node2):
        starter = Node(0)
        ans = starter

        while node1 is not None and node2 is not None:
            if node1.data < node2.data:
                ans.next = node1
                node1 = node1.next
                ans = ans.next
            else:
                ans.next = node2
                node2 = node2.next
                ans = ans.next

        if node1 is not None:
            ans.next = node1
        if node2 is not None:
            ans.next = node2

        curr = starter.next
        prev = None

        while curr is not None:
            forw = curr.next
            curr.next = prev
            prev = curr
            curr = forw

        return prev

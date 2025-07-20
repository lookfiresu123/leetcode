package utils

type ListNode struct {
	Val  int
	Next *ListNode
}

func GetIntersectionNode(headA, headB *ListNode) *ListNode {
	nodeMap := make(map[*ListNode]int)
	for cur := headA; cur != nil; cur = cur.Next {
		nodeMap[cur] = 1
	}
	for cur := headB; cur != nil; cur = cur.Next {
		if _, ok := nodeMap[cur]; ok {
			return cur
		}
	}
	return nil
}

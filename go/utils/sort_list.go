/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

package utils

func findMid(head, tail *ListNode) *ListNode {
	fast := head
	slow := head
	for fast != tail && slow != tail {
		fast = fast.Next
		if fast != tail {
			fast = fast.Next
		}
		slow = slow.Next
	}
	return slow
}

func merge(list1, list2 *ListNode) *ListNode {
	res, tmp1, tmp2 := &ListNode{}, list1, list2
	tmp := res
	for tmp1 != nil && tmp2 != nil {
		if tmp1.Val <= tmp2.Val {
			tmp.Next = tmp1
			tmp1 = tmp1.Next
		} else {
			tmp.Next = tmp2
			tmp2 = tmp2.Next
		}
		tmp = tmp.Next
	}
	if tmp1 != nil {
		tmp.Next = tmp1
	} else if tmp2 != nil {
		tmp.Next = tmp2
	}
	return res.Next
}

func mergeSortList(head, tail *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == tail {
		head.Next = nil
		return head
	}

	mid := findMid(head, tail)
	return merge(mergeSortList(head, mid), mergeSortList(mid, tail))
}

func SortList(head *ListNode) *ListNode {
	return mergeSortList(head, nil)
}
